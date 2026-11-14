# M430 — `sign` measured zero, and the lever was the fixpoint

M429 read the residue and found one class dominating: the extension idiom (47 %) and byte/half signedness (29 %), one root
cause. The obvious build was a pass that does **only** the signedness swap, at the same width, at every type site. It is
built, it is correct, and it **moves nothing**.

## `sign`: a measured zero, and why

| pass | near band (185) | mid band (457) |
| --- | --- | --- |
| **`sign`** — same width, opposite signedness, at every declaration, parameter and cast | **0 closed, 0 improved** | **0 closed, 0 improved** |

The class is real — 47 % + 29 % of the improved bodies carry it — but **signedness alone does not reproduce it.** The
extension idiom appears when gcc believes a value is *narrower*, and widening needs a width change; `cast` and
`localtype` already try six widths-and-signednesses at once, so the one change this pass makes was always already
available to them. A dedicated pass for half of an existing pass is a measured zero, and recording it as one is cheaper
than the next session re-deriving it.

## The lever that did work: the fixpoint

The pass list used to run **once per name**. A body that needs `localtype` on one local *and* `cast` on one site closes
only if the second pass sees the first's result — and only if the first is allowed to run **again** over what the second
changed. `--rounds` repeats the whole list until a round improves nothing:

| round | what it closed |
| --- | --- |
| 1 | 3 (two `symbol:addr`, one `cast`) |
| **2** | **3 more** (`localtype` 1, `dat:width` 2) — none reachable in any single ordering |
| 3–4 | 0, so the search stops |

**Nine passes run once is an ordering; nine passes run to a fixpoint is a search.** The rounds cost nothing — the whole
near band is 55 s — and round 2 paid for the milestone.

## The numbers

| pass | near, closed / improved | mid, closed / improved |
| --- | --- | --- |
| `localtype` | 1 / 10 | **1 / 130** |
| `cast` | 1 / 31 | 0 / 76 |
| `dat:width` | **2** / 22 | 0 / 60 |
| `symbol:addr` | 2 / 1 | 0 / 10 |
| `order` | 0 / 2 | 0 / 15 |
| `sign`, `early`, `forward`, `guard`, `sig` | 0 / 0 | 0 / 0 |

**657 → 661 of 3 664 (18.0 %)**, 684 probe cases pinned, `--full` PASS, audit 160/160. Queue: **262 near
(13 / 81 / 79 / 89), 457 mid, 2 184 far.**

## Where the queue now stands

Two thirds of the near band's closure came from *combinations* rather than from any single mechanism, which is the first
time that has been true. The passes are individually near-exhausted; the space of their compositions is not, and it is
now searched for free.
