# M389 — the front page answers "how close is this?" on the first screen

The repository published five numbers that all sound like progress — **63.3 %** of the image bytes inside a known function
body, **274** reconstructions, **273** byte-exact, **33** curated names, **3 664** catalogued functions — and a newcomer
could not tell which one answered the question they came with. A reader who left believing "63.3 %" had been misled by a
true sentence, which is the same defect M369 named when `F1` fell by 194 and coverage did not move.

This milestone puts the score where it belongs and gives it a picture.

## What is on the page now

A generated block sits immediately under the hero, before anything else on the page:

```
**273 of 3 664 functions match the cartridge exactly — 7.5 %.**

█ █ █ █ █ █ █ █ ▒ ▒
▒ ▒ ▒ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░    ← 100 cells, one per 1 % of the catalogued functions
... (ten rows)

| the three numbers, and which one is the score | |
| **reconstructed and proved** — the score | **273 of 3 664** (7.5 %) |
| bytes inside a known function body | 63.3 % — a *classification*, not a reconstruction |
| functions with a curated name | **33** of 3 664 — the gap between a transcript and understanding |
```

plus the distance in *work* (**53** functions in the last ten milestones ⇒ about **640 more** at that rate) and the build
meter (**273 of 274** bodies link at their cartridge address, 28 image ELFs, 1 published partial, 0 data segments).

**The waffle is the picture the page was missing.** Seven and a half cells out of a hundred is what "7.5 %" looks like,
and it is impossible to read as "nearly done" — which is the point.

## The generator, and why it is not hand-drawn

`tools/front_page.py` (new, 105 → **106 tools**) renders the block from `manifests/analysis_status.json`,
`fixtures/decomp/recovered.json` and `build/corpus/index.json`, and writes it between two markers in `README.md`:

```
tools/front_page.py --write      # re-render
tools/front_page.py --check      # fail if the committed block is stale   (a registered suite, 1 case)
tools/front_page.py --self-test  # 5 cases: the cell total, the order, a lopsided census, insertion, idempotence
```

Three things it does that are worth keeping. **The cells are allocated by largest remainder**, so the three colours add up
to exactly 100 — rounding three percentages independently prints 101 cells, which is the kind of quiet arithmetic defect
this project keeps finding in its own instruments. **The insertion is idempotent** (`--write` twice changes nothing).
And **`--self-test` covers the arithmetic and the splice, not the page**, so a mutation to the cell allocation or to the
marker handling fails a case rather than a reader noticing.

## Every number in the pictures is asserted

A generated block is not a licence to stop gating. `counts.py` gains **three** cases for the sentences a newcomer reads
first — the headline pair and its percentage, the waffle legend's three counts, and the distance line — and its total goes
**42 → 45**. The derived keys are computed in `counts.py` itself (`front_pct_whole`/`front_pct_dec`,
`status_pseudocode`, `status_remaining`, `front_milestones_left`), so the pictures cannot disagree with the ladder they
describe.

**Two of my own slips, both caught by the gates rather than by review:** the first regex had `%%` and a missing period
before the bold close (the sentence ends `7.5 %.**`), and my patch inserted the three new rows **twice** because the
anchor it used appears twice in `CHECKS` — a duplicated row still passes, so only counting the rows found it. Both fixed;
`counts` is 45/45 with no duplicate.

## The test this milestone is graded by

A reader who sees **only the first screen** must be able to answer, correctly, without scrolling. From the new page:

| question | the page's answer |
| --- | --- |
| How close is this to done? | **273 of 3 664 — 7.5 %**, stated twice: as a line and as a picture |
| Which number is the score? | the table names it: reconstructed-and-proved is the score; bytes-inside-a-body is **a classification**, and the prose says why |
| What is left? | **3 390 functions**, about **640 milestones** at the last ten's rate, and the build's 1 published partial |

All three are answerable from the first screen. That is the gate, and it is the reason the block is above the result
table rather than below it — the first layout put it after the "not a matching build" paragraph, which is one screen too
low.

## The defect CI found, which review did not

The first push of this milestone **failed** (`42495191804`): `front page (repository) — no verdict, exit 1`. The cause is the
same class as M356's `.rodata` lesson and M389's own subject — **an input that is not in the tree cannot gate anything**:
the build meter was rendered from `build/corpus/index.json`, which is **gitignored**, so the block rendered in CI (no build
output) never equalled the committed block (rendered with it) and `--check` was guaranteed red on every future run.

The fix is to derive the meter from a **committed** fixture: `make check`'s exact count *is* the corpus's byte-exact count
(M374's invariant `exact = recovered − partials`), and the images are the ones that carry a reconstruction. The tool now
renders **273 of 274 over 28 images** from `recovered.json` alone, and `--check` was verified green with `build/` moved
out of the way — the exact condition CI reproduces.

**The general form, worth keeping:** a generator whose `--check` reads a gitignored path is a gate that cannot pass. If a
picture needs a build artefact, derive the number from the fixture that *predicts* the artefact and say in the prose where
the artefact's own ledger lives.

## What this milestone did not do

The plan's second half — **moving the dense inventory out of the front page into `docs/README-extended.md`** — is not
done, and the reason is a number: the page carries **19 asserted sentences** across 13 `counts.py` rows plus 25 marker
anchors and the phase table `progress_map.py` parses. Moving a sentence means retargeting its row to the other file in the
same commit, and doing eight of those in one pass, on the page that gates the project's own honesty, is the kind of change
that should be its own milestone with its own verification. **It is named here as the next front-page step rather than
half-done.**

## Moves

counts **42 → 45 cases**, tools **105 → 106**, tree **78 → 79 suites / 1 373 → 1 377 cases** (347 → 351 runnable),
`verify.py --full` **PASS**, audit **160/160**. The corpus ledgers did not move: `recovered` **274 / 273**, `F1`
**3 468**, rung **317**, coverage **1 238 404 B**. Milestones **390 numbers / 334 rows / 315 notes**.
