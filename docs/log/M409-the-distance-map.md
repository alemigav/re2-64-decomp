# M409 — the distance map: 3 194 bodies had never been scored, and 188 of them already match

The project published "**273 of 3 664 byte-exact — 7.4 %**" while holding **3 194 bodies of the decompiler's own C that
had never been compared to the cartridge at all**. Not "scored badly" — never compared:

| population | count | ever scored against the image? |
| --- | --- | --- |
| our own reconstructions | 273 | yes — `build_corpus.py --check`, `compile_probe.py` |
| **the provider's C in `src/`** | **3 194** | **never** |
| measured extent only, no C | 196 | impossible — there is no C |

Every target since M388 was chosen by feel or from retracted prose. `tools/distance_map.py` now measures the population:
compile each body with the pinned profile, link it at its cartridge address, count identical words.

## The result, and it is not what the metric implied

| | bodies | words |
| --- | --- | --- |
| **already byte-exact** | **439** | — |
| … of which the project already claimed | 251 | — |
| … **already byte-exact and never claimed** | **188** | **4 791** |
| within 1 word | 70 | |
| within 2 | 50 | |
| within 4 | 55 | |
| within 8 | 78 | |
| over half but not within 8 | 89 | |
| under half | 1 993 | |
| **refused (not measured)** | **699** | |

Measured: 2 774 of 3 473 bodies with C (**80 %**), 28 885 of 298 724 words identical (9.67 %).

**The headline is the 188.** They are byte-exact *today*, from the decompiler's C, with no reconstruction by anyone —
including a **166-word** overlay body, a 133-word one and three at 100 words. 14 are over 64 words, 89 are 17–64, 85 are
16 or fewer. Most are in the overlays, which is where nobody had looked.

Cross-checked against the project's *independent* scorer (`leaf_screen --try`, a different link-and-compare path) on eight
bodies including the three largest: **166/166, 133/133, 100/100, 37/37, 29/29, 16/16, 9/9, 7/7 — all agree.**

So recompiling what the decompiler already produced would take the published figure from **273 to 461 without writing a
line of C** — the work is *verification and pinning*, not drafting.

## What the 20 % refusal costs, and why it is reported rather than hidden

699 bodies are refused, and a refusal is never counted as a zero — a body that will not compile is not a body that
scores 0 of N. The causes, each found by diving into a failure and each a dialect problem rather than a code problem:

| cause | bodies | the fix |
| --- | --- | --- |
| `_DAT_…` names (leading underscore) not recognised, so no `extern` | 86 | allow the underscore in the symbol pattern |
| `Status`/`WatchLo` used as bare COP0 register names | 40 | a COP0 enum in the preamble (macros in the original) |
| the body declares the symbol itself → `conflicting types` | 33 | skip symbols the body already declares |
| `setCopReg`/`trap`/`halt_baddata` unresolved, or placed outside `jal`'s 26-bit region | 35 | place them in the same `0x8…` region |
| `#define` in the preamble (this `cc1` has **no preprocessor**) | 139 | an enum, not a macro — M356's measurement, relearned |
| `cc1` segfaults on some bodies | 8 | refused, and named as such |

The last row of that table is the milestone's own M356 lesson applied to itself: the first version of this tool used
`#define true 1` and lost **139 of 218** boot bodies to a preprocessor that does not exist.

## What changes

1. **The plan for M410 is now different, and cheaper.** It is not "repair the 20 cheapest near-misses"; it is **verify
   and bank 188 bodies that already compile byte-exact**, each needing a probe pin and an entry in
   `fixtures/decomp/recovered.json`. The repair queue (253 within eight words) comes after.
2. **The front page carries the line**, derived by `counts.py` from the fixture, never typed: *"439 bodies already
   compile byte-exact, 188 of them nobody had noticed, and 253 more are within eight words."*
3. **The denominator is honest from here.** `--check` re-derives the published totals and the overlap from the committed
   records and re-measures a 24-body sample in **1.3 s**; the full `--write` is an author operation (~15 s at 8 jobs),
   not a gate, because a gate that recompiles 3 473 bodies cannot fit the 30-second rule.

## Two caveats the fixture states itself

- **23 claimed bodies are not exact in this measurement**, and that is not a contradiction: those reconstructions live in
  `tools/compile_probe.py` as constants (`P6_SOURCE`, …), so the file in `src/` for those addresses still holds the
  provider's version, which is what this tool measures.
- **A body measured with the `array` declaration rung** (`declaration rung` in the record) was one the faithful scalar
  declaration could not express. It is measured with the declaration Ghidra meant, never with a fudged type: a type
  chosen to make a subscript compile would generate different code and therefore a *wrong distance*.

`distance_map.py --self-test` carries the control that matters: the same body measured against **another** function's
window must not be exact, and an empty translation unit (a `src/` listing, whose words all live in a comment) must be
refused rather than scored `0 of 38` — both caught real defects in this tool before it produced a number.
