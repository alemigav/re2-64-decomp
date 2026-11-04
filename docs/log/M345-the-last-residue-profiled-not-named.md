# M345 — the last 84.5 KB resists a rule, so it gets a profile instead of a name

The recipe of M342–M344 is *measure, then name if a rule can be earned*. Applied to the last 84 500 B, the measurement
said no: **no rule covers more than 6 444 B of it**, and the largest runs are mixed data with a 256-byte alphabet. So this
milestone registers **no class**. What it registers is a gate on the measurement itself.

## 1. What was tried, and what each candidate covered

Of the 72 228 B in runs of 64 B or more (269 runs):

| candidate property | bytes covered |
| --- | --- |
| byte alphabet ≤ 16 | **6 444** (8.9 %) |
| ≥ 50 % of words are one repeated byte | 2 744 |
| one word is ≥ 50 % of the run | 2 720 |
| ≥ 90 % of words fit s20 | 880 |
| ≥ 90 % of words fit s16 | 792 |
| ≥ 50 % of words are zero | 592 |
| ≥ 90 % of words fit u16 | 476 |

Every one of these is a *rule that could be enforced and mutated* — and every one would be naming 1–9 % of the residue
while implying the rest is something else. **None is earned**, and `int_table` in particular is refuted: only 12 % of
these words fit a u16 or sign-extended s16, so the name that looked obvious from a distance is wrong up close.

## 2. What the runs actually look like

`classify_image.py --residue` prints the profile, so the next session reads the bytes instead of guessing:

```
269 unclaimed run(s) of 64 B or more, 72228 B; the best single property (alphabet <= 16 bytes) covers 6444 B
image        address     bytes words  top word  share   u16   s16   s20 alph     H
stage2       0x8010c284   5820  1455 0x00000000    25%    25%    25%    50%   56   2.8
stage2       0x80126c80   2368   592 0xffffffff     5%     0%     5%    35%  256   4.8
stage2       0x801105fc   1748   437 0x00640332     7%    78%    78%    78%  110   3.9
ovl_00b2d7a  0x80162630   1260   315 0x00000000    32%    32%    32%    32%   16   2.8
boot         0x80003220   1208   302 0x8e03001c     5%     4%     0%     7%   78   4.5
```

Three of the largest are **structured, not dense** — a 25 %-zero run at 2.8 bits/byte, a run whose words are 78 % u16, a
run with a 16-byte alphabet — which is exactly the shape of packed game data (coordinate, animation or ID tables) whose
*record layout* we do not know. Naming them by their density would hide that; the profile shows it.

## 3. The gate

The claim is the population and the refutation, and both are asserted:

```
PASS the 72,228 B that no rule claims is PROFILEd, not named: 269 run(s) of 64 B or more, and the best
     single property it could be given (alphabet <= 16 bytes) covers only 6,444 B — so this milestone
     registers no class, which is the honest outcome when the rule cannot be earned
```

and one mutation, because a profiler that shrinks its own population would make "no rule is earned" true for the wrong
reason: *the residue profiler quietly ignores runs under 6.4 KB* (`< min_bytes` → `< min_bytes * 100`).

## Numbers

- `unclassified` **84 500 B (4.3 %) — unchanged**: 72 228 B in 269 runs of 64 B+ (profiled) and 12 272 B in 933 runs under
  64 B that are not beside a body
- **12 classes** (no new one), byte map **15 cases** (unchanged), probe **133 → 134 cases**, audit **154 → 155 mutations**
  (lint-clean, **not run** — parked as agreed)
- **recovered 155 / 154 byte-exact — unchanged**
