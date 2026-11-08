# M387 — the 51+ word queue, screened before drafting: half of it is not a function

M386 closed by naming the large end as the only untried population with real size — **28 entries above 50 words**. This
milestone screened all 28 before spending a draft, with two mechanical tests that M385 and M364 established:

1. **does the body read a scratch register before writing it?** (`$v0`/`$v1`/`$t0`–`$t9` read-first = the extent opens
   inside somebody else's routine, or the head is outside it);
2. **does any branch or jump target leave the extent?**

and recorded, as a third, whether the body saves `$ra` (evidence that it is a function with a frame rather than a leaf).

## The result

```
51+ entries: 28 | self-contained: 14
```

**Half the queue is not a function.** The classified defects:

| entry | words | why |
| --- | --- | --- |
| `0x80164bf8` (ovl_00b321e) | 51 | reads `$t0` before writing it **and** its `beq` at word 47 targets −54 words, outside |
| `0x800351e8` (stage2) | 55 | reads `$v1` before writing it |
| `0x8002de0c` (stage2) | 66 | reads `$v1` before writing it |
| `0x80050fa8`, `0x8007199c` (stage2) | 71, 90 | reads `$v1` |
| `0x8007c5b4`, `0x8006f740` (stage2) | 88, 92 | reads `$v0` |
| `0x80049dd0` (stage2) | 111 | reads `$t1` |
| `0x8008bb10` (stage2) | 164 | reads `$v0` |
| `0x800324a8` (stage2) | 209 | reads `$v0` |
| `0x80021c78` (stage2) | 291 | reads `$t8` **and** a branch leaves the extent |
| `0x801802a8` (ovl_0072610) | 79 | reads `$v0` |
| `0x801847d8`, `0x80184970` (ovl_0072610) | 87, 67 | reads `$t8` |

**Both smallest entries — the two that looked cheapest — are in that list.** The 51-word one is also the previously
unknown case `0x80164bf8`, which I dumped by hand before writing the screen: it confirms the mechanical test (it opens on
`lbu $v0,9($t0)` with `$t0` set nowhere in the body).

## What is left, and what it costs

The 14 self-contained entries are **all 67 words or larger** (67, 67, 74, 80, 86, 90, 101, 130, …) and **thirteen of the
fourteen are leaves that save no `$ra`** — i.e. pure data loops with no frame to fix the statement order. That is precisely
the class the size rule says resists, at ten times the reading cost of a 7-word wrapper:

| | cost per draft | expected closure |
| --- | --- | --- |
| 7–8 word wrapper (M384) | ~7 lines | **14 of 14** |
| 22–23 word call body (M382) | ~23 lines | **6 of 6** |
| 67–130 word leaf loop (this queue) | 67–130 lines, plus loop-shape iteration | unknown, and the two mechanisms that would help (allocation, delay-slot scheduling) are the ones measured as unreachable |

**So the honest recommendation is that this queue is not worth drafting at the current instrument set.** Its 14 fragments
should be corrected or withdrawn — that is extent work, and it is cheap; its 14 clean bodies are the largest single
expense in the corpus with the lowest expected yield, and the wall they will hit is the one that has absorbed every residue
since M311.

## Moves

**Nothing registered.** `recovered` stays **274 / 273 byte-exact**, `F1` **3 468**, rung **318 entries / 37 608 B**,
coverage **1 238 112 B**, `make check` **273 of 274**. Tree **1 373 cases**. What changed is the *knowledge*: 14 of the 28
entries now have a verdict, and the queue's expected value is measured rather than assumed.
