# M314 — the 3 x 32 group: two drafts, 29/32, stopped at the cap

The cap was two drafts. The second one is **29 of 32 words** with the instruction sequence exact and **one register**
different — the M311 class — so it stops here.

## Draft 1 — 1/32, and the mistake is worth naming

`1 of 32` with **36** compiled words: the prologue was shifted by two instructions because we kept *unmasked* `a0`
alive across the call and applied the `& 0xff` afterwards, while the image masks **first** and keeps the masked
value. Reading the diff by alignment (every image word appears in ours, 2-4 slots later) was what exposed it — a
raw count of `1/32` says "wrong function", the alignment says "three instructions early".

## Draft 2 — 29/32, and the fix was structural

The correction: give the masked value its own local **before** the call.

```c
u32 FUN_32(u32 a0, u32 *p1, u32 *p2)
{
    u32 v, m;

    if (0x20 < *p1 || (v = *p1 - 1, *p1 = v, v == 0))
    {
        m = a0 & 0xff;                  /* the mask, before the call */
        *p1 = m;
        v = FUN_80033604(a0);           /* the ORIGINAL a0 goes in */
        *p2 = (u32)0x80000000 >> ((v & 0xff) % m);
    }

    v = *p2;
    *p2 = v << 1;
    return v >> 0x1f;
}
```

That single change took it from 36 words to **32**, the image's exact length, and from 1/32 to **29/32**.

## The residue: one register, three words

| word | image | ours | meaning |
|---|---|---|---|
| 8 | `2462ffff` | `2463ffff` | `addiu` **$v0**,$v1,-1 vs **$v1**,$v1,-1 |
| 9 | `1440000d` | `1460000d` | `bnez` **$v0** vs **$v1** |
| 10 | `aca20000` | `aca30000` | `sw` **$v0**,0($a1) vs **$v1** |

The image computes `*p1 - 1` into a **different** register from the load (`$v1`), ours overwrites the load's
register. Same opcodes, same immediates, same operands otherwise — the third instance in this project of a three-word
single-register residue, after `0x8007e590` (226/229) and the 25-word group (22/25).

## Why it stops at the cap rather than one more draft

The cap was two drafts, and it is the right place to stop for a reason beyond the rule: the residue is **the M311
wall** — `global_alloc`'s ordering deciding which pseudo gets `$v0` — and M311 closed that as unreachable from C
after eighteen shapes across two functions. A third draft would be the nineteenth shape against a closed question.

**The group stays unregistered at 29/32**, published as such.

## What the two drafts did buy

- **a reusable source rule**: mask into a named local *before* a call when the masked value is what must survive it.
  Draft 1's prologue was wrong precisely because the mask came after; the compiler then preserved the unmasked
  parameter and added two instructions.
- **an alignment-reading habit**: `1/32` looked like a wrong transcription and was in fact a shift of three
  instructions. Diffing by *sequence* rather than by index found it in one pass.

## Census standing

| | functions |
|---|---|
| banked (8 single-statement cohorts) | **59** |
| stalled on the allocation wall (4 x 25, 4 x 53, 3 x 32) | 11 |
| candidates left in 35 groups (largest 3 x 21) | 74 |

## Numbers

- no case added or re-aimed: probe **64/64**, recovered **75 / 74 exact**, tree **73 suites / 1 039 cases**
