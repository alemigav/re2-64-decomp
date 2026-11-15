# M441 — the type lever measured out: 0 closures, and the population was never 298

M440 left one lever standing: **signedness**, 298 bodies, with `type_repair.py` already built. This runs it against
the real population and the lever does not move.

## What was run

`type_repair.py --write --max-gap 4` — every open body within four words of exact, across **all** classes, not only
type ones. Result:

```
closure by gap:   none
refused ovl_009dd02:0x80166408 still 46 of 47
refused ovl_0072610:0x8017ee88 still 18 of 19
refused stage2:0x800a5c50 still 17 of 18
refused boot:0x80004bac still 13 of 14
refused stage2:0x80047824 still 11 of 12
      … 19 bodies, none closed
```

**Zero closures in 3.9 seconds.** `recovered` stays at **668**.

## The population was overstated, and I should correct my own M440 figure

M440 said signedness is **298 bodies**. That is the size of the *class*, and it counted bodies already claimed. The
**open** picture by gap:

| gap | open `lbu`→`lb` bodies |
| --- | --- |
| 1 | **0** (all 38 are already recovered) |
| 2 | 1 |
| 3 | 3 |
| 4 | 3 |
| **> 4** | **178** |

So the lever's addressable population is **7 bodies, not 298**, and 178 of the class are more than four words off —
where a signedness difference at the first divergence is not what stands between the body and exactness.

## Why each of the five nearest fails

Every open body within two words is **one word** off, and each needs a substitution class the table does not have:

| body | word | target | ours | missing class |
| --- | --- | --- | --- | --- |
| `ovl_009dd02:0x80166408` | 11 | `slti` | `sltiu` | comparison signedness |
| `ovl_0072610:0x8017ee88` | 0 | `sll …,7` | `sll …,9` | element width (shift amount) |
| `stage2:0x800a5c50` | 5 | `addu v1,a0` | `addu a0,v1` | commutative order — the class exists and is a **no-op** |
| `boot:0x80004bac` | 4 | `addiu` | `ori` | materialise, signed against unsigned add |
| `stage2:0x80047824` | 0 | `lhu +0x12` | `lw +0x10` | stack-argument width |

The `ORDER` class is already implemented and already applied; it simply cannot help, because two operands of a
commutative operator are the same expression to gcc, which then picks the register order by its own rule. A class that
is a textual no-op is worth knowing about.

## The one extension that looked certain, and failed

`ovl_009dd02` compares `1 < bVar1` where `bVar1 = *(byte *)((int)param_1 + 6)`, and the table covers `*(char *)`,
`*(unsigned char *)` and `*(undefined1 *)` but **not `*(byte *)`** — the spelling Ghidra uses constantly. Making the
variable signed is exactly the substitution that should turn `sltiu` into `slti`. Tested directly, three spellings:

| variant | score |
| --- | --- |
| as-is | 46 of 47 |
| `byte` → `signed char` | **46 of 47** |
| `byte` → `char` | **46 of 47** |

It does not close. The differing word moves, and something else takes its place. So the gap between "the table lacks a
spelling" and "the table closes bodies" is real, and this was the cheapest way to find that out.

## What this settles

The near band is **measured out**, and this is the third instrument to say so independently: `localtype`/`sign` and
their fixpoint (M429–M433), the mechanism passes (M433), and now the type repair on the current map. Every open body
within two words needs a *different* one-word fix, and each fix is body-specific: a comparison's signedness, an element
width, a stack slot. **There is no population left that a single substitution closes**, which is what a lever means.

The remaining path is the 2,529 open scored bodies at larger gaps, one body at a time, starting from a draft rather
than from a substitution table. That is M425/M426's regime, and M426 measured its rate: the easy body closes in two
iterations, the next one stalls.

## Numbers

- `type_repair --write --max-gap 4`: **19 bodies tried, 0 closed**, 3.9 s
- open `lbu`→`lb` bodies by gap: **0 at gap 1**, 1 at 2, 3 at 3, 3 at 4, **178 beyond** — the addressable set is 7
- one class extension tested directly (`*(byte *)` → signed): **0 of 1** bodies closed
- `recovered` unchanged at **668**; `type_repair --check` still **39 banked bodies pinning**
