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
