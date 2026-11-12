# M407 — the residues are not toolchain artefacts: no available compiler or flag closes them

`tools/toolchain_matrix.py` opens with the suspicion that this project's single pinned profile might be the wrong
question, and that *"the residues we closed as allocation walls may be toolchain artefacts instead."* That suspicion has
now been pointed at the two open residues rather than at the closed ones.

## Both bodies under all four profiles

The four profiles are real compilers crossed with real flag sets — the two generations we have built, each under our
flags and theirs.

| draft | ours 2.8.1 `-mips2` | theirs' flags on 2.8.1 (`-mips3 -mgp32 -mfp32`) | 2.7.2 (theirs) | 2.7.2 (ours) |
| --- | --- | --- | --- | --- |
| `0x80073e38`, the walk + argument compare | **43** | 16 | 0 | 0 |
| `0x800b43a0`, `Rec *` walk + argument compare | **18** | 18 | 5 | 5 |
| `0x800b43a0`, walk + **compare the copy** | 4 | 4 | 3 | 3 |
| `0x800b43a0`, indexed + compare the copy | 7 | 7 | 5 | 5 |
| `0x800b43a0`, byte offsets, argument compare | 18 | 18 | 5 | 5 |
| `0x800b43a0`, parameter reuse | 4 | 4 | 3 | 3 |

The canonical profile wins on every draft. On the 58-word body the older compiler does not merely score worse — it
scores **0 of 58** and compiles 48 words instead of 60, so it is not producing this function's addressing at all. And the
variants that the canonical compiler collapses *stay* collapsed under 2.7.2 (4 → 3, 7 → 5): the coalesce that costs the
word-3 copy is not a 2.8.1 regression that 2.7.2 would avoid.

## The flag sweep

Seventeen flags on `0x800b43a0`, eight on `0x80073e38`, on the canonical compiler. **Nothing exceeds the published
score.** What moves, moves down: `-O1` 6 and 10, `-mno-split-addresses` 9 and 0, `-fno-delayed-branch` 3 and 12,
`-fno-schedule-insns2` 31 on the 58-word body, `-fno-strength-reduce` 6 on the record body. `-O3`, `-fno-caller-saves`,
`-ffunction-cse`, `-fomit-frame-pointer`, `-mno-abicalls`, `-msoft-float`, `-G8` and `-fno-rerun-cse-after-loop` are all
exactly the published score — no-ops for these bodies.

The two flags that *do* matter point the same way M404/M405 found: disabling strength reduction, or the second
scheduling pass, moves the score in one direction only, because both are the passes that produce the shapes the image
has. There is no flag on the far side of them.

## What this does and does not refute

**Refuted:** that either open residue is an artefact of *this project's* pinned profile. Both are at their best under
the profile that reproduces the rest of the corpus, and every alternative available here is worse.

**Not refuted:** that a *vendor* build would close them. `sn-n64-281`, `sn-n64-272-*`, `gcc-2.8.1-pm-*` and
`gcc-2.7.2-kmc` are binaries this project does not have, and `gcc-2.7.2-kmc` is not `gcc 2.7.2` — KMC shipped a patched
tree. A profile that *fails* here refutes nothing about those binaries; only a profile that *succeeds* would be
evidence. That is the tool's own rule, and it is the reason this milestone is a negative result rather than a claim.

So the honest state of both residues is unchanged and now better bounded: `0x80073e38` at **43 of 58** and
`0x800b43a0` at **18 of 38**, with the drafts closed as far as this toolchain can take them.
