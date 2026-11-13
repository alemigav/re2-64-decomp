# M414 — m2c on the far mass: 1 of 50, and no better than Ghidra

The far mass is the only population with reach for 40 %: **1 966 bodies below 25 % word match**, which no structural
variation of the existing translation moved (M412: 20 bodies × 6 variants, median gain **0 words**). The one untried
instrument was a different decompiler. This is the experiment, and it is a refutation.

## What was run

`m2c` (`github.com/matt-kempster/m2c`, cloned at `/tmp` — **not added to the repo**, the zero-dependency rule stands and
its only dependency, `pycparser`, lives in a throwaway venv), driven per body:

1. the function's own words, disassembled from the image bytes with `objdump -D -b binary -m mips:isa32 -EB
   --adjust-vma=<base>` and rewritten into m2c's `glabel`/`/* off vaddr word */` format with **labels** at every branch
   target (m2c refuses hex targets);
2. `m2c --valid-syntax --comment-style none --globals none -t <target>`, with **both** `mips-gcc-c` and `mips-ido-c`
   tried and the better kept — the corpus is gcc 2.8.1, so the gcc target is the fair one;
3. its `M2C_FIELD(expr, type_ptr, offset)` expanded **by argument splitting, not by regex**: a regex moved the type out
   of the cast on any call-valued base, which produced invalid C whose compile failure then scored as "0 of 14" — a
   harness bug that made the first run's numbers meaningless (13 of 50 "worse" were compile failures);
4. compiled, linked at the cartridge address and compared word for word by the same `pins()` path the gate uses.

Sample: 50 unclaimed bodies in the far band, 13–60 words, chosen smallest-first.

## The result

| | |
| --- | --- |
| m2c produced **compilable** C | **19 of 50** |
| **closed to byte-exact** | **1** |
| better than Ghidra | 5 |
| worse than Ghidra | 3 |
| median score, m2c | **1 of ~14 words** |
| median score, Ghidra | **1** |

A 5–6 word body illustrates the shape of the gap: m2c reconstructs `func_8004cd54` as an indexed store with a computed
base (`*(s32 *)((u8 *)(temp_v0 + 0x8010B328) + 0x1B8) = arg1;`) where the image builds the same address differently, and
lands at a handful of words.

## What it refutes, and what it does not

**Refuted:** that swapping decompilers unlocks the far mass. m2c is not closer than Ghidra on average (median 1 word
either way), it closes 2 % of the sample, and its C compiles under this `cc1` less than half the time — the corpus'
pinned profile is gcc 2.8.1 and m2c's dialect needs both the macro expansion above and a `--context` type environment
that does not exist for 1 966 bodies.

**Not refuted:** that m2c is a useful *second opinion* per body in the near and mid bands, where a draft already exists
and the residue is one or two words. Its answers differ from Ghidra's often enough (5 better, 3 worse on 50) that it
belongs in a portfolio for a body already within reach — not as a bulk generator.

## So the arithmetic for 40 % stands where M412 left it

| lever | reach |
| --- | --- |
| the 249-body band residual | mechanism per body, ~5 per milestone |
| the 333-body mid band (25–89 % match) | the same instrument, same rate |
| the 1 966-body far mass | **requires reconstruction**: no translation fix (M412) and no decompiler swap (here) reaches it |

40 % is 1 466 bodies. Two instruments with bulk reach have now been tested and both are refuted. What remains is the
work itself — or a change of goal, which is a decision and not a measurement.
