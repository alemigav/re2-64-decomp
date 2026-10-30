# Reverse-engineering log — RE2-64

Chronological. Each entry states what was believed, what the measurement said, and what changed.
Detailed write-ups live in `docs/log/`.

| milestone | outcome | detail |
|---|---|---|
| M0 | MIPS big-endian decompiles through REA→Ghidra at all | `tools/mkmips.py` known-truth fixture |
| M1 | dump identified: 512 Mbit, z64, entry `0x80000480`, `NREE` rev 1 USA | `docs/log/M1-rom-identification.md` |
| M2 | splat splits code `0x1000`–`0x12140`, 243 functions, `unknown 67 MB (99.89 %)` | `docs/log/M2-code-data-boundaries.md` |
| M3 | naming the entry's callees gained **no** coverage — labels do not discover code | `docs/log/M3-libultra-naming-and-research.md` |
| M4 | the ROM is banked (30 687 pointers over all 64 RDRAM buckets); the `0x128B8` table is a libultra I/O dispatch table, not a load table | `docs/log/M4-bank-structure.md` |
| M5 | two PI DMA programmers located by behaviour | `docs/log/M5-pi-loader-found.md` |
| M6 | the ROM→VRAM map is *not* a stored `(rom, vram)` table — three hypotheses eliminated | `docs/log/M6-mapping-not-a-table.md` |
| M7 | **the mapping was wrong** (`0x480` low); every earlier address repaired | `docs/log/M7-mapping-correction.md` |
| M8 | **the map found**: 16-byte cart descriptor table at vram `0x80012150`, 66 records | `docs/log/M8-file-table-found.md` |
| M9 | **the cartridge unpacked**: 4 761 zlib members, 1 227 JPEG frames, an MPEG-1 movie | `docs/log/M9-unpacked.md` |
| M15 | Boot record 0 **is the stage-2 code image** (`0x80018a80`, 1.17 MB, entry spawns thread id 7). **No descriptor points into R3** by three tests - and R3 turns out not to be a resource at all, but a residual span | `format_notes.md` §5b |
| M14 | Match-run length: the 59 runs >=3 at lag 40 are **fills** (10 zero runs carry 68 % of multi-byte matched bytes; 13 more are repeated 2-byte samples). R3 has no record structure at stride 40 - M12 retracted | `format_notes.md` §5 |
| M13 | Phase sweep: the 40-byte period has **no repeating field** — all 40 positions are uniformly 3–9x their own null, max 11.7 %, 237-256 distinct values; R4's 260 period is weaker still (38/260 phases at null). M12's "period 40" is demoted to a diffuse autocorrelation peak | `format_notes.md` §5 |
| M12 | Stride probe with a shuffle null: **R3 and R4 share no block stride** (R3 period 40, R4 periods 260 and 72; each lag is near-absent in the other region) | `format_notes.md` §5 |
| M11 | R3 is **not** video: zero `00 00 01 B3` in 9 MB (R1 control scores 100 %), and 0/134 JPEG anchors and 0/1 479 trailer candidates resolve | `format_notes.md` §5 |
| M10 | **media container format recovered and verified**; one parser resolves both media kinds, neither unknown blob | this file, §4 of `format_notes.md` |

## The four errors worth remembering

1. **A guessed example poisoned fifteen files (M7).** `tools/wrap_mips_elf.py`'s usage line said
   `--base 0x80000000`, so every hand-computed vram address was `0x480` low. It survived five
   milestones because the wrong addresses still pointed at real code. *Check the base before using any
   address, and prove it numerically.*
2. **The `jal` sweep needed the 26-bit mask and the real function start.** Sweeping for the encoding of
   an interior address reports "no callers" no matter how many exist — that produced a nonexistent
   cross-bank foothold and a whole arc of dead ends.
3. **Three null results were filter artefacts.** `offset < 0x4000000` (the real offsets carry a
   `0xB` flag), adjacent `(rom, vram)` pairs (the record is `offset, size, vram, vram_end`), and
   `CMF == 0x78` (these streams use `0x68`). Each time the data was present and the search constant
   was invented.
4. **A register name is not a register value.** Grepping `sw …,4(v1)` gave 105 apparent PI writes; a
   small data-flow window that aborts on redefinition gave the true 2.

## Working method that produced the answer

- **Read the cheap artefact first**: `rea decompile … --format json` puts pseudocode in
  `normalized_result` as a plain string; `rea instructions` returns a bounded array. Reserve
  `detail:"complete"` for fixtures.
- **Prefer derivations over inspections**: 1 226 known frame transitions score a length field better
  than any amount of staring at a hexdump, and the score is falsifiable.
- **Self-consistency is not truth**: the trailer rule is only believed because an independent
  consumer (`ffprobe`) accepts the concatenated output.
- **Keep discovery and extraction separate** (`scan_headers.py` vs `extract_blocks.py`), so a wrong
  hypothesis cannot quietly produce wrong output files.
