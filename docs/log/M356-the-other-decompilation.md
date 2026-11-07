# M356 — the other decompilation: 1 525 claimed, 51 survive our gate, 15 are new

There is a second *Resident Evil 2* (N64) project — `delibrete/Resident-Evil-II-Decompilation-N64` — built by
`decompdecomp`, an AI-agent harness, and it claims **1 525 byte-exact functions** against this project's **168**. The
obvious question is whether it is a shortcut. It is not, and the reason is measurable in twenty seconds:

> **Scored through this project's own pipeline against this cartridge, 51 of 693 comparable functions are
> word-exact — and 15 of those are functions we had not reconstructed.** Everything else about that corpus is a
> *candidate*, which is what it was treated as.

## 1. Why it cannot be taken on trust

| | theirs | ours |
| --- | --- | --- |
| ROM | `rom.overlays.z64`, sha1 `93187c4145cad272a255c17657cd9a1011b3fb3a` | `NREE` rev 1 cartridge, sha1 `62ec19bead748c12d38f6c5a7ab0831edbd3d44b` |
| toolchain | **eight**, over **70 address ranges** (`gcc-2.7.2-kmc` 26 ranges, `gcc-2.8.1-pm-sn-as` 16, `sn-n64-281` 13, `sn-n64-272-*` 12, `gcc-2.8.1-pm` 2, `ido-5.3` 1) | one pinned profile: gcc 2.8.1, `-O2 -G 0 -mips2 -mcpu=r4300`, `as -g` |
| verdict | their judge, their ROM, their toolchain | our compile, our bytes, gated |

Their sources are m2c-style machine drafts, one file per function, headers per source unit, and 6 152 notes from the
agents that produced them. The corpus is **never committed here**: it is somebody else's reconstruction of a commercial
game, it lives under gitignored `build/other-corpus/`, and `tools/other_corpus.py` prints a refusal rather than
reaching for the network when it is absent.

The decisive data point is one function we both worked: **`osCreateThread`**. They call it exact; we have it at **23 of
52** since M298. Their C, compiled here, scores **23 of 52** — the same residue, to the word. The difference between
their verdict and ours is not the C. It is the compiler binary.

## 2. Three defects in *our* harness fell out before any function was banked

Each cost a sweep to find and each is recorded because the next person to score an outside corpus will hit them.

- **`cc1` has no preprocessor.** Measured, not assumed: `#define X 5` followed by `return X;` compiles to *"`X'
  undeclared"*. Every `M2C_FIELD(a, s32 *, 4)` in their corpus was reaching the parser unexpanded, where the comma in
  the type is a parse error — which is why the first sweep lost **393 of 882** candidates to "compile failure" and
  found only 43 hits among the plain-C remainder. `tools/other_corpus.py` expands the four `M2C_*` macros itself, and
  the compile failures dropped to **27**.
- **`.rodata` was discarded, so a constant pool was a link error.** Their drafts carry float and string pools; the
  probe's link script discards the section. The scoring harness *places* it at `0x90000000` instead — far from the
  function, so the words being compared cannot move — and 10 more candidates compiled.
- **`leaf_screen.py --try` crashed instead of reporting** when `cc1` wrote non-UTF-8 bytes to stderr: `subprocess.run
  (text=True)` raised `UnicodeDecodeError` and the tool died with a traceback. Fixed by decoding leniently, because a
  tool that cannot say *why* a compile failed is the defect M351 named.

## 3. What the corpus actually yields

```
1 525 claimed matches · 1 109 single-function sources · 693 compiled and compared
  51 word-exact (7.4 %)   15 of them new to this project   219 words
  27 compile failures     8 link failures                 688 at addresses outside our images
```

The 688 "outside" are the honest part of the transfer: their overlay layout is **not** ours. Their `func_80162F04`
sits four bytes from our masked loop at `0x80162F08`; their `func_80161C70_overlay_011` is not our `ovl_008900e` base
of `0x80161CF0`. So the corpus can corroborate the *boot* image, where the two address spaces agree (210 of our 215
functions are in their layout), and it cannot reach the overlays at all without an alignment exercise that is worth its
own milestone and not this one.

The **15** registered, all in `boot`, all word-exact under this profile:

| address | words | | address | words | | address | words |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `0x800042F4` | 31 | | `0x80004BAC` | 14 | | `0x8000DE9C` | 10 |
| `0x800022BC` | 22 | | `0x800048B0` | 12 | | `0x800013B0` | 9 |
| `0x8000E920` | 22 | | `0x8000D66C` | 11 | | `0x8000490C` | 7 |
| `0x8000E800` | 21 | | `0x8000319C` | 10 | | `0x80004A50` | 7 |
| `0x80002314` | 19 | | | | | `0x80004EC4` | 7 |
| `0x80004550` | 17 | | | | | | |

Their text is kept as published — the `M2C_UNK` types are m2c's — and the only thing that makes each of them a claim
here is the case that re-derives it: `compile_probe.py --check` went **137 → 152 of 152**.

**And twelve more are queued as seeds**, not banked: functions at our own addresses, at our own size, that come back
75–96 % identical — `0x80004594` 17 of 18, `0x80004B5C` 18 of 20, `0x80009120` 18 of 20, `0x8000E0A0` 19 of 24,
`0x80008FE0` 30 of 38. A near-miss with the right length is exactly the input the permuter and the statement-order
levers want, and they are named here so the next milestone starts from a draft instead of from nothing.

## 4. The lead this opens, stated as a lead

Their **70 compiler ranges over 8 toolchains** is a direct challenge to this project's single pinned profile — and it
is the only hypothesis on the table that could move the residues we have *closed as allocation walls*: `0x8007E590`
226/229, `osCreateThread` 23/52, and the four 25/53/32-word groups. If the original build really did use different
compilers for different address ranges, then "no flag in 25 moves it" was the wrong question and the right one is
"which compiler built *this* function". That is a testable claim against **our** corpus — take a function we have
closed as exact, and see whether any of the eight profiles reproduces it — and it is not tested here.

## Numbers

- **+15 functions** imported and re-verified; recovered **168 → 183**, byte-exact **167 → 182**
- composition **16 hand + 55 singles + 97 copies + 15 imported = 183**; compile probe **137 → 152 of 152**
- new suite `other corpus (repository)` **16/16**; tree **75 → 76 suites / 1 163 → 1 179 cases** (323 runnable, 856 gated)
- `tools/other_corpus.py` — 103 tools; the corpus itself is gitignored and never committed
- the transfer rate, stated plainly: **51 of 693 (7.4 %) word-exact, 15 new, 219 words** — and the 688 functions at
  addresses outside our images are why the overlays remain untouched by it
- `unclassified` **440 B (0.0 %)**, **15 classes**, coverage **63.2 %**; `verify.py --full` **PASS**, audit 160/160

---

## Retracted by M361/M366 — "never committed here"

§1 says the corpus is **"never committed here: it is somebody else's reconstruction of a commercial game, it lives
under gitignored `build/other-corpus/`"**. That is true of the *corpus* and false of its **output**: M359 built
`fixtures/decomp/imported/` and M361–M366 filled it with **170 C files committed verbatim**, and `THIRD_PARTY.md`
did not mention them until M366.

The sentence stands only for the download. What it should have said is that *the source text is what must not be
committed without a licence*, and that project publishes **no licence at all** — no `LICENSE`, `COPYING` or
`NOTICE` — so the committed text is all-rights-reserved third-party work. `THIRD_PARTY.md` §0a states the
position and three options; the choice is the owner's, because it is a legal one.

The **verification** is unaffected: every imported function is byte-exact against this cartridge under this
profile, re-derived by its own case. Verification is not a licence, and this note had the two confused.
