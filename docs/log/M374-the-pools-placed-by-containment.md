# M374 — the thirteen pools placed by containment, and `make check` becomes a verdict

M371 made the corpus build and reported **194 exact / 13 differ of 207**. Twelve of those thirteen were byte-exact
reconstructions whose **constant pool** — a jump table the C indexes through — was parked at `0x90000000`, because "the
image's own address for that pool is per-function knowledge". That was half true: it is per-function knowledge, and
**the repository already had it**.

## The derivation

`manifests/jump_tables.json` records every `(dispatcher, table)` pair `find_jump_tables.py` found in the images. Keyed
by *dispatcher* — an address inside the function that reads the table — which is exactly what containment needs:

```
the unique table whose dispatcher lies inside [addr, addr + 4·words)
```

All thirteen resolve, one each, and twelve of the addresses equal a constant `compile_probe.py` places **by hand**:

| function | extent | dispatcher | table | probe constant |
| --- | --- | --- | --- | --- |
| `0x80024558` | 139w | `0x80024578` | `0x800b69b0` | `P8_TABLE` |
| `0x8004fd1c` | 98w | `0x8004fd28` | `0x800b8bd0` | (a literal in `HEADS`) |
| `0x80057e1c` | 84w | `0x80057e38` | `0x800b8f78` | `P7_TABLE` |
| `0x80059530` | 206w | `0x80059550` | `0x800b9010` | `P59530_TABLE` |
| `0x80059868` | 167w | `0x80059884` | `0x800b9040` | `P59868_TABLE` |
| `0x8006e68c` | 41w | `0x8006e6c8` | `0x800b9540` | `P6E68C_TABLE` |
| `0x8006fc5c` | 53w | `0x8006fca8` | `0x800b95d8` | `P6FC5C_TABLE` |
| `0x8006ff48` | 98w | `0x8006ff50` | `0x800b95f8` | `P6FF48_TABLE` |
| `0x80070120` | 46w | `0x80070164` | `0x800b96a8` | `P9_TABLE` |
| `0x800701d8` | 141w | `0x800701e4` | `0x800b96c8` | `P701D8_TABLE` |
| `0x800704e0` | 123w | `0x800704ec` | `0x800b9778` | `P704E0_TABLE` |
| `0x8007e590` | 229w | `0x8007e5ac` | `0x800b9c78` | `P7E590_TABLE` |
| `0x800acae4` | 53w | `0x800acb2c` | `0x800ba890` | `PACAE4_TABLE` |

`pool_address()` returns the table, `None` with "no dispatcher in extent", or `None` with the list of candidates when a
body dispatches twice — **reported, never guessed**, because a wrong pool is indistinguishable from a code difference
and that is the confusion this tool exists to end. A table that lies *before* the body's end also falls back: `ld`
cannot move the location counter backwards, so placing it would fail the link rather than test anything.

## The result

```
209 exact, 1 differ (13 with the image's own pool address placed); unexpected differences: 0
```

**Twelve functions moved from "differs" to "exact" without a single line of C changing.** The one that remains is
`0x8007e590` at its published **226 of 229** — a code residue, not a pool.

## `make check` is a verdict now

Until this milestone `build_corpus.py --check` exited non-zero whenever *anything* differed, which was always, so the
target had never once been green and the number it printed was a report rather than a gate. It now fails only when a
body the fixture calls **byte-exact** fails to match — a published partial is allowed to differ, a regression is not.
`make check` exits **0** for the first time, and it exits 1 if any of the 209 byte-exact bodies stops matching.

## The gate, and its counterfactual

Suite `corpus build (cartridge)` gained a second case: **every table the probe places by hand must also be found by
containment** — 12 constants, 12 found. It is manifest-only, so it would hold with every compile skipped, and it is the
cross-validation between two independent sources: a hand-typed constant in the probe and a detector's output in a
manifest. Pointing `table_map()` at an empty manifest prints

```
FAIL every table the probe places by hand is also found by containment: 12 constant(s), 0 found -- missing [...]
```

so the case is finished in the sense this project requires: shown able to fail.

## What this changes

`recovered` **210 / 209**, `F1` **3 457** unchanged — the build ledger is the fifth ledger and it moved without moving
the understanding one, which is the distinction M369 established. `make check` **197 → 209 of 210**. Tree **78 suites /
1 303 → 1 304 cases** (341 runnable, **962 → 963** gated).
