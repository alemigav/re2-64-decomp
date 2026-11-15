# M447 — the full re-rank: 72 bodies are genuinely within two words, not 19

The map's near band was built on **positional** identity, which one inserted instruction destroys. M446 found that
across the short bodies; this re-ranks **every open scored body** by **alignment**, so the count is of what is actually
absent rather than of what happens to sit at the same index.

Both word lists are truncated to the extent first — the linker pads `.text`, so an over-long compile is not an
over-long *function* — and then aligned with `difflib.SequenceMatcher`. `gap_aligned = words − matched`; a body is exact
only when that is 0.

## The distribution

**2 477 open scored bodies, 0 refused, 139 708 words genuinely absent.**

| aligned gap | bodies | |
| --- | --- | --- |
| 0 — exact | **0** | the control: no open body is secretly already done |
| **1** | **19** | one instruction |
| **2** | **53** | |
| 3–4 | 83 | |
| 5–8 | 234 | |
| 9–16 | 372 | |
| **> 16** | **1 716 (69 %)** | |

| within | aligned | the map's positional count |
| --- | --- | --- |
| 2 words | **72** | 19 |
| 4 words | **155** | 88 |
| 8 words | 389 | 285 |

So: **72 bodies are genuinely within two words** — 3.8× the map's number — and **155 within four**. And the honest scale
is unchanged at the far end: **69 % of the open corpus is more than sixteen words away**, so this is a re-ranking of a
thin near band, not the discovery of a large one.

## What the near bodies actually are

All **19** gap-1 bodies are a **single changed instruction**, not an omission. Three of the 72 within two words are
missing-word cases; the other 69 are substitutions.

Six of the nineteen were ranked by the map as hopeless and are one word from exact:

| body | words | map said |
| --- | --- | --- |
| `stage2:0x8008456c` | 4 | 0 / 4 |
| `ovl_0090698:0x80165e40` | 34 | 5 / 34 |
| `ovl_0090698:0x801661b8` | 36 | 5 / 36 |
| `stage2:0x80073f28` | 15 | 8 / 15 |
| `stage2:0x80033024` | 22 | 12 / 22 |
| `ovl_00a0344:0x80162224` | 29 | 21 / 29 |

`ovl_009dd02:0x80166408` (47 words) is in the list at **46 of 47** — the `slti`/`sltiu` body M441 refused, and
`ovl_00b321e:0x8016552c` at 56 of 59 is one of the loop-class bodies. So the near band is not new work; it is the work
M441 measured as having **no shared lever** — every one of these needs its own single-instruction fix.

## The number, stated plainly

- **72 bodies within two aligned words**, 155 within four, 389 within eight — against 19, 88 and 285 positional.
- **1 716 of 2 477 (69 %) are more than sixteen words away**, and those are the bodies the open corpus is mostly made
  of.
- The near band is nearly 4× larger than believed and still mostly needs **body-specific** work, which is consistent
  with M441 rather than in tension with it.

## Numbers

- **2 477** open scored bodies re-ranked, **0 refused**, **139 708** words genuinely absent
- aligned gap: **19** at 1, **53** at 2, 83 at 3–4, 234 at 5–8, 372 at 9–16, **1 716** beyond
- within 2/4/8 words: **72 / 155 / 389** aligned against **19 / 88 / 285** positional
- 19 gap-1 bodies, all single-instruction **replacements**; 3 of the 72 within two words are omissions
- new fixture `fixtures/decomp/aligned_gaps.json`; nothing banked
