# M370 — the larger entries: strlen, memcpy, and a two-call combiner

M368 concluded from a 3-of-31 yield that **the small end of the rung is mostly not C** and the reading value is in the
larger entries. This batch tests that on 8 bodies of 9–12 words, and the conclusion holds: **5 closed on the first
pass, and 7 of 8 after one fix each**.

## 1. What was read

```c
u32 FUN_8000de78(u8 *a0)                       u8 *FUN_8000de9c(u8 *a0, u8 *a1, u32 a2)
{                                              {
    u8 *p = a0;                                    u8 *p = a0;

    if (*p != 0) {                                 if (a2 != 0) {
        do {                                           do {
            p++;                                           *p = *a1;
        } while (*p != 0);                                 a1++; a2--; p++;
    }                                                  } while (a2 != 0);
                                                   }
    return p - a0;
}                                                  return a0;
                                               }
```

**`strlen` and `memcpy`**, in the boot image, at 9 and 10 words. They are the first functions in this corpus whose
*names* are obvious from their shape rather than from a caller — a string walk that returns the distance, and a copy
loop that counts down. They join `osCreateMesgQueue` and `osSetEventMesg` as runtime code that the reference can name.

Three more: a four-store setter whose four stores all write the same argument (`0x800013b0`), a call wrapper that
re-shuffles its own arguments to pass `14` third (`0x8000319c`), and a delta-accumulator that clamps a counter to
`0x8000` and returns the delta (`0x800048b0`).

## 2. The two that needed one fix each, and the fix was the same shape

`0x8017b98c` and `0x8017b9bc` call a function **twice** and combine the results — `(a << 8) | b`, and the same with
`<< 16` calling the first. Both were **10 of 12** with `b << 8`, and the two differing words were the shift and the `or`:
the image shifts the **first** result, not the second.

That is not an allocation decision, it is the *order of the operands in the return expression* — M355's OR-chain lesson
(where a value sits in a left-associative chain decides which register accumulates it) appearing in arithmetic instead of
masking. Two drafts, one line each.

## 3. The one that did not close, and why it is worth naming

`0x80004a20` (and its two identical twins at `0x80004be4`, `0x80004c6c` — a **three-copy cohort**) computes an address
as `0x800C76B0 + 0x18000 + 6748`, and the image keeps the `0x18000` in a register of its own. Written as one literal the
compiler folds the two constants and emits a different pair; written as a symbol plus offset it folds them the other way.
This is the `ori`-vs-`addiu` family M368 recorded, in its address-arithmetic form: **the original source had two addends
the compiler could not fold together**, and until the spelling is found the body stays on the rung. Three drafts, all
recorded, none wasted.

## 4. What M369 changed about the queue

The rung went **198 → 392** when the imported corpus was removed, because 194 reconstructions became listings. That is
the honest shape of the queue now: **385 entries**, of which the 194 returned ones are bodies whose *extent* was already
verified by a reconstruction that has since been withdrawn — they are the cheapest to read, because the extent is known
to be right and only the C has to be re-derived from the words.

## Numbers

- **+7 read** onto F1 (`0x800013b0`, `0x8000de78`, `0x8000de9c`, `0x8000319c`, `0x800048b0`, `0x8017b98c`, `0x8017b9bc`)
- rung **392 → 385**; probe **222 → 229/229**; `strlen` and `memcpy` now have names in the corpus
- `F1` **3 453 → 3 454**, recovered **200 → 207 / 206 exact**, census 3 665, coverage 63.3 %
- one body left open with a named cause (`0x80004a20` + its two twins, three drafts)
- tree **1 277 → 1 284 cases**; `verify.py --full` **PASS**, audit 160/160
