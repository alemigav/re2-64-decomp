#!/usr/bin/env python3
"""Patch gcc 2.8.1 for the constant-pool float defect (M261).

A CONST_DOUBLE holds two 32-bit *target-pattern* words, and the fast path in `immed_real_const_1` that stores
one is guarded by `sizeof u == 2 * sizeof (HOST_WIDE_INT)` -- false on a 64-bit host (8 == 16). So SFmode and
DFmode fell through to the "more than two words" path, where a raw bcopy dropped the emulator's packed *internal*
form into the rtx, and every reader decoded it as a target pattern. Two measured symptoms: every constant-pool
float came out as 0, and `mips_const_double_ok` -- which reads the same words -- never chose `li.s`, so the
fix also *changes codegen*, not just data.

Usage: patch_gcc281_fp.py <path to the unpacked gcc-2.8.1 source>
Idempotent: a source that already carries the marker is left alone. Every anchor is required to match exactly
once, so a source that drifts fails loudly instead of being half-patched.
"""
import sys
from pathlib import Path

MARKER = "M261"
EDITS = [
    ('varasm.c', '  if (sizeof u == 2 * sizeof (HOST_WIDE_INT))\n    return immed_double_const (u.i[0], u.i[1], mode);', '  /* M261: a CONST_DOUBLE holds two 32-bit words, and every reader -- including the constant pool -- decodes\n     them as the *target* bit pattern. Store that, and not the emulator\'s packed internal form. The test that\n     used to guard this path, `sizeof u == 2 * sizeof (HOST_WIDE_INT)`, is false on a 64-bit host (8 == 16), so\n     SFmode and DFmode fell through to the "more than two words" path below, where a raw bcopy dropped the\n     packed form into the rtx and every reader decoded it as a pattern: every pool float came out as 0.  */\n#ifdef REAL_VALUE_TO_TARGET_SINGLE\n  if (mode == SFmode || mode == DFmode)\n    {\n      long w0 = 0, w1 = 0;\n\n      if (mode == SFmode)\n\tREAL_VALUE_TO_TARGET_SINGLE (d, w0);\n      else\n\t{\n\t  long w[2];\n\t  REAL_VALUE_TO_TARGET_DOUBLE (d, w);\n\t  w0 = w[0];\n\t  w1 = w[1];\n\t}\n      return immed_double_const (w0, w1, mode);\n    }\n#endif\n\n  if (sizeof u == 2 * sizeof (HOST_WIDE_INT))\n    return immed_double_const (u.i[0], u.i[1], mode);'),
    ('real.h', '#define REAL_VALUE_FROM_CONST_DOUBLE(to, from)\t\t\\\ndo { union real_extract u;\t\t\t\t\\\n     bcopy ((char *) &CONST_DOUBLE_LOW ((from)), (char *) &u, sizeof u); \\\n     to = u.d; } while (0)', '/* M261: the inverse of immed_real_const_1, which now stores the target bit pattern in the two words of a\n   CONST_DOUBLE. Reading them back as a packed emulator value is what made every constant-pool float 0.  */\n#define REAL_VALUE_FROM_CONST_DOUBLE(to, from)\t\t\t\t\\\ndo {\t\t\t\t\t\t\t\t\t\\\n     if (GET_MODE ((from)) == SFmode)\t\t\t\t\t\\\n       (to) = ereal_from_float ((HOST_WIDE_INT) CONST_DOUBLE_LOW ((from)));\t\\\n     else\t\t\t\t\t\t\t\t\\\n       {\t\t\t\t\t\t\t\t\\\n\t HOST_WIDE_INT w_[2];\t\t\t\t\t\t\\\n\t w_[0] = CONST_DOUBLE_LOW ((from));\t\t\t\t\\\n\t w_[1] = CONST_DOUBLE_HIGH ((from));\t\t\t\t\\\n\t (to) = ereal_from_double (w_);\t\t\t\t\\\n       }\t\t\t\t\t\t\t\t\\\n} while (0)'),
    ('varasm.c', '\t  bcopy ((char *) &CONST_DOUBLE_LOW (x), (char *) &u, sizeof u);\n\t  assemble_real (u.d, pool->mode);', '\t  REAL_VALUE_FROM_CONST_DOUBLE (u.d, x);\n\t  assemble_real (u.d, pool->mode);'),
]


def main(argv):
    if len(argv) != 2:
        print("usage: patch_gcc281_fp.py <gcc-2.8.1 source dir>", file=sys.stderr)
        return 2
    src = Path(argv[1])
    texts = {}
    for name, old, new in EDITS:
        p = src / name
        if p not in texts:
            if not p.is_file():
                print("missing: %s" % p, file=sys.stderr)
                return 1
            texts[p] = p.read_text()
        # One-shot per file: the marker is written by the first edit, and a file that carries it is done. The
        # writer edit re-states the lines it replaces, so a per-anchor test cannot see that it has already run --
        # running it twice duplicated the block, which is how this check was found (M261).
        if MARKER in texts[p]:
            continue
        if texts[p].count(old) != 1:
            print("anchor found %d times in %s -- refusing" % (texts[p].count(old), p), file=sys.stderr)
            return 1
        texts[p] = texts[p].replace(old, new, 1)
    changed = [(p, t) for p, t in texts.items() if t != p.read_text()]
    if not changed:
        print("gcc 2.8.1: constant-pool fp patch already applied (M261)")
        return 0
    for p, t in changed:
        p.write_text(t)
    print("gcc 2.8.1: constant-pool fp patch applied (M261)")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
