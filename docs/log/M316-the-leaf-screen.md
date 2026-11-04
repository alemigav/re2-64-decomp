# M316 — the leaf screen: 16 of 16, and a reusable selector

The screen asked for: leaves with a trailing `jr ra`, no `k0`, no `at`, no CP0. It found **72 candidates of 2–8
words** in the remaining 851 leaves, and the first 17 (all 3 words) yielded **16 exact functions, one draft each**.

## The screen

Rejects, in order: no `jr ra` in the last three words; any CP0 instruction (`opcode 0x10`); a branch to itself; any
instruction that **writes** `$1` (`at`) or `$26` (`k0`); `jr`/`jalr` through either. That is what separates a
compiled function from hand-written assembly, and it is mechanical — the six misses in M315's batch were all caught
by it, and nothing it admitted has failed yet.

| candidates | words |
|---|---|
| 17 | 3 |
| 17 | 4 |
| 8 | 5 |
| 12 | 6 |
| 9 | 7 |
| 9 | 8 |
| **72** | **2–8** |

## The batch

Sixteen of the seventeen 3-word candidates landed on the first draft; the seventeenth
(`boot:0x8000e7f0`) is the known load-not-in-the-delay-slot residue and was screened out by hand. The shapes:

| shape | examples |
|---|---|
| sequential field stores | `p[8]=a; p[9]=b`, `*(u16*)(p+6)=0`, two `sw zero` |
| a masked or shifted return | `(a & 0xff) + 63`, `(a + 4) << 1`, `(u32)(a - 14) < 6` |
| a store into a fixed global | `D_801137D0 = a`, `D_8012BD80 = a`, `D_80147FD0 = 0`, byte/word variants |
| a single byte in a big struct | `p[4573] = 4` |

One failure was **my arithmetic, not the shape**: `lui 0x800f; sw a0,-28408` is `0x800F0000 − 0x6EF8 = 0x800E9108`,
and I had written `0x800E9028` (carried over from M313's group). Fixed in the same draft, re-measured 3/3. Worth
recording because the symptom was a *one-word* diff in the offset — the address, not the instruction, was wrong,
and the fix is to compute `hi_base − imm` explicitly rather than pattern-match a constant seen before.

## What was built to make this repeatable

- `SINGLES` in `tools/compile_probe.py`: one table entry per single — `(source constant, image, address, words,
  symbols)` — and **one probe case generated per entry**, so registering the next batch is data, not code.
- `recovered.json` grew by 16, and all four projections (`src/`, ranges, ladder, call graph) plus the map were
  re-derived from it.

## Numbers

- **recovered 78 → 94**, byte-exact **77 → 93**
- compile probe **67 → 80 cases** (80/80 pass); tree **73 suites / 1 055 cases** (769 need the cartridge)
- 16 functions for 16 drafts, and no wall in sight: the clean bodies at 2–8 words are single-statement glue

## Next

The remaining 55 screened candidates (4–8 words) are the same kind of glue — field stores, masked returns, small
dispatches. At 16/16 the screen is worth running to exhaustion, and the constraint is now **registration cost**, not
recovery: each win is a table entry and a fixture line.

## Maintenance the batch exposed

Recovering a function that another tool cites as **evidence** breaks that tool's citation. Two of the sixteen
(`stage2:0x800a9420`, `stage2:0x800b4dac`) were cited by `tools/voice_descriptor.py` for a field write and a buffer
arithmetic, so the suite failed with *"does not contain `*(undefined1 *)(param_1 + 0x11dd) = 4;`"* — the evidence is
real but it now lives in our own text (`p[4573] = 4`, `return (a + 4) << 1`).

Both citations were **retargeted at the reconstruction**, with a comment recording that the offset is the same
(`0x11dd = 4573`) and the value identical, and the artefact was regenerated (`--write`) so its "sources unchanged"
check hashes the new files. Worth expecting on every future batch: **the corpus is an input to other tools' proofs**.
