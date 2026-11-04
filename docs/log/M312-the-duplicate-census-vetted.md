# M312 — the duplicate census, vetted: 85 candidates, and two things I had wrong

The compiler work stopped at M311, so this returns to the duplicate cohorts. Before drafting the biggest remaining
group, the census itself needed a check — and it found two errors, one of them mine from this same session.

## 1. A group is only a candidate if it contains a return

Two of the eight "small" groups examined in M308 turned out to be **mid-function fragments** (`lh t4,0(a0); lh
t1,0(a1); lh t5,2(a0)` with no `jr ra`). Drafting one is wasted work, so the census now splits before it drafts:

| | groups | functions |
|---|---|---|
| repeated bodies among the unmatched | **40** | **89** |
| … that contain a return (reconstructible) | **38** | **85** |
| … that are fragments (not reconstructible) | **2** | **4** |

Gated as a probe case, so the split cannot drift.

## 2. Two corrections

- **My own, from this session**: I read the 53-word group as a fragment because the `objdump` listing stopped early.
  The word scan says it **contains `jr ra`** — it is a complete 53-word function, four copies. The lesson matches
  M304's: read the *words*, not the rendered listing.
- **The census's**: its "duplicate" count included the fragments above, so the previous framing ("89 functions in 40
  groups" → "one reconstruction worth several functions") is right in bulk but was 4 functions optimistic.

## 3. What is left, by size and copies

| copies × words | where | note |
|---|---|---|
| 4 × 25 | `ovl_008900e` etc. | **stalled at 22/25** — the `u16` truncation copy (M310/M311), a reference-count tie-break in `global_alloc` |
| **4 × 53** | `ovl_008900e:0x8016852c` etc. | the largest remaining prize: a stack-argument call, a `× 48 -` stride computation, three paired field updates |
| 3 × 32, 3 × 21, 3 × 20, 3 × 13, 3 × 7 | across overlays and stage2 | mid-sized, two or three copies each |
| 2 × 13, 2 × 12, 2 × 11, … (≈28 more groups) | — | the long tail |

**Next target: 4 × 53.** It is the only remaining group worth four functions, it is a real function (a frame, a
call, a stride), and the two known walls do not obviously apply to it — its arithmetic is a `v1*2 + v1` then
`<<4` then `-v1` then `<<3` stride, i.e. `×376`, which is the same shape the record-writer family already
reproduced byte-exactly (M-6fc5c).

## Numbers

- compile probe **63 → 64 cases** (64/64 pass); recovered **75 / 74 exact** unchanged
- tree: **73 suites / 1 039 cases** (753 need the cartridge)
