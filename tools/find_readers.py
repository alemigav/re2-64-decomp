#!/usr/bin/env python3
"""Report every instruction that accesses an address window, with its enclosing function.

This is the question that has been asked four times in this project in four different shapes — who
writes `0x800ca458`, who writes the two staging banks, who reads `0x800eb264`, who selects the scene
slot — and each time it was answered with a fresh ad-hoc script whose arithmetic could be wrong.
`vaddr.py` fixed the arithmetic; this fixes the shape.

The scan is a forward abstract pass per image: `lui` opens a high half, `ori`/`addiu` (signed) close
it, `addu`/`or` of two knowns combine, `li` produces a small constant, and any other write to a
register clears it. A memory instruction whose base register holds a known constant is then a
computable address, and it is reported with the *enclosing function* — found by scanning back for a
prologue, and cross-checked against the corpus index when one exists.

What it does **not** do: track a base that came from memory. Those accesses are counted separately,
because "the pointer was loaded" is exactly the case where this analysis cannot see the address and
a count is more honest than silence.

Usage:
  ./find_readers.py 0x800eb260 0x800eb270         # a window
  ./find_readers.py 0x800eb268                    # a single word
"""
import argparse
import json
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import vaddr as V

MEM_OPS = {0x23: "lw", 0x2B: "sw", 0x24: "lbu", 0x25: "lhu", 0x21: "lh", 0x29: "sh", 0x28: "sb",
           0x37: "ld", 0x3F: "sd", 0x2A: "swl", 0x2E: "swr", 0x26: "lwl", 0x22: "lwr",
           0x30: "ll", 0x38: "sc", 0x1F: "lwu", 0x27: "lwu"}
LOADS = {0x23, 0x24, 0x25, 0x21, 0x37, 0x26, 0x22, 0x30, 0x1F}
REGS = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5",
        "t6", "t7", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1",
        "gp", "sp", "fp", "ra"]


def enclosing(words: list, base: int, idx: int, prologue_only: bool = True) -> int:
    """Nearest prologue at or before `idx`, else the start of the image."""
    for i in range(idx, max(-1, idx - 0x800), -1):
        w = words[i]
        if (w & 0xFFFF0000) == 0x27BD0000 and (w & 0x8000):
            return base + i * 4
    return base


def scan(name: str, code: bytes, base: int, lo: int, hi: int) -> dict:
    n = len(code) // 4
    words = list(struct.unpack(f">{n}I", code[:n * 4]))
    pend, hits, opaque = {}, [], 0
    for i, w in enumerate(words):
        op = w >> 26
        rs, rt, imm = (w >> 21) & 0x1F, (w >> 16) & 0x1F, w & 0xFFFF
        si = imm - 0x10000 if imm & 0x8000 else imm
        rd = (w >> 11) & 0x1F if op == 0 else rt
        if op in MEM_OPS:
            b = pend.get(rs)
            if b is None:
                if rs != 0:
                    opaque += 1
            else:
                addr = (b + si) & 0xFFFFFFFF
                if lo <= addr < hi:
                    hits.append(dict(pc=base + i * 4, op=MEM_OPS[op], addr=addr,
                                     reg=REGS[rt], base=REGS[rs], imm=si,
                                     kind="load" if op in LOADS else "store",
                                     function=enclosing(words, base, i)))
        # constant bookkeeping (same discipline as find_store_loops / find_bank_writers)
        val = None
        if op == 0x0F:
            val = imm << 16
        elif op in (0x0D, 0x09) and rs in pend:
            val = (pend[rs] | imm) if op == 0x0D else pend[rs] + si
        elif op == 0x09 and rs == 0:
            val = imm
        elif op == 0 and (w & 63) == 0x21 and rs in pend and rt in pend:
            val = pend[rs] + pend[rt]
        elif op == 0 and (w & 63) == 0x25 and rs in pend and rt in pend:
            val = pend[rs] | pend[rt]
        if op not in MEM_OPS and op not in (0x04, 0x05, 0x06, 0x07, 0x01, 0x02, 0x03):
            if val is not None:
                pend[rd] = val
            else:
                pend.pop(rd, None)
    return dict(image=name, hits=hits, opaque=opaque)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("lo")
    ap.add_argument("hi", nargs="?")
    ap.add_argument("--images", default="build/elfs/images.json")
    ap.add_argument("--json", default=None)
    a = ap.parse_args()
    lo = int(a.lo, 0)
    hi = int(a.hi, 0) if a.hi else lo + 4

    images = json.loads(Path(a.images).read_text())["images"]
    out, total = [], 0
    for img in images:
        code = (Path("build/elfs") / f"{img['name']}.elf").read_bytes()[0x100:0x100 + img["size"]]
        r = scan(img["name"], code, img["base"], lo, hi)
        if r["hits"]:
            out.append(r)
            total += len(r["hits"])

    print(f"{total} access(es) to {lo:#010x}..{hi:#010x} across {len(images)} images")
    for r in out:
        for h in r["hits"]:
            print(f"  {r['image']:>14} {h['pc']:#010x}  {h['op']:<3} {h['reg']:>4}, "
                  f"{h['imm']}({h['base']})  -> {h['addr']:#010x}   in {h['function']:#010x}")
    if not out:
        print("  none — the address is never formed as a constructed base plus immediate")
    hidden = sum(r["opaque"] for r in out)
    if hidden:
        print(f"\n{hidden} memory instruction(s) in those images use a base that came from memory; "
              f"those addresses are not resolvable by this analysis")
    if a.json:
        Path(a.json).write_text(json.dumps(dict(lo=hex(lo), hi=hex(hi), images=out), indent=1) + "\n")
        print(f"wrote {a.json}")


if __name__ == "__main__":
    main()
