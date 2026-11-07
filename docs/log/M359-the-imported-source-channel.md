# M359 — the imported-source channel, and the 139 overlays it unlocked

M358 ended with 139 verified overlay reconstructions it deliberately did not register: 139 constants would have added
roughly four thousand lines of somebody else's C to `tools/compile_probe.py`, for a corpus that is **imported** rather
than reasoned about. This milestone builds the channel that makes them registerable, and banks all of them.

## 1. The channel: one reader, two channels

`fixtures/decomp/recovered.json` stays the single reader (M289's invariant) and gains one optional key:

```json
{ "image": "ovl_0072610", "address": "0x801833a0", "words": 178, "verdict": "byte-exact",
  "probe": "import by content alignment: 178 of 178 words at our own address (…, delta +128)",
  "source_file": "fixtures/decomp/imported/ovl_0072610/801833a0.c",
  "syms": { "D_80119E14": 2147450388, … } }
```

`source` means *a constant in the probe*; `source_file` means *a file*. Everything downstream asks one function,
`recovered.source(entry)`, which now answers both — so `export_src.py` publishes either kind into `src/` identically,
and the published header names whichever holds the text.

`tools/compile_probe.py` gained a fifteen-line loader that runs at import: it reads the fixture, registers every
`source_file` as `IMPORTED_<IMAGE>_<ADDRESS>_SOURCE` in its own namespace, and appends the matching `SINGLES` row. The
probe, its case generator and the family probe therefore work unchanged — a file-based reconstruction is a normal
member of the corpus that happens to keep its text somewhere else. Three consumers needed the same two-line
concession (`family_probe`, `toolchain_matrix`, `export_src`); each is the pattern *"if `source` is absent, the key is
a path"*, and the reason it is only three is that M289 made everything go through one reader.

## 2. The 139

Generated from the M358 content alignment and verified the same way: compiled at **our** address with **our** symbol
addresses (their map shifted by the segment delta), compared against our own bytes, written only where the whole body
matched. **139 for 139 verified, 3 025 words**, across 28 overlay members:

| member | n | | member | n | | member | n |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `ovl_0072610` | 22 | | `ovl_00b321e` | 12 | | `ovl_0093aba` | 3 |
| `ovl_0090698` | 16 | | `ovl_009dd02` | 9 | | `ovl_00b2d7a` | 3 |
| `ovl_008505e` | 13 | | `ovl_00a733e` / `ovl_00a9d94` | 8 each | | twelve members | 1–2 each |

The largest are `0x801833a0` **178 words**, `0x80182d00` 158, `0x801837f0` 148, `0x80182f78` 86 — the four biggest
single functions this project has ever banked, and all four in `ovl_0072610`. `compile_probe.py --check` went
**190 → 329 of 329**, which is 139 new cases each re-deriving its own address from the image.

## 3. State

- recovered **221 → 360**, byte-exact **220 → 359** — the corpus more than doubles in one milestone
- composition **16 hand + 55 singles + 97 copies + 192 imported**
- ladder **F1 3 423 → 3 428**, **F2 3 355 → 3 360**, rung `extent_measured` **180 → 175** (five more graduated)
- tree **1 236 → 1 375 cases** (323 runnable, 1 052 gated); `unclassified` **440 B (0.0 %)** unchanged, coverage
  **63.2 %** — the byte map does not move because these functions were already known bodies, which is the honest
  reading: **this milestone reconstructed code, it did not discover any**
- `verify.py --full` **PASS**, audit 160/160, 0 vacuous, 0 broken

## 4. What the channel is not

It is **not** a way to skip the gate: a `source_file` entry is worth exactly what its `SINGLES` case says, and that case
compiles the file at the entry's address and compares. Deleting the file breaks the case, editing it breaks the case,
and a wrong address breaks the case — which is the property the 139 needed, since their addresses came from a *content*
search and not from anybody's symbol table.

It is also **not** a second source of truth about extents: `recovered.json` still carries image, address, words and the
probe string; the file carries only the C.

## Numbers

- **+139 functions / 3 025 words**, all overlays, all verified at our own address; probe **190 → 329/329**
- recovered **360 / 359 byte-exact**; corpus composition **16 + 55 + 97 + 192 = 360**
- `fixtures/decomp/imported/` — 139 files in 28 directories; the corpus they came from stays gitignored
- tree **1 375 cases** (323 runnable, 1 052 gated); 77 suites; `verify.py --full` **PASS**, audit 160/160
