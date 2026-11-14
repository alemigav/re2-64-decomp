# M415 — the per-body portfolio: m2c closes 4 of 249 near-band bodies

M414 refuted m2c as a bulk generator of the far mass and named what it is good for: a second opinion on a body that is
already close. This wires that second opinion in and measures it on the band.

## The instrument

`tools/draft_portfolio.py` takes each body in a band, produces **both drafts** — the provider's (through
`bank_exact.body_for`, the same text the distance map measures) and m2c's — runs **both** through the gate's own
compile-link-compare, and keeps the better. m2c's draft needs four things that took a milestone to get right: the body's
own words from the image bytes, its `glabel` shape **with a label at every branch target** (it refuses hex targets),
both compiler targets (`mips-gcc-c` first — the corpus is gcc 2.8.1 — then `mips-ido-c`), and `M2C_FIELD` expanded **by
argument splitting** rather than by regex.

**m2c is an optional external, never a dependency**: it is not vendored, and every case here reports `SKIP` — never
`PASS` — when it is absent. What the repository keeps is the measurement, `fixtures/decomp/portfolio.json`.

## The measurement: 249 bodies, one band pass

| outcome | bodies |
| --- | --- |
| **closed by m2c where the provider's draft was not** | **4** |
| m2c better (fewer words differing) | 8 |
| m2c worse | 15 |
| equal | 7 |
| m2c refused (no C, or its C would not compile under this `cc1`) | **215** |

So the portfolio is worth **+4 of 249 (1.6 %)**, and it is not free of risk: on 15 bodies m2c's draft is *worse* than
the one we already had, which is exactly why the tool keeps the better rather than adopting m2c.

**The 215 refusals are the ceiling on this instrument**, and they are a property of m2c's dialect under a pinned
gcc 2.8.1 with no preprocessor: it targets IDO/gcc C with macros, and a body whose asm crosses the extent, or whose
expansion needs a type environment (`--context`) that does not exist for 3 664 functions, does not come back compilable.

## Where the near band has now landed

| pass | instrument | closed |
| --- | --- | --- |
| M411 | access-type table, gap ≤ 1 | 24 |
| M411/413 | the same table, gap 2–4 | 13 |
| M413 | declaration-line signedness | 2 |
| **M415** | **the m2c portfolio, gap ≤ 8** | **4** |
| | **total mechanical closure of the band** | **30 of 251 (12 %)** |

The remaining **221 bodies of the band are not mechanical**: their differing words are same-opcode (register, immediate
and order), which is the allocation residue. Three passes have now measured that boundary from three directions —
substitution, ordering, and a second decompiler — and all three return 0 or nearly 0.

591 → **595 of 3 664 (16.2 %)**, 322 of them the decompiler's own C verified word for word, and 4 of those produced by a
tool this repository does not depend on.

## The honest reading for 40 %

The band was the mechanical queue; it is 12 % mechanical and now measured out. That removes the last bulk lever below
the mid band, so the sequence for 40 % is now unambiguous: **the 221 band residues, the 333 mid-band bodies and ~300 of
the far mass are all the same work** — one mechanism, one body, at M378–M387's measured five per milestone.
