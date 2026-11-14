# M424 — the `blez` idiom: found, closed by hand at 16 of 16, and it recurs in 19 bodies

M423 ended with a body at 15 of 16 whose last word was `blez $v0` against our `beq $v0,$zero`, and the open question was
whether that shape recurs. It does — 19 bodies carry it — and the idiom that produces it is now known exactly.

## The idiom

Reading the image's own sequence for `stage2:0x800a56c0`:

```
1  lw   v0,23724(v1)     ; v0 = DAT_80135cac
3  blez v0,+9            ; if (v0 <= 0) goto epilogue     <-- the guard
5  addiu v0,v0,0xffff    ; v0--
6  bne  v0,zero,+6       ; if (v0 != 0) goto epilogue
7  sw   v0,23724(v1)     ; DAT = v0   (the bne's delay slot: unconditional on this path)
```

So the source is a **guard with an early exit**, not a wrapping `if`:

```c
if (DAT_80135cac <= 0) return;
DAT_80135cac = DAT_80135cac - 1;
if (DAT_80135cac == 0) func_0x8000cb60((u32)D_80143fb0, 0, 0);
```

**Both halves are required, and each was measured alone first:**
- the guard alone, with the value unsigned, gives `== 0` → `beq` (**15 of 16**);
- a signed declaration alone, with the wrapping `if`, also gives **15**;
- the guard **and** `int` together give `blez` → **16 of 16**.

The second half is the subtle one: `<= 0` on an **unsigned** value *is* `== 0`, so a signedness error is invisible in the
source and shows up only as a different branch opcode. That is the same defect class as M420's width default — a
declaration deciding code the source cannot express.

## Does it recur? Yes: 19 bodies

Scanning the queue for a differing word that is `blez`/`bgtz`/`bltz`/`bgez` against our `beq`/`bne`:

| | bodies |
| --- | --- |
| carrying the signed-branch residue | **19** |
| of those, near the target (gap ≤ 8) | **0** |

Every one of the 19 is a far body — gaps from 50 to 444 words — so the branch form is *one* of many differences there.
The idiom is real and common; the bodies it appears in are not.

## And as a pass, it closes nothing

`guard:early` was built and measured: it rewrites a wrapping `if` whose block ends the function into a guard with an
early exit, in both the plain and signed declarations. **0 closed, 0 improved, on both bands** — its textual pattern
needs the guarded block to be the function's tail, and in the 19 bodies the branch sits mid-body inside a much larger
structure.

That is M416's finding confirmed a second time: **the mechanisms that close a body are whole-function decisions read off
the image, and a text pass reproduces them only when the function happens to be that small.** The pass stays in the
grammar, marked as measured at zero, because a future body of the right shape will want it.

## State

647 → **648 of 3 664 (17.7 %)**, 671 probe cases. The queue is unchanged in size — 267 near, 463 mid — but one more
mechanism is written down, and **19 bodies now have a named reason for their residue** instead of an unclassified one.
