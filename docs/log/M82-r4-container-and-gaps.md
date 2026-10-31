# M82 — the R4 container, and the stage-2 gaps

**Two questions, one answered, one bounded.**

1. **The 28 non-zlib payloads at cart `0xb6248`.** Geometry and hard structural invariants are
   established from the bytes. The codec is *not* in any family this project can test, and the
   assumption that these payloads are the same content as bank B is **refuted** at the literal
   level. Both are recorded as negatives with their controls.
2. **The 5 488-byte unclaimed region at stage-2 `0x8009d014`.** Not a data island: **three missed
   functions**, one of them an 11-case state machine. They are now in the corpus and the region is
   **99.6 % claimed**.

## 1. The container at cart `0xb6248`

### Geometry — established

* **The payloads tile exactly.** Each of the 28 starts where the previous ends; there is no
  inter-payload padding, no per-payload header, and no trailer. Measured: every adjacent pair has a
  gap of `0` (the single `229 654`-byte gap in the sequence is between the zlib member at slot 6 and
  the start of the run, and is filled by ordinary zlib members).
* **Therefore the cart table *is* the directory.** Offsets and stored lengths come from records
  38–65; nothing needs to be parsed to walk the container.
* Run extent `0xb6248`–`0xc8624` = **81 852 B** stored, exactly the sum of the 28 `stored` fields.

### Structure — established, and it excludes entropy coders

Pooled over all 28 payloads (18 679 four-byte records, 74 716 B):

| measurement | result |
|---|---|
| byte 3 of every record | **`0x00` in 18 679 / 18 679 (100.0 %)** |
| byte 0 of every record | `0x00` in 18 276 / 18 679 (97.8 %) |
| bits 0–4 of the 24-bit value | **never set** (byte 0 < 0x08 always) |
| bits 24–31 | never set |
| bit 15 | set in 83.5 % |
| byte 2 | 39–58 % per bit, i.e. ~uniform |
| per-record entropy | 3.4–3.8 bits/byte raw; 4.2–4.7 after dropping the unused low byte |

The low byte being *never* written is not something an entropy coder can produce — it is a
**record structure of 32-bit words whose low byte is unused**, with the top byte written only
rarely. Every codec that stores a byte stream is therefore excluded on structure alone, before any
decode is attempted. The 432 distinct 16-bit operands out of 1 910 records (payload 38) mark the
data as a **small dictionary of values**, not as coded text.

### Codec — every hypothesis in the matrix rejected

`tools/decode_r4_container.py probe` applies an **exact-length acceptance test**: a decoder has
decoded something only if its output length equals the table's `decompressed` field exactly. A
decoder that produces plausible bytes of the wrong length has produced nothing.

| family | hypotheses tried | result |
|---|---|---|
| zlib / raw deflate / gzip / lzma / lzma-raw / bz2 × 7 transforms (`raw`, 24-of-32 packed both ways, `swap16`, `swap32`, `skip2`, `skip4`) | 42 combinations × 28 payloads | **0 outputs** — every decoder rejects the bytes at the first header |
| byte-oriented LZ command streams, 3 token widths × 6 field splits | 18 combinations × 28 | **rejected** (wrong length, or a back-reference before the stream start) |
| bit-level 1-bit-flag LZ over the packed stream, MSB- and LSB-first, offsets 8–16 bits × lengths 3–9 bits | **1 960 probes** | **rejected** |

That is a negative result, and it is the useful kind: the container is not "zlib with different
constants", which was the cheapest and most likely alternative, and it is not the standard
flag/literal bit-LZ either.

### Identity with bank B — the assumption is refuted, not confirmed

M81 recorded that 28 bank-B records have identical decompressed sizes to 28 bank-C records. That
is a fact about the table. It is **not** evidence about content, and the test is possible because
bank B decompresses, so its plaintext is known:

| window | stored-stream windows found in the size-paired plaintext |
|---|---|
| 6 bytes | **0 / 1 273** |
| 8 bytes | **0 / 954** |
| 4 bytes | 0.00 %–5.00 % per payload |

The 4-byte rate is the number that needs a control, because 4-byte windows over a constrained
alphabet coincide by chance. The control is the other 27 rooms' plaintexts: **in 27 of 28 pairs the
size-paired plaintext scores no better than an unrelated room** (payload 38: 0.84 % paired against
1.62 % for the best unrelated room; payload 48: 0.62 % against 9.06 %). A real literal relationship
would make the paired plaintext win every time.

**Conclusion, stated exactly:** bank C is not an LZ-with-byte-literals encoding of bank B's
plaintext. That does not prove the decoded content differs — a bit-level or transform codec also
scores at chance — so **identity is unestablished in both directions**, and M81's "they are code by
every signal available" was an inference the measurements do not support. Corrected there.

### What would actually settle it

Not more statistics. Either:

* **find the decompressor.** No mapped code references cart `0xb6248` or any of records 38–65 —
  the nine-slot registry loads descriptors 2–10 only, and the corpus's 3 293 functions contain no
  construction of these constants. The loader is in code we have not mapped, which makes the
  unclaimed-run work in §2 a prerequisite rather than a detour; or
* **use the operand dictionary.** 432 distinct 16-bit operands in one payload is the shape of a
  codebook or a palette, and a codebook implies a decoder with a table in RAM.

## 2. The unclaimed region at stage-2 `0x8009d014` — missed functions

The region is **code**, and the first words say why it was missed:

```
0x8009d020  27bdffe0  addiu sp,sp,-0x20      <- a function entry
0x8009d02c  2c62000b  sltiu v0,v1,0xb        }
0x8009d030  10400208  beq   v0,zero,+0x820   } switch on a global
0x8009d040  00031880  sll   v1,v1,2          }
0x8009d044  00621821  addu  v1,v1,v0         }
0x8009d048  8c620000  lw    v0,0(v1)         }
0x8009d04c  00400008  jr    v0               <- dispatch through a table
```

No claimed function `jal`s into it (call closure was 100 % for that reason), so the provider's
call-graph-driven discovery never created it: it is reached indirectly.

**Three functions are now in the corpus:**

| function | body | size |
|---|---|---|
| `func_8009d020` | `0x8009d020`–`0x8009d877` | 2 139 B |
| `func_8009d880` | `0x8009d880`–`0x8009de4f` | 1 487 B |
| `func_8009de58` | `0x8009de58`–`0x8009e583` | 1 835 B |

`func_8009d020` decompiles to an 11-case `switch` calling 11 functions, all of them resolved in the
corpus, driving globals `DAT_8013273a`, `DAT_8013272e`, `DAT_8013272b` — a game state machine, not a
data table. **Region coverage: 0 % → 99.6 % (5 464 of 5 484 B).**

### Generalised: how much code is hiding in the gaps

`tools/find_missed_functions.py` repeats the test for every image. A candidate start is emitted only
when a prologue sits in an unclaimed run **and** that run also carries call/return evidence
(≥ 3 `jal` or ≥ 2 `jr ra`) — the third condition is what separates a missed function from data that
merely contains a prologue-shaped word.

| image | candidates | code-like run bytes |
|---|---|---|
| stage2 | 22 | 60 596 |
| boot | 2 | 844 |
| all six overlays | 0 | 0 |

Seeding them and re-running changed the corpus from **3 267 → 3 293 functions** and coverage from
**61.1 % → 61.6 %** (1 189 484 → 1 199 044 B). The modest gain is the real lesson: seeding a start
does not claim a *run*. Ghidra's body extent stops at the next branch it cannot follow, so a run
that is 60 KB of code yields 9.5 KB of claimed bodies and 254 smaller gaps where 243 were before.

The largest remaining gaps are **not** code: the 521 344 B tail at `0x800b6830` has 816
`jal`-shaped words and **zero** prologues, and the 47 428 B head at `0x80018a8c` has one prologue
against 255 call-shaped words — the same `jal`-shaped-data class the member census identified.

## 3. Verification after the change

`tools/verify_corpus.py` — all hard checks pass: 57/57 seeds placed; call closure inside claimed
code still 100 %; boot bank splat 243 vs Ghidra **213** (210 agree, 33 splat-only, 3 Ghidra-only —
the newly recovered boundaries are now part of that third number); all four named functions still
reproduce their evidence; re-decompiling an overlay gives 3/3 identical body hashes.

## 4. `run-rom.sh`

Inspected, **not committed**. It is a 26-line launcher for the ares app (checks the ROM exists,
then `open -na … --system "Nintendo 64"`, with a `--kiosk` variant). Its header calls running the
cartridge "the project's final objective", which conflicts with the later decision to treat ares as
an optional external validator; that wording would need correcting before it is tracked. Tracking
is a decision for the owner, and it has not been made.

## 5. Next

1. **Find the bank-C loader.** It is the only route to decoding the container; the unclaimed-run
   pass above is the tool for it. Search the remaining 61 KB of code-like gaps and the 4 726
   non-code members for a routine that reads cart `0xb62xx`.
2. **Read `func_8009d020`'s callers.** It is reached indirectly; a function-pointer table that
   names it would also name its neighbours and is likely the same table that selects room overlays.
3. Correct nothing further in `format_notes.md` §5: the addendum there should be read together
   with §1–§2 of this note, which supersede its "code by every signal" wording.
