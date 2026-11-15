#!/usr/bin/env python3
"""What is MISSING from the bodies that compile short — the aligned diff, then the content of the gaps.

The census (M443) found **969 of 2 478 open bodies emit fewer instructions than the function has**, the largest single
class in the residue. `distance.json` cannot describe them: it counts identical words *positionally*, and a single
inserted instruction shifts everything after it, so a body with 28 of 39 words present in order can score 0 of 39
positionally. **Positional hamming is not an alignment**, and for a missing-statement population it is not even a
ranking.

So this aligns first — `difflib.SequenceMatcher` over the two word lists — and then asks what the image has that we do
not. The answer decides whether "propose the omitted locals" is a real instrument or a guess:

  * `sp-store` / `sp-load` **inside the frame gap** — the image touching stack slots our function never allocated. That
    is M439's omitted-local signature (381 bodies whose extra frame bytes are read) and the one class a template can
    act on, because the slot is named by the instruction.
  * `sp-*` **outside** the gap — accesses to a frame that only exists because ours is smaller.
  * `call`, `const`, `arith`, `branch` — a missing statement of another kind, which a *local* template cannot supply.

A refusal is a status, never a zero: a body that will not compile is counted `refused`, and a body with no gap is
counted `aligned`.

    ./missing_spans.py --census [--limit N]     # the class table over the short bodies
    ./missing_spans.py --at image:0xADDR        # one body, span by span
    ./missing_spans.py --self-test
"""
from __future__ import annotations

import argparse
import concurrent.futures
import difflib
import importlib.util
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FIXTURE = ROOT / "fixtures" / "decomp" / "missing_spans.json"
SKELETONS = ROOT / "fixtures" / "decomp" / "skeletons.json"


def _load(name, path):
    spec = importlib.util.spec_from_file_location(name, str(path))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


census_mod = _load("skc", ROOT / "tools" / "skeleton_census.py")
dm = census_mod.dm
cp = census_mod.cp

LOADS = {0x20: 1, 0x21: 4, 0x23: 4, 0x24: 1, 0x25: 1, 0x27: 4, 0x31: 4, 0x35: 4}
STORES = {0x28: 1, 0x29: 4, 0x2b: 4, 0x2c: 4, 0x2e: 4, 0x39: 4, 0x3d: 4}
NAME = {0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x27: "lwu",
        0x28: "sb", 0x29: "sh", 0x2b: "sw", 0x2c: "sdl", 0x2e: "swr",
        0x0f: "lui", 0x09: "addiu", 0x0d: "ori", 0x0c: "andi", 0x0b: "sltiu", 0x0a: "slti"}


def simm16(w):
    v = w & 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


def frame_of(words, base):
    """The function's own frame size, from its prologue `addiu sp,sp,-N`. 0 when it has none."""
    for i, w in enumerate(words[:4]):
        if (w >> 26) == 0x09 and ((w >> 21) & 31) == 29 and ((w >> 16) & 31) == 29:
            return -simm16(w)
    return 0


def classify(words, base, our_frame, gap_lo, gap_hi):
    """What one missing instruction is, and whether it touches the frame we do not have."""
    op = words >> 26
    kinds = []
    if op in STORES or op in LOADS:
        rs = (words >> 21) & 31
        off = simm16(words)
        if rs == 29:
            # The gap is [our_frame, image_frame): slots the image allocated and we did not.
            kinds.append("sp-access-in-gap" if gap_lo <= off < gap_hi else "sp-access-elsewhere")
        kinds.append(NAME.get(op, "mem"))
    elif op == 0x03:
        kinds.append("call")
    elif op == 0x02:
        kinds.append("jump")
    elif op in (0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17) or (op == 0x01):
        kinds.append("branch")
    elif op == 0x0f:
        kinds.append("const")
    else:
        kinds.append("arith")
    return kinds


def analyse(args):
    """One body: the aligned diff, and the missing spans with their content."""
    image, addr, words, name, source, code, data = args
    got = census_mod.compile_words(args)
    if got is None:
        return {"status": "refused"}
    ours, want = got
    if len(ours) >= words:
        return {"status": "not-short", "our_words": len(ours), "words": words}
    # ALIGN, do not index. A single missing instruction shifts every later word, so positional identity reports a
    # near-complete body as "0 of 39".
    sm = difflib.SequenceMatcher(None, want, ours, autojunk=False)
    spans = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal" or i1 == i2:
            continue
        spans.append((i1, i2))
    image_frame, our_frame = frame_of(want, addr), frame_of(ours, addr)
    gap_lo, gap_hi = min(our_frame, image_frame), max(our_frame, image_frame)
    kinds = {}
    for i1, i2 in spans:
        for i in range(i1, i2):
            for k in classify(want[i], addr + 4 * i, our_frame, gap_lo, gap_hi):
                kinds[k] = kinds.get(k, 0) + 1
    same = sum(1 for tag, _i1, _i2, _j1, _j2 in sm.get_opcodes() if tag == "equal"
               for _ in range(0))
    aligned = sum(block.size for block in sm.get_matching_blocks())
    return {"status": "short", "words": words, "our_words": len(ours),
            "missing": sum(i2 - i1 for i1, i2 in spans), "spans": len(spans),
            "aligned": aligned, "positional": sum(1 for i in range(min(len(ours), words)) if ours[i] == want[i]),
            "image_frame": image_frame, "our_frame": our_frame, "kinds": kinds,
            "in_gap": kinds.get("sp-access-in-gap", 0)}


def short_targets():
    """The census's short bodies, in gap order. This is the population, taken from the committed fixture."""
    if not SKELETONS.exists():
        return []
    recs = json.loads(SKELETONS.read_text())["records"]
    keys = {k for k, v in recs.items() if v["class"] == "our-short"}
    return [t for t in dm.functions_to_measure(None) if "%s:%08x" % (t[0], t[1]) in keys]


def census(args) -> int:
    targets = short_targets()
    if args.limit:
        targets = targets[:args.limit]
    print("classifying %d short bodies with %d job(s)" % (len(targets), args.jobs), file=sys.stderr)
    rows = {}
    with concurrent.futures.ProcessPoolExecutor(max_workers=args.jobs) as pool:
        for t, res in zip(targets, pool.map(analyse, targets, chunksize=8)):
            rows["%s:%08x" % (t[0], t[1])] = res
    short = {k: v for k, v in rows.items() if v["status"] == "short"}
    total_missing = sum(v["missing"] for v in short.values())
    in_gap = sum(v["in_gap"] for v in short.values())
    doc = {
        "tool": "missing_spans.py",
        "note": ("The missing spans of every body that compiles SHORTER than its extent, found by ALIGNING the two word "
                 "lists (difflib) rather than indexing them. `aligned` is the alignment identity, `positional` the "
                 "index identity distance.json records — the two disagree wildly on this population, which is why the "
                 "map could not rank it. `in_gap` counts missing instructions that touch a stack slot between our "
                 "frame and the image's: that is the omitted-local signature and the only class a local template can "
                 "supply."),
        "summary": {"bodies": len(rows), "short": len(short),
                    "refused": sum(1 for v in rows.values() if v["status"] == "refused"),
                    "missing_words": total_missing, "missing_in_frame_gap": in_gap},
        "rows": dict(sorted(rows.items())),
    }
    FIXTURE.parent.mkdir(parents=True, exist_ok=True)
    FIXTURE.write_text(json.dumps(doc, indent=1) + "\n")
    s = doc["summary"]
    print("%d bodies: %d short, %d refused; %d missing words, %d of them touching the frame gap"
          % (s["bodies"], s["short"], s["refused"], s["missing_words"], s["missing_in_frame_gap"]))
    import collections
    agg = collections.Counter()
    for v in short.values():
        for k, n in v["kinds"].items():
            agg[k] += n
    print("\ncontent of the missing spans, by instruction:")
    for k, n in agg.most_common():
        print("   %-20s %5d" % (k, n))
    both = [v for v in short.values() if v["aligned"] != v["positional"]]
    if both:
        print("\nalignment identity vs the positional identity the map records:")
        print("   bodies where the two disagree: %d of %d" % (len(both), len(short)))
        print("   median aligned %d, median positional %d"
              % (sorted(v["aligned"] for v in both)[len(both) // 2],
                 sorted(v["positional"] for v in both)[len(both) // 2]))
    return 0


def at(args) -> int:
    image, _, hexa = args.at.partition(":")
    addr = int(hexa, 16)
    t = next((x for x in dm.functions_to_measure([image]) if x[1] == addr), None)
    if t is None:
        print("no such body")
        return 2
    res = analyse(t)
    print(json.dumps(res, indent=1))
    return 0


def self_test() -> int:
    """The alignment must be able to say "one instruction is missing" — the thing positional counting cannot."""
    ours = [1, 2, 4, 5]
    want = [1, 2, 3, 4, 5]
    sm = difflib.SequenceMatcher(None, want, ours, autojunk=False)
    aligned = sum(b.size for b in sm.get_matching_blocks())
    positional = sum(1 for i in range(len(ours)) if ours[i] == want[i])
    spans = [(i1, i2) for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag != "equal" and i1 != i2]
    cases = [("alignment finds 4 of 5 present", aligned == 4, str(aligned)),
             ("positional finds only 2 of 5", positional == 2, str(positional)),
             ("the missing span is exactly the inserted word", spans == [(2, 3)], str(spans)),
             ("a frame is read from the prologue", frame_of([0x27BDFFE8, 0, 0, 0], 0) == 24,
              str(frame_of([0x27BDFFE8, 0, 0, 0], 0))),
             ("an sp access inside the gap is named",
              "sp-access-in-gap" in classify(0xAFBF0018, 0, 24, 24, 64),
              str(classify(0xAFBF0018, 0, 24, 24, 64)))]
    ok = sum(1 for _n, g, _d in cases if g)
    for n, g, d in cases:
        print("  %s %s%s" % ("PASS" if g else "FAIL", n, "" if g else " — " + d))
    print("%d/%d missing-span case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--census", action="store_true")
    ap.add_argument("--at")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.at:
        return at(a)
    if a.census:
        return census(a)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
