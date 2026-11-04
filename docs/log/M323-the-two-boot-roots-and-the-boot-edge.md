# M323 — the two boot roots and the boot edge: two negations and one settled boundary

`main` gave the tree two new roots to grow from — `FUN_800004f0` and `vector_installer` — and neither yields a C
function. The `BOOT_SIZE` edge, by contrast, settles cleanly: it is a **segment** boundary, and the evidence was
sitting one word past it all along.

## 1. `FUN_800004f0` — four words of CP0, and not C

```
0x800004f0  mtc0 $a0,$18      ; CP0 WatchLo
0x800004f4  mtc0 $zero,$19    ; CP0 WatchHi
0x800004f8  jr   $ra
0x800004fc  nop
```

That is libultra's `__osSetWatchLo`/`osSetWatchLo` shape: set the watch registers, clear the high word, return. It
is **not C** for this compiler — `mtc0` has no C construct, the corpus is comment-free plain C with no inline asm,
and `leaf_screen`'s CP0 rule already refuses it. Recorded so the root is not re-walked.

## 2. `vector_installer` at 0x800070c0 — 132 words, C-shaped, not guessed

The other root is a real function and the **largest target this project has decoded**: the boot's exception-vector
installer. Its structure, read off in full:

| words | what |
|---|---|
| 0-6 | frame; `*(u32 *)0x80014FF0 = 1`; `FUN_800072d0()` (reads CP0 Status) |
| 7-16 | `FUN_8000cde0(v \| 0x2000)`, `FUN_8000ccf0(0x01000800)` (the FP control register), `FUN_8000d2d0(0x1FC007FC, &sp+16)` |
| 17-25 | a **poll loop** (`bne` back 4 and back 6) around two PI/SP calls |
| 26-66 | **four 16-byte struct copies** from `0x800006C0` to `0x80000000`, `0x80000080`, `0x80000100`, `0x80000180` — the four exception vectors |
| 67-77 | `FUN_8000efa0(0x80000000, 0x190)`, `FUN_800073d0(0x80000000, 0x190)` (the cache ops), `FUN_80007ef0()`, `FUN_8000c940(4, &sp+20)` |
| 78-113 | a **64-bit multiply by 3 built from 32-bit pairs** (`sll`/`srl`/`addu`/`sltu` — so this *is* C-emittable, unlike `0x8004276c`), `FUN_80006100(…, a2=0, a3=4)`, stores to `0x800128C0`/`0x800128C4` |
| 114-131 | a **PRId dispatch** on `0x02F5B2D2` / `0x02E6025C` / `0x02E6D354`, store to `0x800128C8`, return |

**It is not drafted here, deliberately.** 132 words is nearly three times the largest reconstruction in the corpus
(`0x8007e590`, 229 words, took five milestones and is still 226/229), and a guessed first draft would burn this
milestone for a number that says nothing. It is now *named and structured* — the work is a real milestone of its own,
and the shape above says the method will work on it: the arithmetic is 32-bit-pair 64-bit math, which this compiler
does emit.

## 3. The `BOOT_SIZE` edge, settled

The question was whether `boot:0x800115b0` (5 words, `lui; ori; lw; jr ra` + a delay slot) is measurable. It is not,
and the reason is now measured rather than suspected:

- `BOOT_SIZE` = **69 952 = 0x11140** covers virtual `0x80000480..0x800115C0`. The word at `0x800115C0` is ROM
  `0x12140` — one word past it — and it is not padding: it is `slti v0,v0,0`, the delay slot of the `jr ra` at
  `0x800115bc`.
- The same cartridge region continues to stage2 at ROM `0x14420`, and it is **loaded data**, not filler: the version
  string `RE.0930…9.1542` at ROM `0x12144`, the **overlay table** at virtual `0x80012150` (ROM `0x12CD0`) with magic
  **`OVERLAYTABLENUMC`** and entries of `{rom_start, rom_end, vram_start, vram_end}` whose first row is
  `0xb0014420 / 0x5e1ef / 0x80018a80 / 0x80136d90` — i.e. **stage2** (with flags in the `rom_start` field's high
  nibble), and the ASCII table at ROM `0x143F4` immediately before stage2's zlib.

So there are **two extents**: the boot's **code** extent, `0x11140` (what the census and the byte map cover), and its
**load** extent, `0x13420` (what must be resident: code + version string + overlay table + ASCII table). The
boundary function straddles them — four words of code in the first, its delay slot as the first word of the second.

**Decision: `BOOT_SIZE` stays 0x11140** — it is the code extent, and the overlay table's own magic says it is a
distinct structure, not boot code. The consequence is that `boot:0x800115b0` is **un-registerable**: 5 words cannot
be measured inside the window, and 4 would be a function without its delay slot. The tool already refuses with that
message, and the boundary is now a gate case rather than a mystery. Widening the boot image to `0x13420` would move
coverage, the byte map and the census at once — its own milestone, with this evidence as its case.

## Numbers

- **recovered 130 / 129 exact — unchanged**; nothing in this batch was registerable
- compile probe **117 → 118 cases** (118/118 pass): the `boot_edge()` case pins the boundary, the magic, the
  overlay row and the `0x28420000` delay slot
- tree **1 104 → 1 105 cases** (806 gated, 298 runnable); suites 74, tools 101 — unchanged
