# M413 — the 8-word band, pass by pass: the mechanical classes are exhausted at 2 of 251

The band was the mechanical queue: 251 unclaimed bodies at most eight words from byte-exact. It was worked pass by pass,
and each pass was measured before the next was written — so the number below is not an estimate of what substitution can
do, it is what it did.

## Closure per pass

| pass | class | bodies closed |
| --- | --- | --- |
| A | cast width/signedness (16 rows: `*(char *)`↔`*(unsigned char *)`, `*(short *)`, `*(undefined2 *)`, …) | **0 of 251** |
| B | declaration types (`undefined1/2/4`→`unsigned char/short/int`), the M396c `materialise` rows, and commutative **operand order** (the M401 mechanism in its cheapest mechanical form) | **0 of 251** |
| C | **declaration-line signedness** — `char cVar1;` → `unsigned char cVar1;` | **2** |
| | | **2 of 251** |

Pass A closed nothing because the 24 bodies it would have closed were already banked at M411 (gap ≤1) and the 13 more at
gap ≤4. Pass B closed nothing, which is the informative one: **operand order and declaration types do not move this
band either.**

Pass C came out of *looking* at a refusal instead of guessing: `boot:0x80004b5c` differs at one word, the image has
`andi $v0,$v0,0x00ff` and ours has `sll $v0,$v0,24`, and the body declares `char cVar1;` — a **signed** declaration where
the image reads unsigned. The class is real and it is small, because most declarations were already right.

## What the band's residue actually is

Classifying the differing words across the band before writing any pass:

| differing opcodes | share of sampled diffs |
| --- | --- |
| **same opcode** (`lui`→`lui`, `addu`→`addu`, `addiu`→`addiu`, `lw`→`lw`, `sw`→`sw`, `sll`→`sll`) | **82** |
| width/signedness (`lbu`→`lb`, `lh`→`lw`, `lbu`→`lw`) | 24 |
| materialisation (`addiu`→`lui`, `sw`→`lui`, `addiu`→`ori`) | 23 |

The width and materialisation classes are the ones the passes cover, and they are spent. **The 82 same-opcode
differences are the allocation class** — the residue M396–M408 spent twenty mechanisms on — and text substitution cannot
reach it, which is exactly what the pass result says.

## So the band is not the mechanical queue I called it

M412 said "to ~25 % is mechanical: close the 316-body band". That was wrong, and the pass table is the correction: **2 of
251 close mechanically, so the band is worth ~16.2 %, not 25 %.** The remaining 249 need a mechanism each, at the rate
M378–M387 measured (~5 per milestone) — the same instrument class, and the same cost, as the mid band.

That is the third time a promised rate has been revised downward by measurement, and the pattern is consistent: **what
is mechanical is the *measuring*, not the *closing*.** The instruments built in M409–M412 took the corpus from 7.5 % to
16.2 % by revealing work that was already done; every body after that has to be written.

## The numbers, honestly

| | bodies |
| --- | --- |
| byte-exact | **591 of 3 664 (16.1 %)** |
| of which the decompiler's C, verified | **318** |
| band closed this milestone | 2 |
| band remaining | 249 |
| mid band (25–89 % match) | 333 |
| far mass (< 25 %) | 1 966 |
| refused / no C | 311 / 196 |

`3 of 3` banked-exact cases and `614` probe cases still pass; the two closed bodies are pinned and carry
`provenance: "provider"`.
