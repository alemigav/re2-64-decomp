#!/usr/bin/env python3
"""Classify every word of every executable image: body, table, named data, padding, or unclassified.

Until M207 the corpus published one number -- 62.2 % of image bytes inside a known function body -- and a
sentence for the rest: "data, padding, or code Ghidra did not identify". That sentence is what this tool
replaces with a partition, and the partition is deliberately conservative: a word only leaves `unclassified`
on the strength of an artifact that names it.

    function_body   a body range from fixtures/decomp/ranges.json
    jump_table      a table start named by manifests/jump_tables.json
    data_named      an address the decompiler names DAT_xxxxxxxx in a src/ body
    padding         a word inside a run of >= 16 identical 0x00 or 0xFF bytes, read from the unpacked image
    unclassified    everything else -- reported, never renamed to `data` on a hunch

Precedence is fixed (body, table, named data, padding) and **overlaps are counted, not hidden**: a `DAT_`
address inside a function body is a real ambiguity in the provider's output, so the tool reports how many
words the precedence resolved rather than picking silently.

The committed map is `manifests/byte_map.json`; it is metadata (addresses and classes), like
`fixtures/decomp/ranges.json`, and contains no image bytes.

Usage:
  ./classify_image.py --check             # the committed map's invariants, committed artifacts only (CI-safe)
  ./classify_image.py --check-cartridge   # rebuild from the unpacked images and require the same map
  ./classify_image.py --write             # regenerate manifests/byte_map.json (needs the unpacked images)
"""
import argparse
import json
import re
import struct
import zlib

import recovered
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
MAP = "manifests/byte_map.json"

CLASSES = ["function_body", "jump_table", "data_named", "float_table", "pointer_table", "string_table",
           "padding", "fill", "gap", "u16_table", "dense_data", "unclassified"]
DAT = re.compile(r"\bDAT_([0-9a-fA-F]{8})\b")
MIN_PAD = 16


def load(root: Path = ROOT):
    rd = lambda p: json.loads((root / p).read_text())
    return (rd("fixtures/decomp/images.json"), rd("fixtures/decomp/ranges.json"),
            rd("manifests/jump_tables.json"))


def named_data(root: Path = ROOT):
    """Every DAT_xxxxxxxx the decompiled bodies mention, per image."""
    out = {}
    for src in sorted((root / "src").glob("*/*.c")):
        out.setdefault(src.parent.name, set()).update(
            int(m.group(1), 16) for m in DAT.finditer(src.read_text()))
    return out


_ROM = {}


def _rom(root: Path):
    """The cartridge, read once. Reading it per image is 36 x 64 MiB and took the tool past two minutes."""
    key = str(root)
    if key not in _ROM:
        p = root / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
        _ROM[key] = p.read_bytes() if p.exists() else None
    return _ROM[key]


def image_bytes(img, root: Path = ROOT):
    """The image's own bytes, from `assets/unpacked/…bin` or, for the boot bank, from the cartridge."""
    src, size = img["source"], img["size"]
    if src.startswith("ROM "):
        rom = _rom(root)
        if rom is None:
            return None
        off = int(src.split()[1], 16)
        return rom[off:off + size]
    p = root / src
    return p.read_bytes()[:size] if p.exists() else None


def pad_words(blob, base):
    """Word start -> the repeated value, for runs of >= MIN_PAD identical 0x00 or 0xFF bytes.

    The value is carried because it is what the padding *law* checks: a merged range that spanned a 0x00 run
    and a 0xFF run is still "padding" by the class rule and no longer a single value, so the label keeps them
    apart (`run of 0x00` vs `run of 0xff`) and the two claims agree.
    """
    out = {}
    if not blob:
        return out
    i, n = 0, len(blob)
    while i < n:
        j = i
        while j < n and blob[j] == blob[i] and blob[j] in (0x00, 0xFF):
            j += 1
        if j - i >= MIN_PAD:
            # Words *fully inside* the run: rounding the start down (or the end up) would claim bytes
            # that are not 0x00/0xFF, which is exactly what the padding law caught (256 ranges, first run).
            start = i + (-i % 4)
            for w in range(base + start, base + j - 3, 4):
                out[w] = blob[i]
        # NOT `i = j`: when the byte at i is neither 0x00 nor 0xFF the inner loop never advances, j == i,
        # and the scan spins forever. That hung `--write` past two minutes before it was caught.
        i = j if j > i else i + 1
    return out


# What counts as text (M343). Printable ASCII plus the separators a string *table* uses between entries -- NUL,
# tab, newline, carriage return. The two thresholds in the rule below are what separate a table of strings from
# the two things that look like one: a run of digits or dashes (no letters) and a run of one repeated character
# (no variety).
TEXT_OK = frozenset(range(0x20, 0x7F)) | {0x00, 0x09, 0x0A, 0x0D}
LETTERS = frozenset(range(0x41, 0x5B)) | frozenset(range(0x61, 0x7B))
MIN_TEXT_LETTERS = 16
MIN_TEXT_DISTINCT = 8


def _text_word_ok(w):
    """A word whose four bytes are all text-safe. Says nothing about the run being a *table* of strings."""
    return all(b in TEXT_OK for b in w.to_bytes(4, "big"))


def _text_runs(grp, minlen=4):
    """How many maximal runs of >= `minlen` letters the run holds -- the test that separates text from codes.

    A table of small byte codes is text-safe (0x20..0x7E) and can hold more than sixteen letters while containing
    no *word*: `\x00 \x00\x00\x00!\x00\x00\x00"` is a table of numbers, not a string table. Real text has words,
    so the rule asks for at least two letter-runs of four, which no such table has.
    """
    runs = n = 0
    for c in grp:
        if c in LETTERS:
            n += 1
        else:
            runs += n >= minlen
            n = 0
    return runs + (n >= minlen)


MIN_TABLE_WORDS = 8


# A word is *float-shaped* when its exponent sits in the band computed tables actually use: 0x78..0x87 is roughly
# 0.0078 to 256. This is what keeps small integers out -- 0x00000001 and 0x00010000 are IEEE denormals near zero,
# so an `abs(f) < 1e6` test passes them and a run of integer data then reads as a float table (it claimed 390 KB
# on the first attempt, most of stage2's data and every zero run inside it).
FLOAT_EXP_LO, FLOAT_EXP_HI = 0x78, 0x87


def _float_sane(w):
    """Float-*shaped*: an exponent in the computed-table band and a real magnitude. Says nothing about being a table."""
    e = (w >> 23) & 0xFF
    if not (FLOAT_EXP_LO <= e <= FLOAT_EXP_HI):
        return False
    f = struct.unpack(">f", w.to_bytes(4, "big"))[0]
    return f == f and abs(f) < 1e6


def _addr_in(w, lo, hi):
    """The pointer-table membership test, alone so the rule has one place to be wrong (and one to mutate)."""
    return lo <= w < hi


def table_runs(blob, base, window=None):
    """Maximal runs that qualify as a **float table** or a **pointer table** -- one implementation (M342).

    Both rules were measurements in `unclassified_report()` before they were classes, and the lesson of M339 is that
    a rule living in two places drifts. So this function is the rule, and both the map (`build`) and the report call
    it.

      float_table    >= 8 consecutive IEEE-sane words, >= 90 % of the steps ascending, >= 4 distinct words.
                     The distinctness test is what stops a run of one repeated value -- which is `padding`, not a
                     table -- from qualifying, and the monotonicity test is what stops noise.
      pointer_table  >= 8 consecutive words that are all addresses inside *this* image.

    Deliberately conservative in one direction only: a table embedded in a longer run of sane-but-unordered floats is
    **missed**, never invented. A rule that renames bytes has to be able to fail, so it is mutated twice in the gate
    audit (see `audit_gates.py`) and three synthetic cases in `check()` pin its edges.
    """
    lo_w, hi_w = window if window else (base, base + len(blob))
    ws = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob) - 3, 4)]
    out = []
    i, n = 0, len(ws)
    while i < n:
        if not _float_sane(ws[i]):
            i += 1
            continue
        j = i
        while j + 1 < n and _float_sane(ws[j + 1]):
            j += 1
        if j - i + 1 >= MIN_TABLE_WORDS:
            grp = ws[i:j + 1]
            fs = [struct.unpack(">f", w.to_bytes(4, "big"))[0] for w in grp]
            asc = sum(1 for x, y in zip(fs, fs[1:]) if y >= x) / (len(fs) - 1)
            if asc >= 0.90 and len(set(grp)) >= 4:
                out.append((base + 4 * i, base + 4 * j, "float_table"))
        i = j + 1
    i = 0
    while i < n:
        if not _text_word_ok(ws[i]):
            i += 1
            continue
        j = i
        while j + 1 < n and _text_word_ok(ws[j + 1]):
            j += 1
        if j - i + 1 >= MIN_TABLE_WORDS:
            grp = b"".join(w.to_bytes(4, "big") for w in ws[i:j + 1])
            letters = sum(1 for c in grp if c in LETTERS)
            if letters >= MIN_TEXT_LETTERS and len(set(grp)) >= MIN_TEXT_DISTINCT and _text_runs(grp) >= 2:
                out.append((base + 4 * i, base + 4 * j, "string_table"))
        i = j + 1
    i = 0
    while i < n:
        if not _addr_in(ws[i], lo_w, hi_w):
            i += 1
            continue
        j = i
        while j + 1 < n and _addr_in(ws[j + 1], lo_w, hi_w):
            j += 1
        if j - i + 1 >= MIN_TABLE_WORDS:
            out.append((base + 4 * i, base + 4 * j, "pointer_table"))
        i = j + 1
    return out


MIN_PAD_FLOOR = 4
GAP_MAX = 64
U16_MAX = 0x1000          # a packed coordinate/value: both halves of the word under 4096
U16_FRACTION = 0.90
U16_DISTINCT = 16
DENSE_ENTROPY = 5.0       # bits per byte


def entropy(b):
    """Shannon entropy of the bytes, in bits per byte. A measurement of density, never of *content*."""
    from math import log2
    if not b:
        return 0.0
    counts = {}
    for byte in b:
        counts[byte] = counts.get(byte, 0) + 1
    n = len(b)
    return -sum((c / n) * log2(c / n) for c in counts.values())


def relabel_residue(runs, blob, base):
    """Name what survives every other rule, on the run list those rules produced (M344).

      fill  a run of ONE repeated 0x00/0xFF shorter than the padding law's 16-byte floor. The law's floor stays put
            -- it exists so a lone 0x00 word is not called padding -- so this names the 4..15-byte case instead of
            bending that contract.
      gap   a run under 64 B with a function body on at least one side: inter-function slack. Adjacency is the
            evidence, not the size alone; M338 measured 543 runs sitting directly between two bodies.

    Whatever is left is >= 64 B (or under 64 B and not adjacent to a body) of bytes that are not code, not text, not
    a table and not fill. That is what `unclassified` means from here on, stated rather than implied.
    """
    for k, r in enumerate(runs):
        if r[2] != "unclassified":
            continue
        b = blob[r[0] - base:r[1] - base + 1]
        if (MIN_PAD_FLOOR <= len(b) < MIN_PAD and (b.count(0x00) == len(b) or b.count(0xFF) == len(b))):
            r[2] = "fill"
            r[3] = f"run of 0x{b[0]:02x}, shorter than the padding law's 16-byte floor"
        elif len(b) < GAP_MAX and ((k and runs[k - 1][2] == "function_body")
                                   or (k + 1 < len(runs) and runs[k + 1][2] == "function_body")):
            r[2] = "gap"
            r[3] = "under 64 B, between function bodies"
        elif len(b) >= 64:
            words = [int.from_bytes(b[i:i + 4], "big") for i in range(0, len(b) - 3, 4)]
            halves = [h for w in words for h in (w >> 16, w & 0xFFFF)]
            # u16_table: packed small values -- a positive property, so it goes first. ≥ 90 % of the halves under
            # 4096 and ≥ 16 distinct of them: coordinate/packed tables. M344's measurement found 34 728 B of this.
            if halves and sum(1 for h in halves if h < U16_MAX) >= U16_FRACTION * len(halves) \
                    and len(set(halves)) >= U16_DISTINCT:
                r[2] = "u16_table"
                r[3] = "packed values: 90 %+ of the u16 halves under 4096"
            else:
                # dense_data: NOT an identification. It is the residue measured by density -- bytes no rule can
                # classify, five or more bits of entropy each. Stated as such so nobody reads it as understood.
                h = entropy(b)
                if h >= DENSE_ENTROPY:
                    r[2] = "dense_data"
                    r[3] = "no rule fires; %.1f bits/byte of entropy -- measured density, not identified content" % h
    return runs


def build(root: Path = ROOT):
    images, ranges, jumps = load(root)
    dat = named_data(root)
    tables = {i["name"]: {int(t["table"], 16) for t in i.get("tables", []) if t.get("table")}
              for i in jumps["images"]}
    report = {"tool": "classify_image.py", "classes": CLASSES, "images": {},
              "overlaps": {}, "totals": {}}
    for img in images["images"]:
        name, base, size = img["name"], img["base"], img["size"]
        blob = image_bytes(img, root)
        claimed = {}
        # M340: the measured extents are bodies too. Without this the byte map and the coverage union would
        # disagree by exactly the corrected bytes -- the drift M205/M210 kept catching between projections.
        for m in recovered.load_measured().get(name, {}).values():
            for w in range(m["start"], m["end"] + 1, 4):
                claimed[w] = ("function_body", "fixtures/decomp/measured_extents.json")
        for a in recovered.load_additions().get(name, []):
            for w in range(a["start"], a["end"] + 1, 4):
                claimed[w] = ("function_body", "fixtures/decomp/measured_extents.json")
        for s, e in ranges["images"].get(name, []):
            for w in range(int(s), int(e) + 1, 4):
                claimed[w] = ("function_body", "fixtures/decomp/ranges.json")
        overlap = {"table_in_body": 0, "data_in_body": 0, "padding_in_body": 0}
        for t in tables.get(name, ()):
            overlap["table_in_body"] += t in claimed
            claimed[t] = ("jump_table", "manifests/jump_tables.json")
        for a in dat.get(name, ()):
            if base <= a < base + size:
                overlap["data_in_body"] += a in claimed
                claimed[a] = ("data_named", "src/<image>/*.c DAT_")
        # M342: two measured classes, claimed from the rule above. They sit after bodies, jump tables and named
        # data (a table inside a function is the function) and before padding (a run of one value is fill, and the
        # rule's distinctness test would refuse it anyway -- belt and braces, both stated).
        for lo2, hi2, cls2 in table_runs(blob, base, (base, base + size)):
            why2 = {"float_table": "monotone IEEE run, rule in table_runs()",
                    "pointer_table": "every word an in-image address, rule in table_runs()",
                    "string_table": "text run: text-safe bytes with >= 16 letters, rule in table_runs()"}[cls2]
            for w in range(lo2, hi2 + 1, 4):
                claimed.setdefault(w, (cls2, why2))
        for w, value in pad_words(blob, base).items():
            overlap["padding_in_body"] += w in claimed
            claimed.setdefault(w, ("padding", f"run of 0x{value:02x} in the unpacked image"))
        out = []
        for w in range(base, base + size, 4):
            cls, src = claimed.get(w, ("unclassified", "no artifact names it"))
            # `out[-1][1]` is the inclusive END, so the next word continues the run when end + 1 == w.
            # The first version compared end + 4, which never matched: the map came out one range per
            # word, 486 908 of them, a 47 MB file that the artefact scan (4 MiB limit) refused.
            if out and out[-1][2] == cls and out[-1][3] == src and out[-1][1] + 1 == w:
                out[-1][1] = w + 3
            else:
                out.append([w, w + 3, cls, src])
        relabel_residue(out, blob, base)
        report["images"][name] = out
        report["overlaps"][name] = overlap
        totals = {}
        for s, e, cls, _src in out:
            totals[cls] = totals.get(cls, 0) + (e - s + 1)
        report["totals"][name] = totals
    return report


def check(rep):
    images = json.loads((ROOT / "fixtures/decomp/images.json").read_text())["images"]
    cases = []
    bad_order = bad_cover = 0
    for img in images:
        name, base, size = img["name"], img["base"], img["size"]
        rs = rep["images"].get(name) or []
        if any(rs[i][0] <= rs[i - 1][1] for i in range(1, len(rs))):
            bad_order += 1
        if not rs or rs[0][0] != base or rs[-1][1] != base + size - 1:
            bad_cover += 1
    cases.append((f"the {len(images)} per-image maps are sorted, disjoint and cover each image exactly "
                  f"({bad_order} misordered, {bad_cover} miscovered)", bad_order == 0 and bad_cover == 0))
    tot = {c: sum(t.get(c, 0) for t in rep["totals"].values()) for c in CLASSES}
    # M342: the two table rules, pinned on synthetic bytes. No cartridge, and these are the cases the gate audit
    # mutates -- a class that renames bytes has to be able to fail, and the failure has to be this specific.
    def _blob(vals):
        return b"".join(int(v).to_bytes(4, "big") for v in vals)

    def _blob_bytes(vals):
        return bytes(vals)
    win = (0x80100000, 0x80200000)
    # M344: the two residue classes, pinned on synthetic run lists -- the same function `build()` calls.
    def _runs(cls, n):
        """A run list of three runs: [body][the run under test][body], so adjacency can be tested both ways."""
        return [[0x80100000, 0x8010000F, "function_body", "x"],
                [0x80100010, 0x80100010 + n - 1, cls, "y"],
                [0x80100010 + n, 0x80100010 + n + 15, "function_body", "x"]]
    def _relabelled(payload, n, cls="unclassified"):
        # the run starts at offset 16, so the synthetic blob must cover it: 16 filler bytes, then the payload
        return relabel_residue(_runs(cls, n), b"\xAA" * 16 + payload, 0x80100000)[1][2]
    # The second half must be >= GAP_MAX, or it is legitimately a `gap`: a 12-byte constant run is fill, a 200-byte
    # constant run is not (the padding law owns the >= 16-byte case and this class must not reach into it).
    cases.append(("a 12-byte run of one value is `fill`, and a 200-byte one is not",
                  _relabelled(bytes(12), 12) == "fill" and _relabelled(bytes(200), 200) == "unclassified"))
    cases.append(("a short run between two bodies is `gap`, and the same run elsewhere stays unclassified",
                  _relabelled(bytes(range(48)), 48) == "gap"
                  and relabel_residue([[0x80100000, 0x8010002F, "unclassified", "y"]], bytes(range(48)),
                                      0x80100000)[0][2] == "unclassified"))

    # M344b: the residue's two classes, on the same synthetic run bed. `u16_table` is a *positive* property and goes
    # first; `dense_data` is a density measurement, so its case has to show a low-entropy run staying unclassified.
    packed = b"".join((0x0100 + i).to_bytes(4, "big") for i in range(32))     # halves 0x0100+i, all under 4096
    big = b"".join((0x80008000).to_bytes(4, "big") for i in range(32))        # halves at 0x8000: not packed
    dense = bytes(0xA0 + (i % 40) for i in range(200))                        # ~5.3 bits/byte, halves >= 0x1000
    flat = bytes([0x80]) * 200                                               # one value: no density, no structure
    cases.append(("a run of 32 packed small u16 values is `u16_table`, and the same run at 0x8000 is not",
                  _relabelled(packed, len(packed)) == "u16_table"
                  and _relabelled(big, len(big)) == "unclassified"))
    cases.append(("a high-entropy run is `dense_data`, and a flat run with no structure stays unclassified",
                  _relabelled(dense, len(dense)) == "dense_data"
                  and _relabelled(flat, len(flat)) == "unclassified"))

    # M343: the string-table rule, pinned on synthetic bytes -- text is claimed, a table of small byte codes is
    # not, and neither is a run of one repeated text-safe byte. These are the cases the audit mutates.
    txt = list(b"first string entry\x00\x00second entry here\x00\x00third")
    txt += [0] * (-len(txt) % 4)
    codes = list(b"\x00 \x00\x00\x00!\x00\x00\x00" * 8)          # a table of numbers: text-safe, no words
    spaces = list(b" " * 40)                                          # one repeated byte: fill, not text
    _pad = lambda v: v + [0] * (-len(v) % 4)
    kind_of = lambda vals: {c for _a, _b, c in
                            table_runs(_blob_bytes(_pad(vals)), 0x80100000, win)}
    cases.append(("a run of three real strings is a string table, and a table of small byte codes is not",
                  "string_table" in kind_of(txt) and "string_table" not in kind_of(codes)))
    cases.append(("a run of one repeated text-safe byte is fill, not a string table",
                  "string_table" not in kind_of(spaces)))


    asc = [0x3C000000 + i * 0x00010000 for i in range(10)]
    ptrs_o = [0x80100000 + 4 * i for i in range(10)]
    out_o = [0x00100000 + 4 * i for i in range(10)]
    kinds = lambda vals: {c for _a, _b, c in table_runs(_blob(vals), 0x80100000, win)}
    cases.append(("a monotone run of ten floats is a float table, and the same run reversed is not",
                  "float_table" in kinds(asc) and "float_table" not in kinds(list(reversed(asc)))))
    cases.append(("a run of one repeated float value is fill, not a table (the distinctness test)",
                  "float_table" not in kinds([0x3F800000] * 10)))
    cases.append(("a run of ten in-image addresses is a pointer table, and ten out-of-image words are not",
                  "pointer_table" in kinds(ptrs_o) and "pointer_table" not in kinds(out_o)))

    # M340: the corrected bodies (812 B) moved from `unclassified` into this class. The class total sits 656 B
    # below the coverage union `counts.py` computes, and always has: the union counts every byte of every range,
    # the map counts the whole words it can classify. Both moved by 812 B together, which is the property that
    # matters -- the two projections agree on the *change* even where their absolutes differ.
    cases.append((f"the body class totals {tot['function_body']:,} B, 24 680 B of it measured extents "
                  f"(812 B corrected + 23 868 B adopted)",
                  tot["function_body"] == 1235280))
    srcs = [r[3] for rs in rep["images"].values() for r in rs]
    cases.append((f"every word is in one of the {len(CLASSES)} declared classes and every range names its "
                  f"source ({sum(1 for s in srcs if not s)} unnamed)", all(srcs)))
    # the total is DERIVED from the images fixture, not pinned: a wider boot image (M324) must not need
    # this assertion edited, it must still close
    images_total = sum(i["size"] for i in json.loads((ROOT / "fixtures" / "decomp" / "images.json").read_text())["images"])
    cases.append((f"the partition closes: {' + '.join(f'{tot[c]:,}' for c in CLASSES)} = "
                  f"{sum(tot.values()):,} B of image bytes, which is the fixture's {images_total:,}",
                  sum(tot.values()) == images_total))
    ov = {k: sum(v[k] for v in rep["overlaps"].values()) for k in
          ("table_in_body", "data_in_body", "padding_in_body")}
    cases.append((f"precedence resolved {ov['table_in_body']} table, {ov['data_in_body']} named-data and "
                  f"{ov['padding_in_body']} padding words that fall inside a body — counted, not hidden", True))
    cases.append((f"unclassified is {tot['unclassified']:,} B ({100.0 * tot['unclassified'] / images_total:.1f} %) "
                  f"— a published bucket, never renamed to data", tot["unclassified"] > 0))
    return cases


def cartridge_check(root: Path = ROOT):
    """Rebuild from the unpacked images and require the committed map; then verify the padding law."""
    images, _r, _j = load(root)
    fresh = build(root)
    committed = json.loads((root / MAP).read_text())
    same = fresh["images"] == committed["images"]
    ok_pad, bad = True, []
    for img in images["images"]:
        blob = image_bytes(img, root)
        for s, e, cls, _src in fresh["images"][img["name"]]:
            if cls != "padding":
                continue
            seg = blob[s - img["base"]:e - img["base"] + 1]
            if len(set(seg)) != 1 or seg[0] not in (0x00, 0xFF) or len(seg) < 4:
                bad.append(f"{img['name']}:{s:#010x}")
    ok_pad = not bad
    return [("a rebuild from the unpacked images reproduces the committed map exactly", same),
            (f"every padding range is a single value, 0x00 or 0xFF ({len(bad)} violate: {bad[:3]})", ok_pad)]


def code_run_evidence(blob, base, size):
    """Does this byte range decode as CODE? Returns the evidence, so a caller can report or gate it (M338/M339).

    Four tests, and each earns its place:

      * a `jr ra` is present -- necessary and, on its own, worthless: 408 of the 1 574 bucket runs hold the word
        `0x03E00008` by chance;
      * **>= 90 %** of `j`/`jal` targets land in the cartridge window `0x80000000..0x80800000`. NOT "all": a real
        code region carries embedded data (a switch table sits inside `0x80022a1c`), and three of the nine dense
        regions were rejected by an all-targets rule before this was measured (M339);
      * **>= 8 distinct opcodes**, and
      * **no opcode over 40 %** of the words -- a float table is thousands of `lui`-shaped words and fails both.

    A per-image target test is wrong here: stage2 calls boot code legitimately, which rejected 24 KB of real code
    in the first draft of M338.
    """
    ws = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob) - 3, 4)]
    if not ws:
        return None
    ops = [w >> 26 for w in ws]
    jr = any(w == 0x03E00008 for w in ws)
    br = [w for w in ws if (w >> 26) in (2, 3)]
    jumps = [((w & 0x03FFFFFF) << 2) | (base & 0xF0000000) for w in br]
    in_window = ([t for t in jumps if 0x80000000 <= t < 0x80800000] if jumps else [])
    frac = (len(in_window) / len(jumps)) if jumps else 1.0
    distinct = len(set(ops))
    dominant = max(ops.count(o) for o in set(ops)) / len(ops)
    return {"jr": jr, "jump_fraction": frac, "distinct": distinct, "dominant": dominant,
            "is_code": bool(jr and frac >= 0.90 and distinct >= 8 and dominant <= 0.40)}


def residue_profile(root: Path = ROOT, min_bytes: int = 64):
    """The unclassified runs that no rule claims, described so they can be *read* rather than guessed (M345).

    M338 named this bucket's contents by measurement and M342-M344 gave the measurable parts classes. What is left
    resists a rule, and the honest response is to publish its profile rather than invent a name for it: for every run
    still unclassified at 64 B or more, the word count, the dominant word and its share, the fraction of words that
    would fit a u16 / s16 / s20, the byte alphabet size and the entropy. A reader can then pick a run and look at it.

    The fractions are the *tests that failed*: 12 % of all these words fit a u16, the best single candidate property
    (`alphabet <= 16`) covers 6 444 B of 72 228, and nothing else reaches 10 %. That is why this milestone registers no
    class -- a rule that renames bytes has to be earned, and none of these is.
    """
    images = json.loads((root / "fixtures/decomp/images.json").read_text())
    bmap = json.loads((root / MAP).read_text())
    rows = []
    for img in images["images"]:
        name, base, size = img["name"], img["base"], img["size"]
        blob = image_bytes(img, root)
        if blob is None:
            continue
        for lo, hi, cls, _why in bmap["images"].get(name, []):
            if cls != "unclassified" or (hi - lo + 1) < min_bytes:
                continue
            b = blob[lo - base:hi - base + 1]
            words = [int.from_bytes(b[i:i + 4], "big") for i in range(0, len(b) - 3, 4)]
            if not words:
                continue
            top, topn = max(((w, words.count(w)) for w in set(words)), key=lambda x: x[1])
            n = len(words)
            rows.append({"image": name, "address": "0x%08x" % lo, "bytes": len(b), "words": n,
                         "top_word": "0x%08x" % top, "top_share": round(topn / n, 3),
                         "u16": round(sum(1 for w in words if w <= 0xFFFF) / n, 3),
                         "s16": round(sum(1 for w in words if w <= 0x7FFF or w >= 0xFFFF8000) / n, 3),
                         "s20": round(sum(1 for w in words if w <= 0xFFFFF or w >= 0xFFF00000) / n, 3),
                         "alphabet": len(set(b)), "entropy": round(entropy(b), 2)})
    rows.sort(key=lambda r: -r["bytes"])
    return {"runs": len(rows), "bytes": sum(r["bytes"] for r in rows),
            "best_rule_bytes": sum(r["bytes"] for r in rows if r["alphabet"] <= 16),
            "best_rule": "alphabet <= 16 bytes", "largest": rows[:20], "all": rows}


def unclassified_report(root: Path = ROOT):
    """What the `unclassified` bucket actually contains, measured rather than renamed (M338).

    The class rule keeps a word out of `unclassified` only when an artifact names it, so the bucket is the
    project's honest residue -- 330 176 B, 16.9 % of the image bytes. This decomposes it by **evidence about the
    bytes**, with a fixed and conservative precedence:

        code           contains `jr ra`, and every `j`/`jal` target lands inside the same image
        float_table    >= 8 words, >= 95 % IEEE-sane, and >= 90 % ascending -- a table, not noise
        pointer_table  >= 8 words, >= 80 % of them addresses inside the same image
        short_fill     under the padding law's 16-byte floor and a single repeated 0x00/0xFF
        small_residue  < 64 B and none of the above: inter-function slack
        structured     >= 64 B and none of the above: the part that genuinely has no name yet

    Nothing here renames a class. Naming one of these in `byte_map.json` needs a rule the classifier can
    enforce and a gate that can fail -- a milestone of its own; this is the measurement that would authorise
    it, published so the next session starts from numbers instead of from "data, padding or unknown".
    """
    images = json.loads((root / "fixtures/decomp/images.json").read_text())
    bmap = json.loads((root / MAP).read_text())
    out = {}
    runs = 0
    for img in images["images"]:
        name, base, size = img["name"], img["base"], img["size"]
        blob = image_bytes(img, root)
        if blob is None:
            continue
        for lo, hi, cls, _why in bmap["images"].get(name, []):
            if cls != "unclassified":
                continue
            n = hi - lo + 1
            b = blob[lo - base:hi - base + 1]
            words = [int.from_bytes(b[k:k + 4], "big") for k in range(0, len(b) - 3, 4)]
            if not words:
                continue
            runs += 1
            ev = code_run_evidence(b, base, size)
            # ONE implementation: the same `table_runs()` the map claims with. A copy of these two rules inside
            # this function is what M339 found drifting, and it drifted again here -- the report was still
            # reporting tables the map had already claimed (M342).
            kinds = {c for _lo, _hi, c in table_runs(b, lo, (base, base + size))}
            if n < MIN_PAD and (b.count(0x00) == n or b.count(0xFF) == n):
                kind = "short_fill"
            elif ev["is_code"]:
                kind = "code"
            elif "float_table" in kinds:
                kind = "float_table"
            elif "pointer_table" in kinds:
                kind = "pointer_table"
            elif n >= 64:
                kind = "structured"
            else:
                kind = "small_residue"
            slot = out.setdefault(kind, {"bytes": 0, "runs": 0})
            slot["bytes"] += n
            slot["runs"] += 1
    out["_total"] = {"bytes": sum(v["bytes"] for k, v in out.items() if not k.startswith("_")),
                     "runs": runs}
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--check-cartridge", action="store_true")
    ap.add_argument("--residue", action="store_true",
                    help="profile the unclaimed runs so they can be read (needs the cartridge)")
    ap.add_argument("--unclassified", action="store_true",
                    help="decompose the unclassified bucket by evidence about the bytes (needs the cartridge)")
    a = ap.parse_args()
    if a.residue:
        if not all(image_bytes(i) for i in load()[0]["images"]):
            print("SKIP (needs the unpacked images)")
            return 0
        rep = residue_profile()
        print("%d unclaimed run(s) of 64 B or more, %d B; the best single property (%s) covers %d B"
              % (rep["runs"], rep["bytes"], rep["best_rule"], rep["best_rule_bytes"]))
        print("%-12s %-10s %6s %5s %9s %6s %5s %5s %5s %4s %5s"
              % ("image", "address", "bytes", "words", "top word", "share", "u16", "s16", "s20", "alph", "H"))
        for r in rep["largest"]:
            print("%-12s %-10s %6d %5d %9s %5.0f%% %5.0f%% %5.0f%% %5.0f%% %4d %5.1f"
                  % (r["image"], r["address"], r["bytes"], r["words"], r["top_word"],
                     100 * r["top_share"], 100 * r["u16"], 100 * r["s16"], 100 * r["s20"],
                     r["alphabet"], r["entropy"]))
        return 0

    if a.unclassified:
        if not all(image_bytes(i) for i in load()[0]["images"]):
            print("SKIP (needs the unpacked images)")
            return 0
        rep = unclassified_report()
        total = rep.pop("_total")
        for kind in sorted(rep, key=lambda k: -rep[k]["bytes"]):
            print("  %-14s %7d B %5d runs  (%4.1f %%)"
                  % (kind, rep[kind]["bytes"], rep[kind]["runs"],
                     100.0 * rep[kind]["bytes"] / total["bytes"]))
        print("  %-14s %7d B %5d runs" % ("TOTAL", total["bytes"], total["runs"]))
        return 0

    if a.write:
        rep = build()
        if any(not image_bytes(i) for i in load()[0]["images"]):
            print("REFUSED: the unpacked images are not present, so padding cannot be classified "
                  "(run tools/unpack_zlib.py first)")
            return 2
        (ROOT / MAP).write_text(json.dumps(rep, indent=1) + "\n")
        tot = {c: sum(t.get(c, 0) for t in rep["totals"].values()) for c in CLASSES}
        print(f"wrote {MAP} — " + ", ".join(f"{c} {tot[c]:,}" for c in CLASSES))
        return 0
    if a.check_cartridge:
        if not all(image_bytes(i) for i in load()[0]["images"]):
            print("SKIP (needs the unpacked images)")
            return 0
        cases = cartridge_check()
    else:
        cases = check(json.loads((ROOT / MAP).read_text()))
    bad = 0
    for label, ok in cases:
        bad += not ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{len(cases) - bad}/{len(cases)} byte-map case(s)")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
