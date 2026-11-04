# M325 — `vector_installer` started: structure, a first draft at 18 of 132, and three shape findings

The second of the two boot roots — `boot:0x800070c0`, **132 words**, the boot's exception-vector installer — is the
largest target this project has taken on. This milestone is its **start**: the structure was decoded in M323, and a
first draft now exists and is measured.

## What the draft is

`build/probe/vi-draft-001.c` (kept, because a draft that is 18/132 is evidence about the *shape*, not noise): the
sequence in address order — write `*(u32 *)0x80014FF0 = 1`; `FUN_8000cde0(FUN_800072d0() | 0x2000)`;
`FUN_8000ccf0(0x01000800)`; two poll loops on `FUN_8000d2d0`/`FUN_8000d360(0x1FC007FC, …)`; **four 16-byte
`struct V` copies** from `0x800006C0` to the four exception vectors `0x80000000/80/100/180`;
`FUN_8000efa0`/`FUN_800073d0(0x80000000, 0x190)`; `FUN_80007ef0()`; `FUN_8000c940(4, &sp20)`; the masked
`sp20` re-store; a **64-bit × 3** on the `0x800128C0/C4` pair and `FUN_80006100(hi, lo, 0, 4)`;
`FUN_80006650(0x8000031C, 0x40)` when `*(u32 *)0x8000030C != 0`; and the **three-way dispatch** on
`*(u32 *)0x80000300` selecting `0x02F5B2D2 / 0x02E6025C / 0x02E6D354` into `0x800128C8`.

**18 of 132 words**, 144 compiled. It is not close, and the diffs are worth more than the number.

## Three findings, each measured

1. **The image's frame is smaller than the draft's because it has no long-lived locals.** Ours saves `$s0` and puts
   `ra` at 28; the image puts `ra` at 24 with one zeroed slot at 20 and nothing else. Removing a variable that spanned
   the whole function (18/132 from 3/132) and scoping the loop/diapatch temporaries did not remove `$s0` yet — so
   something still lives across a call in our version, and finding it is the next step.
2. **One local is zeroed and one is not.** Initialising both cost extra stores (3/132); initialising neither cost the
   zeroed store the image has (14/132); initialising only `sp20` gave 18/132. The image's `sw $zero,20($sp)` and the
   callee-written `sp+16` say exactly that: **`sp20` is initialised, `sp16` is output-only**.
3. **A constant OR'd into a call argument is `or`, not `ori`.** The image has `lui $a0,0x2000` *before* the `jal` and
   `or $a0,$v0,$a0` in its delay slot; writing `FUN_800072d0() | 0x2000` lets gcc fold to `ori`. The original build
   materialised the constant first, which happens when the constant is its own expression or variable.

## What the next pass needs

In order: (a) find what still keeps `$s0` — one value is crossing a call in our version and not in the image;
(b) express the `0x2000` so it materialises before the call; (c) the four struct copies are the least certain part
(the image reloads `0x800006C0` for each copy, which a `struct` assignment does, but the *value* register rotation
`v1/a0/a1` suggests a specific four-word copy order); (d) the two poll loops' exit conditions; (e) the dispatch form.

Each of those is a measurement, not a guess — which is why the draft is committed rather than thrown away.

## Numbers

- **recovered 130 / 129 exact — unchanged**; nothing registerable
- compile probe 118 cases (118/118); tree 1 105 cases (807 gated, 298 runnable); suites 74, tools 101
- `build/probe/vi-draft-001.c` is scratch (gitignored), not a fixture
