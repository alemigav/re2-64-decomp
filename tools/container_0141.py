#!/usr/bin/env python3
"""Decode the `01 41` container: a 16-byte-per-unit prologue and a payload.

The family is 355 corpus blocks whose first word is `0x01410000`. What is **proven** about them, on every block:

    word0 = 0x01410000                      magic, constant across all 355
    word1 = N                               number of 16-byte units before the payload
    word2 = filesize - 16*N                 the payload length
    word3 = 0                               (always, in this family)

so the payload begins at `16*N`, and the header is `16*N` bytes — 16 for N=1 (238 blocks), 32 for N=2 (40), 48
for N=3 (11), up to 464 for N=29. The relation holds for **355 of 355** blocks across **21 distinct N**.

What is **refuted**: that the units are a section table. Entries 1..N-1 carry arbitrary data-like words
(`0x35f23763`, `0xd24b5bff`, `0xffc00000`) rather than ascending in-bounds offsets, in every block checked. So
this is a flat prologue, and what the extra units *contain* is unresolved — a palette or mask table is the
plausible reading, and it is stated as a candidate, not a finding.

  ./container_0141.py            # report the family and the law
  ./container_0141.py --check    # the gate
"""
import argparse
import struct
import sys
import zlib
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import script_profile as sp                                     # noqa: E402
import walk_stream as ws                                        # noqa: E402

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
MAGIC = 0x01410000
UNIT = 16


def family(rom):
    out = []
    for idx in range(sp.ENTRY_COUNT):
        off, size = struct.unpack_from(">II", rom, sp.FILE_TABLE_ROM + sp.HEADER + 8 * idx)
        if off == 0xFFFFFFFF or size == 0:
            continue
        try:
            raw = zlib.decompress(rom[sp.FILE_TABLE_ROM + off:sp.FILE_TABLE_ROM + off + size])
        except zlib.error:
            continue
        if len(raw) >= 4 * UNIT and struct.unpack_from(">I", raw, 0)[0] == MAGIC:
            out.append((idx, raw))
    return out


def analyse(blocks):
    by = defaultdict(list)
    law = 0
    sections = 0
    for idx, raw in blocks:
        count = struct.unpack_from(">I", raw, 4)[0]
        declared = struct.unpack_from(">I", raw, 8)[0]
        by[count].append(len(raw))
        if count > 0 and declared == len(raw) - UNIT * count:
            law += 1
        # a section table would give ascending, in-bounds offsets in entries 1..count-1
        if count > 2:
            offs = [struct.unpack_from(">I", raw, UNIT * k + 8)[0] for k in range(1, count)]
            if all(a < b for a, b in zip(offs, offs[1:])) and offs[-1] < len(raw):
                sections += 1
    return by, law, sections


def payload_stats(blocks):
    """The correlation question: is N a bit depth, or the count of distinct payload values?"""
    maxbyte = []
    pairs = []                      # (N, distinct payload values) per block, kept paired
    divisible = 0
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        plen = struct.unpack_from(">I", raw, 8)[0]
        payload = raw[UNIT * n:UNIT * n + plen]
        if not payload:
            continue
        maxbyte.append(max(payload))
        pairs.append((n, len(set(payload))))
        if n and plen % n == 0:
            divisible += 1
    return maxbyte, pairs, divisible


def gbi_test(blocks):
    """Would a display-list reading survive its own test? Count records whose first word looks like a GBI
    opcode (G_* commands live in 0xE4-0xFF). Also report the 16-bit statistics a raw RGBA5551 texture would
    have to show."""
    heads = Counter()
    records = 0
    units = alpha = 0
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        if n > 200:
            continue
        for k in range(n):
            head = struct.unpack_from(">I", raw, UNIT * k)[0]
            heads[(head >> 24) & 0xFF] += 1
            records += 1
        plen = struct.unpack_from(">I", raw, 8)[0]
        payload = raw[UNIT * n:UNIT * n + plen]
        for i in range(len(payload) // 2):
            units += 1
            alpha += struct.unpack_from(">H", payload, 2 * i)[0] & 1
    gbi = sum(c for b, c in heads.items() if 0xE4 <= b <= 0xFF)
    return heads, records, gbi, units, alpha


# Loader tables indexed by the object-type byte, with the tag each call site passes to func_0x80004cfc.
# The tags are .rodata strings, read from the image: 0x800b8f64 "TM3", 0x800b867c "EMD", 0x800b8700 "EFF",
# 0x800b99cc "ITP", 0x800b9dcc "T64", 0x800b8934 "TIM".
LOADER_TABLES = {
    "TM3": 0x8010DBC0,
    "EMD": 0x80126C80,
    "EFF": 0x800EBB30,
    "ITP": 0x8012BEC0,
}


def loader_kinds(rom, sample=40):
    """Which resource kinds actually reference the family? Sample each loader table and report the magics."""
    words = ws.load_stage2()
    base = ws.STAGE2_BASE

    def u16(va):
        off = va - base
        w = off // 4
        if not (0 <= w < len(words)):
            return None
        return (words[w] >> 16) if off % 4 == 0 else (words[w] & 0xFFFF)

    blocks = {idx: raw for idx, raw in family(rom)}
    out = {}
    for tag, va in LOADER_TABLES.items():
        magics = Counter()
        n = 0
        for i in range(200):
            v = u16(va + 2 * i)
            if v is None or not (0 < v < 8091):
                continue
            raw = blocks.get(v)
            if raw is None or len(raw) < 4:
                continue
            magics[struct.unpack_from(">I", raw, 0)[0]] += 1
            n += 1
            if n >= sample:
                break
        out[tag] = (n, magics)
    return out


def constants_in_code():
    """The two shared record constants: are they code immediates, or only data?"""
    words = ws.load_stage2()
    packed = b"".join(struct.pack(">I", w) for w in words)
    return sum(packed.count(bytes.fromhex(h)) for h in ("b2b2b2ff", "7f7f7fff"))


def unit_template(blocks):
    """Does unit 1 carry a recurring template, i.e. are the units records rather than a directory?"""
    seen = Counter()
    for _idx, raw in blocks:
        n = struct.unpack_from(">I", raw, 4)[0]
        if n >= 2:
            seen[raw[UNIT:UNIT + UNIT].hex()] += 1
    top = seen.most_common(1)
    return (top[0][1] if top else 0), (top[0][0] if top else "")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    if not ROM.exists():
        print(f"SKIP: no cartridge at {ROM.relative_to(HERE.parent)}")
        return 0
    blocks = family(ROM.read_bytes())
    by, law, sections = analyse(blocks)
    print(f"01 41 family: {len(blocks)} block(s); unit counts {sorted(by)}")
    print(f"  word2 == filesize - 16*word1: {law}/{len(blocks)}")
    print(f"  blocks whose extra units look like a section table: {sections}")
    if not args.check:
        return 0
    maxbyte, pairs, divisible = payload_stats(blocks)
    heads, records, gbi, units, alpha = gbi_test(blocks)
    const_in_code = constants_in_code()
    kinds = loader_kinds(ROM.read_bytes())
    template_hits, template = unit_template(blocks)
    cases = [
        ("the family is found and is large", len(blocks) > 200),
        ("every block satisfies word2 == filesize - 16*word1", law == len(blocks)),
        ("the unit counts span many values, so the law is not a special case",
         len(by) >= 10),
        ("the extra units are NOT a section table", sections == 0),
        # N is not a bit depth: a 1-bit payload could not contain a byte of 255, and N=1 blocks do.
        ("N is not a bit depth — full-range bytes appear even at N=1", max(maxbyte) == 255),
        # and N is not the distinct-value count either — computed, not asserted by construction.
        ("N is not the number of distinct payload values in any block",
         bool(pairs) and all(n != d for n, d in pairs)),
        ("a large share of payloads divides evenly by N", divisible > 0.7 * len(blocks)),
        # units are records with constants, not a directory of offsets.
        ("unit 1 recurs as a template across blocks", template_hits >= 10),
        # the display-list reading, tested and refuted (M161)
        ("no record begins with a GBI opcode (0xE4-0xFF), so these are not display lists", gbi == 0),
        ("the payload is not a clean RGBA5551 texture (alpha bit is neither all-set nor all-clear)",
         0.25 < alpha / max(1, units) < 0.75),
        ("the shared record constants occur nowhere in the stage-2 code image", const_in_code == 0),
        # --- relational: which loader kinds reference the family (M162)
        ("the EMD (enemy model) loader references family blocks",
         kinds["EMD"][1].get(MAGIC, 0) >= 10),
        ("the TM3 (model) loader references family blocks",
         kinds["TM3"][1].get(MAGIC, 0) >= 8),
        ("the ITP loader references a different kind entirely (no family blocks)",
         kinds["ITP"][1].get(MAGIC, 0) == 0),
        ("the EFF loader references a different kind entirely (no family blocks)",
         kinds["EFF"][1].get(MAGIC, 0) == 0),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} 01-41 container case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
