# M450 — the shape triage: 4 of 14 are source-level, and two of those close on one missing argument

Thirteen diagnoses one at a time is expensive when the majority are unreachable. So the remaining gap-1 bodies were
**triaged by shape first**, on a discriminator that decides the question outright: the **multiset of instructions**,
registers included.

- same multiset, different order → **ORDERING**: the same words are present, so the difference cannot be a value. No C
  fixes it.
- differs only by `nop`s → **HAZARD-NOP**: the assembler's `#nop` expansion (M449).
- differs otherwise → **SOURCE**: an instruction's content is wrong, which is what writing C can fix.

One correction was needed before the numbers were trustworthy: our compile carries **trailing linker padding**, and a
padding `nop` balances the count against a hazard `nop` in the image. With padding stripped, `stage2:0x80033024` — which
M449 had already diagnosed as a hazard slot — moved from ORDERING to HAZARD-NOP, and `stage2:0x800608c8` with it.

## The triage

| class | bodies |
| --- | --- |
| **ORDERING** | **8** |
| **SOURCE** | **4** |
| **HAZARD-NOP** | **2** |

So **10 of 14 are the toolchain family** and only four are worth a deep diagnosis. That is the whole value of the
triage: it redirects the effort before it is spent.

## The two source-level closures

### `ovl_0090698:0x80165e40` — 34 words → **34 of 34**

The image loads `addiu a3,zero,512` before the call; the draft called `func_0x80089d54()` with **no arguments**. The
three leading arguments are the function's own, passed straight through. This is the **same missing-argument pattern**
as `ovl_0093192:0x801629d0` (M446) — the second occurrence, which makes it a *class* rather than a curiosity.

### `ovl_0090698:0x801661b8` — 36 words → **36 of 36**

The sibling of the above, with the identical defect. Closing both took one edit each after the first was understood.

## The two that did not close

**`ovl_00a0344:0x80162224`** (29 words) — `28 → 27 of 29` on aligned identity. The image computes `(uVar1 & 3) + 1`
**into its own register** before the call's argument setup, then accumulates the shifted byte into it. Three spellings
were tried: parenthesising reaches 22 of 29 positionally, two statements reach 27, and the residual is **which register
accumulates** the final sum (`addu v1` against our `addu v0`) — an allocation consequence, not a statement.

**`ovl_009dd02:0x80166408`** (47 words) — the `slti`/`sltiu` body M441 already refused. Unchanged, and now known to be
the same class: a comparison's signedness, which no cast in the substitution table reaches.

## Numbers

- triage over the remaining gap-1 bodies: **8 ORDERING, 4 SOURCE, 2 HAZARD-NOP** — 71 % are toolchain family
- **2 closed**: `ovl_0090698:0x80165e40` (34 of 34) and `ovl_0090698:0x801661b8` (36 of 36)
- 1 improved but not closed (29 → 27 of 29), 1 refusal carried forward
- `recovered` **672 → 674**, byte-exact **671 → 673**; probe **696/696**; tree 95 suites / **1843** cases
- the missing-argument pattern now has **three** instances, so it is the first source-level class with a name
