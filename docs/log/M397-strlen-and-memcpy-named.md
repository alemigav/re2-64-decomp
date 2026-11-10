# M397 — `strlen` and `memcpy`: the first names whose evidence is a body

Every name before this one rested on an *external* authority or on a gate (M395's twelve). These two rest on the
reconstruction itself, and that turns out to be the strongest citation available: **the C is the contract, and it
reproduces the cartridge's bytes nine and ten words at a time.**

| address | name | words | the body |
| --- | --- | --- | --- |
| `boot:0x8000de78` | **`strlen`** | 9 | walks to the NUL byte, returns `p - a0` |
| `boot:0x8000de9c` | **`memcpy`** | 10 | copies `a2` bytes forward, returns the destination |

Both are byte-exact against the image (M370 read them from the words: 9 of 9 and 10 of 10), both live in
`fixtures/decomp/authored/boot/`, and their contracts are not inferred — `while (*p) p++; return p - a0;` **is** `strlen`.
That is what makes these names cheap and safe: no resemblance argument, no caller-side inference, no naming by
neighbourhood.

**`named` 45 → 47**, `validated` **12** and `validated_unnamed` **0** unchanged — a naming pass again moves no corpus
ledger.

## What the rename cost, now that the resolver exists

Nothing, and that is the point of M394. The two files moved from `src/boot/FUN_8000de78.c` / `FUN_8000de9c.c` to
`src/boot/strlen.c` / `memcpy.c`, `code_index.json` followed, and **no tool cited them by name** — `srcmap` resolves by
address, and the gate confirmed zero sites before and after. The only ripples were the derived figures: the front page's
`47` (asserted by `counts.py`), the extended page's copy, and `front_page.py`'s regenerated block.

**Contrast with M395, which needed six tools converted and 34 audit anchors repaired.** That difference is the whole
argument for the resolver, measured: the first rename cost a milestone, the second cost nothing.

## The naming ladder, now with all four rungs occupied

| rung | evidence | count | examples |
| --- | --- | --- | --- |
| 1 | external API + executed instrumentation | 4 | `osCreateThread`, `osRecvMesg`, `osSendMesg`, `osSetEventMesg` |
| 2 | external API + byte-exact C | 4 | `main`, `cart_record`, `osCreateMesgQueue`, `framebuffer_set` |
| 3 | external API + structure | 3 | `pi_dma_programmer`, `pi_dma_raw`, `osStartThread` |
| 4 | project-invented descriptive | 22 | `thread*_entry`, `overlay_*`, `scene_load_*`, `inflate_*` |
| 5 | pinned by a gate, unnamed | **0** | — (M395 closed this) |
| **6** | **the reconstruction *is* the contract** | **2** | **`strlen`, `memcpy`** |

Rung 6 is the new one, and it is the cheapest rung of all — but it has few members, because a body only names itself when
its *behaviour* is a recognisable contract at nine or ten words.

## Moves

`named` **45 → 47**; `recovered` **274 / 273**, `F1` **3 468**, `F2` **3 408**, `F0` **3 664**, coverage **1 238 404 B** —
no corpus ledger moves. Two `src/` files renamed; `srcmap` gate 4/4; all suites green; `verify.py --full` **PASS**, audit
**160/160**; milestones **398 numbers / 341 rows / 322 notes** (after the counters move).
