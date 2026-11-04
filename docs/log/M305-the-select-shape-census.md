# M305 — the select-shape census: the preference is systematic, but the obstacle is a conflict, so the patch is a different one

Two things happened here: the scan was run and it says the preference is real, and the scan's own setup exposed
that **M304 was wrong about the mechanism**. The second matters more, because it decides whether the patch the
scan "authorises" is the patch that would help.

## 1. The correction

M304 called the delayed `li` a *dead store* and the choice a *tie-break*. Both are wrong:

- The branch is `14620002` — `bne v1,v0` with **immediate 2**, so its target is `0x8007e8a8 + 4 + 2·4 = 0x8007e8b4`,
  which is the `sb`. The `li R,5` in the delay slot is therefore the **taken path's value**: when the test fails,
  the `sb` stores 5; when it passes, `li R,4` runs first and the same `sb` stores 4. It is a branch-over select,
  not dead code. (M304 read `34` as the branch offset; that was `objdump`'s rendered target, not the immediate.)
- The register choice is a **conflict, not a tie-break**. `.greg` shows pseudo 229 → `a0` and pseudo 232 (the
  constant 22) → `v0`, with `REG_DEAD (reg:SI 2 v0)` **on the branch**: at the point 229 is written (insn 642,
  before the compare) `v0` is still live, so it is simply unavailable. A preference rule has nothing to break a
  tie with.

Everything measured in M304 stands — the decode of the three words, the 32 spellings that give byte-identical
output, the 30 922 permuter iterations with zero improvement. The correction is to *why*, and it changes the patch.

## 2. The census

The shape `li R,A` → `li R,B` (same R) → a use of R, over all 36 images:

| | count |
|---|---|
| occurrences | **123** |
| first load in the branch's delay slot | **122** (99 %) |
| … where the pair ends in a store of R | **39** |
| register `$2` | **70** of 123 (57 %) |
| register `$2`, stored variant | **35 of 39 (90 %)** |
| full histogram (all) | `$2` 70, `$3` 23, `$4` 13, `$5` 8, `$6` 2, `$8` 2, `$16` 2, `$10` 1, `$17` 1, `$19` 1 |

So **the preference is real and it is specific**: for the exact form the residue has — two constants, then a store
of the second — the real build picks `$2` nine times in ten. It is not this function's accident.

**But the census also refutes the tempting explanation.** Only **19 of 39** cases have R among the registers the
shared-slot branch itself uses, so this is not "reuse the dying compare operand". It is simpler: `$2` is the first
general temporary, and in 90 % of this shape it is free when the constant is materialised. In `0x8007e590` it is
**not** free in our build, and that is the whole difference.

## 3. So the patch the scan authorises is not the one that would work

A preference/tie-break patch — "prefer the dying operand's register" — cannot move this, because there is nothing
to prefer: the ranges overlap. To get `$2` for pseudo 229, its definition has to sit **after** the branch in the
RTL that `global_alloc` sees, which is exactly where the final assembly puts it — the delay-slot fill happens
*after* allocation, so the allocator works on the pre-fill order.

That makes the real fix one of two, both much larger than a tie-break:

1. **Move the delay-slot fill before `global_alloc`.** Then the constant would be allocated in its final position
   (`v0` free) and the image's choice would fall out. Blast radius: every function — the 15 byte-exact ones must
   survive it, and `dbr_schedule` in gcc 2.8.1 runs late because it needs allocated registers, so this is real
   compiler surgery.
2. **Lower the select as store-after-merge** so the false value is defined after the branch. That is gcc's
   `jump`/cross-jumping territory, and the source-level attempts to force it are the if/else forms already
   measured: they produce two separate stores and cost **35 words** (194/229).

Either way the honest test is a second `cc1` built with the change, measured against the whole probe (15 exact
functions plus the 53 others) — not a patch committed against one function.

**Decision: the patch is not written in this milestone**, and the reason is not caution but the correction above:
the change the census seemed to authorise (a preference) provably cannot move this function, and the change that
can is a pass-order experiment that should be scoped, built and measured on its own. `0x8007e590` stays
**226 of 229**, published as such.

## Numbers

- compile probe **53 → 55 cases** (55/55 pass): the shape's frequency and delay-slot rate, and the stored variant's
  `$2` share, so the census is asserted rather than quoted
- M304's note and milestone row carry the correction inline; the three-word decode and the 32-spelling negative
  are unchanged
- tree: **73 suites / 1 030 cases** (744 need the cartridge), 100 tools, 3 416 functions, 1 211 256 B
