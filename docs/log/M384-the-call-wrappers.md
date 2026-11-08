# M384 — the 7–8 word call wrappers: fourteen of fourteen

M383 ended with a size rule: `jal`-bearing bodies close at 13–20 words and 22–23 words, and not at 24+. The population
map behind that rule was incomplete — it counted the band, not the *size buckets*. Re-querying every remaining
`jal`-bearing entry by size found something the earlier passes had walked past:

```
13-20: 31   |   21-23: 3   |   24-40: 15   |   41-50: 7   |   51+: 5
```

**Twelve of those 31 are 7–8 words long**, and not one of them had ever been drafted. They are the corpus's thinnest call
wrappers, and they closed **14 of 14** — every entry at that size, plus the two 8-word ones.

## What they are

Nine are literally the same six instructions with a different callee:

```
addiu sp,sp,-24
sw    ra,16(sp)
jal   TARGET
nop                        ← or one argument instruction
lw    ra,16(sp)
jr    ra
addiu sp,sp,24
```

| entry | body |
| --- | --- |
| `0x80004a50`, `0x80004ec4`, `0x801621a8`, `0x80162d6c`, `0x80168cb4`, `0x80161fc0`, `0x80164734`, `0x800284f4`, `0x80161dc4` | `void f(void) { TARGET(); }` — nine callees, one shape |
| `0x8000490c` (boot) | `void f(u32 a, u32 b) { FUN_800014ac(b); }` — the argument shift (`addu $a0,$a1,$zero`) is the whole body |
| `0x800a5c34` (stage2) | `void f(u32 a, u32 b) { FUN_8000efa0(a, b << 1); }` — `sll $a1,$a1,1` in the delay slot |
| `0x8017bbcc` | `void f(void) { FUN_8017bec8(1); }` — one constant argument |
| `0x80162754` (8 words) | `void f(u8 *p) { FUN_80168b3c(p, (u8 *)(*(u32 *)(p + 564) + 0x1a70)); }` |
| `0x8017df4c` (8 words) | `void f(void) { FUN_8017b5e8((u8 *)D_80185710); }` |

**The one real trap, and it is M368's:** `0x8017df4c` passes a fixed address `0x80185710`. Written as a **literal** the
compiler emits `lui`/`ori`; the image has `lui`/`addiu`. Naming it `extern u32 D_80185710[]` and passing the symbol makes
gcc emit the `addiu`, and the body closes. That is the fifth time this cycle that **a constant's *kind* (literal vs symbol)
decides its encoding, not its value.**

## Why this vein was missed

Two reasons, both worth writing down. First, `M369` turned 194 reconstructions into listings and `M375`/`M378`/`M380` drew
the 9–12 band to exhaustion — so the 7–8 word entries sat at the *other* end of the same band, unexamined because the
selection was "13–20 and 9–12" rather than "any size with a `jal`". Second, and more useful: **a 7-word body looks like the
fragments M368 found unreadable** (that pass refused 12 of 31 at ≤8 words, and its four refusals were jump-table and
incoming-register fragments). The difference is the `jal`: `any(word >> 26 == 3)` separates a wrapper that calls from a
fragment that leaves.

## Moves

`recovered` **259 → 273** (272 byte-exact), **`F1` 3 468 unchanged** (sixth consecutive batch of `written` census
functions), `extent_measured` 197, rung **333 → 319 entries / 38 036 → 37 636 B**, probe cases **281 → 295**, `make check`
**272 exact / 1 differ of 273** with 0 unexpected, corpus over **28 images**. Coverage unchanged at **1 238 112 B**.
Tree **1 358 → 1 372 cases** (347 runnable, 1 025 gated).

## Where the queue stands after this

The `jal` query has now produced **30 byte-exact from 35 drafts** across P21 (10 of 12, 6 of 9, 0 of 5, 14 of 14). The
remaining `jal`-bearing population is **3 at 21–23 words, 15 at 24–40, 7 at 41–50, 5 at 51+** — i.e. the sizes the size
rule says resist. **The next pass should stop querying by `jal` and query by size instead**, because the vein that just
paid was not "call-bearing" but "**small and call-bearing**", and what is left at 7–12 words without a `jal` has never been
counted.
