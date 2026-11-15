# M439 — the call-signature pass, refuted before it was built: 4 bodies, not 565

M438 ended by proposing a lever: *read the callee's prologue to learn how many stack arguments the call passes, and
reserve the same outgoing space.* Its evidence was `ovl_00a43b6:801683d8`, a 7-word body with a −64 frame that saves
only `ra` and makes one `jal`, where the extra 40 bytes looked exactly like outgoing argument space. The estimate was
**565 bodies**.

The estimate is wrong by two orders of magnitude, and twelve seconds of measurement says so. For every body whose first
difference is the prologue frame adjust — **560** of them — classify what the image's own body does with the bytes:

| what the extra frame bytes are | bodies | share |
| --- | --- | --- |
| **locals the draft omits** — the image reads `sp`-relative slots inside the gap | **381** | 68 % |
| **never touched** — the frame differs but no access reaches the difference | **137** | 24 % |
| other — the body accesses *past* its own frame (`maxlocal ≥ frame`) | 38 | 7 % |
| **outgoing argument space, with stores** | **4** | **1 %** |

Four. The lever addresses **0.7 %** of the class it was proposed for, and building it would have cost a pass, a
fixture and a gate to close four bodies.

## What the 560 actually are

Split by direction, which is the part M438 did not do:

| | bodies | share | what it means |
| --- | --- | --- | --- |
| target frame **larger** | **403** | 72 % | the original kept more values live than the draft declares |
| our frame **larger** | **157** | 28 % | the draft declares locals the original did not need |

Both directions are the same defect seen from opposite ends: **the frame is a function of the draft's variable set**,
and the provider's pseudocode does not have the original's variables. In `boot:80001698` (64 words) the image's frame is
112 against our 24 and it *reads* `sp+108`; in `boot:800066f0` (34 words) ours is 32 against the image's 24 and the gap
is never touched. The first needs locals written into the C; the second needs locals removed from it. Neither is a
compiler pass, and no flag in `-O`/`-m`/`-G` space changes either, because the flag set does not decide how many
variables a function has.

The 38 "other" bodies are a different defect again and are worth naming separately: `boot:0x800038f0` accesses
`sp+1508` inside a frame of 1480, and `boot:0x80002bc0` reaches 36 in a 16-byte frame. **Those extents are wrong**, not
the compiler — a body cannot legally read past its own frame, so the measured extent is truncated or the boundary is
misplaced. `leaf_screen.py --called` already exists to look for exactly that.

## The retraction, stated as one

M438 said: *"the lever this points at instead is a call-signature pass … that addresses 565 bodies against
allocation's 212."* The measurement above replaces it with **4 bodies against allocation's 212**, and the 565 becomes
560 bodies of draft fidelity, of which 38 are extent defects. **The call-signature pass is cancelled before any code
was written for it** — which is the cheapest possible outcome for a wrong idea, and the reason M438's estimate was
labelled an estimate.

The pattern is worth recording because it is now three for three: **m2c** was already running the right target
(4 of 249), **libultra** does not reproduce our bytes (best 26 of 70), and **call-signature** is 4 bodies of 560. Each
was a plausible, published, ranked suggestion; each died to a measurement that took less time than the building would
have.

## Numbers

- frame-adjust first differences **560**; outgoing-argument space **4 (0.7 %)**, locals omitted **381 (68 %)**, never
  touched **137 (24 %)**, extent-inconsistent **38 (7 %)**
- direction: target larger **403 (72 %)**, ours larger **157 (28 %)**
- nothing built, nothing banked, no fixture touched; the allocation cluster (**212 bodies, 8.3 %**) is now the largest
  measured lever that is a compiler decision rather than a source-fidelity one
