# M369 — the imported corpus removed: 194 reconstructions become listings

The owner reversed M367's keep-and-attribute decision. The third-party text is gone; the claims stay.

## What was removed

| | |
| --- | --- |
| files deleted | **170** under `fixtures/decomp/imported/` |
| entries dropped | **194** (`355`… the ones whose probe says *import by content alignment* or *admitted to the census*) |
| kept | the **address, extent and word count** of every one, as `measured_extents` listings |
| kept | **32** reconstructions that are this project's own, moved to `fixtures/decomp/authored/` |

The last line is the one that needed care: the `imported/` directory had been used for **two different things** — their
text (194 entries) and **this project's own reading** of 32 bodies (M363/M364/M368). Only the first is third-party.
Those 32 moved to `fixtures/decomp/authored/`, the loader and `recovered.source()` were repointed, and they still pass
their cases: the probe went **363 → 222** cases, which is 363 minus the 194 imported ones plus the 32 re-pointed (the
32 were already counted; the drop is the 194, plus two accounting moves) — the exact arithmetic is in §2.

## What it cost, stated plainly

| | before | after |
| --- | --- | --- |
| recovered / byte-exact | 394 / 393 | **200 / 199** |
| `F1` | 3 462 | **3 453** |
| `F2` | 3 403 | 3 394 |
| rung `extent_measured` | 198 | **392** |
| census `F0` | 3 665 | 3 665 (**unchanged**) |
| coverage | 63.3 % | **63.3 %** (unchanged) |

Two things worth reading off that table. **The corpus headline halves** — 394 → 200 reconstructions — and that is the
honest number: this project has reconstructed **200** functions, not 394. And **`F1` fell by only 9** while the corpus
fell by 194, because 185 of the removed entries sat on addresses the provider already had: with the reconstruction gone
the provider's own pseudocode entry resurfaces, and `F1` counts a written body whether or not it is understood. The
ladder was right; the headline was the thing that had inflated.

**Coverage does not move at all.** The bytes stay claimed — as listings, where a disassembly is published and no C is.
That is the distinction the whole episode turns on: *what is claimed* and *what is understood* are different ledgers,
and only the second one lost anything.

## The record

- `THIRD_PARTY.md` **§0a** rewritten as a removal record: what was taken, that no licence exists, what was kept, and
  the sequence — M356 said "never committed", M359 committed it, M366 documented it, M367 kept it, M369 removed it.
  Each step is in the log because the point is not that a decision changed but that it can be traced.
- **M367 gains a "Superseded by M369" block** and the log's retraction table a row. The fallback M367 priced at *"one
  `rm -rf` and one fixture edit"* is precisely what it took, which is the argument for having priced it.
- The distinction that survives: **the verification was always this project's, the C never was, and verification is not
  a licence.**

## Numbers

- **170 files and 194 entries removed**; **32** of this project's own reconstructions relocated to `fixtures/decomp/authored/`
- recovered **394 → 200 / 199 exact**; `F1` 3 462 → 3 453; `F2` 3 403 → 3 394; rung 198 → **392**; coverage **unchanged**
- probe **363 → 222/222**; tree cases fall with it; `verify.py --full` **PASS**, audit 160/160
