# M412 — the dialect gap: 698 refusals were never a distance, and the arithmetic to 40 %

M411 left 698 bodies *refused* — our translation of the provider's C could not compile them, so they had never been
measured at all. That is 19 % of the corpus whose distance was unknown, and a refused body is not a far body.

## Three defects, 698 → 311 refusals, and +92 bodies

| defect | bodies | the fix |
| --- | --- | --- |
| `code` typedef'd `unsigned int`, so `(**(code **)(x))()` was *"called object is not a function"* | 496 | `typedef int code();` — Ghidra's `code` is a **function** type, and the provider **assigns** its result, so `void` is wrong too |
| `in_a0`/`in_k0` used without a declaration | 125 | a file-scope `static` object per undeclared `in_<reg>` |
| `already_declared()` matched a **prefix across the underscore** (`_DAT_x = …` looked like a declaration of `DAT_x`), so real `extern`s were skipped | 125 | `\s+` after the type token, not `\s*` |

Refusals **698 → 311**; measured bodies 2 774 → **3 162**; byte-exact **484 → 589 (16.1 %)** — 89 of the newly measurable
bodies were already byte-exact, and 13 more closed when the type table ran across the four-word band.

The `code` row is the lesson: **a refused body hides a body, not a distance.** Two of the three defects were in code this
project wrote in the last two milestones.

## The 40 % arithmetic, measured

The distribution is bimodal — Ghidra's pseudocode is either nearly right or nearly useless, with almost nothing between:

| band (words still differing) | bodies | cumulative exact if all closed |
| --- | --- | --- |
| **already exact** | **589** | 589 (16.1 %) |
| within 8 (54 within 1, 85 within 2, 86 within 4, 93 within 8) | 318 | ~907 (24.8 %) |
| 75–89 % of words match | 22 | 929 |
| 50–74 % | 111 | 1 040 (28.4 %) |
| 25–49 % | 222 | 1 262 (34.4 %) |
| **< 25 %** | **1 966** | — |
| refused (still unmeasured) | 311 | — |
| no C at all | 196 | — |

**40 % is 1 466 bodies — 877 more.** Closing *everything* within 8 words, plus every body above 25 % match, reaches
**1 262 (34.4 %)**. The last 204 have to come out of the 1 966-body far mass.

**And the far mass does not move mechanically.** Measured: 20 random bodies below 25 %, six structural variants each
(parameters as `int`, `undefined4`→`uint`, `undefined1`→`unsigned char`, locals as `int`, unsigned-char casts) —
**median gain 0 words, one body gained 1, none reached exact.** So the far mass is not a translation defect; it is
Ghidra's C being structurally different from the original, and closing it means reconstruction, body by body.

## What that means, plainly

- **To ~25 %** is mechanical: close the 318-body band. The rate this session measured on such bodies is **24 closed by
  one type table** and **13 more** by widening it, so the band is a finite, well-understood queue.
- **To ~34 %** needs the 25–89 % mid band: 333 bodies where a *mechanism* — not a type — is missing. That is the work
  of M378–M387, which ran at ~5 bodies per milestone, so budget ~60+ milestones.
- **To 40 %** additionally needs ~200 true reconstructions out of 1 966 far bodies, and the experiment above says no
  mechanical pass reaches them.

So 40 % is a program of ~900 closed bodies, of which this session's instruments reach ~318 mechanically. It is not
reachable by translation fixes; it is reachable by closing the ranked queue the distance map now provides, at a rate
that has to be measured on the mid band next.

Nothing in this milestone changes the goal's honesty: 589 of 3 664 functions compile to the cartridge's own bytes, 316
of them the decompiler's C verified word for word and 273 written here, with 1 differ.
