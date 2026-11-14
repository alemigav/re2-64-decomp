# M418 — the fast tier is 14.2 s again: the audit was 273 s and had never been named heavy

The rule has been in force since 2026-11-03: *"it cannot be more than 30 seconds to verify everything beginning to end"*.
M417 measured the fast tier at **5 m 50 s** and named it as the thing to fix before drafting at volume. It is now
**14.2 s**, and `verify.py` defaults to **14.75 s** — measured, not estimated.

## Where the 350 s went

Timing all 87 fast-tier suites serially:

| suite | time |
| --- | --- |
| **gate audit (mechanisms disabled)** | **273.3 s** |
| toolchain matrix (cartridge) | 36.8 s |
| sound decode (cartridge) | 10.8 s |
| compile probes (cartridge) | 8.2 s |
| the other 83 suites | ~15 s together |

**The gate audit was 79 % of the tier and was not in `acceptance.HEAVY_SUITES`.** The project's own rule — *never add a
suite to the fast tier without timing it* — had no case that enforced it, so the heaviest suite in the repository sat in
the tier that promises half a minute, and grew there as the corpus grew.

## Four changes, each measured

1. **The gate audit is a named heavy suite.** It is admission-grade verification: `verify.py --full` already runs it as
   its own *procedure*, so grading it a second time inside the fast tier bought nothing. **273 s → 0 s** of the fast
   tier, and `--full` still runs it twice (once as a suite, once as admission) — that duplication is pre-existing and
   now visible.
2. **`toolchain matrix` is a named heavy suite too** (36.8 s, the second heaviest, also unnamed).
3. **`acceptance`'s default pool was 1** — three cores idle on every run, and the fast tier was a serial sum of 87
   suites. It now defaults to `min(MAX_JOBS, cpu_count)`. The pool already existed, was already clamped to 4, and its
   results were already collected by index so the report is order-stable (M240); only the default was never set.
   **71 s serial → 14.2 s wall.**
4. **The audit's own cost halved** for the `--full` path: its positive control runs the *unmutated* tool in a pristine
   sandbox, which is **identical for every case sharing a tool**, so it is now cached per (interpreter, tool, args).
   Serial audit **529 s → 195 s wall at 4 jobs**, and the verdict is unchanged: **160/160, 0 vacuous, 0 broken.**

A fifth, smaller fix: the fast tier's own sentence said *"four heavy suites held back"* while there were six. It no
longer carries a number — the count lives in `acceptance.HEAVY_SUITES`, which is the one place it can be right.

## The rule this milestone leaves

**A timing contract needs a case that enforces it, not a paragraph that states it.** The 30-second rule has been quoted
in every session since 2026-11-03 and nothing measured it; the tier grew 20× over thirty milestones while every gate
stayed green, because "slow" is not a failing test. The next tier change should come with a suite that times the tier.

## State

598 of 3 664 byte-exact (16.3 %), `verify.py` **PASS-FAST in 14.75 s**, `--full` PASS with audit 160/160. The drafting
queue resumes: 155 bodies at gap ≤ 4, 2 017 at ≤ 120 words, one command each in `tools/draft_workbench.py`.
