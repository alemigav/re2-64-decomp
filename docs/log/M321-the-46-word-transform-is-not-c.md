# M321 — `0x8004276c` cannot be written in C, and the test that proves it

The target was the corpus's highest-caller unmatched function: 46 words, **96 callers**, which the index has called a
3-word stub. It cannot be reconstructed in C, and the proof is a three-command toolchain experiment rather than an
opinion. That experiment is now a screen rule.

## 1. What the function is

`stage2:0x8004276c` (and its two siblings) is a **negated-free 3×3 fixed-point transform**:

```
out[0] = (s16)(v[0]*m[0] + v[1]*m[1] + v[2]*m[2])
out[1] = (s16)(v[3]*m[0] + v[4]*m[1] + v[5]*m[2])
out[2] = (s16)(v[6]*m[0] + v[7]*m[1] + v[8]*m[2])
return out;
```

The arithmetic is 64-bit: `dmult` per product, `mflo` for the low word, `dadd` to accumulate, and `dsra rd,rd,0` to
sign-extend each partial sum — with `sh` stores of the low half, no stack frame, and every value in a temporary.

## 2. Why C cannot produce it

Our `cc1` never emits a 64-bit-ISA multiply. Measured on a two-line `long long` multiply:

| flags | emitted |
|---|---|
| `-mips2 -mcpu=r4300` | `multu` + `mfhi` + `mflo` (32-bit register pair) |
| `-mips3 -mcpu=r4300` | same |
| `-mips3 -mgp64` | same |
| `-mips2 -mgp64` | same |
| `-mips3 -mgp64 -mabi=64` | same |

**No flag produces `dmult`.** So a body containing `dmult`/`dadd`/`dsubu`/`dsra` was *not* produced by this compiler
from C — under any configuration — and it is hand-written DSP assembly. The same test settles the other enlarged
extents:

| entry | census → true | why it is not C |
|---|---|---|
| `stage2:0x8004276c` | 3 → 46 w | 19 MIPS III 64-bit ops |
| `stage2:0x80042824` | 3 → 46 w | same family (`sw` variants) |
| `stage2:0x800421b4` | 3 → 46 w | same family |
| `boot:0x80000dd4` | 5 → 95 w | CP0 access + 14 writes to `$at`/`$k0` |
| `boot:0x80000518` | 2 → 32 w | a hand-written spin: `b .` with `daddiu a0,a0,1` in the slot |

## 3. The rule

`leaf_screen.py` gained a sixth rule: **any MIPS III 64-bit SPECIAL op** (`dmult`, `dadd`, `dsubu`, `dsll`/`dsra` and
their 32-variants) rejects the candidate, because this compiler cannot emit one from C. The self-test carries the case
(`dmult` on a synthetic word) — **12 cases**.

It changes nothing at 6-8 words today (no unmatched body there contains one), which is itself the useful answer: the
pool is **10**, and those 10 are exactly the entries M319 classified as six residues and four hand-written routines.

## 4. What this settles

**The corpus's highest-caller unmatched function is hand-written assembly, and so are its two siblings.** For 240
milestones the index has recorded a 96-caller DSP transform as a three-word stub; it is now recorded correctly as
**not C**, with the mechanical test that says so. Nothing is registered: recovered stays **129 / 128 exact**.

**A follow-up found on the way and not chased:** the code immediately after that spin (`0x80000520`, 30 words) is a
boot initialiser — clear the BSS from `0x800138A0` to `0x80028A80`, then `FUN_800004f0(0)`, `FUN_800070c0()`, a flag
test at `0x80000300` that spins if clear, then `FUN_80000598()` — and **it is not a census function start at all**.
That is a missed-function candidate, which is its own investigation.

## Numbers

- compile probe **116 cases** unchanged (116/116 pass); leaf-screen suite **11 → 12 cases**
- tree **1 102 → 1 103 cases** (805 gated, 298 runnable); recovered **129 / 128 exact** — unchanged
- `tools/leaf_screen.py`: the 64-bit rule + its self-test case
