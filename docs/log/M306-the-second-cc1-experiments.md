# M306 — the second `cc1`: the fill cannot move ahead of `global_alloc`, and two variants that do not move the register

The instruction was to build a second `cc1` with the delay-slot fill moved ahead of `global_alloc`, and measure it
over the whole probe. The first half turned out to be **impossible for a reason in gcc's design**, so the second
half became two feasible variants instead. Both are negative, and the reason is measured rather than assumed.

## 1. Why the fill cannot move

`dbr_schedule` (reorg.c) reads **`reg_renumber`** — the pseudo→hard-register map — at `reorg.c:2784`. That map is
created by `global_alloc` and consumed by `reload`; `reload_completed = 1` is set immediately after. The pass order
in `rest_of_compilation` is

```
expand → jump → cse → loop → cse2 → flow → combine → sched → local_alloc → global_alloc → [reload]
       → peephole → sched2 → jump2 → dbr → shorten_branches
```

so at any point before `global_alloc` the pseudos are unnumbered and `dbr_schedule` has nothing to fill slots with
respect to. Moving it earlier is not a reordering, it is a rewrite: the pass would have to reason about virtual
registers, which is precisely why gcc runs it last. **This is the answer to "build it": it cannot be built as
specified**, and no amount of patching changes that without inventing a new pass.

## 2. Where the hoist actually comes from

The dump chain settles it, and it is neither `dbr` nor cross-jumping:

- **`f.c.rtl` (before any optimisation)** already has the order we want — `jne 231,232 → 541` first, and the
  constant `229 = 5` **in the `541` block**, i.e. after the branch. Nothing is wrong at expand time.
- **`f.c.jump`** — the *first* `jump_optimize` call, the one whose `cross_jump` argument is already `0` — has the
  assignment moved **above the compare** as a new insn 642.

So an if-then-else normalisation inside `jump_optimize_1` does it. That is the transformation to gate, and it is not
the cross-jumping code.

## 3. The two variants that were built

Both are separate `cc1` binaries built in `build/toolchain/src/gcc28-build`; the installed compiler was rebuilt from
unpatched sources afterwards (below).

| variant | change | `0x8007e590` |
|---|---|---|
| **cross-jumping off** | `toplev.c:3548`, `jump_optimize (insns, 1, 1, 0)` → `(insns, 0, 1, 0)` — the only call with `cross_jump = 1` | **44 / 229** |
| **constant hoist gated** | `jump.c`, the if-then-else path that explicitly permits `GET_CODE (SET_SRC (temp4)) == CONST_INT`: added `&& GET_CODE (SET_SRC (temp4)) != CONST_INT` | **226 / 229, unchanged** — still `a0` |

Two things learned, both worth the build time:

1. **Cross-jumping is load-bearing for this function.** Turning it off does not just fail to fix the residue, it
   deletes 182 of the 226 matching words: the shared tails it merges *are* most of `0x8007e590`. Any patch that
   touches it is dead on arrival.
2. **The site I gated is not the hoist.** `jump.c` has five places that move an insn across a branch
   (`emit_insn_after_with_line_notes` at lines ~844, 945, 1004, 1052, 1113); the one whose condition mentions
   `CONST_INT` is not the one that fires here. Finding the right one needs **instrumentation, not inference**: a
   guard per site, five rebuilds, ~6 minutes each.

## 4. The toolchain is restored and verified

Both experiments left the installed compiler rebuilt from unpatched sources (`toplev.c` and `jump.c` byte-identical
to their originals), and the check that matters was run rather than assumed: **55/55 compile-probe cases pass**, so
all 16 recovered functions still match the cartridge byte for byte. The variant binaries were never installed.

## 5. What this means for the residue

`0x8007e590` stays **226 of 229**. The remaining work is now scoped exactly:

- the *obstacle* is a pre-allocation live range created by `jump_optimize_1`'s if-then-else normalisation;
- the *fix* is to stop that normalisation hoisting a **constant assignment** above the branch (it must keep doing so
  for everything else — cross-jumping proves the pass is holding the function together);
- the *next step* is to locate the firing site with a per-site guard, which is mechanical and cheap, and then to
  re-validate the whole probe, since a carried patch must not disturb 16 byte-exact functions for 3 words.

That is a real plan with a real cost, and it is now the only route left. The three failing attempts are recorded
here so the next session does not re-run them.

## Numbers

- no case added, removed or re-aimed: **55/55** cases still pass, tree unchanged at **73 suites / 1 030 cases**
- two `cc1` variants built and measured; both discarded; the installed compiler verified equivalent by the probe
