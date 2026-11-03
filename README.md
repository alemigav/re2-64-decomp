# Resident Evil 2 (N64) — decompilation research

Black-box decompilation of **Resident Evil 2 (Nintendo 64, `NREE` rev 1 USA)** — analysis, decompiled
pseudocode, and a **884-case verification suite** that anyone can run. Every claim in the docs is either
measured by one of those cases or explicitly labelled a reading of the code.

**This is not a matching build.** A 64 MB cartridge is a community-scale effort, so the project is staged to
be useful at every step instead: formats decoded, a full pseudocode corpus, the script VM, the texture
container, the audio filesystem, and a gate that refuses to let a number rot — plus a verifier that will not
report `PASS` unless the gates themselves have been shown to fail.

[![ci](https://github.com/alemigav/re2-64-decomp/actions/workflows/acceptance.yml/badge.svg)](https://github.com/alemigav/re2-64-decomp/actions/workflows/acceptance.yml)
[![release](https://img.shields.io/badge/release-v1.1-lightgrey)](https://github.com/alemigav/re2-64-decomp/releases)
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
  load table, **3 638 functions** over **3 678** ranges, **62.2 %** of the **1 947 632** image bytes inside
  a known body (**1 210 600 B**) — `src/`, `src/INDEX.md`. The other 37.8 % is classified, not shrugged at
  (M207): **407 608 B padding**, **6 640 B** data the decompiler names, **964 B** of jump tables, and
  **321 820 B (16.5 %) unclassified** — a bucket that is published and never renamed `data` on a hunch.
* **What is actually understood** (M209, derived by `tools/analysis_status.py`): of **3 638 functions**,
  **3 551** resolve every call target in their bodies, **34** carry a curated name, and **12** have behaviour
  pinned by a gate or an executed experiment — and all **12** of those are still called `FUN_…`, because a
  name needs evidence of its own.
* **The script VM**: a 141-entry handler table, **18 distinct instruction lengths** from 1 to 40 bytes
  (M136 published 15; the 30- and 38-byte sizes arrived when M141 corrected `0x69 ItemAotSet4p` and `0x2d
  ObjModelSet` against the PS1 table — M210),
  decoded from the handlers' own behaviour rather than from a reference (M136–M156).
* **Room population**: 256 table entries → 147 ids → 50 room scripts, proven before anything was modelled
  on it (M156–M158).
* **The texture container (T64)**: palette plus raw indices, no compression, `len = 16 + entries·2 + w·h·bpp/8`
  verified on **65 of 65** tiles (M159–M167).
* **The exception path**: `break` → vector → dispatch loop `0x8000098c`, with no `eret` and no EPC write —
  fatal, only a hardware reset leaves it (M168–M171).
* **The audio filesystem**: the file table is the whole file system, not a zlib manifest — 8 091 entries, of
  which **3 126 are stored raw** — and the 17.6 MB "unidentified" region is five files: a 588-record `MORT`
  voice bank, three chained section tables, and a sample pool of **1 192 samples that tile it to the byte**
  (M178–M193).
* **The sample codec, decoded**: order-2 ADPCM with a **256**-byte shared codebook, with **217 944** of
  **217 944** groups structurally valid and **1 180** of **1 192** samples decoding to audio (median
  adjacent correlation +0.901). `tools/sound_decode.py` implements it and gates the result (M187–M193).
  The other twelve are **not failures**: adjacent correlation runs continuously from +0.44 to +0.98 with no
  gap, and the low tail is noise-like content — a 0.7 line drawn through a smooth distribution (M194).
* **Two codecs, not one**: `id 1979`'s 588 records are *not* that format — high-entropy, 16 000/8 000 Hz,
  and no raw prelude — so the voice bank and the sample pool are encoded differently (M189/M191).
* **The voice codec, decoded and bit-exact**: `id 1979`'s 588 `MORT` records are a second, unrelated
  codec — LSB-first bits inside big-endian words, 160 samples per block in 260-bit frames, 14 % of blocks
  silent — and the whole synthesis (dequantisation, a pitch predictor, an 8-stage lattice, a four-band
  polyphase mix) is reimplemented in Python and graded **sample for sample** against the cartridge's own
  code: 13 clips, 634 blocks, 0 differing (M195–M199). `tools/voice_decode.py` also writes the audio.
* **A verification system that can be checked without the game**: 48 mutation audits, a ratchet that forbids
  silent count changes and any edit to `src/`, derived-and-asserted documentation numbers, and one entry point
  that treats a dirty gate audit as `INCONCLUSIVE` rather than `PASS` (M179–M183).

## Verify it without the cartridge

This is the part that is unusual for a decompilation, and the part you can check in a minute. No ROM, no
assets, no emulator:

```sh
git clone https://github.com/alemigav/re2-64-decomp && cd re2-64-decomp
python3 tools/acceptance.py      # 29 suites / 273 of 884 cases run; the other 33 suites SKIP
python3 tools/audit_gates.py     # 127/127 — every gate must fail when its mechanism is disabled
python3 tools/workflow_lint.py   # 14/14 — CI lints the file that makes CI run
python3 tools/check_markers.py   # 22/22 — every doc anchor, heading and note pointer holds
python3 tools/artefact_scan.py   # 5/5  — no tracked file is cartridge content
python3 tools/ratchet.py --check # the registry has not drifted, and src/ has not moved, silently
python3 tools/counts.py --check  # the numbers quoted here still agree with the registry
python3 tools/verify.py          # all of the above, adjudicated into one verdict
```

The suites that need the cartridge print `SKIP (needs the cartridge)` — **never PASS**. A suite that cannot
run and reports success is the same error as a test that asserts nothing, so the split is stated everywhere
it is counted: **611 of 884 cases cannot run without your dump**, and the CI job summary lists them by name.

Two things worth knowing about how the gate works:

* `tools/audit_gates.py` **disables each check's mechanism** and requires the check to fail. 44 mechanisms,
  44 failures, **0 vacuous**. It has repeatedly caught checks that could not fail — six of its own environment
  assumptions, and a verdict rule that made five audits green unconditionally because it grepped the output
  for the word `FAIL`.
* `tools/ratchet.py` forbids the three silent edits that make a suite pass: lowering an expected count,
  deleting a suite, or editing `src/` to satisfy a check. Every change needs `--write`, which is a diff.
* `tools/counts.py` derives every number quoted in this file and the handover from the registry and asserts
  them in sixteen places. A phrase that *disappears* is a failure, so deleting a stale line cannot help.
* `tools/milestone_index.py --check` regenerates [the milestone index](docs/MILESTONES.md) and fails if it
  drifts from the log. The index cannot be hand-edited into agreement with anything.

## Milestones

**232** numbers, 0-231: **182** with a row, and **50** named gaps. The full index — every number, its title,
and the note behind it — is [docs/MILESTONES.md](docs/MILESTONES.md); the narrative record is
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
| P10 | M178–M191 | the file table is the file system; the 17.6 MB is the audio family, framed end to end; the sample codec identified and its fields confirmed; the two key holes resolved |
| P11 | M192–M199 | the pool codec decoded and its samples audible; the voice bank's stream recovered from the reader's own bit order; the voice synthesis transcribed and verified sample for sample; the gate suite made fast enough to run every turn |

The gap at M31–M78 is stated rather than reconstructed: writing a note from guesswork would be
indistinguishable from one written from measurement, and that distinction is the project's whole claim.

## What is decoded

Formats are documented in [docs/format_notes.md](docs/format_notes.md) with the measurement behind each
claim, and codified in [include/re2_formats.h](include/re2_formats.h) with a C validator
(`tools/t64info.c`) that is compiled and run in both directions on every gate run.

| format | state |
|---|---|
| cartridge | 67 108 864 B, header entry `0x80000480`, cart table at vram `0x80012150`, 66 records + a build stamp |
| script VM | 141 handlers, **17** lengths (1–40 B), `0x44 SceEmSet` carries the enemy Id at byte 3, GoSub stride 2 |
| room population | 256 byte entries → 147 ids → 50 room scripts |
| model container | `01 41` = format version **321**, self-relative offsets relocated by `FUN_800824b8` |
| textures (T64) | `[0xBE1E][height][width][size][format][palette entries]` + RGBA5551 + raw 4/8-bpp indices |
| exception path | `break` → `jr k0` → `0x800006d0` → dispatch loop `0x8000098c`; unrecoverable by design |
| file table | 8 091 entries + build stamp; 4 852 zlib, **3 126 stored raw** — the media, uncompressed (M178) |
| sound files | ids 1979–1983: a 588-record `MORT` bank, `SND_PROJ`/`SND_POOL` chained tables, `SND_SMPDIR` |
| sample pool | id 1983, 9 022 912 B: **1 192 samples tiling it to the byte**, 15 canonical rates (M184) |
| sample codec | order-2 ADPCM: one **256**-byte shared codebook per bank, then 40-byte groups — `2 raw + 30 nibbles = 32 samples` per 20-byte frame; decoded and gated (M193) |
| voice bank header | `MORT` + u16 **block count** + u16 rate + u32 **length/4** = **12** bytes; a normal block is a fixed 260 bits (M193, corrected by M194/M197) |
| voice codec | bit stream is LSB-first inside big-endian 32-bit words; per block 36 scale bits + 4 × (17 + 39); synthesis transcribed and bit-exact (M197–M199) |
| directory record | 28 bytes, and that is the whole record: index, refcount, offset, rate, codec byte, **24-bit declared length**, **loop start**, **loop length** — the mixer adds the last two for the loop end and plays the remainder out on release (M193, corrected by M203/M204) |
| key spaces | pool keys are `[tag][index]` with the tag in the **top two bits** (`(key >> 14) & 3`); the four POOL **sections** are tagged 0, 3, 1, 2 in file order — sections are *storage*, while the roles are the **six lists** a `SND_PROJ` record carries; `SND_PROJ`'s 417 records rotate from key 118; one key is absent and one reference dangles, and they are the same fact (M188, corrected by M200) |

The 17.6 MB is no longer unidentified, and neither codec is: the pool decodes to audio, and the voice
bank's stream, its header (12 bytes) and its whole synthesis are transcribed and verified sample for
sample against the cartridge. `u16@+4` is the `MORT` clip's **block count** at 160 samples per block,
which is why every `payload/field` ratio sat under 32.5 bytes (260 bits per block). What genuinely
remains: **what the 16-byte class-3 parameter record is called** — its fields (rate, time, size, level) and its
role (the record 142 samples pair with) are measured, but the cartridge never labels it. The loop points a
directory record carries are settled (M203): **+20 is a loop start and +24 a loop length**, both in decoded
samples, and 187 of the 1 192 records name one.

## Layout

```
tools/       87 analysis and gate scripts — plain Python 3, stdlib only, nothing to compile
src/         3 638 decompiled functions across 36 images, one .c per function, provenance in each header
docs/        handover.md (start here), format_notes.md, MILESTONES.md, reverse_engineering_log.md
docs/log/    161 notes, one per milestone that has one
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
