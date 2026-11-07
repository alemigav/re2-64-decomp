# M365 — the glued pairs split, the mis-extented re-measured, and two of M364's own errors

M364 withdrew 101 rung entries and this milestone was meant to repair them: split the bodies glued at a tail call,
re-measure the ones whose extent cut a function in half. It does that — and it also finds that **M364's rule was wrong in
two places**, both of which it corrects.

## 1. Two errors in M364's test

| error | consequence | fix |
| --- | --- | --- |
| a `jal` was treated as a tail jump | **13** withdrawn bodies that merely contain a **call** — a `jal` does not end a function, only a `j` does | restored; the test now separates opcode 2 from opcode 3 |
| coprocessor bodies were withdrawn | **36** were dropped although they are real functions — they are simply not **C** (M323/M354's class: `mtc0`/`mfc0` is not emittable by this cc1) | restored: they belong in the census as measured extents, and the refusal to reconstruct them is a *different* statement |

## 2. The rebuild, applied uniformly instead of patched

Rather than hand-edit the withdrawn set, the rung was **rebuilt from the pre-M364 fixture** with the corrected rule:

1. **cut** at every `jr $ra`+delay **and every `j`+delay** — a tail jump ends a control path just as a return does;
2. **merge** a segment that begins by restoring `ra`/`s*` from the stack into the body before it (a shared epilogue);
3. **extend** a segment while a branch target leaves it, reading on to the next return in the *image* rather than in the
   entry;
4. **drop** what still fails — and *only* what still fails.

```
241 entries  ->  264 candidate segments  ->  201 after resolving overlaps
                    41 bodies split at a tail jump
                    26 duplicates of registered reconstructions dropped
                    63 segments overlapped another segment (kept the earlier, dropped the later)
                    33 still had a branch past the end, 6 branched to themselves, 2 were epilogues
```

## 3. Two of the gates caught the rebuild's own mistakes

Worth recording, because they are the reason the numbers below can be believed:

- **The header sum** (`counts.py`): *"the 3902 body headers sum to the covered bytes plus the 72 B two extents share"*.
  The first rebuild added 153 segments that overlapped **provider ranges** and each other — the union was 4 752 B
  smaller than the sum of its parts. Comparing against `ranges.json` (the provider's own boundaries) rather than against
  a `code_index` the rebuild had just polluted, and then resolving overlaps within the rung, took 264 → 201.
- **The census case** (`compile_probe.py`) pinned `dupc["fragments"] == 2`, a figure its own note says moves. It now
  asserts the *partition* — `total == complete + fragments`, `groups == complete_groups + fragment_groups`, and
  `0 ≤ fragments < complete` — because a snapshot of a moving number is a gate that fails for the wrong reason.

## 4. State

| | before | after |
| --- | --- | --- |
| rung `extent_measured` | 119 | **201** |
| census `F0` | 3 578 | **3 665** |
| covered bytes | 1 223 008 | **1 238 112** |
| coverage | 62.5 % | **63.3 %** |
| `F1` | 3 459 | 3 459 (unchanged — nothing was *read* here) |
| recovered / exact | 391 / 390 | 391 / 390 |

The rung grew from 119 to 201 while the census grew by only 87, and that is the honest arithmetic of the correction: 36
coprocessor functions and 6 `jal`-only bodies came **back**, 63 overlapping segments were **dropped**, and 41 glued
pairs became **two entries each** instead of one wrong one.

`F1` did not move, and should not have: this milestone measured and repartitioned, it did not read anything. The
reading queue is unchanged in size and now *correct* — 201 entries, every one self-contained by construction.

## Numbers

- **41 tail-jump bodies split**, **36 coprocessor + 6 `jal`-only bodies restored**, **63 overlapping segments dropped**,
  **33 + 6 + 2 still unmeasurable** and named
- rung **119 → 201**, census **3 578 → 3 665**, covered **+15 104 B**, coverage **62.5 → 63.3 %**
- two gate defects found by the gates themselves: the header-sum union and a pinned fragment count
- probe **360/360**; `verify.py --full` **PASS**, audit 160/160; tree unchanged at **1 412 cases**
