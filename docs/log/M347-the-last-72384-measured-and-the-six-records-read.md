# M347 — the last 72 384 B: ten candidate rules measured, none registered, and six records read by hand

M345 tested seven hypotheses against the residue and refuted them all. This pass tried **different** ones — offsets
rather than addresses, byte width rather than word width, ordering, alignment, bit shape — and got closer, but not close
enough to name anything. What it also did, and this is the part that closes the arc, is **read the six records left over
by M346's `slack` rule**. They took one look each.

## 1. The ten candidates, and their coverage

```
word even                          19 992 B  (27.7 %)      high half == low half      6 280 B  ( 8.7 %)
byte < 0x80 (7-bit data)           13 736 B  (19.0 %)      word < 2^16 for half       5 872 B  ( 8.1 %)
word divisible by 4                13 728 B  (19.0 %)      byte < 0x40                4 932 B  ( 6.8 %)
words ascending                     2 608 B  ( 3.6 %)      word < 2^24 (24-bit)       1 452 B  ( 2.0 %)
offset (< image size)                 564 B  ( 0.8 %)      low half zero                448 B  ( 0.6 %)
```

`offset (< image size)` is the interesting refutation: relative-offset tables were the best *new* idea, and they cover
**0.8 %**. The leader — "≥ 90 % of the words are even", 27.7 % — is the trap this project keeps avoiding: it is an
enforceable, mutable rule that would rename a quarter of the residue while asserting **nothing about what the bytes
are**. `dense_data` already names shape-without-meaning and is labelled as density; a second class named after a bit
pattern would be a hunch in a lab coat. **None is registered.**

## 2. The six records, read

M346 left 156 B in six runs. As u16 sequences they are four kinds of thing:

```
ovl_00a0344 0x80163f00  16 B  00 00 | f9 1a | 00 00 | 00 00 | 80 16 | 3e a0 | 00 00 | 00 00
ovl_00b08a2 0x8016746c  20 B  df bb | 00 00 | 00 00 | 00 00 | 80 16 | 74 00 | 00 00 | 00 00 | 00 00 | 00 00
```

— **two lone pointers with zero padding** (`0x80163ea0`, `0x80167400`/`0x8016746c` region), i.e. a pointer table whose
neighbours are already named, so its middle fell below the eight-word floor.

```
ovl_0093192 0x80162d74  28 B  0800 0800 1a00 0000 | 0400 0504 0000 | 1000 040f 0000 | 0c00 0000 0000
ovl_00b5346 0x801630b8  24 B  0000 1000 0001 0008 | 2000 0504 0000 | 1000 040f 0000 | 0c00 0000
ovl_0090698 0x80168040  16 B  0b00 1013 0000 0000 0000 0000 0000 0000
```

— **three small-value records**: flag/size pairs with zero separators, the same `0504 … 040f … 0c00` group appearing in
two different overlays, which says the *record layout* is shared even though the addresses are not.

```
ovl_00a733e 0x80167ffc  52 B  2000 8504 0000 | 1800 8501 0000 | 1000 8407 0008 | 1000 8407 0008 |
                              1800 0106 0000 | 2000 8600 0000 | 1000 8404 0008 | 1800 0005 0000 | 2000
```

— **one command stream**: repeated 8-byte records whose second word is an `0x84xx`/`0x85xx`/`0x86xx` opcode half
(`0x8504`, `0x8501`, `0x8407`, `0x8600`, `0x8404`). That is the shape of an **RDP display list**, and this project has
decoded one before (`0x80024558`'s Gfx packets) — so the record is identifiable even though its four-word neighbours are
not.

**That is what 156 B buys**: four kinds of thing, all read, three of them recognisable families, none of them worth a
class.

## 3. Measured, and the state of the map

`unclassified` **72 384 B (3.7 %) — unchanged**: 72 228 B in 269 profiled runs with ten candidates refuted, plus the
156 B read above. **13 classes**, partition closing exactly on 1 956 560 B.

## 4. The gate

The claim is the refutation, and it is asserted:

```
PASS ten candidate rules were tested against the 72,228 B residue and NONE is registered: the leader
     (word even) reaches 28 %, and it asserts a *shape*, not a data type — which is `dense_data`'s job and
     already labelled as density. The six runs under 64 B (156 B) were read by hand instead
```

One mutation: *a residue hypothesis is quietly allowed to claim everything* (`if rule(...)` → `if True:`) — a ledger whose
hypotheses always fire would make "none is registered" true for the wrong reason. `--lint` clean (3/3) after splitting a
guard line the new function had duplicated from `residue_profile` (the audit's anchor-uniqueness rule caught it).
**Audit parked** — its state is M342's (`119/148, 0 vacuous, 29 broken → INCONCLUSIVE`).

## Numbers

- **10 candidate rules measured**, none registered; leader **27.7 %**, best new idea (`offset`) **0.8 %**
- **156 B in six runs read by hand**: two lone pointers, three small-value records (one layout shared across two
  overlays), one RDP-command stream
- `unclassified` **72 384 B (3.7 %)**, **13 classes**; probe **134 → 135 cases**, audit **156 → 157 mutations**
  (lint-clean, not run); **recovered 155 / 154 byte-exact — unchanged**
