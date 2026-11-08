# M386 — the duplicate cohort, measured and closed: it is not a source

M385 closed by naming the duplicate cohort as the next queue, sized at **11 groups / 29 entries** out of the rung's 318.
Both draftable groups were opened. **Neither yields a reconstruction**, and the reason is worth the milestone: the cohort
is not a mixed bag with some cheap copies in it, it is **90 % one family of bodies this compiler cannot emit**.

## Group 1 — three copies × 15 words (`ovl_0072610`)

`0x8018442c`, `0x80184934`, `0x80184a7c` are byte-identical, and the body is:

```
mfc0 $t3,$7  ; bne $t3,$zero,-2   ← poll
mfc0 $t3,$5  ; bne $t3,$zero,-2   ← poll
mtc0 $t2,$12 ; mtc0 $t1,$13 ; mtc0 $t0,$3 ; mtc0 $zero,$7
mfc0 $t3,$6  ; bne $t3,$zero,-2   ← poll
jr $ra       ; mtc0 $zero,$7
```

That is the **CP0 vector installer** — the same ten-to-fifteen words already refused at `0x800319e8` (M385), `0x801847a8`
(M380) and `0x800800f…` before them. **Three more copies, one more refusal, same reason:** `mtc0` is not something any C
construct makes this `cc1` emit. They stay on the rung.

## Group 2 — two copies × 38 words (the enemy-slot twins)

`ovl_008900e:0x80162a30` and `ovl_008e046:0x80162a30` are byte-identical — the same body at the same address in the two
overlay variants, which is the pair README has advertised as the cohort's best target since M312. It is a **26-store field
initialiser**: one `sw`, twenty-five `sh`, two constants reused (`0x180` twelve times, `0x380` five times), and the values
read like a sprite/collision descriptor (`0x2a0`, `0xff38`, `0x1e4`, `0xffa0`, `0xfe80`, `0x400`).

**35 of 38 words, four spellings, and the residue is three words of register assignment.** Every spelling that puts the
stores in the image's *emitted* order produces the same three differences — the tail block stores `0x380` from `$v0` and
`0x180` from `$v1`, and gcc puts them the other way round no matter whether the constants are literals, one local, two
locals, or declared in either order:

| spelling | diff |
| --- | --- |
| two locals, `v` then `w` | 4 words (`374`, `378`, `366`, `376`) |
| two locals, `w` then `v` | **3 words** (`378`, `366`, `376`) |
| one local + literals | 3 words, same three |
| all literals (CSE) | 3 words, same three |
| ascending source order | 3 words, but the **order** moves — so the source order is the image's emitted order and only the registers are wrong |

**That is the allocation wall again**, and this time it is not 1–3 words in a 9-word body but 3 words in a 38-word one:
the same wall, and the same verdict — the object code is right and the register choice is not reachable from C at `-O2`.

## The eleven groups, by verdict

| group | entries | verdict |
| --- | --- | --- |
| 3 × 15 words (`ovl_0072610`) | 3 | CP0 vector installer — **refused** |
| 2 × 12 words (`ovl_0072610` / `stage2`) | 2 | the same installer's other spelling — **refused** (M380) |
| 2 × 38 words (enemy-slot twins) | 2 | **35 of 38**, allocation in the tail — published partial |
| 3 × 30 words (`stage2`) | 3 | exception/DSP handlers — **refused** (M382) |
| 4 × 2, 3 × 2, 3 × 4, 3 × 5 words (`stage2`) | 13 | the installer's tail fragments — **not functions** (branch out of extent) |
| 2 × 12/15 strays | 6 | already-published residues |

**So the cohort contributes 0 reconstructions, 2 published partials and 27 classified refusals** — and the conclusion is
structural: after M369 removed the imported corpus, the remaining duplicate stock *is* the hand-written exception vector
family, because that is the one body the original kept copying across overlays.

## The strategic reading, stated plainly

This is P21's third thin pass (M383 +0, M385 +1, M386 +0) after four fat ones (M378 +7, M379 +10, M380 +5, M381 +10, M382
+6, M384 +14). The pattern is not fatigue, it is **exhaustion of the populations that a draft can close**:

| population | what is left | why it resists |
| --- | --- | --- |
| `jal`-bearing, ≤12 words | 0 | **done** (M384: 14 of 14) |
| `jal`-bearing, 13–23 words | 0 | **done** (M381/M382: 16 of 21) |
| `jal`-bearing, 24+ words | 27 | the allocation wall (M383: 0 of 5) |
| non-`jal`, ≤12 words | 0 draftable | 3 non-C of 6 (M385) |
| duplicate cohorts | 0 draftable | 27 of 29 are the CP0 family (this milestone) |
| the 13–20 store-heavy tail | ~75 | the delay-slot wall (M380) |
| 51+ words, 28 entries | 28 | untried, and largest per draft |

**The one untried population with real size is the large end — 51+ words, 28 entries.** Nothing in this project has
drafted a body above 50 words except `0x8007e590` (229 words, five milestones, still 226/229). Those bodies are expensive
and most will end in the wall, but they are the only queue left that is not already measured as resisting.

## Moves

**Nothing registered.** `recovered` stays **274 / 273 byte-exact**, `F1` **3 468**, rung **318 entries / 37 608 B**,
coverage **1 238 112 B**. Two entries gain a published score (`35 of 38`) and stay on the rung. `make check` unchanged at
**273 of 274**. Tree **1 373 cases**.
