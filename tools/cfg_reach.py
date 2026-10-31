#!/usr/bin/env python3
"""Walk the real control-flow graph of every script block, and answer positional questions with it.

The linear walker stops at the five dynamic opcodes, which made reachability tests powerless (M149 measured
96 % of everything "unreachable" that way). Those opcodes are the VM's **structured exits**, and their slots
are now modelled:

    push  0x06 IfElseStart, 0x0d ForStart, 0x11, 0x13 Switch, 0x1b   (block / loop / switch opens)
          0x18 GoSub                                                (subroutine call)
    pop   0x10, 0x12   -> the +0x20 slot array   (depth counter at ctx+thread+8)
          0x1a         -> the +0x60 slot array   (same depth counter)
          0x19         -> the GoSub return slot at ctx+0x144+idx*4

A pop resumes at the continuation recorded by the matching open, which is what the depth counter does at
runtime. This is a **structural** model: it approximates the saved pointer by the opener's continuation
rather than reading a runtime slot, so it *over*-approximates reachability slightly — which is the safe
direction for a "does this ever execute?" question.

  ./cfg_reach.py            # report
  ./cfg_reach.py --check    # the gate
"""
import argparse
import struct
import sys
import tempfile
import zlib
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import walk_stream as ws                                     # noqa: E402
import script_profile as sp                                  # noqa: E402

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

OPENERS = {0x06, 0x0D, 0x11, 0x13, 0x1B}      # push the continuation
SUBCALL, SUBRET = 0x18, 0x19
POPPERS = {0x10, 0x12, 0x1A}                  # pop a block slot
NODE_CAP = 40000


def reachable(raw, starts, res):
    """Positions reachable from `starts`, following jumps and the structured pushes/pops."""
    seen = set()
    work = [(s, ()) for s in starts]
    nodes = 0
    while work and nodes < NODE_CAP:
        p, st = work.pop()
        st = list(st)
        while 0 <= p < len(raw) and nodes < NODE_CAP:
            nodes += 1
            key = (p, tuple(st))
            if key in seen:
                break
            seen.add(key)
            r = res.get(raw[p])
            if r is None or r["length"] is None or p + r["length"] > len(raw):
                break
            length = r["length"]
            op = raw[p]
            if r["status"] == "dynamic":
                if op in (SUBRET, *POPPERS) and st:
                    p = st.pop()                 # resume where the matching open said
                    continue
                break
            if op in OPENERS or op == SUBCALL:
                if len(st) < 24:
                    st.append(p + length)
            if r["status"] == "jump":
                sups = ws.successors(op, raw[p:p + length], p, 0,
                                     lambda i: (struct.unpack_from(">H", raw, 2 * i)[0]
                                                if 2 * i + 2 <= len(raw) else None))
                targets = [t for t, _h in sups if t is not None and 0 <= t < len(raw)]
                for t in targets:
                    work.append((t, tuple(st)))
                if ws.JUMP_FAMILY[op]["conditional"] or not targets:
                    p += length
                    continue
                break
            p += length
    return {k[0] for k in seen if len(k) == 2}


def survey(rom, res, verbose=False):
    blocks = records = 0
    rec_hit = Counter()
    reach_ops = Counter()
    decoded_ops = Counter()
    runs_reach = Counter()
    for idx in range(sp.ENTRY_COUNT):
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) < 8:
            continue
        offs = []
        for i in range(64):
            if 2 * i + 2 > len(raw):
                break
            o = struct.unpack_from(">H", raw, 2 * i)[0]
            if o == 0 or o >= len(raw):
                break
            offs.append(o)
        if len(offs) < 2:
            continue
        reach = reachable(raw, offs, res)
        if len(reach) < 4:
            continue
        blocks += 1
        for s in offs:
            rec_hit["reached" if s in reach else "not"] += 1
            p = s
            seq, pos = [], []
            while 0 <= p < len(raw):
                r = res.get(raw[p])
                if r is None or r["length"] is None or p + r["length"] > len(raw):
                    break
                seq.append(raw[p])
                pos.append(p)
                decoded_ops[raw[p]] += 1
                if p in reach:
                    reach_ops[raw[p]] += 1
                if r["status"] in ("jump", "dynamic"):
                    break
                p += r["length"]
            records += 1
            k = 0
            while k < len(seq):
                if seq[k] == 0x20 and pos[k] in reach:
                    j = k
                    while j < len(seq) and seq[j] == 0x20 and pos[j] in reach:
                        j += 1
                    runs_reach[j - k] += 1
                    k = j
                else:
                    k += 1
    return {"blocks": blocks, "records": records, "rec_hit": rec_hit,
            "reach_ops": reach_ops, "decoded_ops": decoded_ops, "runs_reach": runs_reach}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    res = ws.resolve(ws.load_stage2())
    s = survey(ROM.read_bytes(), res)
    hit = s["rec_hit"]
    total = hit["reached"] + hit["not"]
    print(f"blocks {s['blocks']}  records {s['records']}  record starts reached "
          f"{hit['reached']}/{total} ({100 * hit['reached'] / max(1, total):.1f}%)")
    for op in (0x00, 0x20, 0x1E, 0x1F):
        d, r = s["decoded_ops"][op], s["reach_ops"][op]
        print(f"  0x{op:02x}: decoded {d:6d}  reachable {r:6d}  ({100 * r / max(1, d):.1f}% of decoded)")
    runs = s["runs_reach"]
    print(f"  runs of reachable 0x20: {sum(runs.values())} run(s), max {max(runs) if runs else 0}")

    if not args.check:
        return 0
    cases = [
        ("the structured walk reaches nearly every record start",
         hit["reached"] / max(1, total) > 0.95),
        ("block returns no longer stop the walk",
         s["blocks"] > 1000),
        ("0x20's runs are reachable, so they are executed",
         s["reach_ops"][0x20] / max(1, s["decoded_ops"][0x20]) > 0.85),
        ("0x00 reaches less than 0x20, so some of it is genuinely skipped",
         (s["reach_ops"][0x00] / max(1, s["decoded_ops"][0x00]))
         < (s["reach_ops"][0x20] / max(1, s["decoded_ops"][0x20]))),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} cfg-reach case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
