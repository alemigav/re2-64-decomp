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


def handler_lengths(words, base=STAGE2_BASE, table=TABLE, entries=TABLE_ENTRIES) -> dict:
    """opcode -> (handler address, command length), from the advance each handler performs itself.

    Two forms of the same idiom, in order of preference. The **proven** form holds one register
    throughout — `lw X,0x1c(base)` -> `addiu X,X,N` -> `sw X,0x1c(base)` — and covers 140 of the 141
    entries. The **cross-register** form (`lw X` -> `addiu Y,X,N` -> `sw Y`) is a fallback for the one
    that does not, opcode `0x4d`: its handler loads into `a1` at `0x8009bd90`, adds into `v0` fifty
    instructions later at `0x8009be54`, and stores `v0`.

    The order matters and was measured: running the relaxed form first changes **ten** handlers'
    lengths, because a later, unrelated `addiu` from the same register matches. As a fallback it adds
    exactly the one entry and leaves the other 140 byte-identical.
    """
    n = len(words)

    def in_image(va):
        return base <= va < base + 4 * n

    def proven(h):
        """One register end to end. Returns the first positive advance, or None."""
        length = None
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
                        break
                break
        return length

    def cross(h, window=0x40):
        """`lw X` -> `addiu Y,X,N` -> `sw Y`: only for handlers where `proven` found nothing.

        The first `addiu` from the loaded register is the only candidate considered; if it does not
        feed the store, this handler has no advance of this shape and the answer is None, not the next
        load in the function.
        """
        for j in range(h, min(h + 0x400, n - 6)):
            w = words[j]
            if (w >> 26) != 0x23 or (w & 0xFFFF) != CTX_CMDPTR:
                continue
            loaded, rbase = (w >> 16) & 0x1F, (w >> 21) & 0x1F
            for k in range(j + 1, min(j + 1 + window, n)):
                y = words[k]
                if (y >> 26) != 0x09 or ((y >> 21) & 0x1F) != loaded or not (y & 0xFFFF):
                    continue
                N = y & 0xFFFF
                N = N - 0x10000 if N & 0x8000 else N
                dst = (y >> 16) & 0x1F
                for m in range(k + 1, min(k + 3, n)):
                    z = words[m]
                    if ((z >> 26) == 0x2B and (z & 0xFFFF) == CTX_CMDPTR
                            and ((z >> 21) & 0x1F) == rbase and ((z >> 16) & 0x1F) == dst):
                        return N if N > 0 else None
                return None
        return None

    out = {}
    for i in range(entries):
        off = (table + 4 * i - base) // 4
        if not (0 <= off < n):
            continue
        handler = words[off]
        if not in_image(handler):
            continue
        h = (handler - base) // 4
        length = proven(h)
        if length is None:
            length = cross(h)
        if length is not None:
            out[i] = (handler, length)
    return out


def report_lengths(words) -> int:
    """Print the whole opcode -> length map, and fail if it is incomplete or vacuous."""
    lens = handler_lengths(words)
    print(f"opcode -> command length, derived from {len(lens)} of {TABLE_ENTRIES} handlers")
    for i in range(TABLE_ENTRIES):
        if i not in lens:
            print(f"  0x{i:02x}: no advance found")
            continue
        handler, length = lens[i]
        print(f"  0x{i:02x}: {handler:#010x}  +{length}")
    lengths = sorted(set(v[1] for v in lens.values()))
    print(f"  distinct lengths: {len(lengths)} -> {lengths}")
    missing = [i for i in range(TABLE_ENTRIES) if i not in lens]
    if missing:
        print(f"  FAIL {len(missing)} opcode(s) with no derived advance: {[hex(i) for i in missing]}")
    if len(lengths) < 2:
        print("  FAIL fewer than two distinct lengths: a scan that finds nothing also reports "
              "no inconsistency, so a uniform answer here would be unearned")
    ok = not missing and len(lengths) >= 2
    print(f"  {len(lens)}/{TABLE_ENTRIES} opcodes mapped")
    return 0 if ok else 1


def self_test() -> int:
    """A synthetic table with one handler per shape of the idiom — no cartridge needed."""
    base, table, ctx = 0x80000000, 0x80001000, 16
    words = [0] * 0x3000

    def put(va, x):
        words[(va - base) // 4] = x

    def lw(rt, off, rs):    return (0x23 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
    def sw(rt, off, rs):    return (0x2B << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
    def addiu(rt, rs, imm): return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)

    proven_A, proven_B, cross_C, none_D = base + 0x2000, base + 0x2100, base + 0x2200, base + 0x2300
    # A: the proven form, and also a later cross-register store that must NOT win.
    put(proven_A, lw(2, 0x1C, ctx))
    put(proven_A + 4, addiu(2, 2, 4))
    put(proven_A + 8, sw(2, 0x1C, ctx))
    put(proven_A + 4 * 99, addiu(3, 2, 999))
    put(proven_A + 4 * 100, sw(3, 0x1C, ctx))
    # B: the scene-slot length.
    put(proven_B, lw(5, 0x1C, ctx))
    put(proven_B + 4, addiu(5, 5, 22))
    put(proven_B + 8, sw(5, 0x1C, ctx))
    # C: load into a1, add into v0 fifty instructions later, store v0 — opcode 0x4d's shape.
    put(cross_C, lw(5, 0x1C, ctx))
    put(cross_C + 4 * 50, addiu(2, 5, 38))
    put(cross_C + 4 * 51, sw(2, 0x1C, ctx))
    # D: an `lw 0x1c` with no advance at all.
    put(none_D, lw(6, 0x1C, ctx))
    put(none_D + 4, sw(6, 0x14, ctx))
    for i, h in enumerate((proven_A, proven_B, cross_C, none_D)):
        put(table + 4 * i, h)

    got = handler_lengths(words, base=base, table=table, entries=4)
    cases = [
        ("proven idiom",                     got.get(0, (None, None))[1], 4),
        ("scene-slot opcode",                got.get(1, (None, None))[1], 22),
        ("cross-register fallback",          got.get(2, (None, None))[1], 38),
        ("handler with no advance is absent", 3 in got, False),
        ("three of four entries mapped",      len(got), 3),
        ("handler addresses are the table's", got.get(0, (None, None))[0], proven_A),
        ("distinct lengths are non-vacuous",  len(set(v[1] for v in got.values())), 3),
        ("proven wins over a later relaxed match", got.get(0, (None, None))[1] != 999, True),
    ]
    passed = 0
    for label, actual, expected in cases:
        ok = actual == expected
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}"
              + ("" if ok else f": got {actual!r}, expected {expected!r}"))
    print(f"{passed}/{len(cases)} walk_stream self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("dump", nargs="?")
    ap.add_argument("--commands", type=int, default=64)
    ap.add_argument("--ctx", type=int, default=None, help="context index 0-9 (default: all with a pointer)")
    ap.add_argument("--lens", action="store_true",
                    help="print the full opcode -> command length map and exit")
    ap.add_argument("--self-test", action="store_true",
                    help="run the synthetic length-map fixture and exit")
    a = ap.parse_args()

    if a.self_test:
        sys.exit(self_test())

    words = load_stage2()
    if a.lens:
        sys.exit(report_lengths(words))
    if not a.dump:
        ap.error("a dump is required unless --lens or --self-test is given")

    lens = handler_lengths(words)
    print(f"opcode -> command length, derived from {len(lens)} of {TABLE_ENTRIES} handlers")
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
        base = CTX_BASE + i * CTX_STRIDE
        # The dispatcher's pop path decrements `lbu 4(ctx + signed(ctx[2]))` — so the only place a
        # per-context count could live is there. MEASURED: it reads 0xff in every context of both
        # room dumps, i.e. it is a flag, not a remaining count. Recorded, not trusted as a bound.
        rel = rd(base + 2, 1)[0]
        rel = rel - 0x100 if rel & 0x80 else rel
        counter_addr = base + rel + 4
        try:
            counter = rd(counter_addr, 1)[0]
        except ValueError:
            counter = None
        p = word(CTX_BASE + i * CTX_STRIDE + CTX_CMDPTR)
        desc = word(DESCRIPTOR)
        tags = []
        if RD_BASE <= p < RD_BASE + len(dump) and p:
            tags.append("ctx")
        if p == desc:
            tags.append("== descriptor")
        print(f"  ctx{i}: ctx+0x1c = {p:#010x}  counter@{counter_addr:#010x} = "
              f"{counter if counter is None else hex(counter)}  {tags if tags else '(not in RDRAM)'}")
        if tags:
            pointers.append((i, p))
    if not pointers:
        print("\nno context holds a live command pointer — this dump predates a room load")
        return

    print("\nnote: the counter byte is a FLAG (0xff) in every context measured, so it cannot bound a "
          "walk; the dispatcher's only numeric bound is `sltiu s1,10` — ten iterations per call. Walks "
          "therefore run until the stream ends (first byte >= 141).")
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
                # Distinguish "the stream ended" from "the walk desynchronised": a real command's
                # opcode is a table index (< 141). A byte at or above 141 cannot be a command, so the
                # walk has left the command area — which is a bounded stream, not a wrong length.
                kind = ("not a table index (>= 141) -> the stream ENDED here and the walk left "
                        "the command area" if op >= TABLE_ENTRIES else
                        "a table index with no derived advance -> a length is missing")
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} — {kind}")
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
