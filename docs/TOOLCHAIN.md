# The toolchain: what is proven, what is hypothesised, and what the owner has to supply

A matching decompilation needs three things this repository does not vendor: a **MIPS assembler and linker**, the
**original compiler**, and a **linker layout** per image. This document keeps them separate, because they fail
for different reasons and are proved by different measurements.

**Status as of M245: all three pieces exist on this machine.** `mips-linux-gnu-as`/`-ld` (GNU 2.42) and
**IDO 5.3 and 7.1, recompiled to run natively** (`cc`, `as0`, `as1`, `ugen`, `uopt`, `ujoin`, `usplit`,
`upas`, `uld`). The stage-4 blocker is gone: the original compilers execute here and produce MIPS objects.

A probe through IDO 7.1 — `int probe_add(int a, int b) { return a + b; }` at `-O2 -non_shared -G 0 -mips2` —
emits `.text` `03e00008 00851021` = `jr ra; addu v0,a0,a1`, which is the N64-era form with the add in the
delay slot. So the toolchain is not merely present, it produces the idiom this cartridge uses.

Read the dates, not the optimism.

## 1. Assembler and linker — open source, being provisioned now

`splat` emits `.s` files. Without `mips-linux-gnu-as` and `-ld` they are text: no object, no link, no byte
comparison. `tools/toolchain/provision.sh` builds them from GNU source into `build/toolchain/` (gitignored).

```
sh tools/toolchain/provision.sh --doctor   # report only
sh tools/toolchain/provision.sh            # build, then report
```

**Measured obstacles on macOS 14 / Apple clang 17**, each one found by running it rather than reading about it:

| obstacle | what happened | resolution |
|---|---|---|
| `--disable-gas=no` | not a real flag; configure died | removed — my bug |
| configure run by relative path from the build dir | ran the wrong file, output sent to `/dev/null`, reported only "FAIL configure" | absolute path + log to `build/toolchain/configure.log` |
| binutils' **bundled zlib** vs the macOS SDK | `zutil.h` defines `fdopen(fd,mode) NULL` when `HAVE_FDOPEN` is undetected, which collides with `_stdio.h:322` | `ac_cv_func_fdopen` did **not** help (inline, exported, and `--without-zlib` all failed); the fallback is deleted from the build tree by a one-line patch that is re-applied every run from a fresh tarball |

The honest conclusion: **macOS is a bad host for 1990s binutils, but it is survivable.** The build works with
four workarounds (zlib `fdopen`, `MAKEINFO` as a make *command-line* variable, no texinfo, `--without-zlib`),
all encoded in `provision.sh` and all discovered by running it rather than reading about it.

**And binutils turns out not to be on the critical path.** IDO ships `as0`/`as1` (its assembler) and `uld` (its
linker), which is what the game was actually built with; the recompiler makes those native too. GNU `as` is
needed only if a probe wants splat's GNU-dialect output. Two assemblers, one of them the original, is a better
position than one.

## 2. The compiler — named by the SDK's own makefiles, still not runnable here

The owner supplied the **Nintendo 64 Developers Toolkit v5.2** disc (M247). It is a Mode-2 raw CD image; once
the sector framing is stripped it mounts, and inside:

| path | what it is |
|---|---|
| `pc/basic/data1.cab` (InstallShield, `unshield`) | 811 files: `NuSTD`, `NuSystem`, `misc` — the libraries and tools, **no compiler** |
| `sgi/n64kit52.tar` | the IRIX kit: `ccbl`, `HVQ`, `niff`, `nustd`, `nusys`, `misc` — again libraries, no `cc1` |

So the toolchain binary is not on this disc; what *is* on it is the build contract, and that is worth as much:

```
NuSTD/src/makefile:   CC = gcc          CFLAGS = -c -O -G 0 $(WFLAGS) ...
                      INCLUDES = -I$(GCCDIR)/mipse/include
NuSystem/sample/…:    LDFLAGS = … -L$(GCCDIR)/mipse/lib -lkmc
```

`gcc` for the **`mipse`** target (big-endian MIPS), **`-O` — not `-O2`** — and **`-G 0`**, with the runtime
named `-lkmc`. That corroborates the census that refuted IDO (§ below) and fixes the next profile to test.

To *run* it the options are, in order of cost: wine over the Windows-hosted gcc (not on this disc either), or a
native build of gcc 2.7.2 for the host — `n64chain` and `modern-n64-sdk` exist for exactly that, and they are
the next provisioning target. Until one of those exists, the probe corpus can test IDO and nothing else.

## 2b. The compiler question as it stood before the disc

The candidate set for a 1999 N64 title is small and none of it is guessable:

| candidate | why it is plausible | how it would be tested |
|---|---|---|
| **IDO 5.3** | the common N64-era SGI compiler | compile a probe corpus, diff against the image |
| **IDO 7.1** | used by later N64 titles; the Ocarina of Time toolchain | same |
| **gcc 2.7.2 / 2.8.1** | some 1999 titles used GNU | same |

`decompals/ido-static-recomp` (86★) recompiles **the original IRIX binaries** for a modern host. That means the
IRIX binaries must come from the machine's owner, and **this repository will not fetch, commit or redistribute
them** — a decompilation that ships its compiler has a licensing problem, not a shortcut.

Set `IDO_53_DIR` / `IDO_71_DIR` to directories holding the IRIX IDO binaries, and the doctor will say whether
the recompiler can use them. Until then the compiler question is **open**, and no function here has been
compiled against anything.

## 3. What "proven" means for each piece

| claim | evidence required | state |
|---|---|---|
| the split tiles an image | `splat_boot.py --check`: files tile `0x1000..0x12140`, every emitted file covers its extent word for word | **proven on boot** (M243) |
| the map reassembles the image | the same check: slicing the cartridge by the split's own extents reproduces 69 952 B byte for byte | **proven on boot** (M243) |
| the built image equals the cartridge | `match_diff.py`: `build/elfs/boot.elf` vs the ROM slice, 100.000 % | **proven on boot** (M242) |
| the emitted asm assembles | assemble it and compare the object's `.text` with the image | **possible now** — two assemblers exist; not yet run on splat's output |
| C compiles back to the original bytes | one function, one compiler profile, byte equality | **possible now** — IDO 5.3 and 7.1 both run; the measurement has not been made |

## 3b. The SDK-era assembler (M249)

`binutils 2.7` (1996) is built at `build/toolchain/src/bu27-build`, and it settles a question M247 could not:

| tool | `int f(int a){return a;}` | the cartridge |
|---|---|---|
| **binutils 2.7 `as`** | `00801021` **`addu`** | `addu` |
| binutils 2.42 `as` | `00801025` `or` | — |
| IDO's own `as1` | `00801025` `or` | — |

So the corpus no longer normalises `move` when the 2.7 assembler is present: the real tool does what the cartridge
does. With it, p1/p2/p4 are byte-exact and p3 is 6 of 8 (M249).

Two host problems, both recorded rather than papered over:

- **2.7's `ld` writes an empty file on this host.** It builds, runs, and produces zero bytes. Linking therefore
  uses 2.42's `ld`, with 2.42's `objcopy` first — 2.7 writes a `.symtab` whose `sh_info` modern `ld` rejects
  (*"local symbol at index N >= sh_info"*), and `objcopy` rewrites exactly that.
- **2.7's `configure` needs a modern `config.sub`.** It calls it with old-style multiple arguments, which a
  current `config.sub` rejects and which 2.7's own cannot answer for `aarch64-apple-darwin`; 2.42's copies work
  for both.

## 4. The compile probe, ready to run

When the toolchain exists, the first experiment is not "decompile a function" but "which compiler reproduces
code we already understand". The probe corpus should be chosen by codegen class, not by address:

- a leaf function with two arguments and no stack frame;
- a function with a save/restore frame (`addiu sp,sp,-N` + `sw ra`);
- a `switch` that compiled to a jump table (the corpus has 86 dispatch heads — `manifests/dispatch_heads.json`);
- a struct copy, where field widths and ordering show up immediately;
- a loop with a delayed branch (`bne` + delay slot), where scheduling is visible.

Each probe is a small C file plus the image's expected bytes, and the verdict is `match_diff.py`'s: the first
differing instruction, not a hash. A compiler profile that reproduces three of five classes is a lead; one that
reproduces none is a refutation worth publishing before anyone translates another function.
