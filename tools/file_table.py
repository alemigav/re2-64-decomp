#!/usr/bin/env python3
"""The cartridge file table: a census, and the format of the two files that were "unidentified".

`cart_record(0x43)` is `0xb00c8624` (M146): a `0x28`-byte header whose first word is a count, then
`count` 8-byte `{offset, size}` entries relative to cart `0xC8624`. Every milestone since M146 treated
that table as a **zlib manifest**, because the files it was first used on are zlib members.

It is not. It is the whole file system, and most of it is stored **raw**:

    entries                 8091     113 exact sentinels (offset 0xFFFFFFFF, size 0)
    real                    7978     4852 begin `68 DE` and inflate, 3126 do not (58 270 043 B)
    4852 ->                4726     distinct offsets; 126 entries are repeats over 67 shared offsets
    walked members          4761     4726 from this table + 35 that live in the boot descriptor table

The 3 126 non-zlib entries are the media, stored uncompressed — their heads are `ffd8ffe0` x1257
(JPEG) and `000001b3` x271 (MPEG-1), which reproduces M9's independently carved counts.

That reframes the 17.6 MB. It is not a region between files:

    id 1983   cart 0x0b73fbc..0x140ed7c   9 022 912 B   (was "R3", M9 bounds are 9 B / 8 B looser)
    id 1979   cart 0x0338fea..0x0b630fe   8 560 916 B   (was "R4")
    sum                                   17 583 828 B

Both are named by the sound init (`FUN_800759d8`) beside three files it tags on the way in —
`SND_PROJ` (0x7bc), `SND_POOL` (0x7bd), `SND_SMPDIR` (0x7be) — and those three are exactly the entries
that tile the space between them (ids 1980-1982). The sound family is ids 1979-1983, contiguous in cart
order, and the whole 17.6 MB belongs to it.

id 1979's own format is decoded here. `FUN_800b3f54` consumes `[u32 count][count x u32]`, and the file
is that, followed by `count` records:

    header   u32 count = 588, then 588 x u32 `0x01000000 | offset`
             first offset == 4 + 4*count (the table's own end); 587/587 ascending; 588/588 in range
    record   `MORT` u16 field u16 rate u16 0      (10-byte header, then payload)
             magic MORT 588/588, rate in {16000, 8000} 588/588, +8 == 0 588/588

Three things are deliberately *not* claimed:

* `u16` at +4 is **unassigned**. It is not the record length (`len == 32*field` holds 0/588), and no
  constant header size makes the payload a multiple of 16 or 9 — so "16-byte VAG frames" is refuted for
  this container, not confirmed.
* `MORT` is a literal tag with no assigned meaning. It is the ASCII at every record start, and nothing
  more is known.
* Whether id 1983 is audio at all is **inferred** from the call site, not proven. Its head reads as
  small signed 16-bit values and its mean entropy (7.169) differs from id 1979's (7.925), but no code
  reading of a parser exists yet.

The N64-Tools claim that RE2's table is `[flag][u24 addr]` at cart `0x2C794` is checked and **refuted**
here: that span holds 2 577 words whose first byte takes no flag distribution at all, and whose
`(u24 < romsize)` test cannot fail for any 64 MB cartridge.

  ./file_table.py --check     # the gated cases
  ./file_table.py --report    # the census, for a human
"""
import argparse
import struct
import sys
import zlib
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
UNPACKED = HERE.parent / "assets" / "unpacked"

BASE = 0x0C8624          # cart_record(0x43), masked; the loader's base
HEADER = 0x28            # bytes before the first {offset,size} entry

COUNT = 8091             # header word 0
SENTINELS = 113          # offset 0xFFFFFFFF and size 0 — the only well-formed empty form
REAL = 7978
ZLIB = 4852              # real entries whose payload begins `68 DE`
NONZLIB = 3126
DISTINCT_ZLIB = 4726     # ... over this many distinct offsets: 126 entries are repeats
WALKED = 4761            # tools/unpack_zlib.py, M9
WALK_ONLY = 35           # members the walker finds that this table does not name

BANK, OTHER = 1979, 1983
# Cart offsets, as the notes quote them. The table stores offsets *relative* to BASE, so anything that
# compares against an entry field or slices the cartridge must subtract BASE first — doing it twice is
# the error this constant pair is shaped to prevent.
BANK_CART, BANK_SIZE = 0x0338FEA, 8560916
OTHER_CART, OTHER_SIZE = 0x0B73FBC, 9022912
BANK_REL, OTHER_REL = BANK_CART - BASE, OTHER_CART - BASE

# M9's region bounds, kept only to show the file is inside them: 9 B looser at the head, 8 B at the tail.
R4_M9 = (0x0338FE1, 0x0B63106)
R3_M9 = (0x0B73FB3, 0x140ED84)

MORT = b"MORT"
RATE = 16000
RATE_HALF = 8000
N64_TOOLS_TABLE = 0x2C794, 0x2EFD8


def load():
    d = ROM.read_bytes()
    count = struct.unpack_from(">I", d, BASE)[0]
    entries = [struct.unpack_from(">II", d, BASE + HEADER + 8 * i) for i in range(count)]
    return d, count, entries


def records(r4, count):
    """Record extents: consecutive directory offsets, the last one closing at the file end."""
    vals = struct.unpack_from(">" + str(count) + "I", r4, 4)
    offs = [v & 0xFFFFFF for v in vals] + [len(r4)]
    return vals, [(offs[k], offs[k + 1]) for k in range(count)]


def check() -> int:
    d, count, entries = load()
    cases = []

    sentinel = [e for e in entries if e == (0xFFFFFFFF, 0)]
    half = [e for e in entries if (e[0] == 0xFFFFFFFF) != (e[1] == 0)]
    real = [(i, o, s) for i, (o, s) in enumerate(entries) if o != 0xFFFFFFFF and s != 0]
    zl = [(i, o, s) for i, o, s in real if d[BASE + o:BASE + o + 2] == b"\x68\xde"]
    nz = [(i, o, s) for i, o, s in real if d[BASE + o:BASE + o + 2] != b"\x68\xde"]

    cases.append(("header word 0 is the entry count, 8091", count == COUNT))
    cases.append(("113 exact sentinels, and no half-formed empty entry",
                  len(sentinel) == SENTINELS and not half))
    cases.append(("7978 real entries = 4852 zlib + 3126 non-zlib",
                  len(real) == REAL and len(zl) + len(nz) == REAL
                  and len(zl) == ZLIB and len(nz) == NONZLIB))
    cases.append(("every real extent lies inside the cartridge",
                  all(BASE + o + s <= len(d) for _, o, s in real)))

    # the non-zlib class is the raw class, and it is the media
    heads = Counter(d[BASE + o:BASE + o + 4] for _, o, s in nz)
    jpeg = sum(c for h, c in heads.items() if h[:3] == b"\xff\xd8\xff")
    mpeg = heads[b"\x00\x00\x01\xb3"]
    cases.append(("the non-zlib class is media: 1257 JPEG and 271 MPEG-1 heads, as M9 carved",
                  jpeg == 1257 and mpeg == 271))

    # the 17.6 MB is two files
    cases.append(("ids 1979 and 1983 are the two unidentified files, 17583828 B together",
                  entries[BANK] == (BANK_REL, BANK_SIZE)
                  and entries[OTHER] == (OTHER_REL, OTHER_SIZE)
                  and BANK_SIZE + OTHER_SIZE == 17583828))
    cases.append(("both files sit inside M9's region bounds, 9 B in at the head and 8 B at the tail",
                  (BANK_CART - R4_M9[0], R4_M9[1] - (BANK_CART + BANK_SIZE)) == (9, 8)
                  and (OTHER_CART - R3_M9[0], R3_M9[1] - (OTHER_CART + OTHER_SIZE)) == (9, 8)))

    # the sound family tiles: no padding, just the three tagged files
    between = sorted(i for i, o, s in real if BANK_REL + BANK_SIZE <= o < OTHER_REL)
    straddling = [t for t in real
                  if t[1] < OTHER_REL and t[1] + t[2] > BANK_REL + BANK_SIZE]
    cases.append(("the gap between them is exactly ids 1980/1981/1982 - SND_PROJ/POOL/SMPDIR",
                  between == [1980, 1981, 1982] and len(straddling) == 3))
    trailer = d[BANK_CART + BANK_SIZE:BANK_CART + BANK_SIZE + 8]
    cases.append(("the 8 bytes after id 1979 encode its own size (0082a114 = 8560916)",
                  struct.unpack_from(">I", trailer, 4)[0] == BANK_SIZE))

    # id 1979: the directory
    r4 = d[BANK_CART:BANK_CART + BANK_SIZE]
    n = struct.unpack_from(">I", r4, 0)[0]
    vals, recs = records(r4, n)
    offs = [a for a, _ in recs]
    cases.append(("id 1979 opens with u32 588, and the first offset is the table's own end",
                  n == 588 and offs[0] == 4 + 4 * n))
    cases.append(("587/587 offsets ascend and 588/588 are in range",
                  all(b >= a for a, b in zip(offs, offs[1:])) and all(a < BANK_SIZE for a in offs)))

    # id 1979: the records
    magic = sum(1 for a, b in recs if r4[a:a + 4] == MORT)
    rate = sum(1 for a, b in recs if struct.unpack_from(">H", r4, a + 6)[0] in (RATE, RATE_HALF))
    zero = sum(1 for a, b in recs if struct.unpack_from(">H", r4, a + 8)[0] == 0)
    cases.append(("588/588 records begin with `MORT`", magic == 588))
    cases.append(("588/588 rate fields are 16000 or 8000", rate == 588))
    cases.append(("588/588 words at +8 are zero", zero == 588))

    # the flag bit is not a flag: it is set exactly where the rate is 16000
    noflag = {k for k, v in enumerate(vals) if v >> 24 == 0}
    half_rate = {k for k, (a, b) in enumerate(recs)
                 if struct.unpack_from(">H", r4, a + 6)[0] == RATE_HALF}
    cases.append(("the offset's top byte is set on exactly the 16000 Hz records, 23/23",
                  len(noflag) == 23 and noflag == half_rate))

    # refutations, kept so they cannot be quietly re-proposed
    field = [struct.unpack_from(">H", r4, a + 4)[0] for a, _ in recs]
    lens = [b - a for a, b in recs]
    cases.append(("REFUTED: u16 at +4 is not the record length (len == 32*field, 0/588)",
                  sum(1 for f, l in zip(field, lens) if l == 32 * f) == 0))
    cases.append(("REFUTED: the payload is not 16-byte framed under a 10-byte header (0/588)",
                  sum(1 for l in lens if (l - 10) % 16 == 0) == 0))

    # --- M179: u16 at +4, tested against the three readings that were on the table, and the code
    # reading that upgrades the directory from "correlated" to "read". The refutations are values, not
    # opinions, so they stay gated; the code cases pin the three expressions that make FUN_800b3704 a
    # reading, so a re-decompile that loses them invalidates the claim instead of silently keeping it.
    pay = [l - 10 for l in lens]
    rate = [struct.unpack_from(">H", r4, a + 6)[0] for a, _ in recs]
    ms = [pay[k] / 2 / rate[k] * 1000 for k in range(n)]
    cases.append(("REFUTED: u16 at +4 is not a MIDI base note (503/588 above 127)",
                  sum(1 for x in field if x > 127) == 503))
    cases.append(("REFUTED: u16 at +4 is not a duration in ms for 16-bit mono PCM "
                  "(exact on 8/588)", sum(1 for k in range(n) if abs(field[k] - ms[k]) < 1) == 8))
    cases.append(("REFUTED: u16 at +4 is not a sample count (payload/2 and payload/4: 0/588)",
                  sum(1 for k in range(n) if pay[k] // 2 == field[k]) == 0
                  and sum(1 for k in range(n) if pay[k] // 4 == field[k]) == 0))
    cases.append(("u16 at +4 is 3.1-11.4% of its payload on 588/588 — why a loop point is doubtful, "
                  "not merely unconfirmed",
                  all(0.03 < field[k] / pay[k] < 0.115 for k in range(n))))
    # Parity is 272/588 odd: random. That refutes a byte offset in 2-byte units and nothing else — it is
    # *not* evidence against a count, and the ratio band above is what does that work.
    cases.append(("odd on 272/588 — refutes a byte offset in 2-byte units, and says nothing more",
                  sum(1 for x in field if x % 2) == 272))

    src = (HERE.parent / "src")
    f3704 = (src / "stage2" / "FUN_800b3704.c").read_text()
    cases.append(("CODE: FUN_800b3704 bounds the index by the 588 count and reads the directory word's "
                  "top byte as the rate (0 -> 8000, else 16000)",
                  "param_1 < _DAT_8015af80" in f3704
                  and "*(char *)(param_1 * 4 + _DAT_8015af7c) == '\\0'" in f3704
                  and "param_2 = 16000" in f3704 and "param_2 = 8000;" in f3704))
    cases.append(("CODE: FUN_800b3704 takes the record address as the low 24 bits plus _DAT_8015af78",
                  "& 0xffffff) + _DAT_8015af78" in f3704))
    f4a6c = (src / "boot" / "FUN_80004a6c.c").read_text()
    cases.append(("CODE: FUN_80004a6c uses the same idiom — bit 0x8000 selects 8000, & 0x7fff the index",
                  "uVar1 & 0x8000" in f4a6c and "uVar1 & 0x7fff" in f4a6c
                  and "uVar2 = 16000;" in f4a6c and "uVar2 = 8000;" in f4a6c))

    # id 1983 has none of that structure
    r3 = d[OTHER_CART:OTHER_CART + OTHER_SIZE]
    cases.append(("id 1983 carries no MORT record, and its word 0 is not a count",
                  r3.count(MORT) == 0 and struct.unpack_from(">I", r3, 0)[0] > OTHER_SIZE))

    # the zlib accounting: 4761 walked = 4726 distinct named here + 35 elsewhere
    named = {BASE + o for _, o, _ in zl}
    walked = set()
    for p in sorted(UNPACKED.glob("*.bin")):
        walked.add(int(p.name[:-4].split("_")[1], 16))
    cases.append(("4726 distinct table offsets, all walked, plus 35 the walker finds alone = 4761",
                  len(named) == DISTINCT_ZLIB and len(walked) == WALKED
                  and named <= walked and len(walked - named) == WALK_ONLY
                  and len(zl) - len(named) == 126))

    # the third-party claim, refuted on the bytes it names
    lo, hi = N64_TOOLS_TABLE
    words = (hi - lo) // 4
    flags = Counter(d[lo + 4 * k] for k in range(words))
    share = (flags[0x00] + flags[0x80]) / words
    cases.append(("REFUTED: cart 0x2C794 holds no [flag][u24] table - 0x00/0x80 take %.1f%% of bytes, "
                  "a flag needs 100%%" % (100 * share), words == 2577 and share < 0.20))

    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} file-table case(s)")
    return 0 if passed == len(cases) else 1


def report() -> int:
    d, count, entries = load()
    real = [(i, o, s) for i, (o, s) in enumerate(entries) if o != 0xFFFFFFFF and s != 0]
    zl = [(i, o, s) for i, o, s in real if d[BASE + o:BASE + o + 2] == b"\x68\xde"]
    nz = [(i, o, s) for i, o, s in real if d[BASE + o:BASE + o + 2] != b"\x68\xde"]
    print(f"file table at cart {BASE:#x}: {count} entries, {count - len(real)} sentinels, {len(real)} real")
    print(f"  zlib          {len(zl):5d} entries, {sum(s for _, _, s in zl):>12,} B stored")
    print(f"  non-zlib      {len(nz):5d} entries, {sum(s for _, _, s in nz):>12,} B stored")
    heads = Counter(d[BASE + o:BASE + o + 4].hex() for _, o, s in nz)
    print("  non-zlib heads:", heads.most_common(5))
    print(f"\n  sound family (ids 1979-1983):")
    for i in range(BANK, OTHER + 1):
        o, s = entries[i]
        print(f"    {i}  cart {BASE + o:#09x}..{BASE + o + s:#09x}  {s:>10,} B")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true", help="run the gated cases")
    ap.add_argument("--report", action="store_true", help="print the census")
    args = ap.parse_args()
    if not ROM.exists():
        sys.exit(f"cartridge not found: {ROM}")
    if args.report:
        return report()
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
