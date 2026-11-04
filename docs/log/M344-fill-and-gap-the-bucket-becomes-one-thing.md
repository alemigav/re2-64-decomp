# M344 — `fill` and `gap`: the unclassified bucket is now exactly one thing

M343 left 250 764 B unclassified and described it as three kinds. Two of those kinds are *structural* — decided by a run's
length and its neighbours, not by a guess about its content — so they become classes, and what is left means one thing.

## 1. Two structural classes

- **`fill`** — a run of one repeated `0x00`/`0xFF` **shorter than the padding law's 16-byte floor** (so 4–15 B):
  **1 496 B**. The law's floor stays exactly where it is, because it exists so that a lone `0x00` word is not called
  padding; this names the case *below* it instead of bending the contract.
- **`gap`** — a run **under 64 B with a function body on at least one side**: inter-function slack, **4 720 B**. The
  evidence is the **adjacency**, not the size: M338 measured 543 runs sitting directly between two bodies.

Both are decided by `relabel_residue()`, which runs on the *same run list* the other rules produced — hoisted to module
scope for this milestone precisely so its cases could be pinned on synthetic run lists rather than on the cartridge.

## 2. `gap` is smaller than the small residue, and that is the point

The report said 16 992 B of "small residue under 64 B". `gap` claims **4 720 B** of it, because most of those runs are
**not** adjacent to a body (they sit between a table and a body, or between two gaps). The rule refuses to call a run
inter-function slack without a function on one side of it, so 12 272 B stays unnamed. A smaller class with a stated
reason beats a bigger one with a threshold alone.

## 3. Measured, and what `unclassified` now means

```
function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 · pointer_table 20 380
string_table 13 200 · padding 405 296 · fill 1 496 · gap 4 720 · unclassified 244 548 (12.5 %) = 1 956 560 B
```

**10 classes**, partition closing exactly, and the residue is now one kind of thing: **≥ 64 B (or under 64 B and not
beside a body) of bytes that are not code, not text, not a table and not fill** — 232 276 B "structured" plus 12 272 B of
small non-adjacent runs. That sentence is now the class's definition instead of an implication.

## 4. The gate

```
PASS a 12-byte run of one value is `fill`, and a 200-byte one is not
PASS a short run between two bodies is `gap`, and the same run elsewhere stays unclassified
```

Two mutations, one per rule — `fill` reaching into the padding law's ≥ 16-byte territory, and `gap` losing its length
bound. `--lint` clean (3/3). **The audit stays parked**: its state is M342's (`119/148, 0 vacuous, 29 broken →
INCONCLUSIVE`, all 29 one tool with a red case that is red in the repository too), and one fast-gate pass is the gate for
this milestone, as agreed.

Two of this milestone's own bugs were in the *test bed*, not the rule: a synthetic blob too short for the run's offset
(the slice came back empty, so `fill` never fired) and a "not fill" case whose run was 20 B — legitimately a `gap`. Both
were caught by the case failing, which is what a pin-case is for.

## Numbers

- **10 classes**; `fill` **1 496 B**, `gap` **4 720 B**; `unclassified` **250 764 → 244 548 B (12.5 %)**
- byte map **11 → 13 cases**; audit **150 → 152 mutations** (lint-clean, not run)
- **recovered 155 / 154 byte-exact — unchanged**; no reconstruction, no census change
