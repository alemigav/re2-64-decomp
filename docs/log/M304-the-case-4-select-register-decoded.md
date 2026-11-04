# M304 — the case-4 select register, decoded: 32 spellings that change nothing

> **Corrected by M305.** This note called the delayed `li` a *dead store* and the choice a *tie-break*. Both are
> wrong: the branch's immediate is `2`, so it targets the `sb` at `0x8007e8b4` and the `li` is the **taken path's
> value** — a genuine branch-over select — and the two ranges genuinely overlap, so it is a **conflict**, not a
> tie-break. The decode of the three words, the `-da` evidence and the 32-spelling negative all stand.

The ask was to go back to `0x8007e590`'s last three words — M293–M295 converged on "case 4's select register is a
`global_alloc` conflict" without ever decoding the three words. Decoding them turned the description into a
measurement, and the measurement closed the question: **the register is not reachable from source shape.**

## 1. What the three words actually are

`0x8007e590` is 226 of 229. The differing words are `199, 200, 201`:

| word | address | image | ours | meaning |
|---|---|---|---|---|
| 199 | `0x8007e8ac` | `24020005` | `24040005` | `li` **$2**, 5 |
| 200 | `0x8007e8b0` | `24020004` | `24040004` | `li` **$2**, 4 |
| 201 | `0x8007e8b4` | `a2020005` | `a2040005` | `sb` **$2**, 5(`s0`) |

Same opcodes, same immediates, same base register — **only the destination register differs** (`$2` = `v0` against
`$4` = `a0`), and it differs consistently across all three. Not a scheduling difference, not an omitted
instruction: one allocator choice.

**The first of the three is the taken path's value, not dead code** *(corrected in M305: the branch's immediate is
`2`, so it targets the `sb` at `0x8007e8b4`; the earlier reading of `34` as the offset was objdump's displayed
target, not the immediate)*. The sequence is a branch-over select: `li R,5` in the delay slot, `bne` → the `sb`
when the test fails, `li R,4` and the same `sb` when it passes.

## 2. Why it is a *global* choice

`cc1 -da` makes the mechanism explicit. In `f.c.lreg`:

```
block 34:  insn 642  (set (reg:QI 229) (const_int 5))        <- the dead one, hoisted above the compare
           insn 533  (set (reg:SI 231) (zero_extend (mem (plus reg 80) 5)))
           insn 535  (set (reg:SI 232) (const_int 22))
           insn 536  jump  (ne 231 232) -> 541               REG_DEAD 231, 232
block 35:  insn 538  (set (reg:QI 229) (const_int 4))
block 36:  label 541 ...  insn 546  (set (mem (plus reg 80 5)) (reg:QI 229))
```

Pseudo **229** is written in block 34 and read in block 36, so its live range spans the branch — it is a *global*
allocno, and its register is chosen by `global_alloc` over the whole function, not by anything local to the case.
The compare's constant is pseudo 232, which dies at the branch; the image's build reuses that dying register
(`$2`) for 229, ours takes the next free one (`$4`).

## 3. The search, and why it ends here

Three independent attacks, all measured:

| attack | scope | result |
|---|---|---|
| **spelling of the select** | 32 variants: temporaries (`u8`/`u32`/`s32`/`register`), pre-materialised `5`, if/else instead of the ternary, inverted operators, cast forms, `0x16`, swapped compare operands, parenthesised arms | **byte-identical `.text` for 25 of them** (`insn` numbers identical — the allocator does not see the difference); the rest change the *shape* and lose 1 to 38 words |
| **pseudo numbering** | drop the `dev` local, hoist a `w` temporary, declare `dev` at function scope | 226 (no change), 226, or **178** — removing the local makes gcc recompute the condition's pointer twice, which costs 48 words |
| **the permuter, image objective** | 30 922 iterations, 8 threads, 22 353 compile errors | **zero better-score events, zero candidate directories** — randomisation never found anything the scorer preferred |

So the residue is not a wording problem and not a randomisation problem. **It is a conflict inside `global_alloc`** *(not a tie-break — corrected in M305)*, which the C source cannot address: the ordering is fixed by pseudo numbers,
and every perturbation that changes pseudo numbering enough to matter also changes the emitted code.

## 4. What *would* move it (stated as open, with the tests)

1. **A different `global_alloc` ordering** — i.e. a compiler patch. The project already patches `cc1` (two
   constant-pool patches, M291/M292), so this is in-house work: make `global_alloc` prefer a dying operand's
   register for an allocno whose write is hoisted above the compare. That is a real change to a real compiler and
   would need to be shown not to disturb the 15 byte-exact functions.
2. **A corpus-wide scan for the preference**: does the real build *systematically* prefer `$2` for a hoisted
   select, or is this one function's accident? If it is systematic, a patch is justified; if not, 226/229 is the
   honest end state for this function. This is the cheap next measurement — one pass over the 3 416 bodies looking
   for the `li $2,X / li $2,Y / sb $2` shape.

Until one of those lands, `0x8007e590` stays **recovered, 226 of 229**, published as such.

## Numbers

- compile probe **51 → 53 cases** (53/53 pass): one decodes the three words and asserts *same opcode, same
  immediates, same base, different destination*, one asserts that three alternative spellings compile
  byte-identically
- `src/stage2/FUN_8007e590.c` unchanged — it is still the 226-word reconstruction, and it stays that way
- tree: **73 suites / 1 028 cases** (742 need the cartridge), 100 tools, 3 416 functions, 1 211 256 B — unchanged
