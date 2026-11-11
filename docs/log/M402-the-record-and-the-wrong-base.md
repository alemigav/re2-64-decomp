# M402 — `0x800b43a0`: the base was wrong by `0x10000`, and the stride is a struct

Six loop-shape mechanisms were spent on this body between M392 and M400, and each was measured against a base address
that does not exist. The instrument that worked on `0x80073e38` — **read the words whole, then mirror what they say** —
had never been pointed at this body. Two findings fall out of pointing it.

## `lui $v0,0x8016; addiu $a1,$v0,0x8b20` sign-extends

`addiu`'s immediate is signed, so `0x8b20` is `-0x74E0` and the base is **`0x80158B20`**, not `0x80168B20`. Every draft
since M392 was compiled against an address `0x10000` too high. It is the same class of mistake as M396d's (a diff read
from the wrong end): the disassembly was read as arithmetic on paper rather than as the hardware's arithmetic.

## The two displacements are a record, not a stride

`slot` at `4608`, `key` at `4644`, stride `4648` — and `4608 + 1 + 35 + 4 = 4648` **exactly**. Typed as an array of
records, with the loop walking `Rec *p` and only the post-loop lookup indexing `D_80158b20[found]`, the body goes
**8 → 18 of 38**, and the multiply chain at words 24–33 matches for the first time because gcc emits struct-typed index
arithmetic.

```c
typedef struct { u8 pad0[4608]; u8 slot; u8 gap[35]; u32 key; } Rec;   /* 0x1228 bytes */
```

The image's own shape says the same thing twice over: the loop **walks** (`addiu a1,a1,0x1228` in the back-edge delay,
reads at `4608(a1)` and `4644(a1)`) while the lookup **multiplies**. Two access forms for one array is what a
struct-typed pointer and a struct-typed index look like, not what a byte stride looks like.

## The remaining 20 words are one allocation decision

The image keeps the **index in `$a0`** and the **record pointer in `$a1` at the record base**. Ours keeps the key in
`$a0` (it stays live for the loop's compare), puts the index in `$a1`, and **rebases** the pointer to `+0x1224`, so
`slot` becomes `-36($v1)` and `key` becomes `0($v1)` — which is also why the draft compiles to 40 words against the
image's 38.

The pivot is the compare: the image tests the loaded key against `$a2`, the **result** variable (`beql $v0,$a2`), not
the argument. Writing it that way does produce the image's register story — and costs the draft the copy at word 3,
because gcc then coalesces `found = want` away: **18 → 4**. The draft has to keep the copy *and* free `$a0` at once, and
that is a coalescing decision rather than a source one.

`partials.py --check` re-derives **18 of 38**.
