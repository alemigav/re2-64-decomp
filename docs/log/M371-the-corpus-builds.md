# M371 — the corpus builds: a Makefile, 23 image ELFs, and 194 functions that link and match

Every milestone before this one *measured*. This one **builds**. `make` compiles every reconstructed function with the
canonical profile, links each at the address the cartridge puts it, and stitches the results into an image-shaped
binary — so the corpus is code that compiles and links, not only code that is described.

## 1. What it took

Four failures, each a real defect in the naive build, and each found by running it:

| failure | what it was | fix |
| --- | --- | --- |
| `cannot move location counter backwards` | one output section cannot hold functions placed at absolute addresses when a compiled body is **one word longer** than its measured extent (a trailing `nop`), which pushes the counter past the next function | one output section **per function**, each at its own address |
| `local symbol at index 7 (>= sh_info of 7)` | binutils 2.42 refuses to merge **objects from 2.7** in one link | link each function alone, exactly as the probe does, and stitch the results here |
| `--strip-all` as a workaround | it removes the symbols the **relocations** need, so every address-dependent word linked as zero and 194 functions "differed" | never strip; link per function instead |
| `` `.rodata' referenced in section `.text' `` | a function with a constant pool refers to a section that was being discarded | place `.rodata` at `0x90000000`, far from the words compared (M356's lesson, third customer) |

Two more mechanical ones: the symbols of a **constant-based** reconstruction live in the probe's `SINGLES` table and
not in the fixture, and some live in a `*_SYMS` constant — so the build reads all three channels the probe uses. Without
that, 52 functions failed to link on the first honest run.

## 2. What it produces

```
build/corpus/<image>.elf    23 images, an ELF per image
build/corpus/<image>.bin    the same as flat bytes, zero where a body is not recovered
build/corpus/index.json     every function: address, words, status, digest; and each image's share
```

`make check` compares every function against the cartridge **after** linking — the only place it can be compared, since
an object's `.text` still carries unresolved relocations:

```
194 exact · 13 differ  (of 207 reconstructed)
```

The 13 are named rather than rounded away. **Twelve** are functions whose constant pool is a **jump table** the image
places at a specific address (`0x800b9c78`, …); this build puts `.rodata` at `0x90000000`, so their table reference
differs while their code does not — they are recorded as `differs (constant pool not placed)` and are a named
follow-up, not a mystery. **The thirteenth is `0x8007e590`** at its published **226 of 229** — the corpus's own
residue, appearing in the build exactly as it appears in the probe, which is the build agreeing with its source.

## 3. Why it matters more than the count

Two things a reader asked for and could not get before:

- **`make` exists and `src/` compiles.** The corpus is no longer 200 files that compile one at a time under a probe.
- **an address-bearing image per ELF is the shape a static recompiler wants** (ELFs plus symbols). This is the first
  artefact here that a downstream tool could open. It is **not** a ROM: data and unrecovered code are holes, and each
  image reports the share it covers — `boot` 14 functions, `stage2` 145, overlays 1–4 each, between 0.0 % and 2.9 % of
  an image — so the honest reading is "the recovered parts link and match", not "the game builds".

That distinction is the same one the byte map makes between *claimed* and *understood*, one layer up: a build proves
the code links; it does not prove the image is complete.

## Numbers

- `Makefile` (`make`, `check`, `test`, `clean`), `tools/build_corpus.py` — 105 tools
- **194 of 207 functions link and match the cartridge**; 12 differ only on an unplaced constant pool, 1 is the published
  residue; **23 image ELFs** and 23 flat binaries
- new gated suite `corpus build (cartridge)` **1/1**; tree **77 → 78 suites / 1 284 → 1 285 cases**
- corpus unchanged (this milestone builds, it does not reconstruct): **207 / 206 byte-exact**, `F1` 3 454, rung 385
- `verify.py --full` **PASS**, audit 160/160
