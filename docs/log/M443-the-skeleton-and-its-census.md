# M443 — the skeleton exists, and the first census overstated its own opportunity by 86 %

Nothing in this repository knew what shape a function is. `shape_of` is one bit — `loop` if any branch targets
backwards — and the manifests carry calls and dispatch heads but **no basic blocks and no branch structure**. So a tool
could not ask a question that six catalogued mechanisms need: *does the image have a guard where the draft has a wrap?*
`mechanism_pass.MECHANISMS` marks `loop:walk-vs-index`, `guard:conjunction`, `compare:copy`, `rematerialise:block`,
`pointer:named` and `domain:integer` as not expressible as text passes, and nothing could tell whether they mattered.

`tools/skeleton.py` decodes a body's own words into branches with **resolved targets**, basic-block entries, loop edges
with pre/post-test classified from the edges rather than from the C, guards, returns, calls and dispatch — and `diff()`
names the difference between two skeletons in a closed vocabulary. The decode is pure integer arithmetic: no objdump, no
`build/`, so a gate can run it in a CI checkout that has neither.

## Two artefacts the decoder produced, and the controls that caught them

Both were caught by inspecting the **counts inside the classes**, and both are now controls in `--self-test`:

- **A two-word fragment was classed as a `dispatch`.** `boot:0x800006d0` is `lui $k0` and `addiu $k0` and nothing else;
  it matched `compile_probe.dispatch_signature`'s pattern. Guarded: a dispatch head needs ≥ 8 words and an actual `jr`
  through the register.
- **Comparing RETURN POSITIONS labelled identical shapes as `early-return`.** Positions shift with body length, so
  `boot:0x800013d4` — 2 returns against 2, 5 branches against 5, 11 blocks against 11 — was called `early-return`
  purely because a 53-word gap moved `end - 8`. The class now compares early-return **counts**.

## And the one the design review caught, which is the important one

The first census reported **1 785 of 2 478 open bodies (72 %) repairable**. That number was wrong, and the way it was
wrong is this: **969 bodies compile SHORTER than the image's extent**, and a truncated body's branch and return counts
are counting a *prefix* of the function. Every structural class above was comparing a whole against a part, and
truncation was being laundered into `early-return` and `guard-shape`.

`stage2:0x8008ca0c` is the clean example: 79 words against our 72, returns 1 against 1, forward branches 2 against 2 —
and it was classed `early-return`. `diff()` now tests **`our-short` first**, before any structural class.

## The census, corrected

2 478 open scored bodies, ~37 s at 8 jobs:

| class | bodies | | class | bodies |
| --- | --- | --- | --- | --- |
| **our-short** | **969** | | dispatch | 96 |
| **early-return** | **551** | | loop-count | 69 |
| likely-branch | 240 | | loop-kind | 46 |
| guard-shape | 169 | | nesting | 15 |
| no-return | 159 | | extra-loop | 7 |
| none | 150 | | missing-loop | 7 |

**960 repairable (39 %), 902 of them far.** The pre-registered kill rule was 50 bodies; the corrected figure clears it by
an order of magnitude, so the loop proceeds — but the honest headline is that the *biggest single class is not
structural at all*: 39 % of the open far band emits fewer instructions than the function has, which is a coverage gap in
the draft, not a shape error.

## What this settles

- a function's control-flow skeleton is now **decoded and diffable**, with controls that make the decoder fail when it
  is wrong (9 cases, including both artefacts above);
- the addressable structural population is **960 bodies**, dominated by `early-return` (551) and `guard-shape` (169);
- and the census's own first answer was **86 % too optimistic**, because a comparator that cannot tell truncation from
  structure will attribute almost anything to structure.

## Numbers

- `tools/skeleton.py`: 9 self-test cases; `diff()` over 12 classes; no `build/` dependency
- `tools/skeleton_census.py`: 2 478 bodies measured, **960 repairable (39 %)**, 902 far; `--check` re-derives the summary
  and re-measures a 16-body sample
- registered as three suites (`skeleton` 9 repository cases, `skeleton census` 3 repository cases, `structure loop` 1
  gated): tree **91 → 94 suites**, cases **1819 → 1832**, `tool_count` **115 → 118** — the full bincount cascade through
  README, handover, `ci.sh` and `acceptance.yml`
