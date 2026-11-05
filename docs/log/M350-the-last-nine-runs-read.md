# M350 — the last nine runs, read in one sitting

440 B, nine runs, and they can all be read in a single pass. Doing it produced one structural fact and four families.

## 1. The fact: every one of them is an image *tail*

`residue_profile(min_bytes=1)` now reports `at_tail` per run, and the answer is **9 of 9**:

```
ovl_00b321e 0x801668b4  140 B  H=3.8    ovl_00b08a2 0x8016746c  20 B  H=1.4
ovl_008505e 0x80166f84   76 B  H=2.6    ovl_0090698 0x80168040  16 B  H=1.0
ovl_009dd02 0x801673bc   68 B  H=2.4    ovl_00a0344 0x80163f00  16 B  H=1.9
ovl_00a733e 0x80167ffc   52 B  H=2.7    ovl_0093192 0x80162d74  28 B  H=1.9
ovl_00b5346 0x801630b8   24 B  H=2.2
```

**Nothing follows any of them** — each is the last thing in its image's map, preceded by `data_named` (7) or `padding`
(2). So the residue is not scattered data: it is the **tail of nine images**, which is a statement about the *images*
rather than about the bytes. It also says what the previous three milestones could not: these runs are not "unclassified
data among known data", they are *what the declared image extents end with* — and the declared extents came from the
overlay table, so the tails are load-extent arithmetic, not a sub-structure we failed to name.

## 2. The four families

**RDP/Gfx display-list fragments — 4 runs, 196 B.** `ovl_00a733e` (52 B) and `ovl_009dd02` (68 B), and the second half of
`ovl_008505e`:

```
2000 8504 0000 | 1800 8501 0000 | 1000 8407 0008 | 1000 8407 0008 | 1800 0106 0000 | 2000 8600 0000 | 1000 8404 0008
```

— 8-byte records whose second word carries an `0x84xx`/`0x85xx`/`0x86xx` opcode half, exactly the shape M347 identified
and the family `0x80024558` belongs to. The first half of `ovl_008505e` is its setup data (`0200 0800 0901`, small u16
pairs), which is why that run is 76 B rather than 52.

**One small-value record, three copies — 68 B.** `ovl_0093192`, `ovl_00b5346` and `ovl_0090698` all carry the group

```
0504 … 040f … 0c00
```

`ovl_00b5346` reads `0000 1000 0001 0008 | 2000 0504 0000 | 1000 040f 0000 | 0c00` — a `0x1000`/`0x0800` prologue and then
the same three constants. **The same record appears in three overlays**, so it is a shared parameter block (a
setter's argument list), not three coincidences.

**Two lone pointers with a 16-bit code — 36 B.** `ovl_00a0344` (`0000 f91a … 8016 3ea0`) and `ovl_00b08a2`
(`dfbb … 8016 7400`): a u16 code followed by a word that is an address inside the same overlay, zero-padded. A one-entry
pointer table whose neighbours are named, so its middle fell under the eight-word floor `pointer_table` needs.

**One signed-coordinate table — 140 B, `ovl_00b321e`.** The largest and the most legible: alternating type codes
(`0x0003`, `0x0005`, `0x0006`) and **negative s16 values** (`0xff38` = −200, `0xfa88` = −1400, `0xfce0` = −800,
`0xfe0c` = −500, `0xfed4` = −300) interleaved with small positives (`0x0190` = 400, `0x0514` = 1300, `0x0384` = 900,
`0x0640` = 1600). Codes plus signed coordinates is the shape of a **point/trigger or key table**, and it is the one run
here that a reader could take further without another tool.

## 3. What this closes

The arc's bookkeeping, in one line each:

- M338: the bucket was a *policy*, and measuring it found 8.7 % code in it;
- M339–M341: the code became census functions (187 of them, with listings);
- M342–M346: float, pointer, string, fill, gap and slack classes, each earned by a rule that can fail;
- M347–M348: ten candidate rules refuted, then the *code that points at* the data (16 132 B) named;
- M349: the eagle's view — the cap was mine, and `enclosed_data` took 55 812 B by naming neighbourhoods;
- **M350: the last 440 B read by hand**, in nine runs, in one sitting.

`unclassified` stands at **440 B (0.0 %)** of 1 956 560. What remains is not a gap in the analysis; it is **nine image
tails**, described.

## Numbers

- **9 runs / 440 B, all at image tails**; four families: 4 display-list fragments, 3 copies of one parameter record, 2
  lone pointers, 1 signed-coordinate table
- probe **135 → 136 cases** (the tail census is gated: 9 of 9); byte map **20 cases** unchanged
- **recovered 155 / 154 byte-exact — unchanged**; audit **parked** as agreed (state: M342's `119/148, 0 vacuous, 29 broken`
  → `INCONCLUSIVE`, all 29 one tool with a red case that is red in the repository too)
