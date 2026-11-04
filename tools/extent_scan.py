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


def code_runs():
    """Every code-like run from M338's decomposition, as (image, start, end) in address order."""
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
            if cls != "unclassified":
                continue
            b = blob[lo - base:hi - base + 1]
            ev = ci.code_run_evidence(b, base, size)
            if ev and ev["is_code"]:
                runs.append((name, lo, hi))
    return runs


def self_test():
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
    ap.add_argument("--code-runs", action="store_true", help="scan every code-like run M338 measured")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--write", metavar="FIXTURE", help="write the measured extents to a fixture")
    a = ap.parse_args(argv)

    if a.self_test:
        return self_test()

    import classify_image as ci
    images = json.loads((ci.ROOT / "fixtures/decomp/images.json").read_text())
    by_name = {i["name"]: i for i in images["images"]}

    regions = []
    if a.code_runs:
        regions = code_runs()
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
        funcs, rejected = scan(blob[lo - base:hi - base + 1], lo)
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
