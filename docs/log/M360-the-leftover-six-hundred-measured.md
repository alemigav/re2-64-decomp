# M360 — the leftover 650, measured: they are mostly stubs, and the tail is a hole in *our* map

M358 and M359 banked the found bodies that landed exactly on one of our function starts at our size — 177 of them.
The rest were left alone, and "the rest" was the open question: were they functions we had mis-bounded, functions we had
missed, or nothing at all? This milestone answers it with a classification against **our own** occupancy and the bytes,
and the answer is not what the count suggested.

> Of 1 595 found bodies, **1 250 are two-word `jr ra; nop`** — the empty function, which matches at every site in every
> image. Of the 345 that are longer, 228 are bankable-or-banked, **461 shrink to 3**, 409 to **1**, and of the 354
> "unclaimed" only **5** are longer than five words. The measurement's real yield is not in their corpus at all: those
> five sit in a 142-word run our own byte map calls `enclosed_data`, and **three of that run's nine functions are not
> in our census**.

## 1. The classification, and what each bucket means

`tools/other_corpus.py --extent` recompiles each draft, finds its body anywhere in the cartridge, and asks our
`code_index` what that address is:

| bucket | n | ≥6 words | what it is |
| --- | --- | --- | --- |
| `at_start` | 298 | **228** | a function of ours, same size — the bankable class, of which 177 unique were banked in M358/M359 |
| `extent` | 461 | **3** | a function of ours, **different size** |
| `interior` | 409 | **1** | *inside* one of our functions — a block, not a function |
| `unclaimed_function` | 354 | **5** | nothing of ours covers it, and the bytes say it is a function |
| `unclaimed_other` | 73 | **0** | nothing of ours covers it, and the bytes do not |

The word-count column is the whole story. `extent` is 461 entries of which **455 are two words**; `interior` is 409 of
which **386 are two words**; `unclaimed_function` is 354 of which **343 are two words**. A two-word body is `jr ra` and
a delay slot, and those two words appear wherever any function returns — so a two-word "match" is as likely to be a
stray return in a table as a function, and the classifier refuses it for exactly that reason (`unclaimed_function`
requires a `jr ra` **before** the body as well as after it).

**Interior is a structural fact about their corpus, not a defect.** Their discovery splits at every `jr ra`; ours does
not. That is where 4 694 "functions" against our 3 603 mostly come from: a few hundred of theirs are blocks inside a
function we model as one body, sitting at offsets like `+1` and `+2` words.

## 2. The five that matter, and the run they live in

| image | address | words | our model |
| --- | --- | --- | --- |
| boot | `0x80004fb4` | **48** | inside `enclosed_data` `0x80004f80..0x800051b7`, **not claimed** |
| boot | `0x80005074` | **48** | same run, **not claimed** |
| boot | `0x8000de78` | 9 | our `gap` under 64 B |
| ovl_00b5346 | `0x80162ad4` | 14 | unclaimed |
| ovl_0093192 | `0x80162884` | 10 | unclaimed |

The first two are the finding. That run is **142 words**, and it is not one object — it is **nine functions**, delimited
by returns:

```
0x80004f80  2w   0x80004f88  2w   0x80004f90  2w   0x80004f98  2w
0x80004fa0  3w   0x80004fac  2w   0x80004fb4 48w   0x80005074 48w   0x80005134 33w
```

Our census claims the six small ones and **not the three large ones**. Our byte map classifies the whole run as
`enclosed_data` with the note *"bounded by function_body and function_body — the same structure, content unnamed"*,
which is the class being exactly right about the structure and exactly wrong about the kind: it is structured, and it
is code.

The evidence that `0x80004fb4` and `0x80005074` are functions is threefold and independent: the word before each is
`jr ra` + delay (a boundary), each starts with `addu t0,a0,zero` and ends with `jr ra` + delay (a leaf function), and
**another project's C compiles to exactly those 96 words** — which is a stronger statement than any boundary heuristic,
because it means the body is not merely shaped like code but *is* code that a compiler produced from C.

`0x80005134` (33 words) has no reconstruction from anybody; it is the third member of the run and is named here so the
next milestone starts from a measured extent rather than a guess.

## 3. How big the hole is

Scanning **every** run our byte map does not call `function_body`, for return-delimited segments of six words or more
that do not start at a known function:

```
144 segments, 29 488 B
  stage2 dense_data       51        boot gap                 7
  stage2 enclosed_data    34        boot enclosed_data       7
  stage2 gap              29        stage2 referenced_data   5
```

That is the size of the question, and it should be read with one caveat that this milestone cannot remove: `dense_data`
is packed tables, and a table of `u16` pairs will contain `0x03e0`/`0x0008` adjacencies by chance, so its 51 entries are
weaker evidence than the 41 in `enclosed_data` and the 36 in `gap`. What makes a candidate real is the same thing that
settled `0x80004fb4`: **a reconstruction that compiles to those bytes**.

## 4. What it decides

1. **The leftover 650 are not a queue of functions.** 78 % of the found bodies are the empty function matching
   everywhere, and of the remainder only **9** bodies longer than five words are not already banked or already ours.
2. **Their corpus is not more complete than ours in the way its count suggests.** Its extra entries are mostly interior
   blocks; the segment deltas of M358 are boundary conventions, not missing code.
3. **The measurement found a hole in *our* map**, and its shape is specific: whole functions inside runs we classified
   as data, starting with `0x80004fb4` and `0x80005074`, both with a verified reconstruction available, and a third
   (`0x80005134`) with a measured extent and none.
4. **Admitting them is not this milestone.** A function exists in this project because the census says so; adding one
   changes `F0` and the coverage arithmetic, which is a different kind of change from banking a reconstruction onto an
   address the census already has. The mechanism is clear — the census has admitted functions before, through
   `fixtures/decomp/measured_extents.json` and the recovery fixture — and it deserves its own gate rather than a
   sideways edit here.

## Numbers

- **measured, nothing banked**: 1 595 found bodies classified into 5 buckets, 1 250 of them two-word
- **9 bodies ≥6 words are neither banked nor ours**; 3 of them are functions our census misses
- the hole's size: **144 candidate segments / 29 488 B** across 27 images, 41 in `enclosed_data` and 36 in `gap`
- `tools/other_corpus.py --extent` (+ `classify_body()` as a pure function, self-test **16 → 21**)
- tree **1 375 → 1 380 cases** (323 runnable, 1 057 gated); recovered **360 / 359** and the byte map unchanged —
  `unclassified` **440 B (0.0 %)**, coverage **63.2 %**
- `verify.py --full` **PASS**, audit 160/160
