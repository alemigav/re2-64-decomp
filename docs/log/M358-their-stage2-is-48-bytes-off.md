# M358 — their stage2 is 48 bytes off: scoring by content, and 38 functions that were never "outside our images"

M356's honest limit was that **688 of the other corpus's functions sit at addresses outside our images**, so they could
not be scored at all. That number was a statement about **addresses**, not about code — and the addresses turn out to be
wrong in a way that is measurable and correctable.

> `tools/other_corpus.py --align` compiles a draft with this project's profile and then **looks for the body anywhere in
> the cartridge**. Where a found body lands on one of *our* function boundaries at *our* size, the address stops being a
> guess. That turned 688 unscoreable functions into a mapping, and the mapping turned into **38 new byte-exact
> reconstructions** in stage2 and **139 more queued** in the overlays.

## 1. The measurement: three offsets, one of them a segment shift

Searching every image for each compiled body gives a distribution of `delta = our address − their address`:

| where | dominant delta | functions agreeing |
| --- | --- | --- |
| `boot` | **0** | 23 |
| `stage2` | **−48** | 36 |
| overlays | **+128** | 4 per member, consistently across 9 members |
| overlays, second slot | **−51 984** = −(0xcb90 − 0x80) | 4 per member |

`boot` agreeing at zero is the control: we already knew those addresses match. `stage2` at −48 is the finding, and it is
**not** a boundary disagreement — a candidate that matches at *no* delta suddenly matches at −48:

```
func_80033190_ovl_01   22w   delta   0: absent      −48: stage2@80033160
func_80032B8C_ovl_01   31w   delta   0: absent      −48: stage2@80032b5c
func_8002A528_ovl_01   28w   delta   0: absent      −48: stage2@8002a4f8
```

And the shift is **in the symbols too**: their `D_`/`func_` names encode their own vram, so a draft that references one
compiles to a `lui`/`addiu` pair 48 bytes off until the `--defsym` values are shifted with the address. With only the
address corrected, those three stay absent; with both corrected, they land. The overlay numbers are the two enemy-slot
bases our own image table already knows: `+0x80` is the offset between their member base and our shared slot base, and
`−0xcb90 + 0x80` is the same member in the second slot — the stride v64recomp's profile also models.

**What this means for M356's numbers**: the "688 outside our images" was never 688 functions we cannot reach. It was 688
addresses that needed a per-segment affine correction, and 829 of 1 416 candidate drafts land a body somewhere in the
cartridge once the correction is applied.

## 2. What was banked, and the rule that decided it

A content match alone is not a registration: a body can appear at several addresses, and the duplicate census of M335 is
entirely made of bodies that appear twice. So the rule was three conditions, all checkable:

1. the found body's length equals a function **in our own index** at that address — the boundary is ours, not theirs;
2. the compile is then redone at **our** address with **our** symbol addresses (their map shifted by the segment delta),
   so the immediates in the comparison are the ones our image holds;
3. `compile_probe.py --check` re-derives it, which is the only thing that makes it a claim.

**38 functions, 838 words**, all in stage2 — from 8 words to **90** — and the probe went **152 → 190 of 190**. The
largest are `0x800411b8` 90 words, `0x80028780` 80, `0x800351e8` 55, `0x8002aee0` 49, `0x800ab1a0` 43.

The ladder moved with them for the first time since M354: **F1 3 421 → 3 423, F2 3 353 → 3 355**, and
`extent_measured` **182 → 180** — two of the 38 were on the measured rung and graduated, which is the same movement
M354 recorded for the ten empty functions.

## 3. What is queued, and why it is not in this milestone

**139 overlay functions, 4 176 words** — 78 % of the total yield — are verified by content and mapped by offset, and
they are **not** registered. The reason is mechanical rather than cautious: they live in 27 different overlay members,
and putting 139 C sources into `tools/compile_probe.py` as constants would grow that file by roughly four thousand lines
for a corpus that is *imported* rather than reasoned about. The right shape is a **file-based source channel** —
`fixtures/decomp/imported/<image>/<address>.c` read by `recovered.py`, with `compile_probe.py` loading them into its
source namespace at import — so that one reader still answers "where does this function's C live", which is the M289
invariant. That channel is the first task of the next milestone, and the 139 are its payload.

## 4. The limits, stated

- **A content match is not an address.** The rule above is what converts one into the other, and it is why the 38 are
  registered against *our* boundary with *our* symbols rather than against theirs. A body found at an address that our
  index does not call a function start is **not** banked — 45 found bodies were dropped on exactly that condition.
- **The −48 is their layout, not a claim about the cartridge.** Our stage2 base is the cart table's `0x80018a80` and
  our 182 exact functions vouch for it; theirs is 48 bytes higher, and nothing here depends on which of us is "right".
- **The offsets were measured, not assumed.** `boot` at 0 is the control that says the method can return zero; the
  overlay pair (`+0x80`, `−0xcb90 + 0x80`) is what the slot geometry predicts, independently of the search.
- **The corpus's own verdicts remain untrusted.** These 38 are claims because *our* gate reproduces them, and for no
  other reason — the same rule M356 applied to its 15.

## Numbers

- **+38 functions**, 838 words, all stage2, all content-aligned then verified at our own address; probe **152 → 190/190**
- recovered **183 → 221**, byte-exact **182 → 220**; composition **16 hand + 55 singles + 97 copies + 53 imported**
- ladder **F1 3 421 → 3 423**, **F2 3 353 → 3 355**; rung `extent_measured` **182 → 180**
- tree **1 198 → 1 236 cases** (323 runnable, 913 gated); `unclassified` **440 B (0.0 %)**, coverage **63.2 %**
- **queued**: 139 overlay functions / 4 176 words, behind the file-based source channel
- `verify.py --full` **PASS**, audit 160/160
