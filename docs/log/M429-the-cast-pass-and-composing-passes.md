# M429 — the residue says `cast`, and nine passes that never composed

`localtype` (M428) moved 131 bodies and closed 4. Reading the residue on the ones it moved says what to build next, and
building it exposed a defect in the harness itself.

## The residue on the improved bodies

For each of the 96 improved mid-band bodies: take the **best** `localtype` draft and classify what still differs.

| defect present in the body | bodies | share |
| --- | --- | --- |
| **extension idiom** — image `addu`, ours `sll`/`andi` | **45** | **47 %** |
| **byte/half signedness** — `lbu`↔`lb`, `lhu`↔`lh` | **28** | **29 %** |
| same opcode (register/immediate) | 80 | 83 % |
| other opcode pair (structural) | 89 | 93 % |

Two classes dominate and they are **one root cause: the signedness/width of a value**, touching ~60 % of the improved
bodies. My classifier had been spreading it over three labels (`extend`, `materialise`, `width`), which is why the coarse
histogram read "materialise dominates" — the words say otherwise.

The other number matters too: **83 % still carry same-opcode register/immediate differences**, the allocation class
nothing reaches. A signedness fix moves many and closes only those whose allocation is already right.

## `cast`, and why it was the gap

`localtype` varies **declarations**; the dominating residue lives in **casts inside expressions** — `(char)` vs
`(unsigned char)`, `*(u8 *)` vs `*(s8 *)`. `cast` varies each cast site over six types, bounded to twelve variants, and
**preserves pointer-ness** so `*(char *)` can never become `(int)`.

## The defect in the harness: nine passes that never composed

The first composed run closed **1** body and the second **3**, and before the fix the pipeline had closed **4 in nine
passes** — because **every pass restarted from the provider's draft**. A body needing `localtype` *and then* `cast` was
improved twice and closed never, and the "improved" counts were measuring nine independent passes rather than a pipeline.

Each pass now hands the next **the best text any previous pass reached**. The numbers move immediately:

| pass | mid band | near band |
| --- | --- | --- |
| `localtype` | 0 closed, 116 improved | 0, 11 |
| **`cast`** | **1 closed**, 67 improved | **1 closed**, 33 |
| `symbol:addr` | 0, 5 | **2 closed**, 3 |
| `dat:width` | 0, 50 | 0, 22 |
| `order`, `guard`, `early`, `forward`, `sig` | 0 | 0 |

**4 closed, 186 + 64 improved.** `symbol:addr` closing 2 in the near band is the composition working: those bodies had
an address literal *and* a type to fix, and neither pass could close them alone.

## 653 → 657 of 3 664 (17.8 %)

680 probe cases, `--full` PASS, audit 160/160. Queue: 265 near (13 / 82 / 80 / 90 at 1 / 2 / 4 / 8), 461 mid, 2 185 far.

## The rule this milestone leaves

**A pipeline of passes is not a set of passes.** Nine passes measured in isolation reported 186 improvements and 4
closures; the same nine, composed, report the same improvements and close bodies that none of them could close alone.
The improved count was real either way — it was just measuring the wrong thing: not "how much closer is this body" but
"how much closer did this one pass get it", which is a number about the pass and not about the queue.
