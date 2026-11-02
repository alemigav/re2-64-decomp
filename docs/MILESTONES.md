# Milestones

Every milestone this project recorded, in numeric order, with the evidence behind it.

**This file is generated** by `tools/milestone_index.py`; do not edit it by hand. `--check` fails when it
and `docs/reverse_engineering_log.md` disagree, so the two cannot drift. The *record* is that log (one line
per milestone, plus a retraction table) and `docs/log/M<n>-*.md` (one note per milestone); this is the index
to them, and the frontpage carries a curated [phase table](../README.md#milestones) over the same ground.

211 milestones are indexed. 138 of them have a note; the rest are rows in the log that cite
`docs/format_notes.md` instead. **50 have no record at all** — 31–78, 80, 172 — and they appear in place, marked
*(no row, no note)*: an index that hides its gaps is worse than one that names them. Why they are empty is
at the foot of this file.

| # | milestone | evidence |
|---|---|---|
| 0 | **M0** — MIPS big-endian decompiles through REA→Ghidra at all | `tools/mkmips.py` known-truth fixture |
| 1 | **M1** — ROM identification | `docs/log/M1-rom-identification.md` |
| 2 | **M2** — real ROM code reaches the decompiler | `docs/log/M2-boot-code-decompiles.md` |
| 3 | **M3** — libultra naming, and what other N64 decomps do differently | `docs/log/M3-libultra-naming-and-research.md` |
| 4 | **M4** — ROM structure without disassembly | `docs/log/M4-bank-structure.md` |
| 5 | **M5** — the PI DMA loader routines | `docs/log/M5-pi-loader-found.md` |
| 6 | **M6** — the ROM→VRAM mapping is not a stored table (three hypotheses eliminated) | `docs/log/M6-mapping-not-a-table.md` |
| 7 | **M7** — The ROM→VRAM mapping was wrong, and it invalidated every address so far | `docs/log/M7-mapping-correction.md` |
| 8 | **M8** — The ROM→VRAM map found: a 16-byte cart descriptor table at vram 0x80012150 | `docs/log/M8-file-table-found.md` |
| 9 | **M9** — The cartridge unpacked: 4 761 zlib members, 1 227 JPEG frames, an MPEG-1 movie | `docs/log/M9-unpacked.md` |
| 10 | **M10** — media container format recovered and verified; one parser resolves both media kinds, neit… | this file, §4 of `format_notes.md` |
| 11 | **M11** — R3 is not video | `format_notes.md` §5 |
| 12 | **M12** — Stride probe with a shuffle null | `format_notes.md` §5 |
| 13 | **M13** — Phase sweep | `format_notes.md` §5 |
| 14 | **M14** — Match-run length | `format_notes.md` §5 |
| 15 | **M15** — Boot record 0 is the stage-2 code image (`0x80018a80`, 1.17 MB, entry spawns thread id 7)… | `format_notes.md` §5b |
| 16 | **M16** — Stage-2 file open found | `format_notes.md` §5b |
| 17 | **M17** — Registry at `0x8010b2e0` enumerated | `format_notes.md` §5b |
| 18 | **M18** — File-open located | `format_notes.md` §5b |
| 19 | **M19** (i) — Registry cross-ref (`tools/xref_registry.py`, with pointer aliasing) | `format_notes.md` §5b |
| 19 | **M19** (ii) — Overlay scan | `format_notes.md` §5b |
| 20 | **M20** — Stream-walker scan | `format_notes.md` §5b |
| 21 | **M21** — Partial CPU harness built and run (`tools/mips_harness.py`) | `format_notes.md` §5b |
| 22 | **M22** — Scheduler increment | `format_notes.md` §5b |
| 23 | **M23** (i) — COP1/FPU added (float32 rounding, mfc1/mtc1, bc1, S/D arithmetic, cvt, compares, lwc1/ldc… | `format_notes.md` §5b |
| 23 | **M23** (ii) — Experiment A | `format_notes.md` §5b |
| 24 | **M24** — FPRs corrected to 32x64-bit raw with S in the low half (and the arithmetic block's float-… | `format_notes.md` §5b |
| 25 | **M25** — Constant scan | `format_notes.md` §5b |
| 26 | **M26** — Execution checkpoints | `format_notes.md` §5b |
| 27 | **M27** — Send-site census | `format_notes.md` §5b |
| 28 | **M28** — CP0 implemented and validated 5/5 (BadVAddr/Count/Compare/Status/Cause/EPC; acceptance IE… | `format_notes.md` §5b |
| 29 | **M29** — Two mapping corrections applied | `format_notes.md` §5b |
| 30 | **M30** — k0 trace from the vector to the fault | `format_notes.md` §5b |
| 31 | **M31** — *(no row, no note)* | no evidence in the tree |
| 32 | **M32** — *(no row, no note)* | no evidence in the tree |
| 33 | **M33** — *(no row, no note)* | no evidence in the tree |
| 34 | **M34** — *(no row, no note)* | no evidence in the tree |
| 35 | **M35** — *(no row, no note)* | no evidence in the tree |
| 36 | **M36** — *(no row, no note)* | no evidence in the tree |
| 37 | **M37** — *(no row, no note)* | no evidence in the tree |
| 38 | **M38** — *(no row, no note)* | no evidence in the tree |
| 39 | **M39** — *(no row, no note)* | no evidence in the tree |
| 40 | **M40** — *(no row, no note)* | no evidence in the tree |
| 41 | **M41** — *(no row, no note)* | no evidence in the tree |
| 42 | **M42** — *(no row, no note)* | no evidence in the tree |
| 43 | **M43** — *(no row, no note)* | no evidence in the tree |
| 44 | **M44** — *(no row, no note)* | no evidence in the tree |
| 45 | **M45** — *(no row, no note)* | no evidence in the tree |
| 46 | **M46** — *(no row, no note)* | no evidence in the tree |
| 47 | **M47** — *(no row, no note)* | no evidence in the tree |
| 48 | **M48** — *(no row, no note)* | commit only: `4e1aa63` “controlled VI: vectors never installed on this path - correcting M48” |
| 49 | **M49** — *(no row, no note)* | no evidence in the tree |
| 50 | **M50** — *(no row, no note)* | no evidence in the tree |
| 51 | **M51** — *(no row, no note)* | commit only: `b6483df` “the 0x8000dc88 tail is a clean epilogue - M51 hypothesis falsified” |
| 52 | **M52** — *(no row, no note)* | no evidence in the tree |
| 53 | **M53** — *(no row, no note)* | no evidence in the tree |
| 54 | **M54** — *(no row, no note)* | no evidence in the tree |
| 55 | **M55** — *(no row, no note)* | no evidence in the tree |
| 56 | **M56** — *(no row, no note)* | no evidence in the tree |
| 57 | **M57** — *(no row, no note)* | no evidence in the tree |
| 58 | **M58** — *(no row, no note)* | no evidence in the tree |
| 59 | **M59** — *(no row, no note)* | no evidence in the tree |
| 60 | **M60** — *(no row, no note)* | no evidence in the tree |
| 61 | **M61** — *(no row, no note)* | no evidence in the tree |
| 62 | **M62** — *(no row, no note)* | no evidence in the tree |
| 63 | **M63** — *(no row, no note)* | no evidence in the tree |
| 64 | **M64** — *(no row, no note)* | no evidence in the tree |
| 65 | **M65** — *(no row, no note)* | no evidence in the tree |
| 66 | **M66** — *(no row, no note)* | no evidence in the tree |
| 67 | **M67** — *(no row, no note)* | no evidence in the tree |
| 68 | **M68** — *(no row, no note)* | no evidence in the tree |
| 69 | **M69** — *(no row, no note)* | no evidence in the tree |
| 70 | **M70** — *(no row, no note)* | no evidence in the tree |
| 71 | **M71** — *(no row, no note)* | no evidence in the tree |
| 72 | **M72** — *(no row, no note)* | no evidence in the tree |
| 73 | **M73** — *(no row, no note)* | no evidence in the tree |
| 74 | **M74** — *(no row, no note)* | no evidence in the tree |
| 75 | **M75** — *(no row, no note)* | no evidence in the tree |
| 76 | **M76** — *(no row, no note)* | no evidence in the tree |
| 77 | **M77** — *(no row, no note)* | no evidence in the tree |
| 78 | **M78** — *(no row, no note)* | commit only: `2edfb1f` “S1 done: delay-slot-correct interrupt entry fixes the M78 crash” |
| 79 | **M79** — Scoping the interrupt context path | `docs/log/M79-interrupt-scope.md` |
| 80 | **M80** — *(no row, no note)* | no evidence in the tree |
| 81 | **M81** — the code corpus | `docs/log/M81-code-corpus.md` |
| 82 | **M82** — the R4 container, and the stage-2 gaps | `docs/log/M82-r4-container-and-gaps.md` |
| 83 | **M83** — the pipeline audit, and what the differential actually measures | `docs/log/M83-pipeline-audit.md` |
| 84 | **M84** — the static tables: store-runs, jump tables, and the address I had wrong | `docs/log/M84-static-tables.md` |
| 85 | **M85** — the bank-C loader: found as a call chain, with one hop still open | `docs/log/M85-bank-c-loader.md` |
| 86 | **M86** — the loader's contract, and two bugs in the instrument I was about to trust | `docs/log/M86-load-contract-and-harness-bugs.md` |
| 87 | **M87** — the harness fixed under a fixture, the slot map found, and the codec hypothesis tested | `docs/log/M87-harness-fixture-and-slot-map.md` |
| 88 | **M88** — the codec is zlib after all, and the scene slot traces to a heap object | `docs/log/M88-codec-is-zlib-and-scene-slot.md` |
| 89 | **M89** — there is no bank-C caller | `docs/log/M89-no-bank-c-caller.md` |
| 90 | **M90** — the slot-byte writers are not statically derivable, and six audit flags resolved | `docs/log/M90-slot-byte-writers-and-audit-close.md` |
| 91 | **M91** — the bank-C map *is* read, and bank C is not compressed | `docs/log/M91-bank-c-map-is-read.md` |
| 92 | **M92** — one caller, the s0 direction corrected, and index 67 is a build stamp | `docs/log/M92-callers-s0-direction-and-index-67.md` |
| 93 | **M93** — the slot condition fully traced, `cart_record(0)` is a *crash* path, and the build question | `docs/log/M93-slot-condition-and-build-question.md` |
| 94 | **M94** — callers of `FUN_8003287c`, enumerated, and the slot values they pass | `docs/log/M94-callers-enumerated.md` |
| 95 | **M95** — the table at `0x80113898`: three readers, and entry 68 is selected by a byte | `docs/log/M95-table-readers-and-index-68.md` |
| 96 | **M96** — `FUN_8003287c`'s callers and their slot values, enumerated | `docs/log/M96-slot-values-enumerated.md` |
| 97 | **M97** — descriptors are script commands; no code writes their bytes 0 and 3 | `docs/log/M97-descriptors-are-script-commands.md` |
| 98 | **M98** — where the stream comes from: a runtime buffer inside the room overlay | `docs/log/M98-stream-source.md` |
| 99 | **M99** — the stride is settled: a variable-length bytecode, and opcode 0x44 is 22 bytes | `docs/log/M99-stride-settled.md` |
| 100 | **M100** — the watch is set and the probe is built; the one input needed cannot be made here | `docs/log/M100-watch-and-dump-probe.md` |
| 101 | **M101** — the room dump arrived, and it corrects the model: the loader is gated | `docs/log/M101-room-dump-and-the-gate.md` |
| 102 | **M102** — the gate PASSES, and it is vacuous for this descriptor | `docs/log/M102-the-gate-passes.md` |
| 103 | **M103** — the walk: 174 commands, no scene-slot command pending, and slot 31 selects *nothing* | `docs/log/M103-the-walk.md` |
| 104 | **M104** — no other rooms available, and the six "desyncs" are stream ends | `docs/log/M104-no-other-rooms-and-the-six-stops.md` |
| 105 | **M105** — the counter is a flag, and the first real scene-slot commands are found | `docs/log/M105-counter-is-a-flag-and-the-first-slot-commands.md` |
| 106 | **M106** — the maps never populate, and the scene-slot path is a per-execution no-op | `docs/log/M106-maps-never-populate.md` |
| 107 | **M107** — controlling ares directly (design) | `docs/log/M107-ares-control.md` |
| 108 | **M108** — the ares handshake: one byte, and then the whole machine | `docs/log/M108-ares-handshake.md` |
| 109 | **M109** — driving the game through the debugger: the transport works, the input layer doesn't | `docs/log/M109-ares-injection-attempt.md` |
| 110 | **M110** — three rooms, one operand, and the scene-slot path is by design | `docs/log/M110-three-rooms-one-operand.md` |
| 111 | **M111** — experiment B, step 1: a provenance core that survives its own fixture | `docs/log/M111-provenance-step1.md` |
| 112 | **M112** — experiment B, step 2: summaries resolve the record chain, and the map reader stays out of reach | `docs/log/M112-provenance-step2.md` |
| 113 | **M113** — `CONSTBASE`, and what acceptance test 2 actually proves | `docs/log/M113-provenance-cbase.md` |
| 114 | **M114** — jump-table edges: 4 142 new edges, and the `unreached` bucket finally moves | `docs/log/M114-provenance-jump-tables.md` |
| 115 | **M115** — the `unk` bucket: measure the cause first, then fix the one that dominates | `docs/log/M115-provenance-unk-cause.md` |
| 116 | **M116** — frame slots: entry-relative keys, and proof that `spoff` is not an unresolved bucket | `docs/log/M116-provenance-slotkeys.md` |
| 117 | **M117** — Ghidra's function bounds replace my heuristic, and two layer-2 fabrications fall out | `docs/log/M117-ghidra-bounds.md` |
| 118 | **M118** — frame slots are 98.5 % resolved; the residual is stack arguments, and the tests are now executable | `docs/log/M118-provenance-slot-misses.md` |
| 119 | **M119** — stack-argument propagation: the mechanism resolves 89.8 %, and buys seven addresses | `docs/log/M119-provenance-stack-args.md` |
| 120 | **M120** — the caller-side check: 7 sites out of 14 371, and one of them read from the instructions | `docs/log/M120-provenance-stk-check.md` |
| 121 | **M121** — reading the callee: seven confident flags, all mine | `docs/log/M121-provenance-stk-verdict.md` |
| 122 | **M122** — the register-argument check: same method, different question, and it needed four calibrations | `docs/log/M122-provenance-arg-check.md` |
| 123 | **M123** — path sensitivity clears the polymorphic sites, and what perfect_dark is actually good for | `docs/log/M123-path-sensitivity-and-perfect-dark.md` |
| 124 | **M124** — the controller layout, diffed against perfect_dark's libultra | `docs/log/M124-controller-layout-diff.md` |
| 125 | **M125** — the CHNL_ERR path, made executable | `docs/log/M125-chnl-err-made-executable.md` |
| 126 | **M126** — `pad_layout` in the acceptance suite, and a mixed-errno fixture that changed a behaviour | `docs/log/M126-acceptance-suite.md` |
| 127 | **M127** — a pre-commit hook that runs the acceptance suite | `docs/log/M127-pre-commit-hook.md` |
| 128 | **M128** — CI: the same acceptance run, locally and on a runner | `docs/log/M128-ci.md` |
| 129 | **M129** — a 9 KB synthetic cartridge, so the corpus pipeline runs in CI | `docs/log/M129-synthetic-corpus.md` |
| 130 | **M130** — can the last three checks run in CI? Two blockers, one of them removable | `docs/log/M130-corpus-checks-in-ci.md` |
| 131 | **M131** — a scripted edit now fails loudly instead of doing nothing | `docs/log/M131-loud-patches.md` |
| 132 | **M132** — the marker check: the loop M131 left open | `docs/log/M132-marker-check.md` |
| 133 | **M133** — the marker check now runs in both directions | `docs/log/M133-marker-reverse-check.md` |
| 134 | **M134** — the registration check extended to the notes themselves | `docs/log/M134-note-registration.md` |
| 135 | **M135** — being registered is not the same as being registered correctly | `docs/log/M135-index-consistency.md` |
| 136 | **M136** — the 141 handlers, mapped: every opcode advances the stream by its own N | `docs/log/M136-command-length-map.md` |
| 137 | **M137** — Phase 2 starts from a reference, and its fingerprints do not yet fire on our data | `docs/log/M137-phase2-reference-and-negative-tests.md` |
| 138 | **M138** — the registry route pays: nine 8-byte entries, the room's own entry point, and two confirmed structures | `docs/log/M138-registry-route.md` |
| 139 | **M139** — S2DEX is searchable: OCR with the OS, no installs | `docs/log/M139-s2dex-ocr.md` |
| 140 | **M140** — the enemy routine table is found; the room header is runtime data, and that closes the static route | `docs/log/M140-enemy-table-and-room-header.md` |
| 141 | **M141** — OpenBiohazard2 names the opcodes, and it breaks the "one length per opcode" claim | `docs/log/M141-openbiohazard2-names-the-opcodes.md` |
| 142 | **M142** — the licensed table is imported, the walk refuses to guess, and M141's own correction was wrong | `docs/log/M142-licensed-table-and-a-walk-that-refuses.md` |
| 143 | **M143** — the jump family decodes, and `0x32 Poset` was never missing a length, only a window | `docs/log/M143-jump-decoder-and-poset.md` |
| 144 | **M144** — `0x03` is a script jump, the advance scan becomes a dataflow, and the walk is in the gate | `docs/log/M144-script-jump-dataflow-and-walk-gate.md` |
| 145 | **M145** — all 141 opcodes classified, and the script base turns out to be a cartridge block | `docs/log/M145-all-opcodes-classified-and-the-script-base.md` |
| 146 | **M146** — the id resolves, and a real room script decodes out of the cartridge | `docs/log/M146-room-script-decoded-from-cartridge.md` |
| 147 | **M147** — the whole file table swept: 102 673 commands, every opcode seen, and the shape of a scenario | `docs/log/M147-opcode-profile.md` |
| 148 | **M148** — a dozen opcode reads, and a second naming source that cannot be confused with the first | `docs/log/M148-twelve-opcode-reads.md` |
| 149 | **M149** — the two-NOP question, and three more reads (one of them a random number generator) | `docs/log/M149-two-nops-and-three-more-reads.md` |
| 150 | **M150** — the block-return slots are modelled, the CFG walk is real, and the NOP answer flips | `docs/log/M150-block-slots-and-the-nop-answer.md` |
| 151 | **M151** — the 1 % was my own defect, the GoSub stride settles, and the dead-code list exists but is not proof | `docs/log/M151-orphans-stride-and-dead-code.md` |
| 152 | **M152** — the callback theory is refuted by the code, and the interpreter loop is now read | `docs/log/M152-callback-theory-refuted.md` |
| 153 | **M153** — both leads closed: the dead-only list falls from 8 to 2, and the stream exits were right | `docs/log/M153-both-leads-closed.md` |
| 154 | **M154** — no direct starter exists, `0x0f` was mis-sized, and a guard-order bug made my own model inert | `docs/log/M154-no-direct-starter-and-a-guard-order-bug.md` |
| 155 | **M155** — the gate audited: three checks were vacuous, and two of my audit's own mutations were too | `docs/log/M155-gate-audit.md` |
| 156 | **M156** — both leads closed, by asking a smaller question | `docs/log/M156-room-population-closes-both-leads.md` |
| 157 | **M157** — the rule applied backwards: every earlier population, audited | `docs/log/M157-population-audit-retrospective.md` |
| 158 | **M158** — the section-table hypothesis is refuted, and the room table turns out to be a resource table | `docs/log/M158-section-table-refuted-resource-table.md` |
| 159 | **M159** — the `01 41` count field is decoded: 16 bytes per unit, proven on 355 of 355 | `docs/log/M159-container-count-decoded.md` |
| 160 | **M160** — the correlation run: N is neither a bit depth nor a value count | `docs/log/M160-correlation-refutes-bit-depth.md` |
| 161 | **M161** — the display-list reading, tested and refuted | `docs/log/M161-display-list-reading-refuted.md` |
| 162 | **M162** — relational: the family is what the *model* loaders load | `docs/log/M162-relational-loader-kinds.md` |
| 163 | **M163** — the three calls read: relocation, part filter, and a tile grid of *display lists* | `docs/log/M163-three-calls-relocation-grid-display-lists.md` |
| 164 | **M164** — dumping the tile: there is no GBI in it, and M163 was wrong | `docs/log/M164-tile-dump-refutes-gbi.md` |
| 165 | **M165** — the T64 tiles decoded: no compression, a palette and raw indices | `docs/log/M165-t64-format-no-compression.md` |
| 166 | **M166** — `h1` is the true height, not a stride | `docs/log/M166-h1-is-the-height.md` |
| 167 | **M167** — palettes are not shared: the engine shares whole tiles | `docs/log/M167-palettes-not-shared.md` |
| 168 | **M168** — the handle's high byte is a global allocation counter, not a per-slot generation | `docs/log/M168-registry-handle-generation.md` |
| 169 | **M169** — nothing else writes the handle, and the use path doesn't just compare: it traps | `docs/log/M169-handle-writers-and-the-trap.md` |
| 170 | **M170** — `trap(0)` is `break`, and the exception path never returns | `docs/log/M170-break-halts.md` |
| 171 | **M171** — where it stops, and why nothing software can do will restart it | `docs/log/M171-where-it-stops.md` |
| 172 | **M172** — *(no row, no note)* | commit only: `cc1673b` “M172: drop a citation to a file the repo does not have”, `c26d44a` “M172: consolidate for a rebuild — the format header, its C validator, and the start-here doc” |
| 173 | **M173** — `obj+5` is not bounded below 14, and 14 turns out not to be the bound | `docs/log/M173-obj-plus-5-is-not-bounded.md` |
| 174 | **M174** — the runner CI that never ran, the suite that would have gone red, and the two mistakes I made finding them | `docs/log/M174-the-ci-that-never-ran.md` |
| 175 | **M175** — the self-hosted tier: all 230 cases in CI without uploading the cartridge | `docs/log/M175-the-self-hosted-tier.md` |
| 176 | **M176** — the secret holds access, not bytes: CI fetches the cartridge | `docs/log/M176-the-secret-holds-access.md` |
| 177 | **M177** — publication readiness: a frontpage, a licence, and a copyright audit that reads bytes | `docs/log/M177-publication-readiness.md` |
| 178 | **M178** — the file table is the file system, and the 17.6 MB is the sound family | `docs/log/M178-file-table-and-the-sound-family.md` |
| 179 | **M179** — `u16@+4` refuted three ways, and the directory becomes a reading | `docs/log/M179-u16-at-plus-4-refuted-and-the-directory-read.md` |
| 180 | **M180** — the counts are derived, not hand-edited | `docs/log/M180-counts-derived-and-asserted.md` |
| 181 | **M181** — the verifier | `docs/VERIFICATION.md`, `tools/verify.py`, `tools/audit_gates.py` |
| 182 | **M182** — nothing in the corpus reads the record header | `docs/log/M182-nothing-in-the-corpus-reads-the-record-header.md` |
| 183 | **M183** — a milestone that exists only as a commit is refused | `docs/log/M183-a-milestone-that-exists-only-as-a-commit.md` |
| 184 | **M184** — id 1983 is parsed at the container level, and its codec is a named gap | `docs/log/M184-id-1983-framed-and-its-codec-named.md` |
| 185 | **M185** — the sound family is framed: proj and pool are chained section tables | `docs/log/M185-the-sound-family-framed.md` |
| 186 | **M186** — the 835 unresolved shorts are 834 zeros and one dangling reference | `docs/log/M186-the-835-resolved.md` |
| 187 | **M187** — the codec is identified: MusyX ADPCM, with a 16-byte prologue | `docs/log/M187-the-codec-identified.md` |
| 188 | **M188** — the two holes: 531 is a stale index, 11 is an unused slot | `docs/log/M188-the-two-holes.md` |
| 189 | **M189** — id 1979 is a second codec, its header is 12 bytes, and the 418 is a rotation | `docs/log/M189-a-second-codec-and-the-rotation.md` |
| 190 | **M190** — the 2.42 % was my alignment error, and `u16@+4` stays unassigned | `docs/log/M190-the-residual-was-mine.md` |
| 191 | **M191** — `u16@+4` closed as unassignable, the codebook fields confirmed, and the README fixed | `docs/log/M191-u16-closed-codebook-confirmed-readme-fixed.md` |
| 192 | **M192** — the codec's header fields are understood, and `u16@+4` is closed with its reason | `docs/log/M192-codec-fields-understood-u16-closed.md` |
| 193 | **M193** — `u16@+4` is the block count, and the pool codec is decoded | `docs/log/M193-u16-is-the-block-count-and-the-codec-is-decoded.md` |
| 194 | **M194** — the voice decoder is not implemented, and the description does not fit this cartridge | `docs/log/M194-the-voice-decoder-does-not-reconcile.md` |
| 195 | **M195** — `FUN_800b53f4` transcribed field by field, and why the decode still does not run | `docs/log/M195-the-voice-stream-transcribed-and-the-ring.md` |
| 196 | **M196** — the suite was slow because it recomputed, not because it was Python | `docs/log/M196-the-suite-was-recomputing.md` |
| 197 | **M197** — the ring does nothing to the bytes, and the reader reverses them | `docs/log/M197-the-ring-does-nothing-and-the-reader-reverses.md` |
| 198 | **M198** — the voice bank decodes to audio, by running the cartridge's own synthesis | `docs/log/M198-the-voice-bank-decodes-to-audio.md` |
| 199 | **M199** — the voice synthesis is transcribed, and it agrees with the cartridge sample for sample | `docs/log/M199-the-synthesis-is-transcribed.md` |
| 200 | **M200** — the pool's classes, pinned from the data | `docs/log/M200-the-pools-classes-pinned.md` |
| 201 | **M201** — the 16-byte records, and the encoding hiding in them | `docs/log/M201-the-16-byte-records-are-little-endian.md` |
| 202 | **M202** — the four parameters named, and what feeds cache B | `docs/log/M202-the-parameters-and-the-pairing.md` |
| 203 | **M203** — +20 and +24 are a loop start and a loop *length* | `docs/log/M203-loop-start-and-loop-length.md` |
| 204 | **M204** — there is no +28: the record ends at +27 | `docs/log/M204-there-is-no-plus-28.md` |
| 205 | **M205** — the coverage figure was one word per function body too high | `docs/log/M205-the-coverage-figure-was-one-word-high.md` |
| 206 | **M206** — the manifest published a word count as `covered_bytes` | `docs/log/M206-the-manifest-published-words-as-bytes.md` |
| 207 | **M207** — the other 37.8 % is classified, not shrugged at | `docs/log/M207-the-rest-of-the-image-bytes-classified.md` |
| 208 | **M208** — the census was a whole corpus generation stale, and the cull is a decision | `docs/log/M208-the-census-was-a-generation-stale.md` |
| 209 | **M209** — "3 638 decompiled" is one claim; here are the four that are not it | `docs/log/M209-the-ladder-and-the-two-axes.md` |
| 210 | **M210** — three published claims corrected, and the landing unit becomes a cycle | `docs/log/M210-three-claims-and-the-cycle-contract.md` |

## The gaps, and why they are empty

**50** milestone numbers have neither a row in `docs/reverse_engineering_log.md` nor a note in `docs/log/`. The project did not keep a note for every number it used: much of the middle work was recorded in `docs/format_notes.md` and in commit messages instead, and the log's own numbering runs M10–M30 in that style before resuming per-milestone notes at M81.

* **M48, M51, M78, M172** survive only as commit subjects, quoted above. Nothing further is known about them, so nothing further is written.
* **31–47, 49–50, 52–77, 80** have no evidence in the tree at all — no row, no note, no commit that names them.

None of these gaps is reconstructed after the fact. A note written from guesswork would be indistinguishable from a note written from measurement, and this project's whole claim is that the difference is visible.
