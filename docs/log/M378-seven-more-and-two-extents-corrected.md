# M378 — the second pass over 9–12 words: seven read, two extents corrected

The same band M375 drew from, and the same conclusion: this is where the corpus pays. Seventeen drafts over fourteen
entries gave **seven byte-exact** — and, more usefully, **found two extents that were a word too long**.

## The result

| verdict | count | entries |
| --- | --- | --- |
| **byte-exact** | **7** | `0x80082474`, `0x800667b0`, `0x800837ac`, `0x8003247c`, `0x80073564`, plus two that came back as **extent corrections**: `0x800a5b7c` (11 → **10** words), `0x8003b640` (12 → **11**) |
| partial, with scores | 5 | `0x8005c308` 7 of 9, `0x8009b1f4` 8 of 10, `0x80051104` 8 of 10, `0x8006fe44` 10 of 12, `0x8006fe74` 10 of 12 |

## The two corrections are the finding

Both were drafted to *exactly* the rung's word count and came back `10/11` and `11/12` with the **last word** differing —
and in both cases the offending word is the next function's prologue:

```
0x800a5b7c … 0x800a5ba0   jr ra ; sb $zero,0($v0)      ← the body ends here, in its own delay slot
0x800a5ba4                addiu sp,sp,0xffe8            ← the NEXT function's frame
```

So the body was right and the **extent** was one word long. Registering them at 10 and 11 words makes both byte-exact
and removes two words from the census's claimed bytes. That is the class M368 queued as "three more need their extent
fixed rather than read", and it is now **two of them done, with the rule for finding them**: *a body that matches every
word except its last, where the last word is a frame allocation, is an extent that swallowed its neighbour.*

**A self-inflicted lesson worth recording.** The first reading of `leaf_screen --try`'s output took `10/11 words
identical` for a pass, because the summary line prints a fraction and the diff follows it. Three drafts were briefly
believed exact that were not; the corpus build caught it immediately (`3 differ, 2 unexpected`). **`--try` prints a
fraction, not a verdict, and only `N == M` is a pass** — the same confusion M320 documented about a scorer reporting
`5/5` on four available words.

## What each mechanism was

1. **`0x80082474`** — a do-while byte copy bounded by a precomputed `end`, not a count. `while (dst < end)` after
   `*dst++ = *src++` gives the `sltu`/`bne` pair with the pointer increment in the delay slot.
2. **`0x800667b0`** — a four-valued comparison with **no `slt` anywhere**. The image extracts two sign bits
   (`srl 31`, `srl 30`) and shifts `1` by them, so the source shifts by the sign rather than comparing:
   `(1 << ((u32)(a - c) >> 31)) << ((((u32)(b - d)) >> 30) & 2)`. The unsigned casts are the whole function.
3. **`0x800837ac`** — a bit test whose mask looks like `0x8000` and is not: `lui $v0,0x8000` is `0x80000000`, so the
   mask is `0x80000000u >> (i & 31)`. The first draft's `0x8000u` produced `ori` and one wrong word.
4. **`0x8003247c` / `0x80073564`** — **the M372 shape, now met for the fourth and fifth time**: `D_800C76B0` and
   `0x18000` materialised in **separate registers** and `addu`ed. Two spellings work; both keep the addends visible.
5. **`0x800a5b7c` / `0x8003b640`** — a pointer read from a global (`lw`), then a 104-byte stride and two halfword
   accumulations respectively. Their `--sym` values are *addresses of pointer variables*, not addresses of data, which
   is why both had to be declared `extern u8 *` rather than `extern u8 []`.
6. **Consecutive statements in the same family cost one draft each.** `0x8006fe44` and `0x8006fe74` are one body with
   two destination tables; both reached 10 of 12 with the *same* two words wrong (the context-pointer store's register
   and the return value's placement). They stay published as a pair, because their residue is identical.

## Moves

`recovered` **221 → 228** (227 byte-exact), **`F1` 3 465 → 3 468**, `F2` 3 404 → 3 404, `extent_measured` **197**,
rung **371 → 364 entries / 40 088 → 39 808 B**, probe cases **243 → 250**, `make check` **227 exact / 1 differ of 228**
with 0 unexpected, tree **1 320 → 1 327 cases**. Coverage stays **1 238 112 B** — the two corrections gave back two words
and the seven bodies claimed nothing new, which is the difference between the census's ledger and `F1`.
