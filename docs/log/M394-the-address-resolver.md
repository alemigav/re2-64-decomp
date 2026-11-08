# M394 — the address resolver: a name change stops being a code change

Six tools cited reconstructed sources **by filename**: 29 `"src/…​.c"` literals, 214 `"<name>.c:<line>: <statement>"`
citations, and 9 paths joined at run time. A function's name is the one thing about it that moves — that is the whole
point of naming it — so renaming the twelve audio bodies broke every one of those citations and turned the mutation audit
**INCONCLUSIVE**: 34 gates whose own tool could no longer read a file, before a single number moved.

## What was built

`tools/srcmap.py` resolves a source path from the **address**, against the committed `manifests/code_index.json` — so it
needs no cartridge and cannot disagree with the tree that `export_src.py` wrote.

```python
srcmap.path("stage2", 0x800b63b4)   -> Path("src/stage2/<whatever it is called today>.c")
srcmap.render("@800b63b4:20: iVar6 = (int)(short)param_1[0xb3];")
                                   -> "src/stage2/<current name>.c:20: iVar6 = …"
```

**Citations now name a function, not a file.** `@<address>:<line>: <statement>` is the form; `render()` expands it at use
time and **verifies the cited statement is still on that line**, so a citation whose line moved becomes a message instead
of a silent mismatch. A citation may also name a line without a statement (`@addr:12`), which the registry does.

## The gate that makes the class impossible

Suite `resolve (repository)`: **no tool may build a `src/` path, cite `"<name>.c:<line>"`, or join one at run time.**
It reported **240 sites** on its first run and **zero** now.

## What the conversion taught — three shapes, not three one-offs

1. **An artefact bakes citations into itself.** `voice_descriptor.json`, `opcode_registry`'s file, `rsp_decode`'s manifest
   and `fixtures/scd/trace_fixture.json` all carried the old text; each needed regenerating, and the *fixture* needed its
   cited text edited because it is not generated.
2. **A citation may name a line without a statement** — the registry cites `@addr:22`, not a phrase, so the parser takes
   both forms and `render()` skips the statement check when there is none.
3. **The `arith:` hop carries a statement after the line**, so a pattern anchored at the digits rejected every one of the
   14 clip-trace values until it allowed a tail.

**And one near-miss worth recording:** the first attempt at this rename (M394's predecessor, reverted) failed because the
conversion was done *after* the rename. Doing it first is the whole reason this commit applies **no name**.

## Moves

`named` stays **33**; `recovered` **274 / 273**, `F1` **3 468**, rung **317**, coverage **1 238 404 B** — no corpus number
moves, which is the point of the split. tools **108 → 109**, tree **81 → 82 suites / 1 381 → 1 384 cases** (354 → 357
runnable), four artefacts regenerated, `verify.py --full` **PASS**, audit **160/160**. Milestones **395 numbers / 338 rows
/ 319 notes**.

**Next (M395):** the twelve names ride on this resolver — `symbols.tsv` → `make_seeds.py` → `export_src.py`, with
`analysis_status.py`'s residue case flipping from `validated_unnamed > 0` to `== 0`.
