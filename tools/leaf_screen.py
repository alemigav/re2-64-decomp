#!/usr/bin/env python3
"""Screen the unmatched leaves for functions a compiler could have produced, and try a draft against one.

Two jobs, both of which used to live in throwaway shell scripts:

  leaf_screen.py --words 6:8 [--json]      list the candidates
  leaf_screen.py --try draft.c --image stage2 --addr 0x80026820 --words 5 [--sym D_X=0x80112780]
  leaf_screen.py --self-test               the reject rules, on synthetic words, with no cartridge

The screen exists because **the smallest "functions" in this corpus are disproportionately hand-written
assembly**: of ten 2–5-word leaves examined by hand in M315, six could not be C at all — a branch to itself,
`k0` writes, the stage-2 entry stub's `at` write, and three CP0 moves. The rules below are exactly what ruled
those out, and they are the whole value of the tool.

`--try` is the drafting loop: it compiles one draft through the canonical pipeline, links it at the function's
address, and prints the words that differ **decoded** rather than as hex. Decode, never eyeball: a rendered
`objdump` line hid a one-bit difference between `sh zero,6(a0)` and `sh a0,6(a0)` (M317), and a rendered branch
target was misread as an offset (M304).

Needs the cartridge for anything that reads bytes (`--words` listing, `--try`); `--self-test` does not.
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
JR_RA = 0x03E00008
CP0 = 0x10
# instructions whose `rt` is a source, not a destination: stores, branches, jumps, coprocessor moves
RT_IS_SOURCE = {0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x2F, 4, 5, 6, 7, 1, 2, 3, 0x11}
AT, K0 = 1, 26
# MIPS III 64-bit-ISA SPECIAL functions. Our cc1 emits `multu` + `mfhi`/`mflo` (32-bit register pairs) for
# `long long` under -mips2, -mips3 AND -mgp64 -- verified in M321 -- so a body containing any of these was
# not produced by this compiler from C. It is hand-written DSP assembly (the three 46-word transforms and the
# 95-word boot routine in this corpus are exactly that).
D64_FUNCTS = {0x1C, 0x1D, 0x1E, 0x1F, 0x2C, 0x2D, 0x2E, 0x2F, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F}

REGS = ("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 "
        "s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra").split()
OPS = {2: "j", 3: "jal", 4: "beq", 5: "bne", 6: "blez", 7: "bgtz", 9: "addiu", 0x0C: "andi",
       0x0D: "ori", 0x0F: "lui", 0x10: "cop0", 0x20: "lb", 0x21: "lh", 0x23: "lw", 0x24: "lbu",
       0x25: "lhu", 0x28: "sb", 0x29: "sh", 0x2B: "sw"}
SPECIAL = {0x00: "sll", 0x02: "srl", 0x03: "sra", 0x08: "jr", 0x09: "jalr", 0x10: "mfhi",
           0x12: "mflo", 0x18: "mult", 0x19: "multu", 0x1A: "div", 0x1B: "divu", 0x20: "add",
           0x21: "addu", 0x22: "sub", 0x23: "subu", 0x24: "and", 0x25: "or", 0x26: "xor",
           0x2A: "slt", 0x2B: "sltu"}


def op(w): return (w >> 26) & 0x3F
def rs(w): return (w >> 21) & 0x1F
def rt(w): return (w >> 16) & 0x1F
def rd(w): return (w >> 11) & 0x1F
def fn(w): return w & 0x3F
def imm(w): return w & 0xFFFF
def simm(w):
    v = w & 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


# SPECIAL functions that write no general register (they write hi/lo, or nothing)
NO_GPR_WRITE_FN = {0x08, 0x09, 0x0C, 0x0D, 0x0F, 0x11, 0x13, 0x18, 0x19, 0x1A, 0x1B}


def dest(w: int):
    """The general register an instruction writes, or None. SPECIAL writes `rd`, not `rt` -- checking `rt`
    alone let `sltu $at,$v0,$a1` through, and that was a real hand-written function (M319)."""
    if op(w) == 0:
        return None if fn(w) in NO_GPR_WRITE_FN else rd(w)
    if op(w) in RT_IS_SOURCE:
        return None
    return rt(w)


def why_rejected(words: list[int], addr: int = 0) -> str | None:
    """None when a compiler could have produced `words`; otherwise the first rule that rules it out."""
    if not any(w == JR_RA for w in words[-3:]):
        return "no trailing jr ra"
    for i, w in enumerate(words):
        if op(w) == CP0:
            return "cp0 access"
        if op(w) == 0 and fn(w) in D64_FUNCTS:
            return "MIPS III 64-bit op (this cc1 never emits it from C)"
        # `b .` assembles as `beq $0,$0,-1`; `j .` as a self-targeting j
        if op(w) == 4 and rs(w) == 0 and rt(w) == 0 and simm(w) == -1:
            return "branch to itself"
        if op(w) == 2 and (((w & 0x3FFFFFF) << 2) | (addr & 0xF0000000)) == addr:
            return "branch to itself"
        if dest(w) in (AT, K0):
            return "writes $at/$k0"
        if op(w) == 0 and fn(w) in (8, 9) and rs(w) in (AT, K0):
            return "jumps through $at/$k0"
    return None


def gloss(w: int, pc: int = 0) -> str:
    """A one-line reading of an instruction: mnemonic, operands, and the fields that matter."""
    o, f = op(w), fn(w)
    if o == 0:
        name = SPECIAL.get(f, "special&0x%02x" % f)
        if name in ("jr", "jalr"):
            return "%s $%s" % (name, REGS[rs(w)])
        if name in ("mult", "multu", "div", "divu"):
            return "%s $%s,$%s" % (name, REGS[rs(w)], REGS[rt(w)])
        if name in ("mfhi", "mflo"):
            return "%s $%s" % (name, REGS[rd(w)])
        if name in ("sll", "srl", "sra"):
            return "%s $%s,$%s,%d" % (name, REGS[rd(w)], REGS[rt(w)], (w >> 6) & 0x1F)
        return "%s $%s,$%s,$%s" % (name, REGS[rd(w)], REGS[rs(w)], REGS[rt(w)])
    name = OPS.get(o, "op&0x%02x" % o)
    if o in (2, 3):
        return "%s 0x%08x" % (name, ((w & 0x3FFFFFF) << 2) | (pc & 0xF0000000))
    if o in (4, 5):
        return "%s $%s,$%s,%+d" % (name, REGS[rs(w)], REGS[rt(w)], simm(w))
    if o in (6, 7):
        return "%s $%s,%+d" % (name, REGS[rs(w)], simm(w))
    if o == 0x10:
        return "cop0 rs=%d rt=$%s rd=%d" % (rs(w), REGS[rt(w)], rd(w))
    if name in ("lui",):
        return "lui $%s,0x%04x" % (REGS[rt(w)], imm(w))
    if o in (0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B):
        return "%s $%s,%d($%s)" % (name, REGS[rt(w)], simm(w), REGS[rs(w)])
    return "%s $%s,$%s,0x%04x" % (name, REGS[rt(w)], REGS[rs(w)], imm(w))


def load_probe():
    spec = importlib.util.spec_from_file_location("_cp_screen", ROOT / "tools" / "compile_probe.py")
    cp = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cp)
    return cp


def body_of(cp, inv, image: str, addr: int, words: int):
    win = cp.image_window(image, inv)
    if win is None:
        return None
    blob, base = win
    return [int.from_bytes(blob[addr - base + 4 * i:addr - base + 4 * i + 4], "big")
            for i in range(words)]


def called_report(lo: int, hi: int) -> list[dict]:
    """Entries rejected as "no `jr ra`" that the call graph *references* -- i.e. truncated extents, not stubs.

    The screen can only see a body, so "no return" reads as hand-written assembly. The call graph settles it: a
    function with 96 `jal` sites is not a stub, it is a function whose census extent stops early. Walk forward to
    the first `jr ra` and report the true extent, so the defect is a work item rather than a skip (M320).
    """
    cp = load_probe()
    inv = cp.image_inventory()
    graph = ROOT / "manifests" / "call_graph.json"
    if inv is None or not graph.exists():
        return []
    refs = {}
    for e in json.loads(graph.read_text()).get("edges", []):
        d = e.get("dst")
        if isinstance(d, str):
            refs[d.lower()] = refs.get(d.lower(), 0) + 1
    out = []
    for r in screen(lo, hi, include_rejected=True):
        if r["why"] is None:
            continue
        key = ("%s:%s" % (r["image"], r["address"])).lower()
        if not refs.get(key):
            continue
        a = int(r["address"], 16)
        words = body_of(cp, inv, r["image"], a, 96) or []
        true, spins = None, False
        for i, w in enumerate(words):
            # A self-branch never returns, so the walk must stop there: `boot:0x80000518` is a two-word
            # `idle_spin`, and walking past it once reported `main`'s 30 words as its extent (M322).
            if op(w) == 4 and rs(w) == 0 and rt(w) == 0 and simm(w) == -1:
                spins = True
                break
            if op(w) == 2 and (((w & 0x3FFFFFF) << 2) | (a & 0xF0000000)) == a:
                spins = True
                break
            if w == JR_RA:
                true = i + 2
                break
        out.append({"image": r["image"], "address": r["address"], "census_words": r["words"],
                    "true_words": true, "spins": spins, "callers": refs[key], "why": r["why"]})
    out.sort(key=lambda r: -r["callers"])
    return out


def screen(lo: int, hi: int, include_rejected: bool = False) -> list[dict]:
    cp = load_probe()
    inv = cp.image_inventory()
    index = ROOT / "manifests" / "code_index.json"
    if inv is None or not index.exists():
        raise SystemExit("the corpus is not built (need build/elfs/images.json and manifests/code_index.json)")
    out = []
    for img in json.loads(index.read_text())["images"]:
        for f in img.get("functions_list", []):
            if f.get("status") == "recovered" or f.get("callees"):
                continue
            n = f.get("size", 0) // 4
            if not (lo <= n <= hi):
                continue
            a = f["address"] if isinstance(f["address"], int) else int(f["address"], 16)
            words = body_of(cp, inv, img["name"], a, n)
            if words is None:
                continue
            why = why_rejected(words, a)
            if why is not None and not include_rejected:
                continue
            out.append({"image": img["name"], "address": "0x%08x" % a, "words": n, "why": why})
    out.sort(key=lambda r: (r["words"], r["address"]))
    return out


def try_draft(cp, draft: Path, image: str, addr: int, words: int, syms, cc1_extra=()) -> int:
    inv = cp.image_inventory()
    win = cp.image_window(image, inv)
    if win is None:
        print("no image %s" % image, file=sys.stderr)
        return 2
    blob, base = win
    cc1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    scratch = ROOT / "build" / "probe"
    scratch.mkdir(parents=True, exist_ok=True)
    d = Path(tempfile.mkdtemp(prefix="try_", dir=str(scratch)))
    c = d / "f.c"
    c.write_text(draft.read_text())
    s, o, fx, elf = d / "f.s", d / "f.o", d / "f.fix.o", d / "f.elf"
    # M334: `--cc1-arg` exists because "is this allocation a wall?" is a question about *flags*, and the only
    # honest way to ask it is to compile the same draft again with one flag moved. The assembler and linker
    # pipeline is unchanged, so a difference in the words is a difference the compiler made.
    for cmd in ([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300"]
                + list(cc1_extra) + [str(c), "-o", str(s)],
                [str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)]):
        # M373: `errors="replace"`. M356's note claimed this crash ("`cc1` wrote non-UTF-8 bytes to stderr and the
        # tool died with a traceback") was fixed by decoding leniently; it was not, and the file's last touch was
        # M334 -- so for seventeen milestones a committed note described a tree that did not exist. A tool that
        # cannot say *why* a compile failed is the M351 defect, and it is now also a self-test case.
        r = _run(cmd)
        if r.returncode:
            print("compile failed: %s" % (r.stderr.strip().splitlines() or ["?"])[0], file=sys.stderr)
            return 2
    cp.normalise_object(o)
    subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
    (d / "l.ld").write_text(
        "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
        "*(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) *(.rodata) *(.gnu.attributes) }\n}\n" % addr
        + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms))
    if subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(d / "l.ld"), "-o", str(elf), str(fx)],
                      capture_output=True).returncode:
        print("link failed (a missing symbol?)", file=sys.stderr)
        return 2
    got = cp.text_of(elf)
    ours = [int.from_bytes(got[4 * i:4 * i + 4], "big") for i in range(len(got) // 4)]
    want, short = [], False
    for _i in range(words):
        _sl = blob[addr - base + 4 * _i:addr - base + 4 * _i + 4]
        if len(_sl) < 4:
            short = True
            break
        want.append(int.from_bytes(_sl, "big"))
    if short:
        print("the function runs past the %s window (%d words available of %d)"
              % (image, len(want), words), file=sys.stderr)
        return 2
    same = sum(1 for a, b in zip(want, ours) if a == b)
    print("%d/%d words identical (%d compiled)" % (same, words, len(ours)))
    if same != words:
        for i in range(min(words, len(ours))):
            if want[i] == ours[i]:
                continue
            pc = addr + 4 * i
            print("  %2d  0x%08x  had  %-26s  ours %-26s"
                  % (i, pc, gloss(want[i], pc), gloss(ours[i], pc)))
    return 0 if same == words else 1


def _run(cmd):
    """One subprocess whose stderr is decoded leniently (M373).

    `cc1` and the assembler both write raw bytes, and a draft that fails to compile is exactly when their stderr is
    most interesting -- so a strict decode turns the tool's most useful message into a traceback. Kept as a named
    helper so the self-test can aim at it directly instead of at a call site.
    """
    return subprocess.run(cmd, capture_output=True, text=True, errors="replace")


def self_test() -> int:
    cases = []
    cases.append(("a clean leaf passes (jr ra + delay slot)", why_rejected([JR_RA, 0x00000000], 0) is None))
    cases.append(("a body with no jr ra is rejected", why_rejected([0x24020001, 0x00000000], 0) == "no trailing jr ra"))
    cases.append(("a CP0 access is rejected (mfc0 v0,$9)", why_rejected([0x40026000, JR_RA, 0], 0) == "cp0 access"))
    cases.append(("a branch to itself is rejected (b .)", why_rejected([0x1000FFFF, JR_RA, 0], 0) == "branch to itself"))
    cases.append(("a MIPS III 64-bit op is rejected (dmult), because this cc1 cannot emit one from C",
                  why_rejected([0x0189001C, JR_RA, 0], 0).startswith("MIPS III 64-bit op")))
    cases.append(("a write to $at is rejected (lui at,0x8001)", why_rejected([0x3C018001, JR_RA, 0], 0) == "writes $at/$k0"))
    cases.append(("a write to $k0 is rejected (addiu k0,k0,20480)", why_rejected([0x275A5000, JR_RA, 0], 0) == "writes $at/$k0"))
    cases.append(("a jump through $at is rejected (jr at, with jr ra present)",
                  why_rejected([0x00200008, JR_RA, 0], 0) == "jumps through $at/$k0"))
    cases.append(("a store to (a0) passes: rt is a source, not a destination",
                  why_rejected([0xA0850004, JR_RA, 0xA0860005], 0) is None))
    cases.append(("a SPECIAL write to $at is rejected through rd (sltu at,v0,a1)",
                  why_rejected([0x0045082B, JR_RA, 0], 0) == "writes $at/$k0"))
    cases.append(("the gloss decodes a store's offset and base", gloss(0xA4800006) == "sh $zero,6($a0)"))
    cases.append(("the gloss distinguishes that from the same store of $a0",
                  gloss(0xA4840006) == "sh $a0,6($a0)" and gloss(0xA4840006) != gloss(0xA4800006)))

    # M373: the case that would have caught the M356 note. A subprocess writing invalid UTF-8 to stderr must come
    # back as text with replacement characters, never as `UnicodeDecodeError`; reverting `_run` to a strict decode
    # makes this return False instead of crashing the self-test.
    def _non_utf8_stderr():
        try:
            r = _run([sys.executable, "-c", r"import sys; sys.stderr.buffer.write(b'\xff\xfe\x80')"])
        except UnicodeDecodeError:
            return False
        return "\ufffd" in r.stderr

    cases.append(("a non-UTF-8 stderr is decoded leniently, not raised", _non_utf8_stderr()))
    bad = 0
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d leaf-screen case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--words", default="2:8", help="MIN:MAX word count (default 2:8)")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--called", action="store_true",
                    help="entries rejected as 'no jr ra' but referenced by the call graph (truncated extents)")
    ap.add_argument("--try", dest="draft", metavar="DRAFT.c")
    ap.add_argument("--image")
    ap.add_argument("--addr")
    ap.add_argument("--count", type=int, help="expected word count, for --try")
    ap.add_argument("--sym", action="append", default=[])
    ap.add_argument("--cc1-arg", action="append", default=[],
                    help="extra cc1 argument for --try (repeatable); the assembler and linker are unchanged")
    a = ap.parse_args(argv)

    if a.self_test:
        return self_test()

    if a.draft:
        if not (a.image and a.addr and a.count):
            print("--try needs --image, --addr and --count", file=sys.stderr)
            return 2
        syms = []
        for s in a.sym:
            k, v = s.split("=")
            syms.append((k, int(v, 16)))
        return try_draft(load_probe(), Path(a.draft), a.image, int(a.addr, 16), a.count, syms, a.cc1_arg)

    lo, _, hi = a.words.partition(":")
    if a.called:
        rows = called_report(int(lo), int(hi or lo))
        if a.json:
            print(json.dumps(rows, indent=1))
        else:
            print("%-13s %-11s %-6s %-5s %s" % ("image", "address", "census", "true", "callers"))
            for r in rows:
                print("%-13s %s %5sw %4s %6d%s" % (r["image"], r["address"], r["census_words"],
                                                   r["true_words"], r["callers"],
                                                   "  (never returns: self-branch)" if r["spins"] else ""))
            print("%d truncated extent(s) at %s words" % (len(rows), a.words))
        return 0
    rows = screen(int(lo), int(hi or lo))
    if a.json:
        print(json.dumps(rows, indent=1))
    else:
        for r in rows:
            print("%-14s %s  %2d words" % (r["image"], r["address"], r["words"]))
        print("%d candidate(s) at %s words" % (len(rows), a.words))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
