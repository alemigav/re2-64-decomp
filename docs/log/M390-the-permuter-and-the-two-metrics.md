# M390 — the permuter pointed at the near-misses, and the two metrics disagree

The eagle view said this was the highest-leverage move left: twenty entries sit at 80–99 %, six of them one to three words
from byte-exact, and the lever every recent milestone found by hand — *a value's materialisation follows the statement that
binds it* — is exactly what a permuter automates. So the repo's own permuter (committed since M299/M303, provisioned at
`build/toolchain/src/decomp-permuter`) was pointed at the closest residue for the first time.

**It produced 150 candidates in about ten minutes and closed nothing.** The numbers say why, and they are worth more than
a lucky hit would have been.

## The run

Target `stage2:0x800725ac`, twelve words, the closest residue in the corpus (**11 of 12** by this project's word metric;
the residue is where the return value sits relative to `jr ra`).

| | |
| --- | --- |
| objective | `target.o` assembled from the image's own twelve words, **verified byte-identical to the cartridge** (48 B) |
| base | the hand draft that scores 11 of 12 |
| search | `permuter.py -j 8`, ~10 minutes, 150 scored candidates written |
| permuter's own score | base **820** → best **620** |
| **our word metric, same candidates** | best **10 of 12** — **worse than the base** |

**The permuter improved its score by 24 % and made the function worse.** That is the finding.

## Why the two metrics diverge, precisely

The permuter diffs the instructions of an **unlinked** object against `target.o`. This project's verdict **links** each
candidate at the cartridge address and compares the words. Those are the same thing until a body materialises an absolute
address, and this one does: the image holds `lui v0,0x8001` + `sb v1,10376(v0)`, i.e. **the address is resolved**, while a
candidate object carries a relocation pair against `0x80012888`. So the permuter sees an instruction mismatch where the
linked comparison would see none, and its search steers away from the shape the cartridge actually has. The p6 fixture has
recorded this asymmetry since M302 in its own words — *"the word metric, which links both sides, stays the verdict and the
permuter's score is a search signal"* — and this milestone is the first time it was measured on a residue rather than
stated.

**So the permuter cannot be pointed at these residues as-is.** For it to help, the objective has to be *linked*: a custom
`compile.sh` that links the candidate at the address and emits the comparison, or a scoring hook that re-runs
`leaf_screen`-style linking per candidate. That is a real piece of work — the permuter's loop expects an object it can
objdump, so it means either a wrapper that links to an ELF and back, or a fork. **Named as the next step, not attempted
here**, because guessing at a fork in the last hour of a cycle is how a working instrument gets broken.

## What was built anyway

- **`tools/permute_target.py`** (tools 106 → **107**) — builds a permuter objective from an image's own words through
  `.word` directives, **verifies it is byte-identical to the cartridge before writing**, and has a `--self-test` (3 cases)
  that proves the identity rule can fail. Registered as suite `permute target (repository)`.
- The harness directory for the run is reproducible from one command:
  `python3 tools/permute_target.py --image stage2 --addr 0x800725ac --words 12 --out build/permuter/m390-725ac/target.o`
  plus `base.c`, the committed `compile.sh` and a two-line `settings.toml`.
- **Two operational facts for the next run**, both learned the hard way: the permuter needs a `mips-linux-gnu-objdump` on
  `PATH` (it raises `Could not find any objdump executables` otherwise), and it must be driven with `.venv/bin/python` —
  the system interpreter has no `permuter` package.

## The honest reading

Three of P21's last five milestones are now negative (M383, M386, M390), and each one is negative for a *different*
reason: the trait did not discriminate, the cohort was not C, and the instrument's objective was not the verdict. The
pattern that holds across them is that **the wall is the same** — a body that is right in every statement and wrong in one
register's life — and no instrument in the tree currently optimises for it.

**What would**: either a linked objective for the permuter (named above), or an allocator-order search over the *source*
shapes that produce different live ranges — which is what the hand levers have been doing one function at a time. The
permuter with a linked objective is the only one of those that scales, which is why it is the recommendation.

## Moves

**Nothing registered** — `recovered` stays **274 / 273 byte-exact**, `F1` **3 468**, rung **317**, coverage
**1 238 404 B**. tools **106 → 107**, tree **79 → 80 suites / 1 377 → 1 380 cases** (351 → 354 runnable),
`verify.py --full` **PASS**, audit **160/160**. Milestones **391 numbers / 335 rows / 316 notes**.
