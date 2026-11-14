# M420 — `dat:width`: 41 bodies, and the instrument's own default was the defect

The drafting program's second batch built three mechanisms from the queue and measured each over both bands. One of
them is worth more than everything the last four milestones found, and it was a defect in my own harness.

## The pass results

| pass | near band (240) | mid band (468) |
| --- | --- | --- |
| **`dat:width`** — vary a data symbol's declared width | **40 closed**, 64 improved | **1 closed**, 64 improved |
| `symbol:addr` — an address as a value becomes a symbol reference | 0 closed | 0 closed |
| `sig:forward` — declare the parameters the callee reads, forward them | 0 closed | 0 closed |
| `order:adjacent` | 0 closed, 1 improved | 0 closed, 19 improved |
| `guard`, `sig` | 0 | 0 |

**600 → 641 of 3 664 (17.5 %)** — the largest single pass of the whole program, and 664 probe cases now pin it.

## The defect it found

`tools/distance_map.py` declares every `DAT_…` symbol in its preamble as `extern unsigned int`. So **every byte read
and every half read in the corpus was compiled as a word** — the image's `lbu` became our `lw`, `lh` became `lw`, and the
body scored as a near-miss for a reason that had nothing to do with the provider's C.

`stage2:0x800b2694` is the whole story in four lines: the image does `lbu $v0,25360($v0)` and we did `lw $v0,...`,
because the source reads `DAT_80136310` and *we chose its width*. The image had already made that decision.

Two consequences worth stating plainly:

- **The distance map's numbers are conservative, and the queue was mis-measured in the direction that hides closures.**
  Forty bodies it reported as near-misses were byte-exact modulo my own declaration. A fixture that measures the corpus
  is itself a claim about the corpus, and this one carried an assumption nobody had examined.
- The `width` class the workbench reports most often was **partly an artefact of the harness**, not a property of the
  provider's C. M411's 24 bodies were found by substituting *casts*; the same class was also reachable through
  *declarations*, where it had 41 more members.

## The two mechanisms that measured zero, and why they still count

- **`symbol:addr`** exists because `stage2:0x800a5700` differs by `ori` against `addiu` for one constant: a symbol goes
  through `%hi`/`%lo` with a relocation and lands as `addiu`, a foldable constant lands as `ori`. Measured **9 → 10 of
  10** on its source body — and 0 on the band, because the two bodies with that shape were already banked by hand in
  M419. A mechanism proven on its source body and measured at zero elsewhere is a *measured zero*, not a refutation.
- **`sig:forward`** reproduces both of M419's hand closures exactly (7 of 7 each, verified by running the pass on their
  provider text) and closes 0 of 240. Its pattern is rare: Ghidra declared `void f(void)` for a body that forwards three
  parameters and a constant.

## State

641 of 3 664 byte-exact (17.5 %), 368 of them the decompiler's own C and 273 ours. `verify.py` 14.9 s, `--full` PASS,
audit 160/160. The queue after this pass: **267 bodies within eight words**, ~2 000 at ≤ 120 words — and every one of
them now gets its data symbols at the width the image reads them, because the pass runs first.
