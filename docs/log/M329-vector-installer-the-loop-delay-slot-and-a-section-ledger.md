# M329 — `vector_installer`: word 20 is not dead; the loop's delay slot is — and a section ledger

Both M327 and M328 closed by blaming an unexplained word in the middle of this function for the way every later offset
drifts. That word is image word 20 — `lui $a0,0x1fc0`, the fourth materialisation of the poll constant. It is **not**
dead, the difference is not ours, and once it is accounted for the function is **51 consecutive words correct**.

## 1. Is word 20 dead? No — and the branch offsets say why

Two poll loops sit on `0x1FC007FC`. Image words 13–25:

```
 13 lui $a0,0x1fc0        18 lui $a0,0x1fc0   <- loop 1's exit delay slot / loop 2's entry slot
 14 ori $a0,$a0,0x07fc    19 lw  $a1,16($sp)  <- LOOP 2 BACK EDGE TARGETS 19
 15 jal FUN_8000d2d0      20 lui $a0,0x1fc0   <- the word in question
 16 addiu $a1,$sp,0x10    21 ori $a0,$a0,0x07fc
 17 bne $v0,$zero,-4      22 jal FUN_8000d360
 18 lui $a0,0x1fc0        23 ori $a1,$a1,0x8
                          24 bne $v0,$zero,-6
                          25 sll $zero,$zero,0  <- the back-edge delay slot is a nop
```

Loop 1's test (word 17) targets word 14; loop 2's test (word 24) targets word **19**. So on a loop-2 iteration word 18
never executes, and **word 20 is the only materialisation of the constant on that path** — remove it and loop 2 ORs a
low half into whatever `$a0` happens to hold. It stays.

What *is* waste in the image is smaller and differently placed than "one dead word":

- **word 18's value is dead on loop 1's exit path** — when the `bne` is not taken the delay slot still runs, and word 20
  immediately recomputes the same register. One instruction, once, and it is the compiler's delay-slot steal from loop
  2's head landing in loop 1's slot.
- **the image's back-edge delay slot is a `nop`** (word 25) where ours reloads the high half into it. That is one word
  **per iteration**, and it is why the branch distance differs — image `bne $v0,$zero,-6`, ours `bne $v0,$zero,-5`. The
  offset is the signature of the placement: 7 words per image iteration, 6 per ours.

Words 11–19 match the draft exactly, word for word; the divergence starts at 20 and is a *structural* choice about where
a constant is re-materialised. **Capped, by construction rather than by compiler version**: no C shape asks for a `nop`
in a delay slot. This is our only negative delta in the function, and reproducing it would mean making the loop worse.

## 2. The ledger — where the eight extra words actually are

Section lengths, both sides aligned on the eleven `jal` targets in order:

| section (from this call to the next) | image | ours | delta |
| --- | --- | --- | --- |
| `FUN_800072d0` … (prologue, window store) | 3 | 2 | −1 |
| `FUN_8000cde0` | 3 | 3 | 0 |
| `FUN_8000ccf0` | 4 | 4 | 0 |
| `FUN_8000d2d0` … (both poll loops) | 7 | 6 | **−1** |
| `FUN_8000d360` … (four copies + both cache calls) | 46 | 46 | 0 |
| `FUN_8000efa0` | 3 | 3 | 0 |
| `FUN_800073d0` | 2 | 2 | 0 |
| `FUN_80007ef0` | 3 | 3 | 0 |
| `FUN_8000c940` … (mask block + the 64-bit ×3) | 26 | 33 | **+7** |
| `FUN_80006100` … | 11 | 9 | **−2** |
| `FUN_80006650` … (PRId dispatch + epilogue) | 19 | 23 | **+4** |
| **total** | **132** | **140** | **+8** |

Three facts fall out, and they re-price the whole remaining chase:

1. **The 46-word middle is exactly the right length** — the copies, the two cache calls and the mask block take the same
   number of words as the image. M327's copy fix was not a word-count win; it was a *shape* win.
2. **The offset drift is retired as an error.** The single word M327 and M328 kept attributing to a shift is this loop
   artifact: ours is one word *short* there, so everything after it sits one word early. Measured with that one word
   taken out of the alignment: **51 consecutive words align register-agnostically** — our words 27–77 against the
   image's 28–78, running from the first `lui` of the copies through `lw $v0,20($sp)`, i.e. the copies, both cache
   calls, `FUN_80007ef0`, `FUN_8000c940` and the mask block's first instruction. Half the function is
   instruction-for-instruction correct and differs only in which registers the allocator chose.
3. **The +8 is concentrated, not diffuse**: +7 in one region and +4 in another, against −3 spread over three. The next
   milestone has a single address: the mask block and the 64-bit ×3 around `FUN_8000c940`/`FUN_80006100`, where our
   draft emits `addu $v0,$zero,$zero`, `addu $a0,$v0,$zero` and `sll $v0,$v1,0` to shuffle the 64-bit pair between
   registers. That is the largest remaining defect and it is a data-shape question, not a scheduling one.

Register-agnostic alignment at fixed offset is 60 of 132; `leaf_screen --try`'s word-identical count is unchanged at
**16 of 132**, because no draft changed in this milestone — word 20 was measured, not fixed.

## 3. What this milestone is

A measurement, not a fix, and it changes what the next fix should be: the deficits are **+7 here, +4 there**, no longer
"some drift after the loops". The reference draft remains `vi-draft-005.c`; nothing was registered.

## Numbers

- **Word-identical 16 of 132 (draft-005, unchanged)**; 140 compiled, image 132; register-agnostic 60 at offset,
  **51 in one run** when the loop's one-word deficit is taken out of the alignment
- Section ledger: **−1, 0, 0, −1, 0, 0, 0, 0, +7, −2, +4 = +8**
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
