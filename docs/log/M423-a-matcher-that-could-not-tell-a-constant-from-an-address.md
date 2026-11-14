# M423 — six of the twelve "improvements" were spurious, and the six real ones do not close

M422's report said `symbol:addr` *improved* 13 mid-band bodies. Following them up found that half of that was the pass
lying, and the other half is the queue's real shape.

## The spurious half

The pass matched address literals with `0x[89a-f]…` — which includes **sign-extended negatives**: `0xfffffffe` (-2),
`0xffffffff` (-1), `0xfbffffff`, `0xfffffbff`, `0xfffffff7`, `0xfffffff8`. So it "symbolised" them, turned an arithmetic
mask into a pointer reference, moved the words, and reported *improvement on six bodies where it had changed the
meaning*. The matcher is now **RAM addresses only**: `0x8xxxxxxx`, which is where every image in this corpus lives.

That is the third time this arc has found an instrument asserting something the data did not support — the width default
(M420), the map measuring its own projection (M410), and now a matcher that could not tell a constant from an address.
The pattern is consistent enough to state as a rule: **a pass that infers meaning from the shape of a literal must say
what shapes it accepts, and a negative constant looks exactly like an address to a regex.**

## The genuine half, and why it does not close

Six bodies improved and none closed. Two were examined word by word:

- **`stage2:0x800a56c0`** — after the symbol fix it is **15 of 16**, and the last word is `blez $v0,+9` against our
  `beq $v0,$zero,+9`. The image branches on **signed ≤ 0**; we branch on zero. Three spellings were tried — the value
  declared `int`, the comparison written `<= 0`, both together — and all three leave `beq`. The source shape that makes
  gcc emit `blez` for a decrement-then-test idiom is not one I have found, so the body stays at 15.
- **`boot:0x8000c940`** — 13 of 37 after the fix, and its compiled C is **shorter than the extent**: a hole, not a
  residue. `draft_workbench.classify` crashed on it (`gloss(None)`), which was a real defect in the workbench: it now
  reports a `short` class and says the residue is upstream of any single word.

## The re-measured queue

| | bodies |
| --- | --- |
| map: byte-exact | **467** of the 3 473 measured |
| near band (≤ 8 words) | **267** (15 at 1 word, 81 at 2, 81 at 4, 90 at 8) |
| mid band (25–89 % match) | **464** |
| pass set, both bands | **0 closed**; `symbol` improved 10, `dat:width` 84, `order` 20 |

The corpus is unchanged at **647 of 3 664 (17.7 %)** — this milestone moved the instrument twice and closed nothing, and
that is the honest result: **the pass set is exhausted, and what remains at the top of the queue is source SHAPE** (a
signed-comparison idiom, a hole), which no substitution, ordering or symbolisation reaches.
