#!/usr/bin/env python3
"""Walk a room's command stream from the live command pointer.

The static work (M95–M99) established the pieces: a 141-entry opcode→handler table at `0x80113898`,
ten contexts at `0x80113ad0 + i*0x174`, a command pointer at `ctx+0x1c`, and — the part that makes a
walk possible — **each handler advances the pointer by its own command length**. This tool turns that
into a decoder:

  1. for every table slot i, find the advance `lw v,0x1c(rX)` → `addiu v,v,N` → `sw v,0x1c(rX)` inside
     the handler and record `length[i] = N`;
  2. read a memory dump, take the live command pointer from `ctx+0x1c` (falling back to the descriptor
     `*(0x80115284)` that the handler itself reads);
  3. walk: `opcode = byte[p]`, `p += length[opcode]`, recording each command's bytes.

Two guards, because a wrong length desynchronises the whole walk:

  * a command is only accepted when `byte[p]` is a table index with a known length, and the next
    address stays inside RDRAM;
  * the walk reports the first opcode with no length and stops there rather than guessing.

For opcode `0x44` (the scene-slot command, 22 bytes) it also prints byte 3 — the slot — and byte 9 —
the gate — so the walk answers "does a room ever select a bank-C record?" directly.

Usage:
  ./walk_stream.py <rdram-dump.bin> [--commands 64]
"""
import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

RD_BASE = 0x80000000
TABLE = 0x80113898
TABLE_ENTRIES = 141
CTX_BASE = 0x80113AD0
CTX_STRIDE = 0x174
CTX_COUNT = 10
CTX_CMDPTR = 0x1C
DESCRIPTOR = 0x80115284
SLOT_OPCODE = 0x44
SLOT_LEN = 22                  # the handler's own advance, re-derived below

STAGE2_BASE = 0x80018A80
STAGE2_FILE = "assets/unpacked/00000_0014420_1172240.bin"


def load_stage2() -> tuple:
    data = Path(STAGE2_FILE).read_bytes()
    n = len(data) // 4
    return struct.unpack(f">{n}I", data[:n * 4])


def handler_lengths(words) -> dict:
    """opcode -> (handler address, command length) from the advance idiom inside each handler."""
    n = len(words)

    def in_image(va):
        return STAGE2_BASE <= va < STAGE2_BASE + 4 * n

    out = {}
    for i in range(TABLE_ENTRIES):
        off = (TABLE + 4 * i - STAGE2_BASE) // 4
        if not (0 <= off < n):
            continue
        handler = words[off]
        if not in_image(handler):
            continue
        h = (handler - STAGE2_BASE) // 4
        length, backwards = None, None
        for j in range(h, min(h + 0x400, n - 6)):
            w = words[j]
            if (w >> 26) != 0x23 or (w & 0xFFFF) != CTX_CMDPTR:
                continue
            rt, rbase = (w >> 16) & 0x1F, (w >> 21) & 0x1F
            for k in range(j + 1, min(j + 5, n)):
                y = words[k]
                if (y >> 26) != 0x09 or ((y >> 21) & 0x1F) != rt or not (y & 0xFFFF):
                    continue
                N = y & 0xFFFF
                N = N - 0x10000 if N & 0x8000 else N
                for m in range(k + 1, min(k + 3, n)):
                    z = words[m]
                    if ((z >> 26) == 0x2B and (z & 0xFFFF) == CTX_CMDPTR
                            and ((z >> 21) & 0x1F) == rbase and ((z >> 16) & 0x1F) == rt):
                        if N > 0 and length is None:
                            length = N
                        elif N < 0 and backwards is None:
                            backwards = N
                        break
                break
        if length is not None:
            out[i] = (handler, length)
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dump")
    ap.add_argument("--commands", type=int, default=64)
    ap.add_argument("--ctx", type=int, default=None, help="context index 0-9 (default: all with a pointer)")
    a = ap.parse_args()

    words = load_stage2()
    lens = handler_lengths(words)
    print(f"opcode -> command length, derived from {len(lens)} handlers with an advance idiom")
    known = sorted(set(v[1] for v in lens.values()))
    print(f"  lengths in use: {known}")
    print(f"  opcode 0x{SLOT_OPCODE:02x} (the scene-slot command) -> "
          f"{lens.get(SLOT_OPCODE, ('?', '?'))}")

    dump = Path(a.dump).read_bytes()

    def rd(va, n):
        o = va - RD_BASE
        if o < 0 or o + n > len(dump):
            raise ValueError(f"{va:#010x} outside the dump")
        return dump[o:o + n]

    def word(va):
        return struct.unpack(">I", rd(va, 4))[0]

    ctxs = range(CTX_COUNT) if a.ctx is None else [a.ctx]
    pointers = []
    for i in ctxs:
        p = word(CTX_BASE + i * CTX_STRIDE + CTX_CMDPTR)
        desc = word(DESCRIPTOR)
        tags = []
        if RD_BASE <= p < RD_BASE + len(dump) and p:
            tags.append("ctx")
        if p == desc:
            tags.append("== descriptor")
        print(f"  ctx{i}: ctx+0x1c = {p:#010x}  {tags if tags else '(not in RDRAM)'}")
        if tags:
            pointers.append((i, p))
    if not pointers:
        print("\nno context holds a live command pointer — this dump predates a room load")
        return

    for ci, start in pointers:
        print(f"\n=== walking from ctx{ci} = {start:#010x} ===")
        p = start
        seen = {}
        slots = []
        for k in range(a.commands):
            try:
                op = rd(p, 1)[0]
            except ValueError:
                print(f"  [{k:2d}] {p:#010x}: outside the dump — stop")
                break
            if op not in lens:
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} has no derived length — stop "
                      f"(a wrong length here would desynchronise the walk)")
                break
            handler, length = lens[op]
            cmd = rd(p, min(length, 64))
            seen[op] = seen.get(op, 0) + 1
            extra = ""
            if op == SLOT_OPCODE:
                slot = cmd[3] if len(cmd) > 3 else None
                gate = cmd[9] if len(cmd) > 9 else None
                slots.append((p, slot, gate))
                extra = f"  slot(byte3)={slot}  gate(byte9)={gate:#04x}" if gate is not None else ""
            print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} len {length:2d} -> "
                  f"{cmd[:8].hex(' ')}{extra}")
            p += length
        print(f"\n  distinct opcodes: {len(seen)}; top: "
              f"{sorted(seen.items(), key=lambda kv: -kv[1])[:6]}")
        if slots:
            print(f"  scene-slot commands: {len(slots)}; slot values {sorted(s for _, s, _ in slots)}")
        else:
            print("  scene-slot commands (opcode 0x44): none in this walk")


if __name__ == "__main__":
    main()
