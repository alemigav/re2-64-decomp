# M326 — `vector_installer`: `$s0` solved, `0x2000` not, and the wall it names

Two chases, both to ground. One converted, one did not — and the second one says something larger than the function.

## 1. `$s0`: solved, and it was CSE across a call

The draft saved `$s0` where the image does not. Three rounds of disassembly found it exactly:

```
lui $16,%hi(D_800128C0)   ;  $s0 = the ADDRESS of D_800128C0
lw  $3,%lo(D_800128C0)($16)     ; read it (the 64-bit combine)
...  jal FUN_80006100            ; the call
sw  $2,%lo(D_800128C0)($16)     ; write the result AFTER the call — so the address is live across it
```

The C used one symbol three times (two reads, one write after the call); gcc's CSE merged them into one pseudo and
`global_alloc` kept it in a callee-saved register. **The image materialises that address three separate times** —
words 89, 91 and 106, the last through the assembler temp `at` — so its source's references were *not* merged across
the call.

Breaking the CSE does clear `$s0`: reading the pair through literal addresses and writing through the symbol gives two
different rtx trees, and the frame now matches the image word for word (`sw $ra,24($sp)` / `sw $zero,20($sp)`).
**But the offset score fell to 2/132**, because the prologue then *orders* differently (we materialise the store's
address first, the image materialises it into `at` and stores in the `jal`'s delay slot). The structure improved while
the number got worse — which is the honest way to say that offset-identical is the wrong single metric for a
132-word function.

## 2. `0x2000`: three forms, one answer — it is an idiom, not a shape

The image has `lui $a0,0x2000` *before* the `jal` and `or $a0,$v0,$a0` in its delay slot; ours folds to a single
`ori $a0,$v0,0x2000`. Measured: the literal (`0x2000 | FUN_800072d0()`), the constant on the left, and a `mask`
variable all give **`ori`**. gcc 2.8 chooses `ori` for an or-with-constant, and only uses the register form when the
constant is already in a register — which its own scheduling decided against.

That is the **same family as `slti` vs `srl`** in M324 (`boot:0x800115b0`): not a source shape, but a codegen idiom the
original build chose differently. Two instances now, and both sit in the boot image.

## 3. What this means for the function

`vector_installer` is 132 words, and its resistance is not structural — the sequence, the calls, the four copies, the
poll loops and the dispatch are all read correctly. It resists because it contains **a dozen or more of these idiom
choices** (`at` vs a general register, `or` vs `ori`, when to materialise an address, which of `slti`/`srl`), and each
one costs a disassembly round-trip to find and may not be reachable from C at all.

That is a different class from the allocation residues: it is not one register in one arm, it is **the compiler's
style versus the original build's style**, one instruction at a time. Named here so the next session starts from it
rather than from 18/132.

## Numbers

- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
- drafts kept at `build/probe/vi-draft-001.c` (18/132) and `vi-draft-002.c` (`$s0` cleared, prologue divergent)
