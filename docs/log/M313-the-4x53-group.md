# M313 — the 4 × 53 group: decoded, drafted, and stopped at 33/53 by the same wall

The largest remaining duplicate group, taken as M312 planned. It is a **real function** — and it is blocked by
allocation, not by anything in the C.

## 1. What the function is

`ovl_008900e:0x8016852c` and its three identical copies, 53 words:

```c
void f(u8 *ctx, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6)
{
    u16 local[3];
    u8 *base = *(u8 **)(ctx + 0x234) + p5 * 376;     /* stride via (p*3)<<4 - p)<<3 */

    FUN_8004276c(base + 56, p6, local);              /* fills the three u16s  */
    local[0] += *(u16 *)(base + 78);
    local[1] += *(u16 *)(base + 82);
    local[2] += *(u16 *)(base + 86);
    FUN_80037780((p1 << 24) | (p2 << 16) | p3, (s16)p4, D_800E9028, local);
}
```

The `× 376` stride is the same `3·p → <<4 → −p → <<3` chain as the record-writer family, so that part was named
from the disassembly directly. Two calls, a 6-byte stack array, three accumulated `u16` fields, and a packed byte
composite as the second call's first argument.

## 2. Where it stops

| draft | words |
|---|---|
| first transcription | 31 / 53 |
| + the constant as a **symbol** (`extern u8 D_800E9028[]`) instead of a literal | **33 / 53** |
| two structural variants (explicit casts on the accumulations; the array as a 3-field struct) | 31 / 53 |

The residue is **22 words** and it is not the arithmetic:

- **the callee-saved set is permuted.** The image keeps `p1→$s2, p2→$s3, p3→$s4, p4→$s1, base→$s0`; every draft
  keeps `p1→$s1` and `base→$s2`. Same instruction sequence, different registers, throughout.
- **we emit three instructions too many** (56 against 53), which is the signature of a live range the original did
  not need.
- one real fix *was* found and kept: a **global address passed as an argument must be a symbol, not a literal** —
  `D_800E9028` emits `lui 0x800f / addiu -28632` like the image, while the literal `0x800E9028` emits
  `lui 0x800e / ori 0x9028` (same value, different split).

## 3. Why it is stopped rather than pushed

The callee-saved assignment is `global_alloc`'s ordering again — the wall M311 measured and closed: allocnos are
sorted by reference count, the ordering decides the registers, and no C shape changes the counts without changing
the code that must match. Four drafts and two structural variants is the same budget that exhausted the 25-word
group.

**So the group stays unregistered at 33/53**, published as such, alongside `0x8007e590` (226/229),
`osCreateThread` (23/52) and the 25-word group (22/25). Four residues, one diagnosis.

## 4. Where the duplicate census stands

- **banked: 59 functions** from eight cohorts (34 empty, 11 masked call, 3+2+2+2+3 stores/forwarders/wrappers)
- **stalled by allocation: 8** — the 4 × 25 and the 4 × 53
- **remaining candidates: 77 functions in 36 groups**, the largest being 3 × 32, 3 × 21, 3 × 20, 3 × 13, 3 × 7

The next cohort worth trying is **3 × 32**: bigger than the 3 × 13/20/21, and the only remaining group above 21
words. But the honest expectation is set by the last two: **five of the eight attempts that needed a non-trivial
body have ended on the allocation wall**, and the ones that landed were single-statement functions.

## Numbers

- no case added or re-aimed: probe **64/64**, recovered **75 / 74 exact**, tree **73 suites / 1 039 cases**
