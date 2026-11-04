# M339 — the extents inside the code regions: 189 functions measured, and the rule defect that hid three of them

M338 ended with a lead — nine dense stage2 regions, 1.5–6 KB each, that decode as code — and a promise that turning them
into census functions needs *extents*. This milestone measures them: **189 functions, 23 876 B across 75 regions**, from
a committed, self-tested scanner. It also found that M338's own rule was wrong in a way that hid its three biggest
regions, which is the more useful finding.

## 1. The extent rule, and why it counts returns instead of prologues

`tools/extent_scan.py` (new, `--self-test` 5 cases, now a repository suite):

- a **return** is `jr $ra` (`0x03E00008`) followed by exactly one delay-slot word, and a function **starts** at the
  region start or at the word after a previous return's delay slot. Nothing else creates a start — the M320 rule: a
  `jal` target is *not* evidence of a start, because a truncated extent looks the same;
- a candidate is **rejected**, never silently sized, when it is a lone `jr ra` with no delay slot (a function needs both
  words) or when a tail survives after the last return with no `jr ra` of its own;
- a `jr` through any register other than `$ra` is a **tail jump** — reported separately, not counted as a return and not
  sized, because the function does not come back and a human still has to read it.

**Why returns and not prologues:** a prologue heuristic (`addiu sp,sp,-N` first) fails on leaf functions, on
hand-written assembly, and on the boot image's own style — the project has been bitten by exactly that. A return is
unambiguous in the bytes. The cost is stated rather than hidden: a region whose first function begins mid-way is reported
as one long rejected candidate instead of being silently mis-split, and 13 such candidates are listed in the fixture.

## 2. What it measured

```
189 function(s), 23 876 byte(s) measured across 75 region(s)
13 candidate(s) rejected for want of a return, 9 `jr` tail jumps reported separately
0 of them overlap a census function
```

The zero is by construction — the regions are `unclassified` runs and therefore disjoint from every body range — and it
is **asserted**, not assumed: the probe case walks all 189 extents against `fixtures/decomp/ranges.json` and fails if any
overlaps. The fixture is `fixtures/decomp/measured_extents.json`, written by `--write`, carrying the summary, the extents
and the rejections.

## 3. The rule defect: M338's three biggest regions were rejected by an accident

M338's code test required **every** `j`/`jal` target to land in the cartridge window. The three largest regions failed it
— and they should not have: `0x80022a1c` is 6 084 B whose first words are `addi $12,$zero,0x1000`, `lw $24,0($11)`,
`jal 0x80001fd8`, `mfc0 $11,$12`, `jr $ra`. What fails the "all" test is that a real code region **carries embedded
data** — a switch table sits inside it — and a table word that happens to have opcode 2 or 3 decodes to a nonsense jump
target (`0x84001150` and friends).

Two things came out of that, and the second is the one to keep:

1. The test is now **≥ 90 %** of `j`/`jal` targets in-window, which keeps what it was for — 408 of 1 574 bucket runs hold
   a stray `0x03E00008`, and data fails the opcode-diversity tests anyway — while admitting code that carries tables.
2. **The rule existed twice** — a copy inside `unclassified_report()` and another inside the scanner — and the two had
   already drifted: one demanded *all* targets in-window, the other was the same by luck. It is now **one function**,
   `classify_image.code_run_evidence()`, and both callers read it, so the next threshold change cannot land in one of
   them. That is the M289 lesson (one reader, two projections) applied to a *rule* rather than to a fixture.

The bucket totals did not move — 28 764 B in 75 runs either way — because the runs that pass are not the three that fail.
So the honest statement is: M338's headline number was right, its *reason* for excluding those three was an accident, and
the three remain excluded on evidence (their in-window fraction is well under 90 %) rather than by a bug. They are
code-with-embedded-data and need a smarter splitter — named here as the next target instead of quietly dropped.

## 4. What the census needs, and why it did not get it today

`export_src.py` **can** add functions the provider never claimed — it does so for `recovered.json` entries — but it
requires a **reconstruction**: it publishes `src/<image>/FUN_xxxxxxxx.c` from a `*_SOURCE` constant in the tool. These
189 functions have extents and no C, so the census channel they need is the one the project has been missing since M323:

> a fixture of **measured-but-not-reconstructed extents**, with a status of its own, consumed by `export_ranges.py` and
> `export_src.py` so the census and the coverage fixture both see them.

That is a projection change with a status-ladder question (a fourth rung weaker than `written`), and it also unblocks the
**four non-C extent corrections** (`0x8004276c`, `0x80042824`, `0x800421b4` at 46 words and `boot:0x80000dd4` at 95) that
have been waiting for exactly this channel. It is a milestone, not a line — so this one delivers the measurement, the
artifact and the gate, and says so.

## Numbers

- **189 functions / 23 876 B / 75 regions** measured, **0** overlapping the census, 13 rejections and 9 tail jumps
  reported; `fixtures/decomp/measured_extents.json` committed
- `tools/extent_scan.py` added (**5/5** self-test) as a repository suite: tree **74 → 75 suites**, **1 122 → 1 128
  cases** (34 runnable suites / 307 cases, 41 gated / 821), **tools 101 → 102**
- `classify_image.code_run_evidence()` is now the single copy of the code rule; the bucket's own numbers are unchanged
  (28 764 B / 75 runs)
- **recovered 155 / 154 byte-exact — unchanged**; nothing registered, because an extent is not a reconstruction
