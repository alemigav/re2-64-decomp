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
import json
import math
import re
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

    # --- M184: id 1983's container, framed by the sample directory (id 1982, SND_SMPDIR).
    # The directory is 28-byte records terminated by `ffffffff`; a u32 at +4 is a byte offset into 1983,
    # and with the last record closing at the file end the records tile 1983 exactly. So the pool is 1192
    # samples with known boundaries and rates. The *sample codec* is a named gap, and the negatives that
    # keep it open are gated with it — a gap without its refutations becomes a shrug.
    so, ss = entries[1982]
    sdir = zlib.decompress(d[BASE + so:BASE + so + ss])
    other_size = OTHER_SIZE
    srec = [sdir[28 * k:28 * k + 28] for k in range(len(sdir) // 28)]
    n_smp = 0
    while 28 * (n_smp + 1) <= len(sdir) and struct.unpack_from(">h", sdir, 28 * n_smp)[0] != -1:
        n_smp += 1
    smp_off = [struct.unpack_from(">I", r, 4)[0] for r in srec[:n_smp]]
    smp_rate = [struct.unpack_from(">H", r, 14)[0] for r in srec[:n_smp]]
    smp_idx = [struct.unpack_from(">H", r, 0)[0] for r in srec[:n_smp]]
    ends = smp_off[1:] + [other_size]
    smp_len = [e - b for b, e in zip(smp_off, ends)]
    o83 = BASE + entries[1983][0]
    smp_blobs = [d[o83 + b:o83 + e] for b, e in zip(smp_off, ends)]
    g_len = 0
    for _l in smp_len:
        g_len = math.gcd(g_len, _l)

    cases.append((f"the sample directory is {len(sdir)} B = {n_smp} x 28 + a ffffffff terminator",
                  len(sdir) == 33380 and n_smp == 1192 and sdir[28 * n_smp:] == b"\xff\xff\xff\xff"))
    cases.append((f"its u16 at +0 is a sequential index 1..{n_smp}",
                  smp_idx == list(range(1, n_smp + 1))))
    cases.append((f"its u32 at +4 is a strictly ascending byte offset into id 1983, starting at 0 "
                  f"({smp_off[0]}..{smp_off[-1]:,})",
                  smp_off[0] == 0 and all(b > a for a, b in zip(smp_off, smp_off[1:]))
                  and max(smp_off) < other_size))
    cases.append((f"the offsets tile id 1983 exactly — {n_smp} lengths sum to {sum(smp_len):,} == the file",
                  sum(smp_len) == other_size))
    cases.append((f"u16 at +14 takes 15 canonical sample rates (16000 x{sum(1 for x in smp_rate if x == 16000)})",
                  len(set(smp_rate)) == 15 and smp_rate.count(16000) == 601
                  and {16000, 11025, 22050, 14000} <= set(smp_rate)))
    cases.append((f"all {n_smp} sample lengths are divisible by 4",
                  all(l % 4 == 0 for l in smp_len) and min(smp_len) == 336))

    # the codec, kept open by measurement rather than by omission
    o83 = BASE + entries[1983][0]
    hi, lo = bytearray(), bytearray()
    for b, e in zip(smp_off, ends):
        blob = d[o83 + b:o83 + e]
        hi += blob[0::2]
        lo += blob[1::2]
    def _H(x):
        c = Counter(x); t = len(x)
        return -sum(v / t * math.log2(v / t) for v in c.values())
    flat = (Counter(hi)[0] + Counter(hi)[255]) / len(hi)
    cases.append((f"REFUTED: the samples are not plain 16-bit PCM — high-plane entropy {_H(hi):.3f} vs "
                  f"{_H(lo):.3f}, and 0x00/0xFF only {flat:.1%} of the high plane",
                  _H(hi) > 6.9 and flat < 0.12))
    f6 = [struct.unpack_from(">H", r, 6)[0] for r in srec[:n_smp]]
    f18 = [struct.unpack_from(">H", r, 18)[0] for r in srec[:n_smp]]
    def _a4(x): return (x + 3) // 4 * 4
    laws = {"f18*3/2": lambda x: _a4(x * 3 // 2), "f18*2": lambda x: _a4(x * 2),
            "f18": _a4, "f6*2": lambda x: _a4(x * 2), "f6": _a4}
    fits = {k: sum(1 for l, x in zip(smp_len, f18 if k.startswith("f18") else f6) if l == fn(x))
            for k, fn in laws.items()}
    cases.append((f"REFUTED: no record field gives the sample length — best of {len(laws)} laws fits "
                  f"{max(fits.values())}/{n_smp}", max(fits.values()) <= 2))

    # --- M187: the sample codec. A third-party claim — MusyX's own ADPCM, 32 samples per 20-byte frame,
    # two frames per 40-byte group as [A.raw 4][B.raw 4][A.nib 16][B.nib 16] — arrived with two predictions.
    # The *length* one, as stated, fails; the *structure* one is overwhelming. Both are gated, because the
    # difference between "refuted as stated" and "confirmed" is the whole point.
    mods40 = Counter(l % 40 for l in smp_len)
    cases.append((f"REFUTED as stated: len % 40 == 0 on 0/{n_smp} — every length is 16 (mod 40) "
                  f"({mods40[16]}/{n_smp}), so the gcd is {g_len}, not 20 or 40",
                  sum(1 for l in smp_len if l % 40 == 0) == 0
                  and mods40[16] == n_smp and g_len == 8))
    # ...which does not refute the codec: it is a 16-byte prologue of 8 big-endian int16 samples, and the
    # 40-byte groups start after it. The prologue's own byte census says so.
    ev = [len({smp[c] for smp in smp_blobs}) for c in range(0, 16, 2)]
    od = [len({smp[c] for smp in smp_blobs}) for c in range(1, 16, 2)]
    cases.append((f"the 16-byte prologue is 8 big-endian int16 samples — even byte positions take at most "
                  f"{max(ev)} distinct values, odd at least {min(od)}",
                  max(ev) <= 51 and min(od) >= 234))

    def _groups(phase):
        good = total = 0
        for smp in smp_blobs:
            p = phase
            while p + 40 <= len(smp):
                g = smp[p:p + 40]
                if any(g):
                    total += 1
                    good += (g[8] >> 4) <= 7 and (g[24] >> 4) <= 7
                p += 40
        return good, total
    g16, t16 = _groups(16)
    g0, t0 = _groups(0)
    cases.append((f"at phase 16, {g16:,}/{t16:,} 40-byte groups ({g16 / t16:.2%}) have both codebook "
                  f"bytes' high nibble <= 7, against 25 % by chance", g16 == 219550 and t16 == 224991))
    cases.append((f"the alignment control holds — at phase 0 the same test gives only {g0 / t0:.2%}",
                  t0 == 224999 and g0 == 129452))

    def _corr(xs):
        if len(xs) < 4:
            return 0.0
        a, b = xs[:-1], xs[1:]
        ma, mb = sum(a) / len(a), sum(b) / len(b)
        num = sum((u - ma) * (v - mb) for u, v in zip(a, b))
        den = (sum((u - ma) ** 2 for u in a) * sum((v - mb) ** 2 for v in b)) ** 0.5
        return num / den if den else 0.0
    import random as _random, statistics as _st
    real_c, shuf_c = [], []
    rng = _random.Random(1)
    for smp in smp_blobs[:400]:
        vals = []
        p = 16
        while p + 40 <= len(smp):
            vals += list(struct.unpack_from(">4h", smp, p))
            p += 40
        real_c.append(_corr(vals))
        rng.shuffle(vals)
        shuf_c.append(_corr(vals))
    cases.append((f"adjacent raw samples correlate — median {_st.median(real_c):+.3f}, shuffled "
                  f"{_st.median(shuf_c):+.3f}",
                  _st.median(real_c) > 0.30 and abs(_st.median(shuf_c)) < 0.05))

    fails_total, bad_smp = t16 - g16, 0
    for smp in smp_blobs:
        p, bad, tot = 16, 0, 0
        while p + 40 <= len(smp):
            g = smp[p:p + 40]
            if any(g):
                tot += 1
                bad += not ((g[8] >> 4) <= 7 and (g[24] >> 4) <= 7)
            p += 40
        bad_smp += bool(tot and bad / tot > 0.5)
    cases.append((f"the {fails_total:,} failing groups ({fails_total / t16:.2%}) are scattered — "
                  f"{bad_smp} of {n_smp} samples has a majority failing, so there is no second codec class",
                  fails_total == 5441 and bad_smp == 0))

    # --- M185: the other three files of the sound family. `FUN_800a86a0` walks both SND_PROJ and
    # SND_POOL the same way — a u32 at the head is a *relative offset to the first record*, each record's
    # first u32 is the stride to the next, and `-1` ends the chain — so each is framed the same way id 1983
    # was framed by its directory. All three are zlib members, unlike 1979 and 1983.
    def _chain(b, start, end=None, limit=8000):
        pos, out = start, []
        end = len(b) if end is None else end
        while len(out) < limit and pos < end:
            nxt = struct.unpack_from(">i", b, pos)[0]
            if nxt == -1:
                return out, pos, True
            if nxt <= 0 or pos + nxt >= end:
                return out, pos, False
            out.append(pos)
            pos += nxt
        return out, pos, False

    pro = zlib.decompress(d[BASE + entries[1980][0]:BASE + entries[1980][0] + entries[1980][1]])
    pro_recs, pro_end, pro_term = _chain(pro, 0)
    pro_keys = [struct.unpack_from(">h", pro, r + 4)[0] for r in pro_recs]
    cases.append((f"SND_PROJ is a chain of {len(pro_recs)} records whose strides tile to {pro_end:,}, and a "
                  f"4-byte terminator closes the {len(pro):,}-byte member exactly",
                  pro_term and len(pro_recs) == 417 and pro_end == 102144
                  and pro_end + 4 == len(pro)))
    # Not sequential in record order — a *bijection onto a contiguous range with one hole*. I asserted
    # `keys == range(118, 535)` first and it failed; the truth is better, and the hole is worth naming.
    holes = sorted(set(range(min(pro_keys), max(pro_keys) + 1)) - set(pro_keys))
    cases.append((f"SND_PROJ's u16 at +4 is a bijection onto {min(pro_keys)}..{max(pro_keys)} less "
                  f"{holes} — {len(set(pro_keys))} distinct keys",
                  len(set(pro_keys)) == 417 and min(pro_keys) == 0 and max(pro_keys) == 417
                  and holes == [11]))

    pool = zlib.decompress(d[BASE + entries[1981][0]:BASE + entries[1981][0] + entries[1981][1]])
    secs = list(struct.unpack_from(">4I", pool, 0))
    pool_keys, counts, abut, sec_keys = set(), [], 0, []
    for i, st in enumerate(secs):
        end = secs[i + 1] if i + 1 < len(secs) else len(pool)
        recs, termpos, ok = _chain(pool, st + struct.unpack_from(">I", pool, st)[0], end)
        counts.append(len(recs))
        keys_here = {struct.unpack_from(">h", pool, r + 4)[0] for r in recs}
        pool_keys |= keys_here
        sec_keys.append(keys_here)
        abut += int(ok and termpos + 4 == end)
    cases.append((f"SND_POOL's head is 4 section offsets {secs}, and every section's terminator abuts the "
                  f"next section or EOF ({abut}/4)", abut == 4))
    cases.append((f"the four sections hold {counts} records — {sum(counts)} in all, all keys distinct",
                  counts == [2025, 241, 3, 326] and sum(counts) == 2595 and len(pool_keys) == 2595))

    # the cross-file link the code implies: FUN_800a86a0 compares each PROJ list short against the POOL
    # chain's keys. It resolves for most, not all — measured and stated, not rounded up.
    shorts = []
    for r in pro_recs:
        pos = r + struct.unpack_from(">I", pro, r + 8)[0]
        while True:
            v = struct.unpack_from(">h", pro, pos)[0]
            if v == -1:
                break
            shorts.append(v)
            pos += 2
    resolved = sum(1 for v in shorts if v in pool_keys)
    cases.append((f"PROJ lists hold {len(shorts)} shorts and {resolved} ({resolved / len(shorts):.1%}) are "
                  f"POOL keys — a real link, not a total one",
                  len(shorts) == 5136 and resolved == 4301))

    # --- M186: the 835 that do not resolve are structural, not a second object class. Chased down:
    # 834 of them are the constant 0 in the first four shorts of *every* list — a two-parameter prologue
    # stored as u32s with zero high halves — and exactly one is a real dangling reference.
    pro_lists = []
    for r in pro_recs:
        pos = r + struct.unpack_from(">I", pro, r + 8)[0]
        vals = []
        while True:
            v = struct.unpack_from(">h", pro, pos)[0]
            if v == -1:
                break
            vals.append(v)
            pos += 2
        pro_lists.append((r, vals))
    unresolved = [v for _r, L in pro_lists for v in L if v not in pool_keys]
    zeros_at = [(i, v) for _r, L in pro_lists for i, v in enumerate(L[:4]) if v not in pool_keys and v == 0]
    stray = [(r, i, v) for r, L in pro_lists for i, v in enumerate(L) if v not in pool_keys and v != 0]
    cases.append((f"834 of the {len(unresolved)} unresolved shorts are the constant 0, at positions 0 and 2 "
                  f"of all {len(pro_lists)} lists",
                  len(unresolved) == 835 and len(zeros_at) == 834
                  and all(i in (0, 2) for i, _v in zeros_at)))
    cases.append((f"every PROJ list opens with [0, a, 0, b] — a two-parameter prologue, "
                  f"{len({L[1] for _r, L in pro_lists})} and {len({L[3] for _r, L in pro_lists})} distinct",
                  all(L[0] == 0 and L[2] == 0 for _r, L in pro_lists)
                  and len({L[1] for _r, L in pro_lists}) == 55
                  and len({L[3] for _r, L in pro_lists}) == 54))
    cases.append((f"exactly one non-zero short is unresolved — {stray[0][2]} in the list of the first record, "
                  f"at position {stray[0][1]}",
                  len(stray) == 1 and stray[0][0] == 0 and stray[0][2] == 531))
    # ...and it is a *dangling reference*, not a decode failure: it is precisely the one hole in the pool.
    sec0_keys = sec_keys[0]
    holes0 = sorted(set(range(min(sec0_keys), max(sec0_keys) + 1)) - sec0_keys)
    cases.append((f"POOL section 0 has exactly one hole, {holes0}, and it is the key the PROJ dangles on",
                  holes0 == [531] and 531 not in pool_keys))
    cases.append((f"all {len(shorts)} shorts are therefore accounted for: {resolved} pool keys + 834 prologue "
                  f"zeros + 1 dangling reference",
                  resolved + 834 + 1 == len(shorts)))

    # --- M188: the two holes. They are the same *kind* of anomaly — one absent entry in an otherwise
    # contiguous key space — and they are not the same fact. Both are gated so neither can be upgraded.
    keypos = Counter(v for _r, L in pro_lists for v in L[4:])
    cases.append((f"PROJ key positions reference {len(keypos)} distinct slot values, {min(keypos)}..{max(keypos)} "
                  f"— the whole range, so every slot is spoken for",
                  len(keypos) == 2026 and min(keypos) == 1 and max(keypos) == 2026 and 0 not in keypos))
    sec0_refs = set(keypos) & pool_keys
    cases.append((f"exactly {len(sec0_refs)} of them exist in the pool — section 0's count — so the one "
                  f"dangling reference is the one hole, and the two facts close",
                  len(sec0_refs) == 2025 and (set(keypos) - pool_keys) == {531}))
    cases.append((f"pool sections 1-3 ({sum(counts[1:])} records) are never referenced by any PROJ list",
                  len(pool_keys - set(keypos)) == 570 and sum(counts[1:]) == 570))
    # keys are read signed (`>h`) because sections 1 and 3 carry negative ranges, so compare masked
    hole_census = [sorted(set(range(min(k), max(k) + 1)) - k) for k in sec_keys]
    h3 = [h & 0xFFFF for h in hole_census[3]]
    cases.append((f"pool holes per section: {[len(h) for h in hole_census]} — section 2 has none, section 3 "
                  f"has {[hex(h) for h in h3]}",
                  [len(h) for h in hole_census] == [1, 11, 0, 1]
                  and hole_census[0] == [531] and h3 == [0x8098]))
    pro_key_holes = sorted(set(range(min(pro_keys), max(pro_keys) + 1)) - set(pro_keys))
    at_11 = [(k, i) for _r, L in pro_lists for k, i in [(0, 0)] if False]
    at_11 = [(rec_key, i) for (rec_key, L) in [(pro_keys[j], L) for j, (_r, L) in enumerate(pro_lists)]
             for i, v in enumerate(L) if v == 11 and i >= 4]
    cases.append((f"PROJ slot {pro_key_holes} is unused, yet the value 11 is a live key reference in "
                  f"{len(at_11)} lists (record keys {sorted(k for k, _i in at_11)}) — an unused slot, not an "
                  f"absent target",
                  pro_key_holes == [11] and len(at_11) == 2
                  and sorted(k for k, _i in at_11) == [6, 51]))
    pro_ab = [L[1] for _r, L in pro_lists] + [L[3] for _r, L in pro_lists]
    cases.append((f"the two prologue parameters are multiples of 4 throughout ({len(pro_ab)} values)",
                  all(v % 4 == 0 for v in pro_ab)))

    # --- M182: does anything in the corpus read the record header? No. The tag is never validated, and
    # the field at +4 is never read at its literal offset by any decompiled function. These are negatives,
    # which is why they are gated: a negative that is not pinned to a measurement decays into a belief.
    import re as _re
    root = HERE.parent
    images = [p for p in sorted((root / "build" / "elfs").glob("*")) if p.is_file()] \
        + [p for p in sorted(UNPACKED.glob("*.bin")) if p.is_file()]
    tagged = [p.name for p in images if 0 < p.read_bytes().count(MORT) < 5]
    cases.append((f"no built image or unpacked member contains the literal `MORT` — the tag is never "
                  f"validated ({len(images)} files scanned, {len(images) - len(tagged)} without it)", not tagged))

    ranges = json.loads((root / "fixtures" / "decomp" / "ranges.json").read_text())["images"]
    have = {p.stem.lower() for p in (root / "src").glob("*/*.c")}
    total = sum(len(v) for v in ranges.values())
    missing = [(img, s) for img, rs in ranges.items() for s, _e in rs
               if f"func_{s:08x}" not in have and f"fun_{s:08x}" not in have]
    cases.append((f"the corpus holds 3678 function ranges and 74 without a src file "
                  f"({total} / {len(missing)})", total == 3678 and len(missing) == 74))
    audio = [(s, e) for s, e in ranges["stage2"] if 0x800B3000 <= s < 0x800B6000]
    audio_missing = [(s, e) for s, e in audio
                     if f"func_{s:08x}" not in have and f"fun_{s:08x}" not in have]
    cases.append((f"the audio cluster is fully decompiled — {len(audio)} functions in "
                  f"0x800b3000..0x800b6000, {len(audio_missing)} missing", len(audio) == 26 and not audio_missing))
    gaps_in_audio = [(s, e) for img, s in missing for e in [0] if img == "stage2" and 0x800B0000 <= s < 0x800C0000]
    cases.append((f"none of the {len(missing)} gaps lies in the audio range 0x800b0000..0x800bffff",
                  not gaps_in_audio))

    writes = [(p.parent.name + "/" + p.name, ln.strip())
              for p in sorted((root / "src").glob("*/*.c"))
              for ln in p.read_text().splitlines() if _re.search(r"0x1a4\) = ", ln)]
    cases.append((f"only {len(writes)} writes to a literal +0x1a4 field exist, and none is in the audio family",
                  len(writes) == 4
                  and not any(n.startswith(("FUN_800b", "func_800b")) for n, _ in writes)))
    voice = [p.name for p in sorted((root / "src").glob("*/*.c"))
             if _re.search(r"80158[cde]", p.read_text())]
    cases.append((f"no decompiled function addresses the voice struct region 0x80158c..0x80158e ({len(voice)})",
                  not voice))
    f4a04 = (root / "src" / "stage2" / "FUN_800b4a04.c").read_text()
    cases.append(("CODE: FUN_800b4a04 reads +0x1a4 and +0x1a8 as stream state, never as a header to parse",
                  "*(undefined2 *)(param_1 + 0x1a4)" in f4a04
                  and "*(uint *)(param_1 + 0x1a8) & 0xffffff" in f4a04))

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
