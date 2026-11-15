# M446 — statement proposals: one function closed, and the metric that was hiding it

The instrument the last four milestones pointed at: propose **statements** rather than shape. It closed
`ovl_0093192:0x801629d0` — the first function this arc has closed — and on the way it found a defect in the project's
own scoring metric that was hiding bodies like it.

## 1. The metric was wrong for the whole population

`distance.json` counts identical words **positionally**. A single inserted instruction shifts every later word, so a
body with almost everything present in order scores near zero. Measured across all 969 `our-short` bodies:

| | |
| --- | --- |
| bodies where aligned identity ≠ positional identity | **969 of 969** |
| median aligned identity | **34** |
| median positional identity | **4** |

`stage2:0x80025e6c` is 0 of 9 positionally and 6 of 9 aligned. `ovl_0093192:0x801629d0` is **3 of 33** positionally and
**32 of 33** aligned — a body one word from exact, ranked by the map as hopeless. The map's `gap` is not a ranking for
this population, and the near band it produced (19 bodies) was a lower bound, not a count.

## 2. What is actually missing — and the omitted-locals hypothesis, refuted

`tools/missing_spans.py` aligns with `difflib.SequenceMatcher` and classifies every image instruction that has no
counterpart. Over the 969 short bodies: **68 872 missing words**.

| content of the missing spans | instructions |
| --- | --- |
| **arith** | **30 608** |
| loads/stores (`lw` 6 634, `sw` 5 616, `sh` 3 415, `lbu` 2 984, `lhu` 2 398, `sb` 2 293, `lh` 1 413, `lb` 411) | ~25 200 |
| branch | 5 309 |
| const | 4 403 |
| jump | 2 026 |
| **`sp` access inside the frame gap** | **1 767 (2.6 %)** |

So **the omitted-locals hypothesis addresses 2.6 % of what is missing**, and only **2 bodies of 969** have in-gap
accesses as the majority of their missing words. M439's frame measurement was about *frame size*, and frame size is not
the same thing as a body missing its statements. Starting here would have built a template for 2 bodies.

The dominant missing content is arithmetic across many spans: these drafts are substantially different programs, not
drafts with one statement dropped.

## 3. The one body that was one word away

Aligned gap 1 on 33 words. The single missing instruction:

```
image[3]  24070400   addiu a3,zero,1024
```

and the draft called `func_0x80089d54()` with **no arguments**. The proposal is a statement-level one — supply the
argument the image materialises — and it closes the body:

| | positional | aligned | `bank_exact.pins` |
| --- | --- | --- | --- |
| draft | 3 / 33 | 32 / 33 | 3 / 33 |
| with `func_0x80089d54(param_1, param_2, param_3, 0x400)` | **33 / 33** | 33 / 33 | **33 / 33 — byte-exact** |

Banked as `fixtures/decomp/authored/ovl_0093192/801629d0.c`, `provenance: "provider"`, with the probe string naming
exactly what was added and why. `compile_probe --check` went **690 → 691 of 691** on its own, because the pin is
derived from `source_file`. **`recovered` 668 → 669, byte-exact 667 → 668.**

## 4. What the instrument is, and what it is not

- **It works and is registered**: `missing_spans.py --self-test` has 5 cases, the first of which is the finding — one
  inserted word makes positional identity 2 of 5 where alignment says 4 of 5 present.
- **It is a diagnostic, not a generator.** It says *what* is absent and *where*; proposing the C for an arithmetic span
  needs semantics the span does not carry. The one body it closed was closed by hand from its diagnosis.
- **The population it describes is mostly far even when measured correctly**: 770 of the 969 short bodies are missing
  more than 16 aligned words.

## Numbers

- 969 short bodies; **68 872** missing words; in-gap **1 767 (2.6 %)**; **2** bodies where in-gap is the majority
- aligned vs positional disagree on **969 of 969**; median **34** against **4**
- **1 function closed**: `ovl_0093192:0x801629d0`, 33 of 33, `recovered` 669 / byte-exact 668
- probe **691/691**; tree **95 suites / 1837 cases**; `tool_count` 119; counts 47/47, markers 25/25
