# M357 — the per-range toolchain: tested against our own corpus, and refuted

The other project's `decompdecomp.json` carries a **per-range toolchain map**: **70 address ranges over 8 compilers** —
`gcc-2.7.2-kmc` for 26 of them, `sn-n64-281` 13, `sn-n64-272-*` 12, `gcc-2.8.1-pm*` 18, `ido-5.3` 1 — with a default of
`gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2` over everything else. M356 named that as the only live hypothesis that
could move the residues this project closed as *allocation walls*. **It does not survive contact with our corpus**, and
the measurement that kills it also sharpens something we did not know: **our corpus discriminates between gcc 2.7.2
and 2.8.1**, at 39 versus 94 of 94.

## 1. What the map actually claims, in our address space

| | |
| --- | --- |
| address space its 70 ranges cover | **10 505 B** of `0x800004e8`–`0x801849fc` |
| our 183 recovered functions inside a claimed range | **13** (7 `sn-n64-281`, 3 `gcc-2.8.1-pm-sn-as`, 2 `gcc-2.7.2-kmc`, 1 `sn-n64-272-0004`) |
| our 183 recovered functions outside every range | **170** — their default, `gcc-2.7.2-kmc -mips3 -mgp32 -mfp32 -O2` |
| **all four residues** (`0x8007e590`, `0x80006d60`, `0x80059868`, `0x80059530`) | **outside every range**, i.e. the map's default |

So the map is not a claim that the cartridge was built by eight compilers; it is a *residual device* — where
decompdecomp's default profile failed, an agent was allowed to pick another. That matters for what follows: the map
makes a falsifiable prediction about the four functions we most want explained, and it predicts **KMC gcc 2.7.2**.

## 2. The experiment: four profiles we can actually run

`tools/toolchain_matrix.py` compiles every source in `fixtures/decomp/recovered.json` under each profile and compares
against this cartridge, with the **assembler held constant** across profiles (`as.new -EB -mips2 -mcpu=r4300 -g -G 0`),
because the architecture is r4300 whatever the compiler thinks. The first run got this wrong — `-G0` without `-mips2`
makes `as.new` reject `beql`, which reported "no score" for a function whose draft assembles perfectly — and that
artefact is why the profile list now pins the assembler and says so.

| profile (107 source groups, 94 compiled here) | exact | `0x8007e590` (229 w) | `osCreateThread` (52 w) |
| --- | --- | --- | --- |
| **ours: 2.8.1 `-O2 -G 0 -mips2 -mcpu=r4300`** | **94 / 94** | **226 / 229** | 23 / 52 |
| their flags on our compiler: 2.8.1 `-mips3 -mgp32 -mfp32` | 81 / 94 | 66 / 229 | 13 / 52 |
| their default compiler: **2.7.2** `-mips3 -mgp32 -mfp32` | 39 / 94 | 8 / 229 | **40 / 52** |
| 2.7.2 with **our** flags (`-mips2`) | 39 / 94 | 8 / 229 | **40 / 52** |

## 3. Three findings

**The per-range map buys nothing.** Of the 39 functions gcc 2.7.2 reproduces, **39 are also reproduced by the pinned
profile and 0 are reproduced only by 2.7.2** — every one of those 39 is 2 to 12 words, the size at which two compiler
generations agree because there is nothing to decide. There is no function anywhere in our corpus that needs a
compiler other than the one we pinned, and there is no function it reproduces that we were missing.

**Their flags are worse than ours on our own compiler.** `-mips3 -mgp32 -mfp32` costs 13 of 94 exact functions on gcc
2.8.1 and takes the 229-word dispatcher from 226 to 66. Whatever the `-mips3/-mgp32/-mfp32` spelling was for, it is
not this cartridge.

**And the compiler generation is now discriminated — which is new.** gcc 2.7.2 reproduces **39 of 94**, gcc 2.8.1
reproduces **94 of 94**, and the difference is the compiler and not the flags (2.7.2 scores 39 under *both* flag sets).
Before this milestone the corpus said "gcc 2.8.1 reproduces every probe"; it now says something stronger and more
useful: **the corpus cannot have been built by 2.7.2**, so a claim of the form *"range X used gcc-2.7.2-kmc"* is
contradicted for every one of the 170 recovered functions that fall under the map's 2.7.2 default.

## 4. The one number that moved the right way, and why it is not a lead

`osCreateThread` is **40 of 52 under gcc 2.7.2** against **23 of 52 under ours** — the only entry in the matrix that
improves, and a better residue than the one we have published since M298. The obvious rescue is the one M296 raised as
a caveat: libultra shipped as a prebuilt object (`libultra_rom.a`), so perhaps the *runtime* was built by a different
compiler than the game. **That rescue is cut by the same table**: `osSetEventMesg` is libultra too, and it prefers ours —
**24 of 24 against 22 of 24** under 2.7.2 — and `osCreateMesgQueue` is 9 of 9 under both. A runtime built by 2.7.2
cannot have one function preferring 2.7.2 and the next preferring 2.8.1.

So 40 of 52 is recorded as what it is: a *different* twelve-word residue under a compiler that cannot build the image
around it, not progress on the residue we have. Chasing it would mean publishing a function no neighbouring function
can vouch for.

## 5. What is not tested, stated rather than implied

- **`gcc-2.7.2-kmc` is not `gcc 2.7.2`.** KMC shipped a patched tree; our build is the vanilla 2.7.2 from the
  project's own provisioning. A profile that *fails* here therefore refutes their *KMC* only as far as the generation
  and the flags go — but the direction is one-way and that is enough: a profile that *succeeds* would have been
  evidence, and none did.
- **`sn-n64-281`, `sn-n64-272-*`, `gcc-2.8.1-pm-*` are binaries we do not have** and cannot test at all. Their 13
  in-range functions that our profile reproduces exactly (13 for 13, including a 30-word `main` their map assigns to
  `sn-n64-281 -mips3 -mhard-float` and a 9-word `0x800013b0` it assigns to `sn-n64-272-0004 -O1`) are therefore
  *not evidence that our profile is what produced them* — different compilers can agree on a function. What they show
  is that the per-range choices are **not necessary** for anything we can test.
- **13 of the 107 source groups do not compile in this harness** (families whose externs live in tuples the matrix does
  not read), so the denominators are 94, not 107. The `--check` gate states the invariant on the 94 it does compile.

## Numbers

- **the hypothesis is closed**: no function needs a compiler other than the pinned one, and no alternative profile
  closes a residue — `0x8007e590` **226 → 66 → 8** and `osCreateThread` **23 → 13 → 40** across the profiles
- **the compiler generation is now discriminated**: 2.8.1 **94/94**, 2.7.2 **39/94**, the same 39, none exclusive —
  so the corpus cannot have been built by 2.7.2
- new suite `toolchain matrix (cartridge)` **4/4**; tree **76 → 77 suites / 1 194 → 1 198 cases** (323 runnable, 875 gated)
- `tools/toolchain_matrix.py` — 104 tools; profiles, the assembler-constant rule and the limits live in the tool
- recovered **183 / 182 byte-exact** and every ladder figure unchanged: this milestone measured, it did not bank
- `unclassified` **440 B (0.0 %)**, **15 classes**, coverage **63.2 %**; `verify.py --full` **PASS**, audit 160/160
