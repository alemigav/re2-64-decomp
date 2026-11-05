# M351 — the audit unparked: three harness defects, and the first full `PASS`

The audit had been parked since M342, when it reported `119/148, 0 vacuous, 29 broken → INCONCLUSIVE` and the 29 were
attributed to one tool with a red case. Unparked on the finished census it now reports:

```
audit      159/159, 0 vacuous, 0 broken
VERDICT PASS — every procedure passed and the gate audit is 159/159 with nothing vacuous
```

**Nothing was wrong with the corpus.** All three defects were in the harness — and one of them had been hiding the other
two from the audit for nine milestones.

## 1. `file_table`'s stale literal (29 broken audits, one red case)

The case pinned *"the corpus holds 3678 function ranges and **74** without a src file"*. It reported **297**. Diagnosis:

- **123 of the "missing" starts are switch bodies.** The case's `have` set globbed `src/*/*.c` and never saw
  `src/*/switch/*.c`, where the provider's `switchD_::caseD_` arms live.
- **33 are functions published under their seed names** — `main.c`, `osCreateMesgQueue.c` — so `fun_xxxxxxxx.c` was never
  going to exist for them.
- the rest are range starts that belong to an absorbed or corrected extent.

So the count was a *literal that drifted twice*, and the fix is not a new literal: the case now asserts **the invariant**
— *every function `code_index.json` lists must name a file that exists* — and reports the corpus size beside it
(`0` without, `101/101` cases). A number that changes when the corpus changes should never have been pinned.

**That one red case was all 29 BROKEN audits**: a mutation cannot be judged when the unmutated tool already fails.

## 2. `build/toolchain` was never in the sandbox (the ninth environment gap)

`compile_probe.py` needs `cc1`. The audit sandbox linked `rom`, `assets`, `build/elfs`, `build/decomp`, `src` and `.venv` —
but not `build/toolchain`, so the probe reported `no cc1` for every profile, failed 106 of its cases, and **two mutations
could never be judged** (the residue-hypothesis and residue-profiler ones). Added to `LINK`; both now judge correctly.

## 3. Two vacuous mutations — both mine, both in the *test bed*

The audit's own rule is that a mutation must fail for the *right reason*, and it caught two that could not fail at all:

- **"the referenced-data rule stops checking whether anything references it"** — the mutation made the run lookup return
  the *last* run unconditionally, and the pin-case could not see that (it asserts that the *second* run is not hit).
  Re-aimed at the hit computation, so the addressed run loses its entry and the case fails.
- **"the string-table rule accepts a table of small byte codes"** — the synthetic payload was **4 words long, below
  `MIN_TABLE_WORDS` (8)**, so no rule could claim it either way and the mutation was a no-op. Lengthened to 16 words and
  made *letter-bearing* (eight letters, nine distinct bytes, no run of four), so the **word** test is now the only thing
  excluding it — which is what the mutation disables.

## What this says about parking an audit

M342–M350 ran the fast tier and left admission parked, and the reasons given were honest: the audit is slow and it was
one tool's red case. But **a parked audit cannot find harness defects**, and the parked state was hiding *three*: a shell
(`src/*/switch/`) that never matched, an input (`build/toolchain`) never linked, and two mutations that could not fail.
None of them was visible from the corpus side, and all three would have surfaced the moment the audit ran.

The rule to carry: **parking admission parks the instrument that audits the instruments.** Run it when a milestone
changes a gate, not only when a release asks for a verdict.

## Numbers

- **159/159 audit mutations, 0 vacuous, 0 broken → `VERDICT PASS`** (was `119/148, 0 vacuous, 29 broken`)
- `ci` 74 suites / 1 000 cases (cartridge present), `ratchet` 4/4, `counts` 26/26
- `file_table` **100/101 → 101/101**; byte map 20 cases; probe 136; **recovered 155 / 154 byte-exact — unchanged**
- three harness fixes: an invariant replacing a pinned count, `build/toolchain` linked, two mutations re-aimed
