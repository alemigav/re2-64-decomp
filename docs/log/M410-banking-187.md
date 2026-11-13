# M410 — banking 187 bodies: the corpus goes 274 → 461, and a correction to M409's headline

M409 measured the distance and found bodies that compile to the cartridge's own bytes without anyone having claimed
them. M410 makes them claims — with a pin each, and with their provenance stated rather than absorbed.

## The result

| | before | after |
| --- | --- | --- |
| entries in `recovered.json` | 274 | **461** |
| byte-exact | 273 | **460** |
| `make check` (`build_corpus --check`) | 273 exact / 1 differ | **460 exact / 1 differ, 0 unexpected** |
| compile-probe cases | 296 | **483**, all passing |

Nothing was drafted. Every one of the 187 was already compiling to the image; what was missing was *evidence*:
a self-contained source file, a fixture entry, and a probe pin that can fail.

## A correction to M409: 439 was 392

M409's headline said **439 bodies already compile byte-exact**, of which 188 were unclaimed. The 188 was right; the 439
was not. `distance_map.py` measured `src/`, and `src/` is a **projection of `recovered.json`** — so for the 251 bodies
the project had already claimed, it was measuring *our* reconstruction, which is exact by definition, and counting it as
the decompiler's C. **Two measures were being added.**

Measured correctly, from the provider's own artifact (`build/decomp/<image>/functions/0x<addr>.c`):

| | bodies |
| --- | --- |
| provider bodies that compile byte-exact as emitted | **392** |
| of those, never claimed before M410 | **188** |
| of those, banked by M410 | **187** |
| refused — pins 0 of 8, `ld` rejects the object | 1 (`stage2:0x800282e8`) |
| within 1 / 2 / 4 / 8 words | 71 / 88 / 59 / 78 |

Both tools now read the provider artifact for this question, which is the only input that does not change when the
fixture does. The published line was corrected with the measurement: *"392 bodies of the decompiler's own C compile
byte-exact, 187 of which were never claimed until M410, and 296 more are within eight words."*

## Provenance is a fifth bucket, and it is not merged

These 187 are **the decompiler's C**, adapted only in its scaffolding (type names, `extern` declarations, the COP0
constants). The project did not write them. So `recovered.json` gained `provenance: "provider"`, `counts.py` gained
`banked` / `banked_exact` / `project_recovered` / `split_banked`, and **the front page states the split in the same
sentence as the total** — 461 entries, 460 byte-exact, *187 the decompiler's C verified word for word, 274 ours*. The
invariant that the split adds up is asserted, exactly as the older four-way split is.

A project whose whole value is that every claim is checkable cannot relabel somebody else's output as its own work, and
188 functions is precisely the size of temptation where that gets tempting.

## Two harness lessons, both found by failing

1. **The input must be the artifact that does not move.** The first banking run read `src/`, which after a projection
   contains *our* reconstruction — so it prepended a second preamble and six bodies came back `redeclared as different
   kind of symbol`. Banking now reads the provider artifact, and the same rule then fixed the map (above). One wrong
   input, two wrong numbers.
2. **A pin must be verified at banking time, not discovered by the gate.** `bank_exact.py` now compiles, assembles,
   links and compares every body *before* writing its entry, mirroring `compile_probe.single_probe` step for step —
   including the `objcopy` pass that normalises the binutils-2.7 symtab binutils 2.42 refuses. Skipping that one step
   refused all 188; keeping it refuses one.

## The ripple, and one that mattered

`src/` and `code_index.json` were re-projected, `call_graph.json` rebuilt (15 539 edges), the front page regenerated,
the ladder re-derived, and 188 probe cases added — **1 582 cases** now, which is the cost of pinning them.

The ripple that mattered: **`manifests/voice_descriptor.json`'s citations broke**, because they are `@<addr>:<line>:
<statement>` and the preamble moved the statements down ~25 lines in 4 of them. The address resolved (M394's rule) and
the *line* did not. They were re-derived by finding each cited statement in the resolved file — the same repair
`srcmap.render()` does at use time, done once for the fixture. **A citation that carries a line number is a claim about
a file's layout, and any tool that rewrites `src/` is a citation-wide event.**

## What this does not claim

- The 187 are not validated behaviour, only **byte identity**. They move `recovered`; they move `validated` not at all
  (still 12), and `named` not at all (still 47).
- One body is refused and stays refused: `stage2:0x800282e8` pins 0 of 8 because `ld` will not link its binutils-2.7
  object. That is a harness limit, named rather than worked around.
- 296 bodies are within eight words, and 71 within **one**. They are the next queue, and they need drafting — which is
  what the corpus was doing before M409 and can now do against a ranked list instead of a guess.
