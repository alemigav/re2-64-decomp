# M344b — `u16_table` and `dense_data`: the structured residue, measured before it was named

The last 244 548 B were called "structured" — a description, not a class. Measuring them first said something
uncomfortable: **only 12 % of their words fit a u16 or sign-extended s16**, so the obvious name (`int_table`) would have
been a hunch with a number attached. What the words *are* is density, not small numbers:

| byte entropy of the run | bytes |
| --- | --- |
| ~6 bits/byte | 62 536 |
| ~5 bits/byte | 56 104 |
| ~7 bits/byte | 44 916 |
| ~4 bits/byte | 40 452 |
| ~3 bits/byte and below | 28 268 |

So the residue splits into **packed** and **systematic**, and only one of those can be named by a positive rule.

## 1. `u16_table` — the positive rule (31 992 B)

A run of ≥ 64 B where **≥ 90 % of the u16 halves are under 4096** and there are **≥ 16 distinct halves**: packed
coordinate/value data. That is a property of the bytes, not of our hope, and it claims **31 992 B**.

## 2. `dense_data` — a measurement, and labelled as one (128 056 B)

A run of ≥ 64 B that no rule claims and whose byte entropy is **≥ 5 bits/byte**. The class's own source string says what
it is: *"no rule fires; 6.1 bits/byte of entropy — measured density, not identified content"*. It is **not** an
identification and the note says so twice; what it buys is that `unclassified` stops being a place where two very
different facts (packed data, and low-entropy systematic data we cannot read) are stored under one name.

## 3. Measured

```
function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 · pointer_table 20 380
string_table 13 200 · padding 405 296 · fill 1 496 · gap 4 720 · u16_table 31 992 · dense_data 128 056
unclassified 84 500 (4.3 %)                                    = 1 956 560 B
```

**12 classes**, partition closing exactly, and `unclassified` is now **84 500 B (4.3 %)**: 72 228 B of runs ≥ 64 B that
are *low*-entropy and match no rule (systematic data we cannot yet read — the interesting remainder) plus 12 272 B of
small runs not beside a body.

## 4. The gate

```
PASS a run of 32 packed small u16 values is `u16_table`, and the same run at 0x8000 is not
PASS a high-entropy run is `dense_data`, and a flat run with no structure stays unclassified
```

Two mutations, one constant each: `U16_FRACTION 0.90 → 0.0` (any run with sixteen distinct halves becomes packed) and
`DENSE_ENTROPY 5.0 → 0.0` (a flat run becomes dense). `--lint` clean (3/3). **Audit parked** as agreed — its state is
M342's (`119/148, 0 vacuous, 29 broken → INCONCLUSIVE`).

Both pin-cases needed a payload chosen so the *other* rule could not fire first — a dense payload whose u16 halves were
all under 4096 would have been `u16_table`, and the case would have proved nothing. That is the third milestone in a row
where the test bed, not the rule, was the thing that needed care.

## Numbers

- **12 classes**; `u16_table` **31 992 B**, `dense_data` **128 056 B**; `unclassified` **244 548 → 84 500 B (4.3 %)**
- byte map **13 → 15 cases**; audit **152 → 154 mutations** (lint-clean, not run)
- **recovered 155 / 154 byte-exact — unchanged**; no reconstruction, no census change
