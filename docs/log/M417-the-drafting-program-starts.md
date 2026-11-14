# M417 — the drafting program starts: a workbench, and the first body closed by classification

The program is committed: 40 % of 3 664 is ~870 bodies written one at a time. The rate was never limited by the edit — it
was limited by the *setup*: dump the words, find the provider's draft, compile it, diff it, work out what kind of
residue it is, then pick the mechanism that class. That was ~20 minutes of mechanical work per body, and it is what made
the old rate five per milestone.

## The workbench

`tools/draft_workbench.py` collapses it to one command:

```
python3 tools/draft_workbench.py --queue 8        # the cheapest bodies left, band-first
python3 tools/draft_workbench.py --at stage2:80082388
```

`--at` prints the image's words in build order, the provider's draft, the word-by-word diff, and — the part that matters
— **the residue's class**, from rules the log measured rather than guessed:

| class | the tell | the move it implies |
| --- | --- | --- |
| `width` | `lbu` vs `lw`, `lb` vs `lbu` | the access TYPE (M411) |
| `extend` | `andi 0xff` vs `sll 24` | declaration signedness (M413) |
| `materialise` | `addiu`/`ori` vs `lui` | the arithmetic domain (M396c) |
| `order` | same opcode, different operands | statement order (M401) |
| `layout` | only a branch displacement | the residue is upstream — the body's size |
| `alloc` | one register, nothing else | the class no pass reaches (M408, M416) |

The classifier has its own gate (5 cases) because it is the half that makes a claim; `--at` itself asserts nothing.

## The first body, and the mechanism it produced

`stage2:0x80082388` — 10 words, 9 identical. The workbench classified it `alloc`: `addu $v0,$v1,$zero` against the
image's `addu $v0,$zero,$zero`. Four allocation spellings changed nothing. The fifth did:

```c
iVar2 = 0;                    /* before the guard: our early return reuses a register that holds zero */
if (param_1 == (char *)0x0) {
    return 0;
}

if (param_1 == (char *)0x0) { /* after it: the early return materialises from $zero, as the image does */
    return 0;
}
iVar2 = 0;
```

**10 of 10.** A guard that returns a constant leaves a zero in a register, and *where the initialisation sits* decides
whether the compiler reuses it. That is M401's statement-order mechanism in a form a pass can express, so it became one:
`order:past-guard`, added to `mechanism_pass.py` and measured — **0 of 243** on the near band, because the pattern is
rare and the one body it fits was the one just banked. A measured zero, recorded as such.

## Two defects this milestone found in its own instrument

1. **68 262 leaked scratch directories, 12 GB.** Every `pins()` call created a `build/probe/…` directory and never
   removed it. The gate audit sandbox-copies the tree per case, so the fast tier **hung with no output at all** and two
   30-minute timeouts were spent before a `faulthandler` dump showed `walk_stream --self-test` — a tool that runs in
   0.09 s — waiting forever inside a sandbox copy. All four tools now register their scratch dirs and sweep them at
   exit.
2. **The fast tier no longer meets its contract.** With the leak gone it completes, but in **5 m 50 s**, against a
   §30-second rule. The cause is growth: ~1 300 authored reconstruction files and a much larger fixture set mean the 160
   audit cases copy a much bigger tree. **This is the next milestone's work, not a footnote** — a verifier that takes
   six minutes is not the verifier this project agreed to run.

## State

596 → **598 of 3 664 (16.3 %)**, 325 the decompiler's C. The queue the program works from: **155 bodies at gap ≤ 4**
and 2 017 at ≤ 120 words, each one command away in the workbench.
