# M383 — the live-range-first rank was tested, and it does not discriminate

M382 closed by proposing the next selection: *start with the entries whose first call comes after a live-range
decision — an argument still held across it, which is the trait all six of that milestone's wins share.* This milestone
tested the proposal on the remaining 25 `jal`-bearing entries of the 21–50 band, and it is wrong.

## The test

The trait is mechanical and was measured, not eyeballed: **a write to a callee-saved register (`$s0`–`$s7`) before the
first `jal`**. Over the 25 remaining entries:

```
jal entries in 21-50: 25 | save-before-first-call: 17 | not: 8
```

**68 % of the population has it.** A rank that selects two thirds of the queue is not a rank — M382's six wins all had
the trait, but so does almost everything else, so the correlation was a property of the *band*, not a predictor.

## The drafts

Five entries were drafted from the ranked list. **None came back exact**, and four are near-misses worth publishing:

| entry | words | score | what is left |
| --- | --- | --- | --- |
| `0x8017fe54` (ovl_0078c0e) | 25 | **22 of 25** | a retry loop (`for` three attempts, break on a zero result) whose shape is right; ours restores one extra callee-saved register |
| `0x80165cb0` (ovl_0098ee0) | 29 | **26 of 29** | a guarded jump-table dispatch; ours keeps a fourth register live, so the epilogue is two words longer |
| `0x8016557c` (ovl_0090698) | 25 | 16 of 25 | two calls with a store into each delay slot; ours aliases the base through `$s0` where the image reuses `$a0` |
| `0x801655bc` (ovl_009dd02) | 24 | 17 of 24 | an if/else whose arms are a call each; two spellings tried (`if/else`, then early `return`) and both lay the arms out the other way round |
| `0x8000d3cc` (boot) | 23 | not drafted | a **varargs prologue** (`sw $a1..$a3` to the caller's frame, then an `a3` pointing at the spill area) whose first word is a `nop` — an extent that starts one word late |

**The residue is the same wall, one band up.** Every miss is a register-allocation choice (an extra callee-saved restore,
or a base register reused instead of re-materialised), not a wrong statement. That is M311/M334's allocation wall as M380
measured it, and it gets *worse* with size because a bigger body has more live values competing for the same sixteen
registers.

## The correction this milestone carries

M382's "frame makes the order explicit" was **a true description of six successes and a false prediction**: the frame does
make the spill order explicit, but at 21+ words *almost every body has a frame*, so it selects nothing. What actually
separated the wins was their size:

| population | exact |
| --- | --- |
| 13–20 words, `jal`-bearing (M381) | **10 of 12** |
| 21–50 words, `jal`-bearing, **22–23 words** (M382) | **6 of 6** |
| 21–50 words, `jal`-bearing, **24–29 words** (M383) | **0 of 5** |

**The useful predictor is not a shape but a size: 22–23 words closes, 24 words and up does not** — and the reason is
mechanical, because that is where the four argument registers plus one spill stop being enough and the allocator starts
making choices a draft cannot steer. The next selection in this band should be **≤ 23 words**, which is 9 of the 25
remaining entries, and the 24+ tail should wait for a mechanism rather than for more drafts.

## Moves

**Nothing registered** — the corpus stays at **259 / 258 byte-exact**, `F1` **3 468**, rung **333 entries / 38 036 B**,
coverage **1 238 112 B**. Four entries gain a published score on the rung and stay there. `make check` unchanged at
**258 of 259**. This is the first milestone of P21 that adds no reconstruction, and it is published as what it is: a
refutation with a number, which is the same trade M357 made when it closed the compiler question.
