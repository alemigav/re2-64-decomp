# M432 — the variant cap was a lottery: 5 more bodies, and the bug that hid them

The drafting loop's first body, by hand, went from 26 to **27 of 27** in one edit — and that edit proved the pass set had
been throwing away its own answers.

## The body, and the hand draft

`ovl_009d282:0x80161db0`, 27 words, one word short. The image:

```
4  lbu  v1,5(s0)        ; v1 = *(u8 *)(s0+5)      -- an UNSIGNED byte load
7  slti v0,v1,2         ; v0 = (v1 < 2) SIGNED    -- a SIGNED comparison of it
```

Ours emitted `sltiu` for the same comparison. The cause is in the draft's declaration: `byte bVar1;` makes `1 < bVar1` an
unsigned compare, and declaring the local **`int`** makes it `slti` while leaving the load `lbu` — exactly the image's
pair. **26 → 27 of 27** with that one word changed.

## The bug it exposed

`localtype` varies every local over six types — so it should have found `int bVar1`. It never tried it: the generator
**capped its output at 12 variants**, and this body has several declarations, so `int bVar1` was the **13th** candidate
and was silently discarded. The pass then reported a **measured zero** for a mechanism that closes the body.

**A cap that truncates by TEXT ORDER turns a search into a lottery** — it does not limit how much work the pass does, it
limits *which* work, and the choice is the order the declarations happen to appear in. Raised to 48 (sites × six types,
which is the real size of the space it is enumerating):

| | before (cap 12) | after (cap 48) |
| --- | --- | --- |
| near band, round 1 | 0 closed | **4 closed** |
| near band, fixpoint | 3 closed | 4 closed |
| improvements | 66 | 75 |

**This is the fifth instrument defect this arc has produced, and the pattern is the same every time**: the tool was not
wrong about the transformation, it was wrong about *its own bounds*, and the error always makes the yield look like zero
rather than like a bug.

## State

**662 → 667 of 3 664 (18.2 %)**, 690 probe cases, `--full` PASS, audit 160/160. Queue: **259 near
(11 / 79 / 78 / 89), 456 mid, 2 184 far.**

The drafting loop works — one body, read and closed by hand in a single edit — but the more valuable result is the second
half: the same edit showed that a pass which reported zero on this body could close it. **A measured zero from a pass
with a bound deserves the same suspicion as a measured zero from a mechanism.**
