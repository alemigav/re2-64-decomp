# M426 — the family template does not transfer: the 54-word body was the easy one

M425 closed a 54-word body in two iterations and identified three siblings sharing a six-word prologue. The hypothesis
was that one drafted properly gives the other two a template. It does not, and this is the measurement.

## Three restructurings, and the wall

`stage2:0x800acd1c` — 64 words, the first of the family:

| attempt | the shape | score |
| --- | --- | --- |
| 1 | unsigned count, `while (i < count)`, `i * 8` indexing | **8 of 64** |
| 2 | **signed** count, `do { } while` with the test at the bottom | **7 of 64** |
| 3 | signed count, the loop bound in a **copy** variable, a **walked** pointer, the key as `u32` | **8 of 64** |

Each attempt was read off the image and each got the *structure* right — the guard, the walk, the refcount decrement,
the 8-byte tail shift, both exits calling `0x800a56c0`. **The residue is allocation and statement order**: the image keeps
the count in `$v0`, its copy in `$a2` and the key in `$a0`; ours distributes them differently and the three-instruction
loop body lands in another order.

## Why the first body was easy and this one is not

`ovl_00ae24a:0x80162484` is a **straight-line guard chain** — six branches, no loop. gcc's allocation for straight-line
code follows the source order closely enough that two iterations reached 54 of 54, and the two corrections were both
*types*.

This body has **two loops** (search and shift), and a loop is where allocation stops being steerable by source spelling.
That is the same boundary twenty mechanisms established between M396 and M416, arriving here from the opposite direction:
they tried to *close* an allocation residue with mechanisms; this tried to *avoid* one by drafting from scratch, and the
draft reproduces the algorithm and not the register map.

**So the family template is refuted as a cost saving.** The three siblings share a prologue, and sharing a prologue is
not the same as sharing a difficulty: what they share is a search-and-shift structure, which is exactly the part that
resists.

## What is banked, and what is published

Nothing is banked — a draft at 8 of 64 is not a claim. It is **published as a partial with its draft**, per M391's rule,
with the shape recorded word by word and the three attempts scored, so the next attempt starts from the image reading
rather than from scratch.

## The re-measured queue

| | bodies |
| --- | --- |
| byte-exact | **649 of 3 664 (17.7 %)** |
| near band (≤ 8 words) | **268** |
| mid band | 463 |
| far mass | 2 187 |

The honest rate after two bodies of the 19: **one closed (54w, two iterations), one published as a partial (64w, three
iterations, no closable residue left)**. The remaining 17 are closer to the second than to the first: 15 of them are
larger than 64 words.
