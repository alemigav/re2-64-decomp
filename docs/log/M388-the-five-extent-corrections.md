# M388 — the five extent corrections: three trims, three merges, and one withdrawal the arithmetic found

An extent is a claim about the census, so a wrong one is a wrong claim about the thing every other number divides by.
Five entries were queued as "needs its extent fixed"; this milestone derived each correction from the bytes, applied it,
and published what the corrected body is.

## The five, as corrected

| # | entry | was | now | what the bytes say |
| --- | --- | --- | --- | --- |
| 1 | `stage2:0x80049f8c` | 3 w | **2 w at `0x80049f90`** | it opened on a `nop` belonging to nothing — the previous function ends `jr ra`+`nop` at `0x80049f84/88`. From `0x80049f90` the body is `jr ra; addu $v0,$a1,$zero`: **the two-word `return b;` shape** |
| 2 | `boot:0x8000d3cc` | 23 w | **22 w at `0x8000d3d0`** | same shape: a leading `nop`; the real body starts at the first varargs spill (`sw $a1,4($sp)`) |
| 3 | `stage2:0x80039f08` | 8 w | **11 w** | the `beql` at word 3 targets `0x80039f28`, **inside the same body** — the take-zero arm `sb $zero,0($v1); jr ra; sh $zero,24($v1)`. Cut at the extent's own `jr ra`, the body looked like a fragment; it has two returns |
| 4 | `stage2:0x80073efc` | 9 w | **58 w at `0x80073e38`** | it opens on `ori $v1,$v1,0x8000`, reading a register the **previous nine words materialised** — and the `bne` at `0x80073ea8` **targets `0x80073efc`**. So it is the second half of one body split at an *early return*, and the body starts at the word after the previous `jr ra`+`addiu sp` |
| 5 | `stage2:0x800b4400` | 12 w | **38 w at `0x800b43a0`** | same class: it opens on `addiu $v0,$v0,0x8b20`, and the `$v0` it reads is set by the **delay slot of the `bne` that branches to it** (`lui $v0,0x8016` at `0x800b43f4`). The body begins after the previous `jr ra`+`addiu sp,sp,0x18` |

**Two of the five were not "one word short" as the queue assumed** — they were bodies split at an *early return*, and the
corrected extents are 6× and 3× their old sizes. That is worth stating plainly: the queue's label ("needs a trim") was
right for two entries and wrong for two, and only the bytes could tell them apart.

## The withdrawal the arithmetic found

After the corrections, `counts.py`'s header-sum invariant — *headers == union + overlap* — failed by **exactly 12 B**. The
cause was precise: the new 11-word `0x80039f08` now covers `0x80039f28`, which was **a separate rung entry of 3 words**.
That entry is one of M368's "incoming-register fragments" — `sb $zero,0($v1)` reading `$v1` before writing it — and the
correction shows what it actually is: **the second return of `0x80039f08`**. So it is **withdrawn**, not duplicated.

That has a consequence the note has to carry: **the census moves down, 3 665 → 3 664**, because the fragment was a census
entry. Withdrawal is the fourth ledger (M364's rule) and this is its second use.

## The gate each correction passed

- **Self-containment** (M385's screen): no branch or jump leaves any of the five, and none reads a scratch register
  before writing it. This screen **caught my own error**: my first draft of #5 was 36 words, and the `beq` at
  `0x800b43a8` targets `0x800b4430` — one past it. The correction is 38.
- **No unexplained overlap**: after the withdrawal, the header sum equals the union plus the known 72 B.
- **The projections move together**: `function_body` 1 238 112 → **1 238 404 B** (+292) and coverage by the same bytes;
  `fill` +8 and `dense_data`/`enclosed_data` −196/−96, i.e. the words left the classes they were mis-filed in.
- **`F1` did not move** (3 468) — an extent is not a reconstruction (M340's rule). `F2` moved 3 404 → **3 408**, because
  the corrected bodies resolve call targets the truncated ones could not.

## Moves

census `F0` **3 665 → 3 664**, `F1` **3 468** (unchanged), `F2` 3 404 → **3 408**, covered **1 238 112 → 1 238 404 B
(63.3 %)**, rung **318 → 317 entries / 37 608 → 37 900 B**, recovered **274 / 273**, `make check` **273 of 274** with 0
unexpected, probe **296/296**, counts **42/42**. Tree **1 373 cases** (unchanged).

## What the corrections unlocked, and what they cost

- **`0x80049f90` is now a draftable two-word body** (`u32 f(u32 a, u32 b) { return b; }` — the corpus's own `ret2` shape).
  It is *not* drafted here: correcting an extent is this milestone's theme, and drafting it is the next batch's first line.
- **`0x80073e38` (58 words) and `0x800b43a0` (38 words) are now real bodies with frames and loops**, where before they were
  9- and 12-word halves that could not be read. They are the two largest entries the rung has gained in this cycle.
- The queue is now **empty of derivable corrections**: what remains is the *refusal* set (MIPS III `daddu`, the CP0
  installer family, the `cache` flush) and the 14 fragments M387 classified, which are M392's subject.
