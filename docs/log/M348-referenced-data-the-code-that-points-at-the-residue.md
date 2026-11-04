# M348 — `referenced_data`: the code that points at the residue, and what its displacements say

M345 and M347 tested seventeen candidate rules against the residue and refuted all of them, because every one described
the *bytes*. This pass used a different kind of evidence: **the code that addresses them**. A `lui rt,hi` followed by
`addiu/ori rt,rt,lo` — or by a load/store off `rt` — materialises an address, and if that address lands in an unclassified
run then the game *points at those bytes*. That is a positive property of a different order from every rule before it, and
it is earned:

```
residue runs: 269 (72 228 B);  addressed by code: 60 runs (16 132 B, 22 %)
referencing sites: 857
```

## 1. The rule, and the class

**`referenced_data`** — an unclassified run of ≥ 64 B whose address is **materialised by an instruction** in a function
body: **16 132 B**. Conservative by construction: only *absolute* materialisations count, so data reached through a
computed base register, or through another data structure, is **missed, never invented**.

## 2. The displacements are the first look at record layouts

The class carries its evidence per run, and for the largest referenced runs that evidence is already structural:

| run | bytes | sites | displacement set |
| --- | --- | --- | --- |
| `stage2:0x8012ffac` | 804 | **400** | **84, 85** |
| `stage2:0x80162630` | 1 260 | 3 | 640, 1 252 |
| `stage2:0x8011165c` | 1 116 | 2 | 12 |
| `ovl_007e132:0x8017e214` | 796 | 2 | 236 |

A run with **400 sites at displacements 84 and 85** is an array indexed at `+84`/`+85` — a two-field record read by four
hundred instructions. That is the first *record-layout* evidence this bucket has produced, and it came from the consumers
rather than from the bytes.

## 3. Measured

```
13 classes before this milestone, 14 now
function_body 1 235 280 · jump_table 980 · data_named 6 680 · float_table 23 980 · pointer_table 20 380
string_table 13 200 · padding 405 296 · fill 1 496 · gap 4 720 · slack 12 116 · u16_table 31 992
referenced_data 16 132 · dense_data 128 056 · unclassified 56 252 (2.9 %)     = 1 956 560 B
```

`unclassified` **72 384 → 56 252 B (2.9 %)**, and its composition is *stated*: **209 runs of 64 B or more** (56 096 B,
profiled by `--residue`, with the ten-candidate ledger re-based on this smaller population: leader `word even` now
24.5 %) plus the **156 B in six runs** read in M347.

**What the 56 252 B is**: data that no instruction materialises an address for — reached, if at all, through a computed
base or through another structure. That is a *different* kind of unknown from "we have no rule for these bytes", and it is
the next lever: chase the base registers (`lw` from a known table, then arithmetic) rather than the bytes.

## 4. The gate

```
PASS a run the code materialises an address into is `referenced_data`; the next run over is not
```

on a synthetic body (`lui $v0,0x8010 ; addiu $v0,$v0,0x100` naming one of two runs), and one mutation — *the rule stops
checking whether anything references it* (the run-selector loses its size floor) — because a class called
"referenced" that fires without a reference would be the worst kind of wrong. `--lint` clean (3/3); **audit parked**
(M342's state).

## Numbers

- **14 classes**; `referenced_data` **16 132 B** in 60 runs, 857 materialising sites
- `unclassified` **72 384 → 56 252 B (2.9 %)** = 209 profiled runs (56 096 B) + six read records (156 B)
- byte map **17 → 18 cases**; probe cases re-based on the smaller population (**135/135**); audit **157 → 158 mutations**
  (lint-clean, not run); **recovered 155 / 154 byte-exact — unchanged**
