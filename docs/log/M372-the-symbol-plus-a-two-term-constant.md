# M372 — the three-copy cohort that needed two addends: symbol plus a constant, kept apart

M370 left `0x80004a20` open with a named cause — *"the original had two addends the compiler could not fold together"* —
and three drafts recorded. The fourth closes it, and its two identical twins with it.

## The body, and what it took

```
lui  a0,0x0001 / ori a0,0x8000      ; a0 = 0x00018000, materialised as a constant of its own
lui  v1,0x800c / addiu v1,v1,0x76b0 ; v1 = 0x800C76B0, the symbol
addu v1,v1,a0                       ; v1 = symbol + 0x18000
sw   zero,0x2884(v0)                ; D_80012884 = 0
lw   v0,6748(v1) ; andi… ; sw v0,6748(v1)
```

The first three words are the whole puzzle: the image keeps **the symbol's address and the `0x18000` in separate
registers** and adds them with `addu`. Every spelling that *initialised* a pointer with both — `u8 *t = D_800c76b0 +
0x18000` — folded them into one `lui`/`addiu` pair (`0x800E F6B0`), which is a different answer, not a worse one.

What closes it is leaving the two addends **in the access expression** and binding only the symbol:

```c
extern u8  D_800c76b0[];
extern u32 D_80012884;

void FUN_80004a20(void)
{
    u8 *t = D_800c76b0;

    D_80012884 = 0;
    *(u32 *)(t + 0x18000 + 6748) = *(u32 *)(t + 0x18000 + 6748) & ~0x20;
}
```

Then the compiler does what the image does: `lui`/`addiu` for the symbol, `lui`/`ori` for `0x18000` (it does not fit
16 bits), `addu`, and `6748` stays a **displacement** because it does. **Three terms, three places**: symbol to the
address pair, big constant to a register, small constant to the offset — and *which* term lands where is decided by the
magnitudes, so the source has to leave all three visible.

Twelve of twelve, and its twins at `0x80004be4` and `0x80004c6c` are the same twelve words, so the cohort mechanic
registers all three from one proof. The rung drops three, `F1` gains three.

## The rule, which is the fourth form of one rule

This project has now recorded the same thing four ways: a **statement's shape decides where a value is materialised**,
and the materialisation is what the bytes show.

| milestone | the lever |
| --- | --- |
| M336 | the counter **initialised before** the pointer read lands in `$a1` |
| M355 | an **index with a stride** keeps the field offset a displacement; a walk folds it into the initial value |
| M370 | the operand **order in a return expression** decides which register shifts and which accumulates |
| **M372** | a **big constant left out of a pointer's initialiser** is materialised separately; folded in, it disappears into the address |

Each was invisible until the alternative was written and measured, and each is a property of the C rather than of the
compiler's mood. That is now the most reusable thing this corpus has produced — more than any single function.

## Numbers

- **+3 functions** from one body (`0x80004a20`, `0x80004be4`, `0x80004c6c`), 12 words each, a three-copy cohort
- rung **385 → 382**; probe **229 → 232/232**; `F1` **3 454 → 3 457**, recovered **207 → 210 / 209 exact**
- the corpus build picks them up: **210 functions over 23 images**, 10 972 B
- `verify.py --full` **PASS**, audit 160/160; tree **1 285 → 1 288 cases**
