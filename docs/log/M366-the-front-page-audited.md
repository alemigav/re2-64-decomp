# M366 — the front page audited: three stale claims, a licence problem, and the gates that now cover them

A third-party review of this repository made four claims about it. Three are checkable and one of them is serious.
This milestone checks all four and fixes what is ours to fix.

## 1. Number drift on the front page — real, and the gates could not see it

| claim | was | is |
| --- | --- | --- |
| functions matching the cartridge exactly | **129** | **390** |
| copies of a proven body shape | **59** of **eight** | **97** of **21** |
| "checks run with no ROM" / "the other N need your dump" | **302 / 839** | **324 / 1 088** |
| `verify.py` one-liner | **302 run, 815 SKIP** | **324 run, 1088 SKIP** |

All four sat in the **headline table** — the first thing anyone reads — and none was covered by `counts.py`, which
gated the *corpus* pair ("N reconstructed, M matching") and left the rest to prose. That is exactly the failure mode
M335 recorded for the corpus pair itself, one layer out: *a number that is the point of the repository gets a case*.

Three gates were added, and each was proved able to fail:

```
("README.md", r"(\d+) of them are copies of (\d+) proven body shapes", ("cohort_copies", "cohort_shapes"), 1),
("README.md", r"\*\*(\d+) checks run with no ROM, no assets and no emulator\*\* — the other (\d+) need", …),
("README.md", r"PASS-FAST: (\d+) cases run, (\d+) SKIP", …),
```

with `cohort_copies`, `cohort_shapes` and `imported` now **derived** from `recovered.json` rather than typed. The
proof they bite: changing `97` to `96` fails the check with `[96, 21] != [97, 21]`, and reverting passes. Counts went
**26 → 29** cases.

## 2. The licence problem — real, and the repository contradicted itself

The review's sharpest point: **170 C files from another decompilation are committed under
`fixtures/decomp/imported/`**, while M356's note says that corpus is *"never committed here"*, and `THIRD_PARTY.md`
does not mention them.

Checked: the other project publishes **no licence at all** — no `LICENSE`, no `COPYING`, no `NOTICE` — so by default
**all rights are reserved**. The sentence in M356 is true of the *download* (which is gitignored) and false of its
*output*, and the milestone after it built the channel that commits the output. Both statements were in the tree at
once, which is how such contradictions survive.

What this milestone does about it:

- **`THIRD_PARTY.md` §0a** states the position: what was taken (192 reconstructions' C text), what was not (no tool,
  no corpus), the licence status, and **three options with their costs** — remove and fall back to listings (F1 −192),
  ask the other project for permission, or keep-and-attribute as §2 does for `src/`, noting that §2's material is the
  game's own code while this is a third party's work product with no licence, which is weaker.
- **M356's note gains a "Retracted by M361/M366" block** and the log's retraction table a row. Retraction by addition,
  as the project does: the note keeps every number and gains the correction.
- **The choice is left to the owner**, because it is a legal decision and not a measurement. Nothing was deleted
  unilaterally: deleting 170 files is a one-command change once asked, but it is not a decision a verifier should take.

What the review does *not* affect: the verification. Every imported function compiles to its own address on this
cartridge and is re-derived by its own case. **Verification is not a licence**, and the note had the two confused;
that confusion is now written down rather than argued away.

## 3. The other two claims — correct, and already stated in the repository

- *"Only 33 functions have curated names, and 12 have behaviour pinned by experiment."* — **true**, and both are
  published: the README says *"33 carry a curated name, and 12 have behaviour pinned by a gate or an executed
  experiment — and all 12 of those are still called `FUN_…`, because a name needs evidence of its own."*
- *"63.4 % is bytes classified inside a function body, not bytes understood."* — **true, and the sentence it is
  quoting says so**: *"63.3 % of the image bytes sit inside a known function body and the rest is classified rather than
  guessed"*. A reviewer reading 63.3 % as "understood" is reading the number against the sentence, which is why the
  ladder (`F1` 3 459 of 3 665 = the *reconstructed* column) exists next to it.
- *"There is no Makefile, linker script or build that produces a ROM; `src/` cannot be compiled as it stands."* —
  **true**, and the README's opening line says *"This is not a matching build"*. It does not say "and there is no
  build system at all", which is a fair thing to add: the repository builds **one function at a time** through
  `compile_probe.py`, and a linked image is out of scope so far.
- *"Static recompilation needs ELFs plus symbols; this repo builds the ELFs."* — accurate, and it is the one forward
  path the repository has that a reviewer independently identified.
- *"363 milestones in nine days… suggests heavy AI-agent involvement."* — **true**, and the inference about volume is
  the right instinct: the defence is not the count but that every number on the front page is derived and gated, and
  the gates are shown able to fail. This milestone is an instance — a third party found four things by reading that
  the gates did not catch, and three of them are now gated.

## Numbers

- **four stale front-page claims corrected**; **three new `counts.py` gates** (26 → 29 cases), each proved to fail
- `cohort_copies` / `cohort_shapes` / `imported` **derived**, not typed
- **`THIRD_PARTY.md` §0a** added; **M356 retracted by addition**; a retraction row in the log
- corpus unchanged: **391 / 390 exact**, census 3 665, coverage 63.3 %, `verify.py --full` **PASS**, audit 160/160
