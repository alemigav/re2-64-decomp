# M436 — libultra is a source of names, not of bytes; and the preprocessor we did not know we had

The third-party critique ranked "libultra and SDK identification" as a free pass: library code is byte-identical
across N64 titles, so a matching libultra is a reference that costs nothing. The premise is true in general. It is
**false for this cartridge**, and the measurement is small and repeatable.

## 1. The asset found on the way

`build/toolchain/mips-gcc-2.8.1/bin/` shipped **only `cc1`** — which is why every tool in this repository
hand-assembles a preamble and why `cc1` is always invoked directly, with no preprocessor, on a body whose comments
were stripped by regex. The gcc 2.8.1 **build tree survived** at `build/toolchain/src/gcc28-build`, and `cpp` is a
target in it:

```
cd build/toolchain/src/gcc28-build && make cpp      # -> cpp, a native arm64 Mach-O, 188 520 B
```

That is the genuine 1998 preprocessor, built from the same source as the `cc1` this project has been using since M1.
It means real C — `#include`, `#ifdef`, macros — can now be compiled at full fidelity, which nothing here could do
before. It is a build artefact under gitignored `build/`, so **it is not committed**; the recipe above is the record.

**It buys nothing for the 278 refusals.** Measured: **0 of 3 473** bodies in the map contain a `#` directive at all,
refused or not. The preamble problem is not a missing-preprocessor problem.

## 2. The channel, measured

The reference is `decompals/ultralib` — a reverse engineering of libultra, **445 `.c` files** across 24 libraries,
supporting both IDO and GCC builds and nine libultra versions (`VERSION_D`=1 … `VERSION_L`=9). It carries **no
licence** (`license: null`), exactly like the RE2 sibling at M369, so it is used here to measure and never copied.

Four functions in our `boot` image that we have already named, each preprocessed with our own `cpp`, compiled with
our own `cc1`, assembled, linked at the cartridge address and compared word for word:

| function | our address | words | best of every combination |
| --- | --- | --- | --- |
| `osCreateThread` | `0x80006D60` | 52 | **20** |
| `osRecvMesg` | `0x8000C9E0` | 73 | **3** |
| `osSendMesg` | `0x8000CB60` | 76 | **5** |
| `osStartThread` | `0x8000DB90` | 70 | **26** |

The search was not small. `osCreateThread` was scored under **all nine versions × three debug states × five flag
sets** — including the documented libultra profile (`-O3 -mips3 -G 0 -mgp32 -mfp32 -funsigned-char`) and this
project's own (`-O2 -G 0 -mips2 -mcpu=r4300`):

| versions D–J | versions K–L | with `-mgp32 -mfp32` | documented `-O3 -mips3` |
| --- | --- | --- | --- |
| 20/52 | 16/52 | no change | **12/52** (worse) |

Flat across the version axis, unaffected by `-DNDEBUG`, and the documented libultra flag set is *worse* than the
game's own. **For comparison, this project's own reconstruction of the same body has stood at 23 of 52 since
M298** — the reference source scores below our own reading of the image. There is nothing here to import.

## 3. Why the version axis could not have saved it

The attractive form of the hypothesis was "the library region was built with IDO, the game code with gcc", which
would have explained the residues this project closed as allocation walls. **IDO is already refuted on a
fingerprint, not a byte diff**: the cartridge writes a register move as `addu rd, rs, $zero`, IDO emits
`or rd, rs, $zero`, and counting both across every function range shows the cartridge is GNU-flavoured
(`compile_probe.py:13`). A single-compiler cartridge is consistent with M357, which found our own corpus
**discriminates** between gcc 2.7.2 and 2.8.1 at 94 versus 39 of 94.

So `osCreateThread` at `0x80006D60` — one of the four named residues — stays a residue. The reference implementation
of the same routine, from the project that has dedicated itself to reproducing libultra, does not produce our bytes.

## What this settles

- **libultra is usable for identification and naming, not for closures.** A name is a fact about a function's
  behaviour; a byte match is the only currency this repository accepts, and there is none here.
- **The 40 % goal is not reachable through this channel.** Four functions is 0.1 % of 3 664, and the four were the
  *favourable* cases — already named, already studied, in the image where the reference most plausibly applies.
- **The preprocessor is the asset.** It did not help the refusal block (0 of 3 473 bodies carry a directive), but it
  removes a standing limitation for any future work that reads real C rather than decompiler pseudo-C.

## Numbers

- `cpp` built from gcc 2.8.1: **188 520 B**, native arm64; **9 × 3 × 5** combinations exercised on one body, **24** on the matrix
- `osCreateThread` **20/52** best (versions D–J), **16/52** (K–L), **12/52** documented libultra flags, **23/52** our own
- `osRecvMesg` **3/73**, `osSendMesg` **5/76**, `osStartThread` **26/70** — none exact, none close
- `#` directives in the corpus: **0 of 3 473** — the preprocessor is orthogonal to the refusal block
- nothing committed from the reference; `build/ultralib` is a gitignored clone, as at M356
