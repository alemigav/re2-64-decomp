# M328 — `vector_installer`: the store sinks, and the price is one hoisted word

The `jal`-delay-slot store was the next item on M327's list. It is reachable, it is measured, and it *loses* 14 words
on the stick — because the same change that puts the store in the slot moves its address computation to the top of the
function. Two more measurements say the image's exact word pair cannot be reached from this compiler at all, which caps
the prologue to the instruction.

## 1. The rule: only a *register-addressed* store is a slot candidate

Five spellings of the same store, each compiled alone and read as assembly:

| source | sinks into `jal`'s slot? |
| --- | --- |
| `extern u32 A; A = 1; f();` — symbol, **split** into `$3` | **yes** — `jal f` / `sw $2,%lo(A)($3)` |
| the same under `-mno-split-addresses` — bare `sw $2,A` | **no** |
| `*(u32 *)0x80014FF0u = 1;` — bare constant | **no** |
| `u32 *p = (u32 *)0x80014FF0u; *p = 1; f();` | **no** |
| `u32 v = 1; *(u32 *)0x80014FF0u = v; f();` | **no** |

So the filler has to already have its address in a register. A store whose address is left to the assembler is never
chosen — in *either* split mode, so this is not about the flag M327 found, it is a second, independent rule that
happens to divide the same memories along the same line: `$at`-form stores (literal) do not schedule, register-form
stores (symbol) do. The two properties do not combine.

## 2. The fix, measured — and what it costs

One store only (`D_80014FF0 = 1;` — a single reference, so unlike `D_800128C0` it cannot resurrect `$s0`, and the frame
stays `ra`@24 / `zero`@20). The generated prologue becomes:

```
subu  $sp,$sp,32
lui   $3,%hi(D_80014FF0)      <- hoisted to word 1
li    $2,1
sw    $31,24($sp)
sw    $0,20($sp)
jal   FUN_800072d0
sw    $2,%lo(D_80014FF0)($3)  <- the delay slot, no nop
```

which is the image's *shape* at words 5/6 — `jal` at 5, the store in its slot at 6, the `nop` gone — with the address
one register out (`$3` for `$at`) and, decisively, **the high half hoisted to word 1 instead of sitting at word 4**. At
132 words a single displaced word is charged against every following word:

```
draft-005  (literal store, no sink)   16 of 132 words identical, 140 compiled
draft-006  (symbol store, sinks)       2 of 132 words identical, 140 compiled
```

Under the register-agnostic diagnostic introduced in M327 the same two drafts read **57 vs 5** at offset and **57 vs
52** under a one-word shift — i.e. the sink is *structure-neutral and offset-hostile*, and the offset stick cannot tell
the two apart without knowing that one word moved. **The sink is therefore kept as an experiment, not as the endpoint:
draft-005 stays the reference draft.**

## 3. Gas is not the author of the image's pair — so the pair is capped

The image splits the expansion *around* the call (`lui $at` at 4, `jal` at 5, `sw %lo($at)` at 6). Since `$at` only
appears when the assembler expands a bare operand, the obvious theory was that the original compiler sank a bare store
and **gas** hoisted one word of the expansion. Measured, three ways — a macro store placed in a `jal`'s slot, assembled
with the project's binutils 2.7:

```
  .set noreorder / jal f / sw $2,A / .set reorder      ->  jal ; lui at ; sw     (with -g)
  the same, mips_optimize on (no -g)                   ->  jal ; lui at ; sw
  .set reorder, store written after the jal            ->  jal ; nop ; lui at ; sw
```

Gas puts the expansion **in** the slot, `lui` first, in every case — never `lui` before the call. (The no-`-g` run also
swaps `addu $sp` into the `jr $31` slot, which the image does not do: M281's `-g` conclusion re-confirmed on a second
instruction class.) So the straddle was authored by the **compiler**, and a compiler that writes a symbolic address into
`$at` and defers the store by one instruction is not this one: `FIXED_REGISTERS` marks `$1` fixed, so cc1 never
allocates it — our closest is `$3`, and cc1 hoists it to the top rather than leaving it adjacent to the `jal`.

**Cap, stated plainly**: the prologue's first seven words are now understood to the instruction — value, frame stores,
address, call, slot — and the last of them is a compiler-version difference, not a source shape. Do not spend another
draft on it.

## 4. What is left

In the order the diff shows it: `lui $a0,0x2000` + `or` in a call argument (M326, capped there as an idiom); the dead
`lui` reload the image carries at word 20 (ours re-uses the delay-slot value — one word, and the reason our copy group
starts early); the `ori`-vs-`addiu` base (M322's sign-extension family); the 64-bit ×3's operand copies
(`addu $v0,$zero,$zero` and friends, words 93–100); and the PRId dispatch, which the image writes as a `bnel`-and-`j`
chain and our ternary as a compare tree (words 117–128). The 41-word copy group from M327 is untouched by all of this
and still aligns at 39 words.

## Numbers

- **Word-identical: 16 of 132 (draft-005, the endpoint) and 2 of 132 (draft-006, the sink)**; both 140 compiled, image 132
- Register-agnostic diagnostic (off-tool, computed for the note): 57 vs 5 at offset, 57 vs 52 under a one-word shift
- `vi-draft-006.c` kept beside 003/004/005 in `build/probe/`
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
