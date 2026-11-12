#!/usr/bin/env python3
"""Measure how far every function that has C is from byte-exact — the map the project never had.

Eleven milestones were optimised against **two** bodies, because the repo could only score a draft it already had:
`leaf_screen --try` scores one file, `compile_probe.py` is binary (exact or FAIL) over 211 cases, `build_corpus.py`
checks the 274 reconstructions we authored, and `partials.py` re-scores 2 published pairs. **3 194 functions hold the
provider's C and have never been compared to the cartridge at all.** This tool compares them, ranks them, and writes the
one fixture every later milestone should pick its target from.

What it does, per function: take `src/<image>/<name>.c`, strip the header comment (`cc1` 2.8 has no comment parser and
**segfaults** on one — measured), add the minimum preamble the Ghidra dialect needs (its type names, and an `extern`
declaration for every `DAT_…` it references), compile with the canonical profile, assemble, link at the cartridge
address with every `FUN_…`/`LAB_…`/`DAT_…` name defined at the address *its own name carries*, then count identical
words against the image.

Three rules this file keeps, each learned here the hard way:

  * **A failure is a status, never a zero.** A body that will not compile is not a body that scores 0 of N, and
    reporting it as one would make the distribution lie in the safe direction.
  * **Never fudge a type to raise coverage.** A `DAT_…` declared `unsigned char[]` to make a subscript compile would
    generate different code and therefore a *wrong distance* — worse than a gap. When the faithful declaration fails,
    the body is recorded as failing.
  * **The summary is derived, not declared.** `--check` recomputes it from the fixture and re-measures a deterministic
    sample, because a published distribution that can drift from its own data is the M373 defect.

The full run is a heavy suite (~3 200 compiles) and belongs to `verify.py --full`; `--check` is the cheap tier.

Usage:
  ./distance_map.py --write                 # every function that has C; writes fixtures/decomp/distance.json
  ./distance_map.py --check                 # summary from the fixture + a 24-function re-measurement
  ./distance_map.py --self-test             # controls, including one that must NOT be reported exact
  ./distance_map.py --image stage2 --jobs 8 --limit 50
"""
from __future__ import annotations

import argparse
import concurrent.futures
import importlib.util
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FIXTURE = ROOT / "fixtures" / "decomp" / "distance.json"
CFLAGS = ["-O2", "-G", "0", "-mips2", "-mcpu=r4300"]
ASFLAGS = ["-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0"]

# Statuses. `exact` and `scored` are measurements; the rest are refusals, and a refusal is never counted as a zero.
EXACT, SCORED, CC1_FAILED, AS_FAILED, LINK_FAILED, NO_SOURCE = "exact", "scored", "cc1-failed", "as-failed", \
    "link-failed", "no-source"
MEASURED = (EXACT, SCORED)

# Ghidra's type vocabulary, as it appears in this corpus (counted, not guessed). `undefined` is its catch-all; the
# width-suffixed names are the ones the decompiler uses when it cannot infer a type.
#
# `true`/`false` are an ENUM and not `#define`s: this `cc1` has **no preprocessor** (M356 measured it — `#define X 5`
# then `return X;` gives "`X' undeclared"), so a `#` line is a parse error, not a macro. The first version of this
# file used `#define` and lost 139 of 218 boot bodies to it.
# Ghidra's type vocabulary, as it appears in this corpus (counted, not guessed). `undefined` is its catch-all; the
# width-suffixed names are the ones the decompiler uses when it cannot infer a type.
#
# `true`/`false` are an ENUM and not `#define`s: this `cc1` has **no preprocessor** (M356 measured it — `#define X 5`
# then `return X;` gives "`X' undeclared"), so a `#` line is a parse error, not a macro. The first version of this
# file used `#define` and lost 139 of 218 boot bodies to it.
#
# Every one of these is emitted ONLY when the body does not already declare it: this project's own reconstructions
# open with `typedef unsigned char u8;`, and a second typedef of the same name is an error in C89 — emitting all of
# them unconditionally broke 15 byte-exact bodies before this check existed.
TYPES = [
    ("undefined", "typedef unsigned char undefined;"),
    ("undefined1", "typedef unsigned char undefined1;"),
    ("undefined2", "typedef unsigned short undefined2;"),
    ("undefined3", "typedef unsigned int undefined3;"),
    ("undefined4", "typedef unsigned int undefined4;"),
    ("undefined8", "typedef unsigned long long undefined8;"),
    ("byte", "typedef unsigned char byte;"),
    ("ubyte", "typedef unsigned char ubyte;"),
    ("sbyte", "typedef signed char sbyte;"),
    ("ushort", "typedef unsigned short ushort;"),
    ("uint", "typedef unsigned int uint;"),
    ("code", "typedef unsigned int code;"),
    ("longlong", "typedef long long longlong;"),
    ("ulonglong", "typedef unsigned long long ulonglong;"),
    ("size_t", "typedef unsigned int size_t;"),
    ("bool", "typedef unsigned char bool;"),
    ("u8", "typedef unsigned char u8;"),
    ("s8", "typedef signed char s8;"),
    ("u16", "typedef unsigned short u16;"),
    ("s16", "typedef signed short s16;"),
    ("u32", "typedef unsigned int u32;"),
    ("s32", "typedef signed int s32;"),
]
ALWAYS = ["typedef unsigned char bool_t;", "enum { false = 0, true = 1 };"]

# Ghidra passes COP0 register *names* as bare identifiers — both as helper arguments (`setCopReg(0, WatchLo, in_a0)`)
# and directly (`Status | 2`). They were macros in the original source. Emitted ALWAYS: a local variable of the same
# name would simply shadow the enum constant, so there is nothing to collide with, and the conditional version missed
# every body that reads a COP0 register without going through a helper (40 of 218 boot refusals).
COP0 = """enum { Index = 0, Random = 1, EntryLo0 = 2, EntryLo1 = 3, Context = 4, PageMask = 5, Wired = 6,
       BadVAddr = 8, Count = 9, EntryHi = 10, Compare = 11, Status = 12, Cause = 13, EPC = 14, PRId = 15,
       Config = 16, LLAddr = 17, WatchLo = 18, WatchHi = 19 };"""
COP_CALL = re.compile(r"\b(?:set|get)Cop\w*\s*\(")

MODIFIERS = re.compile(r"\bprocessEntry\b")

# A Ghidra symbol name carries its own address: `FUN_800243d0` is at 0x800243d0 and `DAT_801137d8` at 0x801137d8.
# That is what makes a bulk link possible without a symbol table: the name IS the address.
# The optional leading underscore is Ghidra's: `_DAT_80132110` is a data name whose symbol had one. Without it the
# name is not recognised, no `extern` is emitted, and the body fails with a mangled "undeclared" — 86 of 218 boot
# bodies, the single largest refusal cause before this was found.
SYMBOL = re.compile(r"(_?[A-Za-z][A-Za-z0-9_]*?)_([0-9a-fA-F]{8})\b")
# `export_src.py` renames references to `func_0x<addr>` in some images; same rule, different spelling.
SYMBOL_0X = re.compile(r"\b((?:func|FUN|DAT|LAB)_0x([0-9a-fA-F]{1,8}))\b")
# Names Ghidra gives to code positions rather than to data.
CODE_PREFIXES = ("FUN", "LAB", "SUB", "THUNK", "SWITCHD", "CASED", "DEFAULT", "CASE", "JOIN")


_PROBE = None


def srcmap_module():
    """`srcmap` resolves a source path from an ADDRESS — a tool may never name a source file by name (M394)."""
    spec = importlib.util.spec_from_file_location("sm", str(ROOT / "tools" / "srcmap.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def probe():
    """The probe module, loaded once per process — a worker compiles thousands of bodies."""
    global _PROBE
    if _PROBE is None:
        spec = importlib.util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        _PROBE = module
    return _PROBE


def strip_comments(text: str) -> str:
    """Remove C comments, respecting string and character literals.

    `cc1` 2.8 has no comment parser: a leading `/* … */` makes it die with `parse error before` a garbage byte, and on
    some files it segfaults outright. Every file in `src/` opens with one, so this is not optional.
    """
    out, i, n = [], 0, len(text)
    while i < n:
        ch = text[i]
        if ch in "\"'":
            quote, j = ch, i + 1
            while j < n:
                if text[j] == "\\":
                    j += 2
                    continue
                if text[j] == quote:
                    j += 1
                    break
                j += 1
            out.append(text[i:j])
            i = j
            continue
        if text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        out.append(ch)
        i += 1
    return "".join(out)


def symbols_of(body: str):
    """([(name, address)] code labels, [(name, address)] data names) referenced by this body."""
    code, data = {}, {}
    for match in SYMBOL.finditer(body):
        name, addr = match.group(0), int(match.group(2), 16)
        (code if match.group(1).upper().lstrip("_") in CODE_PREFIXES else data)[name] = addr
    for match in SYMBOL_0X.finditer(body):
        name, addr = match.group(1), int(match.group(2), 16)
        (code if name.upper().startswith(("FUNC", "FUN", "LAB")) else data)[name] = addr
    return sorted(code.items()), sorted(data.items())


_IMAGE_SYMBOLS = None


def image_symbols() -> dict:
    """name -> address for every function in the census, so a call to `cart_record` or `main` resolves.

    The provider names most functions `FUN_<addr>`, whose address is in the name — but the project's own named
    functions (`cart_record`, `inflate_init`, `thread_dispatcher`, `main`) are not, and a body that calls one of them
    fails to link. This is the table that makes those calls resolve to the address the census gives them.
    """
    global _IMAGE_SYMBOLS
    if _IMAGE_SYMBOLS is None:
        index = json.loads((ROOT / "manifests" / "code_index.json").read_text())
        _IMAGE_SYMBOLS = {}
        for image in index["images"]:
            for fn in image.get("functions_list") or []:
                if fn.get("name") and fn.get("address"):
                    _IMAGE_SYMBOLS.setdefault(fn["name"], int(fn["address"], 16))
    return _IMAGE_SYMBOLS


def declaration(name: str, body: str, form: str) -> str:
    """The `extern` for one data symbol, in the given form.

    `form` is the ladder rung, not a guess about the symbol: `scalar` is the faithful default (Ghidra writes `DAT_x`
    for a 4-byte global and `DAT_x[i]` only when it modelled a blob), `array` is the retry for a body that subscripts
    it, `pointer` for one that both subscripts and assigns.
    """
    esc = re.escape(name)
    assigned = re.search(r"(?<![=!<>+\-*/&|^])\b%s\b\s*(?:=(?!=)|\+=|-=|\*=|/=|\+\+|--)" % esc, body)
    arrow = re.search(r"\b%s\s*->" % esc, body)
    if arrow or (form == "pointer" and assigned):
        return "extern unsigned int *%s;" % name
    if form == "array":
        return "extern unsigned int %s[];" % name
    return "extern unsigned int %s;" % name


def typedecls(body: str) -> str:
    """The type preamble this body needs: only the names it does not declare itself."""
    out = []
    for name, decl in TYPES:
        if not re.search(r"\btypedef\b[^;]*\b%s\b\s*;" % re.escape(name), body):
            out.append(decl)
    return "\n".join(out) + "\n" + "\n".join(ALWAYS) + "\n" + COP0 + "\n"


def already_declared(body: str, name: str) -> bool:
    """True when the body declares this symbol itself, so the preamble must not declare it again.

    Some provider bodies carry their own `extern undefined4 D_80012150;`; a second declaration with a different type
    is `conflicting types for ...`, which refused 33 boot bodies (the largest single remaining cause).
    """
    return bool(re.search(r"^\s*(?:extern\s+)?(?:unsigned\s+|signed\s+|const\s+)*[A-Za-z_][A-Za-z0-9_]*\s*\**\s*"
                          r"%s\b" % re.escape(name), body, re.M))


def build_source(body: str, data, form: str) -> str:
    clean = MODIFIERS.sub("", body)
    decls = "".join(declaration(n, clean, form) + "\n" for n, _a in data if not already_declared(clean, n))
    return typedecls(clean) + decls + clean


def compile_one(args) -> dict:
    """Compile, assemble, link and compare one function. Runs in a worker process, so it takes one tuple."""
    image, addr, words, name, source, code, data = args
    probe_module = probe()
    cc1 = probe_module.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = probe_module.AS27 if probe_module.AS27.exists() else probe_module.GAS / "mips-linux-gnu-as"
    objcopy = probe_module.GAS / "mips-linux-gnu-objcopy"
    ld = probe_module.GAS / "mips-linux-gnu-ld"
    inventory = probe_module.image_inventory()
    window = probe_module.image_window(image, inventory)
    if window is None:
        return {"s": NO_SOURCE, "w": words}
    blob, base = window
    want = blob[addr - base:addr - base + 4 * words]
    if len(want) < 4 * words:
        return {"s": NO_SOURCE, "w": words}
    path = ROOT / source
    if not path.exists():
        return {"s": NO_SOURCE, "w": words}
    body = strip_comments(path.read_text())
    # A `src/` file can be a DISASSEMBLY LISTING, whose words all live inside a comment: strip it and the translation
    # unit is empty, which compiles cleanly and would be reported as "0 of N" — a refusal masquerading as the worst
    # possible score. Emptiness is refused, never measured.
    if "{" not in body or not body.strip():
        return {"s": NO_SOURCE, "w": words}
    scratch = Path(tempfile.mkdtemp(prefix="dm_", dir=str(probe_module.WORK)))
    stem = scratch / "f"
    s, o, fx, elf = (stem.with_suffix(x) for x in (".s", ".o", ".fix.o", ".elf"))
    # The ladder: the faithful declaration first; the retry only for a body the faithful one cannot express.
    attempts = [("scalar", body)] if form_is_scalar(body, data) else [("scalar", body), ("array", body),
                                                                         ("pointer", body)]
    last = CC1_FAILED
    for form, text in attempts:
        (scratch / "f.c").write_text(build_source(text, data, form))
        if subprocess.run([str(cc1), "-quiet"] + CFLAGS + [str(scratch / "f.c"), "-o", str(s)],
                          capture_output=True).returncode:
            last = CC1_FAILED
            continue
        if subprocess.run([str(gas)] + ASFLAGS + ["-o", str(o), str(s)], capture_output=True).returncode:
            last = AS_FAILED
            continue
        probe_module.normalise_object(o)
        subprocess.run([str(objcopy), "--set-section-alignment", ".text=4", "--set-section-alignment",
                        ".rodata=8", str(o), str(fx)], capture_output=True)
        def link(extra):
            (scratch / "l.ld").write_text(
                "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = %#x;\n  .rodata : { *(.rodata) }\n"
                "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) "
                "*(.data) *(.bss) *(.sbss) }\n}\n" % (addr, 0x90000000)
                + "__bss_start = 0x%X; __bss_end = 0x%X;\n" % (0x80100000, 0x80100000)
                + "".join("%s = 0x%X;\n" % (n, a) for n, a in list(code) + list(data) + extra))
            return subprocess.run([str(ld), "-T", str(scratch / "l.ld"), "-o", str(elf), str(fx)],
                                  capture_output=True, text=True, errors="replace")

        # Every function the census names, so calls to `cart_record`/`main` resolve; then, if the link still fails,
        # the leftover externals (COP helpers, `halt_baddata`, `trap`) are placed at a far address and the body is
        # still measured — their call words will differ from the image, which is the honest outcome and better than
        # refusing the whole body over a helper this project does not model.
        known = list(image_symbols().items())
        result = link(known)
        if result.returncode:
            missing = sorted(set(re.findall(r"undefined reference to `([^']+)'", result.stderr or "")))
            # The address has to share the body's top nibble: `jal` carries a 26-bit target, so a helper placed
            # outside 0x8xxxxxxx is a "relocation truncated to fit: R_MIPS_26" and the whole body is refused for the
            # sake of a stub it cannot see. 0x8F000000 is far above every image and inside the region.
            far = [(name, 0x8F000000 + 4 * i) for i, name in enumerate(missing)]
            result = link(known + far)
        if result.returncode:
            last = LINK_FAILED
            continue
        code_bytes = probe_module.text_of(elf)
        identical, first = 0, None
        for i in range(words):
            if code_bytes[4 * i:4 * i + 4] == want[4 * i:4 * i + 4]:
                identical += 1
            elif first is None:
                first = i
        return {"s": EXACT if identical == words else SCORED, "w": words, "i": identical, "d": first,
                "t": form}
    return {"s": last, "w": words}


def form_is_scalar(body: str, data) -> bool:
    """True when no data symbol is subscripted, so the faithful declaration is the only one needed.

    Checked per symbol, not by looking for a `[` anywhere: a body full of `param_1[3]` needs no retry, and entering
    the ladder for it would triple the compiles of the whole corpus for nothing.
    """
    return not any(re.search(r"\b%s\s*\[" % re.escape(name), body) for name, _a in data)


def functions_to_measure(images=None):
    """[(image, addr, words, name, source, code, data)] for every function whose source file exists."""
    index = json.loads((ROOT / "manifests" / "code_index.json").read_text())
    out = []
    for image in index["images"]:
        if images and image["name"] not in images:
            continue
        for fn in image.get("functions_list") or []:
            source = fn.get("file")
            if not source or not (ROOT / source).exists():
                continue
            text = (ROOT / source).read_text(errors="replace")
            # a listing is not C: the extent is measured and the body is deliberately absent
            if "DISASSEMBLY LISTING" in text:
                continue
            body = strip_comments(text)
            code, data = symbols_of(body)
            out.append((image["name"], int(fn["address"], 16), int(fn["size"]) // 4, fn.get("name", ""),
                        source, code, data))
    return out


def histogram(records) -> dict:
    """The distribution, over the census: where the remaining non-exact bodies actually are."""
    buckets = {"exact": 0, "within_1": 0, "within_2": 0, "within_4": 0, "within_8": 0, "under_half": 0,
               "over_half": 0, "none": 0}
    for rec in records.values():
        if rec["s"] == EXACT:
            buckets["exact"] += 1
            continue
        if rec["s"] != SCORED:
            continue
        gap = rec["w"] - rec["i"]
        if gap <= 1:
            buckets["within_1"] += 1
        elif gap <= 2:
            buckets["within_2"] += 1
        elif gap <= 4:
            buckets["within_4"] += 1
        elif gap <= 8:
            buckets["within_8"] += 1
        elif rec["i"] * 2 >= rec["w"]:
            buckets["over_half"] += 1
        else:
            buckets["under_half"] += 1
    return buckets


def overlap(records) -> dict:
    """How the map's exact set relates to what the project already CLAIMS byte-exact.

    This is the number the milestone exists for: a body can be byte-exact without anyone having noticed, because the
    project only ever compiled the C it had rewritten. `claimed_not_exact` is expected to be non-zero and is not a
    contradiction — 23 reconstructions live in `tools/compile_probe.py` as constants (`P6_SOURCE`, …), so the file in
    `src/` for those addresses still holds the provider's version, which is what this tool measures.
    """
    claimed = {(f["image"], int(f["address"], 16))
               for f in json.loads((ROOT / "fixtures" / "decomp" / "recovered.json").read_text())["functions"]}
    exact = set()
    for key, rec in records.items():
        if rec["s"] != EXACT:
            continue
        image, addr = key.split(":")
        exact.add((image, int(addr, 16)))
    return {"claimed": len(claimed), "exact": len(exact),
            "exact_and_claimed": len(exact & claimed), "exact_unclaimed": len(exact - claimed),
            "claimed_not_exact": len(claimed - exact)}


def summarise(records) -> dict:
    totals = {"functions": len(records)}
    for status in (EXACT, SCORED, CC1_FAILED, AS_FAILED, LINK_FAILED, NO_SOURCE):
        totals[status.replace("-", "_")] = sum(1 for r in records.values() if r["s"] == status)
    totals["measured"] = totals["exact"] + totals["scored"]
    words = sum(r["w"] for r in records.values())
    identical = sum(r.get("i", 0) for r in records.values())
    totals["words"] = words
    totals["words_identical"] = identical
    totals["percent_words"] = round(100.0 * identical / max(words, 1), 2)
    return {"totals": totals, "histogram": histogram(records)}


def measure(targets, jobs: int):
    records = {}
    if jobs <= 1:
        for target in targets:
            records["%s:%08x" % (target[0], target[1])] = compile_one(target)
        return records
    with concurrent.futures.ProcessPoolExecutor(max_workers=jobs) as pool:
        for target, rec in zip(targets, pool.map(compile_one, targets, chunksize=8)):
            records["%s:%08x" % (target[0], target[1])] = rec
    return records


def write(args) -> int:
    targets = functions_to_measure(args.image)
    if args.limit:
        targets = targets[:args.limit]
    print("measuring %d function(s) with %d job(s)" % (len(targets), args.jobs), file=sys.stderr)
    records = measure(targets, args.jobs)
    document = {"note": "How far every function that has C is from byte-exact, measured by tools/distance_map.py. "
                        "'exact' and 'scored' are measurements; every other status is a REFUSAL and is never counted "
                        "as a zero. 't' is the declaration rung the body needed (scalar/array/pointer) -- a body that "
                        "needed 'array' is measured with the declaration Ghidra meant, not with a fudged type.",
                "profile": "cc1 2.8.1 -O2 -G 0 -mips2 -mcpu=r4300; as -EB -mips2 -mcpu=r4300 -g -G 0",
                "records": records, **summarise(records), "overlap": overlap(records)}
    FIXTURE.write_text(json.dumps(document, indent=1, sort_keys=True) + "\n")
    totals = document["totals"]
    print("%d function(s): %d exact, %d scored, %d refused (cc1 %d, as %d, link %d), %d bytes-free"
          % (totals["functions"], totals["exact"], totals["scored"],
             totals["cc1_failed"] + totals["as_failed"] + totals["link_failed"],
             totals["cc1_failed"], totals["as_failed"], totals["link_failed"], totals["no_source"]))
    print("words: %d of %d identical (%.2f %%)" % (totals["words_identical"], totals["words"],
                                                   totals["percent_words"]))
    print("histogram: " + ", ".join("%s=%d" % (k, v) for k, v in document["histogram"].items()))
    ov = document["overlap"]
    print("overlap with the project's claims: %d exact (%d already claimed, %d UNCLAIMED), %d claimed but not exact "
          "here" % (ov["exact"], ov["exact_and_claimed"], ov["exact_unclaimed"], ov["claimed_not_exact"]))
    return 0


def check(args) -> int:
    """Re-derive the summary from the fixture and re-measure a deterministic sample. Never recompiles the corpus."""
    if not FIXTURE.exists():
        print("FAIL no fixture at %s — run --write" % FIXTURE, file=sys.stderr)
        return 1
    document = json.loads(FIXTURE.read_text())
    records = document["records"]
    derived = summarise(records)
    cases, bad = [], 0
    derived["overlap"] = overlap(records)
    for key in ("totals", "histogram", "overlap"):
        same = derived[key] == document[key]
        cases.append(("%s is derived from the records" % key, same,
                      "" if same else "%s != %s" % (derived[key], document[key])))
        bad += 0 if same else 1
    # the sample: spread across the ordered population so it cannot pass by picking only easy bodies
    targets = functions_to_measure(None)
    by_key = {"%s:%08x" % (t[0], t[1]): t for t in targets}
    keys = sorted(k for k in records if k in by_key)
    step = max(len(keys) // 24, 1)
    sample = keys[::step][:24]
    drifted = []
    for key in sample:
        again = compile_one(by_key[key])
        if again.get("i") != records[key].get("i") or again["s"] != records[key]["s"]:
            drifted.append("%s: %s of %s" % (key, records[key].get("i"), records[key]["w"]))
    cases.append(("a %d-function sample re-measures the same" % len(sample), not drifted,
                  ", ".join(drifted[:3])))
    bad += 0 if not drifted else 1
    for name, ok, detail in cases:
        print("  %s %s%s" % ("PASS" if ok else "FAIL", name, (" — " + detail) if detail else ""))
    print("%d/%d distance-map case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def self_test() -> int:
    """Three controls, and the third is the one that matters: a comparator that cannot fail is not a comparator."""
    cases = []
    # 1. a reconstruction this project already proved byte-exact must come out exact.
    #    Both paths come from srcmap, by ADDRESS: a tool may not name a source file (M394's rule, gated).
    sm = srcmap_module()
    strlen_rel = str(sm.path("boot", 0x8000DE78))          # srcmap returns it relative to the repo root
    text = strip_comments((ROOT / strlen_rel).read_text())
    code, data = symbols_of(text)
    rec = compile_one(("boot", 0x8000DE78, 9, "strlen", strlen_rel, code, data))
    cases.append(("a byte-exact reconstruction reports exact (strlen, 9 words)",
                  rec["s"] == EXACT and rec.get("i") == 9, str(rec)))
    # 2. a body that is the image's own listing cannot be compiled, and must be refused rather than scored 0
    listing = str(sm.path("stage2", 0x800B43A0))
    refused = compile_one(("stage2", 0x800B43A0, 38, "listing", listing, [], []))
    cases.append(("a disassembly listing has no C to measure — refused, never '0 of 38'",
                  refused["s"] not in MEASURED, str(refused)))
    # 3. the comparator must fail when the same body is measured against a DIFFERENT function's window: this is the
    #    control that a comparator which always says "exact" cannot pass
    wrong = compile_one(("boot", 0x8000DE9C, 10, "memcpy", strlen_rel, code, data))
    cases.append(("the same body against another body's window is NOT exact",
                  wrong["s"] != EXACT, str(wrong)))
    ok = sum(1 for _n, good, _d in cases if good)
    for name, good, detail in cases:
        print("  %s %s%s" % ("PASS" if good else "FAIL", name, "" if good else " — " + detail))
    print("%d/%d distance-map self-test case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true", help="measure every function that has C; write the fixture")
    ap.add_argument("--check", action="store_true", help="re-derive the summary + re-measure a 24-function sample")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--image", action="append", help="restrict to this image (repeatable)")
    ap.add_argument("--jobs", type=int, default=1, help="worker processes for --write")
    ap.add_argument("--limit", type=int, default=0, help="first N functions only (debugging)")
    args = ap.parse_args(argv)
    if args.self_test:
        return self_test()
    if args.check:
        return check(args)
    if args.write:
        return write(args)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
