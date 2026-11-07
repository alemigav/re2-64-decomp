# M367 — the licence decision recorded, and the no-build limitation stated

M366 left the imported corpus with three options and no choice. The owner chose **keep and attribute**, and this note
is the record, because a decision that lives only in a chat is the same defect as a number that lives only in prose.

## What was decided

`fixtures/decomp/imported/` — **170 C files** taken verbatim from
`delibrete/Resident-Evil-II-Decompilation-N64` — **stays**, attributed, with the risk stated:

- that project publishes **no `LICENSE`, `COPYING` or `NOTICE`**, so the default is **all rights reserved**;
- this is therefore a redistribution the other project has not licensed, offered for removal on request in the same
  terms `THIRD_PARTY.md` §2 offers for the Capcom-derived `src/`;
- **`THIRD_PARTY.md` §0a is the one place** that says where the files came from, and the only place that needs editing
  if the position changes.

## The fallback, kept costed

Remove the directory and the **192 entries** that point at it; the claims stay as `measured_extents` listings, so
**coverage does not move** and **F1 falls by 192** (3 459 → 3 267). One `rm -rf` and one fixture edit — reversible,
because the corpus is public.

What survives either way is the distinction M356 got wrong and M366 had to retract: **the verification is this
project's, the C is not, and verification is not a licence.**

## The other correction, from the same review

The README's opening claim said *"this is not a matching build"* and stopped there. It now also says there is **no
Makefile, linker script or ROM target**, that **`src/` cannot be compiled as it stands**, and that what compiles here is
**one function at a time** through `tools/compile_probe.py` at the address the cartridge puts it. A reader was right
that the absence of a build is worth stating rather than leaving to be discovered.

## Numbers

- decision recorded; fallback costed (F1 −192, coverage unchanged); one section is the single point of change
- README states the no-build limitation in the sentence that already claims "not a matching build"
- corpus unchanged: **391 / 390 exact**, census 3 665, coverage 63.3 %; counts **29/29**, markers **25/25**,
  `verify.py --full` **PASS**, audit 160/160

---

## Superseded by M369 — the files are removed

This note recorded **keep-and-attribute**. M369 reverses it: the imported text is **gone**
(`fixtures/decomp/imported/`, 170 files, 194 entries), the claims stay as measured extents, and `recovered` falls
**394 → 200** with **F1 3 462 → 3 453** and coverage **unchanged** — because the bytes are still claimed, as listings
rather than reconstructions.

The reasoning in this note was that the risk was stated and the fallback costed; the owner has now judged the risk not
worth carrying. The note is kept for the sequence — retraction by addition, not by rewriting — and the fallback it
priced at *"one `rm -rf` and one fixture edit"* is exactly what it took.
