#!/usr/bin/env python3
"""Score an *external* decompilation corpus against this cartridge, through this project's own pipeline.

The corpus this was written for is `delibrete/Resident-Evil-II-Decompilation-N64` -- 1 525 functions its own
judge calls byte-exact, produced by `decompdecomp` under **eight toolchains over seventy address ranges** and
against a **different ROM file** (`rom.overlays.z64`, sha1 `93187c41…`, not this cartridge's `62ec19be…`).

None of that transfers on trust, and the point of the tool is that it does not have to: every candidate is
compiled with *this* profile (`cc1 -O2 -G 0 -mips2 -mcpu=r4300`, `as -g`) and compared word for word against
*this* cartridge at the address the corpus names. A hit is a hit because it matches, which is the only
currency this repository accepts.

    ./other_corpus.py --report            # ranked table + the transfer rate
    ./other_corpus.py --report --json     # the same, machine-readable
    ./other_corpus.py --self-test         # the parsers, with no corpus and no cartridge

The corpus is never committed: it is somebody else's copyrighted reconstruction of a commercial game, it lives
under gitignored `build/`, and `--report` refuses to run without it rather than reaching for the network.

Three parsers do the work and each exists because the first sweep got it wrong:

  * `strip_preprocessor` -- their sources carry `/* */` comments and `#` directives, and **this cc1 parses
    neither**: it is the compiler proper, not the driver, so any surviving `#` is "undefined or invalid #
    directive" and any surviving comment surfaces as mojibake. `#`-stripping alone leaves a multi-line macro's
    body dangling, hence the order (join continuations, then strip).
  * `symbol_table` -- `func_XXXXXXXX` and `D_XXXXXXXX` names *encode their own vram*, so a `--defsym` for every
    reference can be generated without ever asking the corpus. Their own `functions` map covers the rest,
    including the suffixed names (`func_80036764_ovl_01_510`) whose address is in the prefix and not the tail.
  * `function_names` -- a `src/<name>.c` may hold several functions; only files with exactly one definition are
    scored, because the target's offset inside a multi-function unit is not published.
"""
from __future__ import annotations

import argparse
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_CORPUS = ROOT / "build" / "other-corpus"

# The types and macros their `include/common.h` establishes. The header itself is read from the corpus when it
# is present; these are the fallbacks the self-test exercises, kept minimal on purpose.
FALLBACK_TYPES = """typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
"""

MACROS = """
#define M2C_FIELD(expr,t,o) (*(t)((s8*)(expr)+(o)))
#define M2C_BITWISE(t,e) ((t)(e))
#define M2C_ERROR(d) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
"""

COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
VRAM_NAME = re.compile(r"\b(?:func|D)_([0-9A-Fa-f]{8})(?:_[A-Za-z0-9_]+)*\b")
SYMBOL_NAME = re.compile(r"\b((?:func|D)_[0-9A-Fa-f]{8}(?:_[A-Za-z0-9_]+)*)\b")
# a definition: a return type, a name, a parameter list and an opening brace at column 0
DEFINITION = re.compile(r"^[A-Za-z_][A-Za-z0-9_ \*]*?\b(\w+)\s*\([^;{]*\)\s*\{", re.M)


def strip_preprocessor(text: str) -> str:
    """Remove comments and every `#` line, joining `\\`-continued lines first so no macro body is orphaned."""
    text = COMMENT.sub("", text)
    joined, buffer = [], ""
    for line in text.splitlines():
        if line.rstrip().endswith("\\"):
            buffer += line.rstrip()[:-1]
            continue
        joined.append(buffer + line)
        buffer = ""
    if buffer:
        joined.append(buffer)
    return "\n".join(line for line in joined if not line.lstrip().startswith("#"))


def _split_args(text: str, start: int):
    """The argument list of the call whose `(` is at `start`, as a list, plus the index of its closing paren."""
    depth, args, current, i = 0, [], [], start
    while i < len(text):
        ch = text[i]
        if ch == "(":
            depth += 1
            if depth == 1:
                i += 1
                continue
        elif ch == ")":
            depth -= 1
            if depth == 0:
                args.append("".join(current))
                return args, i
        elif ch == "," and depth == 1:
            args.append("".join(current))
            current = []
            i += 1
            continue
        current.append(ch)
        i += 1
    return None, start


def expand_macros(text: str) -> str:
    """Expand the few `M2C_*` macros by hand, because **this cc1 has no preprocessor**: a `#define` is silently
    ignored and an unexpanded `M2C_FIELD(a, s32 *, 4)` is a parse error at the comma. Measured, not assumed:
    `#define X 5` followed by `return X;` compiles to "`X' undeclared", so no macro of theirs ever fired.
    """
    forms = {"M2C_FIELD": lambda a: "(*(%s)((s8 *)(%s) + (%s)))" % (a[1], a[0], a[2]),
             "M2C_BITWISE": lambda a: "((%s)(%s))" % (a[0], a[1]),
             "M2C_ERROR": lambda a: "(0)",
             "M2C_OVERFLOW": lambda a: "(0)"}
    for _ in range(8):
        changed = False
        for name, render in forms.items():
            pos = 0
            while True:
                at = text.find(name + "(", pos)
                if at < 0:
                    break
                before = text[at - 1] if at else " "
                if before.isalnum() or before == "_":
                    pos = at + len(name)
                    continue
                args, end = _split_args(text, at + len(name))
                if args is None:
                    pos = at + len(name)
                    continue
                text = text[:at] + render([a.strip() for a in args]) + text[end + 1:]
                pos = at + 1
                changed = True
        if not changed:
            break
    return text


def vram_of(name: str):
    """The vram a corpus name declares (`func_800042F4`, `func_80036764_ovl_01_510` -> 0x80036764), or None."""
    m = re.search(r"(?:func|D)_([0-9A-Fa-f]{8})", name)
    if not m:
        return None
    value = int(m.group(1), 16)
    return value if 0x80000000 <= value < 0x80200000 else None


def symbol_table(text: str, known: dict) -> dict:
    """Every `func_`/`D_` name the text mentions, resolved to an address; `known` wins where it has the name."""
    out = {}
    for name in set(SYMBOL_NAME.findall(text)):
        if name in known:
            out[name] = known[name]
            continue
        value = vram_of(name)
        if value is not None:
            out[name] = value
    return out


def function_names(text: str) -> list:
    return DEFINITION.findall(strip_preprocessor(text))


def compile_and_compare(probe, source_text, addr, words, syms, images):
    """(identical words, image) for one source at one address, or (None, reason)."""
    scratch = Path(tempfile.mkdtemp(prefix="other_", dir=str(probe.WORK)))
    c, s, o, fx, elf = scratch / "f.c", scratch / "f.s", scratch / "f.o", scratch / "f.fix.o", scratch / "f.elf"
    c.write_text(source_text)
    cc1 = probe.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = probe.AS27 if probe.AS27.exists() else probe.GAS / "mips-linux-gnu-as"
    for cmd in ([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                [str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)]):
        if subprocess.run(cmd, capture_output=True).returncode:
            return None, "compile"
    probe.normalise_object(o)
    subprocess.run([str(probe.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)

    # `.rodata` is *placed*, not discarded: their sources carry constant pools and a discarded section is a
    # link error, not a difference in the code being measured (M356).
    (scratch / "l.ld").write_text(
        "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = 0x90000000;\n"
        "  .rodata : { *(.rodata) *(.rodata.*) }\n  .data : { *(.data) *(.bss) *(.sbss) }\n"
        "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) }\n}\n"
        % addr + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms.items()))
    if subprocess.run([str(probe.GAS / "mips-linux-gnu-ld"), "-T", str(scratch / "l.ld"), "-o", str(elf),
                       str(fx)], capture_output=True).returncode:
        return None, "link"
    got = probe.text_of(elf)
    size, best = 4 * words, (0, None)
    for name, base, blob in images:
        want = blob[addr - base:addr - base + size]
        if len(want) < size:
            continue
        same = sum(1 for i in range(0, size, 4) if want[i:i + 4] == got[i:i + 4])
        if same > best[0]:
            best = (same, name)
    if best[1] is None:
        return None, "outside"
    return best, "ok"


def build_candidates(probe):
    inventory = probe.image_inventory()
    out = []
    for name, entry in inventory.items():
        window = probe.image_window(name, inventory)
        if window:
            out.append((name, entry["base"], window[0]))
    return out


def report(corpus: Path, as_json: bool) -> int:
    spec = __import__("importlib.util").util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
    probe = __import__("importlib.util").util.module_from_spec(spec)
    spec.loader.exec_module(probe)
    data = json.loads((corpus / "decompdecomp.json").read_text())
    matches, functions, layout = data["verification"]["matches"], data["functions"], {x["vram"]: x for x in data["layout"]}
    known = {n: f["vram"] for n, f in functions.items()}
    for sym in data.get("symbols", []):
        if "address" in sym:
            known.setdefault(sym["name"], sym["address"])
    header = (corpus / "include" / "common.h")
    prelude = (strip_preprocessor(header.read_text()) if header.exists() else FALLBACK_TYPES) + MACROS
    images = build_candidates(probe)
    table = dict(known)
    names = [n for n in sorted(matches) if (corpus / "src" / (n + ".c")).exists()]
    singles = [n for n in names if len(function_names((corpus / "src" / (n + ".c")).read_text())) == 1]
    rows, reasons = [], {"compile": 0, "link": 0, "outside": 0}
    for name in singles:
        entry = functions.get(name)
        place = layout.get(entry["vram"]) if entry else None
        if not place:
            reasons["outside"] += 1
            continue
        text = prelude + "\n" + expand_macros(strip_preprocessor((corpus / "src" / (name + ".c")).read_text()))
        syms = symbol_table(text, table)
        result, why = compile_and_compare(probe, text, entry["vram"], place["size"] // 4, syms, images)
        if result is None:
            reasons[why] += 1
            continue
        rows.append({"function": name, "vram": entry["vram"], "words": place["size"] // 4,
                     "same": result[0], "image": result[1]})
    exact = [r for r in rows if r["same"] == r["words"]]
    if as_json:
        print(json.dumps({"corpus": str(corpus), "matched": len(matches), "scored": len(rows),
                          "exact": len(exact), "reasons": reasons, "rows": rows}, indent=1))
        return 0
    print("corpus %s — %d matched, %d single-function, %d compiled and compared"
          % (corpus, len(matches), len(singles), len(rows)))
    print("%d word-exact under this profile; skipped: %d compile, %d link, %d outside this cartridge"
          % (len(exact), reasons["compile"], reasons["link"], reasons["outside"]))
    rows.sort(key=lambda r: (-(r["same"] == r["words"]), -r["same"] / max(r["words"], 1)))
    for r in rows[:30]:
        print("  %-34s %08x %3d/%-3d %-12s %s" % (r["function"], r["vram"], r["same"], r["words"], r["image"],
                                                  "EXACT" if r["same"] == r["words"] else ""))
    return 0


def align(corpus: Path, as_json: bool) -> int:
    """Score by **content** rather than by address: find each compiled body anywhere in the cartridge.

    Their overlay numbering is not ours — `func_80161C70_overlay_011` sits 0x80 below our shared slot base
    `0x80161cf0`, and twenty-five of our overlay members load at that one base. So an overlay function cannot be
    scored at the address its name declares, and the sweep's "outside our images" count is a statement about the
    address, not about the code. This mode asks the code instead: compile the draft, then look for the exact word
    sequence in every image. A **consistent delta** across many functions of one member is what turns a content
    match into an address.
    """
    spec = __import__("importlib.util").util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
    probe = __import__("importlib.util").util.module_from_spec(spec)
    spec.loader.exec_module(probe)
    data = json.loads((corpus / "decompdecomp.json").read_text())
    matches, functions, layout = data["verification"]["matches"], data["functions"], {x["vram"]: x for x in data["layout"]}
    known = {n: f["vram"] for n, f in functions.items()}
    header = corpus / "include" / "common.h"
    prelude = (strip_preprocessor(header.read_text()) if header.exists() else FALLBACK_TYPES) + MACROS
    images = build_candidates(probe)
    index = {}
    for name, base, blob in images:
        for off in range(0, len(blob) - 16, 4):
            index.setdefault(blob[off:off + 16], []).append((name, base, off))
    rows, misses = [], {"compile": 0, "absent": 0}
    names = [n for n in sorted(matches) if (corpus / "src" / (n + ".c")).exists()]
    for name in names:
        if len(function_names((corpus / "src" / (name + ".c")).read_text())) != 1:
            continue
        entry = functions.get(name)
        place = layout.get(entry["vram"]) if entry else None
        if not place:
            continue
        words = place["size"] // 4
        text = prelude + "\n" + expand_macros(strip_preprocessor((corpus / "src" / (name + ".c")).read_text()))
        scratch = Path(tempfile.mkdtemp(prefix="align_", dir=str(probe.WORK)))
        c, s, o, fx, elf = scratch / "c.c", scratch / "c.s", scratch / "c.o", scratch / "c.fix.o", scratch / "c.elf"
        c.write_text(text)
        cc1 = probe.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
        gas = probe.AS27 if probe.AS27.exists() else probe.GAS / "mips-linux-gnu-as"
        if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(c), "-o", str(s)],
                          capture_output=True).returncode:
            misses["compile"] += 1
            continue
        if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                          capture_output=True).returncode:
            misses["compile"] += 1
            continue
        probe.normalise_object(o)
        subprocess.run([str(probe.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                        "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
        (scratch / "l.ld").write_text(
            "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
            "*(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) *(.rodata) *(.gnu.attributes) }\n}\n"
            % entry["vram"] + "".join("%s = 0x%X;\n" % (k, v) for k, v in symbol_table(text, known).items()))
        if subprocess.run([str(probe.GAS / "mips-linux-gnu-ld"), "-T", str(scratch / "l.ld"), "-o", str(elf),
                           str(fx)], capture_output=True).returncode:
            misses["compile"] += 1
            continue
        got = probe.text_of(elf)
        want = got[:4 * words]
        blobs = {n: b for n, _base, b in images}
        found = []
        for image_name, base, off in index.get(want[:16], []):
            if blobs[image_name][off:off + 4 * words] == want:
                found.append((image_name, base + off, base + off - entry["vram"]))
        if not found:
            misses["absent"] += 1
            shutil.rmtree(scratch, ignore_errors=True)
            continue
        rows.append({"function": name, "their": entry["vram"], "words": words,
                     "found": [{"image": i, "address": a, "delta": d} for i, a, d in found]})
        shutil.rmtree(scratch, ignore_errors=True)
    if as_json:
        print(json.dumps({"rows": rows, "misses": misses}, indent=1))
        return 0
    from collections import Counter
    deltas = Counter()
    for r in rows:
        for f in r["found"]:
            deltas[(f["image"], f["delta"])] += 1
    print("%d bodies found in the cartridge by content; %d compile failures, %d absent"
          % (len(rows), misses["compile"], misses["absent"]))
    print("\nthe consistent offsets, per image (a mapping needs many functions agreeing):")
    for (image, delta), n in deltas.most_common(15):
        print("  %-14s delta %+7d  %3d function(s)" % (image, delta, n))
    return 0


def self_test() -> int:
    cases = []
    cases.append(("a comment is removed and does not survive to the compiler",
                  strip_preprocessor("int f;\n/* x */\nint g;") == "int f;\n\nint g;"))
    cases.append(("a `#` directive is removed, because this cc1 is the compiler and not the driver",
                  strip_preprocessor("#ifndef A\n#define A\nint f;\n#endif") == "int f;"))
    cases.append(("a continued macro leaves no orphan line",
                  strip_preprocessor("#define F(a) \\\n  ((a) + 1)\nint f;") == "int f;"))
    cases.append(("a name without an address yields nothing", vram_of("FUN_thing") is None))
    cases.append(("an eight-digit name yields its vram", vram_of("func_800042F4") == 0x800042F4))
    cases.append(("a suffixed name yields its prefix address, not its tail",
                  vram_of("func_80036764_ovl_01_510") == 0x80036764))
    cases.append(("a data name yields its address", vram_of("D_800128C8") == 0x800128C8))
    cases.append(("a plausible 8-digit name outside the segment is refused", vram_of("func_12345678") is None))
    table = symbol_table("extern int D_800128C8;\nvoid func_80036764_ovl_01_510(void);", {"D_800128C8": 0x800128D0})
    cases.append(("the corpus's own map overrides the address a name encodes",
                  table.get("D_800128C8") == 0x800128D0))
    cases.append(("a suffixed function name is resolved through its prefix", table.get("func_80036764_ovl_01_510") == 0x80036764))
    cases.append(("M2C_FIELD expands to the cast-and-deref the corpus means",
                  expand_macros("M2C_FIELD(a, s32 *, 4)") == "(*(s32 *)((s8 *)(a) + (4)))"))
    cases.append(("a type with commas inside is one argument, not three",
                  expand_macros("M2C_FIELD(a, s32 (**)(s32, s32), 0x34)")
                  == "(*(s32 (**)(s32, s32))((s8 *)(a) + (0x34)))"))
    cases.append(("a macro nested in its own argument expands too",
                  "M2C_FIELD" not in expand_macros("M2C_FIELD(M2C_FIELD(a, s32 *, 4), s32 *, 0)")))
    cases.append(("one definition is one function", len(function_names("int f(void) {\n}\n")) == 1))
    cases.append(("two definitions are two functions",
                  len(function_names("int f(void) {\n}\nint g(int a) {\n}\n")) == 2))
    cases.append(("a prototype is not a definition", function_names("int f(void);\n") == []))
    bad = 0
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d other-corpus case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--align", action="store_true",
                    help="score by content: find each compiled body anywhere in the cartridge and report the offset")
    ap.add_argument("--corpus", default=str(DEFAULT_CORPUS))
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if not (a.report or a.align):
        ap.error("nothing to do: --report, --align or --self-test")
    corpus = Path(a.corpus)
    if not (corpus / "decompdecomp.json").exists():
        print("no external corpus at %s — it is never committed (see the module docstring); nothing to score"
              % corpus, file=sys.stderr)
        return 2
    return align(corpus, a.json) if a.align else report(corpus, a.json)


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
