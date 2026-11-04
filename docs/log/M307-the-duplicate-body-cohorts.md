# M307 — the duplicate-body cohorts: 48 functions byte-exact from three reconstructions

The instruction was to stop polishing three words of `0x8007e590` and spend the time where the leverage is. So
the first question was not "which function next" but **"how many functions is one reconstruction worth?"** — and
the corpus answers it: **148 of the 3 400 unmatched functions have a body that is byte-identical to another's, in 48
groups**. One proven shape registers every copy.

## The cohorts

| cohort | words | copies | result |
|---|---|---|---|
| **the empty function** — `03e00008 00000000` (`jr ra; nop`) | 2 | **34** | **34/34 byte-exact** |
| **the masked call** — `lhu a0,0x1aa(a0); move a1,zero; jal; andi a0,0xfff` | 9 | **11** | **11/11 byte-exact** |
| **the sequential store setter** — `sb a1,0(a0); sb a2,1(a0); jr ra; sb a3,2(a0)` | 4 | **3** | **3/3 byte-exact** |
| | | **48** | **48/48** |

Each was drafted once and matched **on the first compilation** — no iteration, no solver, no permuter. That is the
point of the cohort approach: the draft is small enough to read off the disassembly by eye, and the payoff is
multiplied by the number of copies.

Two details worth keeping:

- **The setter's last store is in the `jr ra` delay slot** (`a0870002` after `03e00008`). Our toolchain reproduces
  that automatically, which is the `-g` assembler fact (M281) doing its job on a four-word function.
- **`boot` is read from the cartridge at `0x1000` and the overlays from `assets/unpacked`** — the fixture's own
  `source` field says which, so `image_window(name)` now serves any of the 36 images. That is what makes overlays
  measurable without new plumbing.

## The measurement, not the claim

One compilation per cohort, N comparisons: `family_probe()` reads `fixtures/decomp/recovered.json`, groups the
entries by their `source` constant, and **requires the same reconstruction to match every member**. Three probe
cases carry it, so "all 34 copies" is checked on every run rather than remembered:

```
the empty function, 2 words: all 34 copies … BYTE-EXACT (34 of 34)
the sequential store setter, 4 words: all 3 copies … BYTE-EXACT (3 of 3)
the masked call, 9 words: all 11 copies … BYTE-EXACT (11 of 11)
```

## What this changes

- **recovered 16 → 64** in the code index; **byte-exact 15 → 63** (`0x8007e590` keeps its 226/229)
- `src/` republished from the fixture (`export_src.py`), ranges and the analysis ladder re-derived, map unchanged
  (all 48 were already inside the covered bytes — this adds *recovered* functions, not coverage)
- corpus **55 → 58 cases**, all passing
- **Honest split**: 34 of the 48 are empty functions. They are byte-exact and they are real corpus entries, but
  they carry no information about the game; the informative half is the other 14. Both are counted, and the README
  says which is which.

## Next, in the order the census implies

1. **The remaining duplicate groups** — 100 more functions in 45 groups, including a 25-word × 4 and a 53-word × 4;
   those need real reconstruction but each pays four times.
2. **The 861 leaves** — one draft each, no externs, no relocation asymmetry; sized by the census, this is where the
   volume is, and `family_probe` generalises to a batch driver as soon as the drafts exist.
