# M315 — the first singles batch: three of ten, one draft each

Switching from cohorts to singles: one draft per function, no searching. Ten small leaves, disassembled together,
drafted once each.

## The batch

| candidate | words | verdict |
|---|---|---|
| `boot:0x80000518` — `b .` + `daddiu a0,a0,1` | 2 | **not C** — a branch to itself |
| `boot:0x800006d0` — `lui k0,… / addiu k0,…` | 2 | **not C** — writes the kernel temp `k0` |
| `stage2:0x80018a80` — `j … / addi at,zero,4032` | 2 | **not C** — the stage-2 entry stub, writes `at` |
| `boot:0x80007000` — `mfc0 v0,$9` | 3 | **not C** — reads CP0 `Count` |
| `boot:0x800072d0` — `mfc0 v0,$12` | 3 | **not C** — reads CP0 `Status` |
| `boot:0x8000de30` — `mtc0 a0,$11` | 3 | **not C** — writes CP0 `Compare` |
| **`stage2:0x80035e34`** — `jr ra; move v0,a1` | 2 | **exact** — `u32 f(u32 a, u32 b) { return b; }` |
| **`stage2:0x8004d184`** — `jr ra; sh zero,0(a0)` | 2 | **exact** — `void f(u16 *p) { *p = 0; }` |
| **`stage2:0x800ab574`** — `jr ra; srl v0,a0,8` | 2 | **exact** — `u32 f(u32 a) { return a >> 8; }` |
| `boot:0x8000e7f0` — `lui; lr ra; lw` | 3 | **residue** — ours emits `lui; lw; jr ra`: the load is not in the delay slot |

**Three of ten.** The rate is the point of the batch: six of the ten are not C at all — they are hand-written assembly
(a branch to itself, `k0`/`at` writes, CP0 moves) — which is a useful fact about the corpus rather than a failure:
**the smallest "functions" are disproportionately not compiler output.** The tenth is a scheduling residue (the load
not sunk into the delay slot), which is the family M309–M311 characterised; per the one-draft rule it is not pushed.

## What registering them took

One draft each, then the machinery: three source constants, three probe cases, three fixture entries, republish.
That is the cost per single — and it is why cohorts were worth 59 functions for eight drafts and singles are worth
one apiece. **The singles route pays 1:1, so it is only worth taking where the body is trivial**: these three are
two words each.

One small correction the batch exposed: `single_probe()` first asserted `compiled == words`, which fails on every
function shorter than `as`'s 16-byte padding (a 2-word function compiles to 4 words of `.text`). The assertion is
now `matched == words`, and the case text says how much of the object is padding.

## Numbers

- **recovered 75 → 78**, byte-exact **74 → 77**
- compile probe **64 → 67 cases** (67/67 pass); tree **73 suites / 1 042 cases** (756 need the cartridge)
- `src/`, ranges, ladder, map and call graph re-derived from the fixture

## What the singles route is good for

Not throughput. Six of ten were not C, and the C ones were two words: **the singles corpus is mostly glue and
hand-written stubs**, so the marginal function costs a fixture entry and about a minute. It is worth sweeping for
the *easy* tail (2–3 words, `jr ra` plus one instruction) and not worth hand-scheduling residues one at a time —
that is what the cohorts were for.
