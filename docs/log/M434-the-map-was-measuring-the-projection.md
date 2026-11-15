# M434 — the map was measuring the projection: 419 refusals become 278, and 112 "exact" bodies were our own C

The ask was to chase the **419 bodies `distance.json` called `cc1-failed`**. They were not 419, and the reasons were
not in the bodies. Two defects in the measuring apparatus fell out before a single refusal cause was fixed.

## 1. The map compiled a different translation unit from the one it extracted symbols from

`functions_to_measure()` reads the **provider** artifact (`build/decomp/<image>/functions/0x<addr>.c`), derives
`code`/`data` from that text — and then returned the census `source`, which is the **`src/` projection**. `compile_one`
compiles the path it is handed. So for every function whose `src/` file is not a copy of the provider's body, the map
measured **a different body from the one whose symbols it had just extracted**.

This is M410's defect — *measure the projection and you count your own output as the decompiler's C* — in the one place
the M421 fix did not reach. The docstring already said the right thing ("The PROVIDER's artifact, never `src/`"); the
return value did not.

Measured, on a body whose answer is known:

| body | measured by | identical words |
| --- | --- | --- |
| `boot:0x80000520` (`main`) | path the map used — `src/boot/main.c`, our own reconstruction | **24 of 30** |
| `boot:0x80000520` (`main`) | the provider draft, the body whose symbols were extracted | **1 of 30** |

And `main` is **byte-exact 30 of 30** through the probe. The map was reporting 24 of 30 for a function this project has
already proved exact, because it was scoring our reconstruction with a preamble built from somebody else's body.

**647 of the 3,473 records** compiled a body that differs from the provider's after comment stripping; **576** of those
are this project's own reconstructions. The consequence, before the fix:

- **112 records were `exact` because the map compiled our own C** — they are not measurements of anything;
- **108 of this project's own byte-exact bodies were on record as `cc1-failed`.**

The fix is one expression: return the path that was read.

## 2. Ghidra's byte-assembly notation crashed `cc1`, which then printed nothing

Ghidra writes `local_578._1_3_` for "bytes 1..3 of `local_578`" and `CONCAT12(a,b)` for assembling bytes. In Ghidra's own
sources those are `#define`s in `mem.h`; **this `cc1` has no preprocessor**, so they arrive as raw text. `x._1_3_` is a
parse error — and on the error-recovery path `cc1` 2.8 **dies with SIGSEGV while reporting it**, so the body was
recorded as `cc1-failed` with an empty message. That is the whole of the 89-body "no stderr" class.

`expand_idioms()` translates them, and translates is the right word: `x._a_b_` *is* bytes `a..b` of `x`, so the shift and
mask emit the image's own code and no type is guessed. Two limits keep it a translation:

- the field form is expanded **only** for a variable whose **declared width** is known and large enough. Unknown or too
  narrow ⇒ left exactly as it was, refused rather than silently reinterpreting a narrower object. That is the rule this
  project does not bend: a wrong distance is worse than a gap.
- `SUBnn` is **not** expanded — it drops bytes, and the corpus has none (0 of 311 refusals).

## The measurement, both ways

| | before | after | Δ |
| --- | --- | --- | --- |
| `cc1-failed` | 419 | **278** | **−141** |
| `exact` | 481 | **498** | +17 |
| `scored` | 2,573 | 2,697 | +124 |
| words identical | 33,028 (11.06 %) | **34,035 (11.39 %)** | +1,007 |
| histogram `within_1` | 11 | **93** | +82 |
| histogram `within_2` | 79 | 42 | −37 |
| histogram `within_4` | 78 | 91 | +13 |
| histogram `within_8` | 89 | 97 | +8 |

Of the 141 that left the refusal column, **110 compile as they always did** — they were refused because the map was
compiling the projection, not the provider's C — and **31 more** are the idiom expansion (2 → 58 of the genuine 311).

**Two honest notes on that table.** The record set did not grow: 3,473 functions and 298,724 words both ways. And
`within_1` nearly octupling is not new closability — it is the same population, measured on the body it claims to
measure. The one number that speaks to *work* rather than *measurement* is the unclaimed near band, and it did not
move: **23 bodies at gap ≤ 2 before and after** (5 at gap ≤ 1), because `queue()` already excluded claimed bodies and
the 647 affected bodies were almost all claimed.

## What the remaining 278 are

| bodies | words | class |
| --- | --- | --- |
| 98 | 18,455 | error at a line whose **identifier `cc1` cannot print** (see below) |
| 83 | 13,698 | `` `X' undeclared `` |
| 36 | 6,250 | subscripted value is neither array nor pointer |
| 22 | 2,895 | `cc1` died with no message |
| 11 | 1,980 | from incompatible pointer type |
| 10 | 1,074 | invalid type argument of `->` |
| 7 | 1,452 | request for member in something not a structure |

The largest class cannot be classified from `cc1`'s own diagnostic, and that is a defect in `cc1`, not in the corpus:
the source is pure ASCII (measured — 0 of 278 bodies carry a byte above `0x7f` or a control byte below `0x20`), yet the
message contains an uninitialised buffer instead of the identifier:

```
f.c:46: `\xd8K\x02\x03\t' undeclared (first use in this function)
f.c:44: invalid type argument of `\xd0j\x81o\x01'
```

**The line number is usable; the name is not.** Whoever takes this next starts from the source line, not the message.

## The one body this found, and why it did not bank

The corrected map reports **498 exact, 497 already claimed, 1 unclaimed**: `stage2:0x800282e8`, 8 words. `bank_exact.py`
refused it — `pins 0 of 8 — ld refused`. So the map has a **false positive against the pin**, and the two instruments
disagree on exactly one body. Nothing was banked; `recovered` stays at **668**.

## Numbers

- **`distance.json` regenerated**: 3,473 functions, 498 exact, 2,697 scored, **278 refused**, 34,035 of 298,724 words (11.39 %)
- refusals **419 → 278**; `exact` **481 → 498**; 112 former "exact" records were our own reconstructions
- `distance_map --self-test` **3/3**, `--check` **4/4** (summary derived, 24-body sample re-measured)
- `bank_exact --check` **3/3**, banked **0** (1 refused: the pin will not link it)
- README's `within-eight` counter **257 → 323**, caught by `counts.py --check`; counters **47/47**, markers **25/25**
- recovered unchanged at **668**; coverage and the probe untouched — this milestone repaired measurement, and claims nothing
- M433's "filled a 228 GB disk" **corrected** in the note and the row: the disk is 228 GB in total and the leak consumed
  the **16 GB of free space**; 836 scratch directories were still on disk afterwards
