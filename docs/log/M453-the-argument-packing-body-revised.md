# M453 — the 12-word body: my packing diagnosis was wrong, and the residual is two halves that exclude each other

`stage2:0x80047824` was carried since M437 as "argument packing — a halfword at `+0x12` that no declaration reaches".
That diagnosis is **wrong**, and the sweep that showed it is small enough to state: every parameter shape was compiled
and its `lhu` offset read.

| signature | `lhu` offset |
| --- | --- |
| 5 params, **`unsigned short p5`** | **18 (0x12)** — the image's |
| 5 params, `int p5` | — (a `lw` at 0x10) |
| 6 params, `char q, unsigned short p5` | 22 (0x16) |
| 6 params, `unsigned short q, unsigned short p5` | 22 (0x16) |
| 6 params, `unsigned short p5, unsigned short q` | **18 (0x12)** |
| 7 params, `unsigned short p5` mid-list | 22 (0x16) |

`unsigned short p5` produces `97a20012` — **the image's exact first word**. The original M437 attempt did reach this and
I misread which variant had produced which offset. The body scores **9 of 12** there, and the three remaining words are
not about the argument at all.

## What the three words are

```
image   addu a2,a2,v0 ; sb a2,0x21(a0)
ours    addu v0,a2,v0 ; sb v0,0x21(a0)
```

The **accumulator register**. The image adds into `a2` — the parameter's own register, modified in place — and stores
from it; gcc adds into `v0` and stores from that. Assigning back into the parameter (`p3 = p3 + p5`, `p3 += p5`, the
comma form, and the reversed store order) all leave it at 9 of 12: gcc chooses the destination, not the source form.

## The two halves exclude each other

Changing the parameter's type moves the failure instead of removing it:

| declaration | first word | accumulator | score |
| --- | --- | --- | --- |
| `unsigned short p5` | **`lhu 0x12` ✓** | `v0` ✗ | 9 / 12 |
| **`char p5`** | `lw 0x10` ✗ | **`a2` ✓** | **11 / 12** |
| `char p5`, `unsigned char p3` | `lw 0x10` ✗ | `a2` ✓ | 9 / 12 |
| `char p5`, `int p3` | `lw 0x10` ✗ | `a2` ✓ | 9 / 12 |
| `signed char p3`, `unsigned short p5` | `lhu 0x12` ✓ | `v0` ✗ | 9 / 12 |

So the best reachable is **11 of 12**, and what it costs is word 0: `char p5` makes gcc read a word where the image
reads a halfword, because with a `char` it only needs the low byte and loads the full word. The two requirements —
16-bit load, and accumulate into the parameter's register — are **mutually exclusive** under this compiler's allocator.

## What this changes

- The body is **not** "argument packing"; that label is retracted. It is the **accumulator class**, the same one that
  leaves `ovl_00a0344:0x80162224` at 27 of 29.
- It improves **9 → 11 of 12** and is not closed. Nothing was banked.
- The two remaining non-toolchain bodies (`ovl_00a0344` at 27 of 29, `ovl_009dd02` at 46 of 47) were **not attempted**
  in this milestone; the first one consumed it.

## Numbers

- **6 parameter shapes** swept, `lhu` offset measured for each — `unsigned short p5` gives the image's `0x12`
- best score **11 of 12** (`char p5`); the residual is word 0 and is mutually exclusive with the accumulator
- 4 source forms tried for the accumulator, all 9 of 12; 3 declaration changes tried, none combining both halves
- no edits, nothing banked; `recovered` stays **674**, byte-exact **673**
