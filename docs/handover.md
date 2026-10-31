# Handover — how to resume this project cold

Written 2026-10-31 at the end of a long session, so that a rebuilt session needs this file and not the
transcript. Everything here is either measured or points at the note that measured it.

## What this project is

Decompilation research on **Resident Evil 2 (N64, `NREE` rev 1 USA)** by the cartridge's owner, under
`~/projects/re2-64-decomp`. The ROM is user-supplied, gitignored, and never modified. The goals are
formats, decompression, executable structure, symbols and documented behaviour — **not** an emulator.
`/Applications/ares.app` (an N64 emulator) is an **optional external validator**, used only to produce
ground-truth RDRAM dumps. Nothing in the repo imports or requires it.

## Verified state, in numbers

| fact | value | note |
|---|---|---|
| cartridge | 67 108 864 B, header entry `0x80000480`, `NREE` rev 1 | `docs/log/M1-*.md` |
| ROM→vram | `vram = rom_offset + 0x7FFFF480` | M7, three independent tests |
| boot bank | ROM `0x1000`–`0x12140`, **69 952 B** | (69 184 was wrong) |
| cart table | vram `0x80012150`: 16-byte header `"OVERLAYTABLENUM"` + count `0x43`; records 1–66; record 67 = build-stamp descriptor; zlib tables from `0x80012590` | M81/M84/M92 |
| zlib members | **4 761**, 8 748 242 → 18 550 424 B; streams start `68 de` (16 KB window) | M9, `unpack_zlib.py` |
| code images | **36** (boot + stage-2 + 34 overlays), **1 947 632 B** | M81 census |
| decompiled corpus | **3 292 functions**, 61.3 % of code bytes claimed, `src/` + `src/INDEX.md` | M81–M83 |
| media | 1 227 MJPEG frames, 271 MPEG-1 blocks (24.4 MB + 15.8 MB), all verified | M10 |
| unidentified | two blobs ~17.6 MB (R3 `0xb73fb3`–`0x140ed84`, R4 `0x338fe1`–`0xb63106`); R4's tail holds a **non-zlib container** of 28 payloads at cart `0xb6248` | M82/M90 |

`assets/` is gitignored and regenerable in ~20 s. The repo tip is the last documentation commit; `git log
--oneline` is the milestone index and `docs/reverse_engineering_log.md` carries every milestone one-liner
**plus a retraction table** — read the retraction table before believing any older note.

## Tools, and how to run them

All plain Python 3 on the system interpreter. **Nothing needs compiling.**

```
python3 tools/n64info.py rom/re2.z64                              # identify the dump
python3 tools/unpack_zlib.py rom/*.z64 --out assets/unpacked      # 4 761 members
python3 tools/extract_blocks.py rom/*.z64                        # media blocks
python3 tools/read_overlay_table.py rom/*.z64                    # the cart table, self-validating
python3 tools/scan_code_members.py rom/*.z64                     # census: which members are code
python3 tools/build_images.py rom/*.z64                          # 36 ELFs into build/elfs/
python3 tools/make_seeds.py --extra build/seeds_extra --extra build/seeds_tables
python3 tools/run_corpus.py baseline|final|report                # the two-phase decompile
python3 tools/export_src.py                                      # build/decomp → src/
python3 tools/verify_corpus.py                                   # 7 checks, 4 hard
python3 tools/test_harness.py                                    # 15-case MIPS fixture (must be 15/15)
python3 tools/vaddr.py 0x80004550                                # resolve an address to its image
python3 tools/find_readers.py 0x80115284 0x80115288              # who touches an address window
python3 tools/find_jump_tables.py                                # recover dispatch targets
python3 tools/find_store_loops.py                                # table-fill initialisers
python3 tools/probe.py --reg 4@0x80071ebc --steps 2000000        # harness watch
python3 tools/walk_stream.py rom/*-rdram-20261031-*.bin          # walk a room's command stream
python3 tools/room_probe.py rom/*-rdram-*.bin                    # slot / gate / stream from a dump
```

## The ares dump workflow (the only manual step)

`./run-rom.sh` launches the cartridge. **Dumps land in `rom/`**, named `<rom>-rdram-<YYYYMMDD-HHMMSS>.bin`,
8 388 608 B each. To make one: play into a room, then **Tools → Memory Editor → region `RDRAM` → the
`Memory` row → `Export`**. `tools/room_probe.py` / `walk_stream.py` then read it directly.

Nine dumps exist: two pre-room (title / just after NEW GAME) and seven from rooms — five distinct states
(three of the earlier ones are byte-identical copies of one instant).

**Known automation limit:** ares v148 ships no AppleScript dictionary, and its `Goto` field accepts text
without committing (M69). Memory export has only ever been done by hand — see `docs/log/M107-ares-control.md`
for the route to fixing that.

## The runtime question this session chased, and where it stands

The chain from a room script to the cartridge loader is now mapped end to end:

```
room overlay → BSS command buffer → *(0x800df92c) → context +0x145c → ctx+0x1c (current command)
  → byte 0 = opcode → 141-entry table at 0x80113898 → handler
  opcode 0x44 → FUN_80071e14: byte 9 gate → lbu a0,3(descriptor) = "slot"
  → FUN_8003287c(slot): destination entry (zero ⇒ early return) → byte[slot-16] → cart_record
  → FUN_800327ec: branch 0 (stored==0) / 1 (stored==span, unreachable) / 2 inflate → failures discarded
```

Measured conclusions:

* command lengths are **per opcode** (18 distinct, `0x44` = 22 bytes);
* **no code writes a context individually**; the ten contexts are driven generically (`s0 += 0x174`);
* the two 48-byte slot maps at `0x800eb204`/`0x800eb234` are **static `.rodata`**, identical in all five
  room dumps, and the entry for the only slots observed (31, 72) is **0 forever**;
* so the observed scene-slot commands are a **recurring no-op**: `cart_record(0)` = the marker, inflate
  fails, the return is discarded, the destination is unchanged;
* the descriptor's **byte 9 gate** passes for every observed command and is vacuous for the one tested.

**Open, and it needs a different room:** does any room's script carry an `0x44` whose byte 3 is one of the
13 live map slots (16, 32–49, 51, 52, 54–56, 58, 59, 62, 63)? Five captures from one corridor say no.

## Rules this project follows (they have all been earned)

1. **Read-only until proven.** The cartridge is immutable; tools print its sha256 before and after.
2. **Every claim gets a note** in `docs/log/` with the command, the output, and what it does *not* establish.
3. **Two independent paths, or it is not established.**
4. **Never compose an address by hand** — `tools/vaddr.py` and `tools/find_readers.py` exist because that
   error class struck seven times. A scanner output becomes a fact only after the instruction is read.
5. **Negative results are results** — record them, with the scan's matching rule.
6. **No ROM bytes, no extracted assets, no binaries in git.** `src/` (pseudocode) *is* tracked.

## Immediate next step

Read `docs/log/M107-ares-control.md` and take the first experiment there: drive ares through its
**GDB remote-serial-protocol stub** (`DebugServer/Enabled` + `DebugServer/Port`) so that breakpoints,
register reads and RDRAM dumps become scripted. That converts every remaining question in this file from
"ask the owner to play and click Export" into a loop that runs unattended — and it is the only thing
blocking the last open item above.
