# M362 — 85 functions the byte map was calling data: the measured-extent path, widened once

M361 admitted two functions that had reconstructions. The third function in that run — `0x80005134`, 33 words — has no
C from anybody, and it belongs on the `measured_extents.json` path, which claims an **extent** and never that the body
is understood. Widening that path for one function, with the rule written down, admitted **85**.

## 1. What the path is for

`fixtures/decomp/measured_extents.json` (M340/M341) carries functions that have a **measured extent and no
reconstruction**: the census gains the function, the byte map gains the bytes, `src/` publishes a disassembly listing,
and the ladder keeps them out of F1 — `extent_measured` is a rung, not a claim of understanding. 188 entries before this
milestone, every one of them measured inside a byte-map run classed `unclassified`.

`0x80005134` is the same thing in a run classed `enclosed_data`. The rule that measures it is the project's own,
`extent_scan.scan()`: **a return is `jr $ra` plus exactly one delay slot, and a start is the region start or the word
after a return's delay slot.** Applied to that 142-word run it returns nine functions, six of which the census already
had, the two M361 admitted, and this one.

## 2. The rule, widened once and bounded

Running the same scanner over **every** run the byte map does not call `function_body` produced **541 unclaimed
return-delimited candidates**, 8 178 words. Admitting by the scanner alone would have been wrong, and the rejections are
the interesting part:

| rule | rejected | why |
| --- | --- | --- |
| `dense_data` runs | **58** | packed tables: `0x03e0` and `0x0008` are two `u16` values, so a table imitates `jr $ra` — and the candidates there are 200–434-word "functions", which is what a table looks like when you split it at coincidences |
| shorter than 4 words | **364** | nearly all two words: once again the empty function matching wherever a function returns |
| starts with a branch, jump or `nop` | **23** | a function does not open with `beq`/`bne`/`j`/`jal`, and `nop; nop; jr $ra; nop` is filler that the return rule splits cleanly |
| `referenced_data` runs | **11** | a run the code *materialises an address into* is a table; a function inside it is a contradiction |
| **admitted** | **85** | `enclosed_data` 44, `gap` 41 — 1 565 words |

The two admitted classes are the two that mean *between code*: `enclosed_data` is bounded by `function_body` on both
sides, and `gap` is under 64 B between two bodies. Both are places where the classifier had already noticed structure
and had no artifact to name it with.

## 3. What moved

| | before | after |
| --- | --- | --- |
| `F0` (census) | 3 605 | **3 690** |
| covered bytes | 1 236 228 | **1 242 488** (+6 260 = the 1 565 words) |
| rung `extent_measured` | 175 | **260** |
| `F1` | 3 430 | 3 430 — unchanged, and that is the point: none of the 85 is claimed as understood |
| `F2` | 3 362 | **3 405** |
| `function_body` | 1 236 228 | **1 242 488** |
| `enclosed_data` | 52 496 | **47 496** |
| coverage | 63.2 % | **63.5 %** |

`F2` rising by 43 is the one figure that needs a sentence of honesty: F2 counts functions whose call targets all
resolve, and a 4-word leaf with no calls resolves trivially. The ladder is not wrong — a leaf *is* fully resolved — but
"3 405 resolve every call target" now includes 85 functions whose bodies nobody has read, and any headline quoting F2
has to say so. F1 is the figure that answers "how much is understood", and it did not move.

## 4. What is not admitted, and why the number is 85 and not 141

M360 counted 144 candidate segments with a cruder test (return-delimited, ≥6 words, inside a non-body run). This
milestone re-measured with the real scanner over **all** non-body runs and got 541 candidates — a bigger number from a
weaker rule — then applied four rejections to get back to 85. The difference between 144 and 85 is not a correction of
M360: M360's figure was a *sizing* of the question, and this is the subset that survives a rule strict enough to write
down.

The 58 `dense_data` candidates are the largest rejection and the most important: they include four "functions" of
200–434 words in stage2, which would have added 1 400 words of packed table to the census as code. A census that
admits those is worse than one that misses a function.

## Numbers

- **+85 functions** admitted on the measured-extent path, 1 565 words, `enclosed_data` 44 + `gap` 41; **456 rejected
  in three classes with their reasons** (58 packed-table runs, 364 shorter than four words, 23 branch/nop openings,
  11 table runs)
- census **3 605 → 3 690**; covered **+6 260 B**; rung **175 → 260**; `F1` **unchanged at 3 430**; `F2` 3 362 → 3 405
- byte map **partition still closes on 1 956 560 B**; `enclosed_data` **52 496 → 47 496**, `gap` 4 772 → 3 488,
  `fill` +24, `unclassified` **440 B (0.0 %)** unchanged
- `0x80005134` itself: 33 words, measured by the project's own return rule, published as a listing
- `verify.py --full` **PASS**, audit **160/160**, 0 vacuous, 0 broken; tree **1 383 cases**
