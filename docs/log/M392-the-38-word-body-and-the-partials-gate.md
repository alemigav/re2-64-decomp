# M392 — the 38-word M388 body read, and the partials gate that makes a score checkable

M388 corrected this extent from 12 words to **38** — it was a body split at an early return, and the correction made it
readable for the first time. This milestone read it. The reading is the deliverable; the draft is a published partial at
**3 of 38**, and the gate below is what makes that number mean something.

## What the 38 words are

Decoded from the bytes (`0x14` is `beql`, which the tool's gloss table lacks):

```
lui/lbu   v0 = *(u8 *)0x80136D80            ; a global flag
beq       if (v0 == 0) return 0             ; the image branches FORWARD to the tail
addu      a2 = a0                           ; `want`, kept in an argument register
addu      a0 = 0                            ; i
loop:  lbu  v0 = *(u8 *)(a1 + 4608)         ; slot occupied?
       beql v0,zero → test                  ; delay `a0++` runs ONLY when taken
       lw   v0 = *(u32 *)(a1 + 4644)        ; slot's key
       beql v0,a2 → found                   ; delay `a2 = a0` runs ONLY when taken
       addiu a0++                            ; no match: advance
test:  sltiu (a0 < 2); bne back              ; two slots, stride 0x1228
       addiu a1 += 0x1228                    ; (delay)
found: a2 = 0xffff; if (a2 == 0xffff) return 0
       return *(u8 *)(0x80168B20 + a2 * 0x1228 + 4608) != 0
```

**The two `beql`s are the whole function.** A branch-likely executes its delay slot *only when the branch is taken*, so
`a0++` happens on the "slot empty" path and `a2 = a0` on the "key matches" path. That is what a nested `if` with side
effects inside a `for` compiles to — and it is why this body cannot be read as straight-line code with two ordinary
branches: the increments live in slots, not statements.

## The draft, and where it stops

`fixtures/decomp/partials/stage2/800b43a0.c` — the loop above, written the way the shapes suggest:

```c
for (i = 0; i < 2; i++)
    if (*(u8 *)(0x80168b20 + i * 0x1228 + 4608) != 0)
        if (*(u32 *)(0x80168b20 + i * 0x1228 + 4644) == want) { found = i; break; }
```

**3 of 38 words identical**, and the residue is **loop shape, not spelling**: gcc hoists both pointers into fresh
registers and inverts the early-out (`bne v0,zero,+5` where the image has `beq v0,zero,+33`, i.e. the image branches
forward to the tail), so the body diverges from word 2 onward. The image keeps the index in `$a0` and the found value in
`$a2` — the **argument registers themselves** — which says the source reused its parameters rather than declaring fresh
locals. That is the named next hypothesis, and per the cap it is not spent here.

**The second M388 body (`0x80073e38`, 58 words) was not drafted.** Reading it needs the same care and a full session's
budget; publishing a rushed 58-word draft would put a number in the record that cannot be trusted, which is precisely
what M391 was about.

## The gate this milestone exists for

M391's rule — *a partial is published only with its draft committed* — is now machinery:

| | |
| --- | --- |
| `fixtures/decomp/partials/<image>/<addr>.c` | the draft, **and no comments**: `cc1` 2.8 has no comment parser and dies with a garbage-byte parse error on the first `/*`. That is why the score lives beside the file, not in it |
| `fixtures/decomp/partials/<image>/<addr>.json` | `{words, score, mechanism, residue, measured, drafted}` — the published number, with what it was measured on |
| `tools/partials.py --check` | re-scores every pair with full, untruncated output and fails when the number drifts (**1/1** today) |
| `tools/partials.py --self-test` | 2 cases: an uncompilable draft fails *with a message*, and **a score with no draft fails** — the M391 defect itself, as a case |

So `3 of 38` is now a claim with an artefact behind it, re-derivable by one command — which is what none of the ~14
scores withdrawn in M391 had.

## The defect CI found

The first push of this milestone **failed** (`42510780060`): `partials (repository) 0/1 FAIL`. The gate re-scores through
`leaf_screen --try`, which **reads the cartridge** — so it is a *cartridge* suite and I had registered it as
repository-only. CI has no dump, so it ran the gate, the gate could not read a byte, and the case failed.

The fix is the rule this project already lives by, applied to one more tool: **absent cartridge means `SKIP`, never
`PASS` and never `FAIL`.** `partials.py --check` now prints `SKIP (needs the cartridge)` and exits 3 when the images are
absent, and the suite is registered as `partials (cartridge)` — which in turn moved one case from the runnable column to
the gated one (**355 → 354 runnable, 1026 → 1027 gated**) and needed `ratchet.py --write --allow-decrease`, because a
suite *renamed* from runnable to gated reads to the ratchet as a drop. That is the second CI-found defect in three
milestones (M389's gitignored objective, this) and both are the same shape: **a gate whose environment differs from the
one it was written in.**

## Moves

**Nothing registered** — `recovered` stays **274 / 273**, `F1` **3 468**, rung **317**, coverage **1 238 404 B**. New:
`fixtures/decomp/partials/` (1 pair), `tools/partials.py` (tools 107 → **108**), suite `partials (repository)` 1/1, tree
**80 → 81 suites / 1 380 → 1 381 cases** (354 → 355 runnable), `verify.py --full` **PASS**, audit **160/160**.
Milestones **393 numbers / 337 rows / 318 notes**.
