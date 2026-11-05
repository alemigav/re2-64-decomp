# M354 — the empty-function shape: ten copies for one proven reconstruction

The cohort stock is **32 complete groups / 83 functions** (12 532 B) after the byte-map arc, and the instruction was *one
shape at a time*. The first shape is the cheapest and the most honest: **ten copies of `jr ra; nop`** — the body
`STUB_SOURCE` has proven since M307, which needed **no drafting at all**.

## What was done

Ten addresses across `stage2` (nine) and `ovl_009dd02` (one), each verified byte-for-byte as
`03e00008 00000000` **before** the fixture was touched, then registered against the existing source:

```
0x800341ec  0x80036ed0  0x8006e684  0x8007230c  0x80072354
0x8007a3d8  0x8007c714  0x8007c71c  0x8007cce4   ovl_009dd02:0x801665b8
```

and the family case went from 34 to **44 of 44**:

```
PASS STUB_SOURCE, 2 words: all 44 copies of the identical body are BYTE-EXACT from one reconstruction (44 of 44)
```

That is the cohort mechanic working exactly as designed — one proven shape, N registrations, and the gate asserts every
copy rather than the one that was checked.

**One group in the same size class was refused**: three 2-word bodies at `stage2:0x8001f3a8`/`0x80020738`/`0x800218c8`
are `jr ra` with a **`mtc0`** in the delay slot. CP0 writes are not C-emittable (M323), so they are *not* the empty
function despite being the same length, and the leaf screen's CP0 rule already refuses them. Length is not shape.

## Measured

```
recovered 155 -> 165          byte-exact 154 -> 164
F1 3 411 -> 3 421             F2 3 343 -> 3 353
rung extent_measured 192 -> 182
```

The last line is the interesting one: **the ten were already in the census as measured extents** (part of M341's 187
listings) and their bodies happened to be `jr ra; nop`. Registering them moves them from the *measured* rung — extent
known, body a listing — to **`recovered`**: the body is now a reconstruction that compiles to the image's own bytes. Ten
functions graduated, and the composition ledger moved with them: **16 hand + 55 singles + 94 copies = 165**.

## The phase table, immediately

`P19` said **M332–M352** an hour ago; M353 was itself outside it, and this milestone would have been too. The row now
reads **M332–M354** and the record panel was regenerated in the same edit — the lesson M353 recorded (*extend the row in
the milestone that opens an arc*) applied to the milestone that follows it.

## Numbers

- **+10 functions** from one already-proven shape; 44/44 copies byte-exact; corpus **165 / 164**
- ladder **F0 3 603 / F1 3 421 / F2 3 353**, rung `extent_measured` **182**
- three CP0-bodied same-size copies refused, with the reason (length is not shape)
- `unclassified` **440 B (0.0 %)**, **15 classes**, coverage **63.2 %** — all unchanged
- `verify.py --full` **PASS**, audit 160/160
