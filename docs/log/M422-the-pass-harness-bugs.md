# M422 — six more bodies, and two bugs in the pass harness that were hiding them

The queue analysis said 12 differing words in the ≤2-word band are `addiu` against `ori` — the mechanism `symbol:addr`
already proved at **10 of 10** on its source body. The pass closed nothing. That gap is the milestone.

## Two harness bugs, both in the pass framework

1. **A variant's generated declaration used a type the body did not have.** `symbol:addr` emits
   `extern u8 D_80143fb0[];` — and that body has no `u8` typedef, so cc1 refused the variant and the pass recorded a
   measured zero for a mechanism that scores full marks. It now emits `unsigned char`.
2. **A variant's symbols were never handed to the pin.** The variant introduces `D_80143fb0`, which must be *defined*
   at its address for the linker; the pin got only the provider draft's symbol table and failed. Then the same bug one
   level down: the *banked entry* also carried the provider's `syms`, so six entries were written whose pins failed —
   the probe suite reported **664 of 670** until the entries were withdrawn and re-banked with `syms_for(variant, syms)`.

**Rule: a pass that introduces a name must bring its address with it, everywhere the name is used** — the pin and the
fixture entry are two different places, and fixing only the first produced six claims the gate could not verify.

## The measurement after the fix

| pass | near band (200) | mid band (464) |
| --- | --- | --- |
| **`symbol:addr`** | **6 closed**, 10 improved | 0 closed, 13 improved |
| `dat:width` | 0 closed, 23 improved | 0 closed, 61 improved |
| `order:adjacent` | 0, 1 improved | 0, 19 improved |
| `guard`, `sig:forward`, `sig:param` | 0 | 0 |

**641 → 647 of 3 664 (17.7 %)**, all six pinned (670 of 670 probe cases).

## What it says about the queue

The band's remaining members are the ones whose difference is **structural**: `lhu` against `lw` (a half read where a
width is not the answer), `addu` against `andi` (a mask where an add is emitted), `beq` against `j` (a tail call's shape),
and the same-opcode residues that are allocation. Each is one body's decision, not a pass.

The 13 `addiu`/`ori` bodies in the mid band that `symbol:addr` *improved without closing* are the next thing to look at:
the mechanism moved them, which means the literal is only part of what differs — the same lesson M421 taught about the
width class, one class over.
