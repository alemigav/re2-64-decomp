#!/usr/bin/env python3
"""Measure function extents inside a byte range of an image, from the bytes alone.

M338 found that 8.7 % of the `unclassified` bucket is **code** — 28 764 B in 75 runs, whose dense end is nine
stage2 regions of 1.5-6 KB. Those regions are code no artifact names: the provider's index has no entry there,
so the census cannot see them and the byte map files them as unclassified. This tool measures *where the
functions in such a region start and end*, which is the extent half of the recovery this project already does
by hand — and unlike a reconstruction it needs no C.

The rule, and why each part of it is there:

  * a **return** is `jr $ra` (`0x03E00008`) followed by exactly one delay-slot word. A `jr` through any other
    register is a *tail jump*, not a return: the function ends there too, but it does not come back, and a
    human still has to read it;
  * a **start** is the region start, or the word after a return's delay slot. Nothing else creates a start:
    the M320 rule — a `jal` target is *not* evidence of a start, because a truncated extent also looks like
    one, and inferring starts from call sites is how the census came to call a 96-caller function a stub;
  * a candidate is **rejected** when it has no return at its end, when a `jr $ra` appears inside it (that is
    a split the scan missed, not one function), or when it holds fewer than two words. Rejections are
    reported, never silently dropped.

So this measures *returns*, not prologues. That is deliberate: a return is unambiguous in the bytes, while a
prologue heuristic (`addiu sp,sp,-N` first) fails on leaf functions, on hand-written assembly and on the boot
image's own style. The cost is that a region whose first function starts mid-way — after data, say — is
reported as one long rejected candidate rather than silently mis-split.

Usage:
  ./extent_scan.py --self-test
  ./extent_scan.py --image stage2 --start 0x80022a1c --end 0x800241b0
  ./extent_scan.py --code-runs              # every code-like run M338 measured, via classify_image
"""
import argparse
import json
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))

JR_RA = 0x03E00008


def words_of(blob):
    return [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob) - 3, 4)]


def is_jr(w):
    return (w >> 26) == 0 and (w & 0x3F) == 0x08


def simm16(w):
    """The signed 16-bit displacement of a branch or memory instruction."""
    v = w & 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def check_body(ws, start, end):
    """M364/M365's four rejections, applied to one candidate extent [start, end] (word indices).

    They exist because a body that is only "words up to the next `jr ra`" can be a fragment, and eleven of the
    eighty-five entries M362 admitted failed at least one of these. Written once, here, with a self-test case each,
    because the original implementation lived in a `/tmp` script that no longer exists -- which is why the rules were
    re-derived by hand in two later milestones and applied inconsistently (M377).

      * a **branch that leaves the body** -- its target is outside [start, end], so this extent is a fragment of a
        larger function;
      * a **self-branch** (`b .`, or any branch whose target is itself) -- the body never returns;
      * an **epilogue with no prologue** -- it restores `$ra` from a frame it never saved, so the head of the
        function is not in this extent;
      * and, from the splitter rather than from here, a body **cut at a tail `j`** (opcode 2 ends a control path;
        `jal`, opcode 3, does not -- that was M365's correction of M364, and it cost thirteen functions).
    """
    saved_ra = False
    for i in range(start, end + 1):
        w = ws[i]
        o = w >> 26
        if o in (4, 5, 6, 7) or (o == 1 and (w >> 16) & 0x1F == 0):
            target = i + 1 + simm16(w)
            if o == 4 and ((w >> 21) & 0x1F) == ((w >> 16) & 0x1F) and target == i:
                return "branch to itself: the body never falls through"
            if target < start or target > end:
                return "a branch leaves the body (target word %d of %d..%d)" % (target, start, end)
        if o == 0x2B and ((w >> 21) & 0x1F) == 0x1D:       # sw $ra, N($sp)
            saved_ra = True
        if o == 0x23 and ((w >> 21) & 0x1F) == 0x1D and ((w >> 16) & 0x1F) == 0x1F:   # lw $ra, N($sp)
            if not saved_ra:
                return "restores $ra from a frame it never saved: the head is outside this extent"
    return None


def ends_path(w):
    """True when the word ends a control path: a return, or a tail `j` (opcode 2 -- never `jal`)."""
    return w == JR_RA or (w >> 26) == 2


def scan_strict(blob, base):
    """`scan`, but cutting at tail jumps too and applying the four rejections (M377).

    Kept beside `scan` rather than replacing it: the committed rung was produced by M365's hand-run rebuild, and a
    reader has to be able to reproduce that measurement *or* see that a stricter tool disagrees. `--strict` selects
    this one, and `--write --strict` is the reproducible path.
    """
    ws = words_of(blob)
    funcs, rejected = [], []
    start, i = 0, 0
    while i < len(ws):
        if ends_path(ws[i]):
            delay = i + 1 if i + 1 < len(ws) else i
            body = {"start": base + 4 * start, "end": base + 4 * delay, "words": delay - start + 1}
            if body["words"] < 2:
                rejected.append({**body, "why": "a lone return with no delay slot"})
            else:
                why = check_body(ws, start, delay)
                if why:
                    rejected.append({**body, "why": why})
                else:
                    funcs.append({**body, "returns": 1})
            start = delay + 1
            i = delay + 1
            continue
        i += 1
    if start < len(ws):
        rejected.append({"start": base + 4 * start, "end": base + 4 * len(ws) - 4,
                         "words": len(ws) - start,
                         "why": "no trailing return or tail jump: %d word(s) left" % (len(ws) - start)})
    return funcs, rejected


def scan(blob, base):
    """Return (functions, rejected) for a byte range starting at `base`; every extent is in bytes."""
    ws = words_of(blob)
    funcs, rejected = [], []
    start, i = 0, 0
    while i < len(ws):
        w = ws[i]
        if w == JR_RA:
            end = i + 1 if i + 1 < len(ws) else i          # the delay slot belongs to the function
            body = ws[start:end + 1]
            # Splitting at every `jr ra` makes an *interior* return impossible by construction, so the only
            # candidate that can be short is a lone `jr ra` with no room for its delay slot at the region end.
            # (An earlier draft carried an "interior return" rejection: dead code, and its self-test case
            # failed for the right reason — the input was a legal two-word empty function.)
            if len(body) >= 2:
                funcs.append({"start": base + 4 * start, "end": base + 4 * end,
                              "words": end - start + 1, "returns": 1})
            else:
                rejected.append({"start": base + 4 * start, "end": base + 4 * end,
                                 "words": end - start + 1,
                                 "why": "a lone `jr ra` with no delay slot: a function needs both words"})
            start = i + 2
            i = i + 2
            continue
        i += 1
    if start < len(ws):
        tail = ws[start:]
        rejected.append({"start": base + 4 * start, "end": base + 4 * len(ws) - 4,
                         "words": len(tail),
                         "why": "no trailing `jr ra`: %d word(s) after the last return"
                                % len(tail)})
    return funcs, rejected


def tail_jumps(blob, base):
    """`jr` through a register other than $ra: a function that leaves instead of returning (reported, not sized)."""
    out = []
    for i, w in enumerate(words_of(blob)):
        if is_jr(w) and w != JR_RA:
            out.append({"at": base + 4 * i, "word": "0x%08x" % w})
    return out


def code_runs(want=("unclassified",)):
    """Every code-like run of the given byte-map classes, as (image, start, end) in address order.

    M377: the class matters and used to be hard-coded to `unclassified`. That was right in M338, when 28 764 B of
    code sat in that bucket; the twelve-milestone byte-map arc classified those runs, so by M372 `unclassified` holds
    440 B in nine tails and `--code-runs` returned **nothing**. The rung's later entries came from `enclosed_data`
    (M362) and `gap`, so the classes are selectable now -- otherwise the tool cannot reproduce the fixture it wrote.
    """
    import classify_image as ci
    images = json.loads((ci.ROOT / "fixtures/decomp/images.json").read_text())
    bmap = json.loads((ci.ROOT / "manifests/byte_map.json").read_text())
    runs = []
    for img in images["images"]:
        name, base, size = img["name"], img["base"], img["size"]
        blob = ci.image_bytes(img, ci.ROOT)
        if blob is None:
            continue
        for lo, hi, cls, _why in bmap["images"].get(name, []):
            if cls not in want:
                continue
            b = blob[lo - base:hi - base + 1]
            ev = ci.code_run_evidence(b, base, size)
            if ev and ev["is_code"]:
                runs.append((name, lo, hi))
    return runs


def self_test():
    def _blob(words):
        return b"".join(w.to_bytes(4, "big") for w in words)

    def _funcs_strict(words):
        return scan_strict(_blob(words), 0)[0]

    def _why_strict(words):
        # index-safe on purpose: with the rules disabled this must FAIL, not raise (M204's rule -- a crash is not a
        # message, and a mutation that crashes the self-test proves nothing about the rule it removed)
        rej = scan_strict(_blob(words), 0)[1]
        return rej[0]["why"] if rej else ""

    # a two-function body: prologue-free leaf, then a leaf with a delay-slot store
    two = (0x24020001, 0x03E00008, 0x00000000,           # li v0,1 ; jr ra ; nop
           0x8C820000, 0x24030002, 0x03E00008, 0xAC430000)  # lw v0,0(a0) ; li v1,2 ; jr ra ; sw v1,0(v0)
    blob = b"".join(w.to_bytes(4, "big") for w in two)
    f, r = scan(blob, 0x80100000)
    cases = [
        ("two functions are split at their returns", [x["words"] for x in f] == [3, 4] and not r),
        ("the extents are byte ranges, delay slot included",
         [(x["start"], x["end"]) for x in f] == [(0x80100000, 0x80100008), (0x8010000C, 0x80100018)]),
        ("a lone `jr ra` with no delay slot is rejected, not sized",
         scan(b"".join(w.to_bytes(4, "big") for w in (0x03E00008,)), 0)[0] == []
         and "delay slot" in scan(b"".join(w.to_bytes(4, "big") for w in (0x03E00008,)), 0)[1][0]["why"]),
        ("a tail with no return is rejected, never sized as a function",
         scan(b"".join(w.to_bytes(4, "big") for w in (0x24020001, 0x24020002)), 0)[1][0]["why"].startswith("no trailing")),
        # M377: one case per rule the tool lacked -- each fails if its rule is removed.
        ("strict: a body is cut at a tail `j`, because a `j` ends a control path",
         scan_strict(b"".join(w.to_bytes(4, "big") for w in (0x08000010, 0x00000000, JR_RA, 0)), 0)[0][0]["words"] == 2
         and len(scan_strict(b"".join(w.to_bytes(4, "big") for w in (0x08000010, 0x00000000, JR_RA, 0)), 0)[0]) == 2),
        ("strict: `jal` is a call, not a tail jump -- the body continues past it",
         [x["words"] for x in scan_strict(b"".join(w.to_bytes(4, "big") for w in
                                                (0x0C000010, 0x00000000, JR_RA, 0)), 0)[0]] == [4]),
        ("strict: a branch whose target leaves the body is rejected",
         _why_strict((0x10800010, JR_RA, 0, 0)).startswith("a branch leaves")),
        ("strict: a self-branch is rejected (b .)", "branch to itself" in _why_strict((0x1000FFFF, JR_RA, 0))),
        ("strict: an epilogue restoring `ra` from a frame it never saved is rejected",
         _funcs_strict((0x8FBF0010, JR_RA, 0)) == [] and "never saved" in _why_strict((0x8FBF0010, JR_RA, 0))),
        ("strict: a saved-then-restored `ra` is a legal frame",
         _funcs_strict((0xAFBF0010, 0x8FBF0010, JR_RA, 0)) != []),
        ("a `jr` through another register is reported as a tail jump, not a return",
         tail_jumps(b"".join(w.to_bytes(4, "big") for w in (0x03200008,)), 0x80100000)[0]["at"] == 0x80100000
         and scan(b"".join(w.to_bytes(4, "big") for w in (0x03200008,)), 0)[0] == []),
    ]
    bad = 0
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d extent-scan case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--image")
    ap.add_argument("--start")
    ap.add_argument("--end")
    ap.add_argument("--code-runs", action="store_true", help="scan every code-like run of --region-class")
    ap.add_argument("--region-class", default="unclassified",
                    help="byte-map class to scan with --code-runs (comma-separated; default `unclassified`, which "
                         "the byte-map arc emptied -- `enclosed_data` is where M362's entries came from)")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--strict", action="store_true",
                    help="apply M364/M365's four rejections and cut at tail jumps (M377); the committed rung was "
                         "produced without them, so a diff between the two is a reconciliation, not a regression")
    ap.add_argument("--write", metavar="FIXTURE", help="write the measured extents to a fixture")
    ap.add_argument("--resummary", metavar="FIXTURE",
                    help="recompute a fixture's `summary` block from its own lists, without rescanning")
    a = ap.parse_args(argv)

    if a.self_test:
        return self_test()

    if a.resummary:
        # M373: `--write` computes the summary from a *rescan*, but later milestones edit the lists (M365 split
        # the glued pairs, M369 withdrew 194 entries as listings) without rescanning -- so the summary drifted to
        # 188 functions / 23 868 B while the list held 382 / 40 516 B, and said so on the handover page. The lists
        # are the source of truth once a correction has been adopted, so the summary is recomputed *from them*:
        # this is a regeneration, not a hand patch, and `counts.py --check` now asserts the two agree.
        dest = Path(a.resummary)
        doc = json.loads(dest.read_text())
        funcs, regions = doc.get("functions", []), doc.get("regions", [])
        summary = {"regions": len(regions),
                   "functions": len(funcs),
                   "bytes": 4 * sum(f["words"] for f in funcs),
                   "rejected": sum(len(r["rejected"]) for r in regions),
                   "tail_jumps": sum(len(r["tail_jumps"]) for r in regions)}
        before = doc.get("summary", {})
        doc["summary"] = summary
        dest.write_text(json.dumps(doc, indent=1) + "\n")
        print("resummarised %s" % dest)
        for k in summary:
            if before.get(k) != summary[k]:
                print("  %-10s %s -> %s" % (k, before.get(k), summary[k]))
        return 0

    import classify_image as ci
    images = json.loads((ci.ROOT / "fixtures/decomp/images.json").read_text())
    by_name = {i["name"]: i for i in images["images"]}

    regions = []
    if a.code_runs:
        regions = code_runs(tuple(c.strip() for c in a.region_class.split(",") if c.strip()))
    elif a.image and a.start and a.end:
        regions = [(a.image, int(a.start, 16), int(a.end, 16))]
    else:
        ap.error("give --code-runs, or --image/--start/--end")

    out = []
    for name, lo, hi in regions:
        img = by_name[name]
        blob = ci.image_bytes(img, ci.ROOT)
        if blob is None:
            print("SKIP %s (no bytes)" % name)
            continue
        base = img["base"]
        slicer = scan_strict if a.strict else scan
        funcs, rejected = slicer(blob[lo - base:hi - base + 1], lo)
        tails = tail_jumps(blob[lo - base:hi - base + 1], lo)
        out.append({"image": name, "region": [lo, hi], "functions": funcs,
                    "rejected": rejected, "tail_jumps": tails})

    if a.write:
        # merge, never clobber: the fixture also carries `corrections` (adopted extents, M340) and its note. An
        # earlier version rewrote the whole file and silently dropped five corrections -- caught immediately
        # because a follow-up read raised KeyError, and fixed by merging instead of overwriting.
        dest = Path(a.write)
        prev = json.loads(dest.read_text()) if dest.exists() else {}
        doc = {"tool": "extent_scan.py",
               "note": "Function extents measured from the bytes. `corrections` (M340) replace a census entry's "
                       "truncated body with the extent the bytes have. `functions` (M341) are extents inside "
                       "byte-map regions that no artifact names: new census entries with no C and no provider "
                       "record, published as a disassembly listing rather than pseudocode. `regions` is the raw "
                       "scan evidence behind both.",
               "summary": {"regions": len(out),
                           "functions": sum(len(r["functions"]) for r in out),
                           "bytes": sum(f["words"] * 4 for r in out for f in r["functions"]),
                           "rejected": sum(len(r["rejected"]) for r in out),
                           "tail_jumps": sum(len(r["tail_jumps"]) for r in out)},
               "functions": [{"image": r["image"], "address": "0x%08x" % f["start"], "words": f["words"],
                              "evidence": "extent measured by walking to the first `jr ra` inside a byte-map "
                                          "region no artifact names (M339); no C and no provider record exists"}
                             for r in out for f in r["functions"]],
               "regions": out}
        for keep in ("corrections",):
            if keep in prev:
                doc[keep] = prev[keep]
        dest.write_text(json.dumps(doc, indent=1) + "\n")
        print("wrote %s — %d region(s), %d function(s), %d B (corrections kept: %d)"
              % (a.write, doc["summary"]["regions"], doc["summary"]["functions"], doc["summary"]["bytes"],
                 len(doc.get("corrections", []))))
    if a.json:
        print(json.dumps(out, indent=1))
        return 0

    tf = sum(len(r["functions"]) for r in out)
    tb = sum(f["words"] * 4 for r in out for f in r["functions"])
    print("%-14s %10s %10s %6s %6s %6s" % ("image", "region", "bytes", "fns", "rej", "tail"))
    for r in out:
        lo, hi = r["region"]
        print("%-14s 0x%08x %7d B %6d %6d %6d"
              % (r["image"], lo, hi - lo + 1, len(r["functions"]), len(r["rejected"]), len(r["tail_jumps"])))
    print("\n%d function(s), %d byte(s) measured across %d region(s)" % (tf, tb, len(out)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
