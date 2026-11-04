# M334 — can the allocation gap be influenced? Twenty-five flag variants, one corpus control

The question at the end of M333 was whether the last gap in `vector_installer` — 16 words identical, 61 identical once
register names are ignored — is reachable or a hard cap. It is **reachable by exactly one knob, and that knob is
refuted by the corpus**. Both halves of that sentence are measured below.

The sweep needed a capability the committed tool did not have, so `leaf_screen.py --try` gained **`--cc1-arg`**
(repeatable; the assembler and linker pipeline unchanged, so any difference in the words is the compiler's). "Is this
allocation a wall?" is a question about flags, and the only honest way to ask it is to compile the same draft again with
one flag moved.

## 1. The flag sweep: 25 variants, one that moves

| variant | insns | exact | register-agnostic |
| --- | --- | --- | --- |
| **baseline** (`-O2 -G 0 -mips2 -mcpu=r4300`) | 132 | **16** | **61** |
| `-fno-schedule-insns` | 132 | **21** | **65** |
| `-fno-schedule-insns2` | 132 | 14 | 56 |
| `-fno-delayed-branch` | 144 | 7 | 8 |
| `-O1` | 132 | 18 | 20 |
| `-fforce-mem`, `-fforce-addr`, `-fno-defer-pop`, `-fno-peephole`, `-mno-memcpy` | 132 | 16 | 61 |
| `-fno-strength-reduce`, `-fno-rerun-cse-after-loop`, `-fno-thread-jumps`, `-fno-inline`, `-fno-function-cse`, `-fno-caller-saves`, `-fno-expensive-optimizations`, `-fno-cse-follow-jumps`, `-fno-cse-skip-blocks` | 132 | 16 | 61 |
| `-mno-split-addresses` | 132 | 16 | 57 |
| `-fforce-addr -fno-schedule-insns`, `-fno-peephole -fno-schedule-insns` | 132 | 21 | 65 |

So the register-allocation surface is **insensitive to everything except the pre-reload scheduler**, and what that
scheduler changes here is not the registers at all: it changes the **order of the two 32-bit loads**. Recompiling with
`-fno-schedule-insns` puts the high half first (`lw $a2,10432` then `lw $v1,10436`), which is the image's order; the
baseline swaps them (lo first), because the two loads are independent and the scheduler is free to. Five words of
alignment come back from that ordering alone.

## 2. The control: that flag is not the image's

The corpus decides. Every entry in `compile_probe.SINGLES` was re-scored through the same pipeline, once under the
pinned profile and once with the flag:

```
singles tested                               52
byte-exact with the pinned profile           52 / 52
byte-exact with -fno-schedule-insns          51 / 52
broken by the flag                           S_8008AF6C (5/5 -> 3/5)
```

One function needs the scheduler to be byte-exact, so **the profile that reproduces this cartridge has the pre-scheduler
on**, and `vector_installer`'s improvement under it is a coincidence of ordering rather than evidence about the original
build. That is the answer to the question as asked: *influencable* — yes, measurably, by one flag and five words —
*available* — no, because the same flag costs a registered function, and a build is one profile.

## 3. What the gap actually consists of

Of the image's 132 words, for draft-009:

| | words |
| --- | --- |
| identical, byte for byte | **16** |
| identical once register names are ignored (so these differ **only** in which register) | **45 more** (61 total) |
| different in opcode, immediate or order | **71** |

And the 45 register-only words are not distributed evenly: they concentrate in the four 16-byte copies (the image uses
`$v1,$a0,$a1` as the move's three scratch registers and `$a2` as the destination; we use `$t0,$t1` and `$t3`) and in the
multiply (the image's pair lives in `$a0`/`$a1`, ours in `$4`/`$5`).

Two facts bound what could be done about them:

- **The allocator is not misconfigured.** Under the pinned profile the corpus reproduces the image's register choices
  for functions up to **206 and 229 words** (`0x80059530` byte-exact, `0x8007e590` at 226 of 229) — allocation at that
  size is not luck. So the divergence here is not a wrong `REG_ALLOC_ORDER` but a different *live-range shape*.
- **The copy expander's register count is pressure-driven, not fixed.** `movstrsi_internal` asks for four scratch
  registers and `output_block_move` uses as many as reload gives it; the image got three (its `lw,lw,lw,sw,sw,sw` then
  `lw,sw`), we got two (`lw,lw,sw,sw` twice) with the scheduler interleaving the rest. That is the same knob from the
  other side — the scheduler — and it is why the flag moved this function.

So the honest position is the one M303 measured on `osCreateThread`: **shape and allocation are separable, and only one of
them is reachable from the source we can see.** The levers that exist are (a) the pre-scheduler, measured here and
refuted by the corpus, and (b) live-range shape, which is reachable in principle at roughly one disassembly round-trip
per value — 45 words of payoff, with the risk of losing words elsewhere each time. Neither is a per-function switch.

## 4. What was added to the tool, and why it belongs there

`--cc1-arg` is six lines in `leaf_screen.py`, and without it this sweep would have been a shell loop that re-derived the
compile, assemble, link and score steps by hand — the exact pattern the M319 rule forbids (*a thing needed a third time
becomes a committed tool*). The self-test still covers what it covered (the screen's twelve cases); `--try` cannot be
self-tested because it needs the cartridge, so nothing was re-baselined and no case count moved.

## Numbers

- **25 cc1 variants measured**; one moves the function (`-fno-schedule-insns`: exact **16 → 21**, register-agnostic
  **61 → 65**), and the corpus control refutes it (**52/52 → 51/52**, `S_8008AF6C` 5/5 → 3/5)
- **Gap breakdown: 16 identical / 45 register-only / 71 other, of 132 words**
- **Draft-009 remains the reference**; nothing about it changed
- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 74 suites / 1 108 cases (807 gated, 301 runnable); **tools 101** (no new
  tool, one new flag); leaf-screen self-test 12/12
