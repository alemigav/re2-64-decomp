# M335 — the duplicate cohorts: 17 functions from one shape, and the headline number finally gated

The census said **82 functions in 37 complete duplicate groups** were still available, and the M307 mechanic says one
proven reconstruction registers every copy. Worked to ground: **17 registered** — and the other 65 priced, with four
bodies drafted and measured, and one structural discovery about the corpus's own headline that mattered more than the
17.

## 1. The find: one shape, eight table addresses

Eight of the 37 groups are **the same thirteen-word body**, and they differ only in the address of the handler table
they index:

```
addiu $sp,$sp,-24      lui  $v0,<table hi>     sw   $ra,16($sp)
lbu   $v1,5($a0)       addiu $v0,$v0,<lo>      sll  $v1,$v1,2
addu  $v1,$v1,$v0      lw   $v0,0($v1)         jalr $v0
nop                    lw   $ra,16($sp)        jr   $ra          addiu $sp,$sp,24
```

Members: 3 + 2 + 2 + 2 + 2 + 2 + 2 + 2 = **17 functions**, in seven overlays. One C shape covers all of them, once per
table address. Registered, and all eight family cases pass — 17 functions, **147 recovered / 146 byte-exact**.

**The shape is the whole finding.** The obvious C — `TABLE[*(u8 *)(a0 + 5)](a0)` — compiles to **7 of 13**: every
difference is a `$v0`/`$v1` swap, because the allocator coalesces the index into the load's destination. Taking the
**address of the table slot** and calling through the pointer is byte-exact:

```c
fn *t = &D_80163120[*(u8 *)(a0 + 5)];

(*t)(a0);
```

That keeps the table base live across the load, which is what puts it in `$v0` with the index in `$v1` — the image's
allocation, obtained from a *statement boundary* rather than from a flag. Both the 7/13 and the 13/13 are recorded, the
first as the refutation of the shape that looks natural.

**A `lui`/`addiu` pair is not what it prints.** Four of the eight tables decode to `0x8016_xxxx`, not `0x8017_xxxx`:
`lui $v0,0x8017` + `addiu $v0,$v0,0x82d0` computes **0x801682d0**, because an `addiu` immediate is sign-extended. That
is M322's rule met from the other side — the first entry was registered by hand from the rendered listing and was
wrong until the decoder disagreed with it. The registration now derives each table address from the words.

## 2. What the other 65 groups cost

Four bodies drafted alongside the dispatcher, each at its own address, each measured:

| group | words | first draft | best draft | what the miss is |
| --- | --- | --- | --- | --- |
| `0x801630bc` (2 copies) | 11 | 7/11 | 7/11 | register naming; the loop counter lands in `$a0` where the image has `$a1` |
| `0x80162114` (2) | 12 | 8/12 | **9/12** | the second argument (`a1 = 0`) put the `addu` in the `jal` slot; the rest is register naming |
| `0x8005dac0` (2) | 18 | 7/18 | 7/18 | the mask pair and the branch distance follow from register choice |
| `0x8000d428` (2) | 13 | — | — | a different 13-word body (a call then `a0 + a2`), not the dispatcher shape |

So the remaining cohort stock is **not** the M307 stock. Those first 59 were an empty function, a nine-word masked call
and a three-store setter; what is left starts at eleven words and every one of them meets the allocation wall at
between 60 % and 75 % of its words. **The cohort mechanic is preserved — one proof still registers every copy — but
the copies no longer come cheap.**

## 3. The thing that mattered more: the headline was ungated

Registering 17 functions moved the project's headline from **130 / 129** to **147 / 146**, and `counts.py --check`
**passed**. The pair was quoted in `README.md` and in the extended page and asserted by **no gate at all** — the exact
class M332 found eight of, now found in the number the repository exists to state.

Fixed both ways: the sentence is gated against the fixture the two exporters already read, so it cannot drift again.

```
("README.md", r"\*\*(\d+) functions reconstructed in C and recompiled \u2014 (\d+) of them matching",
 ("recovered", "recovered_exact"), 1)
```

and `_recovered()` derives both numbers from `fixtures/decomp/recovered.json` — the same fixture `export_src.py` and
`export_ranges.py` read, so the front page, the published bodies and the coverage fixture cannot disagree.

**The two case-counts ripple, together this time**: eight new family probe cases (118 → 126) and one new counts case
(25 → 26) → **1 108 → 1 117 cases**, runnable 301 → 302, gated 807 → 815, quoted in five files. `ratchet.py --write`
re-baselines the registry **and** `src/`, which is the sanctioned route for a milestone that legitimately changes both
(the ratchet's rule is "any change needs `--write`, which is a diff", not "`src/` never moves").

## 4. What is left in the census

37 complete groups are now **29** (eight banked), holding **65 functions**: five groups of 3 (13, 20, 21, 32 words and
one 25), and 24 pairs from 11 words up to 146. The next-cheapest is the 11-word loop at `0x801630bc` (7/11, one
register), and the largest single prize left is the 146-word pair — which is 146 words of *structural* work, not a
cohort shortcut.

## Numbers

- **recovered 130 → 147, byte-exact 129 → 146**; 17 functions from 8 reconstructions of one shape
- compile probe **118 → 126 cases (126/126)**; counts **25 → 26 (26/26)**; tree **74 suites / 1 117 cases**
  (302 runnable, 815 gated); **tools 101**; markers 25
- `src/` grew 17 published reconstructions with their extents, body hashes and probe text; `code_index`,
  `analysis_status`, `call_graph` and the ranges fixture regenerated; ratchet re-baselined (registry + `src/`)
- 4 bodies drafted and measured for the residue: 7/11, 9/12, 7/18 and one shape-not-matched — the remaining cohorts
  start at 11 words and stop at the allocation wall
- The headline pair is now a **gated** claim, derived from `fixtures/decomp/recovered.json`
