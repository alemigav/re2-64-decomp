# M381 — the 13–20 word band's call-bearing entries: ten of twelve, and the rule that predicted it

M380 closed with a recommendation rather than a result: *draw the 13–20 band's call-bearing entries, because a call cannot
be sunk into a delay slot.* This milestone tested that. **Ten byte-exact from twelve drafts**, the best first-draft rate of
any batch in the cycle — and the prediction is what made it.

## How the population was selected

Not by eye. For every one of the **137** entries in the band, the words were read and the entry kept if any word has
**opcode 3 (`jal`)** — 27 entries, spread over eight images (`ovl_008505e` 6, `stage2` 6, `ovl_0072610` 5, `boot` 2, and
four singles). The selection is a committed, repeatable query against `fixtures/decomp/measured_extents.json` plus the
cartridge, not a reading of the listing.

## The ten

| entry | mechanism |
| --- | --- |
| `0x8016387c`, `0x80162024`, `0x80162e28` | **one shape, three copies**: `if (p[n] == 0) A(p); else B(p);` — the arms are two different calls, and the `j` over the else-branch is what the shape produces |
| `0x80166338` | a guarded init (two stores) then an unconditional call |
| `0x801649fc`, `0x80163100` | the same callee behind the same guard, two different store sets — `$s0` is saved because the context outlives the call |
| `0x8017dd78` | a wait loop: call, test, call-with-8, **back edge as a `j`** rather than a branch |
| `0x801813d8` | a counter read, passed to a call, incremented, then a second call — the increment's store lands in the second `jal`'s delay slot |
| `0x8017b7a8` | five stores through a loaded pointer (three zeroes, one value twice), then a call with 0 |
| `0x80166e58` | a flag test whose taken arm loads, clears, stores and calls; the other arm is one call |

**Two partials, both 15 of 17:** `0x8017f370` (ours folded the global's base into `$at` instead of a spare register) and
`0x80004550` (a store moved across a call's argument setup). Neither is a shape failure.

**Six refusals in the same population, all one family:** the band's six `stage2` call-bearing entries are the
**exception/DSP handlers** — `$k0`/`$t8`/`$t9`/`$at` on entry, `mfc0`/`mtc0`, ending in a `j`. `0x8001f434` and
`0x800207c4` are the same fifteen words, a two-copy cohort. They stay on the rung.

## Why the prediction worked, stated precisely

M380's residue was 11 partials whose only differences were (a) a register name or (b) whether the last store lands in the
`jr ra` delay slot. **A call is not schedulable into a delay slot**, so a body that ends in `jal … ; jr ra` has no
sinkable tail: the last thing that happens is a call, and its argument setup is forced by the callee's signature. Ten of
twelve closed on the first draft, and the two that did not failed on the *call's* argument setup rather than on a tail
store — the same wall, one instruction earlier.

**The general form, worth carrying:** when a residue class is identified by *why* it fails, the complement of that class is
a queue with a predicted yield. That is what turned a 5-in-6 pass at M380 into a 10-in-12 at M381 without any new
instrument.

## Moves

`recovered` **243 → 253** (252 byte-exact), **`F1` 3 468 unchanged** (these are `written` census functions, as in M379 and
M380), `extent_measured` 197, rung **349 → 339 entries / 39 164 → 38 568 B**, probe cases **265 → 275**, `make check`
**252 exact / 1 differ of 253** with 0 unexpected, corpus over **26 images**. Coverage unchanged at **1 238 112 B**. Tree
**1 342 → 1 352 cases** (347 runnable, 1 005 gated).

## What is left in the band, with its size

137 entries remain in 13–20; 27 were call-bearing and 21 of those now have a verdict. The rest splits into
store-heavy bodies (the M380 wall) and 21 call-bearing entries' tail. The next selection worth making is the same query at
**21–50 words** (114 entries), where a body has a frame, a call *and* a loop — the class where the source's statement order
is most constrained by the callee and therefore least able to hide a scheduler choice.
