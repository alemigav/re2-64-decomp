# M364 — the rung audited: 101 of 241 entries are not functions, and 9 more read

M363 found that eleven of the 85 admitted bodies were fragments. This milestone applied the same test to **the whole
rung** — the 241 entries `measured_extents.json` carries, most of them inherited from M341 — and the answer is a
correction, not a reading.

> **101 of 241 rung entries are not functions.** 44 have a `j`/`jal` inside the body (a tail call the scanner ran
> through, so two functions are glued together), 27 have a conditional branch **past the end**, 3 branch to themselves,
> 2 are bare epilogues (`lw ra,…; jr ra: addiu sp,sp,N` with no matching save), and 10 are the empty function that M354
> had **already registered** from `STUB_SOURCE`. The rung goes 241 → 140, then → 119 after nine were read and one more
> proved unreadable.

## 1. The four tests, and why each is the rung's own rule turned inward

`extent_scan` measures a body as *the words between `jr $ra` pairs*. Each of these asks whether the result can be a
function at all:

| test | fails | what it catches |
| --- | --- | --- |
| a conditional branch whose target leaves the body | 27 | the extent cut a function in half — `0x800a2424` is six words ending `jr ra` with `bne` at word 2 targeting word 6 |
| a `j`/`jal` before the final return | 44 | a **tail call**: the function ends there without a `jr ra`, so the scanner ran on into the next function and glued the two together |
| a branch to itself | 3 | `b .` — the hand-written idiom M315's screen already refuses |
| an epilogue with no prologue | 2 | `lw ra,64(sp) … jr ra; addiu sp,sp,72` — the tail of a function whose head is somewhere else |
| already registered as the empty function | 10 | `jr ra; nop` at addresses M354 banked from `STUB_SOURCE` — a **duplicate**, which is drift between two fixtures |

The last one is the one that could not have been found by looking at bytes alone: the same address was counted on F1 *and*
on the rung. Two fixtures naming the same function is exactly the drift M205/M210 chased, one layer up.

## 2. What was read

Nine of a fifteen-draft tranche came back byte-exact and are now on F1 — counter bumpers, a copy of three words, a
conditional store, a pointer walk:

```c
u32 FUN_8006dd7c(u8 *a0)                    void FUN_80036c44(u8 *a0, u32 a1)
{                                           {
    u8 *p = a0 + *(s8 *)(a0 + 2);               if ((*(u32 *)(a0 + 4) & 0xffffff00u)
                                                    != (a1 & 0xffffff00u))
    p[8] = p[8] + 1;                                a0[488] = 255;
    *(u32 *)(a0 + 28) += 1;                 }
    return 1;
}
```

The six that did not are informative rather than wasted: **three have the wrong extent** (one includes a leading `nop`
that belongs to alignment, two give a `lui`+`addiu` pair whose sum lands outside the byte range), **one is MIPS III** —
`0x8004249c` ends with `daddu v0,a1,zero`, a 64-bit operation this profile cannot emit (the D64 family M321 identified),
so it is a real function that is not C-compilable here, and **two were simple mistakes** of the same sign-extension kind
M363 recorded. Only the first and last are worth another draft; the MIPS III one is refused with a reason, not retried.

## 3. State, and what it says about M341

| | before | after |
| --- | --- | --- |
| rung `extent_measured` | 228 | **119** |
| census `F0` | 3 679 | **3 578** |
| **`F1`** | 3 451 | **3 459** |
| recovered / exact | 383 / 382 | **391 / 390** |
| covered bytes | 1 241 400 | **1 223 008** |
| coverage | 63.4 % | **62.5 %** |

Coverage **fell by 18 392 B** and the census by 101, and both are corrections: those bytes are not function bodies, they
are the halves of split functions, epilogues and duplicates that a byte rule could not tell from code. M341 adopted 187
measured extents in good faith on a rule that measures *runs between returns*; this milestone is the audit of that
adoption, and the honest headline is that **the rung was over-counted by 84 %** (101 of 241) — with the read ones
(the 9 of this milestone and the 21 of M363) being the only entries that were ever really functions of this corpus.

The ladder keeps the distinction: **F1 rose by 8** while the census fell by 101, because reading and admitting are
different acts and only one of them is evidence.

## 4. What is left

**119 entries remain on the rung.** Of the ones examined here, the disposition is known for 101 (withdrawn) and 30 (read
or refused), and the rest are mostly 9–209 words with the same shapes — readable in batches. The three classes that will
not read as they stand, and what each needs:

- **44 glued pairs** — split at the tail call; each becomes two functions, one of them probably readable,
- **27 + 2 mis-extented** — re-measured around the branch or the epilogue,
- **1 MIPS III body** (`0x8004249c`) — a refusal to record, since this profile cannot emit `daddu`.

## Numbers

- **rung 241 → 119**: 101 withdrawn as not-functions (27+44+3+2 tests, plus 10 duplicates of `STUB_SOURCE`), 9 read onto
  F1, 1 refused as MIPS III, 2 mis-extented
- `F1` **3 451 → 3 459**; recovered **383 → 391 / 390 exact**; census **3 679 → 3 578**; covered **−18 392 B (62.5 %)**
- probe **352 → 360/360**; tree **1 404 → 1 412 cases**; `verify.py --full` **PASS**, audit 160/160
