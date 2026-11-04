# M308 — the small tail of the duplicate census: 11 more functions, and the 25-word group stuck at 22/25

The instruction was the 25-word ×4 group. It did not land — it is at **22 of 25**, with a residue that is a *branch
encoding* choice, not a transcription error. The rest of the small duplicate groups did land: **11 more functions
from five cohorts**, taking the total to **75 recovered / 74 byte-exact**.

## 1. The 25-word group: 22/25, and why

`ovl_008900e:0x80168654` (and its three identical copies). The draft needed three corrections, each informative:

| diff | cause | fix |
|---|---|---|
| the global's `+0x2a`/`+0x32` folded into one address (`0x800E115A`) | `extern u8 D_800E1130[]` lets gcc materialise the summed constant | declare a **struct** at the base, so the offsets stay displacements (`lh a2,42(v0)`) |
| the clamp compiled as an `if` with `li 0xf000` + `or` | the OR was promoted past 16 bits | a **ternary** in `u16` (`u16 r = (d < 2049) ? d : (u16)(d | 0xf000)`) gives the image's `ori` |
| — | — | **22/25** |

The last three words are one decision:

```
image  slti v0,a0,2049 ; bnez v0,+2 ; move v1,a0 (slot) ; ori v1,a0,0xf000
ours   move v1,a0      ; slti v0,v1,2049 ; beql v0,zero,+1 ; ori v1,a0,0xf000
```

Ours annuls the branch (`beql`) with the `ori` in the delay slot; the image uses a plain `bnez` with the copy in the
slot. Both compute the same thing — the residue is **reorg's annulment choice**, decided after register allocation,
which is the same class as `0x8007e590`'s conflict (M304–M306) and equally unreachable from the source: **twelve
shapes** were measured (ternary, if/else, two returns ×4, pre-computed OR ×3, casts, `0x800`/`2048`/`2049`
comparisons) and every one either reproduces ours (22/25) or loses the select entirely (16/25 or worse). Branch-likely
is not a flag in this `cc1` — `GENERATE_BRANCHLIKELY` is `mips_isa >= 2`, i.e. always on under `-mips2`, and the
choice is made in `reorg.c`'s annulment logic.

So the group stays **unregistered**, like `0x8007e590`. Recorded here so nobody re-derives it.

## 2. The small tail that did land

Of the remaining 45 duplicate groups, eight are ≤ 8 words. Six were usable; two are **mid-function fragments**
(`lh t4,0(a0); lh t1,0(a1); lh t5,2(a0)` with **no `jr ra`**) — a census artefact, not a function, and not
reconstructible as one. The six:

| cohort | words | copies | draft |
|---|---|---|---|
| `s32 f(void) { return 0; }` | 2 | 2 | `FUN_zero` |
| `void f(u8 *p) { p[622] = 0; }` | 2 | 2 | `FUN_clear622` |
| `p[4]=3; p[5]=0; p[6]=0; p[7]=0` | 6 | 2 | `FUN_set4` — **four** stores, the last in the `jr` delay slot |
| `void f(u32 a0, u32 a1) { callee(a1); }` | 7 | 2 | `FUN_wrapfwd` — a forwarder that **drops its first argument** |
| `void f(void) { callee(); }` | 7 | 3 | `FUN_wrapvoid` |
| | | **11** | **11/11 byte-exact** |

Two of these were my own misreadings, caught by the byte metric rather than by eye: the "three-store" setter has a
**fourth** store hiding in the delay slot (`sb zero,6(a0)` sits before the `jr`), and the forwarder is not
`callee(a0)` but `callee(a1)` — the image opens with `move a0,a1`.

## 3. Test plumbing made generic

The three hand-written family cases from M307 became **one case per family, generated from the fixture**: any
`source` with two or more entries is compiled once, compared against every member, and asserted. A new cohort now
needs no code in the probe at all — only fixture entries. Corpus **58 → 63 cases**, all passing.

## Numbers

- **recovered 64 → 75**, byte-exact **63 → 74**; the map, the ladder, the ranges and the call graph are re-derived
- 8 families measured, **63 of 63 probe cases pass**
- remaining: **89 functions in 44 duplicate groups** (the 25-word ×4 among them, at 22/25) and the 861 leaves
- the honest note from M307 still holds and now covers more: **34 + 2 + 2 = 38** of the 75 are trivial bodies
  (empty or single stores); the rest carry real structure

## Next

The 53-word ×4 group is the largest remaining duplicate prize, and the 44 groups' median is 2 copies at 7–20 words —
still worth more per draft than the 861 leaves, which need one draft each. The 861 leaves are where the volume is
but not where the *rate* is, and the rate is what the last three milestones moved.
