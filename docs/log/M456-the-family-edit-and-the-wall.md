# M456 — the family edit: 11 bodies move 36 → 37 of 38, uniformly, and stop at the Group A wall

The gap-2 family had two defects on one signature: `lbu` against our `lb`, and a deferred `sw s2,24(sp)`. The plan was
one edit — fix the type and see whether the store order follows the allocation. It does not, and the answer is uniform
across all eleven.

## The edit

The draft compares `*(char *)(param_1 + 5) == '\0'` where the image reads `lbu`. `byte *` and `unsigned char *` both
work, and both give the same result:

```
stage2:0x8007f0e8   36 of 38  ->  37 of 38
```

The residual is `delete img[5] / insert ours[8]` — the deferred `sw s2,24(sp)`, i.e. **the Group A signature**, unchanged.

## Flags cannot take it further

With the type already fixed, on that body:

| variant | aligned |
| --- | --- |
| **baseline** | **37 / 38** |
| `-O3`, `-fomit-frame-pointer` | 37 / 38 (identical) |
| `-fno-schedule-insns2` | 35 / 38 |
| `-G 8` | 30 / 38 |
| `-fno-schedule-insns` | 22 / 38 |

Nothing improves it. That is M452's result reproduced on a different body of the same signature: the prologue save
order is not reachable.

## The re-triage: eleven for eleven, identically

| body | before | pattern | after | residual |
| --- | --- | --- | --- | --- |
| `stage2:0x8007f0e8` … `0x8007f6d8` (**all 11**) | 36 / 38 | present | **37 / 38** | `del@5 ins@8` |

Every one of the eleven carries the same pattern, moves by the same single word, and keeps the same residual. **The
family is not closable**: the type fix is necessary and uniform, and insufficient, because the last word is the Group A
wall.

So eleven bodies are **correctly filed as unreachable**, and the cost of finding that out was **one edit plus eleven
substitutions** rather than eleven diagnoses.

## The finding worth keeping: `type_repair` could not see these

`type_repair.py` selects candidates by **positional** gap (`--max-gap`), and these bodies read `34 of 38` positionally —
a gap of **4** — while their **aligned** gap is **2**. So the substitution that closes them (`*(char *)` →
`*(unsigned char *)`, a row that has been in its `SUBS` table since it was written) was **never offered to them**.

That is M446/M447's metric defect with a measured cost, stated concretely: **eleven bodies with a working substitution
sat outside the tool's candidate set because the tool ranks by index.** Selecting by aligned identity would have put all
eleven in front of the substitution table.

## Numbers

- family edit: **all 11 move 36 → 37 of 38**, one word, identical residual — **none closed, none banked**
- 5 flag variants on the fixed body: baseline 37, best alternative 37, worst 22 — no improvement
- `type_repair` candidate selection by positional gap **excluded all eleven**; their aligned gap is 2, their positional
  gap 4
- `recovered` stays **674**, byte-exact **673**
