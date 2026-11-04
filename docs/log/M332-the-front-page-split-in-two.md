# M332 — the front page split in two, and the eight stale numbers it had been carrying

`README.md` had grown to 430 lines doing two jobs at once: a front page for a stranger, and a reference manual for
someone already inside the project. Split, with the short page keeping the job of the first and a new
`docs/README-extended.md` taking the second. The rewrite also surfaced **eight claims that no longer matched the
registry** — none of them caught by a gate, because none of them was a number the gates had been taught to read.

## 1. What was stale, and why nothing noticed

| claim | was | measured |
| --- | --- | --- |
| cases that need no ROM, on the front page | "the other **806** need your dump" | **807** (298 + 806 ≠ 1 105) |
| the same figure in the quick start | "298 cases run, **805** SKIP" | **807** |
| the same figure as a bullet | "**286** of **1 022** verification cases" | **298** of **1 105** |
| functions reconstructed, in the matching-build section | "**fourteen** functions have been reconstructed" | **sixteen** in the table beneath it |
| the script VM's instruction lengths, in the format table | "**17** lengths" | **18** — and the same page's prose said 18 |
| mutation audits, in the produced list | "**48** mutation audits" | **146** |
| the phase table | ended at **P17 (M301–M307)** | 24 milestones (M308–M331) in **no row at all** |
| commits quoted in the no-ROM section | "not in any of its **200+** commits" | 400+, and the exact number rots by construction |

The pattern in the first three is the interesting one: **a derived number that a gate reads is safe, and the same
number quoted a second time in prose is not.** `counts.py` asserted the gated-case figure once — the sentence it was
taught to find — while three other sentences on the same page quoted it wrongly. That is the argument for the split
being *also* a subtraction: the front page now contains fewer places to say a number twice, and the ones that remain are
mostly the ones the gate reads.

The phase-table hole was the known debt (carried since M308 as "P18 still owed") and it was not cosmetic:
`progress_map.py` parses those rows, so the record panel stopped at M307 and under-reported the entire singles arc by 24
bars. Adding P18 fixed the picture rather than the prose — the panel now reads M0–M331.

## 2. The split, and the constraint that shaped it

- **`README.md`** — what it is, the result in one table, the byte-for-byte proof, the 60-second quick start, how to
  verify it, milestones, the progress map, the corpus with its qualifier, what is decoded, the jargon, the layout, the
  no-ROM/legal summary, and a pointer table to everything else. 282 lines instead of 430.
- **`docs/README-extended.md`** — the technical companion: the numbers with the qualifiers they need, the corpus and its
  geometry, the full toolchain profile, all sixteen recovered functions, the `vector_installer` ledger, the long
  produced-list, the format reference, the verification architecture, the rebuild recipe, where the work stands, the
  references and the full legal section.

The constraint: **a document a gate reads cannot be restructured freely.** `counts.py` matches twelve sentences in
`README.md` by regular expression, `progress_map.py` parses the phase table, and `audit_gates.py` copies the file into
every audit sandbox because `counts.py` reads it. So the split was designed around the patterns: those twelve sentences
were carried across **verbatim**, and everything moved was prose the gates do not read. Two of them had to be *repaired*
in place rather than moved, which is why they are in §1's table.

## 3. The one gate change, and what it cost

The split is itself a claim — that the short page points at the long one — so it gets markers like any other structure
worth not losing: three entries in `check_markers.py` (the companion's identity, the qualifier section, and the front
page's pointer to it). Two consequences, both measured:

1. **The self-test bed had to be derived rather than hard-coded.** It built its sandbox from the handover and the log
   only, so a marker naming a third document made four self-test cases fail for reasons unrelated to what they test
   (11 of 15). The bed now derives every marked file from `MARKERS`, so a fourth document arrives complete and each case
   perturbs only what it is about. 15 of 15 again.
2. **Three markers is a case-count change, and the case count is quoted in five files.** Total cases **1 105 → 1 108**,
   runnable **298 → 301**: `README.md`, `docs/handover.md`, `tools/ci.sh`, `.github/workflows/acceptance.yml` and the
   ratchet registry all carried the old pair, and `ratchet.py --write` re-baselined 74 registered counts. This is the
   third instance of the same lesson — *a count lives in more than one file* — and the cheapest one yet, because
   `counts.py` named all five in one run instead of one at a time.

## 4. What the rewrite was for

A front page is not a shortened manual; it is an argument that the work is worth ten minutes. So the short page now
carries the four things a stranger needs — what it is, what it proves, how to check it, where the honest limits are —
and hands the reference material to the companion, which is allowed to be dense because it is read on purpose. The claim
that most needed saying plainly is the corpus composition: **130 recovered, 129 byte-exact, of which 16 were
reconstructed by hand, 55 are singles and 59 are copies of eight proven shapes (34 of them the empty function)** — read
the 16 as the measure of what was understood, and the extended page carries the table.

## Numbers

- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree **74 suites / 1 108 cases** (807 gated, 301 runnable), **101 tools**,
  **markers 25**, milestones **333 numbers / 277 rows / 56 gaps / 257 notes**
- `README.md` **430 → 282 lines**; `docs/README-extended.md` **new, 340 lines**; the phase table now ends at **P18
  (M308–M331)** and the progress map's record panel covers **M0–M331** instead of M0–M307
