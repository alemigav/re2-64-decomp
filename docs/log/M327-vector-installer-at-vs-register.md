# M327 — `vector_installer`: `$at` is the assembler, and the draft had the two address forms inverted

M326 closed by naming `at` vs a general register as one of the dozen idioms this function resists on. It is not an
idiom the source cannot reach — it is a *rule*, the draft was writing both halves of it backwards, and correcting the
two directions is worth 17 words at absolute offset and a 39-word contiguous run.

## 1. What `$at` is, measured

The image uses `lui $at,0x8001` six times (words 4, 85, 87, 106, 108, 127) and **every one of them is a store**:

```
  4 lui $at,0x8001 /   6 sw $v0,20464($at)      ; *(u32*)0x80014FF0 = 1
 85 lui $at,0x8001 /  86 sw $v0,10432($at)      ; *(u32*)0x800128C0 = 0
 87 lui $at,0x8001 /  88 sw $v1,10436($at)      ; *(u32*)0x800128C4 = masked
106 lui $at,0x8001 / 107 sw $v0,10432($at)      ; the result pair, high word
108 lui $at,0x8001 / 110 sw $v1,10436($at)      ; the result pair, low word, in the bne's slot
127 lui $at,0x8001 / 128 sw $v0,10440($at)      ; the PRId
```

Every *read* of an absolute address in the same function goes through a general register instead (`lui $v0` +
`lw $v0,%lo($v0)`, words 89/90; the same at 91/92, 104/105, 115/116). So the split is not per-function or per-address —
it is **per access direction**, and it is a property of cc1, not of the cartridge. Five source forms, each compiled and
assembled with the project's own `cc1` and `as`:

| source form | what cc1 emits | what the word stream shows |
| --- | --- | --- |
| `extern u32 D; D = 1;` (symbol) | `lui $3,%hi(D)` + `sw $2,%lo(D)($3)` | a **general register** — the address is *split* |
| `*(u32 *)0x80014FF0u = 1;` (literal) | `sw $2,-2147397648` | **`lui $at` + `sw %lo($at)`** — `as` expands it |
| `*(volatile u32 *)0x80014FF0u = 1;` | `li $3,0x80010000; ori $3,$3,0x4ff0; sw $2,0($3)` | a general register, **two** instructions |
| `extern u32 D; return D;` (symbol) | `lui $2,%hi(D)` + `lw $2,%lo(D)($2)` | a **general register**, base = destination |
| `return *(u32 *)0x800128C0u;` (literal) | `lw $2,-2147407680` | **`lui $at`** |

The mechanism is `mips_split_addresses` (`config/mips/mips.c`, on when `TARGET_GAS && TARGET_SPLIT_ADDRESSES &&
optimize`): a bare `SYMBOL_REF` address is *legitimate* on its own when splitting is off, so the compiler prints the
symbolic operand and leaves the high half to the assembler, which is what `$at` is for. With splitting on, cc1
decomposes the address into `HIGH`/`LO_SUM` and a general register appears. Measured directly: the same symbol store
under `-mno-split-addresses` becomes `sw $2,D` — assembled, `lui $at` + `sw %lo($at)`.

**So `$at` in this image is not "an older register allocator" — it is the assembler finishing an address the compiler
declined to split.** And a literal address is never split, whatever the flag says; `volatile` is the one form that
*forces* a register, because a volatile access may not be re-materialised.

## 2. Fix 1 — the two directions were inverted (2 → **19** of 132)

M326 broke the `$s0` CSE by reading `0x800128C0/C4` through literal addresses and writing them through the symbols.
That cleared the frame and cost the score (2 of 132), and it was **exactly backwards**: the image reads through
symbols (split, general register) and writes through literal addresses (`at`). Swapping the two directions — and
leaving no symbol store anywhere, which is also what finally removes `$s0` for good — gives:

```
  2 of 132  (draft-002, M326's endpoint)
 19 of 132  (draft-003: literal stores, symbol reads)
```

`lui $at,0x8001` and `sw $zero,10432($at)` now appear in the draft at the image's own offsets.

## 3. Fix 2 — refuted in one compile (19 → **19**)

The four 16-byte copies materialise their source base per copy (`addiu $10,$2,%lo(...)` ×4, two registers). The
obvious lever was a pointer local — `struct V *s = &D_800006C0; *dst = *s;` — since a bound base is what a hoisted
address looks like. **The emitted code is byte-identical to the unbound form** (diffed: one line, the `.file`
directive). In split mode the `HIGH` and `LO_SUM` of a symbol address are two pseudos whether or not the source named
one, and `global_alloc` decided not to coalesce them. Recorded as a lever that does not exist rather than a shape that
failed.

## 4. Fix 3 — the copy source must be a **literal** address (19 → **16** at offset, 144 → **140** insns)

cc1 has two entirely different expansions for a 16-byte copy, and which one you get depends on how the *source* is
spelled:

| source form | expansion |
| --- | --- |
| `*(struct V *)dst = D_800006C0;` (symbol) | `lui`+`addiu` **twice** per copy (`%hi` in one register, `%lo` in another), blocks of **2** (`lw,lw,sw,sw,lw,lw,sw,sw`) |
| `struct V *s = &D_800006C0; *dst = *s;` | identical to the row above |
| `*(struct V *)dst = *(struct V *)0x800006C0u;` (literal) | **one** base register, materialised **once** for all four copies, blocks of **3 + 1** (`lw,lw,lw,sw,sw,sw,lw,sw`) — the image |

The literal form is a `BLKmode` block move (`expand_block_move` → `movstrsi_internal`, whose `define_split` peels the
last store off so it can sit in a delay slot); the symbol form is expanded address-by-address and scheduled in pairs.
The image's copies are the block move: **39 words of the 41-word copy group now align instruction for instruction**,
with one base register and `la`-per-destination — including the destination's `lui $a2,0x8000` (low half zero) vs
`lui`+`ori` (low half non-zero), which the `la` expansion already produces.

Two costs, both measured and both *not* this fix's:

- **One word**: the base is `li`+`ori` (`lui $2,0x8000` / `ori $2,$2,0x06c0`) where the image has `lui` + `addiu`.
  That is the M322 `addiu`-is-sign-extended family, one instruction, not settled here.
- **One word earlier**: ours has 131 instructions to the image's 132 because loop 2 re-materialises its constant
  (`lui $a0,0x1fc0`) **twice** in the image (word 18, in loop 1's delay slot, and word 20) and once in ours — the
  image's word 18 is a dead reload inserted by delayed-branch scheduling. Our copy group therefore starts one word
  early, which is why the absolute score *fell* while the structure improved: at 132 words, absolute offset identity
  prices one inserted instruction in the middle as if the whole function were wrong.

At 132 words the fairer stick is a register-agnostic aligned comparison, and it moves the other way — **13 → 27 → 57**
of 132 words matching modulo register names, with the longest contiguous run going from 8 words to **39**. That number
is computed off-tool for this note and is a diagnostic, not a gate; `leaf_screen --try`'s word-identical count remains
the score of record.

## 5. What this re-prices

M326 called this function "the compiler's style versus the original build's style, one instruction at a time" and
estimated a dozen such choices, each costing a disassembly round-trip, "possibly not reachable from C at all". Two of
them are now settled as **reachable rules** rather than style:

- `at` vs a general register — decided by *access direction* and *address spelling*, in five measured forms (§1);
- how a 16-byte copy is expanded — decided by whether the source is a symbol or a literal, 41 words' worth (§4).

Both were one compile each *once the mechanism was named*; the round-trips were spent finding the mechanism, not the
fix. That is the reusable part: `$at` in this corpus is a fact about `mips_split_addresses`, not about luck, so any
future function that shows `lui $at` should be read as "this address was spelled literally (or left unsplit on
purpose)" before anything else is tried.

Still named and unfixed, in the order the diff shows them: the store that must sink into `jal FUN_800072d0`'s delay
slot (words 5/6); `lui $a0,0x2000` + `or` in a call argument (M326's `or`-vs-`ori`, words 7/9); the dead reload at
word 20; the `ori`-vs-`addiu` base; the 64-bit ×3's operand copies (`addu $v0,$zero,$zero` and friends, words
93–100); and the PRId dispatch, which the image writes as a `bnel`-and-`j` chain and our ternary as a compare tree
(words 117–128).

## Numbers

- **Word-identical: 2 → 19 → 16 of 132** (drafts 002/003/005); instructions compiled **144 → 140** (image 132)
- Drafts kept at `build/probe/vi-draft-003.c` (addresses fixed, 19/132), `vi-draft-004.c` (fix 2, identical codegen)
  and `vi-draft-005.c` (copies fixed, 40 of the 41-word copy group aligned)
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
