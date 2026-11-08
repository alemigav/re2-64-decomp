# M382 — the `jal` query at 21–50 words: six of nine, and the frame is what makes it work

The same query as M381, one band up. **31 of the 114 entries in the 21–50 band contain a `jal`**; nine were drafted and
**six came back byte-exact**.

## The six

| entry | words | mechanism |
| --- | --- | --- |
| `0x8000e920` (boot) | 22 | a call whose result becomes the **next** call's argument, with three stores into a pointer loaded from a global between them |
| `0x800022bc` (boot) | 22 | one call, then two indirect calls through the same slot with different arguments — the second passes the first parameter as its own |
| `0x80033160` (stage2) | 22 | four `lh` arguments into one call, then a signed wrap and a **half-turn test**: `((x - d + 0x400) & 0xfff) < 0x800` |
| `0x80162dd4` | 22 | a **jump-table dispatch** on `p[6]` (`D_80166DB8[p[6]]` as an array of function pointers), then two named calls |
| `0x80165da0` | 22 | one call, then the same callee twice with `3` and `4` and the second argument's halves |
| `0x801653a0` | 23 | a guarded call with two constants, then one unconditional call carrying all three parameters |

**Two partials, both at 17 of 21:** `0x8000e800` — a bounds test on an address (`addr - 0x80000000 <= 0x1fffffff` and
`0x1fffffff < addr + 0x60000000`, else `addr & 0x1fffffff`) whose two failure arms converge; two spellings were tried
(a short-circuit `&&` chain, then a `result` variable initialised to the mask) and both put the call one schedule late.
**A third draft is not spent** — the mechanism is named and the shape is right.

## What the band adds to the rule

M381's finding was that a **call cannot be sunk into a delay slot**, so call-bearing bodies have no sinkable tail. The
21–50 band shows the *other* half of why these close: **a frame makes the order explicit.** Every one of the six saves
`$ra` and at least one `$s0`/`$s1`/`$s2`, and the spill order is fixed by the parameter the function keeps live across its
first call. That ordering is a property of the source (which argument is still needed afterwards), not of the scheduler, so
a draft that gets the live ranges right gets the frame right.

**And the band's refusals are the same family as before:** the three `stage2` entries at 30 words in this population are the
exception/DSP handlers again (`0x8001f4c0`, `0x80020850`, `0x800219f0` — the same shapes as M380's and M381's). They are
not drafted, and they stay on the rung.

## Moves

`recovered` **253 → 259** (258 byte-exact), **`F1` 3 468 unchanged** — the fifth consecutive batch drawn from
already-`written` census functions, which is now the expected behaviour of this queue and not a surprise, `extent_measured`
197, rung **339 → 333 entries / 38 568 → 38 036 B**, probe cases **275 → 281**, `make check` **258 exact / 1 differ of
259** with 0 unexpected, corpus over **27 images**. Coverage unchanged at **1 238 112 B**. Tree **1 352 → 1 358 cases**
(347 runnable, 1 011 gated).

## Where the queue stands

Across P21 the `jal` query has produced **16 byte-exact from 21 drafts** (10 of 12 at M381, 6 of 9 here) — an
order of magnitude better than drawing by size alone, and the selection costs one script and no cartridge reads beyond
the words already needed. **21 of the 31 entries in this band are still unopened**, and the next pass should start with
those whose **first call comes after a live-range decision** (an argument still held across it), because that is the trait
all six of these share.
