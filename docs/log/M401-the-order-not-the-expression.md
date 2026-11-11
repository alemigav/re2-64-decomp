# M401 — `0x80073e38`: the residue was ORDER, and the order is the allocation

M396c proved the compiler could be made to materialise every constant the way the image does — `0x18000` in `$a0`,
`0x20000` in `$a1` — and then stalled at **3 of 58**, because the words after 2 were in the wrong *sequence*. M401 is
that sequence, and it is worth **43 of 58**.

| mechanism | score |
| --- | --- |
| absolute literals | 0 of 58 |
| symbols, addends in the access expression | 2 of 58 |
| symbol at the pre-addend address | 0 of 58 |
| `u32 base` + a variable offset (M396c) | 3 of 58 |
| **the image's statement order, with every constant a register value** | **43 of 58** |

## What "read the image's order literally" actually bought

The image's build order, read off the words rather than off the C:

```
0x18000 -> $a0          3-6   store-1 address: 0x800FE288 + 0x8000, IN A REGISTER
8     ctx[1] -> $a3     9     0x20000 -> $a1
10    store 1           11-13 table -> t = table + 0x18000
14    global @0x801152CC 15    flag = *(u32*)(t+6716)
16-17 store 2 = table + 0x20000, displacement 3925
18-20 flag & 0x40 ... with `sw a2,1328(t)` in the beq's DELAY SLOT
```

Mirroring that order alone took 3 to **10**. Two further sentences did the rest:

**The else arm re-derives its pointer.** The image spends five words rematerialising what it already had in `$a0`:
`lui a2,1; ori a2,0x8000` (0x18000 again), `lui v1,0x800c; addiu v1,0x76b0` (the table again), then `addu`. Written as
a block with its own `u32 o = 0x18000` and `u8 *w = base + o`, gcc reproduces all five — and, as a side effect, rotates
the whole allocation into the image's: `v -> $a3`, `t -> $a0`, `old -> $a2`. **15 to 43.**

**The tail arm's base is `table + (0x8000 | ctx[1])`, not `table + 0x18000`.** The two arms address different records.
The image writes it with `ori` (`ori v1,v1,0x8000`), reusing the register the `v == 30` compare's zero-extension already
filled, so the C had to say `|` and not `+`: the OR form is also what stops the tail arm overshooting in length.
**10 to 15.**

And one negative that mattered: store 2's `3925` **must stay outside the integer sum**. `base + off2 + 3925` lets the
two constants meet and folds them into a single `lui 2; ori 0x0f55` (0x20F55); a named pointer (`p2 = base + off2;
p2[3925] = v;`) forces the addend into a register and leaves `3925` a displacement, exactly as the image has it.

## The 15 words that remain, and they are one problem

1. **Words 3–5 are transposed.** gcc schedules `ori v1,zero,0x8000` *before* `lui v0,0x8010; addiu v0,0xe288`; the image
   has the base first. Tried as pointer arithmetic (`u8 *s1 = D_800fe288 + k8`), as `k8 + symbol`, and as a separate
   statement — the transposition survives all three, so it is the scheduler's, not the expression's.
2. **`$a1`/`$a2` are swapped** between the `0x20000` constant and the loaded global (words 7, 9, 14, 16, 20).
3. **The tail arm re-narrows `v`** (`andi v1,a3,0x00ff` at 49) where the image reuses the compare's zero-extension,
   which shifts 49–57 by one word *and* makes the add's destination `$v1` instead of `$a0`.

They are one allocation problem, and the third one is a trap worth recording: the obvious fix — hoist the narrowed byte
into a `u32 vz` used by both the compare and the tail — scores **21**, because `u32 vz = v` costs nothing after `lbu`,
so the `andi` at word 21 vanishes and the whole prologue shifts with it. The image's `andi` at 21 exists *because* the
compare is written on a `u8`; it then reuses that extension. Reproducing an artefact that only arises from an
inefficiency requires keeping the inefficiency.

## Where that leaves the body

The published score moves **3 → 43 of 58** and `partials.py --check` re-derives it. The residue is no longer about
materialisation, arithmetic domain, or statement order — all three are settled — but about three allocation decisions
that the C does not reach directly. That is a different kind of wall from the one M396 hit, and it is the first time
this arc has had to say so.
