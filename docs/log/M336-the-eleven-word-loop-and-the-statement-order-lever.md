# M336 — the eleven-word loop: the register was a consequence of the statement order

M335 left four cohort bodies drafted and unbanked, at 7 of 11, 9 of 12, 7 of 18 and one shape-not-matched, and named
the eleven-word loop as the next-cheapest. It closed in one compile — and the lever it closed with then closed two of
the other three. **Six functions from three shapes**, and the residue named rather than argued about: 7 of 11 for a
reason the words give.

## 1. The loop: 7 of 11 → 11 of 11

The image, `0x801630bc`:

```
 0 addu $a1,$zero,$zero     i = 0           6 sltiu $v0,$a1,22    i < 22
 1 lw   $v1,564($a0)        v = *(u32**)(a0+564)   7 bne $v0,$zero,-6   back to the load
 2 lw   $v0,0($v1)          x = *v          8 addiu $v1,$v1,0x178  v += 376  (slot)
 3 addiu $a1,$a1,1          i++             9 jr $ra
 4 ori  $v0,$v0,0x8000      x |= 0x8000    10 nop
 5 sw   $v0,0($v1)          *v = x
```

The draft was 7 of 11 with three differences, all at the head: **the counter sat in `$a0`** — the argument register,
dead by then — and the two statements were in the other order (`lw` first, `addu` second).

The fix is not about the counter at all:

```c
u32 i = 0;                       /* BEFORE the pointer read */
u32 *v = *(u32 **)(a0 + 564);
while (i < 22) { *v |= 0x8000u; v = (u32 *)((u32)v + 0x178); i++; }
```

Initialising the counter **first** keeps `$a0` live at the moment the zero is materialised, so the allocator cannot
coalesce the counter into it and takes `$a1` — the image's register — and the load lands where the image has it. Both
`while` and `for (; i < 22; i++)` forms give **11 of 11**. Registered: **2 copies** (`0x801630bc` in `ovl_008900e` and
`ovl_008e046`).

**The general form, and it is the same one M335 found**: when the miss is a register and every *expression* variant
fails, move a **statement** so a live range covers the point — the allocator's choice is downstream of liveness, and
liveness is downstream of statement order. This is the C-side of M303/M334's boundary, and it is now the second
instance.

## 2. The lever closes two of the other three

The 12-word flag test and the 18-word masked call were drafted in M335 at 9 of 12 and 7 of 18, and each missed for a
reason that was **in the words, not in the allocator**:

- **12 words, `0x80162114`** — the last word was `lui $v0,0x0300`. The stored value is **`0x03000000`**, not `0x0300`:
  the draft's `0x0300` materialised as `addiu`. Read the immediate *and the instruction that carries it*: `lui` means
  the low half is zero. **11 of 12 → 12 of 12.**
- **18 words, `0x8005dac0`** — the group carries **two different masks**: the bit *tested* is `0x00100000`
  (`lui v0,0x0010`) and the field *kept* is `0x000f0000` (`lui a0,0x000f`). The M335 draft used `0x000fffff` for the
  second and scored 7 of 18. **7 of 18 → 18 of 18.**

Both registered, two copies each: **4 more functions**, and the family cases say so — `129/129` compile-probe cases,
**153 recovered / 152 byte-exact**.

## 3. What stayed

The fourth body, `0x8000d428` (13 words, `boot` + `stage2`), never matched the dispatcher shape and was not re-drafted:
it is a call followed by `a0 + a2`, a different function that happens to be 13 words long. It stays in the census.

## 4. The gated headline earned its keep immediately

The pair `counts.py` started asserting in M335 did exactly what it was added for: **`counts.py --check` failed on the
first run after the registration** — `[147, 146] != [153, 152]` — instead of passing silently as it had for six
milestones. One line to fix, and the same run named the four files that quote the case totals.

```
recovered 130 → 147 → 153      byte-exact 129 → 146 → 152
probe      118 → 126 → 129     tree cases 1108 → 1117 → 1120  (302 runnable, 818 gated)
```

`ratchet.py --write` re-baselines the registry and `src/` again — 6 published reconstructions this time — and the
progress map is unchanged, because the top panel draws only the 16 hand-recovered functions and the notes say so.

## Numbers

- **recovered 147 → 153, byte-exact 146 → 152**: the 11-word loop (2 copies), the 12-word flag test (2), the 18-word
  masked call (2) — three shapes, six functions, all byte-exact from one reconstruction each
- compile probe **126 → 129 cases (129/129)**; tree **74 suites / 1 120 cases** (302 runnable, 818 gated)
- The two operands that mattered: `0x0300_0000` (a `lui`, not a small constant) and the pair
  `test 0x00100000` / `keep 0x000f0000` in one instruction group
- Standing residue in the census: **27 complete groups / 61 functions**, from 13 words (one shape-not-matched) upward
