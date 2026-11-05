# M349 — eagle vision: the residue is *bounded*, and the cap was mine

M348 left 56 252 B unclassified and named the next lever as "the base registers, not the bytes". This milestone stepped
back instead and asked a different question: **where do the remaining 209 runs sit?** The answer needed no new rule about
the bytes at all.

## 1. The view from above

```
residue runs >= 64 B: 209, 56 096 B
  data_named    -> data_named       19 356 B (34.5 %)      padding      -> padding        6 740 B (12.0 %)
  function_body -> function_body    12 288 B (21.9 %)      data_named   -> pointer_table  3 916 B ( 7.0 %)
  ... and eight more pairs, every one of them named
both neighbours named : 56 096 B (100.0 %)
one neighbour named   :       0 B (  0.0 %)
neither               :       0 B (  0.0 %)
```

**Not one of the 56 096 B is floating.** Every run has a *named* run on both sides — and 21.9 % of the bytes sit between
two **function bodies**, which is the same fact `gap` recorded, at a scale `gap` refused to look at.

## 2. The cap was arbitrary, and that was the bug

M344 capped `gap` at 64 B and M346 capped `slack` at 64 B. Nothing measured justified 64 — it was a number chosen to keep
the classes small. The eagle's view shows what that cost: **56 096 B of the same phenomenon**, excluded by a threshold
rather than by evidence.

**`enclosed_data`** — a run **bounded by named runs on both sides**, at *any* size: **55 812 B**. It runs **last**, after
`referenced_data` and `dense_data` (which it initially swallowed — the first attempt put it inside an `elif` chain that had
already been taken, and the second put it before the reference pass; both were caught by the totals moving the wrong way).

**And it does not name the bytes.** Its source string names the *neighbours* — `"bounded by data_named and data_named —
the same structure, content unnamed"` — because a 5 820 B run is not slack and pretending to know what it holds would be
the exact error this arc has avoided for twelve milestones. What it states is true and useful: **this data belongs to the
structure around it**, so it is embedded, not mysterious.

## 3. Measured: the bucket closes at 440 B

```
15 classes: function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 · pointer_table 20 380
            string_table 13 200 · padding 405 296 · fill 1 496 · gap 4 720 · slack 12 116 · u16_table 31 992
            referenced_data 16 132 · dense_data 128 056 · enclosed_data 55 812 · unclassified 440 (0.0 %)
                                                                    = 1 956 560 B
```

`unclassified` **330 176 B (16.9 %) at M338 → 440 B (0.0 %)**: **284 B in three runs** (`ovl_00b321e:0x801668b4` 140 B,
`ovl_008505e:0x80166f84` 76, `ovl_009dd02:0x801673bc` 68 — each with one unnamed neighbour) plus the **156 B in six runs**
read in M347. The bucket is now small enough that a person can read all nine in a sitting, which is the only honest
definition of "done" this project has.

## 4. The gate

```
PASS a 128-byte run between two `dense_data` runs is `enclosed_data`, and one with an unnamed neighbour is not
PASS a 128-byte run between two bodies is `enclosed_data` too (the cap was arbitrary)
```

Two pin-cases, one mutation (*the enclosing class stops requiring a named neighbour on both sides*), `--lint` clean (3/3),
and the three residue probe cases re-based on the closing population (3 runs / 284 B, ledger leader 144 B). Two mutation
anchors were re-aimed because earlier milestones' conditions had been split around them. **Audit parked** as agreed.

## Numbers

- **15 classes**; `enclosed_data` **55 812 B**; `unclassified` **56 252 → 440 B (0.0 %)**
- byte map **18 → 20 cases**; audit **158 → 159 mutations** (lint-clean, not run)
- **recovered 155 / 154 byte-exact — unchanged**
- The arc: **330 176 B (16.9 %) → 440 B (0.0 %)** in twelve milestones, every class earned by a rule that can fail
