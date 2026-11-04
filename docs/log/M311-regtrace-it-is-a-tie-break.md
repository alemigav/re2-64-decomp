# M311 — REG_TRACE: it is a tie-break, so the duplicates are next — and a defect in M309's patch

Two things: the one-run `REG_TRACE` the plan called for, and a **correction to M309**, which claimed more
verification than it had.

## 1. The defect first, because it changes what M309 proved

M309 said the `DBR_TRACE` patch was *"verified from pristine source"*. It was **applied** and idempotent, but it was
never **compiled**: the annul edit's replacement was double-escaped, so the patched `reorg.c` carried a literal
`\tfprintf …` and the C compiler rejected it (`stray '\' in program`). The `63/63` I reported was measured against a
**stale `cc1`** — the earlier, hand-edited build — because `make` failed and the old binary was still in place.
Exactly the failure mode this project's rules exist to catch: *a green check on a binary that was never rebuilt.*

**Fixed**: the escaping is corrected in `tools/toolchain/patch_gcc281_fp.py` (single `\n`/`\t` in the file, so the
emitted C has real newlines and a real tab), and this time the proof is a **successful compile from pristine +
patch**, not a grep. The trace itself was sound — the instrument worked and M309's *conclusions* stand; what was
wrong was the claim about how it had been verified.

## 2. The one-run `REG_TRACE`

Instrumented the allocation loop in `global.c` (order, pseudo, reference count, live length, chosen hard register),
gated on `REG_TRACE`, built, run once on the 25-word draft, then **reverted** — it is deliberately *not* in the
patch set.

```
REG_TRACE 2 allocno(s)
REG_TRACE   0 pseudo 104 refs  4 live    5 hard  3     ← the u16 variable `d` → $v1
REG_TRACE   1 pseudo 103 refs  3 live    5 hard  4     ← the mask             → $a0
```

**It is a tie-break, and the tie is reference counts.** `d` (pseudo 104, 4 refs) sorts **before** the mask (103,
3 refs) in `allocno_compare`, so it takes the first free caller-saved register `$v1`; the mask then gets `$a0`.
The truncation copy `104 = 103` — the thing M310 showed forces the annul — is a **consequence of that order**, not
an independent decision. There is no source hook: reference counts can only be changed by changing the code, and
the code's shapes were swept (12 in M308, 6 in M310) without moving it.

So the wall is now fully characterised, and it is the one thing the source cannot reach:

> **`global_alloc` orders allocnos by reference count; the ordering decides which pseudo gets `$v1`; the copy and
> the annulled branch follow.** Nothing in the C changes 4 against 3 without changing the C that must match.

## 3. What follows

Per the plan agreed before the run: **it is a tie-break, so the compiler work stops here** and the time goes back
to the duplicate-body cohorts, where one reconstruction is still worth several functions. The three residues stay
published as they are (`0x8007e590` 226/229, `osCreateThread` 23/52 unregistered, the 25-word group 22/25
unregistered), each now with a complete mechanism rather than a hypothesis.

The instrumentation stays available and reproducible:
- `DBR_TRACE` — in the provisioned patch, **silent and byte-identical when unset**, and now actually compile-verified
- `REG_TRACE` — a one-run tool; the edits are recorded above and take four lines if a future residue needs them

## Numbers

- compile probe **63/63** — this time against a compiler that was rebuilt and installed, verified after the revert
- toolchain: `patch_gcc281_fp.py` corrected (annul edit escaping); `global.c` restored to pristine
- corpus unchanged: **75 recovered / 74 exact**, 73 suites / 1 038 cases
