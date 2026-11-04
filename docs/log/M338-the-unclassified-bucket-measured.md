# M338 — the 330 KB `unclassified` bucket, measured: 8.7 % of it is code, 70 % still has no name

A different direction: not another function, but the byte map's own residue. The bucket is **330 176 B, 16.9 % of the
image bytes**, and until this milestone its entire description was a *policy* — "reported, never renamed to `data` on a
hunch". Now it has a decomposition, a committed measurement mode, and a probe case.

## 1. Which part of it is code? — 8.7 %

The first question a bucket like this raises is whether the function census missed things, and the answer needed a rule
strong enough that data cannot satisfy it. A `jr ra` word is `0x03E00008`, and **408 of the 1 574 runs contain one** —
`77 252 B` — so "contains a return" is worthless as evidence. Four tests together are not:

- a `jr ra` present;
- every `j`/`jal` target inside the cartridge's address window (`0x80000000..0x80800000`) — a *per-image* test was
  wrong, because stage2 calls boot code legitimately, and that mistake rejected 24 KB of real code before it was fixed;
- **≥ 8 distinct opcodes** in the run;
- **no single opcode over 40 % of the words**.

Result: **28 764 B in 75 runs (8.7 %)**. The dense end is unambiguous — nine stage2 regions of 1.5–6 KB with 15–26
distinct opcodes and 1–13 returns each:

| region | bytes | `jr ra` | distinct opcodes |
| --- | --- | --- | --- |
| `stage2:0x80022a1c` | 6 084 | 7 | 25 |
| `stage2:0x8001c66c` | 4 436 | 10 | 26 |
| `stage2:0x8001df0c` | 4 388 | 6 | 24 |
| `stage2:0x800b2704` | 3 900 | 13 | 22 |
| `ovl_0072610:0x80184058` | 2 752 | 8 | 18 |
| … five more ≥ 1.4 KB | 9 928 | | 15–26 |

`0x80022a1c` decodes as ordinary MIPS on inspection — `addi`, `lw`, `lhu`, `jal 0x80001fd8`, `mfc0 $11,$12`,
`jr ra` — so **the census is missing code**, not mislabeling data. That is a lead with addresses attached, and it is
explicitly *not* a registration: turning those regions into functions needs extents and the leaf screen, which is its
own milestone.

## 2. The rest: what it is, and what it is not

| measured kind | bytes | share | runs | the evidence |
| --- | --- | --- | --- | --- |
| **structured, unnamed** | **230 824** | **69.9 %** | 373 | ≥ 64 B, and none of the tests below fire |
| float tables | 41 000 | 12.4 % | 29 | ≥ 8 words, ≥ 95 % IEEE-sane, ≥ 90 % ascending |
| code | 28 764 | 8.7 % | 75 | the four tests in §1 |
| small residue | 16 832 | 5.1 % | 847 | < 64 B, none of the above: inter-function slack |
| pointer tables | 11 572 | 3.5 % | 92 | ≥ 8 words, ≥ 80 % of them in-image addresses |
| short fill | 1 184 | 0.4 % | 158 | a single repeated `0x00`/`0xFF` under the padding law's 16-byte floor |
| **total** | **330 176** | | **1 574** | |

Two of these are *provable*, and the proof is why they are named here rather than in the map: the float table at
`stage2:0x800f57f0` runs `0.0499, 0.0996, 0.149, 0.199, 0.249…` — ascending IEEE-754 with no gaps, 4 496 words of it —
and the pointer tables are runs whose words are simply addresses inside the same image. Everything else is honest: **231
KB of the cartridge has no name yet**, in 373 runs, and 59 runs ≥ 1 KB account for 195 KB of the whole bucket.

The bucket also shrinks in the other direction: 1 005 of the 1 574 runs are under 64 B and account for 5.5 % — they are
the slack *between* function bodies (543 runs, 57 620 B, sit directly between two bodies), which is a classification
question the padding law already answers for runs ≥ 16 B and deliberately does not answer below it.

## 3. What was built, and what it refuses to do

`tools/classify_image.py` gained **`--unclassified`** and an `unclassified_report()` function that recomputes this
decomposition from the cartridge and the committed map. The rules and their thresholds are stated in the docstring —
including why each threshold is where it is — because a threshold that renames bytes is a claim.

**It does not rename anything.** `byte_map.json` still lists five classes, and the bucket still says "no artifact names
it". Naming `float_table` or `pointer_table` in the map needs a rule the classifier can enforce, a mutated self-test
that proves the rule can fail, and therefore its own milestone; what this one delivers is the measurement that would
authorise it. The gate added is a probe case, and it asserts the decomposition rather than describing it:

```
PASS the 330,176 B `unclassified` bucket is measured, not renamed: code 28,764 B in 75 runs
     (8 distinct opcodes, in-window jump targets, 1+ `jr ra`), float tables 41,000 B in 29 runs
     (monotone IEEE), pointer tables 11,572 B, and 230,824 B still unnamed — which is the honest core of it
```

## 4. What the flight bought

- A **policy** became a **partition**: 16.9 % of the image is now described by evidence in five parts, not by one
  sentence about hunches.
- A **lead**: the census misses code, and the nine dense regions are named with addresses and returns counted.
- A **negative result that closes a worry**: the bucket is *not* hiding the corpus. At 8.7 % it cannot be where whole
  subsystems went — which is the question that made the bucket worth flying at.

## Numbers

- **330 176 B / 1 574 runs** decomposed: 230 824 unnamed, 41 000 float tables, 28 764 code, 16 832 small residue,
  11 572 pointer tables, 1 184 short fill
- `classify_image.py --unclassified` (new, cartridge-gated); probe **130 → 131 cases (131/131)**; the map and its
  6/6 checks are unchanged
- **recovered 155 / 154 byte-exact — unchanged**; nothing registered, and nothing renamed
- tree **74 suites / 1 122 cases** (302 runnable, 820 gated)
