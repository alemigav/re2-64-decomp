# M385 — the 7–12 word entries without a `jal`: one read, three classified, two left standing

M384 ended by naming the next queue: what is left at 7–12 words **without** a `jal` had never been counted. It is **31
entries**, and this milestone separated them into what they actually are.

## The population, classified

| class | n | what it is |
| --- | --- | --- |
| already published | 22 | the M368/M375/M378/M380 residues — partials with scores and the two refusals, all previously measured |
| **never examined** | 6 | the 7–8 word entries, which the earlier passes never selected (the 9–12 band was closed, the ≤8 band was M368's, and the gap between them was the 7–8 group) |
| known refusal | 1 | `0x8004249c`, MIPS III `daddu` |
| other bands | 2 | `0x8006b9d4`-shaped strays the earlier sweeps counted differently |

## The six never-examined entries, and their verdicts

| entry | words | verdict |
| --- | --- | --- |
| `0x8017bbb0` | 7 | **byte-exact** — a scale getter: a global pointer, a depth field at `+12`, `depth >> (32 - a)` |
| `0x80039f08` | 8 | **extent defect** — its `beql` targets `0x80039f2C`, **two words past the extent**; the body is `if (p[2]) p[2]--; p[1] = 0;` and the epilogue is outside. Queued with `0x80073efc` and `0x800b4400` |
| `0x80083e60` | 8 | **coprocessor body** — all eight words are COP1, no word load or store; the class M368 refused five of and M364 established must stay on the rung |
| `0x80088528` | 8 | **fragment** — `addu $a1,$t0,$zero` reads `$t0` on entry and its `beq` branches **−34 words**, far outside the extent |
| `0x8006b9d4` | 7 | partial, **5 of 7** — two global stores (`0x80112A20 = v; 0x801137D4 = 1;`); ours materialises the second base one instruction late |
| `0x80166f18` | 8 | partial, **6 of 8** — a masked read-modify-write then `q[703] = 0`; ours puts the last store before `jr ra` where the image sinks it into the delay slot |

## The one mechanism worth keeping

`0x8017bbb0` failed first on **the shift's operand order** and closed the moment it was written the other way:

```c
return (32 - a) >> *(u32 *)(p + 12);      /* ours: srlv $v0,$v1,$v0 -- depth shifted by (32-a) */
return *(u32 *)(p + 12) >> (32 - a);      /* image: srlv $v0,$v0,$v1 -- (32-a) ... no: depth >> (32-a) */
```

The image is `depth >> (32 - a)`; the first draft was `(32 - a) >> depth`. **This is M370's and M355's rule a third time:
in a two-operand expression the operand order is the whole encoding**, and a wrong one costs two words and looks exactly
like an allocation failure.

## Moves

`recovered` **273 → 274** (273 byte-exact), **`F1` 3 468 unchanged** (seventh consecutive batch of `written` census
functions), `extent_measured` 197, rung **319 → 318 entries / 37 636 → 37 608 B**, probe cases **295 → 296**, `make check`
**273 exact / 1 differ of 274** with 0 unexpected, corpus over **28 images**. Coverage unchanged at **1 238 112 B**.
Tree **1 372 → 1 373 cases** (347 runnable, 1 026 gated).

## The honest reading of this pass

**One reconstruction from six fresh entries is the poorest yield since M383**, and the reason is structural rather than
bad luck: the 7–8 word population *without* a call is where the corpus's non-C bodies live. Three of the six are not
draftable at all (an extent defect, a coprocessor run, a fragment), and the two that are draftable differ by one or two
words of scheduling. **M384's vein paid because a `jal` is evidence that the body is a compiled function**; without one, a
small body is as likely to be a tail, a vector, or the middle of a larger routine, which is exactly what these three
refusals are.

**So the useful next query is not `size < 13 and no jal` but `size < 13 and (jal or a frame)`** — a body that saves `$ra` is
a function by construction, and that test has not been run.
