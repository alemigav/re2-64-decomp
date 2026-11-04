# M320 — the 4-word misses and the tail: five truncated extents, no new functions

Both batches came back empty, and the reason is the same one twice: these entries are not functions the compiler
would produce from the code we think we are looking at. What the tail *did* produce is a census defect — **five
functions whose declared extent is a fraction of their real one**, including a 95-word boot routine and the
highest-caller unmatched function in the corpus.

## 1. The five 4-word misses: second hypotheses spent, all residues

| candidate | second hypothesis | result |
|---|---|---|
| `boot:0x80000f50` (`*pp = **pp` with `$t9`) | keep the loaded pointer in a local so two registers are live | 2/4 — still one register |
| `boot:0x8000be50` (read `0xA4600010`) | address in a `volatile` local pointer | 2/4 — the access stays *before* `jr ra`; the image puts it **in** the delay slot |
| `boot:0x8000db10` / `0x8000db70` (`0xA4040010`) | same | 2/4, same three words |
| `stage2:0x8006b364` (`sltu; subu`) | identical ternary arms; `if (a<b) {}` dead compare | 2/4 — gcc **eliminates** the dead compare, the image keeps it |

Four are the sinking/register families already characterised (M309-M311). The fifth is a **dead `sltu`** whose
source I cannot produce: two hypotheses that should have left it in place did not, and the extent is confirmed
correct (the preceding function ends at its own `jr ra`, 16 bytes earlier).

## 2. The tail is mostly a census defect, not a set of stubs

Thirteen unmatched leaves at 2-3 words. The screen rejects nine for "no `jr ra`" — but **the call graph says five of
them are called**, which a stub cannot be. `tools/leaf_screen.py` gained `--called`, which crosses the two and walks
each suspect to its first `jr ra`:

| image | address | census | true | callers |
|---|---|---|---|---|
| stage2 | `0x8004276c` | 3 w | **46 w** | **96** |
| stage2 | `0x80042824` | 3 w | **46 w** | 20 |
| boot | `0x80000dd4` | 5 w | **95 w** | 7 |
| stage2 | `0x800421b4` | 3 w | **46 w** | 3 |
| boot | `0x80000518` | 2 w | **32 w** | 1 |

The three 46-word entries are one family — a **64-bit fixed-point transform**: eight `s16` taps from `a0`, three
`u16`/`u32` coefficients from `a1`, `dmult`/`mflo`/`dadd`/`dsubu` accumulation, three results stored back through
`a2`, and `daddu v0,a1,zero` as the return. The `0x8004276c` / `0x80042824` pair differs only in `sh` vs `sw`
outputs. **`0x8004276c` has 96 callers — it is the highest-caller unmatched function in the corpus**, and for 240
milestones the index has called it a 3-word stub.

The remaining four 2-3 word entries are genuinely what they look like: two write `k0`/`at` with no return, and two
(`0x8008f190`, `0x8008f320`) are mid-function fragments that never reach a `jr ra` in 96 words.

## 3. A boundary question, recorded rather than forced

`boot:0x800115b0` was the tail's one screen-passing candidate, and it nearly registered: `lui; ori; lw; jr ra` plus a
delay slot. **The delay slot is one word past `BOOT_SIZE`** — `0x800115c0`, where `BOOT_SIZE = 69952` ends exactly —
so the function's five words are four inside the declared boot window and one outside it. It is **not registered**:
changing a measured constant to fit one function is its own decision with its own evidence, and this is not it.

Two tool corrections fell out of that:

- **`--try` scored an out-of-window word as a match.** An empty slice decoded to `0` and a `nop` is `0`, so the
  boundary function reported **5/5** while only four words were available. It now reports
  *"the function runs past the boot window (4 words available of 5)"* and exits 2.
- The same latent flaw in `called_report` is why the table above prints `5 w` for that entry: the walk adds the delay
  slot unconditionally. Stated here rather than silently fixed, because the window is the thing being questioned.

## 4. What this buys

- **No new functions.** Recovered stays **129 / 128 exact**.
- One new gate case pinning the five truncated extents, and `leaf_screen.py --called` — the report that finds this
  class, which is how a 96-caller function gets noticed instead of skipped.
- The next target named precisely: **`stage2:0x8004276c`, 46 words, 96 callers**, with its shape decoded. It needs an
  extent correction (the fixture already carries extents, so registering it *is* the correction) and a C draft for
  64-bit fixed-point accumulation — a real reconstruction, not a transcription.

## Numbers

- compile probe **115 → 116 cases** (116/116 pass); tree **1 101 → 1 102 cases** (805 cartridge-gated)
- recovered **129 / 128 exact** — unchanged; suites 74, tools 101 — unchanged
- `tools/leaf_screen.py` gained `--called` and the window guard
