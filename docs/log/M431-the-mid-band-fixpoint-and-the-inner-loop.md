# M431 — the mid band to a fixpoint: one body, and the seven rounds it took to see why

`--rounds` was added at M430 to search *combinations* of passes rather than an ordering. Run to a genuine fixpoint on the
mid band, here is what it closes.

## The answer: one body

| | |
| --- | --- |
| mid-band bodies | 457 |
| rounds to fixpoint | **8** (before the inner loop, below) |
| **closed** | **1** — `stage2:0x8009c594`, **51 words** |
| improvements | 292 |

`stage2:0x8009c594` has **ten data symbols whose widths matter** (`short` against `unsigned int`, `unsigned char` against
`int`) and it closed by `dat:width` **in round 7**. That is the interesting number, not the closure: a pass visit made
**one change per body** and moved on, so ten corrections needed seven sweeps of the whole band.

## The defect that exposed, and the fix

A pass that improves a body without closing it should **keep going on that body**. `--inner` repeats one mechanism on
the body it just improved, up to six times, before the sweep moves on:

| | rounds to fixpoint | closed | improvements |
| --- | --- | --- | --- |
| outer rounds only (M430) | **8** | 1 | 292 |
| with `--inner 6` | **3** | 1 (already closed) | 284 |

Same fixpoint, **converged in three rounds instead of eight**. The cost is identical — the same compiles, in a better
order — and what it buys is that a body needing many changes of ONE kind accumulates them in a single visit instead of
one per sweep.

## What this says about the mid band

**292 improvements and one closure from 457 bodies.** The mid band is not a mechanical queue: its residues are large,
each body needs several different mechanisms, and after the fixpoint is reached the closure rate is 0.2 %. The passes
are not missing a transformation — nine of them, composed and iterated, find nothing else.

## State

**662 of 3 664 byte-exact (18.1 %)**, 685 probe cases, `--full` PASS, audit 160/160. Queue: **262 near
(13 / 81 / 79 / 89), 456 mid, 2 184 far.**

The near band is where the compositions paid (two thirds of its closure, M430). The mid band is where they do not, and
the difference between those two facts is the most useful thing this milestone measured: **composition helps when bodies
are one or two words away and stops helping when they are fifty.**
