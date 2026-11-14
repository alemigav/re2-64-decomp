# M416 — the mechanism grammar as passes: 1 of 477 mid-band bodies

The mid band was the last untested population with a plausible mechanism story: 477 unclaimed bodies whose provider draft
matches 25–89 % of the image's words. Eight mechanisms closed bodies by hand across M378–M408, so the question was what
they close when applied as passes. The answer is one body, and the reason is the finding.

## What ran, and what it closed

| pass | mechanism | bodies tried | **closed** | score improved |
| --- | --- | --- | --- | --- |
| `order:adjacent` | swap two adjacent simple assignments to distinct names (M401's statement order, cheapest form) | 477 | **1** | 22 |
| `sig:param` | re-type one parameter, or drop its pointer (Ghidra's inferred signature) | 476 | **0** | 0 |
| | | | **1 of 477 (0.2 %)** | 22 |

`tools/mechanism_pass.py` runs each pass as a **named** pass over the band, scores every variant through the gate's own
compile-link-compare, keeps the best draft per body, and writes the count per pass into
`fixtures/mechanism_passes.json`. A mechanism that closes nothing is recorded as a **measured zero**, not as an untested
claim.

## Why only two passes exist, and that is the real result

Eight mechanisms are in the log. **Six cannot be expressed as a text transformation at all**, and the tool records the
reason for each rather than leaving them as a TODO:

| mechanism | expressible as a pass? |
| --- | --- |
| statement order | **yes** — this is `order:adjacent` |
| parameter/signature retyping | **yes** — this is `sig:param` |
| the arithmetic domain (`u32 base + off` so a constant stays in a register) | no — changes the type of an expression tree |
| a named pointer for the displacement | no — introduces a binding that changes CSE |
| the rematerialisation block | no — introduces a nested scope |
| walk-vs-index | no — changes an induction variable |
| guard clause vs one conjunction | no — changes control-flow shape |
| compare-the-copy vs compare-the-argument | no — changes which value is live |

So the mechanism grammar is **not** a search space that a harness can enumerate. The two members that are textually
expressible close 1 body in 477; the other six are exactly the ones that closed bodies by hand, because each of them is a
*decision about the whole function* made by reading the image.

## The 22 improvements are the useful residue

Twenty-two bodies moved *without* closing — the order swap made their draft closer. That is a real signal: a body that a
pass improves by one word is a body whose remaining residue is *ordered*, and it is the population a portfolio of passes
should iterate on rather than discard. It is recorded in the fixture for the next milestone to start from.

## Where every lever now stands

| population | size | best mechanical result |
| --- | --- | --- |
| near band (≤8 words) | 251 | **30 closed (12 %)** — types, signedness, portfolio |
| **mid band (25–89 %)** | **477** | **1 closed (0.2 %)** — this milestone |
| far mass (<25 %) | 1 966 | 0 — translation fixes and a decompiler swap both refuted (M412, M414) |
| refused | 311 | unmeasured |
| no C | 196 | needs authoring |

595 → **596 of 3 664 (16.3 %)**.

**No bulk instrument remains untested.** Every population has now been probed with every mechanism that can be applied
without reading a function: the total is 596, and 31 of the last 322 came from passes. The rest is one function at a
time — which is what the project did at ~5 per milestone before M409, and what 40 % requires about 870 of.
