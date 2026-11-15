# M442 — the repair loop's first piece: a words-level scorer, two hard walls, and branch-likely quantified

The loop needs three things: a scorer that answers *what still differs* for an arbitrary candidate, a set of edit
proposals driven by that answer, and a fixpoint that keeps improvements. The first piece is built and the second is
partly measured; **no body closed**, and the two reasons are both structural rather than puzzling.

## What the scorer does

`words_of(image, addr, words, body_text)` compiles any candidate body through `distance_map`'s own ladder and preamble
and returns **both word lists**, plus a decoder that prints the pair per index. That is the unit the loop iterates on:
the existing `leaf_screen --try` scores a file, and `type_repair` substitutes text, but neither hands back the two
decodable words at the first difference, which is what a proposal has to be derived from.

## Target 1 — `boot:0x80004bac`, 13 of 14, and it is a constant-materialisation wall

One word differs (`addiu v1,v1,10380` against `ori v1,v1,0x288c`), and **both compute the same value** `0x8001288C`.
gcc picks `ori` for an absolute constant load and `addiu` for a **symbol address** (`lui %hi` + `addiu %lo`). Twelve
edits were tried and none closed it:

| edit | score |
| --- | --- |
| as-is | 13 / 14 |
| reorder the addition | **4** / 14 |
| cast the constant, cast the product, unsigned product, positive hex, subtract the base, int pair | 13 / 14 |
| spell the base as `&DAT_8001288c` (symbol address) | **11** / 14 |
| same, with a `char *` cast | 12 / 14 |

So the draft's *arithmetic* form is already the best available, and the symbolic form — the one that should produce
`addiu` — drags two other words out of place. The body is reachable only by finding the source shape where gcc keeps
the address as a symbol **and** folds the index the same way, which is not a substitution.

## Target 2 — `stage2:0x800540d4`, 4 of 6 → 5 of 6, then a wall our toolchain cannot pass

The draft is `for (iVar1 = 7; iVar1 != 0; iVar1 += -1) { }`. Loop shape was the lever and it moved:

| shape | score |
| --- | --- |
| draft (`i = 7`) | 4 / 6 |
| `while (i--)` | 0 / 6 |
| `for (; i--; )` | 0 / 6 |
| `for (; --i; )` | 4 / 6 |
| **`do { } while (--i)`** | **5 / 6** |
| **`for (i = 8; i != 0; --i)`** | **5 / 6** |

The remaining word is `bnel` against our `bne`. **This `cc1` cannot emit branch-likely**: `-mbranch-likely` is
rejected as an invalid option, and it is not reachable through any ISA or CPU choice either —

| flags | score |
| --- | --- |
| `-mips2 -mcpu=r4300`, `-mips3 -mcpu=r4300`, `-mips3`, `-mips2 -mcpu=vr4300`, `-mips3 -mcpu=vr4300`, `-mips2 -mcpu=r4600`, `-mips1 -mcpu=r4300` | **all 5 / 6** |

— and the **assembler does not relax into it either**: gas emits `1440ffff` (`bne`) under `-mips2` and under `-mips3`,
because cc1 wrote plain `bne` and gas preserves it.

## How big that wall is

Measured over all 2 552 paired bodies: the first difference is a branch-likely instruction in **5 open bodies**
(`bnel` 4, `beql` 1). So the wall is absolute but small — it is worth **5 bodies, not a strategy**, and the honest thing
is to skip them rather than chase a compiler build for them.

## State, stated plainly

- **No body closed.** `recovered` stays **668**. The scorer works; the proposal table does not yet contain an edit that
  closes either target, and the second target cannot be closed by *any* edit with this toolchain.
- The loop's first piece is real and reusable: give it a candidate and it says which words differ and what they say.
- The next bodies to try are ones whose single difference is a class already proven to work — the 39 bodies
  `type_repair` banked are the evidence that the type class does close bodies; the near population simply no longer
  contains any.

## Numbers

- scorer built and used for **12 edits on one body and 12 candidate bodies on another**; best scores **13/14** and **5/6**
- `-mbranch-likely` **rejected** by this `cc1`; 7 flag combinations and 2 assembler ISA levels all produce `bne`
- branch-likely first differences across the corpus: **5 open bodies** (`bnel` 4, `beql` 1)
- `recovered` **668**, unchanged; nothing banked, no fixture touched
