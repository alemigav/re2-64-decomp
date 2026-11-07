# The technical companion

This is the dense half of the project's front page. [README.md](../README.md) carries the short version — what the
project is, what it proves, how to check it in a minute — and this file carries the reference material behind it: the
corpus numbers with the qualifiers they need, the toolchain profile, every recovered function, the format
reference, the verification architecture, and the residue list.

| if you want… | read |
| --- | --- |
| the short version, and how to verify it | [README.md](../README.md) |
| **this file** — the full technical state | you are here |
| to resume the *work* cold, with its rules and traps | [docs/handover.md](handover.md) |
| what the cartridge contains, with the measurement behind each claim | [docs/format_notes.md](format_notes.md) |
| to rebuild the toolchain and the pipeline | [docs/TOOLCHAIN.md](TOOLCHAIN.md) |
| how verification is layered, and what each tier cannot catch | [docs/VERIFICATION.md](VERIFICATION.md) |
| every milestone, in order, with a note each | [docs/MILESTONES.md](MILESTONES.md) |
| the narrative record, including retractions | [docs/reverse_engineering_log.md](reverse_engineering_log.md) |

---

## 1. What the numbers mean, and which ones to trust

Every figure on the front page is **derived from the fixtures and asserted by `tools/counts.py`**, in sixteen places,
including in this file's shorter sibling. A phrase that *disappears* counts as a failure, so a stale line cannot be
fixed by deleting it. Where a number is a *reading* rather than a measurement, the text says so.

**The corpus of recovered functions is 362 entries, 361 of them byte-exact.** The composition matters more than the
total, and any headline quoting it must carry this line:

| | count | what it is |
| --- | --- | --- |
| reconstructed by hand from the disassembly | **16** | the information-bearing core — the table in §3 |
| singles landed from one shape each | **55** | one draft per body, measured against `leaf_screen.py` |
| imported from another decompilation and re-verified here | **194** | one tool scores that corpus through this profile against this cartridge (`tools/other_corpus.py`); these fifteen came back word-exact, and nothing else about that project is taken on trust |
| copies of twenty-one proven body shapes | **97** | one proven reconstruction registers every copy: 44 empty functions, 11 nine-word masked calls, **17 of the dispatch family** across eight table addresses (M335), three of a masked read-modify-write loop, three of a three-store setter, and the rest two-copy shapes found by the *statement order*, by the *stride* rather than the walk (M355), or by where a constant sits in an OR chain |

So "362" is a **corpus** number, not 360 independent reconstructions. The remaining published residue is one function
at **226 of 229 words**; everything else is byte-exact. And the cohort gain is not free but it is not
closed either: the eight dispatch groups were reachable (M335), and three of the four bodies drafted alongside them
were then closed by moving a *materialisation* ahead of a load — 11, 12 and 18 words, two copies each (M336) — while
the fourth stayed 7 of 11 for a reason the words name.

The progress map on the front page draws only the **16** hand-recovered functions, one cell per group of functions. The
344 singles, copies and imports are in the fixtures and in the counts above, not in the picture — the map's job is to show where
the *matching* question stands per image, and a picture that inflated itself with cohort copies would be the same error
as a test that asserts nothing.

**The verification tiers.** `tools/verify.py` defaults to a fast tier whose verdict is `PASS-FAST` and whose certificate
records `admission: not-run`; `--full` adds the mutation audit and is the only verdict that admits a claim. The fast
tier exists because the project's own rule is that **verification must fit in 30 seconds end to end** — four heavy
suites are named and timed in `acceptance.HEAVY_SUITES` rather than quietly moved into the fast path.

## 2. The corpus, and the geometry it came from

- **36 images** — `boot`, `stage2`, and 34 overlays — censused from the cartridge's own load table: **1 956 560 B**,
  **3 690 functions** over **3 678 ranges**, **1 242 488 B (63.5 %)** inside a known body.
- **The other 38.1 % is classified, never shrugged at:** 408 124 B padding, 6 680 B data the decompiler names,
  980 B of jump tables, **23 980 B** of float tables, **20 380 B** of pointer tables, **13 200 B** of string
  tables, and **440 B (0.0 %) unclassified** — a bucket that is published and is never renamed
  `data` on a hunch.
- **174 switch case bodies** are code and are counted in the ranges and the byte total, but the provider itself labels
  them `switchD_::caseD_`, so they live under `src/<image>/switch/` instead of being published as functions.
- **The analysis ladder** (`tools/analysis_status.py`): F0 3 690 / F1 3 430 / F2 3 405 — of **3 690 functions**,
  **3 405** resolve every call target in their bodies, **33** carry a curated name, and **12** have behaviour pinned by
  a gate or an executed experiment. All 12 are still called `FUN_…`: a name needs evidence of its own.
- **The boot image has two extents, and the difference is what the loader loads.** Code is `0x11140`
  (`0x80000480..0x800115C0`); the **load** extent is `0x13420`, and it ends exactly at `__bss_start` (`0x800138A0`) —
  the value read out of `main`'s own byte-exact C. The bytes between the two are not filler: the version string
  `RE.0930…9.1542`, the **overlay table** at virtual `0x80012150` (magic `OVERLAYTABLENUMC`, rows of
  `{rom_start, rom_end, vram_start, vram_end}` with flags in `rom_start`'s high nibble), and the ASCII table before
  stage-2's zlib.
- **Four extent corrections remain open.** `0x8004276c`, `0x80042824` and `0x800421b4` are 46 words each (96 callers on
  the first) and `boot:0x80000dd4` is 95 words, but all four are **hand-written assembly**, so `recovered.json` — the
  extent authority for *recovered* functions — cannot carry them, and the index still calls a 96-caller function a
  three-word stub. The evidence class that would admit the correction is a `--called` walk plus the absence of a
  return, which is *weaker* than the `__bss_start` witness that authorised the boot correction; said plainly, as it
  should be.

## 3. The matching build

The question that decides whether a decompilation can ever be byte-exact is *what produced these bytes*. It is answered
by measurement, not by reading:

- **Compiler:** gcc **2.8.1** for `mips-elf` at `-O2 -G 0 -mips2`, four of four probe functions byte-identical,
  including a linked probe gcc 2.7.2 cannot reproduce.
- **Assembler:** binutils **2.7**, which expands `move` to `addu` natively — the cartridge's idiom, where modern gas
  picks `or`.
- **`-g` on the assembler, and it is not about debug info.** gas's `mips_optimize` defaults to 2, and at that level it
  fills a branch's delay slot by *swapping the branch with the preceding instruction*. `-g` sets it to 0. Across the
  whole image **not one of the 2 237 `jr ra`** has a load in its delay slot, so the original build assembled with the
  swap off — invisible until a function has a `load; return` arm, and then it is 41 words.
- **`-mcpu=r4300` on both compiler and assembler.** On the compiler it selects the load's `READY-DELAY` (2 instead of
  3) and therefore the instruction order; on the assembler it stops a hazard `nop` after every `mtc1`.
- **Two patched compiler behaviours**, forced by evidence about the image: its constant pool holds the real IEEE bits,
  and its `.rodata` is `[jump table][constant pool]` with every float constant loaded from memory — a scan of the whole
  image finds no `li.s` expansion anywhere.

With that profile, sixteen functions have been reconstructed from the disassembly and recompiled:

| function | size | result |
|---|---|---|
| `0x8004fd1c` | 98 words | **byte-exact** (only alignment padding past the image's extent) |
| `0x80057e1c` | 84 words | **byte-exact, zero differences** |
| `0x80024558` | 139 words | **byte-exact** — needed two toolchain facts rather than source work: the original gives every **double** constant its own pool slot and shares its **float** ones, and it never splits a **float** address, so the assembler materialises it with `$at` |
| `0x80070120` | 46 words | **byte-exact**, jump table included — a predicate dispatcher over `==`, `>`, `>=`, `<`, `<=`, `!=` and `&` |
| `0x80059868` | 167 words | **byte-exact**, jump table included — a seven-state game-state machine touching the device window |
| `0x80059530` | 206 words | **byte-exact**, jump table included — twelve arms, the state machine that runs immediately before the one above |
| `0x800acae4` | 53 words | **byte-exact**, jump table included — a clamp-then-dispatch predicate on an offset domain (`(cmd & 0xff) - 128`) |
| `0x800704e0` | 123 words | **byte-exact**, jump table included — 44 arms returning `p + offset`, ten also bumping a `u16` counter, one shared increment tail |
| `0x8006e68c` | 41 words | **byte-exact**, jump table included — a seven-operator predicate dispatcher |
| `0x8000cc90` | 24 words | **byte-exact** — `osSetEventMesg`, and a revision marker: Nintendo's later source carries an `OS_EVENT_PRENMI` block this image does not, and removing exactly that block reproduces it |
| `0x80006d30` | 9 words | **byte-exact** — `osCreateMesgQueue`, the first **library** function recovered: Nintendo's libultra C through this pipeline is byte-identical, which is what says RE2's runtime was *rebuilt from libultra source* rather than linked as objects |
| `0x8006e574` | 23 words | **byte-exact** — a bit-test leaf, exact once the table pointer is the *first* addend and the offset is written as a shift |
| `0x8006ff48` | 98 words | **byte-exact**, jump table included — the write half of the accessor pair whose read half is `0x800701d8` |
| `0x8006fc5c` | 53 words | **byte-exact**, jump table included — the smallest arm-shaped dispatch, writing a halfword into `base + a * 376` |
| `0x800701d8` | 141 words | **byte-exact**, jump table included — a 44-arm accessor dispatcher; it forced `-g` on the assembler |
| `0x8007e590` | 229 words | 226 of 229 — a **structural** last mile: the switch has no `default:`, so case 3 `break`s into the device-update tail while cases 1 and 4 `return` past it. The three remaining words are one register in case 4's value select |

`main` (`0x80000520`, 30 words) is also byte-exact, and it is the first **named** function to reach that rung: `p = __bss_start; n = __bss_end - __bss_start; while (n--) *p++ = 0; …` with `__bss_start`
`0x800138A0` and `__bss_end` `0x80018A80` — the same two constants that then corrected the boot image's own declared
size.

### 3a. `vector_installer` — a measured near-miss, with its ledger

`boot:0x800070c0` is the largest function attempted (132 words) and it is published as a near-miss rather than
rounded up. Four drafts, one section at a time:

| region (aligned on the eleven calls) | image | draft | delta |
| --- | --- | --- | --- |
| prologue (window store, address, call, slot) | 8 | 9 | **+1** |
| both poll loops | 7 | 6 | **−1** |
| four 16-byte copies + both cache calls | 46 | 46 | 0 |
| the mask block and the 64-bit ×3 | 26 | 24 | **−2** |
| after `FUN_80006100` | 11 | 12 | **+1** |
| PRId dispatch and epilogue | 19 | 19 | 0 |
| **total** | **132** | **130** | **−2** |

Register-agnostic alignment reaches **60 of 132** words with a **39-word contiguous run** through the copy group; the
word-identical score is 16 of 132, because what is left is which registers the allocator chose — the wall this project
closed in M295/M311. Three of the four one-word placements are the *image* being worse than the draft (a redundant
`lui`, a `nop` in a back-edge slot), and the fourth is a compiler-version difference verified by assembly experiment.

Four rules came out of it, each measured and each reusable:

- **`$at` is the assembler, not a register allocator.** A symbol store is split into a general register; a
  **literal-address** store is left bare and `as` expands it with `$1`; `volatile` forces a register and costs two
  instructions. The split is per access direction *and* per address spelling.
- **A store is a `jal`-delay-slot candidate only when its address is already in a register**, so the `$at` form and the
  schedulable form never combine — and the price of sinking one is that cc1 hoists its high half to the top of the
  function.
- **A `u64` in the C is a `DImode` the original source may not have had.** `((u64)hi << 32) | lo` makes cc1 build and
  shuffle a register pair (five instructions); explicit `u32` pair arithmetic reproduces the image's eight operations
  with zero copies.
- **A word count cannot detect a wrong operand.** The draft carried an inverted `if` and two comparison constants
  (`== 0`/`== 2` had been written as `== 0x02F5B2D2`/`== 0x02E6025C`) for five milestones without moving the score; only
  reading each branch's operand against its range found them.

## 4. What the project produced

- **The mapping law**: `vram = rom_offset + 0x7FFFF480`, established three independent ways after the first version of
  it was wrong by `0x480` and had invalidated every address (M7).
- **The container**: 4 761 zlib members, 8 748 242 → 18 550 424 B, plus 1 227 MJPEG frames and 271 MPEG-1 blocks, all
  verified byte-for-byte.
- **The script VM**: a 141-entry handler table, **18 distinct instruction lengths** from 1 to 40 bytes, decoded from the
  handlers' own behaviour rather than from a reference. `0x44 SceEmSet` carries the enemy Id at byte 3; `GoSub` has
  stride 2.
- **Room population**: 256 table entries → 147 ids → 50 room scripts, proven before anything was modelled on it.
- **The texture container (T64)**: palette plus raw indices, no compression,
  `len = 16 + entries·2 + w·h·bpp/8` verified on **65 of 65** tiles.
- **The exception path**: `break` → vector → dispatch loop `0x8000098c`, with no `eret` and no EPC write — fatal, only
  a hardware reset leaves it.
- **The audio filesystem**: the file table *is* the file system, not a zlib manifest — 8 091 entries, **3 126 stored
  raw** — and the 17.6 MB "unidentified" region is five files: a 588-record `MORT` voice bank, three chained section
  tables, and a sample pool of **1 192 samples that tile it to the byte**.
- **The sample codec, decoded**: order-2 ADPCM with a **256**-byte shared codebook, **217 944** of **217 944** groups
  structurally valid and **1 180** of **1 192** samples decoding to audio (median adjacent correlation +0.901). The other
  twelve are not failures: correlation runs continuously from +0.44 to +0.98 with no gap, and the low tail is
  noise-like content — a 0.7 line drawn through a smooth distribution.
- **Two codecs, not one**: `id 1979`'s 588 records are *not* that format — high-entropy, 16 000/8 000 Hz, no raw
  prelude — so the voice bank and the sample pool are encoded differently.
- **The voice codec, bit-exact**: LSB-first bits inside big-endian words, 160 samples per block in 260-bit frames, 14 %
  of blocks silent; the whole synthesis (dequantisation, a pitch predictor, an 8-stage lattice, a four-band polyphase
  mix) is reimplemented and graded **sample for sample**: 13 clips, 634 blocks, 0 differing.
- **RSP microcode** decoded and deliberately not named, the vector unit named 252 of 254, and the dispatch-head queue
  resolved.
- **A verification system that can be checked without the game** — §6.

## 5. Format reference

Formats are documented in [docs/format_notes.md](format_notes.md) with the measurement behind each claim, and codified
in [include/re2_formats.h](../include/re2_formats.h) with a C validator (`tools/t64info.c`) compiled and run in both
directions on every gate run.

| format | state |
|---|---|
| cartridge | 67 108 864 B, header entry `0x80000480`, cart table at vram `0x80012150`, 66 records + a build stamp |
| script VM | 141 handlers, **18** lengths (1–40 B), `0x44 SceEmSet` carries the enemy Id at byte 3, GoSub stride 2 |
| room population | 256 byte entries → 147 ids → 50 room scripts |
| model container | `01 41` = format version **321**, self-relative offsets relocated by `FUN_800824b8` |
| textures (T64) | `[0xBE1E][height][width][size][format][palette entries]` + RGBA5551 + raw 4/8-bpp indices |
| exception path | `break` → `jr k0` → `0x800006d0` → dispatch loop `0x8000098c`; unrecoverable by design |
| file table | 8 091 entries + build stamp; 4 852 zlib, **3 126 stored raw** — the media, uncompressed |
| sound files | ids 1979–1983: a 588-record `MORT` bank, `SND_PROJ`/`SND_POOL` chained tables, `SND_SMPDIR` |
| sample pool | id 1983, 9 022 912 B: **1 192 samples tiling it to the byte**, 15 canonical rates |
| sample codec | order-2 ADPCM: one **256**-byte shared codebook per bank, then 40-byte groups — `2 raw + 30 nibbles = 32 samples` per 20-byte frame |
| voice bank header | `MORT` + u16 **block count** + u16 rate + u32 **length/4** = **12** bytes; a normal block is a fixed 260 bits |
| voice codec | bit stream is LSB-first inside big-endian 32-bit words; per block 36 scale bits + 4 × (17 + 39); synthesis transcribed and bit-exact |
| directory record | 28 bytes: index, refcount, offset, rate, codec byte, **24-bit declared length**, **loop start**, **loop length** — the mixer adds the last two for the loop end and plays the remainder out on release |
| key spaces | pool keys are `[tag][index]` with the tag in the **top two bits** (`(key >> 14) & 3`); the four POOL **sections** are tagged 0, 3, 1, 2 in file order — sections are *storage*, while the roles are the **six lists** a `SND_PROJ` record carries; `SND_PROJ`'s 417 records rotate from key 118 |

What genuinely remains: **what the 16-byte class-3 parameter record is called** — its fields (rate, time, size, level)
and its role are measured, but the cartridge never labels it. The loop points a directory record carries are settled:
**+20 is a loop start and +24 a loop length**, both in decoded samples, and 187 of the 1 192 records name one.

## 6. The verification architecture

This is the part that is unusual for a decompilation, and the part that can be checked in a minute. No ROM, no assets,
no emulator.

- **`tools/audit_gates.py` disables each check's mechanism and requires the check to fail.** 146 mechanisms, 146
  failures, **0 vacuous**, and the unmutated tool runs first as a positive control: an audit whose sandbox cannot run
  the tool is reported **BROKEN**, not passed. That control found that **49 of 132** audits had never tested their
  mutation — the sandbox had no `manifests/` — so an earlier `127/127` was inflated. It has since caught checks that
  could not fail: its own environment assumptions, a verdict rule that made five audits green because it grepped the
  output for the word `FAIL`, and two mutations that were provably no-ops on this image.
- **`tools/ratchet.py` forbids the three silent edits that make a suite pass**: lowering an expected count, deleting a
  suite, or editing `src/` to satisfy a check. Every change needs `--write`, which is a diff.
- **`tools/counts.py` derives every number quoted in the README and the handover** from the registry and asserts them in
  sixteen places. A phrase that disappears is a failure, so deleting a stale line cannot help.
- **`tools/milestone_index.py --check` regenerates the milestone index** and fails if it drifts from the log; the index
  cannot be hand-edited into agreement with anything.
- **`tools/check_markers.py`** asserts that named sections still exist in the handover and the log, and that every
  `docs/log/*.md` the milestone table points at exists — written because two handover sections were once committed,
  written, and absent for four commits while nobody grepped.
- **`tools/artefact_scan.py`** asserts that no tracked file is cartridge content: no file begins with an N64 cartridge
  header, none matches the committed SHA-256, `rom/`, `assets/`, `build/` and `*.pdf` are untracked.
- **`tools/hook_cert.py`** lets a commit skip the suite only when the worktree hash, the verdict and the cleanliness
  match a certificate that `verify.py` wrote — certify the hook, never bypass it.
- **`tools/verify.py`** adjudicates all of it into one verdict, and a dirty gate audit is **`INCONCLUSIVE`**, never
  `PASS`.

CI runs the cartridge-less half of that on every push (`.github/workflows/acceptance.yml`), three ways: the fast gate,
the full gate, and a self-hosted job for a machine that has the dump. The suites that need the cartridge print
`SKIP (needs the cartridge)` — **never PASS** — because a suite that cannot run and reports success is the same error
as a test that asserts nothing.

Two operating rules shape the gate rather than the code: **verification must fit in 30 seconds end to end** (hence the
`PASS-FAST` tier and the four named and timed heavy suites), and **a measurement that authorises must also veto** — a
gate that can only fail in the direction you were already worried about is not a gate.

## 7. Progress map — and what it does not draw

The map on the front page is generated by `tools/progress_map.py` and gated: `--check` fails on a missing block, a
stale block, or a function claimed as recovered that is not in the corpus. Two panels:

- **the cartridge**, one cell per group of functions, shaded by how far each group is *matched* — `█` byte-exact,
  `▓` recovered but not exact, `▒` pseudocode body only;
- **the record**, one bar per phase, parsed from the front page's own phase table, so the picture cannot drift from the
  table beside it.

It draws the **16** hand-recovered functions. The 94 cohort copies and 55 singles are counted in `fixtures/decomp/` and
in §1, not in the picture, and the legend on the front page says so. Regenerating it is `python3 tools/progress_map.py
--write` after any change to the recovered corpus **or to the phase table**.

## 8. Rebuild with your own dump

Place the cartridge at `rom/re2.z64` (byte order is auto-detected), then:

```sh
python3 tools/n64info.py rom/re2.z64                          # identify and normalise the dump
python3 tools/unpack_zlib.py rom/*.z64 --out assets/unpacked  # 4 761 members, ~11 s
python3 tools/build_images.py rom/*.z64                       # 36 ELFs into build/elfs/
python3 tools/read_overlay_table.py rom/*.z64                 # the load table, self-validating
python3 tools/export_src.py                                   # build/decomp → src/
sh tools/ci.sh                                                # the whole gate, with the cartridge
```

The decompilation step itself is Ghidra 12.2 driven through REA's CLI (`rea decompile-all --provider ghidra`), one
invocation per image, seeded from `config/symbols.tsv`. It takes hours, not minutes; the chain that matters for
reproducing the *findings* is the gates, and those take a minute.

The order matters in one place that has bitten twice: **`fixtures/decomp/images.json` is regenerated by
`export_ranges.py --write-images`, and `classify_image.py` reads it** — images fixture → byte map → ranges → code index,
or the byte map silently keeps a stale total. `docs/handover.md` carries the full sequence, including how the ranges
fixture (`fixtures/decomp/ranges.json`, 3 678 regions) stands in for the decompiler's index so a rebuild cannot silently
shift a boundary.

Drafting a reconstruction is a committed tool, not a shell loop: `tools/leaf_screen.py --try draft.c --image NAME
--addr 0xADDR --count N [--sym NAME=0xADDR …]` compiles one draft through the canonical pipeline and prints the words
that differ, decoded. The permanent tool exists because the selection rules were being re-derived by hand every batch
while their results were gated — the inverse of this project's discipline.

## 9. Where the work stands

The current arc (`P18`, M308–M331) is **the singles sweep and the boot image's own geometry**. In order: the 6–8 word
pool screened and worked; the boot extent corrected from `0x11140` to `0x13420` because a recovered `main` named
`__bss_start`; `main` itself recovered at 30 of 30; the 46-word DSP family closed as hand-written assembly after five
compiler configurations emitted no `dmult`; and `vector_installer` — the largest function attempted — taken from 18 of
132 to a **measured near-miss** whose every section is within one word (§3a).

What is left, in the order it is worth doing:

1. **The duplicate-body census**: **34 candidates in 17 complete two-copy groups** remain — every one of them the same
   body at the same address in `ovl_008900e` and `ovl_008e046` (28 to 146 words), i.e. the enemy-slot variants of one
   overlay; one proven reconstruction registers each copy, which is the cheapest real coverage in the corpus.
2. **The four non-C extent corrections** (§2): a channel is needed before an assembly body can correct the index.
3. **`vector_installer`'s four one-word placements**: three are the image being worse than the draft and one is a
   compiler-version difference; they are published, not chased. The gap to byte-exactness is the original build's
   register allocation.
4. **The five published allocation residues**, each one register in one arm: `0x8007e590` (226/229), `osCreateThread`
   (23/52), 4×25 (22/25), 4×53 (33/53), 3×32 (29/32). Each is worth one *mechanism*, not one more guess.
5. **The remaining 36.8 % of the image**, of which 250 764 B is honestly unclassified — the float, pointer and
   string tables in it are now classes, and its code was adopted in M341.

## 10. References

- **REA / Ghidra 12.2** — the analysis engine; every function in `src/` was produced by it, and its provider record is
  quoted in each file's header.
- **[OpenBiohazard2](https://github.com/OpenBiohazard2/OpenBiohazard2)** (MIT) — a Go re-implementation whose RDT opcode
  table is the one transcription here. Read as code, because MIT permits it.
- **[n64decomp/perfect_dark](https://github.com/n64decomp/perfect_dark)** (MIT) — **struct layouts only**, from
  `include/PR/`. It is *not* a code reference: Rare modified libultra heavily, their own RSP microcode among it.
- **[zeldaret/oot](https://github.com/zeldaret/oot)** (MIT) — the reference for **stock libultra**: its
  `src/libultra/os/` is Nintendo's own C, and it is where `osCreateMesgQueue` came from. Its revision is *later* than
  RE2's — see `osSetEventMesg`, which there carries an `OS_EVENT_PRENMI` branch this image does not have.
- **[Console Protocols: N64 Assembly](https://sites.google.com/site/consoleprotocols/home/homebrew/n64-assembly-home)** — a beginner's `bass`-assembler tutorial, cited for **two semantics only**: conditional branches execute their delay slot *only if taken* (the `beql`/`bnel` nullification this project's drafts rely on), and there are **no immediate compare instructions**, which is why a branch against a constant needs the constant seeded into a register first. It is a tutorial, not a measurement: nothing here is evidence about this cartridge.
- **[n64decomp/banjo-kazooie](https://github.com/n64decomp/banjo-kazooie)**,
  **[n64decomp/sm64](https://github.com/n64decomp/sm64)** — the decomps whose frontpage conventions this one follows,
  and whose CC0 choice it shares.

## 11. Legal and licence

This repository contains **no cartridge data**: no ROM bytes, no extracted assets, no audio, no video. You need your own
legally dumped copy of Resident Evil 2 (N64) to run anything that reads the cartridge. The only `.z64` here is an 8 KiB
*synthetic* fixture that exists so the corpus pipeline can run without the game; the cartridge's SHA-256 is committed in
`manifests/manifest.json` and nothing else from it is.

The files under `src/` are **decompiled pseudocode**, produced by Ghidra from a Capcom work. They are derivative of that
work and are published here for study, with no warranty of correctness and no claim of endorsement.

This project is not affiliated with, endorsed by or sponsored by Capcom or Nintendo. All trademarks belong to their
owners.

The author's own text, tools and fixtures are dedicated to the public domain under **CC0-1.0**
([LICENSE](../LICENSE)); that dedication cannot and does not extend to `src/`. Third-party material is credited in
[THIRD_PARTY.md](../THIRD_PARTY.md) — one table transcribed from MIT-licensed OpenBiohazard2, with its full licence text
reproduced there.
