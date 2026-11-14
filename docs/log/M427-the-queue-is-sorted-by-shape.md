# M427 — the queue is sorted by shape: 1 495 linear bodies, 469 with loops

M426's finding was that drafting succeeds on a straight-line body (54 of 54, two iterations) and stalls on one with a loop
(8 of 64, three iterations). That is a property of the **image**, so the queue can be sorted on it before it is sorted on
distance — and a backward branch is a machine fact, not a judgement.

## The split

`draft_workbench --queue N --shape linear` classifies every body at ≤ 120 words by whether the image branches backward
anywhere inside it:

| shape | bodies |
| --- | --- |
| **linear** (no backward branch) | **1 495** |
| loop (at least one) | 469 |

Two thirds of the drafting queue is straight-line. The top of the linear queue is nine bodies at **gap ≤ 2**, from 12 to
97 words — the cheapest drafting targets the project has ever had a sorted list of.

## The three smallest, and what they cost

| body | score | the one word that differs |
| --- | --- | --- |
| `stage2:0x80047824` (12w) | **11 of 12** | `lhu $v0,18($sp)` against our `lw $v0,16($sp)` — a stack parameter read as a **halfword** |
| `stage2:0x8007277c` (13w) | **12 of 13** | `addu $a0,$v1,$zero` against our `andi $a0,$v1,0xff` — the value is **not** truncated |
| `boot:0x80004bac` (14w) | **13 of 14** | `addiu $v1,$v1,0x288c` against our `ori` — a constant that wants to be a **symbol reference** |

All three are one word, and none closed. Each is a **type or constant decision on a local**, which is the one place none
of this project's passes looks:

- the passes vary `extern` declarations (`dat:width`) and address literals (`symbol:addr`);
- these three need a **parameter's width**, a **local's signedness**, and a **negative constant recognised as an
  address** — `-0x7ffed774` is `0x8001288C`, and the address matcher requires the positive form.

Measured attempts: `char uVar1` instead of `undefined1 uVar1` on `0x8007277c` scored **6** (worse); the symbol reference on
`0x80004bac` scored **12** (worse); the stack halfword on `0x80047824` has no spelling in the draft's signature yet.

## What the sort actually buys

Not closures — yet — but the right list. Before this milestone the queue was sorted by distance and the distance said
nothing about difficulty: a 12-word body one word away can be the hardest thing in the list (these three are). After it,
the queue says **linear, 1 495, cheapest first**, and that is the population where a draft can converge.

## State

**649 of 3 664 byte-exact (17.7 %)** — unchanged, and this milestone did not expect to change it: sorting a queue moves no
functions. `verify.py --full` PASS, audit 160/160, 91 suites.

The next three attempts should be bodies where the residue is a *type of a local*, since that is now the single most
common one-word cause and no pass covers it. That is a `localtype` pass away, and unlike the mechanisms it is purely
textual: the draft already names its locals.
