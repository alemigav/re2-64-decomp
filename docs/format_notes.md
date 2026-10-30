# RE2-64 cartridge formats — what has been established, and how

Everything here is derived from the user's own dump plus code read out of it. Each claim names the
tool that produced it and the measurement that supports it. Anything not measured is marked
**hypothesis**.

```
vram = rom_offset + 0x7FFFF480            ROM 0x1000  <->  vram 0x80000480
```

Getting this wrong shifts every address by `0x480`; three independent tests recover it (see
`docs/log/M7-mapping-correction.md`). Recovery recipe, ~2 seconds:

```sh
python3 -c "…"   # score candidate bases by: fraction of jal targets landing on prologues,
                 # plus count of embedded-string addresses constructed as lui/addiu pairs
```

---

## 1. Cartridge layout (whole image, 67 108 864 B)

| region | bytes | content |
|---|---|---|
| `0x0`–`0x40` | 64 | header (entry `0x80000480`, `NREE`, rev 1, USA) |
| `0x40`–`0x1000` | 4 032 | IPL3 bootcode |
| `0x1000`–`0x12140` | 69 184 | boot bank — 243 functions, code only |
| `0x12140`–`0x14420` | 8 928 | boot data, then the descriptor table at `0x12cd0` |
| `0x14420` → | ~8.7 MB | zlib members (4 761), contiguous from the boot set onward |
| see §4 | ~24.4 MB | MPEG-1 video, 271 container blocks |
| see §5 | ~15.8 MB | MJPEG frames, 1 227 container blocks |
| see §6 | ~17.6 MB | two unidentified blobs |

`splat` classifies 0.11 % of the cartridge as code and 99.89 % as unknown; the unknown is assets, not
unread code.

---

## 2. The cart descriptor table — `vram 0x80012150`, ROM `0x12cd0`

Producer, two instructions of code:

```c
int FUN_80001180(int index) { return index * 0x10 + 0x80012150; }
```

| offset | field |
|---|---|
| +0 | **direct cartridge pointer** `0xB0xxxxxx` (= KSEG1 cart window, offset `xxxxxx`); the boot DMA path masks it with `& 0x0FFFFFFF` because a PI register needs a physical address |
| +4 | stored (compressed) size |
| +8 | destination vram start |
| +12 | destination vram end (= start + decompressed size) |

66 usable records, cart `0x14420`…`0xC85E8`, payload 737 779 B, destinations `0x80018A80`…`0x801899F0`.
This is the **boot load set only**; a whole-ROM sweep finds this table and no other
(`tools/find_cart_table.py`).

Loader: `FUN_80000598` — record → `FUN_8000C870(0, cart & 0x0FFFFFFF, 0x8015B030, size)` (DMA to a
staging buffer) → `FUN_80004550/DC/94` (inflate).

---

## 3. Compression: stock zlib, 16 KB window

The three `FUN_80004*` calls are stock `inflate`: `0x8000` window allocated at state `+0x4c`, window
size `0x8000` at `+0x10`, `trap(0)` on error, and `inflate.c`'s error strings elsewhere in the image.

Streams begin `68 de`: `CMF 0x68` = deflate, `CINFO 6` = **16 KB window**, `(0x68*256+0xDE) % 31 == 0`.
**A scanner keyed on the common `0x78` header finds zero streams in this cartridge.**

`tools/unpack_zlib.py` walks the image sequentially with `decompressobj().unused_data`, so boundaries
are exact rather than guessed: **4 761 members, 8 748 242 B → 18 550 424 B in ~10 s**, output plus
`manifest` to `assets/unpacked/`. Cross-check: the walker and the code-derived descriptor table agree
on 35/40 boot records in both offset and decompressed size.

---

## 4. Media container — **discovered format, verified**

Blocks are stored **payload first, then an 8-byte trailer**:

```
block := payload [pad] trailer
trailer := u32 type, u32 payload_size        big-endian
pad     := 1 byte, present when payload_size is odd
```

Evidence, from 1 226 known frame transitions in the MJPEG region
(`tools/scan_headers.py derive --jpeg-region …`):

| measurement | result |
|---|---|
| field that explains anchor spacing | `u32` at **next-anchor − 4**, big-endian |
| residual `(anchor[k+1] − anchor[k]) − size` | **8** in 52.5 % of cases, **9** in 47.5 % — and 9 exactly when the size is odd |
| trailer type word across all frames | `0x00010000` in **1 226 / 1 226** |

Because the size sits *after* its payload, a block cannot be walked forward by reading its header —
the parser must resolve it backwards: given a payload start `p`, find a trailer at `t` whose declared
size equals `t − p` (or `t − p − 1` when one parity byte is present). A wrong `t` predicts a size that
does not match, so it is rejected rather than trusted. That is `tools/extract_blocks.py`.

### The critical experiment: one parser, four resource kinds

`tools/extract_blocks.py` with `manifests/block_types.json`, dry-run then real:

| kind | region | starts | resolved | payload | coverage |
|---|---|---|---|---|---|
| `mjpeg_frame` | `0x2bdefa9`–`0x3af17fe` | 1 227 | **1 227** | 15 794 094 B | **99.9 %** |
| `mpeg1_video` | `0x1440f30`–`0x2b7d8ea` | 271 | **271** | 24 363 189 B | **100.0 %** |
| `region_r3` | `0x0b73fb3`–`0x140ed84` | 1 479 | **0** | 0 B | **0.0 %** |
| `region_r4` | `0x0338fe1`–`0xb63106` | 1 | **0** | 0 B | **0.0 %** |

**Answer: yes for both media kinds, no for both unknown blobs.** The same parser, the same trailer
type and the same arithmetic resolve the known MPEG resource and all 1 227 JPEG frames without a
single failure — so the format is reusable within its class. The two unidentified blobs are a
*different* container, not a variant with different constants: 1 479 candidate starts in R3 and every
one fails the self-consistency test.

Independent confirmation that the boundaries are real, not just self-consistent: concatenating the
first ten MPEG blocks yields a stream `ffprobe` reads as `mpeg1video 240×120`, duration 18.89 s. A
wrong boundary would corrupt the stream.

---

## 5. Still unidentified — and what has been eliminated

| blob | size | measurements |
|---|---|---|
| `0x0b73fb3`–`0x140ed84` (R3) | 9 022 929 B | entropy 7.08; **0 x `00 00 01 B3`**; 214 x `00 00 01 00`, 133 x `ffd8ff`, 1 484 x `fffb`, 319 x `8000` |
| `0x0338fe1`–`0xb63106` (R4) | 8 560 933 B | entropy 7.34; 2 x `00 00 01 B3` at one identical spacing (coincidence), 1 x picture code, 29 x `fffb`, 735 x `8000` |

### Eliminated for R3 by the `00 00 01 B3` experiment

Command: `tools/scan_headers.py … derive --region 0x0b73fb3:0x140ed84 --magic 000001b3`,
with R1 as a positive control:

| region | `000001b3` anchors | parity-model score |
|---|---|---|
| R1 (known MPEG-1 container) | 271 | **100.0 %** (C = 8, the 9s all have odd sizes) |
| **R3 (unknown)** | **0** | not applicable — no sequence header exists |
| R4 (unknown) | 2 | one spacing only, i.e. coincidence |

So **R3 is not an MPEG-1 video container**: there is no sequence header anywhere in 9 MB. R4 has two,
at a single spacing, which is the signature of accidental byte matches rather than framing.

Two further rejections for R3, both with the same parser:

- media container with JPEG payloads: 134 anchors, **0 resolved**
- the general trailer rule: 1 479 candidate starts, **0 resolved**

A second attempt, using the trailer *type word* as the anchor (`--magic 00001000`, which `derive` now
supports via `--max-after`), reached only 33 % and is not evidence.

### Stride probe (M12) — R3 and R4 do **not** share a block stride

`tools/scan_headers.py stride` measures byte agreement at lag S over three 64 KB windows spread
through a region, then builds an **empirical null by shuffling the same bytes** (the histogram
survives, only order dies — exactly the property under test). The null is not optional: a negative
control on the zlib asset region (`0x20000`–`0x80000`, no block structure) already shows 2.1x-floor
spikes, so "2x over median" alone proves nothing.

Same lag set, both regions:

| lag | R3 agreement (z vs null) | R4 agreement (z vs null) |
|---|---|---|
| **40** | **4.067 % (z +43.7)** — R3's strongest | 0.668 % — **below R4's own median**, i.e. absent |
| 80 | 3.458 % (+25.7) | 0.668 % — below median |
| 16 | 2.975 % (+24.4) | 0.797 % |
| 24 | 2.816 % (+23.3) | 0.818 % |
| 144 | 2.102 % (+12.5) | 0.874 % |
| **72** | 1.794 % (+10.1) | **1.084 % (z +29.5)** — R4's second structure |
| **260** | 1.429 % (**z +4.4 — noise**) | **1.182 % (z +34.9)** — R4's strongest |
| 520 | 2.379 % (+15.0) | 1.002 % (+28.5) |
| 780 | 1.155 % (**z +0.7 — none**) | 0.846 % (+15.4) |

Medians: R3 2.379 %, R4 0.846 % (R3's byte distribution is skewed, hence the higher floor).

**Conclusion: no shared stride.** R3 is periodic at **40** (and 80 = 2x40); R4 at **260** (520 = 2x260)
and **72** (144 = 2x72). Each region's characteristic lag is near-absent in the other — R3 at 260 is
z +4.4, indistinguishable from noise, and R4 at 40 sits *below* its own median agreement.
`gcd(40, 260) = 20`, but lag 20 is not a peak in either region, so the common divisor is arithmetic,
not structure.

Two honest limits:

1. **Periodic is not the same as block stride.** A repeated inner field (a counter, a pointer, a
   per-record checksum) produces the same signature. The probe establishes a period, not a framing.
2. **The null is a shuffle null**, so any real local structure scores z > 0. The evidence is the
   *ranking within a region* and the *absence of the other region's lag*, not the z value alone.

What a 40-byte period means for R3 is still open. A 40-byte record with one changing field would
produce agreement ≈ (constant bytes)/40 + 1/256; the measured 4.07 % against a 1.08 % null implies
roughly **one to two repeating bytes per 40**, which is the weakest possible structure — consistent
with a per-record field that mostly changes (an offset, an index, a checksum).

### Phase sweep (M13) — the 40-byte period is diffuse, **not** a record field

`tools/scan_headers.py phase --region … --stride 40` measures, for each byte position
inside the period, how often that position repeats in the next record. Each phase is scored
against **its own** marginal distribution (`sum p^2` of that phase's values), so a merely skewed
position cannot pass — which matters, because the top-scoring positions are all odd and R3's odd
bytes are the high half of 16-bit samples.

R3, stride 40 (all 40 phases shown in the tool run; top 8 here):

| phase | agreement | vs own null | top byte | distinct values |
|---|---|---|---|---|
| 9 | 10.66 % | 9.39x | 0x00 (4.0 %) | 249 |
| 25 | 11.69 % | 8.95x | 0x00 (4.8 %) | 237 |
| 33 | 7.51 % | 8.10x | 0x00 (4.0 %) | 254 |
| 1 | 8.02 % | 7.59x | 0x00 (4.2 %) | 249 |
| 16 | 6.19 % | 6.82x | 0x00 (3.5 %) | 253 |
| 32 | 5.17 % | 5.06x | 0x00 (5.0 %) | 256 |
| 8 | 4.86 % | 4.80x | 0x00 (4.3 %) | 255 |
| 0 | 4.78 % | 4.55x | 0x00 (4.0 %) | 252 |

**Every one of the 40 phases is above its own null** (mean 3.54x, none at or below), and the
elevation is *uniform*: the lag-40 agreement of 4.07 % is exactly the average of the phases.

**So there is no repeating field.** A record structure with a header byte would put one or two
phases near 100 %; the maximum here is 11.7 %, with 237–256 distinct values at even the best phase, and
the modal byte (`0x00`, 4–6 %) is only the region's baseline skew, not a marker.

R4 at its 260 period behaves the same way, and weaker: mean ratio 2.06x, **38 of 260 phases at or
below their own null**, best phase 2.79 % with 237 distinct values.

### Consequence: M12's "R3 period 40" is demoted

A period with no position standing out is not evidence of records. The honest reading is that lag 40
is a **diffuse autocorrelation peak** — most likely from redundancy in the data itself (near-duplicate
blocks, or 16-bit samples whose high bytes are skewed) — and not a block stride. Nothing about R3's
container is established by it.

### Match-run length (M14) — the runs are **fills**, so the demotion is confirmed

The test that separates "approximate record repetition" from "byte-level artifact" is run length:
whole-record repetition produces multi-byte runs; skew produces isolated single matches. Added as
`scan_headers.py runs --stride N` (run histogram against a shuffle null, plus the distinct-value count
over each run's span, which is what tells a repeated record from a constant fill).

R3, lag 40, three 64 KB windows:

| run length | observed | shuffled null | ratio |
|---|---|---|---|
| 1 | 5 914 | 2 129.0 | 2.8x |
| 2 | 112 | 23.2 | 4.8x |
| 3 | 6 | ~0 | — |
| 4 | 15 | ~0 | — |
| 5 | 2 | ~0 | — |
| 6+ | 36 | ~0 | — |

59 runs of length ≥ 3, and the null produces essentially none — so there *is* multi-byte repetition.
But the span inspection says what it is:

| longest runs | offset | content |
|---|---|---|
| 482 B | `0x0b80582` | **all zeros** |
| 466 B | `0x0b7925b` | **all zeros** |
| 105 B | `0x0b740bc` | **all zeros** |
| 51 B | `0x0fc04b9` | **all zeros** |
| 42 B | `0x0fbb7fa` | **all zeros** |
| 41 B | `0x140437c` | `fff9fff9fff9fff9…` — a repeated 16-bit sample, not records |

Accounting over the analysed 192 KB: **10 of the 59 runs are constant fills and they carry 68 % of all
multi-byte matched bytes**; 13 more are the repeated-2-byte-sample shape; the remaining 49 non-fill runs
total only **582 bytes**, a few bytes each.

**A constant stretch matches at every lag**, so zero-fill inflates the lag-40 rate — and a shuffle null
cannot produce a 482-byte zero run, which is precisely why the null test alone looked like structure.

**Conclusion: R3 has no record structure at stride 40.** The period is fully explained by fills plus
per-byte skew. M12's "period 40" is retracted, not merely demoted.

### The general lesson, third instance

After "is it above the null?", the next question is **"what else would produce this?"**. A null tells
you the measurement is not chance; it does not tell you the measurement is what you named it. Fill
stretches, per-phase skew and a hardcoded `0x78` header all passed a statistical test and all meant
something other than the intended reading.

### What is left for R3

The head of the region is `… 64 fe 27 fe 74 ff 21 ff a0 ff e3 ff fe 00 05 00 05 06 b6 03 c8 01 a0 00`
— a run of `0xFF` high bytes, the shape of **16-bit samples that are mostly negative**, i.e. audio.
1 484 `fffb` frame syncs are too sparse (one per 6 KB) to be a dense MP3 stream, so that is not yet a
claim either. **Hypothesis, not finding:** R3 is audio (VADPCM/PCM) or a texture archive; R4 likewise.
Both regions were entered mid-block by the coverage pass, so the first bytes are cut points, not
headers — which is why their apparent "headers" disagree byte-for-byte with the verified ones.

## 5b. The scene-load path, and why no descriptor points into R3 (M15)

### Record 0 is the stage-2 code image

The boot loader `FUN_80000598` ends by calling `func_0x8004d344` — an address **outside** the boot bank
(`0x80000480`–`0x800120C0`). That was never a stray reference: boot table record 0 is

| | |
|---|---|
| cart offset | `0x14420` |
| stored | 385 519 B |
| decompressed to | `0x80018a80` … `0x80136d90` (**1 172 240 B**) |
| `0x8004d344` | inside it, at `+0x348c4`, where the word is `27bdffe0` = `addiu sp,sp,-0x20` |

So record 0 **is** the stage-2 image, decompressed into RAM and called. It is `assets/unpacked/00000_0014420_1172240.bin`,
and it is code: **1 240 prologues, 2 237 `jr ra`, 6 457 `jal`**, dense from `+0x8000` to `+0xA0000`, empty at
the tail. Its base is `0x80018a80`.

Wrapped at that base (`tools/wrap_mips_elf.py --base 0x80018a80`), the entry decompiles to a thread spawn:

```c
void FUN_8004d344(void) {
  func_0x80006d60(&DAT_8010b700, 7, FUN_8004d190, 0, &DAT_800c36a0, 0);   /* create, id 7 */
  func_0x8000db90(&DAT_8010b700);                                        /* start */
}
```

Note `func_0x80006d60` is at `0x80006d60` — back **inside the boot bank**. Stage 2 calls the boot bank and
the boot bank calls stage 2, so the two images are one program split across two load units.

### The stage-2 file registry (M16)

Decompiling the thread entry `FUN_8004d190` gave video/RAM setup, not file I/O — so the open was located
by scanning stage 2 for `jal` encodings of the known loader chain instead. Result: stage 2 has **two**
complete inflate chains (`0x80032824`, `0x8004CC1C`), and five calls to the descriptor-table producer
`FUN_80001180`. The file-open is:

```c
/* the open: inflate one descriptor into its destination */
undefined4 FUN_8004cbf4(undefined4 *desc) {
  if (desc[1] == 0) return 0;
  func_0x80004550(stack, DAT_8010b6fc);                    /* inflate init, window buffer */
  func_0x800045dc(stack, desc[0], desc[2], desc[1]);       /* src, dst, compressed length */
  func_0x80004594(stack, 2);                               /* free */
}

/* the call site: slot -> descriptor -> inflate -> per-slot handler */
void FUN_8004cc5c(int slot) {
  uVar1 = func_0x80001180((&DAT_8010b2e0)[slot * 8]);      /* boot table index for this slot */
  FUN_8004cbf4(uVar1);
  (**(code **)(&DAT_8010b2e4 + slot * 8))();               /* handler for this slot */
}
```

So the file system is a **32-byte-per-entry registry at `0x8010b2e0`**: word 0 = boot-descriptor index,
word 1 = post-load handler, six more per entry. `FUN_8004cc5c(slot)` is the game's open.

`DAT_8010b6fc = 0x80189a00` is the inflate window, and it is set by the thread entry `FUN_8004d190` —
which ties the two functions together and confirms the entry is the stage-2 init.

### The file-open call, and why no static descriptor can be found (M18)

`FUN_8004d190` itself does no file I/O. It sets video mode and RAM layout (Expansion Pak test at
`< 0x400001`; 320×240 vs 640×480; framebuffer/buffer pointers), then calls four functions, two of which
spawn threads:

| call | what it is |
|---|---|
| `FUN_8008af6c` | one line: `DAT_8012bd84 = DAT_8010b6f0` (framebuffer pointer) |
| `FUN_80088910` | `osCreateThread(&DAT_8012bb00, 9, FUN_80088668, 0, &DAT_800c4ea0, 0x3c)` + `osStartThread` |
| `FUN_8006cb94` | controller/eeprom setup, then `osCreateThread(&DAT_80112a40, 1, FUN_8006c0d4, …)` + start |
| `func_0x80000518` | a boot-bank function |

`func_0x80006d60` = `osCreateThread(thread, id, entry, arg, stack, pri)` and `func_0x8000db90` =
`osStartThread`; `func_0x80006d30` / `func_0x8000c9e0` / `func_0x8000cb60` = `osCreateMesgQueue` /
`osRecvMesg` / `osSendMesg`. Thread 1 (`FUN_8006c0d4`) then spawns thread 2 (`FUN_800282e8`).

**The open is called exactly once in the whole stage-2 image**, at `0x800273e4`, inside `FUN_800271d4`:

```c
if (DAT_801344c0 == 1) DAT_801344c0 = 2;      /* earlier in the same function */
...
if (DAT_801344c0 == 2) {                       /* the state machine fires */
  FUN_8004cc5c(0);                             /* <-- open, ALWAYS slot 0 */
  FUN_80026a88();
  DAT_800c4f60 = 1;
  DAT_801344c0 = 0;                            /* reset */
  DAT_800c56f4 = DAT_8010b6e4 == 0;
}
```

`FUN_800271d4` is called from `0x800264e0` and `0x800264f8`, both inside `FUN_8002616c`, in the same
`0x8002xxxx` cluster as thread 2's entry. Proven edges: `FUN_8004d190` → `FUN_8006cb94` →
thread 1 → thread 2 → `0x8002xxxx` cluster → `FUN_8002616c` → `FUN_800271d4` → `FUN_8004cc5c(0)`.
The thread boundaries in the middle cannot be followed by `jal` scanning (a thread entry has no caller),
so that part of the chain is inference from adjacency, not proof.

### The registry is **read-only** in every analysed image (M19) — retracting "mutable slot"

Entry layout, now confirmed by a cross-reference scanner rather than by inference:

```c
struct OverlayEntry {   /* 8 bytes, table at 0x8010b2e0 */
  u8  descriptor;       /* +0 */
  u8  padding[3];       /* +1..3, always zero */
  u32 entry;            /* +4 */
};
```

`tools/xref_registry.py` does a bounded abstract interpretation (MIPS has no absolute store, so it tracks
constants per register through `lui`/`addiu`/`ori`/`addu`, invalidates on writes and on caller-saved
registers across `jal`, and follows pointers **stored into globals and reloaded** — the "pointer held in
another variable" case). Scanned: boot bank (69 KB), stage-2 (1.17 MB), and all six overlay blobs
(~210 KB), window `0x8010b2e0`..`0x8010b328`.

| image | references | **stores** |
|---|---|---|
| boot bank | 0 | **0** |
| stage-2 | 9 | **0** |
| all six overlays | 0 | **0** |

The 9 references are three reader functions (`0x8004cc5c`, `0x8004cca8`, `0x8004cd08`), each of which
constructs the base, reads `+0` with `lbu` (descriptor) and `+4` with `lw` (entry) — which independently
confirms the layout above.

**So the registry is never written, and my previous conclusion was wrong.** I claimed slot 0's index byte
was mutable and rewritten by the scene loader to select which record to open. There is no such write
anywhere in the analysed code. The correct reading is the opposite:

- `FUN_8004cc5c(0)` always opens **descriptor index 2** — cart `0x72610`, 17 022 B → `0x8017b410`,
  entry `0x80180cd0`. It is a **fixed overlay load**, not a dynamic file selector.
- The nine slots are a static resident-overlay table, indexed by constants at each call site.

Coverage limit worth stating: this rules out a write in code we have mapped. Code in regions we have not
mapped (further overlays, or RAM images loaded by paths not yet followed) could still write it.

### No stream walker exists in mapped code (M20) — and that is the answer to "its loop bound"

`tools/find_stream_walker.py` looks for a routine that walks the cartridge window: it classifies a
register as a cart pointer only when the value is **constructed** (`lui`/`addiu`/`ori` into
`0xB0000000`–`0xB3FFFFFF`), then reports every load through such a register plus the innermost enclosing
backward branch and the constant that branch compares against.

| image | result |
|---|---|
| stage-2 (1.17 MB) | **no register ever holds a constructed KSEG1 cart pointer** |
| boot bank (69 KB) | same |

So there is **no loop bound to report**, because there is no loop. Both known consumers read the cart
pointer out of memory and pass it once:

- boot loader `FUN_80000598`: `FUN_8000C870(0, desc[0] & 0x0FFFFFFF, 0x8015B030, desc[1])`
- registry reader `FUN_8004cbf4`: `inflate(state, desc[0], desc[2], desc[1])`

In both, `desc[0]` is loaded from the descriptor record (a `0xB0…` KSEG1 pointer) and used exactly once.
No increment, no comparison, no iteration.

**Limitation, stated because it is the honest edge of this result:** an increment applied to a pointer
that was *loaded* rather than constructed is invisible to this analysis — the value is not a constant, so
no register is classified. Ruling that out needs real data-flow (or a dynamic trace), not this scan.

### Static load-path table, cross-checked against the 4 761-member manifest

This is a **static reconstruction**, not an execution trace. Rows are known call paths evaluated with the
constants the code would use; "descriptor" is the boot-table index.

| iter | path | cart pointer | desc | compressed | destination |
|---|---|---|---|---|---|
| 0 | boot `FUN_80000598` | `0xb0014420` | 1 | 385 519 | `0x80018a80` |
| 1 | registry slot 0 | `0xb0072610` | 2 | 17 022 | `0x8017b410` |
| 2 | registry slot 1 | `0xb007688e` | 3 | 9 087 | `0x8015b030` |
| 3 | registry slot 2 | `0xb0078c0e` | 4 | 9 067 | `0x8017b410` |
| 4 | registry slot 3 | `0xb007e132` | 10 | 6 880 | `0x8017b410` |
| 5 | registry slot 4 | `0xb007af7a` | 5 | 5 592 | `0x8017b410` |
| 6 | registry slot 5 | `0xb007e132` | 8 | 0 | `0x8017b410` |
| 7 | registry slot 6 | `0xb007c552` | 7 | 7 136 | `0x8016e880` |
| 8 | registry slot 7 | `0xb007c552` | 6 | 0 | `0x8015b030` |
| 9 | registry slot 8 | `0xb007e132` | 9 | 0 | `0x8017b410` |

Seven distinct cart offsets (`0x14420`, `0x72610`, `0x7688e`, `0x78c0e`, `0x7af7a`, `0x7c552`,
`0x7e132`), and **every one is a zlib member in the manifest**. That is static agreement between the
code's own constants and the file inventory — not proof of runtime behaviour, and it does not by itself
show that the game ever walks the other 4 754 members.

### Partial CPU harness, and an executed load trace (M21)

`tools/mips_harness.py` executes the game's own instructions. Scope, stated so it cannot be mistaken for
a console emulator: integer/doubleword subset of MIPS III (32-bit view of 64-bit ops), no threads, no
interrupts, no video. What it does provide:

- RAM: 4 MB at `0x80000000`, holding the boot image (ROM `0x1000`–`0x14600`, i.e. **code plus the
  descriptor table at ROM `0x12cd0`**) at `0x80000480` and stage-2 at `0x80018a80`.
- Cartridge mapped at KSEG1 `0xB0000000`, so a `0xB0…` descriptor pointer resolves to real ROM bytes.
  Writes to ROM fault rather than silently succeed.
- The loader primitives are **host hooks**: `inflate` is Python's `zlib` reading emulated memory;
  `osCreateThread`/`osStartThread`/message-queue calls are stubs that are logged. Every run prints what
  was executed and what was stubbed.

**A bug worth recording**: the first run mapped only ROM `0x1000`–`0x12140`. The descriptor table lives at
ROM `0x12cd0`, past the code end, so every `desc[1]` read as zero and all nine slots took the early exit.
A clipped image produces a *plausible* result — nine "no inflate call" rows — rather than an error.

#### Executed trace: `FUN_8004cbf4(desc)` for each registry slot

| slot | desc idx | cart pointer | compressed | destination | decompressed | manifest |
|---|---|---|---|---|---|---|
| 0 | 2 | `0xb0072610` | 17 022 | `0x8017b410` | **49 312** | match |
| 1 | 3 | `0xb007688e` | 9 087 | `0x8015b030` | **27 840** | match |
| 2 | 4 | `0xb0078c0e` | 9 067 | `0x8017b410` | **58 848** | match |
| 3 | 10 | `0xb007e132` | 6 880 | `0x8017b410` | **13 568** | match |
| 4 | 5 | `0xb007af7a` | 5 592 | `0x8017b410` | **20 992** | match |
| 5 | 8 | — | 0 | — | — | early exit |
| 6 | 7 | `0xb007c552` | 7 136 | `0x8016e880` | **15 104** | match |
| 7 | 6 | — | 0 | — | — | early exit |
| 8 | 9 | — | 0 | — | — | early exit |

These rows are produced by *executing* the loader: the pointers, sizes and destinations come out of the
game's address arithmetic and descriptor field loads, not from reading the table. **All six non-zero
slots decompress to exactly the size in the 4 761-member manifest**, and the three zero-size slots reach
the early exit after 13 instructions — which confirms "stored == 0 means no load" by execution rather
than inference.

#### Run 1: `FUN_8004d190` executes and sets its globals

62 instructions with its four callees stubbed: `0x8010b6fc = 0x80189a00` (the inflate window that
`FUN_8004cbf4` later consumes), `0x801137f0 = 0x140`, `0x801137f4 = 0xf0` → 320×240, i.e. the
no-Expansion-Pak branch.

#### Run 2: the last call in `FUN_8004d190` is an idle loop, **not** a file open

`func_0x80000518` decodes to two instructions:

```
0x80000518  1000ffff   b .                  ; branch to itself
0x8000051c  64840001   daddiu a0, a0, 1     ; counter in the delay slot
```

Executed: **400 000 instructions, 2 distinct PCs, zero calls.** It never returns and opens nothing. So
`FUN_8004d190` ends by handing control to a permanent spin — the file open is reached from the thread
path (`FUN_800271d4` → `FUN_8004cc5c(0)`), as established in M18, and not from this function.

### Scheduler increment (M22): the thread graph runs, open(0) does **not** fire

`tools/run_scheduler.py` adds real thread and message-queue semantics on top of the harness:
`osCreateThread`/`osStartThread` build a thread table, `osCreateMesgQueue`/`osRecvMesg`/`osSendMesg` operate
on emulated memory with OS_MESG_BLOCK honored, and runnable threads are scheduled round-robin. Hardware
registers read as zero, so a thread polling one spins and the run reports it.

Starting from the boot chain entry `FUN_8004d344`, execution produces the real thread graph:

```
create thread 0  0x8004d344        (root: the boot chain)
create thread 7  0x8004d190        (stage-2 init)
create thread 9  0x80088668        (from FUN_80088910)
create thread 1  0x8006c0d4        (from FUN_8006cb94)
thread 9 blocks on mesg queue 0x8012bd30     <- real OS_MESG_BLOCK behaviour
```

**After adding COP1 (M23):** FP register file held as Python floats with explicit float32 rounding for
S-format, `mfc1`/`mtc1`/`cfc1`/`ctc1`, `bc1f`/`bc1t`, S/D arithmetic (`add`/`sub`/`mul`/`div`/`sqrt`/
`abs`/`mov`/`neg`, round/trunc/ceil/floor, `cvt.s/d/w/l`), `c.eq/c.lt/c.le`, `lwc1`/`ldc1`/`swc1`/`sdc1`,
correct `lwl`/`lwr`/`swl`/`swr`, `cache` as a no-op, the branch-likely family `0x14`–`0x17` **with delay-slot
nullification when not taken**, and `mfc0`/`mtc0`/`eret`. `ldl`/`ldr`/`sdl`/`sdr` remain **named faults** —
approximating a 64-bit unaligned access as an aligned one corrupts memory silently.

Result: **thread 7 gets past `0x8000ccf0` and runs to completion.**

| thread | state | detail |
|---|---|---|
| 0 (root) | done | boot chain returned |
| **7** | **done** | 3 slices, returned normally — the FPU blocker is gone |
| 9 | blocked | waiting on queue `0x8012bd30` (count 0, 1 waiter) |
| 1 | blocked | waiting on queue `0x8012bcf8` (count 0, 1 waiter) |

60 326 instructions; the run ends because **every thread is either done or blocked**, and nothing ever
posts to those two queues. `open(0)` still does not fire.

So the blocker has moved from *instructions* to *event sources*. The queues are posted by hardware
interrupts — VI retrace, PI/RSP completion, SI controller — all of which are stubs that return 0 and post
nothing. The next increment is therefore an event source: implement `osViSetEvent` (record the queue and
message), then post a retrace message once per simulated frame and let the driver thread wake.

Two opcodes were **mis-mapped during this increment and then removed rather than approximated**: `0x2D` is
`SDR`, not `daddu` (`daddu` is a SPECIAL function), and `0x3C`/`0x3D` are `SCD`/`SDC1`. An unaligned
dword store emulated as an aligned one corrupts memory silently and makes a run look successful — the
harness now raises a *named* fault instead (`NAMED_OPS`), so a stopped run says which feature is missing.

### Experiment A: `0x14420` is a plain concatenation boundary, not a structure

| observation | value |
|---|---|
| 48 bytes before `0x14420` | `…30 31 32 33 34 35 36 37 38 39 41 42 43 44 45 46…` = the ASCII table `0123456789ABCDEF`, then zeros |
| first 2 bytes of the member | `68 de` — valid zlib header, `%31 = 0` |
| member end | stored 385 519 → ends at ROM `0x7260f`; the next member begins immediately after |
| region `0x133b0`–`0x14420` (4 208 B) | 23 vram-pointer words, 48 % non-zero, mostly zeros — mixed boot data, no length table |

**Answer to A: isolated in the structural sense, not in the layout sense.** There is no per-member
metadata, directory, or size table around the member: it starts with a self-describing zlib header, ends
where zlib's own end marker says, and the next member follows. The container is a bare concatenation of
self-delimiting streams — which is why a sequential walker reproduces it (M9) and why no index is needed
(M15–M19).

### Experiments B and C: scoped, not done

- **B (pointer provenance)** — `tools/xref_registry.py` currently propagates constructed constants and
  follows pointers stored into globals and reloaded. Extending it through stack slots, arguments and
  return values is the natural next step, but note that M21/M22 make part of it unnecessary: for code the
  harness can execute, *running* it beats propagating types.
- **C (init sequence / resource structures)** — this is now directly observable rather than inferred: run
  `FUN_8004d344` under the scheduler and log every global the init threads write in the `0x8010Bxxx`
  range. That is the right way to find the resource structures, and it needs FPU support first.

### Frame tick built; the hypothesis it tested is falsified (M24)

Two FPU-model corrections first, both prompted by review:

1. **FPRs are now 32 x 64-bit raw bit patterns, not host floats.** An S-format value lives in the low 32
   bits and the high 32 bits are preserved; `LWC1`/`SWC1` touch only the low half, `LDC1`/`SDC1` the whole
   register, `MFC1`/`MTC1` move the low half. Storing a Python float per register conflated the two views.
2. Fixing the storage exposed a second bug: the arithmetic block still read `self.f[fs]` as a float, so
   `add.s` would have operated on raw bit patterns. Both are corrected; `cvt.s` now rounds on store.

The two stop points from M22 decode to **`CFC1`** (`0x8000ccf0`, `4442f800`) and **`BNEL`**
(`0x800887b8`, `54600001`) — not SDC1, and not a broad FPU suite. That matches the "implement the minimum
encountered" advice: the extra work was one FP control-register read and one branch-likely.

#### `osSetEventMesg` identified, and a frame tick built

Instrumenting every stub showed exactly one call receiving a queue address:

```
stub 0x8000cc90(event=4,  mq=0x80139f10, msg=0x1)     /* AI          */
stub 0x8000cc90(event=9,  mq=0x80139f10, msg=0x2)     /* SP_BREAK    */
stub 0x8000cc90(event=6,  mq=0x80139f10, msg=0xa)     /* PI          */
stub 0x8000cc90(event=14, mq=0x80139f10, msg=0x8)     /* RDB_PREPARE */
```

So `0x8000cc90` is `osSetEventMesg`, and `0x80139f10` is the hardware-interrupt inbox. The scheduler now
records those registrations and, whenever **every** thread is blocked, delivers the next one as a frame
tick. Posting was also unified, because the first version incremented a queue count without waking a
parked waiter — a silent bug that made the tick look inert.

#### Result: the tick runs, nothing consumes it

| queue | count after 20 ticks | waiters | consumer |
|---|---|---|---|
| `0x80139f10` (event inbox) | **20** | **0** | **none — no thread ever waits here** |
| `0x8012bcf8` | 0 | 1 (thread 1) | app-side |
| `0x8012bd30` | 0 | 1 (thread 9) | app-side |

`open(0)` still does not fire. The hypothesis is falsified rather than merely unproven: delivering 20
hardware events to the registered inbox wakes nobody, because **the thread that would drain that inbox is
not among the threads the boot chain creates** (0 root, 7, 1, 9). Thread 7 registers the events and then
returns; threads 1 and 9 park on two app queues that nothing posts to.

**Next, concretely:** scan the mapped images for the constant `0x80139f10` to find the drainer, and for
`0x8012bd30` to find its poster. Both are single-address searches, and whichever thread appears owns the
piece that is missing from the graph we can start.

### Constant scan: who owns the two queues (M25)

Scanning every mapped image (boot bank, stage-2, six overlays) for both addresses:

| constant | referenced by | reading |
|---|---|---|
| `0x80139f10` | **thread 1**'s entry `FUN_8006c0d4` (13 construct/arg sites) and `FUN_8006cb94` (5 arg sites = the four `osSetEventMesg` registrations) | the hardware-event **inbox**, drained by **thread 1** |
| `0x8012bd30` | **thread 9**'s entry `FUN_80088668` (create + receive) plus helpers `FUN_800885c0`, `FUN_80088764` | owned by **thread 9**; **no mapped code ever sends to it** |

This explains the M24 result precisely. The ticks arrived at the *right* queue — thread 1 is its consumer —
but by the time they were delivered thread 1 was already parked on `0x8012bcf8`, a queue that **thread 9**
fills, and thread 9 was parked on `0x8012bd30`, for which **every reference in mapped code is a
construction or a receive, never a send**. The missing edge is a *producer* for `0x8012bd30`: the game
expects one from a hardware handler or from an overlay this run never loads.

So the dependency chain the game needs is

```
(something) --> 0x8012bd30 --> thread 9 --> 0x8012bcf8 --> thread 1 --> drains 0x80139f10
```

and the first link is the one that does not exist in the code we can execute.

### Commit A / B / C status against the plan

| item | status |
|---|---|
| **A — COP1 foundation**: real FPR representation, observed loads/stores, arithmetic + comparisons, named faults for the rest | **done** — 32 × 64-bit raw, S in low half; named faults cover `ldl`/`ldr`/`sdl`/`sdr`/`lld`/`scd` |
| **B — thread execution**: re-run boot, compare thread creation, record first new boundaries | **done** — thread graph stable (0/7/1/9), thread 7 now *completes* (previously faulted at `0x8000ccf0`), threads 1/9 block on app queues |
| **C — resource access**: instrument cartridge reads, record decompression calls, compare with `manifest.json` | **done in M21** — six executed loads, every decompressed size matches the manifest |

### Execution checkpoints (M26)

`run_scheduler.py` now writes `checkpoint/` at the end of every run:

```
checkpoint/ cpu_registers.json  fpu_registers.json  thread_table.json
            message_queues.json  memory_regions.json  execution_trace.json
            unresolved_instructions.json  run_digest.json
```

`memory_regions.json` carries sha256 over the emulated RAM, the cartridge and the stage-2 image, so a run
is pinned to exact inputs. `run_digest.json` hashes every other file, which makes reproducibility a single
comparison. Two independent runs of the boot sequence produce the **same digest**
(`80436211b50d1229a2a1ef001e1d8ac2f0ec4d28ea404881aa36786abebde223`), so the claim is now
"same cartridge, same images, same initial state → same thread and memory behaviour", and it is checked
rather than asserted.

### Send-site census and event-delivery trace (M27): the producer is *indirect by design*

A constant scan for `0x8012bd30` could never find the producer, and the census shows why. Every
`osSendMesg` (`0x8000cb60`) call site in the mapped images — **51 of them** — classified by how the queue
argument is formed:

| how `a0` is formed | count | consequence |
|---|---|---|
| `loaded` from memory (`lw a0, off(reg)`) | 17 | queue pointer comes from a **table**, invisible to a constant scan |
| register + offset (`addiu a0, reg, imm`) | 21 | same, via a computed base |
| copied from another register (`addu a0, r, zero`) | 11 | same, via data flow |
| unknown | 1 | — |

Not one send site passes a literal queue address. So the phrasing must be **"no producer identified in
mapped code and execution coverage so far"**, not "the producer must be hardware or an unloaded overlay"
— an indirect dispatcher in already-mapped code is exactly the shape this census describes.

Where the hardware layer lives:

| image | `lui 0xA460` (PI) | `lui 0xA440` (VI) |
|---|---|---|
| boot bank | **82** | **19** |
| stage-2 | 1 | 1 |
| all six overlays | 0 | 0 |

The PI/VI handling is libultra in the boot bank, and the libultra send sites whose `a0` is *loaded*
(`0x8000c2b0`, `0x8000c2dc`, `0x8000c41c`, `0x8000c444`, `0x8000c454`, `0x8000e050`, `0x8000e71c`) are the
indirect-dispatch candidates — consistent with `osSetEventMesg` writing an `(mq, msg)` table that the
dispatcher later loads. **But the only queue registered in that table is `0x80139f10`**, so even the
indirect path posts there and not to `0x8012bd30`.

#### The trace, before the deadlock

Two message operations occur in the entire run, both receives on empty queues:

```
0x8000c9e0 recv q=0x8012bd30 msg=- before=0 flag=1 thread 9   <- blocking
0x8000c9e0 recv q=0x8012bcf8 msg=- before=0 flag=1 thread 1   <- blocking
```

**Zero sends occur before the system deadlocks**, so thread 1 never reaches the point where it drains
`0x80139f10`, and the 20 ticks it is sent land in a queue whose consumer is parked upstream.

#### Why the harness cannot observe the interrupt path yet

`mfc0` returns 0, so **CP0 Status reads as zero — interrupts are disabled in the emulated CPU**. No
interrupt can be recognised, so no dispatcher can run, no matter what is posted. That is a harness
limitation, not a property of the game, and it is the thing to fix next: model Status/Cause (at minimum
the interrupt-enable bit, the mask bits and the pending bits), raise an interrupt when a modelled source
asserts, and route it through the game's own exception vector at `0x80000000`.

### CP0 validated, then two mapping corrections, then the real interrupt path (M28/M29)

**Corrections accepted, both of which invalidate part of the M28 write-up:**

1. **`0x80000180` is RDRAM (physical `0x180`), not cartridge ROM.** My "ROM `0xd00`" was this harness's
   image-projection offset, not a hardware translation. Equally, `0xBFC00380` is **PIF boot ROM**
   (physical `0x1FC00380`, offset `0x380`) — a different component from the cartridge's IPL3.
2. **`Cause = 0x2000` is `CAUSE_IP6` (external interrupt level 6), not the N64 VI interrupt.** The RCP
   interrupt is **`CAUSE_IP3 = 0x400`**. M28's trace showed only that the CP0 model accepted a pending
   interrupt on whatever bit was asserted; it did not show a VI interrupt reaching the CPU.

**D1 — the VI path is now the real one.** `HwMemory` models `MI_INTR` (`0xA4300008`, per-device pending
bits) and `MI_INTR_MASK` (`0xA430000C`). A device sets its MI bit; the MI aggregate asserts `IP3` only when
`pending & mask`. Verified in a live run:

```
irq event: ('irq', pending=0x08, mask=0x08, rcp=0x400)
exception at 0x80088668   EPC 0x80088668   Cause 0x400 (IP3)   vector 0x80000180
```

The CPU never sees `0x08` or `0x2000`; it sees `IP3`, which is the layering the manual describes.

**D2 — the vector installation is real, and I was wrong about IPL3.** Write watchpoints on all four vector
addresses fire on the game's own init, from **both** entry points tried:

```
0x80000000 UT_VEC   <- 0x3c1a8000
0x80000080 XUT_VEC  <- 0x3c1a8000
0x80000100 ECC_VEC  <- 0x3c1a8000
0x80000180 E_VEC    <- 0x3c1a8000
```

`E_VEC` afterwards reads `3c1a8000 275a06d0 03400008 00000000` = `lui k0,0x8000 ; addiu k0,k0,0x6d0 ;
jr k0 ; nop`. **The general exception handler starts at `0x800006d0`.** So an empty vector at cold start
is expected — exactly the `osInitialize` behaviour — and there is no need to hunt for a handler in IPL3.

**D3 — dispatch works up to the handler, then stops on missing state.** With the MI path and IP3 enabled,
the interrupt is taken and execution reaches `0x800006d0`. It runs for about `0xa0` bytes and then faults:

```
thread 9 at 0x80000770: ff490020 = sd t1, 0x20(k0)      with k0 = 0
                        -> unmapped access at 0x00000020
thread 7 faulted at pc 0x0 (k0-derived base is zero)
```

So the chain *device → MI → IP3 → CP0 → `0x80000180` → preamble → `0x800006d0`* is demonstrated end to end,
and the handler's own first phase is what remains unemulated: `k0` is zero where the code expects a base
(the preamble sets it, so something between `0x6d0` and `0x770` clears or fails to save it — either state I
do not model, or an instruction whose effect I get wrong).

#### k0 trace: what "clears" it (M30)

A per-instruction trace from the vector to the fault (`TracingCpu` subclass, logging every write to `k0`):

| pc | instruction | k0 |
|---|---|---|
| `0x80000184` | `addiu k0, k0, 0x6d0` | `0x80000000` → `0x800006d0` |
| `0x800006d0` | `lui k0, 0x8001` | `0x800006d0` → `0x80010000` |
| `0x800006d4` | `addiu k0, k0, 0x5000` | `0x80010000` → **`0x80015000`** (handler work area) |
| `0x80000764` | `lui k0, 0x8001` | `0x80015000` → `0x80010000` |
| **`0x80000768`** | **`lw k0, 0x2950(k0)`** | `0x80010000` → **`0x0`** |

So nothing "clears" `k0` incorrectly: the handler **loads** it from **vram `0x80012950`** (ROM `0x134d0`),
and the word in the cartridge at that address is

```
0x80012950:  0x00000000 0x00000000 0x00000000 0x00000000 0x80017840 0x00000000
```

zero, with a plausible pointer in the neighbourhood. The handler therefore depends on a **runtime
initialised global** that no code path in this run writes — a watchpoint on `0x80012950` records **no
hits**. The subsequent `sd t1, 0x20(k0)` at `0x80000770` then faults at address `0x20`.

This is not an emulator bug and not a register-clobber bug: it is a **missing initialisation dependency**.
The handler's work area base `0x80015000` is written (with zero) during the run — one watchpoint hit — which
suggests the code that would populate `0x80012950` is the same init that owns that area.

Conclusion: `device → MI → IP3 → CP0 → vector → preamble → 0x800006d0` now runs entirely inside the
game's own instructions; what remains is the part of initialisation that fills `0x80012950`, which our entry
path never executes.

#### Who initialises `0x80012950` (M31)

Static scan of the table window `0x80012940`–`0x80012980` across all mapped images: 53 references, all in
the **boot bank**, and the writer is the boot loader itself:

| address | in function | kind |
|---|---|---|
| `0x80000cb0` / `0x80000cb8` | `FUN_80000598` | store to `0x80012948` / `0x80012954` |
| **`0x80000f70`** | **`FUN_80000598`** | **store to `0x80012950`** |
| `0x80000dd8` / `0x80000768` | `FUN_80000598` | reads of `0x80012950` |

So the global the exception handler dereferences is initialised by `FUN_80000598` — **the boot loader our
earlier runs skipped** by starting at `FUN_8004D344`. The rest of the window is libultra thread machinery
(`osCreateThread`, `osStartThread`, `osRecvMesg`, `osSendMesg` all read `0x80012948`–`0x80012960`).

Attempting to run that init did **not** yet succeed: starting at `FUN_80000598` ran 186 234 instructions
and then faulted at pc `0x0` (threads 0 and 7), never reaching the store. So the *writer is identified*,
but the path is not yet executed correctly — most likely in the DMA/inflate handoff that precedes the
table initialisation. That is the next thing to fix, and it must be fixed before any interrupt test is
meaningful.

#### MDU ops and scheduler-owned current thread (M32)

Two gaps closed:

1. **MDU instructions implemented** — `MFHI`/`MTHI`/`MFLO`/`MTLO`, `MULT`/`MULTU`, `DIV`/`DIVU` with
   proper signed division semantics and the divide-by-zero results the architecture defines. The handler
   previously stopped at `0x800007f8` on `SPECIAL 0x12` (MFLO); that fault is gone.
2. **The scheduler now maintains the guest's current-thread pointer itself.** Every thread records the
   `OSThread*` passed to `osCreateThread`, and each context switch writes it to `0x80012950` before
   restoring registers. Observed values across switches: `0x0` (boot thread), `0x0`, **`0x8010b700`**
   (thread 7's structure). `osCreateThread`'s 5th/6th arguments were also being read from the wrong stack
   slot (`0(sp)` instead of `16(sp)`); corrected.

This closes the semantic gap identified earlier: a host-side scheduler that starts interpreting at an entry
point while leaving `__osCurrentThread` stale lets threads *run* but leaves the guest's own view wrong —
which is exactly why the exception handler dereferenced a zero.

**Result of the honest re-run (no planted pointer):** the interrupt is taken
(`0x8004d190`, Cause `0x400`), the handler now gets **past** `0x80000770` — the `sd` that previously faulted
at address `0x20` — and fails later at `0x80000f2c` on an unmapped access at `0x00000004`, i.e. a
null-based pointer plus offset 4. So the current-thread identification is supported by the guest's own
behaviour, and the next null is identified with an address and an instruction rather than a symptom.

#### The null base at `0x80000f2c` is the guest's ready-list terminator (M33)

The faulting instruction and its register values, captured at the fault:

```
0x80000f14  lw t6, 0x4(t8)      t6 = node->priority        <- dispatch loop body
0x80000f18  slt ...             compare priorities
0x80000f1c  bne ...             exit if this node is not the best
0x80000f28  lw t8, 0x0(t8)      t8 = t8->next              <- advance
0x80000f2c  lw t6, 0x4(t8)      t8 = 0x0  -> fault at 0x4
```

State at the fault:

| global | value |
|---|---|
| `0x80012948` | `0x80012940` |
| `0x8001294c` | `0x80012940` |
| `0x80012950` | `0x8010b700` (current thread — now scheduler-owned) |
| **`0x80012954`** | **`0x0`** |

So this is libultra's **thread dispatch loop walking a ready queue**, and it dereferenced the priority field of
a node whose `next` was null. libultra keeps ready queues as **circular** lists whose terminator is the queue
head node itself — here the head is `0x80012940`, which is exactly what `0x80012948`/`0x8001294c` already
point at. What is missing is the linkage: the walk should have returned to the sentinel `0x80012940`, not
stepped into null, and `0x80012954` — written by the boot loader's init at `0x80000cb8` and still `0x0` here —
is part of that initialisation.

**So what should be at the null base is the guest's own ready-queue node/sentinel, not a host pointer.** This
is the same class of gap as `__osCurrentThread`: my scheduler maintains a Python thread table and selects
runnable threads itself, while the guest's dispatch routine walks a list that the host never builds. Writing
one pointer (`0x80012950`) was enough to get the handler past context save; it is not enough for the guest to
dispatch threads on its own.

#### Option 1: the host now maintains libultra's circular ready queues (M34)

Node layout taken from the dispatcher itself (`lw t6,0x4(t8)` priority, `lw t8,0x0(t8)` next):
`+0x00 next`, `+0x04 priority`, `+0x08 queue`, `+0x0C tlnext`, `+0x10 state`, `+0x14 id`,
`+0x18 fp`, `+0x20 context`. The sentinel is `0x80012940` (where `0x80012948`/`0x8001294c` point), and an
empty queue is that node pointing at itself.

The scheduler now: writes a real `OSThread` header at each `osCreateThread` address (next/priority/state/id),
initialises the sentinel as a circular empty list, inserts on `osStartThread` and on wake, unlinks on
switch/block/exit, sets state RUNNABLE/RUNNING/WAITING, and keeps `0x80012954` as the tail.

**Result: the `0x80000f2c` fault is gone.** After the run the guest list walks cleanly and circularly:

```
ready list: 0x8012bb00 (thread 9) -> 0x80112a40 (thread 1) -> 0x80012940 (sentinel)
0x80012950 (current) = 0x8010b700 (thread 7)     0x80012954 (tail) = 0x80112a40
threads: 0 done, 1/7/9 runnable     faults: none     exceptions: 2 x Cause 0x400 (IP3)
```

So the guest's own dispatch routine now walks a structure the host keeps coherent, instead of stepping into
null. Three threads are alive and the interrupt is being accepted — where previously the system either
deadlocked or faulted.

**Still not solved, and the honest gaps:**

- `msg log` is empty and `open(0)` has not fired; nothing has been posted to `0x8012bd30` or `0x8012bcf8`.
- Thread 7 now sits in the idle spin at `0x8000051c`, so "all threads runnable" partly means "all threads
  idle".
- **The dual-scheduler problem remains.** Threads that stay runnable are unlinked from the guest list at
  switch and only relinked when they block and are woken, and the host still *chooses* which thread runs.
  Option 1 makes the guest's structures coherent; option 2 — letting the guest's dispatcher choose — is what
  removes the duality rather than papering over it.

#### Phase 1 differential: the host scheduler ignores priority (M35)

Guest state words and priorities read straight out of the `OSThread` headers the scheduler writes, instead
of from the host's Python table:

| thread | `OSThread*` | priority | guest state | pc |
|---|---|---|---|---|
| 1 | `0x80112a40` | **40** | RUNNABLE | `0x8006c0d4` |
| 7 | `0x8010b700` | **0** | **RUNNING** | `0x8000051c` |
| 9 | `0x8012bb00` | **60** | RUNNABLE | `0x80088668` |

The earlier report that "1, 7 and 9 are runnable" was a host-table label, not guest state — corrected here.
**I1 passes**: exactly one thread is RUNNING and it equals `0x80012950` (`0x8010b700`).

Run queue order and priorities: `[... 0x8012bb00 (60), 0x80112a40 (40) ...]` — thread 7 (priority 0) is
running and therefore off the queue. Under libultra priority scheduling the next thread to run should be
**thread 9 (60)**, then thread 1 (40), then thread 7 (0).

**The differential, which is the point of Phase 1:**

```
12 of 15 dispatch points: guest highest-priority ready node != host choice
  step 60023: host chose 0x8010b700 (prio 0)   guest queue says 0x8012bb00 (prio 60)
  step 90023: same
  step 120023: same
```

So the host has been scheduling round-robin while the guest's own structure says thread 9 has the highest
priority. That is the dual-scheduler gap measured rather than argued — and it is exactly the discrepancy
Phase 1 exists to surface before removing host selection.

Note on thread 7: priority **0** (lowest) and resident in the `b .` spin at `0x8000051c` is *consistent*
with an idle thread, but consistency is not proof — the priority came from `osCreateThread`'s stack
argument, so a wrong stack read would also produce 0.

#### Phase 2 started: guest owns dispatch, and it cannot yet run (M36)

`tools/run_guest_sched.py` implements the target architecture, kept separate so the Phase-1 harness still
works:

- **One architectural CPU state.** PC, GPRs, HI/LO, CP0 and FPU live on the CPU; there is no host thread
  table and no per-thread register file. Suspended contexts exist only where the guest put them, in RDRAM.
- **No hooks on `osCreateThread`/`osStartThread`/`osCreateMesgQueue`/`osRecvMesg`/`osSendMesg`.** Those run
  as guest instructions and mutate the guest's own circular lists.
- The host models hardware only: cartridge reads, the inflate primitive, PI DMA, MI pending/mask, and
  register reads that would otherwise spin. It never writes `0x80012950` and never chooses a thread.
- Every guest write to `0x80012950` is logged as a context switch.

**Result: zero guest context switches, on every entry path tried.**

| entry | outcome |
|---|---|
| `FUN_80000598` (boot loader) | 148 324 instrs, PI DMA + inflate used, then fault at `0x80000f2c` (null at `0x4`) |
| `FUN_8004D344` (stage-2 entry) | **123 instrs**, then the same fault at `0x80000f2c` |
| `0x80000480` (real entrypoint) | 42 299 instrs, then pc `0x0` |
| `0x80000520` (`main`) | 21 321 instrs, then pc `0x0` |

In every case `0x80012950` is `0x0` and the ready-list sentinel at `0x80012940` still reads `0x0`, so the
guest dispatcher walks into null. The 123-instruction result for `FUN_8004D344` is diagnostic: the guest
reaches `osStartThread` almost immediately and dispatches into an **uninitialised** ready queue.

**So: the scheduler's own initialisation never runs on any path we can start.** Phase 1 kept working only
because the host wrote the sentinel and the current pointer itself — i.e. it was supplying the very state the
guest owns. Phase 2 removes that crutch and the missing initialisation becomes the fault.

**The digest does not reproduce, and no guest-controlled thread transition has been observed.** Recording
that as not-done: the remaining work is to find and execute libultra's scheduler initialisation (the code that
sets `0x80012940` circular and `0x80012950` to the boot thread) before any `osStartThread`, most likely by
starting where `osInitialize` runs rather than at the entry paths tested here.

**Both queue handoffs remain unexplained and separate**, exactly as argued: the only registered event queue
is `0x80139f10`, while the blocked receives are at `0x8012bd30` (thread 9) and `0x8012bcf8` (thread 1).

### What is still not available

A full-game trace. The harness runs one function at a time with prepared state; it cannot follow the
thread scheduler, so it cannot observe the open as it actually fires at a scene transition. The load
trace above is real execution of the loader, replayed per slot, not a recording of the game's own
dispatch order.

### A genuine execution trace is not available here

No N64 emulator is installed and this project has no CPU harness, so a trace of the form
`iteration → pointer → descriptor → size → destination` cannot be produced by observation. It would need
either an emulator with a write/PC hook, or a partial CPU emulator driven from the wrapped ELF images.
Recording this as *not done* rather than reconstructing something that looks like a trace: a fabricated
trace would be the easiest possible way to make this architecture look finished.

### What this leaves for R3

R3 is referenced by nothing we can see: not statically (no record, no constructed address, no cart
pointer in any of 4 761 members) and not dynamically (the only loader path is the fixed 9-slot registry,
which maxes out at cart `0x7e132`). The 4 761 zlib members are therefore **not** loaded through this
registry at all — they must be reached by the sequential stream walk that §3 already demonstrates works,
or by a mechanism still outside the mapped code.

### No descriptor points into R3. Three independent tests:

| test | result |
|---|---|
| boot descriptor table (66 records, `0x80012150`) | cart offsets stop at `0xC85E8`; R3 starts at `0xB73FB3` — **0.82 MB vs 12 MB, no overlap** |
| stage-2 image: `0xB`-flagged records in the boot shape, and `lui`+`addiu` constructions landing in R3's range | **0 records**; 93 constructions, all masks (`0x00FFFFFF`, `0x01000800`, `0x014000F0`, …) |
| strict record shape (4 coordinated fields: flag+offset, size, vram, vram_end) across **all 4 761 unpacked members** | **0 records in 0 members** — the boot table is the only instance of this format in the cartridge's compressed content |

The exact value `0x00B73FB3` — plain and `0xB`-flagged — occurs **nowhere** in the ROM or in stage 2.

A tempting-looking test that must be rejected: scanning for words whose top nibble is `0xB` "finds" 24 059
cart offsets across 2 415 members, and 893 apparent pointers into R3. One sixteenth of all random words have
that nibble, so the flag alone is worthless. The boot table was identified by four fields agreeing over
consecutive records, and only that strict shape is evidence.

### The reframing this forces

**R3 is not a resource.** Its boundaries came from inverting zlib coverage — it is *everything in that span
that is not a zlib member*, so a descriptor for it need not exist, and its first bytes are a preceding
block's trailer rather than a header. Asking "which descriptor points into R3" is therefore ill-posed
until a **specific offset inside R3** is chosen. R1 and R2 escaped this because their spans happened to
contain real containers (media blocks with a verified trailer format); R3 and R4 did not.

## 6. Verification rules this document follows

1. **Two independent paths, or it is not established.** The descriptor table was decoded from
   pseudocode *and* confirmed by blind sequential inflation; the media format was derived from 1 226
   transitions *and* confirmed by a decodable concatenation.
2. **A null result implicates the filter first.** Three scans in this project returned zero because of
   an invented constant (`offset < 0x4000000`, adjacent `(rom, vram)` pairs, `CMF == 0x78`). Every
   later scan was tested against a known positive before being believed.
3. **The cartridge is immutable input.** `scan_headers.py` and `extract_blocks.py` print the ROM's
   sha256 before and after, and both runs show `UNCHANGED`.
4. **`assets/` is gitignored.** Every extracted byte is a derivative of the user's dump and is
   regenerable from the ROM plus these three tools in about twenty seconds.
