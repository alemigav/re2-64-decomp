# M318 — `volatile` answered, and the 5-word sample: 6 of 8

Two things, in the order asked: the cheap test the last batch set up, then the sample.

## 1. `volatile` was right; the residue is scheduling

The hypothesis from M317 was that the hardware-register accesses failed because the drafts used
`*(volatile u32 *)ADDR`, and volatile pins an access in place. **Tested, and the hypothesis is inverted**: without
`volatile` gcc *folds the offset into the displacement* —

```
image    lui v0,0xa460 ; ori v0,v0,0x10 ; jr ra ; lw v0,0(v0)
volatile lui v0,0xa460 ; ori v0,v0,0x10 ; lw v0,0(v0) ; jr ra     ← right addressing, wrong order
plain    lui v0,0xa460 ; lw v0,0x10(v0) ; jr ra ; nop             ← wrong addressing too
```

So the qualifier is what produces the image's **address materialisation** (`ori` then a zero displacement), and only
the *order* is wrong. The four remain residues of the M309–M311 scheduling family — and this batch shows the family
runs **both ways**: for `stage2:0x80026820` the image keeps the store before `jr ra` with a `nop` in the slot, while
we sink it. Sinking is not a property of our compiler, it is per-function.

## 2. The 5-word sample: 6 of 8

| shape | site |
|---|---|
| `u8 *p = D_800E9174; *(u16 *)(p+214) = b; *(u8 *)(p+200) = a;` | `stage2:0x800274e4` |
| `D_800EA270 = 0; return 1000000;` | `stage2:0x8002fcd8` |
| `*(u32 *)(p+8) = a; *(u16 *)(p+12) = b;` (same base) | `stage2:0x80052bbc` |
| `D_8012BD84 = D_8010B6F0;` | `stage2:0x8008af6c` |
| two zero words into adjacent globals | `stage2:0x800aaf70` |
| four `u16` stores of one value at 300/302/310/312 | `ovl_0087352:0x80166294` |

The two misses:

- **`boot:0x80001180`** — `return 0x80012150 + (i << 4)`. The image computes the **shift first** and then materialises
  the base; we materialise first. Both compute the same address. This is the one miss where a *better* source is
  obvious and untried: `(i << 4)` with a stride of 16 is an **array of 16-byte records**, i.e.
  `return (u32)&D_80012150[i];` with a 4-word struct. Not spent under the one-draft rule, and worth one try if this
  address comes up again.
- **`stage2:0x80026820`** — the store-sunk-vs-not case above, scheduling.

Note the **reusable idiom** that made three of the six land first time: for a global with several field offsets,
`u8 *p = D_ADDR;` then `*(T *)(p + off) = …` keeps the base materialised once and the offsets as displacements,
which is what the image does. Folding the offset into a symbol reference (`D_ADDR + off`) does not.

## Rate, all singles

| set | drafts | landed |
|---|---|---|
| 3-word | 16 | 16 |
| 4-word | 17 | 9 |
| 5-word | 8 | 6 |
| total | 41 | **31** |

## Numbers

- **recovered 103 → 109**, byte-exact **102 → 108**
- compile probe **89 → 95 cases** (95/95 pass); tree **73 suites / 1 070 cases** (784 need the cartridge)
- `SINGLES` carries 31 entries; registration stayed data-only
