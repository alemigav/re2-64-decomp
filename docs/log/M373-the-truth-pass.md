# M373 — the truth pass: five stale numbers, and the page nothing was checking

M372 left the build reporting 197 of 210 and the front page reporting **390** of them, with **194 imported** — a
population that M369 had deleted, described in the present tense, on the page whose whole job is to say what is true.

This milestone adds no claim. It makes the record and the gates agree, and it is the third pass of a class that keeps
recurring: M335 fixed the headline pair, M366 fixed the shape census and two split counts, and each time the fix was
*partial* because `tools/counts.py` only reads the files it is told to read.

## What was wrong

| # | the claim | where | true as of | why it rotted |
| --- | --- | --- | --- | --- |
| 1 | "**390 functions match the cartridge exactly** … **194 are imported reconstructions**" | `README.md:23` | `7c156ac` (M364: 391 entries, 390 exact) | M369 removed those 194 entries and updated the *body*, not the result row |
| 2 | "The corpus of recovered functions is **391 entries, 390 of them byte-exact**" | `docs/README-extended.md:27` | M364 | **`docs/README-extended.md` was not a file `counts.py` read at all** |
| 3 | "**146 mechanisms and 146 failures**" | `README.md:95`, `docs/README-extended.md:220` | M284-ish | the audit grew to 160; the same page says `160/160` three lines above |
| 4 | `summary`: **188 functions / 23 868 B** | `fixtures/decomp/measured_extents.json` | M341 | `--write` summarises a *rescan*; M365 and M369 edited the lists and never rescanned |
| 5 | "**46** by hand + **55** singles" | both front pages | ~M335 | hand-typed prose summing to 198 against a corpus of 210 |

There is a sixth, of a different kind: `docs/log/M356-*.md` states that `leaf_screen.py --try`'s non-UTF-8 crash was
*"Fixed by decoding leniently"*. It was not. `tools/leaf_screen.py:239` was `subprocess.run(..., text=True)` with no
`errors=`, and `git log -- tools/leaf_screen.py` shows the file's last touch was M334 — **seventeen milestones** during
which a committed note described a tree that did not exist. That is the same defect as a wrong number, one level up: a
claim about the code, made by the record, and gated by nothing.

## What it took

- **`counts.py` now reads the page that explains the numbers.** `docs/README-extended.md` joins `CHECKS` with three
  cases, so the companion page can no longer rot unseen. Eight sentences that were previously prose are now derived.
- **The composition is derived, not typed.** Every entry carries a `probe` string, so the split has three provenances
  and they add up: **52** `single:*` (the screening tool), **42** `read from the words (M36x–M37x)` (by hand), **19**
  named probes, plus **97** cohort copies = **210**. The old 46/55 pair was 12 short and nobody could tell which 12.
- **The fixture's summary is regenerated from its own lists** — `extent_scan.py --resummary` — because after M365 a
  correction lives in `functions`, not in a scan. `counts.py` asserts the two agree, so a future `--write` cannot
  quietly re-summarise a different population.
- **`--resummary` is a regeneration, not a hand patch.** The rule is "a derived artefact is regenerated from its
  source"; once a milestone edits the list, the list *is* the source.
- **The removal is now an invariant.** `fixtures/decomp/imported/` must not exist; M369 deleted the corpus and nothing
  stopped it coming back.
- **`leaf_screen.py` decodes leniently, and says so where the defect was.** The strict call became a named `_run()`
  helper so the self-test can aim at it: a subprocess that writes `\xff\xfe\x80` to stderr must come back as text.
  Reverting the fix now produces `FAIL a non-UTF-8 stderr is decoded leniently, not raised` — verified by pointing
  `_run` at the old call shape.
- **Twenty-one tracked `.pyc` files left the tree.** They were committed by accident and churned on every tool run;
  a stale `.pyc` beside a rebuilt module is a cache the interpreter trusts before it reads the source. `__pycache__/`
  is ignored now, and `git status` stays clean through a working session.
- **The handover page's four stale figures** (byte-map residue, milestone count, two suite/case rows) are corrected
  and, where derivable, gated.

## The pinned count that broke, fourth in the arc

`compile_probe.py`'s rung case asserted `_sum["functions"] == 188 and _sum["bytes"] == 23868 and _sum["regions"] == 74`.
Correcting the fixture turned a *correct* change red — the same failure as M358's `extent_measured` pin, M360's
`function_body == 1 235 280` and M361's `covered_bytes: 58332`. It now asserts the relationship (`summary` is the list,
summarised) and, in the process, exposed a shadowed local: `_me` is rebound to the `corrections` list further down, so
the case had been reading `<list>["functions"]` all along and could only ever pass by comparing literals. The sizes are
captured at load time now.

## Moves

`recovered` **210 / 209** and `F1` **3 457** unchanged — this milestone moves no ledger, which is exactly what it is
for. `counts.py` **29 → 42 cases**, `leaf_screen --self-test` **12 → 13**, tree **78 suites / 1 288 → 1 303 cases**
(327 → 341 runnable, 961 → 962 gated), tools **105**, milestones **374 numbers / 318 rows / 299 notes**.
