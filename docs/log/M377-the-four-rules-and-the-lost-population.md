# M377 — the four rules come back, and the population they measured is gone

The discovery tithe for this cycle. `tools/extent_scan.py` splits a region at every `jr ra` and has done since M339;
the four rules that M364 and M365 had to *derive by hand* — cut at a tail `j`, reject a branch that leaves the body, a
self-branch, an epilogue with no prologue — lived only in `/tmp/rebuild3.py`, which no longer exists. Two later
milestones then re-derived them inconsistently, and one of them (M364) got `j` wrong at a cost of thirteen functions.

## What was built

| rule | where | its self-test case |
| --- | --- | --- |
| a body is **cut at a tail `j`** (opcode 2 ends a control path; `jal`, opcode 3, does not) | `ends_path()` | a `j` + delay ends the body at two words; a `jal` + delay does **not** |
| a **branch that leaves the body** means the extent is a fragment | `check_body()` | `beq` at +0x10 inside a 4-word body → rejected |
| a **self-branch** never returns | `check_body()` | `b .` → rejected |
| an **epilogue with no prologue** restores `$ra` from a frame it never saved | `check_body()` | `lw $ra,16($sp); jr $ra` → rejected; `sw $ra` then `lw $ra` → accepted |

`--strict` selects the strict splitter; `scan()` is untouched, because the committed rung was produced by M365's
hand-run rebuild and a reader must be able to see **both** the measurement that exists and what a stricter tool says
about it.

**The gate is finished in the sense this project requires.** Disabling the rules
(`check_body = lambda *a: None`, `ends_path = jr-ra-only`) prints four named failures and exits 1:

```
FAIL strict: a body is cut at a tail `j`, because a `j` ends a control path
FAIL strict: a branch whose target leaves the body is rejected
FAIL strict: a self-branch is rejected (b .)
FAIL strict: an epilogue restoring `ra` from a frame it never saved is rejected
7/11 extent-scan case(s)
```

The first version of those cases **crashed** under the mutation (`IndexError` on `[1][0]`), which is M204's rule
exactly — a crash proves nothing — so they were rewritten through index-safe helpers before being accepted.

## The finding that matters more than the rules

**`--code-runs` returned nothing.** It scanned the `unclassified` class, and the twelve-milestone byte-map arc
classified those runs away: `unclassified` is 440 B in nine tails today, so the tool that wrote the rung can no longer
find the population the rung came from. The class is now selectable (`--region-class`), and on the classes the rung's
later entries did come from:

```
./extent_scan.py --code-runs --strict --region-class enclosed_data,gap
  … 3 function(s), 144 byte(s) measured across 19 region(s)
```

**Three**, against 371 committed entries. So the plan's item — re-derive the rung and reconcile all of it — cannot be
delivered as written, and the reason is worth recording rather than hiding: **the rung's input population was consumed
by the very arc that named it.** To reproduce M362/M365 exactly you would need the pre-M349 byte map, which is not in
the tree because `manifests/byte_map.json` is regenerated in place. What *can* be reproduced is the rule set, and that
is now committed, gated, and mutation-tested.

The alternative — a rung produced by scanning `enclosed_data` and `gap` today — would be a *new* measurement of three
functions, not a reconciliation of 371. It is named here as the honest next step for a future discovery milestone, with
its number (3 functions / 144 B / 19 regions) already measured.

## Two refusals this milestone also carried

`0x80049f8c` and the three other extents that need a trim (M368's queue) remain open: each needs a *leading* `nop`
removed from the census body, which changes an adopted extent and therefore needs its own reconciliation, not a
one-line fix. They stay queued with their addresses rather than half-done.

## Moves

No ledger moves: `recovered` **221 / 220**, `F1` **3 465** unchanged, rung unchanged at **371**, coverage unchanged.
`extent scan --self-test` **5 → 11 cases**, tree **1 320 → 1 326 cases** (347 → 353 runnable). This is the milestone
whose value is that the next four milestones' inputs can be reproduced.
