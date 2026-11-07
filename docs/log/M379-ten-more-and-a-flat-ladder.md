# M379 — the third pass over 9–12 words: ten read, and a ledger that did not move

Ten byte-exact from twenty drafts, the best return of the three passes — and the more interesting result is which ledger
moved. `recovered` **228 → 238**; **`F1` did not move at all**, and the reason is exact rather than disappointing.

## The result

| verdict | count | entries |
| --- | --- | --- |
| **byte-exact** | **10** | `0x800844e4`, `0x800283f0`, `0x8002841c`, `0x8016baa0`, `0x80162c6c`, `0x80164dec`, `0x801664c4`, `0x80162158`, `0x80161fe8`, `0x8000d66c` |
| partial, with scores | 8 | `0x800725ac` 11 of 12, `0x8006e730` 10 of 12, `0x80072f64` 10 of 12, `0x80073ac4` 10 of 12, `0x800b1c40` 9 of 12, `0x80162884` 8 of 10, `0x80166cec` 7 of 10, `0x8017138c` 7 of 9 |
| refused | 2 | `0x800319e8` (a CP0 vector installer: `mtc0`/`mfc0`, real, not C-emittable), `0x800b4400` (opens `addiu $v0,$v0,0x8b20` — the extent starts inside an address the caller built) |

**Cohort of two in one draft:** `0x800283f0` and `0x8002841c` are one body — an indirect call at vtable slot 0 with a
size argument, then a field cleared in the result — differing only in `0x84`/`128` versus `0x118`/`276`. Two functions for
one shape, which is the cohort mechanic working as advertised.

## Why `F1` stayed at 3 468

`F1` reads "a body exists that could be read". All ten of these already had a **provider-written** body in `src/`, so
replacing that pseudocode with our own reconstruction moves them from `written` to `recovered` **inside** the same rung:
`written` 3 240 → 3 230, `recovered` 228 → 238, `F1` = 3 468 either way. `extent_measured` is untouched at 197.

That is not a defect in the ledger; it is the ledger saying what it means. **`F1` moves when a function had *no* body —
when a measured extent becomes a reconstruction.** M375's batch moved it by seven because three of those were
`extent_measured`; M378's by three; this one by zero. The corpus number (`recovered`) and the ladder (`F1`) answer
different questions, and a batch that only replaces pseudocode is invisible to the second.

## What each mechanism was

1. **`0x800844e4`** — a byte swap as four masked terms, in the image's order:
   `(a << 24) | ((a & 0xff00) << 8) | ((a >> 8) & 0xff00) | (a >> 24)`. Any regrouping changes the word count.
2. **`0x800283f0` / `0x8002841c`** — `(*(u8 * (**)(u8 *, u32, u32))(*(u32 *)(ctx + 4)))(ctx, 0, N)`; the **third**
   argument is what makes the callee's `a2` materialise in the `jalr` delay slot, and the cleared field is the return
   value's, not the context's.
3. **`0x8016baa0`** — `addiu v0,v0,0xc3ac` with `lui 0x8017`: the immediate is **negative**, so the base is
   `0x8016C3AC`, not `0x8017C3AC`. Sign extension, forward, again — the same arithmetic that cost M368 two words.
4. **`0x80162c6c`** — four byte stores then `p[623] |= 0x80`: the load **hoists above** the stores because the offsets
   prove no alias, which is what makes the `lbu` first in the image.
5. **`0x80164dec`** — a no-argument indirect call through a global function pointer (`extern void (*D_80166638)(void)`),
   and gcc loads the pointer **before** the frame is set up.
6. **`0x80162158` / `0x80161fe8`** — one guarded call, the second reading through two loads
   (`*(u32 *)(*(u8 **)(ctx + 564)) & 1`). Same shape, two depths.
7. **`0x8000d66c`** — the boot image's first reconstruction in this band: a wait loop on a callee's result, then
   `FUN_8000db10(0x125)`. `while (FUN() != 0) {}` lowers to the `jal`/`bne` pair with the branch pointing back at the
   call, which is why the loop has no body in C either.

## The operational gotcha, third time, now written down

`cc1` printed `parse error before '<garbage bytes>'` for `*(u16 *)(ctx + 724) = 0;` where `u16` was simply **not
typedef'd**. It does the same for an undeclared function call. This build has no "unknown type name" diagnostic — it
emits a corrupted token into the message — so **the garbage-byte parse error means a missing typedef or an undeclared
callee, not a syntax error**. Three drafts were lost to it across two milestones before the pattern was named.

## Moves

`recovered` **228 → 238** (237 byte-exact), **`F1` 3 468 unchanged**, `F2` 3 404 unchanged, `extent_measured` **197**,
rung **364 → 354 entries / 39 808 → 39 392 B**, probe cases **250 → 260**, `make check` **237 exact / 1 differ of 238**
with 0 unexpected, corpus builds over **24 images** (a second overlay gained its first reconstruction). Coverage
unchanged at **1 238 112 B**. Tree **1 327 → 1 337 cases** (347 runnable, 980 → 990 gated).
