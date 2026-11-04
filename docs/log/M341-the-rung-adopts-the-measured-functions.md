# M341 — the rung's second customer: 187 functions the census never had, and the bucket's code goes to zero

M340 built the rung for extents that the bytes give and no C explains. Its second customer is bigger than its first:
the **188 functions M339 measured** inside byte-map regions no artifact names are now **census functions**, published as
disassembly listings. The unclassified bucket loses all of its code, and two projections that had never moved together
before now do.

## 1. The rung handles *additions*, not only corrections

`recovered.load_additions()` returns the extents the scan measured; `export_src.py` publishes them. The difference from a
correction is that there is **nothing to publish**: no provider record (the address is not in the decompile index), no
pseudocode, and no C. So the body of each new `src/<image>/FUN_xxxxxxxx.c` is the **disassembly listing** — the words of
the measured extent, decoded — under a header that says exactly what it is:

```
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no
 *   artifact names (M339); no C and no provider record exists
 * provider none: this address is not in the decompile index, so there is no pseudocode and no provider hash
```

That is the honest form of "a function we know the shape of and not the meaning of". The file exists so the census, the
byte map and the coverage union can all name the bytes; it claims nothing more.

```
                            before      after      delta
functions                   3 416      3 603      +187
coverage (union)        1 212 068  1 235 844   +23 776 B  (63.2 %)
byte map function_body  1 211 412  1 235 280   +23 868 B
byte map unclassified     329 364    305 496   -23 868 B  (15.6 %)
ladder F0                   3 416      3 603      +187
rung `extent_measured`          5        192      +187
```

(The union gains 23 776 while the map moves 23 868: 92 B of the measured spans sit inside bodies that were already
covered — a union is what coverage means, and the two numbers differ by exactly that.)

## 2. Why the bucket's code is now zero

`classify_image.py --unclassified` reports **code 0 B in 0 runs**, and that is the milestone's cleanest confirmation:
the 74 code-like regions it found in M338 *are* these functions. The bucket keeps what it cannot name —

```
structured      234 860 B   378 runs   (76.9 %)
float tables     41 000 B    29 runs   (13.4 %)
small residue    16 852 B   848 runs   ( 5.5 %)
pointer tables   11 572 B    92 runs   ( 3.8 %)
short fill        1 212 B   162 runs   ( 0.4 %)
TOTAL           305 496 B  1 509 runs
```

— and the code it used to hold is in the census with its extent measured. **A bucket that loses a class to a
measurement is the only kind of bucket-shrinking this project allows.**

## 3. Two things adoption fixed that nothing else could

**Callers into the new functions were counted as unknown.** `export_src` filters a body's callees against the corpus of
provider function starts; a `jal` into a measured function was therefore `callees_unknown` on the caller, while the call
graph — scanning bytes — resolved it to a node. **22 nodes disagreed** with a byte scan that was right. Adding the
measured starts to the corpus set fixed it, and the ladder moved with it: **F2 3 324 → 3 343 (+19)**, because nineteen
functions' call targets now resolve. None of them got a body; they got a *name for their target*.

**The rung's own detector now reports its numbers again.** The M339 extent case had to move from "189 functions, 23 876
B, 75 regions, and they are new ground" to "**188 functions, 23 868 B, 74 regions, and they are adopted**" — one region
fewer because M340's corrections moved 812 B out of the bucket and shrank a run below the code threshold. The scan is
not a constant; it is a measurement of a moving partition, which is why its figures live in the fixture and not in prose.

## 4. What is still not named

**305 496 B (15.6 %)** remains `unclassified`: 234 860 B "structured" with no test firing, 41 000 B of monotone IEEE
float tables, 11 572 B of in-image pointer tables, and 31 KB of slack and fill under 64 B. The float tables and pointer
tables are *provable* and still not classes — giving them a class needs a rule the classifier can enforce and a mutation
that proves the rule can fail, which is the same standard this rung just met for extents.

## Numbers

- **187 functions adopted** (188 measured, one coincided with a provider address and was skipped), 23 868 B of listings
- corpus **3 416 → 3 603 functions**, coverage **63.2 %** (1 235 844 of 1 956 560 B), byte map `unclassified`
  **329 364 → 305 496 B (15.6 %)**, `function_body` **1 211 412 → 1 235 280 B**
- ladder **F0 3 603 / F1 3 411 / F2 3 343** (F2 +19: calls into the newly named functions now resolve),
  `extent_measured` **192**
- **recovered 155 / 154 byte-exact — unchanged.** Nothing here is a reconstruction; 187 functions gained an extent
  and a listing, and the project's headline stays honest
- probe 133/133, tree **75 suites / 853 fast cases**, `src/` +187 listing files, ratchet re-baselined (registry + `src/`)
