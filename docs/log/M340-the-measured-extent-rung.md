# M340 — the measured-extent rung: five truncated stubs become five known bodies, and nothing is absorbed

M323 left four extent corrections with "no channel", because `recovered.json` carries only functions that have a C
reconstruction. This milestone builds the channel, and it closes **five** corrections — the four, plus `0x800115b0`,
which M324 unlocked by correcting the boot image's own extent.

## 1. The rung

`fixtures/decomp/measured_extents.json` gains a **`corrections`** list: an extent the bytes give, with the evidence that
authorises it and no C. One reader (`recovered.load_measured()`), **three** consumers — the M289 rule applied to a third
input:

| consumer | what it does with it |
| --- | --- |
| `export_src.py` | publishes the corrected extent, status **`extent-measured`**, and a header line carrying the old and new word counts plus the evidence |
| `counts.py` `_corpus()` | merges it into the coverage union, so the front page's figure includes it |
| `classify_image.py` | claims its words as `function_body`, so the byte map moves with the union |

```
                                     before      after     delta
coverage (union)                  1 211 256   1 212 068   +812 B
byte map: function_body           1 210 600   1 211 412   +812 B
byte map: unclassified              330 176     329 364   -812 B
ladder F1                             3 416       3 411     -5
ladder F2                             3 329       3 324     -5
```

The two projections moved by the *same* 812 B — which is the property the channel exists for. Note the deltas sum to
884 B (`3×43 + 90 + 2` words) while the union grew by 812: 72 B of the corrected spans were already inside another
body's ranges, and a union is what coverage means.

## 2. The five, and why they were invisible

| function | census | measured | callers | why it looked like a stub |
| --- | --- | --- | --- | --- |
| `stage2:0x8004276c` | 3 w | **46 w** | 96 | no `jr ra` where the provider expected one |
| `stage2:0x80042824` | 3 w | **46 w** | 20 | the `sw` member of the same 64-bit DSP family |
| `stage2:0x800421b4` | 3 w | **46 w** | 3 | the third 46-word member |
| `boot:0x80000dd4` | 5 w | **95 w** | 7 | the largest truncated body in the corpus |
| `boot:0x800115b0` | 3 w | **5 w** | 1 | measurable only after the boot extent became `0x13420` (M324) |

All five are hand-written assembly or table-driven code, so there is **no C to reconstruct** — which is exactly why they
needed a rung rather than a draft.

## 3. The ladder gets a rung *below* F1, and says so

`F1` means "a body exists that could be read". These bodies are the provider's truncated head, so crediting them would be
M296's error in the other direction. `extent-measured` is therefore **F0 only**, and `analysis_status.py` states it in
its own rules block:

```
"extent_measured": "the extent is measured and the body is NOT reconstructed -- F0 only, never F1"
```

F1 3 416 → 3 411 and F2 3 329 → 3 324. The manifest publishes `extent_measured: 5` as its own total, so the rung is
countable without being confused with understanding.

## 4. Three things the work found that the plan did not anticipate

**(a) `boot:0x80000dd4`'s 95-word body contains a published function.** `0x80000f08` is 18 words, sits inside the
corrected span, and has **three direct `jal` callers** — so it is not a continuation the provider mis-split, it is a real
entry point into the tail: a shared-tail idiom. Absorbing it (which is what the recovered pass does to a body's arms)
would delete a function that is called directly. The extents therefore **overlap by 72 B**, and the header-sum invariant
now reads *headers == union + overlap* with the number named — 1 212 140 = 1 212 068 + 72 — instead of pretending the
two are equal.

**(b) The detector that found the five must now report zero.** `truncated_extents()` walks call-referenced entries whose
census body has no return; it used to return 46/46/46/95/5 with 96 callers at the head. With the census corrected it
finds **nothing**, and its probe case flipped from "these five are truncated" to "no call-referenced entry runs past its
census extent any more, and this detector must be silent" — because **a measurement that authorises must also veto**. A
gate that keeps finding its old defect is a gate the fix never satisfied.

**(c) A corrected body's callee list cannot be the provider's.** The provider analysed the head only, so its call record
is incomplete by construction; the byte scan is authoritative. `export_src` marks those records `extent_measured: true`,
and `call_graph.py --check` exempts exactly those nodes from its byte-versus-index comparison, printing the count and the
reason — one node — rather than dropping it silently.

## 5. Two regressions this milestone caused, and the invariants that caught them

- **The callee filter widened.** I replaced "site inside one of the provider's ranges" with "site inside `lo..hi`", which
  for a *multi-range* function counts calls in the gaps. Three F2 functions were demoted for no reason; the fix restores
  the per-range predicate for uncorrected bodies and keeps the span only for measured ones.
- **`size = hi - lo + 1`** did the same to the published byte size: the header sum jumped 30 528 B above coverage, and
  the "headers sum to the covered bytes" case named it immediately. Restored to the sum of range lengths.

Both were mine, both were caught by the arithmetic rather than by review, and both are the reason that case exists.

## Numbers

- **coverage 1 211 256 → 1 212 068 B (+812)**, byte map `function_body` 1 210 600 → **1 211 412**,
  `unclassified` 330 176 → **329 364** (16.8 %)
- **F0 3 416 / F1 3 411 / F2 3 324**, `extent_measured` **5**; the rung is F0 only and the rules block says why
- **recovered 155 / 154 byte-exact — unchanged**: an extent is not a reconstruction, and this rung does not pretend to be
- probe **132 → 133 cases (133/133)**; tree **75 suites / 1 129 cases** (34 runnable / 307, 41 gated / 822)
- two mutation anchors re-aimed (`call_graph`'s callee line, `counts`' header-sum and boot `covered_bytes`), and the
  counts self-test bed gained its **fourth** missing input — the list that has now been short four times
