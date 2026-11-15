# M454 — the accumulator-class experiment: 18 more variants, no lever; and one of the two is not accumulator-class

The last two open gap-1 bodies were carried as accumulator-class residuals. Run them under every flag that could
plausibly change which register gcc chooses — **18 variants, unmodified drafts, no edits** — and the class moves by
nothing.

## The sweep

| variant | `ovl_00a0344` (29) | `ovl_009dd02` (47) | control kept |
| --- | --- | --- | --- |
| **baseline** | **28** | **46** | 5 of 8 |
| `-fomit-frame-pointer`, `-O3`, `-mips3`, `-fno-strength-reduce`, `-fno-inline`, `-fcaller-saves`, `-fno-caller-saves`, `-fno-peephole`, `-fno-cse-follow-jumps`, `-fno-thread-jumps` | 28 | 46 | 5 of 8 (4 for two of them) |
| `-G 8` | 28 | 46 | 4 of 8 |
| `-fno-expensive-optimizations` | 28 | 46 | 4 of 8 |
| `-fno-schedule-insns` | 28 | **43** | 4 of 8 |
| `-fno-schedule-insns2` | **19** | 43 | 4 of 8 |
| `-O1` | 19 | **31** | 4 of 8 |
| `-fno-delayed-branch` | 24 | 36 | **0 of 8** |
| `-fno-omit-frame-pointer` | 21 | 39 | **0 of 8** |
| `-fregmove` / `-fno-regmove` | refused | refused | 0 of 8 |

**Eleven variants are byte-identical to the baseline** on both bodies — including `-fcaller-saves` and `-fno-regmove`'s
nearest usable relatives — and the seven that change anything make it worse. Nothing closes. The two register-movement
flags this compiler does not have (`-fregmove`, `-fno-regmove`) are refused outright, so the most obvious lever for an
accumulator choice is not available at all.

## What the two residuals actually are — and a correction

**`ovl_00a0344:0x80162224`** (29 words, **28** aligned): the `+1` lands on a different value. The image computes
`addiu v0,v0,1` at position 13; we compute `addiu v1,v1,1` at position 20. That is the accumulator/order class, as
described.

**`ovl_009dd02:0x80166408`** (47 words, **46**): one word, `slti v0,v1,2` against our `sltiu v0,v1,2` — the
**signedness of a comparison**, which is what M441 found and refused. **This is not accumulator-class**, and my previous
summary lumped it in; the correction is recorded here.

So of the three non-toolchain gap-1 bodies, **one is accumulator/order** (`ovl_00a0344`), **one is signedness**
(`ovl_009dd02`), and **one is the mutually-exclusive pair** of M453 (`stage2:0x80047824`, 11 of 12).

## The cumulative ledger

Flag variants measured across this session, and closures produced:

| experiment | population | variants | closures |
| --- | --- | --- | --- |
| M440 | 120 allocation-class + 120 controls | 11 | **0** |
| M452 | 7 prologue-save-order bodies | 17 | **0** |
| **M454** | 2 accumulator/signedness bodies | **18** | **0** |
| **total** | | **46** | **0** |

Forty-six flag variants, three populations, no body closed by a flag. The profile is not merely "a good guess": it is
the only configuration that survives its own control, and every alternative either does nothing or damages the corpus.

## What the near band now is

The 14 open gap-1 bodies are **fully accounted for**:

- **11 toolchain family** — prologue save order 7, unexpanded `#nop` 2, scheduler 1, deferred constant 1 — each with a
  measured cause and no lever inside the pinned pair;
- **3 one-word source residuals** — accumulator/order, signedness, and the mutually-exclusive pair — each measured
  under every flag, none movable.

That is a complete account of the near band, and it says the near band is **done**: not because it was closed, but
because every body in it has a named cause and none of them is reachable.

## Numbers

- **18 flag variants** × 2 bodies + 8 controls; **0 closures**; 11 variants byte-identical to baseline, 7 worse
- `-fregmove` and `-fno-regmove` **refused** by this cc1 — the register-movement lever does not exist here
- two controls destroyed (`-fno-delayed-branch`, `-fno-omit-frame-pointer`: 0 of 8)
- cumulative **46 variants / 0 closures**; `recovered` stays **674**, byte-exact **673**; no edits, nothing banked
