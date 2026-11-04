# M310 — the copy that forces the annul: `u16` truncation, proven by removing it

M309 cleared reorg and pointed upstream: reorg's input already has the compare reading a **copy** of the masked
value, so the delay-slot filler has no candidate and annuls. This isolates that copy — where it comes from, and
what happens when it is removed.

## 1. Where the copy comes from

The pre-allocation RTL (`.sched`, before `local_alloc`) shows **two pseudos** where the image has one register:

```
insn 50:  (reg:SI 103) = (reg:SI 101) & 4095            ← the mask
insn 55:  (reg/v:HI 104) = (subreg:HI (reg:SI 103))     ← movhi_internal2: the u16 truncation
insn 58:  (reg:SI 106) = (leu:SI (subreg:SI (reg/v:HI 104)) 2048)   ← the compare reads 104
block 1:
insn 62:  (subreg:SI (reg/v:HI 104) 0) = (reg:SI 103) | 61440      ← the or reads 103
```

`u16 d = …` makes `d` a **HI variable**, so the SI mask result (103) is truncated into a second pseudo (104) by a
`movhi_internal2`, and the comparison — written against `d` — reads **104**. The OR still reads 103. Two live
pseudos with overlapping ranges cannot be coalesced, so the copy is real, and it is *before* the compare.

The image's build has the same three instructions with the operands the other way round: `andi a0` (the mask),
`slti v0,a0` (compare on the **mask**), `ori v1,a0` (the OR on the mask, into the result register). One register
for the value, and the copy that remains is the *result* copy — which is exactly the instruction the delay slot
can take.

**So the annul is forced by a type, not by the scheduler.** That is the whole chain: `u16` → truncation copy →
compare on the copy → no legal delay-slot candidate → `beql`.

## 2. Proving it by removing the truncation

If the copy is the cause, removing it should move the compare back onto `a0` — and it does:

| `d`'s type | clamp shape | words | what changes |
|---|---|---|---|
| `u16` | `r = tern`, return `(s16)r` | **22/25** | compare reads `v1` (the copy) |
| **`s32`** | **direct return** | **20/25** | compare reads **`a0`** — the truncation copy is gone, and word 15 becomes `slti v1,a0` against the image's `slti v0,a0` |
| `s32` | `r = tern` / `if` / `variants` | 14/25 | the select re-allocates and loses the branch shape |
| `u32` | `r = tern` | 14/25 | same |

Six type×shape combinations measured. Removing the truncation **does** fix the operand — and immediately exposes
the *next* choice: with `s32`, the allocator hands the compare's result to `v1` and the select's result to `a0`,
the exact mirror of the image's `v0`/`v1`. The residue changes from "wrong operand" to "swapped result registers",
which is 5 words instead of 3.

## 3. What this settles and what it does not

**Settled:** the 25-word group's 22/25 has a single root cause — a `u16` truncation copy placed before the
compare — and it is *not* fixable by the clamp's wording, which was already swept (twelve shapes in M308). It is
also not reorg's fault, which M309 established by trace.

**Not settled:** the register tie-break that remains. Both instances — the copy's home in the `u16` case and the
swapped result registers in the `s32` case — are `local_alloc`/`global_alloc` choices. The tool for that is the
one M309 named and this milestone did **not** build: a `REG_TRACE` in `global.c` logging, per allocno, the
candidates it considered, the conflicts that removed them and the preference that won. That is the next
experiment, and it is the same instrument-the-pass shape that worked here.

**Neither** function moves: `0x8007e590` stays **226/229**, the 25-word group stays **unregistered at 22/25**, both
published as such. Three residues now share one diagnosis — `0x8007e590`'s interference (M304), `osCreateThread`'s
parameter scheduling (M303) and this truncation copy — and the shared name is *allocation*, not C.

## Numbers

- no case added or re-aimed: probe **63/63**, recovered **75 / 74 exact**, tree **73 suites / 1 038 cases**
- 6 type×shape combinations measured on the 25-word group; the group stays at 22/25, its best
