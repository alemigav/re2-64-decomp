# M309 — instrumenting `reorg.c`: the scheduler was not the culprit, and the trace says so

The instruction was to instrument `reorg.c` and break the scheduler/allocator wall before taking another
function. The instrumented compiler was built, and it answered the question — **by clearing reorg**.

## 1. The instrument

`eligible_for_delay` is **generated** from the machine description (`genattrtab.c` emits it into
`insn-attrtab.c`), so it cannot be patched at its definition. `patch_gcc281_fp.py` now wraps it in `reorg.c` and
logs every eligibility question and every annulment, gated on **`DBR_TRACE`**:

```
$ DBR_TRACE=1 cc1 … f25.c
DBR eligible branch=38 trial=36 slot=0 flags=12 -> no
DBR eligible branch=38 trial=34 slot=0 flags=12 -> no
DBR ANNUL branch=59 stolen_trial=62
DBR eligible branch=94 trial=93 slot=0 flags=12 -> yes
```

The patch is part of the provisioned toolchain (idempotent, re-applied by `provision.sh`, verified on a pristine
tree), and it is **provably inert**: with `DBR_TRACE` unset the assembly is **byte-identical** (`cmp`), and the
probe still passes **63/63**, so all 16 previously exact functions still match.

## 2. What it says about the 25-word group

Branch **59** is our `bnez`/`beql`. The trace is unambiguous:

- **no `DBR eligible branch=59` line at all** — the simple filler never asked, because no candidate survived the
  earlier resource checks (its only movable instruction, the copy `v1 = a0`, is *read by the compare* and cannot
  move past it);
- **`DBR ANNUL branch=59 stolen_trial=62`** — the eager path then stole insn 62 (the `ori`) from the fall-through
  thread and annulled, which is what produces `beql … ; ori` instead of the image's `bnez … ; move ; ori`.

So reorg did the only thing it could with the RTL it was given. **The wall is upstream of it**, and the `.sched2`
dump names it: reorg's input already has

```
insn 55:  v1 = (HI) a0          ← the copy
insn 58:  v0 = (v1 <= 2048)     ← the compare reads the COPY
```

where the image's build has the compare reading **`a0`** and the copy after it:

```
image    andi a0,v0,0xfff ; slti v0,a0,2049 ; bnez ; move v1,a0 (slot) ; ori
ours     andi a0,v0,0xfff ; move v1,a0      ; slti v0,v1,2049 ; beql ; ori
```

Same three instructions, different operand: **register allocation chose to compare through the copy**, and that
single choice removes the delay-slot candidate and forces the annul. It is the *third* instance of the same
family — `0x8007e590`'s interference (M304), `osCreateThread`'s parameter scheduling (M303), and now this — and
it is now traced rather than inferred.

## 3. What changed in the toolchain

- `tools/toolchain/patch_gcc281_fp.py` carries **two new edits** (the wrapper, the annul log), idempotent and
  verified from pristine source; `docs/TOOLCHAIN.md` records why
- the installed `cc1` is rebuilt **from pristine + patch**, so `provision.sh` reproduces exactly this compiler
- the trace is a *facility*, not a finding: the next scheduler/allocation residue can be read instead of guessed

## 4. Where the wall actually is, stated as the next experiment

The residue is a **copy placement**: `v1 = a0` before the compare instead of after. That is decided in
`local_alloc`/`global_alloc` (the copy exists to give the select's result its home register, and the allocator
then made the compare read it). The instrumented build is the right tool for the next step — the same
`DBR_TRACE` mechanism generalises to a `REG_TRACE` in `global.c`, logging why the compare's operand was preferred
in the copy's register. That is the experiment this milestone sets up; it is not claimed here.

`0x8007e590` stays 226/229 and the 25-word group stays unregistered at 22/25, both published as such.

## Numbers

- compile probe unchanged at **63/63** cases — which is the point: the trace is inert
- toolchain: `patch_gcc281_fp.py` +2 edits, `docs/TOOLCHAIN.md` +1 row; corpus, coverage and recovered count
  unchanged at **75 / 74 exact**
