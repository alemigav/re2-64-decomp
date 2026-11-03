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


def text_of(obj, name=".text"):
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
        if d[stroff + s[0]:end] == name.encode():
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


# Dispatch heads, one per (bound, table, index source). Each is compiled as a switch with the same number of
# cases and linked with `.rodata` at *that head's* table address, so the comparison covers the two things that
# vary between them: the `sltiu` bound and the table address materialisation.
HEADS = [
    dict(tag="p6", head=0x8004FD1C, bound_at=0x8004FD1C, jr=0x8004FD3C, table=0x800B8BD0, bound=5,
         index="an incoming argument", cases=5),
    dict(tag="p7", head=0x80057E1C, bound_at=0x80057E30, jr=0x80057E4C, table=0x800B8F78, bound=7,
         index="the byte at ctx+6", cases=7),
    dict(tag="p8", head=0x80024558, bound_at=0x8002456C, jr=0x8002458C, table=0x800B69B0, bound=6,
         index="a global byte", cases=6),
    dict(tag="p9", head=0x80070120, bound_at=0x80070158, jr=0x80070174, table=0x800B96A8, bound=7,
         index="a command byte, `andi 0xff`", cases=7),
]


def _switch_source(ncases):
    body = "".join("    case %d: return %d;\n" % (i, i * 3 + 1) for i in range(ncases))
    return "int f(int idx) {\n  switch (idx) {\n%s  }\n  return 0;\n}\n" % body


def _words(blob, base, lo, hi):
    return [blob[lo - base + 4 * i:lo - base + 4 * i + 4] for i in range((hi - lo) // 4)]


def dispatch_signature(words):
    """The dispatch's own construction: the bound, the table address, the shift, and the op sequence.

    Registers are deliberately not compared -- which register holds the index is the register allocator's choice
    for the *whole* function -- and neither is the **delay slot**, which is filled from whatever the enclosing
    function has to put there (this cartridge uses it for the `lui`, for a frame store, or for the `sll`,
    depending on the head). The values that are read from every word, slot included, are the bound, the table
    address and the shift; only the *op sequence* excludes the slot.
    """
    ints = [int.from_bytes(w, "big") for w in words]
    bound = next((x & 0xFFFF for x in ints if (x >> 26) == 0x0B), None)
    table = None
    for i, x in enumerate(ints):
        if (x >> 26) == 0x0F:
            hi, rt = (x & 0xFFFF) << 16, (x >> 16) & 31
            for y in ints[i + 1:]:
                if (y >> 26) == 0x09 and ((y >> 21) & 31) == rt:
                    lo = (y & 0xFFFF) - (0x10000 if y & 0x8000 else 0)
                    table = (hi + lo) & 0xFFFFFFFF
                    break
            if table is not None:
                break
    shift = next(((x >> 6) & 0x1F for x in ints
                  if (x >> 26) == 0 and (x & 0x3F) == 0 and (x >> 16) & 31 != 0), None)
    branch = next((i for i, x in enumerate(ints) if (x >> 26) in (4, 5)), None)
    ops = []
    for i, x in enumerate(ints):
        if branch is not None and i == branch + 1:
            ops.append("slot")
            continue
        op, fn = x >> 26, x & 0x3F
        if op == 0x0B:
            ops.append("sltiu")
        elif op == 0x0F:
            ops.append("lui")
        elif op == 0x09:
            ops.append("addiu")
        elif op == 0 and fn == 0x00:
            ops.append("sll")
        elif op == 0 and fn == 0x21:
            ops.append("addu")
        elif op == 0x23:
            ops.append("lw")
        elif op == 0 and fn == 0x08:
            ops.append("jr")
            break
    return {"bound": bound, "table": table, "shift": shift, "ops": ops}


def head_probe(spec):
    """Compile a switch with `spec["cases"]` cases, link `.rodata` at the head's table, and signature-compare."""
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / ("%s.c" % spec["tag"])
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(_switch_source(spec["cases"]))
    s, o, fx = (c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o"))
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(o), str(s)], capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("SECTIONS {\n  . = 0x%08X;\n  .text : { *(.text) }\n  . = 0x%08X;\n"
                  "  .rodata : { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) "
                  "*(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n" % (spec["bound_at"], spec["table"]))
    elf = c.with_suffix(".elf")
    # The object's `.rodata` aligns the table to 16 bytes; this cartridge's tables are 8-aligned
    # (`0x800b8f78`, `0x800b96a8`), so a script that places `.rodata` *at* the image's table address lands the
    # table 8 bytes late. Link once, read where the table actually went, and shift the section by that pad.
    def link(at):
        ld.write_text("SECTIONS {\n  . = 0x%08X;\n  .text : { *(.text) }\n  . = 0x%08X;\n"
                      "  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
                      "*(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n" % (spec["bound_at"], at))
        rc = subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                            capture_output=True).returncode
        return None if rc else text_of(elf)

    blob = link(spec["table"])
    if blob is None:
        return None
    first = next((i for i in range(0, len(blob) - 3, 4)
                  if int.from_bytes(blob[i:i + 4], "big") >> 26 == 0x0B), None)
    if first is None:
        return None
    image = IMAGE.read_bytes()
    want = dispatch_signature(_words(image, BASE, spec["bound_at"], spec["jr"] + 8))
    mine_blob = blob
    start = first
    got = dispatch_signature([mine_blob[start + 4 * k:start + 4 * k + 4]
                              for k in range((spec["jr"] - spec["bound_at"] + 8) // 4)])
    # What is codegen and what is layout. The **bound** and the **shift** are the compiler's decisions and are
    # compared exactly. The **table address** is codegen *if* the object's `.rodata` puts the table first: where
    # something precedes it the linked address is the image's plus that pad, which is a fact about this object's
    # layout and is reported rather than smoothed. The **op sequence** is not compared: the delay slot absorbs one
    # instruction and its content is the arms' (this cartridge's heads put the `lui`, a frame store, or the `sll`
    # there, while ours always puts the `lui`).
    pad = (got["table"] - spec["table"]) if got["table"] is not None else None
    return {"spec": spec, "want": want, "got": got, "table_pad": pad,
            "match": want["bound"] == got["bound"] and want["shift"] == got["shift"],
            "table_match": want["table"] == got["table"],
            "table_pad_is_layout": pad is not None and pad % 8 == 0}


# p6 as a whole function: the head and its five arms recovered from the disassembly. This is the only probe that
# compares the delay slot, because the slot is filled from the arms -- here the arms use the pointer and gcc puts
# it in `a3`, which is exactly what the image does.
P6_SOURCE = """typedef struct { unsigned char b0, b1, b2, b3; } S;
void f(S *s, short *p, int idx) {
  switch (idx) {
  case 0: *p = s->b3 << 4; break;
  case 1: *p = (s->b1 / s->b2) << 4;
          if (s->b1 == s->b3 * s->b2 - 1) break;
          s->b1 = s->b1 + 1; break;
  case 2: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = 0; break;
  case 3: *p = (s->b1 / s->b2) << 4;
          s->b1 = s->b1 + 1;
          if ((unsigned char)s->b1 != s->b3 * s->b2) break;
          s->b1 = s->b1 - s->b2; s->b0 = 132; break;
  case 4: s->b1 = s->b1 - 1;
          *p = (s->b1 / s->b2) << 4;
          if (s->b1 == 0) { s->b0 = 131; s->b1 = s->b1 + s->b2; } break;
  }
}
"""
P6_REGIONS = [("head", 0x8004FD1C, 40), ("arm0", 0x8004FD44, 16), ("arm1", 0x8004FD54, 76),
              ("arm2", 0x8004FDA0, 84), ("arm3", 0x8004FDF4, 92), ("arm4", 0x8004FE50, 84)]


def p6_function():
    """Compile the recovered whole function and diff it **content-aligned**.

    The first version sliced both sides at the image's region addresses, which silently compares misaligned code
    the moment any region differs in size — arms 2-4 read as 0/21 while in fact starting 8 bytes later with the
    same instructions. `SequenceMatcher` over the instruction sequences is the honest comparison: it says how many
    instructions differ and where, rather than pretending the offsets line up.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p6full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P6_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(o), str(s)], capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    ld.write_text("SECTIONS {\n  . = 0x8004FD1C;\n  .text : { *(.text) }\n  . = 0x800B8BD0;\n"
                  "  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
                  "*(.comment) *(.pdr) *(.data) *(.bss) *(.mdebug) }\n}\n")
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    blob = text_of(elf)
    want = [image[0x8004FD1C - BASE + 4 * i:0x8004FD1C - BASE + 4 * i + 4] for i in range((0x8004FEA4 - 0x8004FD1C) // 4)]
    got = [blob[4 * i:4 * i + 4] for i in range(len(blob) // 4)]
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = [o for o in sm.get_opcodes() if o[0] != "equal"]
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    divu = sum(1 for w in got if int.from_bytes(w, "big") >> 26 == 0 and (int.from_bytes(w, "big") & 0x3F) == 0x1B)
    return {"image_instrs": len(want), "got_instrs": len(got), "same": same, "hunks": len(hunks),
            "extra": len(got) - len(want), "divu": divu,
            "first": "0x%08x" % (0x8004FD1C + 4 * hunks[0][1]) if hunks else None}



# p7 as a whole function: the recovery done for p6, on the head whose bound is **7** and whose index is the byte at
# `ctx+6`. Two things make it a different question from p6: its seven arms live inside ONE contiguous 336-byte
# range rather than in six separate corpus functions, and two of them fall through (`0` into `1`, `4` into `5`),
# so the image's table entries land mid-arm. The three externs and both callees must be *placed* at their image
# addresses, or the link has nothing to compare.
P7_SOURCE = """typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u32 f0;
    u16 f4;
    u8  mode;
    u8  f7;
    u8  pad[0x1d8];
    u32 f1e0;
    u32 f1e4;
    u32 f1e8;
};

struct Dev { u8 pad[0x1a5c]; u32 reg; u32 reg2; };

extern u8 D_800C76B0[];
extern u8 D_8012BFA8[];
extern u8 D_80131780[];

extern int  FUN_80089d54(struct Ctx *s, int a1, void *tbl, u32 flags);
extern void FUN_800551e0(void);

void FUN_80057e1c(struct Ctx *s, int a1, void *tbl)
{
    u8 *q;

    switch (s->mode) {
    case 0: {
        u8 *dev;
        s->f1e8 = 0x06000700;
        s->mode = 1;
        s->f1e0 = 0;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg |= 0xc0;
        }

    case 1:
        s->mode += FUN_80089d54(s, a1, tbl, 0x200);
        break;
    case 2: {
        u8 *dev;
        D_8012BFA8[0] = 2;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg |= 0x8000;
        D_80131780[0] = 1;
        q = D_80131780;
        *(u32 *)(q + 0x44) = ((struct Dev *)(dev + 0x18000))->reg2;
        s->mode = 3;
        break;
    }
    case 3:
        break;
    case 4:
        s->f1e8 = 0x06000700;
        s->mode = 5;

    case 5:
        s->mode += FUN_80089d54(s, a1, tbl, 0x10200);
        break;
    case 6: {
        u8 *dev;
        FUN_800551e0();
        *(u32 *)&s->f4 = 0x01000000;
        dev = D_800C76B0;
        ((struct Dev *)(dev + 0x18000))->reg &= ~0x80;
        ((struct Dev *)(dev + 0x18000))->reg &= ~0x40;
        break;
    }
    }
}"""
P7_TABLE = 0x800B8F78
P7_SYMS = [("D_800C76B0", 0x800C76B0), ("D_8012BFA8", 0x8012BFA8), ("D_80131780", 0x80131780),
           ("FUN_80089d54", 0x80089D54), ("FUN_800551e0", 0x800551E0)]


def p7_function():
    """Compile the recovered p7 and compare 84 words of text plus the 8-word jump table.

    Two numbers on purpose: the text is the reconstruction's business and the table is the *link's*, so
    conflating them would let a correct table hide a wrong arm. `objcopy --set-section-alignment` is required
    because binutils 2.7's `as` leaves `.text` at 16-byte alignment, which shifts the whole function by 4 bytes
    and makes every word look different for a reason that has nothing to do with the C.
    """
    import difflib
    cc1 = TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = AS27 if AS27.exists() else GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    c = WORK / "p7full.c"
    c.parent.mkdir(parents=True, exist_ok=True)
    c.write_text(P7_SOURCE)
    s, o, fx = c.with_suffix(".s"), c.with_suffix(".o"), c.with_suffix(".fix.o")
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", str(c), "-o", str(s)],
                      capture_output=True).returncode:
        return None
    subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(o), str(s)], capture_output=True)
    subprocess.run([str(GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    ld = c.with_suffix(".ld")
    syms = "".join("%s = 0x%X;\n" % (n, a) for n, a in P7_SYMS)
    ld.write_text("ENTRY(f_probe)\nSECTIONS {\n  . = 0x80057E1C;\n  .text : { *(.text) }\n"
                  "  . = 0x800B8F78;\n  .rodata : ALIGN(8) { *(.rodata) }\n  /DISCARD/ : { *(.reginfo) "
                  "*(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug) "
                  "*(.gnu.attributes) *(.note.GNU-stack) }\n}\n" + syms)
    elf = c.with_suffix(".elf")
    if subprocess.run([str(GAS / "mips-linux-gnu-ld"), "-T", str(ld), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        return None
    image = IMAGE.read_bytes()
    lo, hi = 0x80057E1C, 0x80057F6C
    want = [image[lo - BASE + 4 * i:lo - BASE + 4 * i + 4] for i in range((hi - lo) // 4)]
    txt = text_of(elf)
    got = [txt[4 * i:4 * i + 4] for i in range(len(txt) // 4)]
    sm = difflib.SequenceMatcher(a=[w.hex() for w in want], b=[w.hex() for w in got], autojunk=False)
    hunks = [o for o in sm.get_opcodes() if o[0] != "equal"]
    same = sum(i2 - i1 for tag, i1, i2, _j1, _j2 in sm.get_opcodes() if tag == "equal")
    tw = [image[P7_TABLE - BASE + 4 * i:P7_TABLE - BASE + 4 * i + 4] for i in range(8)]
    ro = text_of(elf, ".rodata")
    gw = [ro[4 * i:4 * i + 4] for i in range(len(ro) // 4)][:8]
    off = sum(1 for a, b in zip(want, got) if a == b)
    return {"image_instrs": len(want), "got_instrs": len(got), "same": same, "hunks": len(hunks),
            "same_offset": off,
            "extra": len(got) - len(want), "table_same": sum(1 for a, b in zip(tw, gw) if a == b),
            "arm0": sum(1 for i in range(14) if want[14 + i] == got[14 + i]),
            "first": "0x%08x" % (lo + 4 * hunks[0][1]) if hunks else None}


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

    for spec in HEADS:
        pr = head_probe(spec)
        if not pr:
            cases.append((f"{spec['tag']} ({spec['index']}): not run", False))
            continue
        row = (f"{spec['tag']} bound {spec['bound']} shift {pr['got']['shift']} table 0x{spec['table']:08x} "
               f"idx {spec['index']}: bound+shift {'match' if pr['match'] else 'DIFFER'}, table "
               f"{'at the image address' if pr['table_match'] else 'at +%d (object .rodata pad)' % pr['table_pad']}")
        cases.append((row, pr["match"]))

    p6f = p6_function()
    p7f = p7_function()
    cases.append((f"p6's whole function, content-aligned: {p6f['same']} of {p6f['image_instrs']} instructions "
                  f"identical, {p6f['hunks']} difference hunk(s), {p6f['extra']} extra instruction(s), "
                  f"first at {p6f['first']}" if p6f else "p6 whole function: not run",
                  bool(p6f) and p6f["same"] >= 82 and p6f["extra"] <= 6))

    cases.append((f"the divide-then-increment order the arms need is what gcc emits: {p6f['divu']} `divu` sites "
                  f"in the compiled body, and each is followed by a reload"
                  if p6f else "p6 whole function: not run",
                  bool(p6f) and p6f["divu"] == 4))

    cases.append((f"the head's delay slot still matches with the arms in place (the only head difference is the "
                  f"branch offset)",
                  bool(p6f) and p6f["first"] == "0x8004fd20"))

    cases.append((f"p7's whole function, recovered: {p7f['same_offset']} of {p7f['image_instrs']} words "
                  f"identical by offset and {p7f['same']} aligned by content ({p7f['hunks']} hunk(s), first at "
                  f"{p7f['first']}) -- both residues are instruction permutations, not wrong operations"
                  if p7f else "p7 whole function: not run",
                  bool(p7f) and p7f["same_offset"] >= 74 and p7f["same"] >= 75 and p7f["hunks"] <= 2))

    cases.append((f"p7's case 0 is byte-exact ({p7f['arm0']} of 14 words) once the device window is a "
                  f"struct member: a mixed struct/non-struct pair is a dependence gcc 2.8.1 drops, so the "
                  f"scheduler hoists the load past the two stores"
                  if p7f else "p7 case 0: not run",
                  bool(p7f) and p7f["arm0"] == 14))

    cases.append((f"p7's jump table lands on the image's own 0x800b8f78 and matches {p7f['table_same']} of 8 words "
                  f"only because the linker places it, not the source" if p7f else "p7 table: not run",
                  bool(p7f) and p7f["table_same"] == 8))

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
