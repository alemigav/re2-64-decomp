# M395 — the twelve audio bodies named: `named` 33 → 45, `validated` flat at 12

The eagle view's finding was that the strongest evidence in this repository was **unclaimed**: twelve functions whose
behaviour a gate or an executed experiment already pins (M179–M204, the whole audio engine) and which still carried
`FUN_…` names. Naming them needed no new measurement — only a resolver, which M394 built.

## The twelve, one citation each, and only what the evidence already says

| address | name | the evidence column says |
| --- | --- | --- |
| `0x800b53f4` | `snd_voice_synthesis` | M199 — bit-exact against the cartridge: the body reproduces the image's output sample for sample |
| `0x800b62c0` | `snd_synth_kernel` | M199 — the kernel the synthesis calls, transcribed |
| `0x800b63b4` | `snd_synth_lattice` | M199 — the lattice stage of the synthesis, transcribed |
| `0x800b4dc0` | `snd_dequantise` | M199 — the dequantisation stage of the synthesis |
| `0x800b3704` | `snd_sample_load` | M179/M193 — the sample loader; its index bound and rate byte are source-shape gated |
| `0x800a86a0` | `snd_chain_walk` | M185 — the chain walk both `SND_PROJ` and `SND_POOL` use |
| `0x800ad330` | `snd_sample_dir_walk` | M185/M204 — the sample-directory walker; its `0xe`-short stride and terminator are gated |
| `0x800ada34` | `snd_record_read` | M203 — the record reader whose fields the loop map is built from |
| `0x800a54ec` | `snd_voice_setup` | M203 — the voice setup that derives the loop remainder |
| `0x800a3bf4` | `snd_mixer_feed` | M203 — the mixer feed that splits a block at the loop end |
| `0x800ace1c` | `snd_cache_resolve` | M202 — the cache-C resolver, keyed by key and rate |
| `0x800a5678` | `snd_mutex_acquire` | M200 — the audio mutex acquire, seen at every cache site |

**No name states more than its citation.** `symbols.tsv`'s own rule — *a name here must be backed by a measurement* — is
what makes this batch worth doing and what stops it: none of these is named for what it *looks like*.

## The ladder moved exactly as designed, and the case encoded the defect

```
named 33 → 45      validated 12 (flat)      validated_unnamed 12 → 0      F0/F1/recovered: unchanged
```

`analysis_status.py`'s residue case **required** `validated_unnamed > 0` — it asserted that the pinned-but-unnamed residue
exists. Naming the twelve falsified it, so the invariant flips: **a function whose behaviour a gate pins must carry a
name**, because the evidence for the name already exists. The unresolved-call residue is still required to be non-empty,
so the case cannot pass on an empty corpus.

## The resolver paid for itself, and the ripple still had teeth

M394's resolver meant the citations did **not** break — but six tools still enumerated sources **by file name**, and the
rename exposed them:

| what | the fix |
| --- | --- |
| `snd_proj`, `file_table`, `cfg_reach`, `snd_macros` built paths as `… / "FUN_<addr>.c"` | converted to `srcmap.path("stage2", addr)` — **16 sites the first gate missed** |
| the gate itself had the blind spot | a **fifth pattern**: a name *with a `.c` extension* is a filename, never a C identifier |
| `file_table` counted the audio cluster by file **stem** (`func_`/`fun_`), so three renamed files read as "missing" | rewritten to ask the index: an address has a body if `code_index.json` names a file for it that exists — the same class M351's own comment had already abandoned once |
| four artefacts bake rendered paths (`voice_descriptor`, `opcode_registry`, `rsp_decode`, `snd_macros`) | regenerated with `--write` |

**One blind spot is left and is named rather than hidden:** `manifests/voice_descriptor.json` stores its citations as
**paths**, so a rename needs a `--write` (its "25 cited sources unchanged" case drifts otherwise). Storing addresses there
is the follow-up; the gate cannot see inside a JSON artefact.

## Moves

`named` **33 → 45**, `validated` **12**, `validated_unnamed` **12 → 0**; `recovered` **274 / 273**, `F1` **3 468**, `F0`
**3 664**, coverage **1 238 404 B** — none of the corpus ledgers move, which is what a naming pass should be. Tree **82
suites / 1 384 → 1 385 cases** (357 → 358 runnable), four artefacts regenerated, `verify.py --full` **PASS**, audit
**160/160**.
