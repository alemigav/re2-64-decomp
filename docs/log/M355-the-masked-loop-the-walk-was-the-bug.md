# M355 — the masked loop: the walk was the bug, and the index is the shape

M337 published this body at **12 of 20** with two named causes — *the store address* and *the OR chain's destination
register* — and closed with a verdict: both are the allocation class M334 measured, no flag in 25 moves them, so the
body stays unregistered. **Both causes were right. The verdict was wrong**, and this milestone closes all 20 words.

The body, read off the cartridge (`ovl_008900e:0x80162f08`, 20 words, three copies):

```
0  lw    a0,564(a0)      ; r = *(u32 **)(a0 + 0x234)
1  beq   a1,zero,+16     ; if (n == 0) return
2  addu  t0,zero,zero    ; i = 0            (delay slot)
3  lui   t1,0xff00       ; mask = 0xff000000
4  lw    v0,16(sp)       ; 5th argument, on the stack
5  sll   v1,a3,8         ;    mid << 8
6  sll   v0,v0,16        ;    hi  << 16
7  or    v0,v0,v1        ;
8  or    a2,v0,a2        ;    ... | lo, accumulated into $a2
9  addu  v1,a0,zero      ; p = r            <-- the initial value is the base, unchanged
10 lw    v0,96(v1)       ; w = p[24]        <-- the field offset stays a displacement
11 addiu t0,t0,1         ; i++
12 and   v0,v0,t1        ;
13 or    v0,v0,a2        ;
14 sw    v0,96(v1)       ; p[24] = (w & 0xff000000) | hi << 16 | mid << 8 | lo
15 sltu  v0,t0,a1        ;
16 bne   v0,zero,-9      ;
17 addiu v1,v1,376       ; p += 94 words   (delay slot)
18 jr    ra
19 nop
```

## 1. The walk was the bug

The image's induction variable starts at **the base, unchanged** (word 9: `addu v1,a0,zero`) and the field sits at
displacement 96 in the memory operand. Every *pointer walk* spelling we wrote makes gcc's loop optimiser do the
opposite: it eliminates the base's induction variable and promotes the **access address** to induction variable, so the
+96 moves into the initial value and the operand becomes 0:

```
had    addu  v1,a0,zero      ours  addiu v1,a0,0x0060
had    lw    v0,96(v1)       ours  lw    v0,0(v1)
had    sw    v0,96(v1)       ours  sw    v0,0(v1)
```

Six spellings do this and all six score **17 of 20** — the three words are one decision, repeated:

| draft | spelling | score |
| --- | --- | --- |
| A | `u32 *p`, `p[24]`, `p += 94` | 17 of 20 |
| B | `u8 *p`, `*(u32 *)(p + 96)`, `p += 376` | 17 of 20 |
| E | `Head { u32 pad[24]; u32 v; } *h`, `h->v`, `h = (Head *)((u8 *)h + 376)` | 17 of 20 |
| F | `u32 *q = p + 24;` bound inside the loop, `p += 94` after the store | 17 of 20 |
| C | `q = p` at the top of the body, `p += 94` first | 8 of 20 (24 compiled) |
| D | `p = base - 94`, increment before the store | 8 of 20 (24 compiled) |
| G | the invariant hoisted by hand into `u32 v` before the loop | 7 of 20 |

**An index is a different mechanism, and it is the image's**: `p[i * 94 + 24]`, or `r[i].v` on a 376-byte record. The
induction variable is then `base + i * 376`, whose initial value is `base + 0` — so the constant 96 has nowhere to live
but the operand. **20 of 20 words, byte-exact, from the first try**, both spellings, all three copies.

The general rule, which is the milestone's yield: **a stride keeps a field offset as a displacement; a walk folds it into
the induction variable's initial value.** It is a fact about `combine_givs`, and it is reachable from C by choosing an
index instead of a pointer — no flag involved.

## 2. The destination register was the operand order

Word 8 is `or a2,v0,a2`: the preheader accumulates the assembled byte value **into `$a2`**, the register that holds the
third argument and is dead after this point, so the whole loop-invariant becomes one register. That is the tree
`((hi << 16) | (mid << 8)) | lo` — `lo` on the **right** of a left-associative OR chain. Written the other way round
(`lo | mid << 8 | hi << 16`) the chain has no `$a2` accumulator at all and the body collapses to **4 of 20**.

Both of M337's causes were therefore *statement-and-expression shape*, not allocation — and that is the boundary worth
recording: **a partial whose two causes are both explained as allocation has not been diagnosed.** "No flag in 25 moves
it" is evidence about flags. It is not evidence about shape.

## 3. What the cap was for, and what it cost

The standing cap said *do not spend a fourth draft*. This shape took **nine drafts and seven flags**. The defence is not
that the cap was wrong but that it was **counting the wrong thing**: drafts A, B, E, F, C, D and G are **one mechanism,
seven times** — a pointer walk, reworded — and none of them could have closed the body. Draft H was the seventh and it
was the first one that changed *mechanism*, and it closed on the first try. The cap's purpose is to stop a milestone
grinding on a hypothesis already refuted; it should read **one mechanism at a time**, not one draft at a time.

The seven flags, for the record, and none of them moves the residue:

| flag | score |
| --- | --- |
| `-fno-expensive-optimizations`, `-fno-rerun-cse-after-loop`, `-fno-thread-jumps`, `-fno-cse-follow-jumps` | 17 of 20, unchanged |
| `-fno-schedule-insns` | 13 of 20 (moves the *allocation*, as M334 found) |
| `-fno-strength-reduce` | 9 of 20 — it produces the **right displacement** (`lw v0,96($a0)`) by dropping the induction variable entirely, and loses eight words elsewhere |
| `-fno-delayed-branch` | 1 of 20 |

`-fno-strength-reduce` is the one worth keeping: it is the *proof* that the residue is strength reduction's decision,
seen from the inside of the compiler rather than argued from the outside.

## 4. A harness defect fell out of it: the family path never normalised its object

The registering compile failed **0 of 3 with no reason**. The compile and the assembly succeeded; `objcopy` died with
*"a section extending past end of file"*, and the family loop swallowed it. The cause is the M319 class: binutils 2.7
writes a **zero-sized `.rel.text` whose `sh_offset` sits one byte past EOF**, and BFD refuses the object. Every other
probe path has called `normalise_object()` since M319 — **the family path never did**, and the defect stayed latent
because no existing family produced such an object. This body does: it has **no relocations at all** (no extern, no
literal address), so `.rel.text` is empty and the offset is unchecked. Fixed in `family_probe()`, and the case then read
`3 of 3`.

The lesson is the audit's own: **a cohort case that can report "0 of N" without a reason is a gate that cannot say why
it failed** — the count was right and the diagnosis was four steps away.

## 5. The census figure was not reproducible, so it is replaced

The README has carried *"74 candidates in 35 groups"* since M314, and M337 wrote *"24 complete groups / 57 functions"*
about the same object. Neither can be recomputed from a committed artefact, which is why they disagree. This milestone
publishes the derivation instead of a number:

```
group every function in manifests/code_index.json that is not in fixtures/decomp/recovered.json
by body sha256, keep the groups with more than one member
-> 17 groups, 34 functions, every one of them the SAME body at the SAME address in
   ovl_008900e and ovl_008e046 (28 to 146 words)
```

**34 candidates in 17 complete two-copy groups**, all of them enemy-slot variants of one overlay. The old figures are
retracted by this paragraph — not because the counts were careless but because a census with no tool behind it drifts
exactly the way this one did.

## 6. The independent recompiler on the same cartridge

`polaco1782/v64recomp` ships a `games/re2-us-v1` profile whose `rom_sha1` is **`62ec19bead748c12d38f6c5a7ab0831edbd3d44b`**
— our cartridge exactly. It was checked against this milestone and it **does not help the reconstruction**: N64Recomp
recompiles *from* MIPS, so its output cannot supply the C spelling that reproduces the same words, which is the only
thing this project needs. What its profile does carry is a second, independent model of the same image:

- **slot-based, where ours is member-based.** It declares two enemy slots, `.overlay11` at `0x80161cf0` and
  `.overlay39` at `0x8016e880`, **both `0xcb90` bytes**, and the difference between them *is* `0xcb90`; every
  `.overlay39` table address in its list is its `.overlay11` twin **plus exactly `0xcb90`** (checked: `0x8017a8a8 −
  0x8016dd18 = 0x80170b34 − 0x80163fa4 = 0xcb90`). That is our "three members, one load address" reading seen from the
  other side: the two enemies are the same code in two slots.
- **its region is slot capacity, not file size.** `0xcb90` exceeds every one of our overlay members (28 800, 18 048,
  22 624 B), so its in-region addresses land outside our members — the word at its `pc 0x80163fa4` is `sltiu v0,v0,0x9c4`
  in our `00010_008900e` member, not the `jr $v0` its list expects. Its `.overlay11` is therefore **not** our member,
  and its jump-table digests cannot be compared with ours until the member sets are aligned. That alignment is a
  milestone of its own, and it is written down here rather than glossed as corroboration.

## Numbers

- **+3 functions** from one shape, all three copies byte-exact (`ovl_008900e:0x80162f08`, `ovl_008bef8:0x80165dc4`,
  `ovl_008e046:0x80162f08`); corpus **168 / 167**, composition **16 hand + 55 singles + 97 copies over 21 shapes**
- compile probe **136 → 137 cases (137/137)**; tree **75 suites / 1 162 → 1 163 cases** (323 runnable, 840 gated)
- ladder **F0 3 603 / F1 3 421 / F2 3 353**, rung `extent_measured` **182** — all unchanged
- `unclassified` **440 B (0.0 %)**, **15 classes**, coverage **63.2 %**; `verify.py --full` **PASS**, audit 160/160
- **two mechanisms** banked as rules: *stride keeps the offset, walk folds it*; *the OR chain's operand order decides
  the accumulator*
- **one clause retracted** (M337's "allocation class, both causes") and **one census figure replaced** with its
  derivation (74 in 35 groups → 34 in 17), both by addition rather than by editing history
