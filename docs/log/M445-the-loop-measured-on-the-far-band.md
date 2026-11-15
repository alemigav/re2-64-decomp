# M445 — the loop measured on the far band: 21 of 414 bodies improve, none closes

The structure loop works. That was M444's finding and it stands: given a byte-exact body whose structure is
mechanically broken, the loop restores **4 of 6**, including a 76-word and a 67-word body. So the templates are
semantically right, the class-directed search works, and the "strict improvement only" rule does not accept noise.

Run against the population the census says it is for — `early-return` and `guard-shape`, gap > 4, ≤ 60 words — it moves
almost nothing.

## The measurement

**414 bodies, one run each, every round scored by `bank_exact.pins`:**

| outcome | bodies | share |
| --- | --- | --- |
| **closed (byte-exact)** | **0** | 0 % |
| **improved** — at least one round won | **21** | 5.1 % |
| stalled or refused | 393 | 94.9 % |

And the winning template, over all 414 bodies:

```
guard:swap  24 wins across 21 bodies        every other template: 0
```

The classes the loop actually acted on were `early-return` 342 and `guard-shape` 35 — i.e. it met the population it
was aimed at, and the single template that ever helps is the one that exchanges the arms of an `if/else` and negates
the test.

## Why it stalls, in one measurement

The census already said it (M443) and this run confirms the mechanism: **969 of the 2 478 open bodies compile shorter
than the function's extent**, and `our-short` is the largest single class. A body that emits fewer instructions than
the original is missing statements, and no amount of guard-shape rewriting supplies them. Of the 414 bodies this run
covered, 393 never produced a variant that beat the draft — not because the templates were wrong, but because the
draft's **statements** are wrong and the structure is downstream of that.

That is the same wall M438 measured from a different direction: the residue is *source fidelity in the draft*
(missing variables, missing types, inverted conditions), and structure is a fourth symptom that only a correct
statement set can exploit.

## What this buys, stated without inflation

- **The instrument is real**: a decoded skeleton, a class-directed template search, the gate's own scorer, and a
  positive control that fails when the templates are wrong. 9 + 3 + 1 = **13 gate cases**.
- **The yield on the far band is 0 closures in 414 bodies**, and 5 % improved. At that rate the far band is not
  reachable by shape.
- **It is not a refutation of the templates.** It locates the defect: the drafts lack statements, so the honest next
  instrument is one that proposes *statements* — the missing locals M439 counted (381 bodies with an omitted-local
  frame) — not one that rearranges the ones present.

## Numbers

- band `early-return,guard-shape`, gap > 4, ≤ 60 words: **414 bodies**
- **0 closed, 21 improved (5.1 %), 393 stalled**; `guard:swap` 24 wins, every other template 0
- classes acted on: `early-return` 342, `guard-shape` 35
- positive control unchanged: **4 of 6 restored**; `structure_loops.json` carries every trace
- nothing banked: `recovered` stays at **668**
