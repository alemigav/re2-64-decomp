# M391 — the retraction: the "near-miss" scores were read wrong, and no partial kept its draft

This milestone set out to make the permuter's objective linked. It found something worse first, and the finding is about
the *record* rather than the instrument.

## What was found

`0x800725ac` is listed in M379's table as **11 of 12 words identical** — one of "six bodies one to three words from
byte-exact" that M390 then spent a permuter run on. Re-measured today, with both the probe's pipeline and a second
independent reproduction of it:

```
leaf_screen --try base.c --image stage2 --addr 0x800725ac --count 12 --sym D_80012888=0x80012888
  -> 2/12 words identical (12 compiled)
```

**Two, not eleven.** The two pipelines agree completely — their `.s` files differ only in the `.file` comment, and the
assembled and linked words are identical — so there was never a pipeline divergence to find. The base draft really is worth
2 of 12, and its assembly says why: this `cc1` compiles `u8 v = p[1]; if (v < 0x80)` into `lb $v0,1($a1)` **and**
`lbu $v1,1($a1)` (a signed read for the test, an unsigned read for the store) followed by **`bltzl`**, because
`v < 128` on a byte is equivalent to "sign bit clear" and gcc 2.8 canonicalises it into a sign test. The image has one
`lbu` and one `sltiu`. Three further spellings (`0x80u`, an inline `p[1]`, an early-`goto` form) give the same 2 of 12.

## How the score was read wrong

Every drafting batch in this cycle ended in `python3 tools/leaf_screen.py --try … | tail -N`. **`--try` prints the
differing words *above* the summary line**, so a truncated diff reads exactly like a short one: five lines of diff at the
bottom looked like "only five words differ" when words 0–6 had also differed and had been cut off by `tail`. The same
error produced M378's "three drafts briefly believed exact" — that one was caught by `build_corpus --check`, and this one
by re-measuring a single entry two milestones later.

**So the near-miss list is unverified, and the state of the evidence is worse than a wrong number:**

| | |
| --- | --- |
| M379/M380/M381/M382/M383/M385 published partial scores | **~14 entries, all scored this way** |
| their drafts | **lived in `/tmp` and are gone** — `/tmp` was wiped between sessions |
| what can be re-checked today | **nothing**, for any of them |

That is M356's lesson in a new place: *a `/tmp` script is not an artefact*. A *draft* is not an artefact either, and a
partial whose source is not in the tree is not a published residue — it is an unverifiable claim with a number attached.

## What is retracted, and what survives

- **M390's premise is retracted**: its target was not "1 word from exact" but 10 words from exact, so its permuter run
  measured a search from a bad base. **Its conclusion survives on the evidence** — the permuter's objective is an
  unlinked-object diff and the verdict is a linked word comparison, and M390's 150 candidates were scored against the
  image either way — but the *base* figure it quoted is wrong and the note now says so.
- **The ~14 partial scores are withdrawn as unverified.** The entries stay on the rung (their extents are separately
  measured and unaffected); what goes is the claim that they are "1–3 words from exact".
- **The eagle view's "largest convertible pool" is therefore unmeasured.** It may be real; today no number in this
  repository supports it.

## The rule this earns, and the fix

**A partial is published only with its draft committed.** The corpus already has the pattern for the winning case —
`fixtures/decomp/authored/<image>/<addr>.c` for a reconstruction — and the losing case needs the same: a
`fixtures/decomp/partials/<image>/<addr>.c` carrying the score in a header, read by a gate that re-scores it and fails if
the published number drifts. Without that, every "near-miss" number in this log is prose.

**And an operational rule that costs nothing:** never bound `leaf_screen --try`'s output. Its summary is the last line;
`grep -E "identical"` gets it, `tail` gets whatever happens to be closest.

## Moves

**Nothing registered, nothing un-registered**: `recovered` stays **274 / 273 byte-exact**, `F1` **3 468**, rung **317**,
coverage **1 238 404 B**. No fixture changed. The milestone's product is a retraction and two rules, which is the honest
outcome of a measurement that did not survive being repeated.
