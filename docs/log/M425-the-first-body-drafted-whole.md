# M425 — the first body drafted whole: 54 words, and what it taught

The 19 `blez` bodies are not residues — their gaps run 50 to 444 words, which means the provider's C for them is
structurally wrong. Drafting one means reading the image and writing the function. This is the first, and it closed at
**54 of 54**.

## The body: `ovl_00ae24a:0x80162484`

Read off the words, the shape is a **guard chain** — six conditions, each branching straight to the epilogue — over the
same `0x800C76B0 + 0x18000` record that M396c spent a milestone on:

```c
s0 = (u8 *)((u32)D_800c76b0 + 0x18000);
s2 = *(u32 *)(s1 + 652);
r  = func_80032e74(s1, *(u32 *)(s0 + 6824), *(u32 *)(s0 + 6832), 0x80);

if (*(s32 *)(s1 + 40) < 0x2329) return;
if (s2 >= 0x1770) return;
if ((r << 16) != 0) return;
if (*(u8 *)(s0 + 7407) != 0) return;
if (*(s16 *)(s0 + 7282) > 0) return;
if (*(u16 *)(s1 + 706) & 4) return;

*(u32 *)(s1 + 4) = 0x01040000;
func_80059e00(0x1f4, 0);
*(u8 *)(s0 + 7407) |= 0x80;
*(u8 *)(s1 + 692) = 4;
*(u8 *)(s1 + 693) = 0;
*(u32 *)(s0 + 6716) |= 0x100;
```

Drafting it took **29 of 54** on the first read and 54 on the second, and the second pass fixed exactly three things:

| what the diff said | the fix |
| --- | --- |
| `slti` vs `sltiu` at word 17 | the comparison is **signed**: `*(s32 *)(s1+40) < 0x2329`, not `*(u32 *)` — the `blez` lesson again |
| `jal` vs `addu` at 37, everything after shifting by one | the call takes **two** arguments, not three; the constant is a separate store to `s1+4` |
| that store's position | it stays *before* the call in source; gcc then puts it in the delay slot |

**The signedness defect is now the third instance of one class**: a declaration decides an opcode the source cannot
express (`slti`/`sltiu` here, `blez`/`beq` in M424, `lw`/`lbu` in M420). In a drafted body it costs one word and a
one-word shift of everything after it; in a *pass* it costs the whole pass.

## The family it belongs to

Three of the 19 share a six-word prologue and all call `0x800a5678` — the twin of the function M424 closed:

```
0x800acd1c  64w   addiu sp; sw s0; sw ra; jal 0x800a5678; addu s0,a0,zero; lui v0,0x8015
0x800acfa8  70w   same six words
0x800ad230  64w   same six words
```

They are a search-and-decrement family over the table at `0x801521F0`: find an entry by a 16-bit key, decrement its
refcount, and shift the tail down when it reaches zero. **One of them drafted properly gives the other two a template** —
which is the reason to read `0x800acd1c` first rather than treat the 19 as 19 independent bodies.

## The re-measured queue

| | bodies |
| --- | --- |
| map: byte-exact | 467 |
| near band (≤ 8 words) | **268** (15 / 81 / 82 / 90 at 1 / 2 / 4 / 8) |
| mid band | 463 |
| far mass | 2 187 |

**648 → 649 of 3 664 (17.7 %)**, 672 probe cases, `--full` PASS.

The honest rate: one 54-word body, read and drafted, per working session — and the first read reached 29 of 54, so the
reading is the cheap half and the *corrections* are what cost. Two of the three corrections were type declarations,
which is the same lever the last four milestones kept finding.
