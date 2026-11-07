# M361 — the admission gate: two functions the census did not have, and the three environments that hid them

M360 found whole functions inside a run our byte map called `enclosed_data`, and named `0x80004fb4` and `0x80005074`
(48 words each) as the first two. This milestone admits them — and discovers that the gate for doing so already
existed, unused.

## 1. The gate was already there

`export_src.py`'s own comment says *"Functions the provider never claimed are added"*: the recovered fixture is applied
after the provider's ranges, and an entry at an address no range covers is **appended**, not skipped. So the admission
mechanism has been present since M289, and M341's `measured_extents.json` uses the same path for functions with a
measured extent and no reconstruction. What was missing was a rule for *when* to use it, and the byte map's
disagreement.

The two entries are ordinary `recovered.json` rows — `source_file` under `fixtures/decomp/imported/boot/`, `syms`, and a
probe string that says what happened:

> `admitted to the census (M361): 48 of 48 words, no provider range at this address (func_80004FB4)`

Both compile to the image's own 192 bytes under this profile, so `compile_probe.py --check` went **329 → 331 of 331**.

## 2. The number that moved, and the invariant that now holds it

| | before | after |
| --- | --- | --- |
| `F0` (functions in the census) | 3 603 | **3 605** |
| covered bytes | 1 235 844 | **1 236 228** (+384 — exactly the two bodies) |
| `F1` / `F2` | 3 428 / 3 360 | **3 430 / 3 362** |
| recovered / byte-exact | 360 / 359 | **362 / 361** |
| `function_body` (byte map) | 1 235 280 | **1 236 228** |
| `enclosed_data` | 53 016 | **52 496** |

`classify_image.py` had to learn that a *reconstructed* function is a body: it claimed `function_body` from the
provider's ranges and from `measured_extents.json`, but not from `recovered.json`, because until now every recovered
function happened to sit inside a provider range. Without the change the index would have claimed a function the map
called data — precisely the drift M340 fixed for the measured rung, one fixture later.

Two cases now hold the property, and both are **derived**:

- *every one of the 29 352 words in `recovered.json` is a `function_body` word in the map* (0 are not);
- *every `function_body` range names one of three fixtures* (0 name anything else).

The class total it used to pin — `1 235 280 B` — is gone from the gate. A pinned total was always going to break when a
function was admitted, and the mechanism it stood for is now asserted directly.

## 3. Three environment gaps, all the same lesson

The admission broke the audit in a way that had nothing to do with admission: **eight counts audits went `BROKEN`
because the unmutated tool failed inside the sandbox**. Chasing it found three missing inputs, each a repeat of a
lesson this file has recorded twice already (*an input a tool reads belongs in the sandbox, not in the tool's task
list*):

| gap | what it hid |
| --- | --- |
| `fixtures/decomp/imported/` not copied | `compile_probe.py` loads those files at import; without them the probe reports broken cases |
| the copy loop could not copy a **directory** | `build_env` used `shutil.copy2`, so the entry above needed a `copytree` branch |
| `include/` not linked | `t64_selftest.py` compiles `tools/t64info.c`, which `#include`s `../include/re2_formats.h`; without it the suite reports "no verdict", and **every counts audit was judged against a total the sandbox could not reproduce** |

And one stale anchor: the mutation *"code_index's covered_bytes is a word count again"* pinned **`boot`'s**
covered_bytes, which moved by 384 B the moment two functions were admitted. It now targets `ovl_009d282` — a 464-byte
image that is fully covered — so the number cannot drift while the image does not. The lint caught it before the audit
ran, which is that gate doing exactly its job.

## 4. What is still not admitted

`0x80005134` (33 words), the third function in that run, has **no reconstruction from anybody**. It is measurable — the
run is return-delimited and its extent is 33 words — but admitting a function with no C is the `measured_extents.json`
path, not this one, and it should be done with the *body* published as a listing rather than as a reconstruction.
The other 141 candidate segments of M360 remain untriaged, and the rule for triage is now demonstrated: a body whose
reconstruction compiles to the image's bytes, and a census entry to hang it on.

## Numbers

- **+2 functions admitted** at addresses no provider range covers; probe **329 → 331/331**
- census **3 603 → 3 605**; covered **1 235 844 → 1 236 228 B**; recovered **360 → 362 / 361 byte-exact**
- byte map: `function_body` **+948 B** (the two bodies plus 564 B of recovered extents that had been classed as data),
  `enclosed_data` **−520**, `dense_data` **−476**; the partition still closes on 1 956 560 B
- audit back to **160/160, 0 vacuous, 0 broken** with three environment gaps closed and one anchor made stable
- tree **1 380 → 1 383 cases** (324 runnable, 1 059 gated); `verify.py --full` **PASS**
