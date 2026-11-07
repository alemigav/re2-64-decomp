# M376 — the 13–20 word band: one read, four left standing

The plan targeted 12–18 functions from this band by proving a *shape* once and registering every copy. The band is
real — 138 entries, 71 `(image, words)` groups, 22 of them multi-member holding 89 entries — but the drafts did not
close the way M375's did, and the honest number is **one**.

## The result

| verdict | count | entries |
| --- | --- | --- |
| **byte-exact** | **1** | `0x8002e810` (14 words: a method-table call through slot 8, then a named callee, 24-byte frame) |
| partial, with scores | 3 | `0x8002fd00` 11 of 14, `0x8003dd8c` 11 of 14, `0x8006dbf4` 12 of 16 |
| refused | 1 | `0x8006b28c` — ends in a `j` whose argument registers (`$t0`, `$t1`) are only partly set inside the extent, so the tail call's signature is not recoverable from these 16 words |

## Why this band is harder, stated with the evidence

1. **The residues are allocation, not shape.** `0x8003dd8c` reached 11 of 14 with every instruction right and only
   three register names wrong (`$a1`/`$v1` in the image against `$v0`/`$a0` here); `0x8002fd00` likewise. That is the
   wall M311/M334 closed as *unreachable from the source we can see* — the 13–20 word band is where the copies of a
   shape differ in their **live ranges**, not in their statements.
2. **A body can be right and still not build.** `0x8006dbf4` matched twelve consecutive words, including the
   `sll/sll/subu/sll` strength reduction of a 124-byte stride, and then differed on the frame's last store: three words
   of ordering that the compiler will only produce from a statement order I did not find. Twelve of sixteen is a
   near-miss, and the note publishes it as one.
3. **The cost per draft rose exactly as the size did.** M375 spent fourteen drafts on ten functions at 9–12 words; this
   milestone spent five on one at 13–20. That is the same curve M368 measured from the other end, and it is why the
   plan's ratio — four writing milestones to one discovery one — should keep drawing from the *low* end of the band
   first rather than the cohort-first order this milestone tried.

## What is still standing, and where it goes

The three partials stay on the rung as published residues with their scores; the cohort groups they belong to are
untouched (`stage2`/14 still holds nine entries, `ovl_0090698`/13 eight). Per the cap rule they are not re-drafted
absent a new mechanism — and the new mechanism this milestone found is a *negative* one worth recording: **matching
eleven or twelve words and differing only in register names is the signature of an allocation wall, and no statement
re-ordering will move it.**

## Moves

`recovered` **220 → 221** (220 byte-exact), **`F1` 3 457 → 3 465**, `F2` 3 404 → 3 411, `extent_measured` 201 → 200,
rung **372 → 371**, probe cases **242 → 243**, `make check` **220 exact of 221**. Coverage unchanged at 1 238 112 B.
