# M330 — `vector_installer`: the 64-bit ×3 is pair arithmetic (+7 → −2), and a polarity bug falls out

The ledger put the function's largest excess at one address: the 64-bit multiply by three and the mask block around it,
**+7 words**. It is now **−2**, in nine words of change, and the chase turned up something the offset metric had been
hiding — a condition in the draft that is simply **wrong**.

## 1. Three spellings of the same multiply, measured

The image computes `0x800128C0/C4 × 3` as eight instructions on **32-bit halves** and passes the halves straight in the
argument registers:

```
 93 sll $a0,$v0,1    hi <<= 1          99 addu $a0,$a0,$v0    hi += hi_old
 94 srl $a2,$v1,31   lo >> 31         100 addu $a0,$a0,$a2    hi += carry
 95 or  $a0,$a0,$a2  hi |= lo>>31     101 addiu $a2,$zero,0   third argument
 96 sll $a1,$v1,1    lo <<= 1         102 jal FUN_80006100
 97 addu $a1,$a1,$v1 lo += lo_old     103 addiu $a3,$zero,4   fourth argument
 98 sltu $a2,$a1,$v1 carry = lo < lo_old
```

Three C spellings, each compiled and read:

| source | what comes out |
| --- | --- |
| `u64 t = ((u64)hi << 32) \| lo; t = t * 3;` (draft-005) | the same eight operations **plus five register-pair shuffles** — `addu $v0,$zero,$zero`, `addu $a0,$v0,$zero`, `sll $v0,$v1,0`, `addu $v1,$zero,$zero`, `or`/`or` — because a `DImode` value has to be *built* from two `SImode` loads before it can be multiplied |
| `u64 t = *(u64 *)0x800128C0u * 3;` | the eight operations are **exactly right**, but extracting the halves for the call still costs five moves (`srl $5,$2,0`, `move $4,$0`, `move $4,$5`, `move $5,$3`, `move $6,$0`) |
| **`u32` pair arithmetic** — `hi3 = (hi<<1) \| (lo>>31); lo3 = lo<<1; lo3 += lo; hi3 += hi; hi3 += (lo3 < lo);` | the image's eight instructions, **zero copies** |

So the +7 was not scheduling and not allocation: it was **a `DImode` the original source never had**. The image's own
instruction sequence spells pair arithmetic, and asking for a `u64` — even a well-formed one, loaded from a `u64`
lvalue — makes cc1 build and shuffle a register pair that the image never builds. One further word was hiding in the
same block: the draft declared `u32 FUN_80006100(...)` and stored only the high half, where the image stores **both**
returned words (`sw $v0,10432($at)` and `sw $v1,10436($at)`, the second in the `bne`'s delay slot). Declaring the return
`u64` and storing `*(u64 *)0x800128C0u` reproduces both.

## 2. What it measured

```
                              insns   ledger total   this section (image 26)
draft-005  (u64 build)        140      +8             +7
draft-007  (pair arithmetic)  136      +3             −2
draft-008  (+ polarity fix)   136      +4             −2
```

The section is now **our only two-word surplus-free region** — 24 words against the image's 26, because our argument
setup is one word tighter and our constant seeding differs. Register-agnostic alignment rose 57 → **60** of 132; the
word-identical count stays 16 because what remains in this block is register naming (`$a0/$a1` against `$4/$5`).

## 3. The bug the ledger found

Chasing the block's neighbours surfaced a straight **semantic** error in the draft, not a shape question. The image tests
the flag with `bne $a0,$zero,+5`, which **skips** the `FUN_80006650` call when the flag is nonzero — so the call happens
when `D_8000030C` is **zero**. Every draft since M325 had `if (D_8000030C != 0)`, the inversion. Corrected to `== 0`,
the branch form now matches the image (`bne`, six words of fall-through) and the region costs +1 instead of −2.

That is worth stating as method rather than as an anecdote: **the ledger measures word counts, and a word count cannot
tell you that a condition is inverted** — an inverted `if` costs the same one word either way. What caught it was
reading the branch's own polarity against the call inside its range. Every remaining section should be read that way
before its word count is trusted.

## 4. What is left — one section, and it is the ternary

`+6` in the PRId dispatch, and now the only defect left of any size. The image writes it as a **jump chain**:

```
117 bnel $v1,$zero,+4    118 addiu $v0,$zero,2      <- seeds v0 = 2 in the slot
119 lui $v0,0x02f5       120 j store               121 ori $v0,0xb2d2
122 bne $v1,$v0,+3       123 lui $v0,0x02e6        124 j store   125 ori $v0,0x025c
126 ori $v0,0xd354       127 lui $at,0x8001        128 sw $v0,10440($at)
```

Ours hoists the *address* (`lui $a1,0x8001` before the call), rematerialises `lui $0x02e6` twice, and branches with
plain `beq`/`bne` pairs and no `j` — 25 words against 19. The `bnel` plus the `v0 = 2` seed says the original source was
not our nested ternary; the next draft should be written from that chain backwards, and the `2` is the clue worth
starting from.

## Numbers

- **Word-identical 16 of 132** (registers are all that is left in the fixed block); register-agnostic 57 → **60**
- Instructions compiled **140 → 136** (image 132); ledger total **+8 → +4**; the 64-bit section **+7 → −2**
- Drafts: `vi-draft-007.c` (pair arithmetic), `vi-draft-008.c` (+ polarity, **the reference draft**)
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
