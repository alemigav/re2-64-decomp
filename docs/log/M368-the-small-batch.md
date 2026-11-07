# M368 — the small batch: three read, twelve refused, and the lever that closed the table readers

The first reading batch over the 201 corrected rung entries took the **31 smallest** (≤8 words), on the principle that
size is not what makes a function hard but it is what makes one cheap. Three closed. The more useful result is the
classification of the other twenty-eight.

## 1. Three read, and the lever was statement order again

```c
extern u32 D_8010bc30;                     extern u8 D_800f5e30[];
void FUN_800510c4(void)                    f32 FUN_80040e10(u32 a0)
{                                          {
    D_8010bc30 = 0;                            u8 *b = D_800f5e30;
}                                              return *(f32 *)(b + (a0 & 0xfff) * 4);
                                           }
```

`0x800510c4` closed only after the **sign-extension** correction — the image's `lui v0,0x8011` + `sw zero,48176(v0)`
addresses **`0x8010BC30`**, not `0x8011BC30` (M322's rule, this time applied *forward* rather than backwards). And the
two table readers closed on one change: **bind the base to a local before the index**. `(f32 *)(D_800f5e30 + (a0 & 0xfff) * 4)`
emits the `lui`/`addiu` pair *after* the `andi`; `u8 *b = D_800f5e30; ... (b + (a0 & 0xfff) * 4)` emits it first, which is
the image's order. That is M336's and M355's lesson in a new place: **an invariant's materialisation follows the
statement that binds it**, and where it lands relative to the index is a property of the source, not the compiler.

## 2. Twelve are not C at all, and each has a reason

| class | n | example | why |
| --- | --- | --- | --- |
| coprocessor bodies | 5 | `0x8001f3a8` (`jr ra; mtc0`), `0x80048280` (`lwc1`/`swc1`) | `mtc0`/`mfc0` are not emittable by this cc1 (M323/M354); they stay on the rung as measured extents |
| the exception/DSP family | 6 | `0x8001f470`, `0x80020800`, `0x800219a0` | they read `t3`/`t8`/`t9`/`at` on entry and end in a `j` — hand-written assembly, the M321 family |
| jump-table fragments | 4 | `0x800a20f4`, `0x800a2194` | `and v0,a0,v0; j v0,...` is the middle of a switch, not a function |
| incoming-register fragments | 2 | `0x80039f28` (`sb zero,0(v1)`), `0x8007dcc8` | they read `v0`/`v1` before writing them, which no function start can |

Three more need their **extent** fixed rather than read: `0x80049f8c` includes a leading alignment `nop` that belongs to
nothing, and `0x8004249c` is the known MIPS III `daddu` body.

## 3. The remaining thirteen are close and stuck on spelling

Every one compiled, none matched, and the residues are two mechanical classes rather than allocation: **`ori` where the
image has `addiu`** (a constant address split, cured by using the symbol), and **a register chosen for the accumulator**
in the `srlv`-and-mask trio (`0x8006e644`/`65c`/`670`, which at 1–2 of 5 words are the largest remaining gap in the
batch). They are published rather than retried: two drafts each, both recorded.

## Numbers

- **+3 read** onto F1 (`0x800510c4`, `0x80040e10`, `0x800b2618`); rung **201 → 198**; probe **360 → 363/363**
- **12 refused with reasons** (5 coprocessor, 6 exception/DSP, 4 jump-table fragments, 2 incoming-register — one body
  counted twice), **3 need re-measuring**, **13 close on spelling**
- `F1` **3 459 → 3 462**, recovered **391 → 394 / 393 exact**, census 3 665 unchanged, coverage 63.3 %
- tree **1 415 → 1 418 cases**; `verify.py --full` **PASS**, audit 160/160
