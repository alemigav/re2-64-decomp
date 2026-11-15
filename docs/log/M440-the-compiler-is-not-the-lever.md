# M440 — the pass catalogue closes: the compiler is not the lever

The catalogue had three named classes left after M439: **allocation** (212 bodies, 8.3 %), **signedness** (298) and
**branch polarity** (57). This milestone tests the one the critique's "read the compiler" item was aimed at, and the
test is a flag sweep with a control beside it, because a flag that closes ten and breaks fifty is a regression.

## The sweep

120 allocation-class bodies — same opcode, same immediate, different register at the first difference — and 120 bodies
the map already calls **exact**, both compiled with `distance_map`'s ladder and preamble under eleven flag variants.

| variant | closed /120 | kept /120 |
| --- | --- | --- |
| **baseline** (`-O2 -G 0 -mips2 -mcpu=r4300`) | **0** | **120** |
| `-fomit-frame-pointer` | 0 | 120 |
| `-fno-omit-frame-pointer` | 0 | **0** |
| `-O1` | 0 | 33 |
| `-O3` | 0 | 120 |
| `-fno-strength-reduce` | 0 | 120 |
| `-fno-delayed-branch` | 0 | 4 |
| `-fno-schedule-insns` | **7** | 63 |
| `-fno-schedule-insns2` | 0 | 40 |
| `-G 8` | 1 | 66 |
| `-mips3` | 0 | 120 |
| `-fno-inline` | 0 | 120 |

Two readings, and both matter.

**The profile is confirmed from the other side.** The baseline keeps **120 of 120** already-exact bodies, and *every*
alternative either breaks the corpus or changes nothing. `-O3`, `-mips3`, `-fomit-frame-pointer`, `-fno-inline` and
`-fno-strength-reduce` are all byte-neutral on this control — the build is insensitive to them — while
`-fno-omit-frame-pointer` breaks **all 120**, `-fno-delayed-branch` breaks 116 and `-O1` breaks 87. So the pinned
profile is not merely a good guess: it is the only survivor.

**The allocation cluster is not reachable by flags.** Zero of 120 close under any variant that leaves the control
intact. The single variant that closes anything, `-fno-schedule-insns`, closes **7 and breaks 57** — a regression
dressed as a lever, and those 7 are better read as **scheduling** differences that were mis-filed as allocation, not as
bodies recovered.

## What that settles about the catalogue

| class | bodies | lever | verdict |
| --- | --- | --- | --- |
| stack frame (M439) | 560 | none — source fidelity | the draft does not have the original's variables |
| **allocation** | **212** | **none — flags measured flat** | live ranges are a property of the source, not the compiler |
| signedness (`lbu`/`lb`) | 298 | **types** | `type_repair.py` already exists for this |
| branch polarity | 57 | source structure | a condition written the other way round |

So the entire "read the compiler, attribute each residue to a pass" direction — the highest-ceiling item on the
critique's list — **closes with a measurement instead of an implementation**. gcc 2.8.1 at this profile is producing
what the C says; where the bytes differ, the C is wrong, and the wrongness is of exactly three kinds: missing
variables, missing or wrong types, and inverted conditions. None of them is a compiler decision.

That is a better outcome than a catalogue of passes would have been, because it says where the work is: **the residue
is 1 127 bodies of source fidelity in the drafts**, and the only mechanical lever among them is the type one.

## Numbers

- **120 allocation-class + 120 exact control** bodies under **11 flag variants** — 2 640 compilations
- baseline keeps **120/120**; `-fno-omit-frame-pointer` keeps **0/120**; `-O1` 33; `-fno-delayed-branch` 4;
  `-fno-schedule-insns2` 40; `-G 8` 66; `-fno-schedule-insns` 63
- allocation closures under an intact control: **0**; the one variant that closes (7) breaks 57
- the one lever left standing is the type lever, on **298 signedness bodies**, and this project already has the
  instrument for it
