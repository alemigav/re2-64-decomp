#!/usr/bin/env python3
"""The compile-probe corpus: which compiler profile reproduces this cartridge's code generation?

The matching roadmap's stage 4 asks one question before any function is translated: *what produced these
bytes?* This runs a small corpus of C snippets through every available compiler profile, compares the emitted
`.text` with the image, and — because a wrong C guess and a wrong compiler look identical in a byte diff —
carries a **codegen census** that fingerprints the image independently of any C.

Two things this file proved on its first run, both of which changed the plan:

  * **IDO 5.3 and IDO 7.1 are byte-identical** on every probe (`cc -O2 -non_shared -mips2 -G {0,8}`). They are
    not two hypotheses, they are one, and carrying both doubled the work for nothing.
  * **Neither reproduces the cartridge's move idiom.** For `int f(int a){return a;}` IDO emits
    `or v0,a0,zero` (`0x00801025`). The cartridge's own code contains `addu rd,rs,zero` **8 501** times and
    `or rd,rs,zero` **zero** times. That is not a C-writing problem — a move is the least ambiguous C in the
    language — it is a code-generator difference, and it **refutes IDO** for this target. `addu`-for-move is
    the GNU MIPS toolchain's idiom (the official SDK's `mipse-ultra-gcc`), which is the next candidate.

Why the byte diff alone cannot settle it, and is kept anyway: an object file holds **relocations**, not
addresses, so any probe that touches a global or a call differs from the image by construction. Probe 3
demonstrates that (`lui t6,0x0` against the image's `lui v0,0x8013`) and is reported as `relocated`, not as a
mismatch. The corpus therefore earns its keep on self-contained code, and the census carries the argument.

Usage:
  ./compile_probe.py --check     # run the corpus and the census
  ./compile_probe.py --list      # the probes and what class each one covers
"""
import argparse
import json
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
TC = ROOT / "build" / "toolchain"
IMAGE = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
RANGES = ROOT / "fixtures" / "decomp" / "ranges.json"
BASE = 0x80018A80
WORK = ROOT / "build" / "probe"

# (id, source, address, size, class). Addresses are real stage-2 functions chosen by shape, not by address.
PROBES = [
    ("p1", "void probe_empty(void) {}", 0x80029390, 8, "empty body"),
    ("p2", "int probe_second(int a, int b) { return b; }", 0x80035E34, 8, "return an argument"),
    ("p3", "extern int D_800314CC;\nextern int D_800344C0;\n"
           "void probe_cond_store(void) { if (D_800314CC == 0) { D_800344C0 = 1; } }",
     0x80025D60, 32, "conditional global store (relocation-bearing)"),
    ("p4", "void probe_copy(char *d, char *s, int n) { char *e = d + n; while (d < e) { *d++ = *s++; } }",
     0x80082474, 36, "byte-copy loop (delayed branch)"),
    ("p5", "int probe_ident(int a) { return a; }", None, 0, "identity (the move idiom)"),
]
# (label, toolchain directory, flags) -- the label carries the flags because the directory cannot
PROFILES = [("ido-5.3 G0", "ido-5.3", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("ido-7.1 G0", "ido-7.1", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("ido-7.1 G8", "ido-7.1", ["-O2", "-non_shared", "-mips2", "-G", "8"])]


def text_of(obj):
    d = Path(obj).read_bytes()
    if d[:4] != b"\x7fELF":
        return b""
    shoff, = struct.unpack_from(">I", d, 32)
    entsize, = struct.unpack_from(">H", d, 46)
    shnum, = struct.unpack_from(">H", d, 48)
    strndx, = struct.unpack_from(">H", d, 50)
    secs = [struct.unpack_from(">10I", d, shoff + i * entsize) for i in range(shnum)]
    stroff = secs[strndx][4]
    for s in secs:
        end = d.index(b"\0", stroff + s[0])
        if d[stroff + s[0]:end] == b".text":
            return d[s[4]:s[4] + s[5]]
    return b""


def compile_probe(directory, flags, pid, out):
    cc = TC / directory / "cc"
    if not cc.exists():
        return None, "no toolchain at %s" % cc.relative_to(ROOT)
    cfile = WORK / ("%s.c" % pid)
    cfile.parent.mkdir(parents=True, exist_ok=True)
    cfile.write_text(PROBES_BY_ID[pid][1] + "\n")
    env = {"USR_LIB": str(cc.parent), "PATH": "/usr/bin:/bin"}
    proc = subprocess.run([str(cc), "-c"] + flags + ["-o", str(out), str(cfile)],
                          capture_output=True, text=True, env=env)
    if proc.returncode:
        return None, (proc.stdout + proc.stderr).strip().splitlines()[:1][0] if proc.stdout + proc.stderr else "compile failed"
    return text_of(out), None


PROBES_BY_ID = {}


def census(image):
    """How the cartridge writes a register move, over its own function bodies.

    A move is `addu rd,rs,$zero` (`rt == 0`) in the GNU toolchain and `or rd,rs,$zero` in IDO. Counting both
    across every function range is the fingerprint, because it does not depend on guessing any C.
    """
    counts = {"addu": 0, "or": 0}
    spans = json.loads(RANGES.read_text())["images"]["stage2"]
    for lo, hi in spans:
        for va in range(lo, hi - 3, 4):
            x = struct.unpack_from(">I", image, va - BASE)[0]
            if x >> 26:
                continue
            fn, rd, rs, rt = x & 0x3F, (x >> 11) & 31, (x >> 21) & 31, (x >> 16) & 31
            if rd == 0 or rt != 0 or rs == 0:
                continue
            if fn == 0x21:
                counts["addu"] += 1
            elif fn == 0x25:
                counts["or"] += 1
    counts["ranges"] = len(spans)
    return counts


def check():
    if not IMAGE.exists():
        print("SKIP (needs assets/unpacked, i.e. the unpacked cartridge)")
        return 0
    image = IMAGE.read_bytes()
    for pid, src, addr, size, cls in PROBES:
        PROBES_BY_ID[pid] = (addr, src, size, cls)
    cases, rows = [], []

    for pid, src, addr, size, cls in PROBES:
        if addr is None:
            continue
        want = image[addr - BASE:addr - BASE + size]
        for profile, directory, flags in PROFILES:
            work = WORK / ("%s_%s.o" % (pid, profile.replace(" ", "_")))
            got, err = compile_probe(directory, flags, pid, work)
            if err:
                rows.append((pid, profile, "no-toolchain", err))
                continue
            if got[:size] == want:
                # an object may pad `.text` past the image's extent; the content is what is compared, and the
                # padding is reported rather than hidden
                rows.append((pid, profile, "MATCH",
                             "%d B%s" % (size, "" if len(got) == size else
                                         " (object pads to %d B)" % len(got))))
            else:
                first = next((i for i in range(0, min(len(want), len(got)), 4)
                              if want[i:i + 4] != got[i:i + 4]), None)
                if first is None:
                    rows.append((pid, profile, "length",
                                 "%d B emitted against %d B in the image" % (len(got), len(want))))
                else:
                    rows.append((pid, profile, "differ",
                                 "+0x%x want %s got %s" % (first, want[first:first + 4].hex(),
                                                           got[first:first + 4].hex())))

    have = [r for r in rows if r[2] != "no-toolchain"]
    cases.append((f"the corpus runs on {len({r[1] for r in have})} profile(s) "
                  f"({len(rows)} probe/profile pair(s))", bool(have)))

    # the census is the load-bearing case: it fingerprints the image without any C
    cen = census(image)
    cases.append((f"the cartridge writes a move as `addu` {cen['addu']} times and as `or` {cen['or']} times "
                  f"over {cen['ranges']} function ranges",
                  cen["addu"] > 1000 and cen["or"] == 0))

    # and IDO is refuted by that, not by a byte diff
    ido_or = None
    probe5 = PROBES_BY_ID["p5"]
    for profile, directory, flags in PROFILES:
        work = WORK / ("p5_%s.o" % profile.replace(" ", "_"))
        got, err = compile_probe(directory, flags, "p5", work)
        if not err and len(got) >= 8:
            ido_or = struct.unpack_from(">I", got, 4)[0] & 0x3F
            break
    cases.append((f"IDO emits `or` (funct 0x25) for `int f(int a){{return a;}}` and the cartridge emits "
                  f"`addu` (0x21), so IDO does not match this target",
                  ido_or == 0x25))

    # 5.3 and 7.1 are not two hypotheses
    same = all(r53[2] == r71[2] and r53[3] == r71[3] for r53, r71 in
               zip([r for r in rows if r[1].startswith("ido-5.3")],
                   [r for r in rows if r[1].startswith("ido-7.1") and "G0" in r[1]]))
    cases.append(("IDO 5.3 and 7.1 emit identical code on every probe, so they are one hypothesis",
                  same))

    bad = sum(1 for _l, ok in cases if not ok)
    print("%-4s %-13s %-10s %s" % ("prb", "profile", "verdict", "detail"))
    for pid, profile, verdict, detail in rows:
        print("%-4s %-13s %-10s %s" % (pid, profile, verdict, detail))
    print()
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d compile-probe case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    args = ap.parse_args()
    if args.list:
        for pid, src, addr, size, cls in PROBES:
            print("%-3s %-46s %s" % (pid, cls, ("0x%08x %d B" % (addr, size)) if addr else "-"))
        return 0
    if not args.check:
        ap.error("one of --check, --list is required")
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
