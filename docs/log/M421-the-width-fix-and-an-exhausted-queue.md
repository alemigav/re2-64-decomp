# M421 — the width bug fixed in the map: the queue shrinks, and every pass now closes zero

M420 found the defect by accident: `distance_map.py` declared every `DAT_…` symbol as `extern unsigned int`, so every
byte and half read in the corpus compiled as a word. Forty-one bodies were closed by compensating for it in a pass. This
fixes it at the source and then re-measures — the instrument first, the queue second, exactly as the rule says.

## The fix

`data_widths()` reads each symbol's width off **the image's own addressing**: `lui` + a load/store offset, or
`lui`+`addiu` then the access, resolving to the address the symbol's name carries. `stage2:0x800b2694` now declares
`D_80136310` as `unsigned char` because the image reads it with `lbu`. The width travels through `build_source` into the
preamble, and `bank_exact.body_for` uses the same function — so **a banked file and the map that found it cannot disagree
about a symbol's type**, which is the property that failed here.

## What re-measuring changed

| | before | after |
| --- | --- | --- |
| bodies the map calls byte-exact | 429 | **467** |
| within 1 word | 54 | **18** |
| within 2 / 4 / 8 | 85 / 86 / 93 | 78 / 81 / 90 |
| **the near band (the drafting queue)** | **318** | **267** |

The 38 bodies that became exact are the ones the `dat:width` pass had already closed by hand: the map now agrees with
the corpus instead of flagging its own closures as near-misses. **The queue was wrong in both directions** — it hid
closures and it advertised bodies whose only defect was a declaration this tool made.

## The re-run, on the honest queue

| pass | near band (200) | mid band (467) |
| --- | --- | --- |
| `dat:width` | 0 closed, 24 improved | 0 closed, 63 improved |
| `order:adjacent` | 0 closed, 1 improved | 0 closed, 19 improved |
| `guard` | 0 closed | 0 closed, 1 improved |
| `symbol:addr`, `sig:forward`, `sig:param` | 0 | 0 |

**Every pass closes zero on both bands.** With the width defect removed at the source, `dat:width` stops closing
anything — which is the confirmation that those 41 bodies were the defect and not a mechanism, and that the pass's
earlier 40-of-240 was me paying for my own bug twice.

## Where that leaves the program

641 of 3 664 byte-exact (17.5 %), unchanged by this milestone: a fix to the instrument moves no functions, it moves the
*queue*. What moves now is 108 bodies whose score rose without closing (25 near, 83 mid) — each one a mechanism further
along than before, and the only place left where a pass can be aimed.

The honest arithmetic stands and is now measured from a correct instrument: the remaining 267 near-band and 467
mid-band bodies, and the 1 966 far mass, need **one mechanism per body, read off the image**. No pass, no decompiler
swap, and no type table closes them; four instruments have now each established that from a different direction.
