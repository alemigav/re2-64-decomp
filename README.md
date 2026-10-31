# RE2-64 Decompilation

Decompilation research on **Resident Evil 2 (Nintendo 64, 1999)** — the MIPS III
big-endian port. Started 2026-10-30.

**The ROM is not in this repository and never will be.** Decompilation work legally
requires you to dump your own cartridge and keep it local. `rom/` is gitignored; the
tooling here operates on whatever you place there.

---

## Honest scope

A *complete* byte-matching decompilation of a 64 MB cartridge is a community-scale,
multi-year effort (reference: the N64 decomps that succeeded were 8–32 MB games with
dedicated teams). This project is therefore staged so that every milestone is useful on
its own, and so the expensive part is only entered with evidence:

| Milestone | Deliverable | Status |
|---|---|---|
| **M0** | Toolchain proof: MIPS big-endian decompiles in this stack | ✅ **done 2026-10-30** |
| **M1** | ROM identified: byte order, entry, cart ID, mapping | ✅ **done** — see `docs/log/M1-rom-identification.md` |
| **M2** | Code/data separation via splat; first code segment disassembles | ✅ **done** — 243 functions, code ends at ROM `0x12140`; see `docs/log/M2-code-data-boundaries.md` |
| **M3** | Name what the entry calls; re-split | ✅ **done** — gained no coverage: labels do not discover code (`docs/log/M3-libultra-naming-and-research.md`) |
| **M4** | One subsystem understood | ✅ **done** — the ROM is banked; the loader chain is `FUN_80001180` → descriptor → PI DMA → inflate (`docs/log/M8-file-table-found.md`) |
| **M5** | Byte-matching build of one module | ⏳ *only if M4 justifies it* — splat detects `compiler: KMC`, so the community matching toolchain does not transfer |
| **M6** | Asset formats and extraction | ✅ **done** — 4 761 zlib members, 1 227 JPEG frames, 271 MPEG-1 blocks; the media container format is verified (`docs/format_notes.md`) |
| **M7** | Code corpus: every code image decompiled and indexed | ✅ **done** — a census of all 4 761 members finds **36 code images** (1 947 632 B); **3 638 functions** decompiled, 100 % of in-code `jal` targets resolving, `src/INDEX.md` (`docs/log/M81-code-corpus.md`, `docs/log/M82-r4-container-and-gaps.md`, `docs/log/M83-pipeline-audit.md`, `docs/log/M84-static-tables.md`, `docs/log/M85-bank-c-loader.md`, `docs/log/M86-load-contract-and-harness-bugs.md`, `docs/log/M87-harness-fixture-and-slot-map.md`, `docs/log/M88-codec-is-zlib-and-scene-slot.md`) |

M5 remains a research question, not a promise — a byte-matching build of a 64 MB cartridge is a
community-scale effort. **M4, M6 and M7 are done.** Code discovery is closed at the member level:
every code payload is named by the cart's own load table. What is left unidentified is ~17.6 MB in
two blobs, and 28 code payloads stored in a non-zlib container inside the tail of R4.

---

## What M0 established (verified, not assumed)

Both findings came from testing, and both constrain everything downstream.

### 1. MIPS decompilation works through this stack

A synthetic MIPS III big-endian ELF (`tools/mkmips.py`, a countdown loop summing
5+4+3+2+1 into `$v0`) was decompiled by REA→Ghidra 12.2:

```
language_id:      MIPS:BE:32:default        (provider-pinned)
mips_support_lane: elf32-exec-mips1-legacy-pinned-v1
mips_abi_basis:   inferred-o32-assumption-v1
assembly:         li t0,0x5 · clear v0 · addu v0,v0,t0 · addiu t0,-1 · bne · nop · jr ra · nop
pseudocode:       do { sum += i; i--; } while (i != 0); return sum;   → 15
```

REA is honest about its own assumptions in the output: it pins the generic 32-bit MIPS
language (which also decodes later MIPS32 opcodes), treats o32 as an *assumption* because
the header declares no ABI, and states that MIPS-I conformance is not established from
the header alone. Those caveats are exactly the ones that matter for a 1999 compiler.

### 2. Raw ROM segments must be wrapped as ELF

`open_binary` with `format: raw-binary` accepts **only** `6502 | x86 | x86_64 | arm |
arm64 | m68k` — **not MIPS**. An N64 ROM is a raw big-endian image, so this fails:

```
architecture: invalid_value — expected one of "6502"|"x86"|"x86_64"|"arm"|"arm64"|"m68k"
```

Hence `tools/wrap_mips_elf.py`: wraps any raw segment in a minimal ELF32 BE MIPS
`ET_EXEC` header with `e_flags = 0` (MIPS-I ISA field, no ABI record), which is the
"recordless legacy" shape REA admits. Verified end to end — the wrapper output is
accepted and decompiles.

**This wrapper is load-bearing.** Without it, no ROM code reaches the decompiler.

---

## Repository layout

Discovery is kept separate from extraction, so a wrong hypothesis cannot quietly produce wrong output.

```
run-rom.sh                 launcher for an OPTIONAL external validator; used only to produce the
                           ground-truth RDRAM dumps that tools/diff_rdram.py compares against
tools/     vaddr.py          resolve an address to the image that holds it; sext16/compose with a
                             mandatory mode; refuses addresses several images share
           test_harness.py   15-case architectural fixture for the MIPS model (loads, unaligned stores)
           scan_headers.py   header analysis: window / compare / derive / chain
           extract_blocks.py  generic container extractor (reads ROM read-only)
           unpack_zlib.py     sequential zlib member unpacker
           find_cart_table.py locates the 0x0..-flagged descriptor records
           wrap_mips_elf.py   raw segment -> ELF (load-bearing: REA refuses raw MIPS)
manifests/ manifest.json      every extracted block: offset, trailer, size, sha1
           block_types.json   the container spec the extractor consumes
assets/    fmv/ video/ unknown/ unpacked/        (gitignored, regenerable in ~20 s)
docs/      format_notes.md    the established formats and the evidence for them
           reverse_engineering_log.md   chronological log + the errors worth remembering
           log/M1..M9/         full write-ups per milestone
```

The cartridge is immutable input: both analysis tools print the ROM's sha256 before and after
every run and report `UNCHANGED`.

## Pipeline

```
rom/*.z64
   │  tools/n64info.py           validate, detect byte order, normalise to z64, CIC fingerprint
   ▼
z64 (big-endian)
   │  splat                      split into asm segments + data + symbol map
   ▼
segments/*.bin + *.asm + undefined_syms.txt
   │  tools/wrap_mips_elf.py     raw segment → ELF32 BE MIPS (required by REA)
   ▼
*.elf
   │  rea open_binary → analyze_function → search_strings (in-session)
   ▼
annotated analysis → hand-written C → eventual matching build
```

## Tooling

In this repo:

| Tool | Purpose | Verified |
|---|---|---|
| `tools/n64info.py` | ROM identification: byte order (z64/v64/n64), header fields, entry point, bootcode SHA-1 for CIC matching. Never claims a CRC verdict — the N64 CRC table is not reimplemented here | yes, on a synthetic z64 |
| `tools/wrap_mips_elf.py` | raw BE segment → ELF32 BE MIPS, the shape REA admits | yes, decompiled via REA |
| `tools/mkmips.py` | generates the known-truth MIPS test pair (raw + ELF) | yes |

To obtain:

| Need | Where |
|---|---|
| `splat` + MIPS binutils | **installed in the nanocore** — see `docs/log/M2-code-data-boundaries.md` for the exact sequence (splat64 needs manual dependency injection and a Rust toolchain for `pygfxd`) |
| MIPS binutils (`mips-linux-gnu-as/objdump/ld`) | distro package, or LLVM's MIPS target (`clang --target=mips-linux-gnu`) |
| `n64crc` (CRC verify + fix) | community source; needed before trusting a dump |
| The original compiler | **unknown until M5** — N64 era used IDO 7.1 or GCC 2.7.2/egcs; matched by comparing generated code |

## Working rules

1. **Read-only until proven.** No writing back to a cartridge image. Ever, without a
   verified duplicate and a matching hash.
2. **Every claim gets a note in `docs/log/`**: what was tested, the exact command, the
   observed output, and what it does *not* establish.
3. **Distinguish observed from inferred.** REA is a good model here: it labels
   assumptions (o32 ABI, MIPS-I conformance) rather than silently assuming them.
4. **No ROM, no ROM-derived binaries, no extracted assets in git.**

## Next action

Place your dump at `rom/re2.z64` (or `.n64` / `.v64` — byte order is auto-detected), then:

```sh
./tools/n64info.py rom/re2.z64
```

That produces M1: byte order, entry point, cart ID, CIC fingerprint and size. Everything
after that is drivable from the layout it prints.
