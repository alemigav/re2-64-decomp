# M452 — the prologue save-order experiment: not a flag, not a cc1 build. Group A is closed as a class.

Group A is seven bodies on **one permutation** — `sw s2,24` at image position 5 against our 7, with `sw ra` and the
`lui` moved the other way. So it is one experiment, not seven: can any flag, or any `cc1` we hold, emit the prologue's
saves in the image's order?

Both halves were measured, each against a control of already-exact bodies, and the answer is **no on both**.

## Flags — 11 variants, 0 closures

| variant | Group A (of 7), aligned | control kept |
| --- | --- | --- |
| **baseline** `-O2 -G 0 -mips2 -mcpu=r4300` | **0** — 22, 27, 27, 31, 35, 35, 35 | 9 of 12 |
| `-fomit-frame-pointer` | 0 — same as baseline | 9 of 12 |
| `-O3` | 0 — same as baseline | 9 of 12 |
| `-mips3` | 0 — same as baseline | 9 of 12 |
| `-fno-schedule-insns` | 0 — 9, 21, 21, 25, 21, 23, 23 | 7 of 12 |
| `-fno-schedule-insns2` | 0 — 21, 25, 25, 29, 31, 33, 33 | 4 of 12 |
| `-G 8` | 0 — 21, 26, 26, 30, 32, 33, 33 | 6 of 12 |
| `-O1` | 0 — 15, 19, 19, 23, 19, 21, 21 | 4 of 12 |
| `-fno-delayed-branch` | 0 — 18, 21, 21, 23, 29, 29, 29 | **0 of 12** |
| `-fno-omit-frame-pointer` | 0 — 16, 20, 20, 24, 28, 28, 28 | **0 of 12** |
| `-fno-optimize-sibling-calls` | **refused by cc1** | — |

Every baseline score is exactly **one below the extent** (22 of 23, 27 of 28, 35 of 36), which is the gap-1 signature
restated. `-fomit-frame-pointer`, `-O3` and `-mips3` are byte-identical to the baseline on these bodies; everything else
is worse, and two variants destroy the control entirely.

## The other `cc1` — refuted, and catastrophically

We hold a full **gcc 2.7.2** at `build/toolchain/mips-gcc-2.7.2/bin/cc1`. Two facts had to be established before it
could be judged: it **rejects `-mcpu=r4300`** (`bad value ... for -mcpu= switch`), so it was run with `-mips2` alone.

| variant | Group A (of 7), aligned | control kept |
| --- | --- | --- |
| cc1 2.7.2, `-mips2` | 0 — 16, 19, 19, 23, 19, 21, 21 | **1 of 12** |
| + `-fno-schedule-insns2` | 0 — 15, 20, 20, 24, 20, 22, 22 | 1 of 12 |
| + `-fno-schedule-insns` | 0 — 9, 19, 19, 23, 19, 21, 21 | 1 of 12 |
| + `-O1` | 0 — 16, 20, 20, 24, 20, 22, 22 | **0 of 12** |
| + `-O3` / `-mips3` | 0 — 16, 19, 19, 23, 19, 21, 21 | 1 of 12 |

**Six variants, no closure, and the corpus collapses**: 1 of 12 control bodies survives where 2.8.1 keeps 9. That is the
M357 result reproduced from a different direction — the corpus *discriminates* between the two compiler generations, and
2.7.2 is on the wrong side of it.

## What this settles

**Group A's seven bodies are not reachable by any flag or any `cc1` in this repository.** The prologue save order is a
compiler behaviour we cannot produce, so the seven are correctly filed as a class and need no further per-body work.
Together with M449's assembler finding, the toolchain family now has a **complete** account: the scheduler (1 body),
the unexpanded `#nop` (2), the prologue save order (7), and the deferred constant materialisation (1) — eleven bodies,
each with a measured cause and no lever inside the pinned pair.

## Numbers

- **17 variants measured** (11 flags on 2.8.1, 6 on 2.7.2) × 7 bodies + 12 controls; **0 closures in all 17**
- baseline Group A scores are all exactly **words − 1**; `-fomit-frame-pointer`, `-O3`, `-mips3` byte-identical
- `-fno-delayed-branch` and `-fno-omit-frame-pointer` keep **0 of 12** controls; 2.7.2 keeps **1 of 12**
- **no edits, nothing banked**; `recovered` stays **674**, byte-exact **673**

## A caveat on the control

The control reads 9 of 12 rather than 12 of 12 at baseline, because every body here is compiled with the `scalar`
declaration rung while a few banked bodies were recorded under `array` or `pointer`. The comparison across variants is
unaffected — all 17 were measured the same way — but the absolute number is a floor, not the corpus.
