# The permuter harness for `p6` (0x8004fd1c), committed

This is decomp-permuter's working directory for the five-arm switch at `0x8004fd1c`, kept in the tree so
the experiment is reproducible. `build/` is gitignored — correctly, it is 1.5 GB of cartridge-derived
images, provisioned toolchain and other projects' decomp trees — and that is why the *inputs* of the
M256/M259 permuter runs no longer existed when M299 tried to re-measure them. Only our own artifacts live
here: the draft, the build hook, the settings, and the scored candidates. No cartridge bytes are committed,
and the scoring reads the image at run time.

## What each file is

| file | provenance |
|---|---|
| `base.c` | our own draft of the function — the starting point the permuter randomises. At M299 it is **one statement transposition** away from the byte-exact source, and that transposition is worth 12 of 98 words |
| `compile.sh` | the build hook the permuter shells out to: `cc1 -O2 -G 0 -mips2 -mcpu=r4300`, then the binutils-2.7 `as` |
| `f.toml` | `compiler_type = "gcc"` — M256 had this set to `"ido"`, which selects IDO's randomisation weights for a compiler that is not IDO |
| `target.o` | **a compiled draft, not the image** — see the caveat below |
| `candidate-1780-1.c`, `candidate-1980-26.c` | two of the 16 candidates that reach **94/98**, the plateau |
| `scores.json` | every number below, with the run's provenance |

## The measurement

Scored with the word metric — compile the candidate, link `.text` at `0x8004fd1c` and `.rodata` at
`0x800b8bd0`, compare word for word against the stage-2 image:

| source | words identical (of 98) | content-aligned | hunks |
|---|---|---|---|
| `base.c` (control) | **86** | 90 | 8 |
| the probe's `P6_SOURCE` (control, must be 98) | **98** | 98 | 1 |
| best candidate, 16 of them | **94** | 94 | 4 |
| the other 133 | 86 … 94 | | |

Two runs, same result:

- **M259's pool** (82 candidates, `compiler_type = "ido"`): 19 beat the base, best 94.
- **this re-run** (144 310 further iterations, `compiler_type = "gcc"`, 8 threads, 34 better-score events):
  67 more candidates, **none above 94**. 78 % of iterations fail to compile (`113 224 / 144 310`) — the
  randomiser keeps producing C this cc1 rejects.

So the permuter's ceiling on this function is 94/98, and it is stable across both weightings and 226 000
iterations. The four missing words were closed by `tools/shape_solver.py`, which searched statement order —
a move the permuter's randomiser reached only by accident, and never in 144 310 tries.

## The caveat: `target.o` is a proxy, not the function

`target.o` is **116 instructions**, and the function in the image is **98**. Its head matches the image for
two words (`sltiu v0,a2,5`; then the first branch offset differs, `1040005e` in the image against `10400070`
here), and it carries unresolved relocations (`lui v0,0x0` pending `R_MIPS_HI16`). It is therefore the output
of compiling an *earlier draft*, kept because a relocatable object compares like with like against a
relocatable candidate.

That is why the scoring here is not the permuter's own score but the word metric against the image: the
permuter is a **candidate generator** whose objective is a proxy, and the image is the judge. Whether a
target built from the image's own bytes moves the 94/98 plateau is an open question, not an answered one.

## Re-running it

```sh
export PATH="$PWD/build/toolchain/binutils/bin:$PATH"   # the permuter needs objdump on PATH
python3 build/toolchain/src/decomp-permuter/permuter.py fixtures/permuter/p6 -j 8
python3 tools/compile_probe.py --check                   # scores the committed sources
```

The permuter writes `output-<score>-<n>/` directories into this folder; they are worth committing when they
beat `scores.json`'s best, and worth deleting when they do not.
