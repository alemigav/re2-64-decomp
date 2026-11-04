# M324 — the boot extent corrected: 0x11140 → 0x13420, and the function it unlocked

`BOOT_SIZE` covered the boot's **code** and stopped one word before the last function's delay slot. It is now the
boot's **load** extent, and the clincher is a number this project recovered itself.

## 1. The evidence, and the number that settles it

`BOOT_SIZE = 0x11140` (69 952 B) ends at virtual `0x800115C0`. The word there is real code — `slti v0,v0,0`, the
delay slot of the `jr ra` at `0x800115bc` — and the same cartridge region runs on to stage2 at ROM `0x14420`, carrying
the version string `RE.0930…9.1542`, the **overlay table** (magic `OVERLAYTABLENUMC` at virtual `0x80012150`) and the
ASCII table before stage2's zlib.

The decisive check is arithmetic on a recovered function:

```
0x80000480 + 0x13420 = 0x800138A0  =  __bss_start, from `main`'s own byte-exact C (M322)
```

So the boot's **load** extent is `0x13420` (78 880 B) and it ends exactly where `main` starts clearing BSS. Two
independent measurements — the cartridge's own layout and a function reconstructed from it — agree on the same byte.

## 2. What moved

Six constants and one comment, all in one commit:

| file | was | now |
|---|---|---|
| `tools/build_images.py` | `length=0x11140` | `0x13420` |
| `tools/compile_probe.py` | `BOOT_SIZE = 69952` | `78880` |
| `tools/splat_boot.py` | `BOOT_SIZE = 0x11140` | `0x13420` |
| `tools/scan_code_members.py` | `size=0x11140` | `0x13420` |
| `tools/exception_path.py` | `69952` | `78880` |
| `config/boot.yaml` | comment | records both extents |

Re-derived, in order: the boot ELF (`build_images.py`), the images fixture (`export_ranges.py --write-images`), the
byte map (`classify_image.py --write`), `src/` and the code index, the analysis ladder, the call graph, the map.

The corpus numbers that follow from the wider image:

| | was | now |
|---|---|---|
| image bytes | 1 947 632 | **1 956 560** |
| coverage (inside a known body) | 62.2 % | **61.9 %** |
| padding | 407 608 | 408 124 |
| `DAT_`-named data | 6 640 | 6 680 |
| jump tables | 964 | 980 |
| unclassified | 321 820 (16.5 %) | **330 176 (16.9 %)** |

**The partition now derives its own total** instead of asserting a literal: `classify_image.py` compares the sum of
its classes against `fixtures/decomp/images.json`, so the next extent correction cannot leave it pinned to a dead
number — the same lesson M319's census case learned. `script_population.py` was regenerated (its artefact embeds
coverage).

## 3. The function it unlocked — and where it stops

`boot:0x800115b0` is measurable now: **4 of 5 words**. It reads `AI_STATUS` (`0xA450000C`) and returns its sign bit —
`AI_STATUS_BUSY`. The residue is one instruction:

```
4  0x800115c0  had  slti $v0,$v0,0
               ours srl  $v0,$v0,31
```

Five expression forms were measured — `(s32)v < 0`, `v >> 31`, `(v & 0x80000000) != 0`, a signed-register local, and
a `?:` with 0/1 arms — and **all of them** give `srl`. gcc 2.8 canonicalises "sign test → 0/1 value" into the logical
shift; the image's build chose `slti`. That is an idiom choice in the same family as the allocator residues, and it is
**not registered**: 4 of 5 words is a residue, not a recovery.

## Numbers

- **recovered 130 / 129 exact — unchanged** (nothing registerable)
- compile probe **118 cases** (118/118), and the `boot_edge()` case now asserts the corrected extent:
  `BOOT_SIZE == 0x13420 == load_extent` and `0x80000480 + load_extent == 0x800138A0`
- tree **1 105 cases** (807 gated, 298 runnable); suites 74, tools 101 — unchanged
- byte map 6/6, script population 13/13, counts 25/25, markers 22/22 — all green
