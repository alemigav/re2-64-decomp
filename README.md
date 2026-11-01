# Resident Evil 2 (N64) — decompilation research

Black-box decompilation of **Resident Evil 2 (Nintendo 64, `NREE` rev 1 USA)** — analysis, decompiled
pseudocode, and a **391-case verification suite** that anyone can run. Every claim in the docs is either
measured by one of those cases or explicitly labelled a reading of the code.

**This is not a matching build.** A 64 MB cartridge is a community-scale effort, so the project is staged to
be useful at every step instead: formats decoded, a full pseudocode corpus, the script VM, the texture
container, and a gate that refuses to let a number rot.

[![ci](https://github.com/alemigav/re2-64-decomp/actions/workflows/acceptance.yml/badge.svg)](https://github.com/alemigav/re2-64-decomp/actions/workflows/acceptance.yml)
[![licence: CC0-1.0](https://img.shields.io/badge/licence-CC0--1.0-lightgrey)](LICENSE)

## No ROM, no assets, no affiliation

The cartridge is **not in this repository and never will be** — not in the tree, not in any of its 200+
commits. `rom/`, `assets/` and `build/` are gitignored; the only `.z64` here is an 8 KiB *synthetic* fixture
that exists so the corpus pipeline can run without the game.

You need your own legally dumped copy to run anything that reads the cartridge. Nothing extracted from it —
no textures, no audio, no video, no compressed members — is committed. Only its SHA-256 is, in
`manifests/manifest.json`.

Not affiliated with, endorsed by or sponsored by Capcom or Nintendo. See [Legal and licence](#legal-and-licence).

## What this project produced

* **The mapping law**: `vram = rom_offset + 0x7FFFF480`, established three independent ways after the first
  version of it was wrong by `0x480` and had invalidated every address (M7).
* **The container**: 4 761 zlib members, 8 748 242 → 18 550 424 B, plus 1 227 MJPEG frames and 271 MPEG-1
  blocks, all verified byte-for-byte (M9/M10).
* **The code corpus**: **36 images** (boot + stage-2 + 34 overlays, 1 947 632 B) censused from the cart's own
  load table, **3 638 functions** decompiled, **62.3 %** of code bytes claimed — `src/`, `src/INDEX.md`.
* **The script VM**: a 141-entry handler table, **15 distinct instruction lengths** from 1 to 40 bytes,
  decoded from the handlers' own behaviour rather than from a reference (M136–M156).
* **Room population**: 256 table entries → 147 ids → 50 room scripts, proven before anything was modelled
  on it (M156–M158).
* **The texture container (T64)**: palette plus raw indices, no compression, `len = 16 + entries·2 + w·h·bpp/8`
  verified on **65 of 65** tiles (M159–M167).
* **The exception path**: `break` → vector → dispatch loop `0x8000098c`, with no `eret` and no EPC write —
  fatal, only a hardware reset leaves it (M168–M171).

## Verify it without the cartridge

This is the part that is unusual for a decompilation, and the part you can check in a minute. No ROM, no
assets, no emulator:

```sh
git clone https://github.com/alemigav/re2-64-decomp && cd re2-64-decomp
python3 tools/acceptance.py      # 21 suites / 205 of 391 cases run; the other 12 suites SKIP
python3 tools/audit_gates.py     # 44/44 — every gate must fail when its mechanism is disabled
python3 tools/workflow_lint.py   # 14/14 — CI lints the file that makes CI run
python3 tools/check_markers.py   # 20/20 — every doc anchor, heading and note pointer holds
python3 tools/artefact_scan.py   # 5/5  — no tracked file is cartridge content
```

The suites that need the cartridge print `SKIP (needs the cartridge)` — **never PASS**. A suite that cannot
run and reports success is the same error as a test that asserts nothing, so the split is stated everywhere
it is counted: **186 of 391 cases cannot run without your dump**, and the CI job summary lists them by name.

Two things worth knowing about how the gate works:

* `tools/audit_gates.py` **disables each check's mechanism** and requires the check to fail. 26 mechanisms,
  26 failures, **0 vacuous** — this caught six checks that could not fail, including one of its own
  environment assumptions four times over.
* `tools/milestone_index.py --check` regenerates [the milestone index](docs/MILESTONES.md) and fails if it
  drifts from the log. The index cannot be hand-edited into agreement with anything.

## Milestones

178 milestones are recorded, in ten phases. The full index — every number, its title, and the note behind
it — is [docs/MILESTONES.md](docs/MILESTONES.md); the narrative record is
[docs/reverse_engineering_log.md](docs/reverse_engineering_log.md), which also carries a retraction table
worth reading before you believe any older note.

| phase | range | what happened |
|---|---|---|
| P0 | M0–M9 | toolchain proof, dump identification, code/data split, the mapping law, cart table, unpack |
| P1 | M10–M30 | media container recovered, five stride hypotheses killed, load path, first CPU/CP0/FPU model |
| P2 | **M31–M78** | **the unsaved middle** — no notes survive; only M48, M51 and M78 as commit subjects |
| P3 | M79–M80 | interrupts work end to end; the boundary is *work*, not signalling |
| P4 | M81–M110 | code corpus (3 638 functions), bank-C loader chain, scripted emulator control, scene-slot path closed as by design |
| P5 | M111–M125 | pointer provenance, and two external references assessed |
| P6 | M126–M135 | the gate itself: fixtures, hook, CI, synthetic corpus, marker checks |
| P7 | M136–M156 | the script VM decoded — lengths, licensed names, jump family, room population |
| P8 | M157–M172 | populations audited; `0x0141`, T64, handle registry, exception path; consolidation |
| P9 | M173–M177 | index bounds, a CI that actually runs, and publication readiness |

The gap at M31–M78 is stated rather than reconstructed: writing a note from guesswork would be
indistinguishable from one written from measurement, and that distinction is the project's whole claim.

## What is decoded

Formats are documented in [docs/format_notes.md](docs/format_notes.md) with the measurement behind each
claim, and codified in [include/re2_formats.h](include/re2_formats.h) with a C validator
(`tools/t64info.c`) that is compiled and run in both directions on every gate run.

| format | state |
|---|---|
| cartridge | 67 108 864 B, header entry `0x80000480`, cart table at vram `0x80012150`, 66 records + a build stamp |
| script VM | 141 handlers, 15 lengths (1–40 B), `0x44 SceEmSet` carries the enemy Id at byte 3, GoSub stride 2 |
| room population | 256 byte entries → 147 ids → 50 room scripts |
| model container | `01 41` = format version **321**, self-relative offsets relocated by `FUN_800824b8` |
| textures (T64) | `[0xBE1E][height][width][size][format][palette entries]` + RGBA5551 + raw 4/8-bpp indices |
| exception path | `break` → `jr k0` → `0x800006d0` → dispatch loop `0x8000098c`; unrecoverable by design |

Still unidentified: ~17.6 MB in two blobs, and a 28-payload non-zlib container in the tail of R4 whose codec
is unsolved.

## Layout

```
tools/       60 analysis and gate scripts — plain Python 3, stdlib only, nothing to compile
src/         3 638 decompiled functions across 36 images, one .c per function, provenance in each header
docs/        handover.md (start here), format_notes.md, MILESTONES.md, reverse_engineering_log.md
docs/log/    107 notes, one per milestone that has one
manifests/   offsets, sizes, addresses, hashes — derived facts, no bytes
fixtures/    the synthetic cartridge, the opcode tables, the function-boundary index
include/     re2_formats.h — the format structures, shared by the tools and the C validator
config/      symbol map and splat configuration
```

Two documents matter most: [docs/handover.md](docs/handover.md) is written so a cold session can resume
without the transcript, and [docs/format_notes.md](docs/format_notes.md) is the reference for what the
cartridge actually contains.

## Rebuild with your own dump

Place the cartridge at `rom/re2.z64` (byte order is auto-detected), then:

```sh
python3 tools/n64info.py rom/re2.z64                          # identify and normalise the dump
python3 tools/unpack_zlib.py rom/*.z64 --out assets/unpacked  # 4 761 members, ~11 s
python3 tools/build_images.py rom/*.z64                       # 36 ELFs into build/elfs/
python3 tools/read_overlay_table.py rom/*.z64                 # the load table, self-validating
python3 tools/export_src.py                                   # build/decomp → src/
sh tools/ci.sh                                                # the whole gate, with the cartridge
```

The decompilation step itself is Ghidra 12.2 driven through REA's CLI (`rea decompile-all --provider ghidra`),
one invocation per image, seeded from `config/symbols.tsv`. It takes hours, not minutes; the chain that
matters for reproducing the *findings* is the gates, and those take a minute.

`docs/handover.md` has the full sequence, including how the ranges fixture (`fixtures/decomp/ranges.json`,
3 678 regions) stands in for the decompiler's index so a rebuild cannot silently shift a boundary.

## Legal and licence

This repository contains **no cartridge data**: no ROM bytes, no extracted assets, no audio, no video. You
need your own legally dumped copy of Resident Evil 2 (N64) to run anything that reads the cartridge.

The files under `src/` are **decompiled pseudocode**, produced by Ghidra from a Capcom work. They are
derivative of that work and are published here for study, with no warranty of correctness and no claim of
endorsement.

This project is not affiliated with, endorsed by or sponsored by Capcom or Nintendo. All trademarks belong to
their owners.

The author's own text, tools and fixtures are dedicated to the public domain under **CC0-1.0**
([LICENSE](LICENSE)); that dedication cannot and does not extend to `src/`. Third-party material is credited
in [THIRD_PARTY.md](THIRD_PARTY.md) — one table transcribed from MIT-licensed OpenBiohazard2, with its full
licence text reproduced there.

## References

* **REA / Ghidra 12.2** — the analysis engine; every function in `src/` was produced by it, and its provider
  record is quoted in each file's header.
* **[OpenBiohazard2](https://github.com/OpenBiohazard2/OpenBiohazard2)** (MIT) — a Go re-implementation whose
  RDT opcode table is the one transcription here. Read as code, because MIT permits it.
* **[n64decomp/perfect_dark](https://github.com/n64decomp/perfect_dark)** (MIT) — assessed for method; nothing
  was ported.
* **[n64decomp/banjo-kazooie](https://github.com/n64decomp/banjo-kazooie)**,
  **[n64decomp/sm64](https://github.com/n64decomp/sm64)** — the decomps whose frontpage conventions this one
  follows, and whose CC0 choice it shares.
