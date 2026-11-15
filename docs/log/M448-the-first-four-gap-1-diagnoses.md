# M448 — the first four gap-1 diagnoses: two closed, one scheduling wall, one argument-packing residual

The 19 bodies one aligned word from exact, smallest first, **one diagnosis before any edit**. Four were diagnosed in
this milestone; two closed, and the two that did not have a named cause rather than a shrug.

## The two closures

### `stage2:0x8008456c` — 4 words → **4 of 4**

The image materialises the address once and reuses the register it just stored:

```
lui v0,0x8012 ; addiu v0,v0,-14044 ; jr ra ; sw v0,0x7800(v0)
```

`0x8011C924 + 0x7800 = 0x80124124`, so the store target is a **displacement of the source symbol**, not a second
symbol. Ghidra wrote `DAT_80124124 = &DAT_8011c924`, which costs an extra `lui` (ours emitted five words for a
four-word function). Binding the address to a local and reusing it reproduces the image exactly:

```c
unsigned int p;
p = (unsigned int)&DAT_8011c924;
*(unsigned int *)(p + 0x7800) = p;
```

Three other spellings were tried first and all failed — `(char *)&sym + 0x7800` (1 of 4 aligned), an array subscript
(1 of 4), cast-to-int without a temp (2 of 4). **The local binding is what makes gcc keep one register.**

### `stage2:0x8004a7c8` — 11 words → **11 of 11**

The image ORs `0x200` into the **fourth argument in place**, between the shift and the combining `or`:

```
sll a2,zero,4 ; ori a3,a3,512 ; or a2,a2,a3
```

Ghidra's `param_3 << 4 | param_4 | 0x200` is wrong twice: it folds 512 into the *third* argument, and it loses the
in-place update of `param_4`. Parenthesising to `param_3 << 4 | (param_4 | 0x200)` reaches 10 of 11; the last word
needs the evaluation order forced, which naming the shift and hoisting the OR does:

```c
unsigned int t;
t = param_3 << 4;
param_4 = param_4 | 0x200;
FUN_8004a7f4(param_1, param_2, t | param_4, &param_5);
```

Hoisting alone regressed to 9 of 11 — it moved `ori` *above* the shift. Two named temporaries also close it, so what
matters is the statement boundary, not the names.

## The two refusals, with causes

### `boot:0x800048e8` — 9 words, **scheduling**

Only the `mult` moves: the image has `frame ; sw ra ; mult a1,a2 ; mflo` and we emit `mult` **first** — gcc hoists it
above the prologue to fill the latency. Measured: **`-fno-schedule-insns2` reproduces the image word for word**
(`27bdffe8 afbf0010 00a60018 00002012`), and no C variant tried (a named temp, casts, unsigned operands) changes it.

That flag cannot become the profile: M440 measured it keeps **40 of 120** already-exact bodies. So this body is a
**scheduling class** — a real, named difference that the pinned compiler cannot express. It is the first residue this
arc has found whose cause is the *scheduler* rather than the source or the allocator.

### `stage2:0x80047824` — 12 words, **argument packing**, narrowed

The image reads the 5th stack argument as `lhu $v0,18($sp)` — a halfword at **+0x12**, i.e. the second of two 2-byte
values sharing the word at `+0x10`. A `struct { unsigned short a, b; }` by value reorders the whole body (0 of 12); a
plain `unsigned short` gives `lhu +0x10`; **two shorts give `lhu +0x16`** — one 2-byte slot too far. The residual is a
packing question, not a semantics one, and it is one slot wide.

## Numbers

- 4 of the 19 diagnosed, **2 closed**, 1 scheduling wall, 1 narrowed to one slot
- `recovered` **669 → 671**, byte-exact **668 → 670** (18.3 %)
- probe **691 → 693 of 693**; tree 95 suites / **1840** cases
- both closures banked `provenance: provider` with probe strings naming the mechanism, the failed spellings and why
