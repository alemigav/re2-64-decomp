# M396 — the 58-word M388 body read: the shape, and a partial at 2 of 58

M388 extended `stage2:0x80073e38` from 9 words to **58** — a body split at an early return, unreadable until then. This
milestone read it. The reading is the deliverable; the draft is a published partial, because two mechanisms moved the score
by two words and the cap says stop.

## The shape, from the bytes

```
ctx saved to $t0 first            a0 is needed for the 0x18000 constant
a0 = 0x18000                      > 0x7FFF, so it CANNOT be a displacement: a register
v0 = 0x800FE288 + 0x8000          = 0x80106288, the first store's base
a3 = ctx[1]                       read ONCE, used by both byte stores
sb a3, 20495(v0)                  → 0x8010B297
v0 = 0x800C76B0 (the table) ; a0 = v0 + 0x18000     t = 0x800DF6B0
a2 = *(u32 *)0x801152CC           a global, stored below
v1 = *(u32 *)(t + 6716)
v0 = table + 0x20000              the second constant, also a register
sb a3, 3925(v0)                   → 0x800E8605
andi v1,0x40 ; beq …  delay: sw a2, 1328(t)         ← the store is in the DELAY SLOT
  if (v == 30) *(u16 *)(ctx + 2) = 2;
bne (ctx[7] & 1), +20 → 0x80073efc                  ← forward branch to the SECOND arm
  … else arm: 2 → 0x8012BFA8, 1 → 0x80131780, t+6752 → 0x80131780+0x1780+68, t+6748 |= 0x8000
  0x80073efc: 6 → t+6789, 0 → t+6790
```

**Four facts that decide any draft of it, and none is visible without reading the delay slots:**

1. **Two constants exceed the 16-bit displacement range** — `0x18000` and `0x20000` — so the image holds each in a register
   and `addu`s. They are not offsets and cannot be written as offsets.
2. **The store to `t + 1328` is in the delay slot of the `beq`**, so it is **unconditional**: a statement *before* the
   flag test, not inside it.
3. **The function has two returns**, and the arm at `0x80073efc` is reached by a **forward branch** from `0x80073ea8` —
   the `ctx[7] & 1` test jumps *to the tail*.
4. **`ctx[1]` is read once** and feeds both byte stores, so the source held it in a variable.

## The draft, and where it stops

`fixtures/decomp/partials/stage2/80073e38.{c,json}` — the symbol-based draft (the table named, the addends kept in the
access expression per M372), with its six symbols declared in the sidecar. **2 of 58.**

Two mechanisms spent: absolute literals (0 of 58 — the compiler folded the table plus its addend into one `lui`/`ori` and
used `$at` for every absolute store), then symbols with the addends apart (2 of 58). **The residue is statement order at
the top of the function**: the image builds the `0x18000` constant, then the first store's address, then reads `ctx[1]`,
while our draft binds `t` first and reads `ctx[1]` early. That is the named next hypothesis, not a guess at a third
wording.

## A gap in the partials gate, found by using it

The first `--check` failed with *"link failed (a missing symbol?)"*: a partial may declare `extern` symbols, and the gate
did not pass them. Fixed — the sidecar now carries `syms` and `partials.py` passes each to `leaf_screen --sym` — which is
the same rule M371 established for reconstructions: **a body whose symbols live outside its own artefact cannot be
re-scored**. `--check` is **2/2**.

## Moves

**Nothing registered.** `recovered` **274 / 273**, `F1` **3 468**, `named` **45**, coverage **1 238 404 B**; rung **317**.
Two partials are now published with drafts and scores (`2 of 58`, `3 of 38`), and partials gate cases **1 → 2**.
