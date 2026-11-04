# M319 — the leaf screen, a toolchain defect it exposed, and 20 functions from the 6-8 word pool

Two jobs from the plan — retry `0x80001180` as 16-byte records, then sweep the 6-8 word pool — plus the tooling that
made them repeatable. The tool earned its keep before the first draft: it exposed a gap in its own rules and a real
defect in the object files.

## 1. The screen is now a committed tool, and its own first run found two bugs

`tools/leaf_screen.py` carries the five reject rules (no `jr ra`; CP0; branch-to-self; writes `$at`/`$k0`; jumps
through them), a pure `--self-test` registered as a suite (11 cases), and a `--try` mode that compiles one draft
against one address and prints each differing word **decoded**.

- **The rules had a hole: `rd`.** They checked `rt` for "writes `$at`/`$k0`", but a SPECIAL instruction writes
  **`rd`** — so `sltu $at,$v0,$a1` passed the screen and turned up as candidate 20 of 30
  (`stage2:0x80135cb0`). Fixed; the pool went 30 → **29**, and the self-test gained the case that pins it.
- **The objects had a hole: a zero-sized section one byte past EOF.** Nine drafts failed to link with no useful
  message. The cause: binutils-2.7 `as` writes `.rel.text` with `sh_offset = 0x4e8` and `sh_size = 0` into a
  `0x4e7`-byte file, and **BFD 2.42 refuses the object outright** (*"a section extending past end of file"*) — and
  because it refuses, the usual `objcopy` normalisation (M300) cannot run either. Nothing reads the offset of a
  zero-sized section, so `compile_probe.normalise_object()` clamps it. Verified end to end on
  `stage2:0x80047b04`, which went from unlinkable to **7/7**.

## 2. `boot:0x80001180` — the record array was right

`return (u32)&D_80012150[i]` with `struct rec { u32 w[4]; }` gives the image's **5/5**, first hypothesis: the stride
of 16 is an array of 16-byte records, so the shift comes first and the base is materialised second, which is exactly
the order the plain `0x80012150 + (i << 4)` draft got wrong.

## 3. The 6-8 word pool: 19 of 29

| words | candidates | drafted | **landed** |
|---|---|---|---|
| 6 | 12 | 10 (2 are delay loops) | **9** |
| 7 | 9 | 8 (1 removed by the `rd` fix) | **7** |
| 8 | 9 | 7 (1 delay loop, 1 COP1) | **3** |
| **total** | **29** | **25** | **19** |

The eleven 7-word wins include a family of four: `if ((u16)v) p[N] = 2; else p[N] = 0;` at four addresses — one
draft, four functions, and the same "two separate epilogues" shape the image uses.

**Six misses, classified** — none was a mystery:

| candidate | diagnosis |
|---|---|
| `boot:0x80007010` (4/6) | `jr ra` / `lw` order — the **sinking** family (M309-M311) |
| `ovl_0072610:0x8017bbb0` (6/7) | `srlv` operand order — **register allocation** (M311) |
| `boot:0x8000be30` (0/8) | branch shape and two extra words — needs a different construct (not spent) |
| `stage2:0x80025d60` (2/8) | register permutation throughout — **allocation** |
| `stage2:0x8004341c` (6/8) | base address folded instead of materialised (`lui 0x8015` vs `lui 0x8014/addiu`) |
| `stage2:0x8009be80` (4/8) | `+0x18000` folded into the address where the image adds it as a constant |

**Four are not C at all** despite the screen: three delay loops (`bnel` to self) and one COP1 run. The screen cannot
catch those — they use no `at`/`k0` and end in `jr ra` — so they belong in the *not-C* column, not the residue one.

## 4. One inference from M318 is retired

M318 concluded that "the yield drops as soon as bodies are four words rather than three", and predicted a low return
above 5 words. The pool refutes that: **19 of 29 (66 %) at 6-8 words** against 9/17 at four words. The drop is not
about *size*, it is about **how many values stay live across the return** — the 6- and 7-word functions are still one
statement each, while the 8-word ones are where the misses concentrate (3 of 7).

## 5. Registration

20 new singles in `SINGLES` (data only — the case loop generates them), 20 fixture entries, and all five
projections re-derived. **Recovered 109 → 129, byte-exact 108 → 128.**

**The citation check caught one, and the plan's own grep almost missed it.** `tools/voice_descriptor.py` cites
`stage2:0x800b4d90` as the writer that sets the voice phase to 3 — and that function is one of the eleven 7-word
wins. Searching for the lowercase address found nothing because the tool writes `FUN_800b4d90.c`, with an uppercase
`B`; the gate found it, the manual grep did not. The citation is retargeted at our own line (`p[4573] = 3`, with
`0x11dd = 4573` noted) and the artefact regenerated. **Search case-insensitively next time.**

One derived number moved legitimately: the M312 duplicate census fell from **89/40/85/38** to **86/39/82/37**, because
the 7-word family we just recovered *was* one of its duplicate groups. The case now asserts the invariant
(`total == complete + fragments`, `fragments == 4`) instead of a snapshot, so the next recovery does not break it.

## Numbers

- compile probe **95 → 115 cases** (115/115 pass); leaf-screen suite **11 cases**; suites **73 → 74**; tools **100 → 101**
- tree **1 070 → 1 101 cases** (804 cartridge-gated, 297 runnable); recovered **129 / 128 exact**
- `tools/leaf_screen.py` new; `tools/compile_probe.py` gained `normalise_object()` and 20 singles
