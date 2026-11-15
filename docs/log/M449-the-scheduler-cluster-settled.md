# M449 — the scheduler cluster settled: one body, not a class; and `#nop` is an assembler difference

The open question from M448 was whether `boot:0x800048e8` — the body `-fno-schedule-insns2` reproduces exactly — was the
first of a cluster. It is not, and the way it fails is worth more than the answer.

## The cluster: 1 of 17

Every remaining gap-1 body compiled under the profile and under the two scheduler-off variants, comparing **aligned**
identity:

| | bodies closed |
| --- | --- |
| `-fno-schedule-insns2` closes, profile does not | **1** (`boot:0x800048e8`) |
| `-fno-schedule-insns2` makes it **worse** | **15** |
| unchanged | 1 |

So the scheduling class is a **singleton**, and the flag is harmful to the population it was proposed for — consistent
with M440's control measurement (it keeps 40 of 120 exact bodies).

## `stage2:0x80073f28` — 15 words → **15 of 15**

The image masks the **second** argument to 16 bits (`andi a1,a1,-1`) after the add; the draft passes a full word. The
draft already carried `(uint)(ushort)` on the *fourth* argument and was missing the same truncation on the second:

```c
FUN_8004ac04(0, (ushort)(param_1[1] + 0x300), *param_1, (uint)(ushort)param_1[2] << 0x10);
```

Applying the cast to `param_1[1]` before the add instead reaches only 14 of 15 — the truncation is on the **sum**.

## `stage2:0x80033024` — the `#nop` wall, and why binutils 2.42 cannot simply replace 2.7

One word: the image has a `nop` between `subu` and `mult`, and everything after shifts by one. cc1 does not emit a
`nop` there — it emits the pseudo-instruction **`#nop`**, which the *assembler* is supposed to expand into a hazard slot
when the CPU needs one.

Measured: **binutils 2.7's `as` produces 0 nops from it. binutils 2.42's `as` produces exactly 1 at `-mips2`** — the
image's own count. So the original build's assembler expanded `#nop` and the pinned one does not.

That is a real toolchain difference, and it cannot be adopted as the profile because it fails its control: over 22
already-exact bodies, **2.42 keeps 13 identical and makes 9 worse** (one loses 21 of 100 words). A change that damages
41 % of the exact corpus to fix one body is not a profile.

## `ovl_00ae24a:0x80165670` and `ovl_00b321e:0x801623e4` — one class, two bodies

Both differ in the **order of the prologue stores**: the image saves the last callee-saved register before the `lui`
that starts the body, and we save it after `sw ra`.

```
image   sw s2,24(sp) ; lui v1,0x8016 ; sw ra,28(sp)
ours    lui v1,0x8016 ; sw ra,28(sp) ; sw s2,24(sp)
```

`-fno-schedule-insns2` makes both **worse** (21 against 22, 25 against 27), so this is the same scheduling family as
`boot:0x800048e8` — a real class with two members, and no lever inside the pinned profile.

## What this settles

The four diagnoses split cleanly: **one closed** (a type truncation, source-level), **three in the scheduler/assembler
family** (a hazard slot and two prologue store orders) — which is now a *named* family with **three bodies** and a
measured cause on each side of it: cc1's instruction order and the assembler's `#nop` expansion.

Only the first is reachable by writing C. The other three need a different toolchain, and the best available candidate
(binutils 2.42) is refuted by its own control.

## Numbers

- scheduler cluster: **1 of 17** closed by `-fno-schedule-insns2`, 15 made worse — **not a cluster**
- `stage2:0x80073f28` **15 of 15**, banked; `recovered` **671 → 672**, byte-exact **670 → 671**
- `#nop`: binutils **2.7 → 0** nops, **2.42 → 1** (the image's count); 2.42 keeps **13 of 22** exact and **damages 9**
- two prologue-order bodies named, both made worse by the scheduler flag
- probe **694/694**; tree 95 suites / **1841** cases
