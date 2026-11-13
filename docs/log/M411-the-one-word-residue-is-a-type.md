# M411 — the one-word residues are an ACCESS TYPE, not an allocation: 24 more bodies

M409 left 71 bodies one word from byte-exact, and every milestone since M392 had assumed a residue that small is a
register-allocation question. Classifying the differing word across all of them says otherwise.

## What the 65 unclaimed one-word residues actually differ by

| kind | bodies |
| --- | --- |
| **different opcode** | **62** |
| same opcode, different register | 3 |

And the opcodes are narrow:

```
had lbu $v0,6($a0)        ours lb  $v0,6($a0)        a signed access where the image reads unsigned
had andi $v0,$v0,0x00ff   ours sll $v0,$v0,24        the same defect one step later, in the extension
had lbu $a0,-24972($v1)   ours lw  $a0,-24972($v1)   byte width against word width
had sll $a0,$a0,7         ours sll $a0,$a0,9         a shift amount, i.e. a different operand width
```

The provider's C says `*(char *)`, the cartridge says `lbu`, and `*(unsigned char *)` is the spelling that emits it.
That is not allocation and it is not a mechanism: **it is the type of the access**, and it is mechanical.

## The pass, and what it closed

`tools/type_repair.py` walks the bodies at most N words from exact, tries a bounded table of width/signedness
substitutions (16 entries, every one a width or a signedness, never a guess about behaviour), pins each variant through
the same pipeline the gate uses, and banks the first that reaches the full word count.

**24 bodies closed**, each pinned word for word: 484 of 3 664 now byte-exact (**13.2 %**), up from 460. Probe cases
483 → **507**; `type_repair --check` re-pins every one of them, and the repair is recorded in the entry's own `probe`
string so the provenance of the *fix* is as visible as the provenance of the C.

The first proof, on `ovl_008505e:0x80164108`: **13 of 14 → 14 of 14** with one substitution.

## The 41 that stay open, and what they say

They are refused with their count, and their differing words are *not* width or signedness — the sample is
`stage2:0x800b202c` at 26 of 27, `0x800a200c` at 24 of 25, and a family of `0x800b2…` bodies all at 24 of 25. A
substitution table cannot reach them, and the next lever has to be chosen the same way this one was: classify the word
first, then pick the instrument.

## The rule this milestone leaves

**A one-word residue is an expression of the compiler's type inference about 62 times out of 65, not a register
allocation.** Twenty milestones assumed the opposite, and the classification that overturned it cost one tool and one
afternoon — where each of those milestones cost a mechanism and a note. The instrument was already in the repo after
M409; what was missing was *asking what kind of word differs* instead of assuming.

Provenance is unchanged: these 24 are still the decompiler's C, adapted in one cast, `provenance: "provider"`, and the
front page's split sentence counts them there.
