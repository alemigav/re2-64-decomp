# M346 — `slack`: the sub-64 B residue is padding *inside* known data, and 156 B is all that is left

M345 profiled the 72 228 B of runs ≥ 64 B and registered no class for them. The other 12 272 B — 933 runs under 64 B —
turned out to have a property that *is* a rule, and measuring it first is what made it visible:

```
557 runs, 12 272 B
bytes with a claimed neighbour on BOTH sides : 12 116   (98.7 %)
bytes with a claimed neighbour on ONE side   :    156
bytes with no claimed neighbour              :      0
```

Not one of these runs is floating in unknown space. **98.7 % of them sit between two things the map already names** —
`padding`/`padding` (164 runs), `data_named`/`data_named` (174), `jump_table`/`jump_table` (60), and mixes. That is
alignment and record padding *inside* known data, and it is the both-sides sibling of M344's `gap` (which required a
**function body** on one side).

## 1. The rule

**`slack`** — an unclassified run **under 64 B** with a **claimed run on both sides**: **12 116 B**. `gap` runs first, so
a run beside a body stays `gap`; `slack` takes what sits between two of everything else. The ordering is the rule, and it
has its own pin-case.

## 2. What is actually left: 156 B in six runs

```
ovl_0090698  0x80168040  16 B   0b 00 10 13 00 …        ovl_00a733e  0x80167ffc  52 B  00 00 20 00 85 04 …
ovl_0093192  0x80162d74  28 B   08 00 08 00 1a 00 …     ovl_00b08a2  0x8016746c  20 B  df bb 00 00 00 …
ovl_00a0344  0x80163f00  16 B   00 00 f9 1a 00 …        ovl_00b5346  0x801630b8  24 B  00 00 10 00 00 01 …
```

Six short records, all in overlays, all with one unnamed neighbour. That is the end of the line for rules — a session can
read them one at a time.

## 3. Measured

```
function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 · pointer_table 20 380
string_table 13 200 · padding 405 296 · fill 1 496 · gap 4 720 · slack 12 116 · u16_table 31 992
dense_data 128 056 · unclassified 72 384 (3.7 %)          = 1 956 560 B
```

**13 classes**, partition closing exactly. `unclassified` is now **72 384 B (3.7 %)**, and its composition is *stated*:
**72 228 B in 269 profiled runs of 64 B or more** (M345's `--residue`) plus **156 B in six runs**.

## 4. The gate

```
PASS a 28-byte run between two `padding` runs is `slack`, and one with an unnamed neighbour is not
PASS a 28-byte run between two bodies is `gap`, not `slack` (the order is the rule)
```

One mutation: the rule stops requiring a named neighbour on both sides. `--lint` clean (3/3); **audit parked** (its state
is M342's `119/148, 0 vacuous, 29 broken → INCONCLUSIVE`).

## Numbers

- **13 classes**; `slack` **12 116 B**; `unclassified` **84 500 → 72 384 B (3.7 %)**, of which 156 B in six named runs
- byte map **15 → 17 cases**; audit **155 → 156 mutations** (lint-clean, not run)
- **recovered 155 / 154 byte-exact — unchanged**
