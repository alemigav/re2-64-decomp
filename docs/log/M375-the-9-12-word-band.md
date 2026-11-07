# M375 — the 9–12 word band: ten read, two refused, three left standing

The plan said the cheap end of the rung is not the small end, and M368 measured it: three of thirty-one at ≤8 words, seven
of eight at 9–12. This batch took the **56 entries at 9–12 words** and drafted fourteen of them.

## The result

| verdict | count | entries |
| --- | --- | --- |
| **byte-exact** | **10** | `0x80043374`, `0x8004343c`, `0x8004d320`, `0x80071df0`, `0x800390b8`, `0x80040e30`, `0x80074024`, `0x8002d164`, `0x8002e848`, `0x80052eec` |
| refused, with reasons | 2 | `0x80073efc` (the extent opens mid-expression: `ori $v1,$v1,0x8000` reads `v1` set outside the body), `0x8000f020` (a `cache` op — `op 0x2f` — which no C construct makes this `cc1` emit, the hand-written family that stays on the rung) |
| partial, published with its score | 3 | `0x8006fd30` 7 of 10, `0x800823b0` 8 of 10, `0x8002fc00` 5 of 9 |

Ten of fourteen drafted, and the three partials are register-or-order residues of two to three words each, not shape
failures — which is the pattern this band keeps showing.

## What each mechanism was

1. **A sign-extended base is the whole trap, twice in a row.** `0x80043374` and `0x8004343c` both read a table at
   `lui 0x8014` + displacement `0x9A80`, and `0x9A80` is **negative** as a signed 16-bit immediate: the address is
   `0x80139A80`, not `0x80149A80`. Both were byte-exact on the first draft because the C names the symbol
   (`D_80139a80`) and lets the assembler do the arithmetic; the two differ only in `lhu`+`sh` versus `lh`+`sw`, which is
   a `u16 *` versus a `s16 *` in the prototype.
2. **A pair of zero stores is a 64-bit store.** `0x8004d320` differs on four words in the natural spelling. The tell is
   `addu $a0,$zero,$zero; addu $a1,$zero,$zero; sw $a0,56($v1); sw $a1,60($v1)`: gcc materialises **two** zero registers
   and stores a 32-bit pair, which is exactly what `*(long long *)p = 0` lowers to under `-mips2`. With that, and with
   the base named as a **symbol** rather than a raw constant (`lui`/`addiu`, not `lui`/`ori` — M368's residue, again),
   it is 9 of 9. Two mechanisms for one nine-word body, and the second one is the body's whole content.
3. **An inline index beats a local.** `0x8006fd30`'s first draft bound `u8 idx = p[1]` and multiplied it: gcc emitted an
   extra `andi $v0,$v0,0x00ff` that the image does not have. Writing `p[1] * 2` in the access expression removed the
   mask — the same family as M372's "leave the addends where they are" — and left a two-register allocation residue
   (7 of 10) which the cap says is where this one stops.
4. **`sltiu` versus `slti` is a signedness fact, not a scheduling one.** `0x80052eec` was 8 of 9 with `int i`; the image
   has `sltiu`, so the index is unsigned. `u32 i` closed it in one word.
5. **The M372 shape recurs on its own.** `0x80074024` materialises `0x800C76B0` and `0x18000` in **separate registers**
   and `addu`s them, then indexes the pointer it loads. The spelling that works is the M372 one — bind the symbol, leave
   the addends in the expression — and the loaded pointer goes through a `u32` before being used as an address, which is
   what made the store's base register match.

## Two refusals worth their lines

`0x80073efc` opens with `ori $v1,$v1,0x8000` — the body starts *after* the instruction that should have set `v1`. That is
an **extent** defect, not a drafting failure, and it joins the four corrections already open (M377's queue).

`0x8000f020` is the boot's cache flush: `lui`, `addu`, `addiu`, then `cache ($op 0x2f)` in the delay slot of the bound
check, ending in `jr ra`. It is a real function; it is not C, and this profile cannot emit a `cache` instruction. It
stays on the rung, and the rung is where a reader can still see it.

## Moves

`recovered` **210 → 220** (219 byte-exact, one partial as before), **`F1` 3 457 → 3 464**, `F2` 3 397 → 3 404,
`extent_measured` **208 → 201**, rung **382 → 372 entries / 40 516 → 40 144 B**, probe cases **232 → 242**,
`make check` **219 exact of 220**. Coverage is unchanged at 1 238 112 B — the ten were already claiming their bytes as
measured extents, which is the cleanest demonstration of what this ledger does and does not mean.
