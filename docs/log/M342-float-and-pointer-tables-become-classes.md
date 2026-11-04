# M342 — `float_table` and `pointer_table` become real classes, with mutations that prove the rules can fail

M338 measured that 12.4 % of the unclassified bucket is float tables and 3.5 % pointer tables, and explicitly refused
to name them: *naming a class needs a rule the classifier can enforce and a gate that can fail*. This milestone pays
that, and the first attempt at the rule was wrong by an order of magnitude.

## 1. One rule, two classes, one implementation

`classify_image.table_runs()` is now the single implementation of both rules; the map (`build()`) claims words with it
and the report (`unclassified_report()`) reports with it. That mattered immediately — the report still had its own copy,
which had already drifted:

- **`float_table`** — ≥ 8 consecutive float-*shaped* words, ≥ 90 % of the steps ascending, ≥ 4 distinct words.
- **`pointer_table`** — ≥ 8 consecutive words, all of them addresses inside **this** image.

Precedence: bodies → jump tables → named data → these two → padding → unclassified. A table inside a function is the
function; a run of one repeated value is fill (and the distinctness test refuses it anyway — belt and braces, both
stated).

## 2. The rule was wrong by 16× before the exponent band

The first version tested "is a plausible float" as `f == f and abs(f) < 1e6`, which **passes `0x00000001` and
`0x00010000`** — both are IEEE denormals near zero — so a run of integer data read as a float table. It claimed
**390 492 B**, most of stage2's data and every zero run inside it, and ate the padding class (408 124 → 37 484 B).

The fix is a band on the *exponent*: `0x78..0x87`, roughly 0.0078 to 256 — the range a computed table actually uses.
That is what keeps integers out, and with it the measurement is a table again:

```
float_table     23 980 B                  stage2:0x800f153c — 4 268 words, 0.007813, 0.008057, 0.008301, …
pointer_table   20 380 B                  runs whose every word is an address in the same image
unclassified   305 496 → 261 136 B        (15.6 % → 13.3 %); padding back to 408 124 B
```

Two more consequences, both caught by the tools rather than by review:

- **The report was a second copy of the rule** (M339's lesson, third instance). Left alone it reported tables the map
  had already claimed. It calls `table_runs()` now.
- **The pointer window was passed as `hi + 1`** instead of the image's end, so a *slice* test used a different window
  from the map's and reported 77 292 B of "pointer tables" that were nothing of the kind. The window is now an explicit
  parameter — `table_runs(blob, addr, window=(base, base + size))` — and membership is one predicate, `_addr_in()`,
  because a rule with two copies of its own test has two places to be wrong.

## 3. The gate, and the mutations that prove it is a gate

Three synthetic cases in `check()` pin the edges, with no cartridge:

```
PASS a monotone run of ten floats is a float table, and the same run reversed is not
PASS a run of one repeated float value is fill, not a table (the distinctness test)
PASS a run of ten in-image addresses is a pointer table, and ten out-of-image words are not
```

and **two mutations** in `audit_gates.py` loosen exactly one half of one rule each, so the audit proves they can fail:

| mutation | what it breaks |
| --- | --- |
| `the float-table rule accepts a descending run` — `asc >= 0.90` → `asc >= 0.0` | the reversed-run case |
| `the pointer-table rule stops checking the address window` — `_addr_in()` returns `True` | the out-of-image case |

The first attempt at the second mutation was **vacuous** — it disabled the entry skip rather than the membership test,
so the tool still refused out-of-image runs for a different reason and the audit said so (*"they cannot fail for the
right reason"*). That is the audit doing its job on a mutation, which is the detail most easily skipped.

## 4. Two environment gaps the audit found, and one it still has

Running the audit for the first time since M332 exposed two sandbox gaps, both mine and both the same shape — *an input a
tool reads must be copied into the sandbox*:

- **`docs/README-extended.md`** — M332 gave the new document three markers; `check_markers.py` then needed the file in
  the sandbox, and every `check_markers` mutation had been BROKEN since. Added to `COPY_FILES`.
- **`fixtures/decomp/measured_extents.json`** — M340/M341 made three tools read it. Added as `COPY_FIXTURES`.

**The gap that remains is logged, not chased, and it is smaller than it looked.** The admission run
(`verify.py --full`) reports **119 of 148 detected, 0 vacuous, 29 broken** → verdict **`INCONCLUSIVE`**, which is the
rule working: a broken audit is not a pass. But all 29 broken are **one tool** — `file_table`'s mutations — and the
reason is not the sandbox: `file_table.py --check` reports **100/101 in the repository itself**, so a single case in that
tool is genuinely red and its mutations cannot be judged. That is one red case in a cartridge-gated suite the fast tier
never runs, not 29 environment gaps, and diagnosing it is its own milestone. The `0 vacuous` is the part that matters
here: both new mutations now fail for the right reason.

## Numbers

- **7 classes** now: `function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 ·
  pointer_table 20 380 · padding 408 124 · unclassified 261 136 = 1 956 560 B` — the partition still closes exactly
- byte map **6 → 9 cases**; audit **146 → 148 mutations**; `unclassified` **305 496 → 261 136 B (13.3 %)**
- **recovered 155 / 154 byte-exact — unchanged**; no reconstruction, no census change: two classes and their rules
- one rule, one implementation (`table_runs`), one predicate (`_addr_in`), three pin-cases, two mutations, two sandbox
  fixes, one logged gap
