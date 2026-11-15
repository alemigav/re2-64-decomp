# M451 — the 11 toolchain-family bodies, signature-grouped, and no edits

The remaining gap-1 bodies were triaged by multiset (M450) into source-level and toolchain-family. This names the
toolchain family by **signature**: for an ORDERING body the instruction multiset is identical, so the difference is a
*permutation*, and comparing each word's position on both sides names it exactly.

**11 bodies, four signatures.** No edit was attempted, by instruction — the point is that a group is a single
mechanism, and a single mechanism is worth one decision rather than eleven diagnoses.

## A — the callee-saved store is deferred past `sw ra` (7 bodies)

The largest group by far. The image saves the last callee-saved register **before** `sw ra` and the `lui` that begins
the body; we save it after.

| body | words | displacement |
| --- | --- | --- |
| `ovl_00ae24a:0x80165670` | 23 | `sw s0,16` 3→5, `lui` 4→3, `sw ra` 5→4 |
| `ovl_00b321e:0x801623e4` | 28 | `sw s2,24` 5→7, `lui` 6→5, `sw ra` 7→6 |
| `ovl_00b321e:0x80163df0` | 28 | identical to the above |
| `ovl_008505e:0x80162748` | 32 | identical |
| `ovl_008bef8:0x80162270` | 36 | `sw s2,24` 5→7, `sw ra` 7→6 (no `lui` in the permutation) |
| `ovl_0098ee0:0x8016332c` | 36 | identical |
| `ovl_009aed0:0x80163608` | 36 | identical |

Six of the seven share **one** permutation to the slot. This is a single compiler decision — the order in which the
prologue emits its saves — and it is why they are one group and not seven findings.

## B — an instruction hoisted above the prologue (1 body)

`boot:0x800048e8` (9 words): `mult` sits at image position 2 and at **our position 0**, with the frame adjust and
`sw ra` pushed down one slot each. This is the body M448 measured as reproduced exactly by `-fno-schedule-insns2` — the
single member of what looked like a scheduler cluster and is not one (M449: 1 of 17).

## C — a hazard `nop` shifts everything after it (2 bodies)

| body | words | displacement |
| --- | --- | --- |
| `stage2:0x80033024` | 22 | `mflo` 14→13, `jal` 15→14, `addu` 16→15, `sltu` 17→16 — the image's `nop` at 12 |
| `stage2:0x800608c8` | 36 | `addu` 17→16, `mflo` 18→17, `jal` 19→18, `addu` 20→19 |

One cause for both: cc1 emits `#nop` and **binutils 2.7 does not expand it** while 2.42 does — measured in M449, where
2.42 also damages 9 of 22 already-exact bodies, so it cannot become the profile.

## D — a constant materialisation deferred (1 body)

`ovl_00b321e:0x8016552c` (59 words): `lui a0,0x003f` 38→39 and `ori` 39→40 move later while `addu v1,s0,zero` moves
38 earlier. The same family as A — a scheduling decision about where an independent materialisation sits — but with a
constant rather than a save, which is why it is named separately.

## What is not in this family (3 bodies)

Named for completeness, because they are still open and would be mis-filed here:

- `stage2:0x80047824` (12 words) — **argument packing**: the 5th stack argument is a halfword at `+0x12`; struct by
  value gives 0 of 12, `unsigned short` +0x10, two shorts +0x16 (M449).
- `ovl_00a0344:0x80162224` (29 words) — **allocation residual**: improves to 27 of 29 and the last difference is which
  register accumulates the sum (M450).
- `ovl_009dd02:0x80166408` (47 words) — **signedness**: `slti` against our `sltiu`; the body M441 refused and no cast
  in the substitution table reaches.

## The decision this invites

Groups A, B, C and D are **toolchain decisions our pinned pair does not make**. A is 7 bodies on one permutation. So the
honest question is no longer per body — it is whether the *prologue save order* is a compiler behaviour that a flag or a
cc1 build we have can produce, which is one experiment for seven bodies rather than seven for one each.

No edits were made in this milestone, and nothing was banked.

## Numbers

- **11 toolchain-family bodies in 4 signatures**: A 7, B 1, C 2, D 1 — plus **3** non-family bodies named
- A: six of the seven share one permutation to the slot; C: both are the same unexpanded `#nop`
- `recovered` unchanged at **674**, byte-exact **673**; no fixture touched
