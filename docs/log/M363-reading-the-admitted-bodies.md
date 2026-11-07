# M363 — reading the admitted bodies: 21 reconstructions, 11 withdrawals, and F1 moves

`F1` counts functions with a reconstruction. M362 admitted 85 on the `extent_measured` rung, which by construction does
not move it — the rung exists to say *the bytes delimit a function here*, not *the body is understood*. This milestone
starts reading them, and the first pass also found that M362's rule admitted eleven things that are not functions.

## 1. The rule M362 was missing: self-containment

`extent_scan` splits at returns; it does not check that a body's **branches stay inside it**. Eleven of the 85 fail
that, and the failures are unambiguous once printed — `0x800a2424` is six words ending in `jr ra`, with a `bne` at word
2 whose target is word 6, i.e. **past the end of the body**:

| shape | count | example |
| --- | --- | --- |
| `j`/`jal` in the middle of the body | 4 | `0x80036b2c` (20 w) has a `j` at word 7 |
| conditional branch past the end | 7 | `0x800a2424`, `0x800aa8b8`, `0x800ab7b8` (all 6 w, target = word 6) |

Those bodies are **fragments**: the first three are tails of a comparison the extent cut in half, and the four with a
mid-body `j` are continuations. They are **withdrawn** from `measured_extents.json` — 85 → 74 — and the rule gains a
fifth rejection. The census goes down with them, which is the honest direction: this milestone takes 11 functions *out*
of the count and 21 *onto* the ladder.

## 2. Reading: 21 for 21 on the first pass, after one correction

The small ones read straight off the words — setters, getters, counter bumpers:

```c
u32 FUN_8006db00(u8 *a0)          u32 FUN_8006bea0(void)
{                                 {
    *(u32 *)(a0 + 28) += 1;           return (D_80139e60 & 0x60) != 0;
    return 1;                     }
}
```

Seven of the first drafts missed, and every one missed the same way, which is worth recording because it is the third
time this project has paid for it: **an `addiu`/load/store immediate is sign-extended**, so `lui v1,0x800f` followed by
`sw v0,0x9130(v1)` addresses **`0x800E9130`**, not `0x800F9130` — the offset `0x9130` is −0x6ED0, not +0x9130. M322
established the rule; this milestone applied it wrongly four times in a row before noticing that the compiler's own
answer (`lui at,0x8010`) was the tell. After the correction: **21 of 21 byte-exact**, `compile_probe.py --check`
**331 → 352 of 352**.

## 3. A second rule the check needed

Admitting `0x80026a98` broke `call_graph`'s callee check for an unrelated function: `0x8017b744` has a `jal` the
provider could not resolve (`callees_unknown: 1`), and the fresh graph now resolves it to the newly-admitted function.
The check demanded **equality** between graph edges and the index's callee list, which fails every time an admission
turns an unknown call into a known one. It now asserts the honest invariant: *the graph reaches every callee the index
lists, plus at most the calls the index itself counted as unknown.*

## 4. What moved

| | before | after |
| --- | --- | --- |
| **`F1`** (has a reconstruction) | 3 430 | **3 451** |
| recovered / byte-exact | 362 / 361 | **383 / 382** |
| rung `extent_measured` | 260 | **228** (−21 read, −11 withdrawn) |
| `F0` (census) | 3 690 | **3 679** (−11 fragments) |
| covered bytes | 1 242 488 | **1 241 400** (fragments withdrawn) |
| `F2` | 3 405 | 3 403 |
| composition | 16 hand + 55 + 97 + 194 | **37 hand + 55 + 97 + 194** |

Coverage fell by 1 088 B and the census by 11, and both are right: those bytes are not functions. **`F1` rising by 21 is
the point of the milestone** — the ladder's "understood" column moved for the first time since M359, and it moved by
reading, not by importing.

## 5. What is left of the 85

**53 bodies remain on the rung**: 32 of 4–10 words (the same shapes as this tranche, so most should read), and 21 of
11–209 words including `0x8000e208` (82 w), `0x80048bac` (121 w) and `0x800324a8` (209 w). The reading procedure is now
pinned down and cheap — dump the words, write the C, let the probe judge — so the rest is a matter of taking them in
batches. The four with `j`/`jal` mid-body and the eleven withdrawn fragments are **not** in that queue; they need the
extent to be re-measured around them rather than read as they stand.

## Numbers

- **+21 reconstructed** and byte-exact on the first corrected pass; probe **352/352**; **−11 withdrawn** as fragments
- ladder **F1 3 430 → 3 451**, `F2` 3 403, rung **260 → 228**, census **3 690 → 3 679**, coverage **63.4 %**
- two rules sharpened: *self-containment* for admission, *edges ⊇ callees + unknown* for the call graph
- tree **1 383 → 1 404 cases** (324 runnable, 1 080 gated); `verify.py --full` **PASS**, audit 160/160
