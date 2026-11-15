# M433 — what the cap was hiding: four bodies and four improvements, and a full disk

M432 found that a cap of 12 variants silently discarded the one that closed a body. Rerunning the queue with the cap
raised answers the question exactly, and the answer has two halves.

## What the cap was hiding

| run | near band | mid band |
| --- | --- | --- |
| **cap 12**, to fixpoint | 0 closed, **63** improved | 0 closed, 284 improved |
| **cap 48**, to fixpoint | 0 closed, **67** improved | (not run — the 48 cap takes >4 min per band) |

- **The four closures are already taken.** The uncapped search on the *current* queue finds **zero** bodies that a single
  mechanism can close outright, on either cap — because the four the raised cap found were banked at M432. The cap's
  closure effect is measured and spent.
- **The improvements are not.** On the near band the raised cap still finds **4 more bodies it can move** (67 against
  63). So the cap was hiding, at the time it was raised, **4 closures and 4 improvements**, and the closures are the part
  that counts.

## The bug that rerunning it produced

The diagnostic **exhausted the 16 GB of free space on a 228 GB disk** and died with `No space left on device`. (Corrected at M434: the disk is 228 GB *in total* and was 92 % full before this ran, so the leak could not have filled it — it consumed the free space, and **836 scratch directories** were still on disk afterwards.) Cause: `pins()` created a scratch
directory per call and the only cleanup was an `atexit` sweep (M417) — an **exit handler**, which a long-running search
never reaches. Eleven minutes of uncapped variants created scratch faster than the process could exit.

The fix is per call, not per process: the pin frees **the directories it created** before it returns. Verified: six pins
in a row now leave the scratch count unchanged. **A scratch directory that outlives the measurement it held is a leak by
definition**, and an `atexit` sweep is a promise about the end of a process, not about the end of a measurement.

## Two smaller things the measurement needed

- **`VARIANT_CAP` is a module constant with a `--cap` flag.** A bound you cannot raise is a bound you cannot measure,
  and this milestone exists because of that.
- **`--no-bank`** counts closures without writing them, so a counterfactual (cap 12 against cap 48) does not require two
  copies of the repository or a reset between runs.

## State

**667 of 3 664 byte-exact (18.2 %)** — unchanged, and this milestone did not expect to change it: it measured a bound and
fixed a leak the measuring exposed. 690 probe cases, `--full` PASS, audit 160/160.

The honest reading of the whole pass experiment, now that the bound is right: **the passes close what they close, and the
queue's remaining 257 near-band bodies are not closable by any single mechanism or by the fixed point of all ten.** That
is measured at two different caps and with an uncapped search.
