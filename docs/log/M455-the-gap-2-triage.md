# M455 — the gap-2 triage: 52 of 53 are source-level, and eleven of them are one family

Same discriminator as M450 — the instruction multiset, registers included — applied to the **53 open bodies at aligned
gap 2**. No edits.

## Result: the band inverts

| class | bodies |
| --- | --- |
| **SOURCE** | **52** |
| ORDERING | 1 |

The gap-1 band was 71 % toolchain family; the gap-2 band is **98 % source-level**. That is the opposite composition, and
it means the remaining near work is *not* dominated by the scheduling/assembler family — at gap 2 an instruction's
content is genuinely wrong, which is what writing C can address.

## Eleven of them are one family

Eleven bodies at **exactly 38 words**, at addresses `0x98` apart, all differing at **word 5**, and sampled three at a
time they show **byte-identical diffs**:

```
delete   img[5]   afb20018   sw s2,24(sp)      ours has it at 7    <- the Group A signature
insert   ours[7]  afb20018                                          <- same store, deferred
replace  img[15]  92020005   lbu v0,5(s0)      ours 82020005  lb v0,5(s0)   <- signedness
```

| bodies |
| --- |
| `stage2:0x8007f0e8`, `:8007f180`, `:8007f218`, `:8007f2b0`, `:8007f348`, `:8007f3e0`, `:8007f478`, `:8007f510`, `:8007f5a8`, `:8007f640`, `:8007f6d8` |

So the family is **two defects**, not one: a **callee-saved store deferred** (Group A, M451/M452 — no lever) and a
**`lb` where the image reads `lbu`** (signedness, M441/M446 — movable by a type). That is the single most valuable
target in the band, because **eleven bodies share it**, and the experiment is one edit: change the accessed type and see
whether the store order follows. If the schedule follows the allocation, all eleven close together; if not, eleven are
blocked on the Group A wall and the family is filed with it.

## Three of the 52 are not C at all

The smallest entries are the fragments already known:

| body | words | draft | why it is not source-level |
| --- | --- | --- | --- |
| `boot:0x80000518` | 2 | `void idle_spin(void) { do { } while(true); }` | the image is `beq $zero,$zero,-1` with `daddiu` in the slot; gcc emits `j` at every `-O` level (M437) |
| `boot:0x800006d0` | 2 | `void exception_handler(void) { halt_baddata(); }` | the image is `lui $k0` / `addiu $k0` — a fragment with no `jr ra` (M443's `no-return` class) |
| `stage2:0x80018a80` | 2 | `void entry(void) { halt_baddata(); }` | the image base, and the image word is a `j` |

So the honest count is **49 real source-level candidates**, not 52.

## What this says about where the work is

| band | bodies | toolchain family | source-level |
| --- | --- | --- | --- |
| gap 1 | 14 open | **11 (79 %)** | 3 |
| **gap 2** | **53 open** | **1 (2 %)** | **49 real** |

The near band is exhausted *and* unrepresentative: it is mostly toolchain. The gap-2 band is mostly source and contains
an eleven-body family on one signature. That is the first band this session where the majority is reachable in principle
— and where a single fix could move eleven functions.

## Numbers

- **53 gap-2 bodies triaged: 52 SOURCE, 1 ORDERING** — the inverse of gap 1's 71 % toolchain
- **11-body family** at 38 words, `0x98` apart, identical diffs: `sw s2,24` deferred **and** `lbu` vs `lb`
- **3 of the 52 are non-C fragments** (2-word stubs), leaving **49 real candidates**
- no edits, nothing banked; `recovered` stays **674**, byte-exact **673**
