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
| M30 | k0 trace from the vector to the fault: the handler loads k0 with `lw k0,0x2950(k0)` at `0x80000768`, reading vram `0x80012950`, which is **0 in the cartridge** and never written in this run (watchpoint: no hits). Not a register bug — a **missing initialisation dependency**. Execution then faults on `sd t1,0x20(k0)` at `0x80000770` | `format_notes.md` §5b |
| M29 | **Two mapping corrections applied**: `0x80000180` is RDRAM (phys `0x180`), not cartridge ROM; `0xBFC00380` is PIF boot ROM; `Cause 0x2000` is IP6, and the RCP interrupt is **IP3 = 0x400**. D1: MI model (`0xA4300008`/`0xA430000C`) asserts IP3 only when pending&mask — live run shows Cause `0x400`. D2: **the game installs all four vectors itself** (`lui k0,0x8000`), `E_VEC` jumps to **`0x800006d0`**. D3: dispatch reaches `0x800006d0`, runs ~0xa0 bytes, then faults at `0x80000770` on `sd t1,0x20(k0)` with k0=0 | `format_notes.md` §5b |
| M28 | **CP0 implemented and validated 5/5** (BadVAddr/Count/Compare/Status/Cause/EPC; acceptance IE&!EXL&!ERL&(IP&IM); BD; ERET restores EPC). Vector selection now uses Status.BEV: `0x80000180` (BEV=0) / `0xBFC00380` (BEV=1), and `0x80000000` is the TLB-refill vector. **Live run: the VI interrupt fires at `0x80088668` with Cause `0x2000` and EPC correct — then the CPU executes uninitialised RAM at the vector, because `0x80000180` maps to ROM `0xd00` (IPL3), 0x300 bytes before the game image.** Two CP0 bugs found by the tests (pending-bit convention, ERET delay slot) | `format_notes.md` §5b |
| M27 | Send-site census: **51 osSendMesg sites, none with a literal queue argument** (17 loaded, 21 reg+offset, 11 copied) — so the producer is indirect by design and a constant scan could not find it. PI/VI references concentrate in the boot bank (82/19) vs 1/1 in stage-2 and 0 in overlays. Event-delivery trace: exactly **two message ops, both blocking receives**, zero sends before deadlock. Harness limit recorded: `mfc0` returns 0 so CP0 Status=0 and **no interrupt can be recognised** | `format_notes.md` §5b |
| M25 | Constant scan: `0x80139f10` is drained by **thread 1** and registered by thread 7's callee; `0x8012bd30` is owned by **thread 9** and **no mapped code ever sends to it**. The missing edge is a producer for `0x8012bd30`, which explains why the M24 ticks woke nobody. Commit A/B/C all confirmed done | `format_notes.md` §5b |
| M26 | Execution checkpoints: `checkpoint/` with the 7 requested files plus `run_digest.json`; two independent runs give the **identical digest**, so reproducibility is checked, not asserted | `format_notes.md` §5b |
| M24 | FPRs corrected to 32x64-bit raw with S in the low half (and the arithmetic block's float-read bug found as a consequence). `osSetEventMesg` identified at `0x8000cc90` (events 4/9/6/14 -> queue `0x80139f10`); frame tick built and unified with osSendMesg. After 20 ticks the inbox holds 20 messages with **zero waiters** - the drainer thread is not created by the boot chain, so **open(0) does not fire** and the hypothesis is falsified, not unproven | `format_notes.md` §5b |
| M23 | **COP1/FPU added** (float32 rounding, mfc1/mtc1, bc1, S/D arithmetic, cvt, compares, lwc1/ldc1/swc1/sdc1) plus lwl/lwr/swl/swr, cache no-op and branch-likely 0x14-0x17 with delay-slot nullification. **Thread 7 gets past 0x8000ccf0 and completes.** Run ends with threads 1 and 9 blocked on queues 0x8012bcf8 / 0x8012bd30 that nothing posts to — blocker is now an **event source** (VI retrace etc.), not a missing instruction. open(0) still does not fire | `format_notes.md` §5b |
| M22 | Scheduler increment: real thread graph runs (threads 0/7/9/1 created and started, thread 9 blocks on queue `0x8012bd30`), 51 243 instructions, **open(0) never fires**. Named blockers: **COP1/FPU** (thread 7 at `0x8000ccf0`, thread 1 via SDC1). Removed two opcodes I had mis-mapped (`0x2D`=SDR not daddu, `0x3C/0x3D`=SCD/SDC1) and replaced them with named faults | `format_notes.md` §5b |
| M23 | Experiment A: `0x14420` is a bare concatenation boundary — ASCII `0123456789ABCDEF` table immediately before it, valid zlib header at it, next member at its exact end, no metadata or length table around it | `format_notes.md` §5b |
| M21 | **Partial CPU harness built and run** (`tools/mips_harness.py`): cart mapped at KSEG1, inflate as a host hook, OS stubbed and logged. Executing `FUN_8004cbf4` per registry slot yields a real load trace — **6/6 non-zero slots decompress to exactly the manifest sizes**, and the 3 zero-size slots exit after 13 instructions. `FUN_8004d190` runs in 62 instructions and sets its globals. Its last call `func_0x80000518` is `b . ; daddiu a0,a0,1` — an idle loop, 400k instructions, zero calls, **not** a file open | `format_notes.md` §5b |
| M20 | Stream-walker scan: **no constructed KSEG1 cart pointer anywhere** in stage-2 or the boot bank, so there is no walker loop and no loop bound. Both consumers take `desc[0]` from memory and pass it once to inflate. Static load-path table (10 rows, 7 cart offsets) agrees with the manifest on every offset — static agreement, not execution. No emulator, so no real trace | `format_notes.md` §5b |
| M19 | Registry cross-ref (`tools/xref_registry.py`, with pointer aliasing): **zero stores** in boot bank, stage-2 and all six overlays; the 9 references are 3 readers of `+0` (lbu) and `+4` (lw), confirming the `{u8 descriptor; u8 pad[3]; u32 entry;}` layout. **Retracts M18's "mutable slot"**: the table is read-only and `open(0)` is a fixed load of descriptor 2 | `format_notes.md` §5b |
| M18 | File-open located: **one** call site in stage 2, `0x800273e4` in `FUN_800271d4`, and it is `FUN_8004cc5c(0)` — always slot 0. The slot index byte at `0x8010b2e0` is mutable, so scene files are selected at runtime: no static scan can find an R3 descriptor, and §5b's negatives are expected | `format_notes.md` §5b |
| M19 | Overlay scan: all six overlay blobs contain **0** boot-shape records and **0** `0xB0000000`-`0xB3FFFFFF` cart pointers; strings found include `ROOM800_SND_LD`, `CONF_LD`, `Init tbl` | `format_notes.md` §5b |
| M17 | Registry at `0x8010b2e0` enumerated: **9 slots**, 8-byte entries (`u8` descriptor index, 3 pad, `u32` entry point). Indices 2-10, max cart `0x7e132` — no R3. `stored == 0` means "already resident": those 3 slots call straight into stage 2 | `format_notes.md` §5b |
| M16 | Stage-2 file open found: `FUN_8004cc5c(slot)` -> `FUN_80001180(DAT_8010b2e0[slot*8])` -> `FUN_8004cbf4(desc)` -> inflate, then `DAT_8010b2e4[slot*8]()` handler. Registry is 32 B/entry at `0x8010b2e0`. **`0xB0000000` is KSEG1 cart base, not a flag** — no DMA on this path | `format_notes.md` §5b |
| M15 | Boot record 0 **is the stage-2 code image** (`0x80018a80`, 1.17 MB, entry spawns thread id 7). **No descriptor points into R3** by three tests - and R3 turns out not to be a resource at all, but a residual span | `format_notes.md` §5b |
| M14 | Match-run length: the 59 runs >=3 at lag 40 are **fills** (10 zero runs carry 68 % of multi-byte matched bytes; 13 more are repeated 2-byte samples). R3 has no record structure at stride 40 - M12 retracted | `format_notes.md` §5 |
| M13 | Phase sweep: the 40-byte period has **no repeating field** — all 40 positions are uniformly 3–9x their own null, max 11.7 %, 237-256 distinct values; R4's 260 period is weaker still (38/260 phases at null). M12's "period 40" is demoted to a diffuse autocorrelation peak | `format_notes.md` §5 |
| M12 | Stride probe with a shuffle null: **R3 and R4 share no block stride** (R3 period 40, R4 periods 260 and 72; each lag is near-absent in the other region) | `format_notes.md` §5 |
| M11 | R3 is **not** video: zero `00 00 01 B3` in 9 MB (R1 control scores 100 %), and 0/134 JPEG anchors and 0/1 479 trailer candidates resolve | `format_notes.md` §5 |
| M10 | **media container format recovered and verified**; one parser resolves both media kinds, neither unknown blob | this file, §4 of `format_notes.md` |
| M81 | **the code corpus**: a census of all 4 761 members finds 36 code images (1 947 632 B), 3 267 functions decompiled into `src/`, 100 % of in-code `jal` targets resolving, and every code payload named by the cart's own load table. **Corrected by M83**: the "28 payloads are code by every signal" line is retracted — that was an inference from matching sizes | `docs/log/M81-code-corpus.md` |
| M82 | **the R4 container's geometry is established and its codec is not**: 28 payloads tile exactly (`0xb6248`–`0xc8624` = 74 716 B), byte 3 of every 4-byte record is zero in 18 679/18 679, and 42 decoder×transform combinations plus 1 960 bit-level probes all fail exact-length acceptance. Identity with bank B refuted with a 27-room chance control. **Retracted by M83**: "region coverage 0 % → 99.6 %" and "61.1 % → 61.6 % from discovery" were produced by a mis-placed boundary and a broadcast seed file | `docs/log/M82-r4-container-and-gaps.md` |
| M83 | **pipeline audit**: a cancelled `decompile-all` leaves a plausible index (34 of 103 functions, `failed: 0`), an index can report `written` for absent files (36 of 93), and a seed address does not identify an image (20 overlays share `0x80161cf0`, 105 mis-bounded functions followed). Against a true baseline the honest differential is **3 267 → 3 292 functions, 61.1 % → 61.3 %**, `failed` 0 both sides. `in_vN` in pseudocode is the mis-placed-boundary signature and is now a hard check. The R4 region's real coverage is **5.3 %**, not 99.6 % | `docs/log/M83-pipeline-audit.md` |
| M84 | **the static tables**: `addiu` is signed, so the case tables are at `0x800ba458` / `0x800ba488` / `0x800ba4b8`, statically populated with 11 / 12 / 15 entries — "who writes 0x800ca458" had no answer because there is no such address. Reading them back takes the 5 484 B region at `0x8009d014` from **5.3 % to 99.9 %** claimed and `stage2` from 1 565 to 1 911 functions. A store-run class finds the initializer that gives every slot the same staging base, which is why 20 overlays share `0x80161cf0`. Corpus **3 267 → 3 638 functions, 61.1 % → 62.3 %**, `failed` 0, 0 mis-bounded. **Retracts M83's** "the tables are zero-filled in the image" and "case blocks remain unattributed" | `docs/log/M84-static-tables.md` |

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
