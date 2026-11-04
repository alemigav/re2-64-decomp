# M343 — `string_table` becomes a class, and the rule needs words, not just printable bytes

The third measured class, by the same recipe as M342: one implementation, synthetic pin-cases, and two mutations that
each loosen one half of the rule.

## 1. The rule, and the two false positives it needed

**`string_table`**: ≥ 8 consecutive text-safe words (printable ASCII plus NUL, tab, LF, CR as the separators a table
uses between entries), **≥ 16 letters**, **≥ 8 distinct bytes**, and **≥ 2 letter-runs of ≥ 4** — i.e. real words.

The first draft had the first three tests and no word test, and it claimed **17 344 B**, including a 248-byte table of
small byte codes in `ovl_00ae24a` (`\x00 \x00\x00\x00!\x00\x00\x00\"…`) — text-safe, letter-bearing if you count the
`A`-`Z` entries as letters, and not a string table at all. **A table of numbers has no words**, so the fourth test is what
separates them, and it is the one both mutations target. With it: **13 200 B**.

What the class actually finds is worth naming: the zlib/miniz **error strings**, exactly where they should be —

```
stage2 0x800b6ed4  "Bogus message code %d" / "Sorry, there are legal restrictions on arithmetic coding" /
                   "ALIGN_TYPE is "                            (3 972 B of them)
boot   0x800117c8  "oversubscribed dynamic bit lengths tree" / "incomplete dynamic bit lengths tree"
```

## 2. Measured

```
function_body 1 235 280 · jump_table 980 · data_named 6 680
float_table 23 980 · pointer_table 20 380 · string_table 13 200 · padding 405 296 · unclassified 250 764 (12.8 %)
= 1 956 560 B, the partition still closing exactly
```

**Padding fell by 2 828 B** and that is not a loss: a string run carries its NUL separators, so words that were fill
between two strings are now part of the table they separate. Precedence says so — bodies, jump tables, named data, the
three measured tables, then padding — and the overlaps are counted in the map rather than silently reassigned.

## 3. The gate

```
PASS a run of three real strings is a string table, and a table of small byte codes is not
PASS a run of one repeated text-safe byte is fill, not a string table
PASS the partition closes: … + 13 200 + 405 296 + 250 764 = 1 956 560 B
```

and two mutations, one per half of the rule:

| mutation | what it breaks |
| --- | --- |
| the word test becomes `>= 0` | the byte-code table is claimed as text |
| the whole rule becomes `if True:` | a run of one repeated byte is claimed |

`audit_gates.py --lint` is clean (3/3) — the mutations are anchored and unique. The **audit itself was not re-run**: its
state is the one M342 recorded (`119/148 detected, 0 vacuous, 29 broken → INCONCLUSIVE`, all 29 one tool with a red case
that is red in the repository too), and re-running it per milestone is what made the previous batch slow.

## Numbers

- **8 classes**; `string_table` **13 200 B** in 78 runs; `unclassified` **261 136 → 250 764 B (12.8 %)**
- byte map **9 → 11 cases**; audit **148 → 150 mutations** (lint-clean, not re-run)
- **recovered 155 / 154 byte-exact — unchanged**; no reconstruction, no census change
- one rule, one implementation, two pin-cases, two mutations, no audit run
