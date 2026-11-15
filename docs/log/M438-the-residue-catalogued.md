# M438 — the residue, catalogued: the biggest class is not a compiler pass, it is a missing call signature

Step 1 of the pass catalogue was mechanical: recompile every scored body with `distance_map`'s own ladder, keep the
image's word and our word at the **first** difference, and pair them. 2 552 of 2 697 scored bodies produced a pair.
The pairs were then split by operand — same registers with a different immediate is a different phenomenon from a
different register with the same immediate, and only the second is allocation.

## The classes

| target → ours | bodies | words | of which… |
| --- | --- | --- | --- |
| `addiu` → `addiu` | **632** | 83 325 | **92 % differ in the immediate only** |
| `sw` → `sw` | 259 | 31 129 | 83 % register + immediate |
| `lbu` → `lb` | 236 | 14 026 | **signedness** — unsigned load where we emit signed |
| `lui` → `lui` | 216 | 10 621 | 42 % register only, 33 % immediate only |
| `beq` → `beq` | 124 | 13 432 | **99 % immediate only** |
| `addu` → `addu` | 73 | 5 369 | 93 % the destination register differs |
| `lbu` → `lw` | 62 | 3 681 | width, not signedness |
| `beq` → `bne` | 57 | 3 815 | inverted condition |
| `lw` → `lw` | 55 | 3 418 | **89 % register only** |

Position of the first difference: **1 007 at word 0**, 1 541 in the middle, 4 at the last word. So two fifths of the
residue is decided by the **prologue**.

## The biggest class is the stack frame, and it is not a flag

`addiu`→`addiu` is 632 bodies and 21 % of the residue by body count. Splitting it by operand:

- **565 (89 %) are the frame adjustment at word 0** — `addiu sp,sp,-N` on both sides, same registers, different `N`;
- 41 are other registers with a different immediate; 23 other registers, same immediate.

And the direction is consistent: **the image's frame is bigger than ours** — `-112` vs `-24`, `-64` vs `-24`,
`-40` vs `-32`, `-656` vs `-608`. Reading four of them side by side answers why, and it is not the allocator:

| body | target frame | ours | what the extra bytes are |
| --- | --- | --- | --- |
| `ovl_00a43b6:801683d8` (7 words) | −64 | −24 | saves only `ra` and makes one `jal`: the extra **40 bytes are outgoing argument space**, so the callee takes more than four parameters and our draft passes none |
| `ovl_0078c0e:8017cf0c` (1 136 words) | −656 | −608 | 48 bytes more, and the target saves `s3` where we save `s2` — **locals the draft does not declare** |
| `ovl_0087352:80164890` (152 words) | −40 | −32 | same pattern: extra saved register, extra 8 bytes |
| `ovl_007af7a:8017ba84` (69 words) | −32 | −24 | 8 bytes, and the target materialises `a1` before `v0` — a scheduling consequence of the larger frame |

**A stack frame is sized by how many values the source keeps live and how many stack arguments its calls pass.**
Nothing in the flag set adds a local that the C does not declare, or an outgoing slot for an argument the call does
not pass. So the largest single class in the residue is **source fidelity in the draft**, not a compiler pass — and no
lever in `-O`/`-m`/`-G` space can move it.

## What that leaves for the actual allocation cluster

Genuine register-allocation residue — same opcode, same immediate, different register:

| class | bodies |
| --- | --- |
| `lui` → `lui`, register only | 90 |
| `addu` → `addu`, destination differs | 68 |
| `lw` → `lw`, register only | 49 |
| `lbu` → `lbu`, register only | 5 |
| **total** | **212 (8.3 % of the residue)** |

The other large classes are named and are *not* allocation either: **signedness** (`lbu`/`lb`, 236 + width variants
62), **branch polarity** (`beq`/`bne`, 57), and branch/immediate offsets (124) which are a consequence of block sizes
rather than a cause.

## The lever this suggests instead

The frame class points at a mechanism this project can actually implement, and it is not a flag: **read the callee's
own prologue to learn how many stack arguments the call passes, and reserve the same outgoing space.** The callee is
in the image, so the number is measurable rather than guessed — a function that reads `lhu 0x12($sp)` takes at least
five arguments. That is a *call-signature* pass, and on this census it addresses 565 bodies against allocation's 212.

## Numbers

- **2 552 of 2 697** scored bodies paired; **1 007** first differ at word 0, 1 541 in the middle, 4 at the last
- `addiu→addiu` **632** bodies / 83 325 words, **565** of them the frame adjustment, image frame consistently larger
- allocation class **212 bodies (8.3 %)**; signedness **298**; branch polarity **57**
- nothing changed in any fixture: this is a classification of the existing `distance.json`, and no body was banked
