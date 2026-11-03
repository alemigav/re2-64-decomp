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
import re
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
# The four codegen classes the corpus does NOT cover, and why. This is a refusal with a measurement behind
# it, not an omission: a probe needs a real function whose C is recoverable, and for these four the cartridge
# does not supply one at the sizes that make reconstruction cheap.
CLASSES_WITHOUT_A_PROBE = {
    # the switch class is probed by `switch_head()` below rather than by the generic loop: it needs the jump
    # table placed at the image's table address, which the generic link script does not do.
    "struct copy": "no function in the 36 images copies three consecutive words between two pointers, and the "
                   "eight-word copy this corpus can compile (0 hits in every image) is not there either",
    "integer divide": "candidate 0x8006e8bc is a *fragment*: it loads through s1, divides by s0 and ends in "
                      "`j 0x8006b...` — a tail jump, so the range boundary is inside a larger function",
    "floating point": "candidate 0x80083e60 is a fragment too: it computes with f2, which no argument "
                      "register carries, so its inputs come from before the range start",
}
PROBES = [
    ("p1", "void probe_empty(void) {}", 0x80029390, 8, "empty body"),
    ("p2", "int probe_second(int a, int b) { return b; }", 0x80035E34, 8, "return an argument"),
    # the image branches `beq` (skip the store when zero), so the source condition is `!= 0`; the globals are
    # named by their real addresses, which is what lets the linker script place them from the names
    ("p3", "extern int D_801314CC;\nextern int D_801344C0;\n"
           "void probe_cond_store(void) { if (D_801314CC != 0) { D_801344C0 = 1; } }",
     0x80025D60, 32, "conditional global store (relocation-bearing -- compared after linking)"),
    ("p4", "void probe_copy(char *d, char *s, int n) { char *e = d + n; do { *d++ = *s++; } while (d < e); }",
     0x80082474, 36, "byte-copy loop (delayed branch; the do-while form is the one that matches)"),
    ("p5", "int probe_ident(int a) { return a; }", None, 0, "identity (the move idiom)"),
]
# (label, kind, toolchain directory, flags). `kind` picks the pipeline: IDO's `cc` assembles with its own as1;
# gcc 2.7.2's `cc1` emits assembly that needs an assembler, and its `move` pseudo-instruction is expanded by
# *that* assembler -- modern gas picks `or`, the cartridge has `addu`, so the pipeline normalises it (below).
PROFILES = [("ido-5.3 G0", "ido", "ido-5.3", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("ido-7.1 G0", "ido", "ido-7.1", ["-O2", "-non_shared", "-mips2", "-G", "0"]),
            ("gcc2.7.2 -O", "gcc", "mips-gcc-2.7.2", ["-O", "-G", "0"]),
            ("gcc2.7.2 -O2", "gcc", "mips-gcc-2.7.2", ["-O2", "-G", "0"]),
            ("gcc2.8.1 -O", "gcc", "mips-gcc-2.8.1", ["-O", "-G", "0"]),
            ("gcc2.8.1 -O2", "gcc", "mips-gcc-2.8.1", ["-O2", "-G", "0"])]


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


MOVE = re.compile(r"^(\s*)move(\s+)(\$\d+),(\$\d+)\s*$", re.M)
GAS = TC / "binutils" / "bin"
# The SDK-era assembler, if it has been built: binutils 2.7's `as` expands `move` to `addu` on its own, which is
# the cartridge's idiom, so the pipeline prefers it and only falls back to modern gas + an explicit rewrite.
AS27 = TC / "src" / "bu27-build" / "gas" / "as.new"
SYM = re.compile(r"^D_([0-9A-Fa-f]{8})$")


def undefined_symbols(obj):
    """Names the object needs from outside, so a linker script can place them.

    This project already names globals by address (`D_801314CC`), so the script can be generated from the names
    instead of maintained by hand -- and if a name does not carry an address, linking fails loudly rather than
    silently placing it at zero.
    """
    d = Path(obj).read_bytes()
    if d[:4] != b"\x7fELF":
        return []
    shoff, = struct.unpack_from(">I", d, 32)
    shentsize, = struct.unpack_from(">H", d, 46)
    shnum, = struct.unpack_from(">H", d, 48)
    secs = [struct.unpack_from(">10I", d, shoff + i * shentsize) for i in range(shnum)]
    out = []
    for s in secs:
        if s[1] != 2:                      # SHT_SYMTAB
            continue
        strtab = secs[s[6]][4]
        for i in range(s[5] // 16):
            name_off, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", d, s[4] + i * 16)
            end = d.index(b"\0", strtab + name_off)
            name = d[strtab + name_off:end].decode("latin-1")
            if shndx == 0 and value == 0 and name:      # SHN_UNDEF
                out.append(name)
    return out


def link_script(probe_addr, obj, workdir):
    names = undefined_symbols(obj)
    lines = ["ENTRY(_start)", "SECTIONS {", "  . = 0x%08X;" % probe_addr,
             "  .text : { *(.text) }",
             '  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.sbss) *(.bss) *(.data) }',
             "}"]
    head = []
    for n in names:
        m = SYM.match(n)
        if not m:
            return None, "undefined symbol %r carries no address in its name" % n
        head.append("%s = 0x%s;" % (n, m.group(1)))
    script = workdir / ("%s_%s.ld" % (workdir.name, probe_addr))
    script.write_text("\n".join(head + lines) + "\n")
    return script, None


def compile_probe(directory, flags, pid, out, kind="ido", flags_addr=None):
    cfile = WORK / ("%s.c" % pid)
    cfile.parent.mkdir(parents=True, exist_ok=True)
    cfile.write_text(PROBES_BY_ID[pid][1] + "\n")
    if kind == "ido":
        cc = TC / directory / "cc"
        if not cc.exists():
            return None, "no toolchain at %s" % cc.relative_to(ROOT)
        env = {"USR_LIB": str(cc.parent), "PATH": "/usr/bin:/bin"}
        proc = subprocess.run([str(cc), "-c"] + flags + ["-o", str(out), str(cfile)],
                              capture_output=True, text=True, env=env)
        if proc.returncode:
            return None, "compile failed"
        return text_of(out), None
    # gcc 2.7.2: cc1 emits assembly, then an assembler encodes it. The `move` pseudo-instruction is expanded by
    # the assembler, and the cartridge's expansion is `addu rd,rs,$zero` where modern gas chooses `or`. The
    # pipeline reproduces the cartridge's expansion explicitly rather than pretending the difference is codegen.
    cc1 = TC / directory / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists():
        return None, "no cc1 at %s" % cc1.relative_to(ROOT)
    asm = WORK / ("%s_%s.s" % (pid, directory))
    proc = subprocess.run([str(cc1), "-quiet"] + flags + ["-mips2", str(cfile), "-o", str(asm)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "cc1 failed"
    if gas == GAS / "mips-linux-gnu-as":
        # only modern gas needs this: binutils 2.7 already expands `move` to `addu`
        text = asm.read_text()
        asm.write_text(MOVE.sub(r"\1addu\2\3,\4,$0", text))
    proc = subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(out), str(asm)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "assemble failed"
    if gas == AS27:
        # binutils 2.7 writes a `.symtab` whose sh_info modern ld rejects ("local symbol at index N >= sh_info"),
        # so the object is rewritten by 2.42's objcopy before linking. Its own ld 2.7 builds but produces an
        # empty file on this host, which is recorded in docs/TOOLCHAIN.md rather than worked around silently.
        fixed = out.with_suffix(".fix.o")
        subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(out), str(fixed)],
                       capture_output=True, text=True)
        if fixed.exists():
            out = fixed
    if flags_addr is None:
        return text_of(out), None
    script, err = link_script(flags_addr, out, WORK)
    if err:
        return None, err
    elf = out.with_suffix(".elf")
    proc = subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(script), "-o", str(elf), str(out)],
                          capture_output=True, text=True, env={"PATH": "/usr/bin:/bin"})
    if proc.returncode:
        return None, "link failed"
    return text_of(elf), None


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


SWITCH_HEAD = {
    "head": 0x8004FD1C, "table": 0x800B8BD0, "bound": 5,
    "source": "int f(int a, int b, int c) { switch (c) { case 0: return a; case 1: return b; "
              "case 2: return a + b; case 3: return a - b; case 4: return a ^ b; } return 0; }",
}


def switch_head():
    """Compile a five-case switch, place `.text` at the head and `.rodata` at the table, and compare.

    The head is ten instructions. Two of them cannot be compared: the **branch offset** (it depends on how large
    the arms are) and the **delay slot** (its content comes from the arm prologue -- in this image
    `addu a3,a0,zero`). What is compared is the bound check and the seven-word table dispatch, which are the
    compiler's business: the `sltiu` bound and index register, the `lui`/`addiu` table address, `sll`, `addu`,
    `lw`, `jr` and its `nop`.
    """
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p6_switch.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(SWITCH_HEAD["source"] + "\n")
    s, o, fx = (WORK / "p6_switch.s", WORK / "p6_switch.o", WORK / "p6_switch.fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(o), str(s)], capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
    ld = WORK / "p6_switch.ld"
    ld.write_text("SECTIONS {\n  . = 0x%08X;\n  .text : { *(.text) }\n  . = 0x%08X;\n  .rodata : { *(.rodata) }\n"
                  "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n"
                  % (SWITCH_HEAD["head"], SWITCH_HEAD["table"]))
    elf = WORK / "p6_switch.elf"
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    want = [image[SWITCH_HEAD["head"] - BASE + 4 * i:SWITCH_HEAD["head"] - BASE + 4 * i + 4] for i in range(10)]
    got = [text_of(elf)[4 * i:4 * i + 4] for i in range(9)]
    # the bound check is word 0 in both; the dispatch run is words 3..9 of the image and 2..8 of ours
    return {"bound_check": want[0] == got[0], "dispatch_run": want[3:10] == got[2:9],
            "delay_slot_image": want[2].hex(), "delay_slot_ours": got[2].hex(),
            "bound": SWITCH_HEAD["bound"]}


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
        for profile, kind, directory, flags in PROFILES:
            work = WORK / ("%s_%s.o" % (pid, profile.replace(" ", "_").replace(".", "")))
            got, err = compile_probe(directory, flags, pid, work, kind, flags_addr=addr)
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
    for profile, kind, directory, flags in PROFILES:
        work = WORK / ("p5_%s.o" % profile.replace(" ", "_").replace(".", ""))
        got, err = compile_probe(directory, flags, "p5", work, kind)
        if not err and len(got) >= 8:
            ido_or = struct.unpack_from(">I", got, 4)[0] & 0x3F
            break
    cases.append((f"IDO emits `or` (funct 0x25) for `int f(int a){{return a;}}` and the cartridge emits "
                  f"`addu` (0x21), so IDO does not match this target",
                  ido_or == 0x25))

    # which profile actually reproduces the image
    per_profile = {}
    for _pid, profile, verdict, _detail in rows:
        per_profile.setdefault(profile, [0, 0])
        per_profile[profile][0] += verdict == "MATCH"
        per_profile[profile][1] += 1
    gcc_best = max((v[0] for k, v in per_profile.items() if k.startswith("gcc")), default=0)
    g28 = max((v[0] for k, v in per_profile.items() if k.startswith("gcc2.8.1")), default=0)
    g27 = max((v[0] for k, v in per_profile.items() if k.startswith("gcc2.7.2")), default=0)
    ido_best = max((v[0] for k, v in per_profile.items() if k.startswith("ido")), default=0)
    cases.append((f"gcc 2.8.1 reproduces {g28} of 4 probes byte-for-byte (gcc 2.7.2: {gcc_best}, IDO: {ido_best})",
                  g28 >= 4))
    cases.append((f"gcc 2.7.2 reproduces {g27} of 4 (it cannot do p3) against IDO's {ido_best} "
                  f"({ {k: '%d/%d' % tuple(v) for k, v in sorted(per_profile.items())} })",
                  g27 == 3 and ido_best <= 1))

    # p3 links now, and its residue is the *assembler's* store expansion, not the compiler's: the image has
    # `lui v1` hoisted into the beq delay slot and sw through v1; we get the same three operations with the
    # address in the assembler temp and the slot filled by the addiu. Reported as numbers, not smoothed.
    p3 = {r[1]: r[2] for r in rows if r[0] == "p3"}
    cases.append((f"p3 is compared **after linking** and the version decides it: {p3} — 2.8.1 materialises the "
                  f"store's address into a general register and schedules it into the delay slot, 2.7.2 leaves it "
                  f"to the assembler's temp",
                  p3.get("gcc2.8.1 -O2") == "MATCH" and p3.get("gcc2.7.2 -O2") == "differ"))

    # 5.3 and 7.1 are not two hypotheses
    same = all(r53[2] == r71[2] and r53[3] == r71[3] for r53, r71 in
               zip([r for r in rows if r[1].startswith("ido-5.3")],
                   [r for r in rows if r[1].startswith("ido-7.1")]))
    cases.append(("IDO 5.3 and 7.1 emit identical code on every probe, so they are one hypothesis",
                  same))

    sw = switch_head()
    cases.append((f"the linked switch head reproduces the bound check and the seven-word table dispatch "
                  f"(bound {SWITCH_HEAD['bound']}; the delay slot is the arm prologue: image "
                  f"{sw['delay_slot_image'] if sw else '-'} vs ours {sw['delay_slot_ours'] if sw else '-'})",
                  bool(sw) and sw["bound_check"] and sw["dispatch_run"]))

    cases.append((f"the {len(CLASSES_WITHOUT_A_PROBE)} remaining uncovered classes are refused with a reason, "
                  f"not silently dropped ({', '.join(sorted(CLASSES_WITHOUT_A_PROBE))})",
                  len(CLASSES_WITHOUT_A_PROBE) == 3
                  and all(len(v) > 40 for v in CLASSES_WITHOUT_A_PROBE.values())))

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
        print("\nclasses with no probe, and why:")
        for cls, why in CLASSES_WITHOUT_A_PROBE.items():
            print("   %-22s %s" % (cls, why[:96]))
        return 0
    if not args.check:
        ap.error("one of --check, --list is required")
    return check()


if __name__ == "__main__":
    raise SystemExit(main())
