#!/usr/bin/env python3
"""Walk a room's command stream from the live command pointer.

The static work (M95-M99) established the pieces: a 141-entry opcode->handler table at `0x80113898`,
ten contexts at `0x80113ad0 + i*0x174`, a command pointer at `ctx+0x1c`, and - the part that makes a
walk possible - **each handler advances the pointer by its own command length**. This tool turns that
into a decoder:

  1. for every table slot i, find every advance `lw v,0x1c(rX)` -> `addiu w,v,N` -> `sw w,0x1c(rX)`
     performed **inside the handler's own extent**, and classify it (M142):
       ok          exactly one advance, so that is the command length;
       unverified  none at all, so the number published at M136 came from *outside* the handler and
                   there is nothing here to walk by;
       ambiguous   several, and the licensed PlayStation table cannot choose between them;
  2. read a memory dump, take the live command pointer from `ctx+0x1c` (falling back to the descriptor
     `*(0x80115284)` that the handler itself reads);
  3. walk: `opcode = byte[p]`, `p += length[opcode]`, recording each command's bytes.

The extent rule is the load-bearing part. These handlers are layout-adjacent and Ghidra has no function
range for several of them, so a scan with a fixed forward window reads advances out of its neighbours -
which is how M136's map and M141's first correction both went wrong. The extent is
min(next handler in the table, next Ghidra function start, +0x1000 bytes).

Guards, because a wrong length desynchronises the whole walk:

  * a command is only accepted when `byte[p]` is a table index in status `ok`, and the next address stays
    inside RDRAM;
  * the walk **stops loudly** at the first `unverified` or `ambiguous` opcode. 24 opcodes are
    `unverified` today, and for five of them that is the semantics rather than a gap: the named
    control-flow commands (`Goto`, `GoSub`, `ForStart`, `Switch`, `ElseStart`) set the pointer from an
    operand instead of advancing it by a constant.

Opcode names and PlayStation command sizes come from `fixtures/scd/opcodes.json`, transcribed from the
MIT-licensed OpenBiohazard2 (`fileio/rdt_scd.go`). The port's own measured advance always wins over the
PlayStation size, and any disagreement is printed rather than hidden.

For opcode `0x44` (`SceEmSet`, 22 bytes) it also prints byte 3 - that command's `Id` field - and byte 9,
so the walk answers "which enemy id does a room ask for?" directly.

Usage:
  ./walk_stream.py --lens                  # the whole opcode -> length map, with names and statuses
  ./walk_stream.py --self-test             # the synthetic fixture (15 cases)
  ./walk_stream.py <rdram-dump.bin> [--commands 64]
"""
import argparse
import json
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


PS1_FIXTURE = "fixtures/scd/opcodes.json"
RANGES_FIXTURE = "fixtures/decomp/ranges.json"


def ps1_opcodes() -> dict:
    """opcode -> [(name, size)] from the MIT-licensed OpenBiohazard2 table.

    The sizes are the *PlayStation* command sizes, derived by that project's own struct fields. They name
    our opcodes; they do not overrule our measurement — where the two disagree, the handler's own advance is
    what the console actually does, and the disagreement is reported rather than hidden.
    """
    try:
        doc = json.loads(Path(PS1_FIXTURE).read_text())
    except (OSError, ValueError):
        return {}
    out = {}
    for key, variants in doc.get("opcodes", {}).items():
        out[int(key, 16)] = [(v["name"], v["size"]) for v in variants]
    return out


_RANGES = None


def _stage2_ranges():
    global _RANGES
    if _RANGES is None:
        try:
            rng = json.loads(Path(RANGES_FIXTURE).read_text())["images"]["stage2"]
            _RANGES = sorted(((f["start"], f["end"]) if isinstance(f, dict) else (f[0], f[1])) for f in rng)
        except (OSError, KeyError, ValueError, TypeError):
            _RANGES = []
    return _RANGES


def handler_extent(h, words, base, handlers) -> int:
    """Where this handler ends: the next handler in the table, the next Ghidra function, or 0x1000 bytes.

    The table bound matters because these handlers are layout-adjacent and Ghidra has **no range at all**
    for several of them — which is how M136's scans came to read advances from outside the handler.
    """
    closer = [x for x in handlers if x > h]
    end = min(closer) if closer else base + 4 * len(words)
    for s, _e in _stage2_ranges():
        if h < s < end:
            end = s
    for s, e in _stage2_ranges():
        if s <= h < e:
            end = min(end, e)
    return min(end, h + 0x1000)


def advance_set(h, words, base, handlers) -> list:
    """Every distinct positive advance of `ctx+0x1c` performed inside the handler's own extent."""
    n = len(words)
    if not (base <= h < base + 4 * n):
        return []
    j0 = (h - base) // 4
    lim = min((handler_extent(h, words, base, handlers) - base) // 4, n)
    out = set()
    for j in range(j0, min(lim, n - 6)):
        w = words[j]
        if (w >> 26) != 0x23 or (w & 0xFFFF) != CTX_CMDPTR:
            continue
        loaded, rbase = (w >> 16) & 0x1F, (w >> 21) & 0x1F
        for k in range(j + 1, min(lim, n)):
            y = words[k]
            if (y >> 26) != 0x09 or ((y >> 21) & 0x1F) != loaded or not (y & 0xFFFF):
                continue
            n_adv = y & 0xFFFF
            n_adv = n_adv - 0x10000 if n_adv & 0x8000 else n_adv
            dst = (y >> 16) & 0x1F
            # Handlers frequently record other state between the add and the write-back, so the store is
            # allowed up to 8 instructions later - but the first store to `ctx+0x1c` decides: if it writes a
            # different register, this add was not the pointer advance and is dropped. Opcode 0x32 advances
            # four instructions after its `addiu` (`sw a1,40(v1)` x3 in between), which a two-instruction
            # window misses; the PlayStation size for it is 8, and the measured advance is 8.
            for m in range(k + 1, min(k + 9, n)):
                z = words[m]
                if (z >> 26) == 0x2B and (z & 0xFFFF) == CTX_CMDPTR:
                    if ((z >> 21) & 0x1F) == rbase and ((z >> 16) & 0x1F) == dst and n_adv > 0:
                        out.add(n_adv)
                    break
                if (z >> 26) == 0x03 or ((z >> 26) == 0 and (z & 0x3F) == 0x08):
                    # A call or return ends this candidate — but its **delay slot still executes first**, and
                    # two handlers write the pointer back there (0x28 stores cmd+1 before its call, 0x45
                    # stores cmd+5 in the return delay slot), so the slot is checked before giving up.
                    slot = m + 1
                    if slot < min(k + 9, n):
                        z2 = words[slot]
                        if ((z2 >> 26) == 0x2B and (z2 & 0xFFFF) == CTX_CMDPTR
                                and ((z2 >> 21) & 0x1F) == rbase and ((z2 >> 16) & 0x1F) == dst
                                and n_adv > 0):
                            out.add(n_adv)
                    break
    return sorted(out)


JUMP_FAMILY = {
    0x07: {"size": 4, "operand": ("u16", 2), "base": "cmd", "add": 0, "conditional": True,
           "from": "0x8006dc84 lhu v0,2(v1) -> 0x8006dc8c addu v1,v1,v0 -> sw v1,28(a0)"},
    0x0D: {"size": 6, "operand": ("s16", 2), "base": "cmd", "add": 6, "conditional": True,
           "from": "0x8006dea4 lh t0,2(a3) -> addu v0,a3,t0 -> 0x8006deac addiu v0,v0,6 -> sw v0,28(r10)"},
    0x13: {"size": 4, "operand": ("u16", 2), "base": "cmd", "add": 0, "conditional": True,
           "from": "0x8006e288 lhu t0,2(a3) -> 0x8006e2b8 addu a0,a3,t0 (case-table skip); the body then "
                   "scans 0x0c-marked case entries and lands on a match or on that skip target"},
    0x17: {"size": 6, "operand": ("s16", 4), "base": "cmd", "add": 0, "conditional": False,
           "from": "0x8006e3a4 lh t0,4(a1) -> 0x8006e3bc addu a1,a1,t0 -> 0x8006e3d0 sw a1,28(a0)"},
    0x18: {"size": 2, "operand": ("u8", 1), "base": "script_table", "add": 0, "conditional": False,
           "saves_return": True,
           "from": "0x8006e3dc lbu a2,1(v1) -> sll a2,a2,6 -> +*(0x80114f2c) -> lhu v0,0(a2) -> "
                   "0x8006e42c addu v0,v1,v0 -> sw v0,28(a0); the return address `cmd+2` is saved to "
                   "0x8006e3f0 sw v1,324(v0)"},
}


def near_conditional(op, sups):
    """True when the command has a fall-through we can take (everything except an unconditional jump)."""
    spec = JUMP_FAMILY.get(op)
    return bool(spec and spec["conditional"])


def _read_operand(cmd, kind, offset):
    width = {"u8": 1, "s8": 1, "u16": 2, "s16": 2}[kind]
    if len(cmd) < offset + width:
        return None
    raw = int.from_bytes(cmd[offset:offset + width], "big")
    if kind.startswith("s") and raw >= (1 << (8 * width - 1)):
        raw -= 1 << (8 * width)
    return raw


def successors(op, cmd, addr):
    """Where a control-flow command goes next: [(target or None, how)], plus the fall-through when it has one.

    `target` is None when the destination is dynamic — GoSub needs the runtime script table, whose base is
    loaded from `*(0x80114f2c)` and is therefore not in the image.
    """
    spec = JUMP_FAMILY.get(op)
    if spec is None:
        return []
    value = _read_operand(cmd, *spec["operand"])
    out = []
    if value is None:
        return [("truncated", "command shorter than its operand")]
    if spec["base"] == "script_table":
        # The destination is `record.u16 + script_base`, and **both** come from outside the command: the
        # base is `*(0x80114f2c)` at runtime and the u16 sits at record offset 0. The command carries only
        # the record index, so this is dynamic by construction, not for want of trying.
        out.append((None, f"dynamic: script record {value} (base *(0x80114f2c) + record u16@0)"))
    else:
        target = addr + value + spec["add"]
        how = f"cmd{value:+d}" + (f"{spec['add']:+d}" if spec["add"] else "")
        out.append((target, how))
    if spec["conditional"]:
        out.append((addr + spec["size"], "fall-through"))
    return out


def resolve(words, base=STAGE2_BASE, table=TABLE, entries=TABLE_ENTRIES) -> dict:
    """opcode -> what to walk by, its name, and whether walking by it is defensible.

    status is one of:
      ok          exactly one advance inside the handler's own extent — walk by it;
      unverified  **no** advance inside that extent, so the number published at M136 came from outside the
                  handler; refuse rather than guess (this is the M141 correction made operational);
      ambiguous   several advances inside the extent and the licensed table does not choose between them.
    """
    n = len(words)
    handlers = sorted({words[(table + 4 * i - base) // 4] for i in range(entries)
                       if 0 <= (table + 4 * i - base) // 4 < n
                       and base <= words[(table + 4 * i - base) // 4] < base + 4 * n})
    ps1 = ps1_opcodes()
    out = {}
    for i in range(entries):
        off = (table + 4 * i - base) // 4
        if not (0 <= off < n):
            continue
        h = words[off]
        if not (base <= h < base + 4 * n):
            continue
        advances = advance_set(h, words, base, handlers)
        variants = ps1.get(i, [])
        name = variants[0][0] if variants else ""
        chosen = None
        if len(advances) == 1:
            status, chosen = "ok", advances[0]
            same = [v for v in variants if v[1] == chosen]
            if same:
                name = same[0][0]
        elif not advances:
            status = "unverified"
        else:
            picked = [v for v in variants if v[1] in advances]
            if len(picked) == 1:
                status, chosen = "ok", picked[0][1]
                name = picked[0][0]
            else:
                status = "ambiguous"
        if i in JUMP_FAMILY:
            spec = JUMP_FAMILY[i]
            status, chosen = "jump", spec["size"]
            same = [v for v in variants if v[1] == chosen]
            if same:
                name = same[0][0]
        conflict = bool(variants) and chosen is not None and chosen not in [v[1] for v in variants]
        out[i] = {"handler": h, "length": chosen, "advances": advances, "status": status,
                  "name": name, "ps1_sizes": [v[1] for v in variants], "conflict": conflict}
    return out


def report_lengths(words) -> int:
    """Print the whole opcode -> length map with names and safety, and fail if anything is unresolved."""
    res = resolve(words)
    ps1 = ps1_opcodes()
    named = sum(1 for r in res.values() if r["name"])
    ok = [i for i, r in res.items() if r["status"] == "ok"]
    unverified = [i for i, r in res.items() if r["status"] == "unverified"]
    ambiguous = [i for i, r in res.items() if r["status"] == "ambiguous"]
    jumps = [i for i, r in res.items() if r["status"] == "jump"]
    conflicts = [i for i, r in res.items() if r["conflict"]]
    print(f"opcode -> command length: {len(res)} of {TABLE_ENTRIES} handlers, "
          f"{named} named from the MIT-licensed PlayStation table")
    for i in range(TABLE_ENTRIES):
        if i not in res:
            continue
        r = res[i]
        length = "  ?" if r["length"] is None else f"{r['length']:2d}"
        tag = {"ok": "ok", "jump": "JUMP", "unverified": "UNVERIFIED", "ambiguous": "AMBIGUOUS"}[r["status"]]
        extra = ""
        if r["conflict"]:
            extra = f"  (ps1 size {r['ps1_sizes']} disagrees)"
        print(f"  0x{i:02x}: {r['handler']:#010x}  len {length}  {tag:10s} "
              f"{r['name'] or '-':14s} advances={r['advances']}{extra}")
    print(f"  named: {named} of {len(res)}; ps1 table has {len(ps1)} opcode number(s)")
    print(f"  walkable {len(ok)}, jump-family {len(jumps)}, unverified {len(unverified)}, "
          f"ambiguous {len(ambiguous)}, size conflicts {len(conflicts)}")
    if jumps:
        print(f"  jump family (target computed from an operand, decoded from the handler): "
              f"{[hex(i) + ' ' + str(res[i]['name']) for i in jumps]}")
    if unverified:
        print(f"  UNVERIFIED (no advance inside the handler's own extent): "
              f"{[hex(i) for i in unverified]}")
        print("  These are the opcodes whose M136 length came from outside the handler. A walk stops at "
              "the first of them rather than advancing by a number the handler never performs.")
    if ambiguous:
        print(f"  AMBIGUOUS (several advances, table does not choose): {[hex(i) for i in ambiguous]}")
    print(f"  {len(ok) + len(jumps)}/{len(res)} opcodes walkable (of which {len(jumps)} by computed target)")
    return 0 if not ambiguous else 1


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

    # --- naming and length-safety cases: a second synthetic table, wide enough to reach named opcodes
    B2, T2, E2 = 0x80000000, 0x80002000, 0x85          # wide enough to reach opcode 0x7f
    w2 = [0] * 0x9000
    def put2(va, x): w2[(va - B2) // 4] = x
    def handler_at(slot, advances):
        h = B2 + 0x4000 + slot * 0x100
        put2(h, lw(2, 0x1C, ctx))
        for k, n in enumerate(advances):
            put2(h + 4 + 8 * k, addiu(2, 2, n))
            put2(h + 8 + 8 * k, sw(2, 0x1C, ctx))
        put2(T2 + 4 * slot, h)
    handler_at(0x44, [22])          # named, and the ps1 size agrees
    handler_at(0x09, [1])           # named, but the ps1 size disagrees
    handler_at(0x7F, [])            # no advance at all -> must be unverified, never guessed
    handler_at(0x26, [4, 9])        # two advances; only 4 matches a ps1 variant -> table decides
    handler_at(0x50, [4, 5])        # two advances, no ps1 entry -> ambiguous, the walk must stop
    res2 = resolve(tuple(w2), base=B2, table=T2, entries=E2)
    op44, op09, op7f = res2.get(0x44, {}), res2.get(0x09, {}), res2.get(0x7F, {})
    op26, op50 = res2.get(0x26, {}), res2.get(0x50, {})
    def succ(op, raw, addr):
        return [(t, h) for t, h in successors(op, bytes(raw), addr)]
    cases += [
        ("Goto target is cmd + s16 at byte 4, with no fall-through",
         [t for t, _h in succ(0x17, [0x17, 0, 0, 0, 0xFF, 0xFA], 0x1000)], [0x0FFA]),
        ("ElseStart has a jump target (u16 at byte 2) and a fall-through",
         [t for t, _h in succ(0x07, [0x07, 0, 0x00, 0x0A], 0x1000)], [0x100A, 0x1004]),
        ("ForStart target is cmd + s16 at byte 2 + 6 (its own size), plus fall-through",
         [t for t, _h in succ(0x0D, [0x0D, 0, 0x00, 0x04, 0, 0], 0x1000)], [0x100A, 0x1006]),
        ("Switch has a case-table skip target and a header fall-through",
         [t for t, _h in succ(0x13, [0x13, 0, 0x00, 0x14], 0x1000)], [0x1014, 0x1004]),
        ("GoSub carries only a record index, so its destination stays dynamic",
         [t for t, _h in succ(0x18, [0x18, 0x03], 0x1000)], [None]),
    ]
    cases += [
        ("the ps1 fixture loads and names SceEmSet at 0x44",
         (ps1_opcodes().get(0x44) or [(None, None)])[0], ("SceEmSet", 22)),
        ("0x26 carries two ps1 variants (Calc/Calc2)",
         len(ps1_opcodes().get(0x26, [])), 2),
        ("a named opcode resolves to its own advance and its name",
         (op44.get("status"), op44.get("length"), op44.get("name")), ("ok", 22, "SceEmSet")),
        ("a handler with no advance is unverified, never guessed",
         (op7f.get("status"), op7f.get("length")), ("unverified", None)),
        ("a measured length disagreeing with the ps1 size is flagged",
         (op09.get("status"), op09.get("conflict")), ("ok", True)),
        ("two advances plus one matching ps1 size -> the table decides, and names it",
         (op26.get("status"), op26.get("length"), op26.get("name")), ("ok", 4, "Calc2")),
        ("two advances with no ps1 entry are ambiguous, not guessed",
         (op50.get("status"), op50.get("length"), op50.get("name")), ("ambiguous", None, "")),
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

    res = resolve(words)
    named = sum(1 for r in res.values() if r["name"])
    unverified = {i for i, r in res.items() if r["status"] == "unverified"}
    print(f"opcode -> command length: {len(res)} of {TABLE_ENTRIES} handlers, {named} named, "
          f"{len(unverified)} unverified (a walk stops at those)")
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
            if op not in res:
                kind = ("not a table index (>= 141) -> the stream ENDED here and the walk left "
                        "the command area" if op >= TABLE_ENTRIES else
                        "a table index with no resolvable handler")
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} — {kind}")
                break
            r = res[op]
            if r["status"] == "jump":
                length = r["length"]
                cmd = rd(p, min(length, 64))
                sups = successors(op, cmd, p)
                label = f" {r['name']}" if r["name"] else ""
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x}{label} len {length:2d} -> "
                      f"{cmd[:8].hex(' ')}")
                for target, how in sups:
                    shown = "dynamic" if target is None else f"{target:#010x}"
                    print(f"        {how:34s} -> {shown}")
                if op == 0x13:                      # Switch: the case table follows the header
                    p += length
                    continue
                if not near_conditional(op, sups):
                    # an unconditional computed jump (Goto) can be followed; GoSub cannot be resolved
                    statics = [t for t, _h in sups if t is not None]
                    if len(sups) == 1 and statics:
                        print(f"        following the computed target (not the fall-through)")
                        p = statics[0]
                        continue
                    print(f"        STOP: destination is dynamic, so the walk cannot continue")
                    break
                p += length                        # conditional: follow the fall-through and say so
                continue
            if r["status"] != "ok":
                which = ("no advance inside its own handler" if r["status"] == "unverified"
                         else "several advances and the table does not choose")
                print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x} {r['name'] or ''} — STOP: {which}. "
                      f"Walking on would advance by a guess and desynchronise the rest of the walk.")
                break
            handler, length = r["handler"], r["length"]
            cmd = rd(p, min(length, 64))
            seen[op] = seen.get(op, 0) + 1
            extra = ""
            if op == SLOT_OPCODE:
                slot = cmd[3] if len(cmd) > 3 else None
                gate = cmd[9] if len(cmd) > 9 else None
                slots.append((p, slot, gate))
                extra = f"  Id(byte3)={slot}" + (f"  gate(byte9)={gate:#04x}" if gate is not None else "")
            label = f" {r['name']}" if r["name"] else ""
            print(f"  [{k:2d}] {p:#010x}: opcode 0x{op:02x}{label} len {length:2d} -> "
                  f"{cmd[:8].hex(' ')}{extra}")
            p += length
        print(f"\n  distinct opcodes: {len(seen)}; top: "
              f"{sorted(seen.items(), key=lambda kv: -kv[1])[:6]}")
        if slots:
            print(f"  scene-slot commands: {len(slots)}; Id values {sorted(s for _, s, _ in slots)}")
        else:
            print("  scene-slot commands (opcode 0x44 SceEmSet): none in this walk")


if __name__ == "__main__":
    main()
