# M331 — `vector_installer`: the PRId dispatch is a chain over two *flag* values (+6 → 0)

The last section with a real surplus, and it had two defects, one of them the second semantic error in two milestones:
the draft compared the flag against the **outputs** instead of against the flag's own values.

## 1. What the image actually tests

Decoded from the operand fields, not from a rendered listing:

```
115 lui $v1,0x8000      ; 116 lw $v1,768($v1)      v1 = *(u32*)0x80000300
117 bnel $v1,$zero,+4   ; 118 addiu $v0,$zero,0x2  seed the second compare; slot runs only if taken
119 lui $v0,0x02f5      ; 121 ori $v0,$v0,0xb2d2   v1 == 0  ->  0x02F5B2D2
120 j 0x800072bc
122 bne $v1,$v0,+3      ; v1 == 2 ?
123 lui $v0,0x02e6      ; 125 ori $v0,$v0,0x025c    v1 == 2  ->  0x02E6025C
124 j 0x800072bc
126 ori $v0,$v0,0xd354  ; else     ->  0x02E6D354
127 lui $at,0x8001      ; 128 sw $v0,10440($at)    one store, at the join
```

`bnel $v1,$zero` then `bne $v1,$v0` with `v0 = 2`: the comparisons are against **0** and **2**. Every draft since M325
had

```c
D = (D_80000300 == 0x02F5B2D2) ? 0x02F5B2D2 : ((D_80000300 == 0x02E6025C) ? 0x02E6025C : 0x02E6D354);
```

— comparing a flag with the constants it *selects*, which is not what the image does and is not what any sane source
would do. It compiled to a similar-looking branch tree, so five milestones of offset counting never noticed. This is
M330's lesson repeating with a different operand: **a word count cannot distinguish `== 0` from `== 0x02F5B2D2`
either** — only reading the compared operands can.

## 2. The shape: a chain with one store, not a nested ternary

Written as the chain the `j`s imply — a single store at the join point:

```c
u32 id = D_80000300;
u32 pri;
if (id == 0)       pri = 0x02F5B2D2u;
else if (id == 2)  pri = 0x02E6025Cu;
else               pri = 0x02E6D354u;
*(u32 *)0x800128C8u = pri;
```

cc1 reproduces the image's control flow **exactly**: `bnel` for the first test, a `j` chain to the join, `ori`s for the
three candidate values, and the address materialised only at the store (`lui $at`, one `sw`). Two things the ternary
version could not do and that are worth naming: the nested ternary **hoisted the destination address** (`lui $a1,0x8001`
before the `FUN_80006650` call) and **rematerialised `lui 0x02e6` twice**; the chain does neither.

## 3. Measured

```
                            code insns   dispatch section   ledger total
draft-008 (ternary)         134          21                 +2
draft-009 (chain)           130          19                 -2
image                       132          19                  —
```

`leaf_screen` reports **132 compiled words for draft-009 — the image's own count** — but those 132 include two
section-padding nops after the epilogue (`objdump` puts the last real instruction at `0x800072c4`, and `.text` is
`0x210`). So the honest figure is **130 instructions of code against the image's 132**, and the section ledger closes
with the dispatch at **19 vs 19**.

Where the remaining −2 sits, and it is all one-word placements this arc already capped:

| region | delta | why |
| --- | --- | --- |
| prologue head | **+1** | our window store sits before the `jal` instead of in its slot (M328: `$at` and schedulable do not combine) |
| both poll loops | **−1** | the image leaves a `nop` in its back-edge slot (M329) |
| 64-bit ×3 | **−2** | our pair arithmetic is two words tighter than the image's (M330) |
| after `FUN_80006100` | **+1** | constant-0 argument materialised as `addu` where the image uses `addiu` |
| PRId dispatch | **0** | fixed here |
| **total** | **−2** | 130 against 132 |

## 4. What this closes

Every section of the function is now within one word, and the dispatch — the last real surplus — is gone. What stands
between this draft and byte-exactness is no longer shape: it is **register naming** (word-identical is 16 of 132 while
the register-agnostic alignment is 58, and the four one-word placements above). Two of those three placements are the
image being *worse* than us (a redundant `lui`, a `nop`), and the third is a compiler-version difference proven by
three assemblies. So the remaining gap is the allocation the original build made, i.e. **the wall this project closed in
M311/M295** — which means `vector_installer` should be published as a measured near-miss, not chased further: four
drafts, one section at a time, took it from 18 of 132 to a function whose every region is the right length and whose
control flow matches instruction for instruction.

## Numbers

- **code 130 instructions (image 132)**; `leaf_screen --try` prints **132 compiled** because `.text` is padded to
  `0x210`; word-identical **16 of 132**, register-agnostic **58**, longest aligned run 39
- ledger: **+1, −1, 0, −2, +1, 0** = **−2**
- Drafts: `vi-draft-009.c` is **the reference** (supersedes 005/008); 007 and 008 are kept as the measurements behind
  M330
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
