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
| +0 | cart offset **OR'd with `0xB0000000`**; real offset = `& 0x0FFFFFFF` |
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

The test that would separate the two: **match-run length at the lag**. Approximate repetition of
whole records produces runs of 3+ consecutive matching bytes; a byte-level skew artifact produces
isolated single matches. That is a small addition to the `phase` subcommand and the next thing to run.

### What is left for R3

The head of the region is `… 64 fe 27 fe 74 ff 21 ff a0 ff e3 ff fe 00 05 00 05 06 b6 03 c8 01 a0 00`
— a run of `0xFF` high bytes, the shape of **16-bit samples that are mostly negative**, i.e. audio.
1 484 `fffb` frame syncs are too sparse (one per 6 KB) to be a dense MP3 stream, so that is not yet a
claim either. **Hypothesis, not finding:** R3 is audio (VADPCM/PCM) or a texture archive; R4 likewise.
Both regions were entered mid-block by the coverage pass, so the first bytes are cut points, not
headers — which is why their apparent "headers" disagree byte-for-byte with the verified ones.

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
