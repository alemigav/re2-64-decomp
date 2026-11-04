# M337 — the 13-word call-and-add pair, and the glide that says there is nothing left to glide on

The asked target was the last small body in the census: `0x8000d428`, thirteen words, two copies. It is banked. But the
directive that came with it — *fly a little and plane all the way down* — turned out to answer a bigger question than
the pair did, and the answer is a map: **the cohort stock has no families left in it.**

## 1. The pair: it was never a dispatcher

M335 listed it as "shape-not-matched" because it is also thirteen words. It is not the dispatcher at all — read from the
words:

```
addiu $sp,$sp,-32     sw $s1,20($sp)     addu $s1,$a0,zero    sw $s0,16($sp)   sw $ra,24($sp)
jal FUN_8000de9c      addu $s0,$a2,zero  (slot)               addu $v0,$s1,$s0
lw $ra,24($sp)        lw $s1,20($sp)     lw $s0,16($sp)       jr $ra           addiu $sp,$sp,32
```

The callee takes the incoming arguments **unchanged** — so the only reason `$a0` and `$a2` are saved at all is that they
are needed *after* the call, and the `jal`'s delay slot is the save of `$a2`:

```c
u32 FUN_call13(u32 a0, u32 a1, u32 a2)
{
    FUN_8000de9c(a0, a1, a2);

    return a0 + a2;
}
```

**13 of 13, byte-exact**, both copies (`boot:0x8000d428`, `stage2:0x8008225c`) — registered as `CALL13_SOURCE`. The
shape that made it look like a dispatcher was the argument-register reuse in the prologue, which is what every
three-argument wrapper with a live-across-call value looks like.

## 2. The glide: 59 functions, 26 bodies, **26 shapes**

The directive's danger was the one thing this arc keeps re-learning: climbing once per byte-group is expensive, and M335
had climbed eight times for one shape. So the flight was to **normalise every remaining cohort body to a shape
signature** — mnemonic plus operand *roles*, with every immediate and register number masked out — and cluster on that
instead of on the body hash.

```
remaining cohort functions: 59 in 26 byte-groups, but only 26 SHAPES
```

**The byte census and the shape census now agree.** Every one of the 26 body shapes is its own shape: no two groups are
the same instruction sequence with different constants. The dispatcher's eight were the last family, which means:

- **there is no multiplier left** — every remaining function needs its own reconstruction, and the cohort mechanic
  ("one proof registers every copy") now buys exactly its own two, three or four copies and nothing more;
- the census's remaining stock is ordered by *work*, and the smallest entries are 13–21 words: this pair (done), a
  20-word masked loop (3 copies), a 21-word shifted-store call (3), a 25-word read-modify-write (4), a 32-word
  bit-tracker (3) — then twenty pairs from 20 to 146 words.

That is the plane's whole yield: not a template, but the knowledge that there is none, measured once instead of
suspected 26 times.

## 3. What the flight also drafted, and what it cost

The 20-word masked loop (`0x80162f08`, 3 copies) was drafted four ways in the same pass:

| draft | score | what it missed |
| --- | --- | --- |
| pointer read, byte-offset store | **12 of 20** | the OR chain's destination register, and the store address |
| `if (n)` guard added | 0 of 20 | the guard is what `for (i = 0; i < n; i++)` already emits — the explicit test doubled it |
| `w` hoisted out of the loop | 7 of 20 | gcc already hoists it; hoisting by hand moved the preheader/loop split |
| `v[24]` word index, byte step, word step | 12 of 20 | **the address fold survives every pointer spelling** |

Our version materialises `v + 96` into a register (`addiu $v1,$a0,0x0060`) where the image uses the displacement
(`lw $v0,96($v1)`) — and it keeps the loop-invariant OR in `$a3` where the image keeps it in `$a2`. Both are the
allocation class M334 measured: no flag in 25 moves them, and the corpus requires the profile that produces them. So the
body is **not registered** and is published at 12 of 20 with both causes named.

## 4. State

- **recovered 153 → 155, byte-exact 152 → 154**; 2 functions from one 13-word shape
- compile probe **129 → 130 cases (130/130)**; tree **74 suites / 1 121 cases** (302 runnable, 819 gated)
- census after this milestone: **24 complete groups / 57 functions**, from 20 words upward, with **24 distinct shapes**
- the 20-word loop is the best-measured residue in the stock: 12 of 20, one allocation decision away in two places,
  and drafted four ways so the next attempt starts from the shape that came closest

## Numbers

- **+2 functions** (`CALL13_SOURCE`, 13 words, `boot` + `stage2`), one reconstruction, **13 of 13**
- **The glide's measurement: 26 shapes for 59 functions** — the cohort family count is now zero
- 4 drafts for the 20-word residue, best **12 of 20**, causes named (address fold, OR destination)
- The gated headline caught the change on the first `counts.py --check`, as designed
