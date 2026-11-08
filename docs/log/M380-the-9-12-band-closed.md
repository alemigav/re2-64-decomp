# M380 — the 9–12 word band closed: five read, and every entry now has a verdict

This milestone finishes the band. Five byte-exact from six fresh drafts — and the number that matters is the other one:
**every one of the 29 entries left in the 9–12 band now carries a verdict**, either a reconstruction or a published
residue with its score.

## The five

| entry | mechanism |
| --- | --- |
| `0x801624a4` | a state test, then three stores; the `lbu` of `+703` **hoists above** them because the offsets prove no alias |
| `0x80163b24` | an if/else on **bit 6** of the argument: one arm is two stores, the other packs `((v & 0xf) << 16) + 0x02000000` into one word |
| `0x80165ff0` | one guarded two-argument call; `sltiu` against 1800 is the test |
| `0x80164650` | a call whose result is ignored, then two stores — `$s0` is saved only because the argument outlives the call |
| `0x8017befc` | a call with a constant argument, a second with none, and the **first** call's result returned |

**Refused in the same batch:** `0x801847a8` is the **CP0 vector installer again** — the same ten words as `0x800319e8`
(`mfc0 $t3,$5` poll, then four `mtc0`s, then `mfc0 $t3,$6` poll), in a different overlay. A two-copy cohort of a body this
compiler cannot emit, recorded rather than drafted.

## The band, closed

Of the 56 entries that were in the 9–12 word band when this cycle opened:

| outcome | count |
| --- | --- |
| reconstructed | **22** (10 at M375, 7 at M378, 5 at M380 — the 13–20 band contributed 1 more) |
| partial, published with its score | **12** |
| refused, with a reason | **5** — 2 exception/DSP bodies, 2 CP0 installers, 1 `cache` flush |
| extent defect, queued | **2** (`0x80073efc`, `0x800b4400` both open inside an address the caller built) |
| **extent correction, delivered** | **2** (`0x800a5b7c`, `0x8003b640` — M378) |

**The residue is one class, not twelve.** Eleven of the twelve partials differ in **one to three words**, and every one
of those words is one of two things: a **register name** (the allocation wall) or the **position of a value relative to
`jr ra`** (whether the last store or the returned constant lands in the delay slot). Two mechanisms were spent trying to
move the second kind — a named `next` pointer, and a `for`-update comma expression — and neither moved it. **That is the
same verdict M311/M334 reached for the allocation wall, now with a second population behind it: the object code is right
and the scheduler's choice is not reachable from C at this optimisation level.**

## Why the yield fell from 7-in-17 to 5-in-6 to 5-in-6

M375 opened the band and drew the entries whose shapes were self-contained. What is left is the tail where the source's
*statement order* matters and the image's ordering came from a scheduler we cannot steer. That is why M379's `F1` was flat
and this one's is flat too: these are already-`written` census functions, so the ladder cannot see them — `recovered`
243, `F1` 3 468.

## Moves

`recovered` **238 → 243** (242 byte-exact), **`F1` 3 468 unchanged**, `extent_measured` 197, rung **354 → 349 entries /
39 392 → 39 164 B**, probe cases **260 → 265**, `make check` **242 exact / 1 differ of 243** with 0 unexpected, corpus
builds over **25 images**. Coverage unchanged at **1 238 112 B**. Tree **1 337 → 1 342 cases** (347 runnable, 995 gated).

## What comes next, stated with its price

The 13–20 word band holds **120 entries** and paid 1-in-5 at M376. The 21–50 band holds **114** and has been touched
once. Neither is a better *ratio* than this band was; what is different is that they contain bodies a scheduler-blind
draft can still close — 14- and 16-word functions with frames and calls, where the last statement is a call rather than a
store. The honest recommendation for the next cycle is to draw **the 13–20 band's call-bearing entries** (those ending in
a `jal`, which the call graph can enumerate) rather than more of its store-heavy tail.
