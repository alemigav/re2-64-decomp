#!/usr/bin/env python3
"""Is the original build one compiler or several? Score the recovered corpus under each profile we can actually run.

The *other* project (`delibrete/Resident-Evil-II-Decompilation-N64`) carries a **per-range toolchain map**: 70
ranges over 8 compilers — `gcc-2.7.2-kmc` for 26 of them, `sn-n64-281` 13, `sn-n64-272-*` 12, `gcc-2.8.1-pm*` 18,
`ido-5.3` 1 — with a default of `gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2`. If that is how the cartridge was
built, then this project's single pinned profile (`cc1 2.8.1 -O2 -G 0 -mips2 -mcpu=r4300`) is simply the wrong
question to ask of any function outside it, and the residues we closed as *allocation walls* may be toolchain
artefacts instead.

This tool tests what is testable here and says plainly what is not:

  * **What is testable**: the two compiler generations we have built (`mips-gcc-2.7.2`, `mips-gcc-2.8.1`), crossed
    with the flag sets — theirs and ours. Four profiles, each a real compiler × real flags, not an approximation.
  * **What is not**: their vendor builds (`sn-n64-281`, `sn-n64-272-*`, `gcc-2.8.1-pm-*`, `gcc-2.7.2-kmc`) are
    binaries we do not have, and `gcc-2.7.2-kmc` is not `gcc 2.7.2` — KMC shipped a patched tree. A profile that
    *fails* here therefore refutes nothing about their binaries; only a profile that *succeeds* is evidence.

The control is the whole point: a profile may only be believed about a residue if it still reproduces the corpus we
already match. A profile that closes `0x8007e590` and breaks forty functions has not explained anything.

    ./toolchain_matrix.py                  # corpus under every profile, plus the two focus functions
    ./toolchain_matrix.py --json
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# The assembler is held constant across profiles: the architecture is r4300 whatever the compiler thinks, and
# `-G0` without `-mips2` makes `as.new` reject `beql` -- an artefact of the harness, not a difference in the code
# (found by the first run, which reported "no score" for a function whose draft assembles fine).
ASSEMBLER = ["-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0"]

PROFILES = [
    # name, cc1 directory, cc1 flags, assembler flags
    ("ours: 2.8.1 -O2 -G0 -mips2 -mcpu=r4300", "mips-gcc-2.8.1",
     ["-O2", "-G", "0", "-mips2", "-mcpu=r4300"], ASSEMBLER),
    ("theirs' flags on 2.8.1: -mips3 -mgp32 -mfp32", "mips-gcc-2.8.1",
     ["-O2", "-G0", "-mips3", "-mgp32", "-mfp32"], ASSEMBLER),
    ("their default compiler: 2.7.2 -mips3 -mgp32 -mfp32", "mips-gcc-2.7.2",
     ["-O2", "-G0", "-mips3", "-mgp32", "-mfp32"], ASSEMBLER),
    ("2.7.2 with our flags: -mips2", "mips-gcc-2.7.2",
     ["-O2", "-G", "0", "-mips2"], ASSEMBLER),
]

# The two published residues, each with the draft and the link layout its own case uses (the dispatcher reads a
# six-word jump table out of `.rodata` at 0x800b9c78, so the section has to be *placed*, not discarded).
FOCUS = [{"label": "0x8007e590", "const": "P7E590_SOURCE", "syms": "P7E590_SYMS", "addr": 0x8007E590, "words": 229,
          "rodata": 0x800B9C78},
         {"label": "0x80006d60", "const": None, "file": "fixtures/permuter/d60/base.c", "addr": 0x80006D60, "words": 52,
          "syms": [("__osActiveQueue", 0x8001294C), ("__osDisableInt", 0x800072E0),
                   ("__osRestoreInt", 0x80007300), ("__osCleanupThread", 0x8000116C)], "rodata": None}]

FLOATY = re.compile(r"(?<![\w.])\d+\.\d*(?:[eE][-+]?\d+)?[fF]?")


def load_probe():
    spec = importlib.util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def build(probe, sources, profile):
    """[(source-name, address, words, identical, compiled)] for one profile over [(name, text, addr, words, syms)]."""
    name, compiler, cc1_flags, as_flags = profile
    cc1 = probe.TC / compiler / "bin" / "cc1"
    gas = probe.AS27 if probe.AS27.exists() else probe.GAS / "mips-linux-gnu-as"
    if not cc1.exists() or not gas.exists():
        return None
    out = []
    scratch = probe.WORK / ("matrix_%s" % re.sub(r"\W+", "_", compiler))
    scratch.mkdir(parents=True, exist_ok=True)
    for src_name, text, addr, words, syms, rodata in sources:
        c, s, o, fx, elf = scratch / "c.c", scratch / "c.s", scratch / "c.o", scratch / "c.fix.o", scratch / "c.elf"
        c.write_text(text)
        if subprocess.run([str(cc1), "-quiet"] + cc1_flags + [str(c), "-o", str(s)],
                          capture_output=True).returncode:
            out.append((src_name, addr, words, None, 0))
            continue
        if subprocess.run([str(gas)] + as_flags + ["-o", str(o), str(s)], capture_output=True).returncode:
            out.append((src_name, addr, words, None, 0))
            continue
        probe.normalise_object(o)
        subprocess.run([str(probe.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                        "--set-section-alignment", ".rodata=8", str(o), str(fx)], capture_output=True)
        rodata_rule = ("  . = %#x;\n  .rodata : ALIGN(8) { *(.rodata) }\n" % rodata) if rodata \
            else "  /DISCARD/ : { *(.rodata) }\n"
        (scratch / "l.ld").write_text(
            "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n" % addr + rodata_rule
            + "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) "
              "*(.mdebug*) *(.gnu.attributes) }\n}\n"
            + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms))
        if subprocess.run([str(probe.GAS / "mips-linux-gnu-ld"), "-T", str(scratch / "l.ld"), "-o", str(elf),
                           str(fx)], capture_output=True).returncode:
            out.append((src_name, addr, words, None, 0))
            continue
        got = probe.text_of(elf)
        inventory = probe.image_inventory()
        best = -1
        for image in inventory:
            window = probe.image_window(image, inventory)
            if not window:
                continue
            blob, base = window
            want = blob[addr - base:addr - base + 4 * words]
            if len(want) < 4 * words:
                continue
            same = sum(1 for i in range(0, 4 * words, 4) if want[i:i + 4] == got[i:i + 4])
            best = max(best, same)
        out.append((src_name, addr, words, best, len(got) // 4))
    return out


def main(argv) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--check", action="store_true",
                    help="assert the two halves of the M357 claim: the pinned profile reproduces the corpus, and at "
                         "least one alternative profile reproduces strictly less of it")
    a = ap.parse_args(argv)
    probe = load_probe()
    entries = json.loads((ROOT / "fixtures" / "decomp" / "recovered.json").read_text())["functions"]
    groups = {}
    for e in entries:
        # a file-based import (M359) has no constant name; its own file is the group
        groups.setdefault(e.get("source") or e.get("source_file"), []).append(e)
    singles = {row[0]: tuple(row[4]) for row in getattr(probe, "SINGLES", [])}
    corpus = []
    for src_name, members in sorted(groups.items()):
        text = getattr(probe, src_name, None)
        if text is None and (ROOT / str(src_name)).exists():
            text = (ROOT / str(src_name)).read_text()
        if text is None:
            continue
        first = members[0]
        syms = tuple(probe.__dict__.get(src_name.replace("_SOURCE", "_SYMS"), []) or ()) or \
            singles.get(src_name, ()) or tuple(sorted(first.get("syms", {}).items()))
        corpus.append((src_name, text, int(first["address"], 16), int(first["words"]), syms, None))
    floaty = sum(1 for c in corpus if FLOATY.search(c[1]))
    focus = []
    for spec in FOCUS:
        text = getattr(probe, spec["const"], None) if spec["const"] else None
        if text is None and spec.get("file"):
            path = ROOT / spec["file"]
            text = path.read_text() if path.exists() else None
        syms = spec["syms"]
        if isinstance(syms, str):
            syms = getattr(probe, syms, [])
        if text:
            focus.append(("focus " + spec["label"], text, spec["addr"], spec["words"], tuple(syms),
                          spec["rodata"]))
    rows = {}
    for profile in PROFILES:
        result = build(probe, corpus, profile)
        if result is None:
            rows[profile[0]] = {"missing": True}
            continue
        scored = [r for r in result if r[3] is not None]
        first_member = {r[0] for r in scored if r[3] == r[2]}
        rows[profile[0]] = {"sources": len(result), "compiled": len(scored),
                            "exact": len(first_member), "words_exact": sum(r[3] == r[2] for r in scored),
                            "rows": [{"source": r[0], "address": "0x%08x" % r[1], "words": r[2], "same": r[3]}
                                     for r in scored],
                            "focus": {}}
        for item in build(probe, focus, profile) or []:
            rows[profile[0]]["focus"][item[0]] = {"same": item[3], "words": item[2], "compiled": item[4]}
    if a.json:
        print(json.dumps({"profiles": rows, "corpus_sources": len(corpus), "float_bearing": floaty}, indent=1))
        return 0
    if a.check:
        ours = rows[PROFILES[0][0]]
        others = [r for name, r in rows.items() if name != PROFILES[0][0] and not r.get("missing")]
        cases = [("the pinned profile compiles every corpus source it is given",
                  ours["compiled"] > 0 and ours["exact"] == ours["compiled"]),
                 ("and it is exact word for word on all of them, not merely close",
                  ours["words_exact"] == ours["compiled"]),
                 ("at least one alternative profile reproduces strictly less, so the profile is what makes them match",
                  bool(others) and all(o["exact"] < ours["exact"] for o in others)),
                 ("neither residue is closed by an alternative profile",
                  all(o["focus"]["focus 0x80006d60"]["same"] < 52 for o in others))]
        bad = 0
        for label, ok in cases:
            print("  %s %s" % ("PASS" if ok else "FAIL", label))
            bad += 0 if ok else 1
        print("%d/%d toolchain-matrix case(s)" % (len(cases) - bad, len(cases)))
        return 1 if bad else 0
    print("corpus: %d source groups over %d recovered functions (%d carry a float constant)"
          % (len(corpus), len(entries), floaty))
    print("the control is the second column: a profile that cannot reproduce what we already match explains nothing\n")
    print("%-52s %8s %8s %s" % ("profile", "sources", "exact", "focus"))
    for name, row in rows.items():
        if row.get("missing"):
            print("%-52s %8s %8s %s" % (name, "-", "-", "compiler/assembler not provisioned"))
            continue
        f = ", ".join("%s %s/%s" % (k.replace("focus ", ""), v["same"], v["words"]) for k, v in row["focus"].items())
        print("%-52s %8d %8d %s" % (name, row["compiled"], row["exact"], f or "-"))
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
