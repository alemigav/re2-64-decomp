# M333 — `vector_installer`: the 64-bit shift block, measured to the instruction, and the mask word capped

There is no +5 in this function. The 64-bit block was **+7** at draft-005, and M330's pair-arithmetic fix turned it into
**−2** — the draft is now *two words shorter* than the image there, not longer. So this milestone is the block measured
to the instruction: where the two words went, and two attempts at them, both refuted by measurement.

## 1. The block, word by word

Image, `0x80007110`–`0x80007158` (the mask test, the two stores, the reload and the eight-operation multiply):

```
 78 lw $v1,20(sp)          89 lui $v0,0x8001    93 sll $a0,$v0,1    99 addu $a0,$a0,$v0
 79 addiu $v0,$zero,0xfff0 90 lw $v0,10432($v0) 94 srl $a2,$v1,31  100 addu $a0,$a0,$a2
 80 and $a0,$v1,$v0        91 lui $v1,0x8001    95 or  $a0,$a0,$a2  101 addiu $a2,$zero,0
 81 beq $a0,$zero,+7       92 lw $v1,10436($v1) 96 sll $a1,$v1,1   102 jal FUN_80006100
 82 sw $a0,20(sp)          97 addu $a1,$a1,$v1  98 sltu $a2,$a1,$v1
 83 addu $v1,$a0,$zero
 84 addu $v0,$zero,$zero
 85-88 the two `lui $at` / `sw` pairs
```

Draft-009, same region:

```
 lw $2,20(sp) ; nop ; andi $2,$2,0xfff0
 beql $2,$0,$L16 ; lui $2,%hi(D_800128C4)     <- the slot only runs on the taken path
 sw $2,20(sp) ; sw $0,10432 ; sw $2,10436 ; lui $2,%hi(D_800128C4)
$L16: lw $3,%lo(C4)($2) ; lui $2,%hi(C0) ; li $7,4 ; lw $6,%lo(C0)($2)
 sll $5,$3,1 ; addu $5,$5,$3 ; sll $4,$6,1 ; srl $2,$3,31 ; or $4,$4,$2 ; addu $4,$4,$6 ; sltu $3,$5,$3 ; addu $4,$4,$3
```

The eight multiply operations are the image's, one for one. The −2 is two things, and they are different in kind:

1. **`andi` where the image materialises the mask** (`addiu $v0,$zero,0xfff0` + `and`). One word.
2. **two `addu` copies the image makes and we do not** — `addu $v1,$a0,$zero` and `addu $v0,$zero,$zero`, the masked
   value and the zero being moved into the registers the two stores use. Two words — against our one word of `lui` in
   the `beql` slot, which serves the reload path. Net −2.

## 2. The mask word: six compilations, one answer

`v & 0xFFF0` folded to `andi` in **every** spelling tried, on both compilers built here:

| source | gcc 2.8.1 | gcc 2.7.2 |
| --- | --- | --- |
| `v = v & 0xFFF0u;` (literal, unsigned) | `andi` | `andi` |
| `u32 m = 0xFFF0u; v = v & m;` (a local mask) | `andi` | `andi` |
| `v = v & 0xFFF0;` (literal, signed) | `andi` | `andi` |
| `v = v & 0xFFFFFFF0u;` (a **negative** mask) | `li $2,-16` **+ `and`** | — |

So the register form exists, and it is what a mask that does not fit `andi`'s zero-extended 16 bits produces. The
image's mask is **`0x0000fff0`**, which does fit — so its `addiu $v0,$zero,0xfff0` cannot have come from a literal
`& 0xfff0`. It came into the compiler as a **value** (a loaded or computed mask), and no C spelling of a constant mask
will reach it. **Capped**, with the reason named rather than as "unreachable".

## 3. The other `+1`: the word *moves* rather than goes

The section after `FUN_80006100` was +1, and the cause is visible: we hoist the `lui` of `D_80000300`'s address above the
`FUN_80006650` call (one extra word in that section, the load still happening after it). One draft tested the obvious
lever — read the flag through a literal address instead of the symbol (M327's rule makes that a bare operand, so the
assembler emits `lui $at` adjacent to the load and there is nothing to hoist):

```
draft-009 (symbol read)   block −2   after 6100 +1   dispatch 0     register-agnostic 58
draft-010 (literal read)  block −2   after 6100  0   dispatch +1     register-agnostic 57
```

The word did not go away, it **landed in the next section** — and the score fell by one, because the image's read is
provably a split symbol reference (`lui $v1` + `lw %lo($v1)`, a general register, not `$at`). So draft-009 stays the
reference and this word is capped as a scheduler artefact.

## 4. The reference that was worth fetching

The N64 assembly notes at `sites.google.com/site/consoleprotocols/home/homebrew/n64-assembly-home` are a beginner's
tutorial in the `bass` assembler, and they do not touch this function's compiler idioms — but two of their pages state
facts this milestone had had to measure:

- **"Conditional: only executes the delay slot if the branch is taken"** — the `beql`/`bnel` nullification rule. Our
  draft's mask block depends on it exactly: the `lui` in the `beql` slot is wanted only on the taken path, and the
  fall-through path needs `$2` to still hold the masked value. The image's `beql` at word 117 of the dispatch relies on
  the same rule.
- **"there are no immediate comparison options"** — branches compare registers, so comparing against a constant needs
  the constant seeded into one first. That is *why* the image carries `addiu $a2,$zero,0` (a third argument that is
  never loaded) and seeds `addiu $v0,$zero,2` in the dispatch's `bnel` slot — two words that look redundant until you
  know the ISA has no `bne $v1,2,label`.

Cited for **semantics** only, and as a source rather than a measurement: the project's rule is that a cited table is not
evidence for anything about *this* image, so the two facts above are still measured here — by the words that use them.

## Numbers

- **Block: image 26 words, draft 24 (−2)** — attribution: `andi` vs `li`+`and` (1) and two allocator copies (2), against
  one `lui` in the branch slot (1)
- **Draft-009 is unchanged and stays the reference**: real code **130 words** (image 132; `leaf_screen` prints 132
  compiled because `.text` is padded to `0x210`), word-identical **16 of 132**, register-agnostic **58**, longest run 39
- Ledger unchanged: `−1, 0, 0, −1, 0, 0, 0, 0, −2, +1, 0` — one block capped, one word moved and capped
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 74 suites / 1 108 cases (807 gated, 301 runnable); suites 74, tools 101
