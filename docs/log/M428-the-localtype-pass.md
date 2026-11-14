# M428 — `localtype`: 4 bodies closed and 131 moved, the largest pass the program has produced

M427 sorted the queue by shape and found that the most common one-word residue is a **type on a local** — a stack
parameter read as a halfword, a value not truncated, a store whose width follows a declaration. None of the existing
passes looks there: `dat:width` varies an `extern`, `symbol:addr` varies an address literal. This builds the third one.

## The pass

`localtype` varies the declared type of **every local and every parameter** in the draft — six candidate types each
(`unsigned char`, `char`, `short`, `unsigned short`, `int`, `unsigned int`), bounded to twelve variants per body, each
pinned through the gate's own pipeline. It is purely textual, which is why it can exist at all: the draft already names
its locals, where the loop mechanisms of M416 could not be expressed as text.

## Measured, both bands

| pass | near band (193) | mid band (463) |
| --- | --- | --- |
| **`localtype`** | **2 closed**, 13 improved | **2 closed**, **118 improved** |
| `dat:width` | 0 closed, 22 improved | 0, 46 improved |
| `symbol:addr` | 0, 3 improved | 0, 4 improved |
| `early`, `forward`, `order`, `guard`, `sig` | 0 | 0 |

**131 bodies moved closer and 4 closed outright** — the largest improvement count of any pass in this project, and it
came from the class that four milestones of mechanism-hunting had walked past.

One of the three M427 test bodies closed exactly as predicted: `stage2:0x8007277c` at **12 → 13 of 13**, with `uVar1`
declared **`short`**. The other two did not, and stay one word short: `stage2:0x80047824`'s halfword stack parameter and
`boot:0x80004bac`'s negative constant are not a local's type nor a positive address literal.

## 649 → 653 of 3 664 (17.8 %)

Six hundred and seventy-six probe cases pin it, `--full` PASS, audit 160/160.

## What the 118 improvements mean

A body that `localtype` improved without closing now has a **correct type and a residue behind it** — the same structure
M421 found when `symbol:addr` improved 13 bodies: the mechanism was right and incomplete. Those 118 are the most
promising population the queue has ever had, because the pass that will close them starts from a draft whose types are
already the image's.

That is the argument for running the passes in sequence rather than in isolation: each one hands the next a better
draft, and the count of *improved* bodies is the measure of how much work has been pre-paid.
