#!/usr/bin/env python3
"""The drafting workbench: everything one body needs, in one command, with the residue CLASSIFIED.

The drafting rate was ~5 bodies per milestone, and the cost was never the edit — it was the setup: dump the words, find
the provider draft, compile it, diff it, work out *what kind of* residue it is, then decide which mechanism the class
demands. This collapses that to one command and one classification, because a long program is a rate problem.

    ./draft_workbench.py --queue 12                 # the cheapest bodies left, band-first, with their class
    ./draft_workbench.py --at stage2:0x800b43a0     # one body: image words, provider draft, diff, class, next moves
    ./draft_workbench.py --at ... --words            # only the image's words
    ./draft_workbench.py --passes stage2:0x800b43a0  # run the mechanical passes for this one body

The classification is the whole instrument. Each rule below is a measured finding from M392–M416, not a guess:

  width       `lbu` vs `lb`, `lw` vs `lbu`, `lh` vs `lw`  -> the access TYPE (M411: 24 bodies by one table)
  extend      `andi 0xff` vs `sll 24`                     -> signedness of the value, i.e. a declaration type (M413)
  materialise `addiu`/`ori` vs `lui`, `sw` vs `lui`       -> the arithmetic domain: keep the constant in a register (M396c)
  order       same opcode, different operands/registers   -> statement order or operand placement (M401: 3 -> 43)
  layout      only a branch displacement differs          -> the body's size, so the residue is upstream
  alloc       one register differs and nothing else       -> register allocation; the class no pass reaches (M408, M416)
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DISTANCE = ROOT / "fixtures" / "decomp" / "distance.json"
RECOVERED = ROOT / "fixtures" / "decomp" / "recovered.json"
AUTHORED = ROOT / "fixtures" / "decomp" / "authored"

LOAD_OPS = {"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr", "sb", "sh", "sw", "swl", "swr"}
MATERIALISE = {"lui", "ori", "addiu", "addi", "addu"}



# Every scratch directory this tool creates is registered and wiped at exit. Not tidiness: each `pins()` call used to
# leak one, and after M409-M417 there were **68 262 of them, 12 GB**, which made the gate audit's sandbox copy crawl
# until the whole fast tier hung with no output. A leak that only shows up as a hang 60 000 runs later is a leak worth
# one helper.
_SCRATCH: list = []


def _mkdtemp(prefix: str, root=None, dir=None) -> Path:
    import tempfile
    where = dir if dir is not None else root
    d = Path(tempfile.mkdtemp(prefix=prefix, dir=str(where)))
    _SCRATCH.append(d)
    return d


def _sweep() -> None:
    import shutil
    for p in _SCRATCH:
        shutil.rmtree(p, ignore_errors=True)


import atexit as _atexit

_atexit.register(_sweep)

def bank_module():
    spec = importlib.util.spec_from_file_location("be", str(ROOT / "tools" / "bank_exact.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def load_modules():
    be = bank_module()
    dm = be.distance_map()
    ls_spec = importlib.util.spec_from_file_location("lsm", str(ROOT / "tools" / "leaf_screen.py"))
    ls = importlib.util.module_from_spec(ls_spec)
    ls_spec.loader.exec_module(ls)
    return be, dm, dm.probe(), ls


def image_words(cp, ls, image, addr, words):
    blob, base = cp.image_window(image, cp.image_inventory())
    out = []
    for i in range(words):
        w = int.from_bytes(blob[addr - base + 4 * i:addr - base + 4 * i + 4], "big")
        out.append((addr + 4 * i, w, ls.gloss(w, addr + 4 * i)))
    return out


def pairs_for(cp, image: str, addr: int, words: int, text: str, syms: dict):
    """[(want, got)] word by word, or (None, why) — the same compile-assemble-link the gate does, kept local so the
    workbench can show WHICH words differ rather than only how many."""
    import subprocess
    import tempfile
    blob, base = cp.image_window(image, cp.image_inventory())
    want = [blob[addr - base + 4 * i:addr - base + 4 * i + 4] for i in range(words)]
    d = Path(_mkdtemp(prefix="wb_", dir=str(cp.WORK)))
    f = d / "f"
    (d / "f.c").write_text(text)
    cc1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(d / "f.c"),
                       "-o", str(f.with_suffix(".s"))], capture_output=True).returncode:
        return None, "cc1 refused"
    if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o",
                       str(f.with_suffix(".o")), str(f.with_suffix(".s"))], capture_output=True).returncode:
        return None, "as refused"
    cp.normalise_object(f.with_suffix(".o"))
    subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(f.with_suffix(".o")),
                    str(f.with_suffix(".fix.o"))], capture_output=True)
    (d / "l.ld").write_text(
        "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
        "*(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) *(.rodata) *(.gnu.attributes) }\n}\n" % addr
        + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms.items()))
    if subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(d / "l.ld"), "-o",
                       str(f.with_suffix(".elf")), str(f.with_suffix(".fix.o"))],
                      capture_output=True).returncode:
        return None, "ld refused"
    got = cp.text_of(f.with_suffix(".elf"))
    out = []
    for i in range(words):
        g = got[4 * i:4 * i + 4]
        out.append((int.from_bytes(want[i], "big"), int.from_bytes(g, "big") if len(g) == 4 else None))
    return out, "linked"


def classify(pairs, ls, addr):
    """Name the residue's class from the words that differ, using the rules measured in M392–M416."""
    diffs = [(i, w, o) for i, (w, o) in enumerate(pairs) if w != o]
    if not diffs:
        return "exact", diffs
    tags = []
    for _i, want, got in diffs:
        hw, gw = ls.gloss(want, addr).split()[0], ls.gloss(got, addr).split()[0]
        if hw != gw and {hw, gw} <= LOAD_OPS:
            tags.append("width")
        elif hw != gw and (hw in MATERIALISE or gw in MATERIALISE):
            tags.append("materialise")
        elif "andi" in (hw, gw) and ({"sll", "sra", "srl"} & {hw, gw}):
            # the M413 rule: `andi $v0,$v0,0xff` in the image against `sll $v0,$v0,24` in ours is a signedness
            # difference surfacing as two different extension idioms — not a shape difference
            tags.append("extend")
        elif hw == gw and hw in ("andi", "sll", "sra", "srl"):
            tags.append("extend")
        elif hw == gw and hw.startswith(("b", "j")):
            tags.append("layout")
        elif hw == gw:
            tags.append("order" if len(diffs) > 1 else "alloc")
        else:
            tags.append("shape")
    for tag in ("width", "extend", "materialise", "order", "layout", "alloc", "shape"):
        if tags.count(tag) * 2 >= len(tags) and tag in tags:
            return tag, diffs
    return tags[0], diffs


NEXT_MOVE = {
    "width": "tools/type_repair.py's table: re-type the access (`*(char *)` -> `*(unsigned char *)`, word/short/byte)",
    "extend": "declaration signedness (`char cVar1;` -> `unsigned char cVar1;`) — M413",
    "materialise": "the arithmetic domain: `u32 base + off` so the constant stays in a register — M396c",
    "order": "statement order / operand placement, mirroring the image's build order — M401",
    "layout": "the residue is upstream: a size difference shifts the branch, so fix the body's shape first",
    "alloc": "register allocation — the class no pass reaches (M408/M416); park unless the body is worth a mechanism",
    "shape": "structural rewrite — read the image and rebuild the statement group",
}


def report(at: str, args):
    be, dm, cp, ls = load_modules()
    image, addr_s = at.split(":")
    addr = int(addr_s, 16)
    doc = json.loads(DISTANCE.read_text())
    key = "%s:%08x" % (image, addr)
    rec = doc["records"].get(key, {})
    words = rec.get("w")
    if not words:
        print("%s is not in the distance map" % key)
        return 1
    print("=== %s  %d words  map: %d identical (%s) ===" % (key, words, rec.get("i", 0), rec.get("s")))
    rows = image_words(cp, ls, image, addr, words)
    if args.words:
        for a, w, g in rows:
            print("  %08x  %08x  %s" % (a, w, g))
        return 0
    text, syms, why = be.body_for(dm, None, rec.get("t", "scalar"), image, addr, words)
    if text is None:
        print("no draft: %s" % why)
        return 1
    print("\n--- current draft (%d lines) ---" % len(text.splitlines()))
    print("\n".join(text.splitlines()[-24:]))
    pairs, status = pairs_for(cp, image, addr, words, text, syms)
    if pairs is None:
        print("\n--- the draft does not compile/link (%s): fix that before classifying the residue ---" % status)
        return 0
    score = sum(1 for w, g in pairs if w == g)
    print("\n--- %d of %d words identical ---" % (score, words))
    kind, diffs = classify(pairs, ls, addr)
    for i, want, got in diffs[:12]:
        print("  %2d  had %-24s ours %s" % (i, ls.gloss(want, addr + 4 * i),
                                            ls.gloss(got, addr + 4 * i) if got is not None else "-"))
    print("\nCLASS: %s (%d word(s) differ)" % (kind, len(diffs)))
    print("NEXT:  %s" % NEXT_MOVE.get(kind, "read the image and rebuild the statement group"))
    return 0


def queue(n: int, max_words: int):
    be, dm, cp, ls = load_modules()
    doc = json.loads(DISTANCE.read_text())
    claimed = {(f["image"], int(f["address"], 16)) for f in json.loads(RECOVERED.read_text())["functions"]}
    rows = []
    for key, rec in doc["records"].items():
        if rec["s"] != "scored" or rec["w"] > max_words:
            continue
        image, addr = key.split(":")
        addr = int(addr, 16)
        if (image, addr) in claimed:
            continue
        gap = rec["w"] - rec["i"]
        rows.append((gap, rec["w"], key))
    rows.sort()
    print("%-26s %4s %5s  %s" % ("body", "gap", "words", "workbench command"))
    for gap, w, key in rows[:n]:
        print("%-26s %4d %5d  python3 tools/draft_workbench.py --at %s" % (key, gap, w, key))
    print("\n%d body(ies) at or below %d words are drafting targets; %d of them are at gap <= 4"
          % (len(rows), max_words, sum(1 for g, _w, _k in rows if g <= 4)))
    return 0


def self_test() -> int:
    """The classifier's rules, alone.

    Only `leaf_screen.gloss` is loaded — NOT `load_modules()`, which pulls in the probe module. Under the acceptance
    pool that import deadlocked and the whole fast tier hung with no output at all; a pure test must not drag in the
    process machinery it is being measured beside.
    """
    ls_spec = importlib.util.spec_from_file_location("lsm_pure", str(ROOT / "tools" / "leaf_screen.py"))
    ls = importlib.util.module_from_spec(ls_spec)
    ls_spec.loader.exec_module(ls)
    addr = 0x80082388
    cases = []
    width = [(0x90620006, 0x90630006)]                       # lbu vs lbu — same opcode, different reg
    cases.append(("a register-only difference classifies as alloc/order",
                  classify(width, ls, addr)[0] in ("alloc", "order"), classify(width, ls, addr)[0]))
    extend = [(0x304200ff, 0x00021600)]                       # andi 0xff vs sll 24
    cases.append(("an andi-vs-shift difference classifies as extend",
                  classify(extend, ls, addr)[0] == "extend", classify(extend, ls, addr)[0]))
    load = [(0x90820006, 0x8c820006)]                         # lbu vs lw
    cases.append(("a byte-vs-word load classifies as width", classify(load, ls, addr)[0] == "width",
                  classify(load, ls, addr)[0]))
    cases.append(("identical words classify as exact", classify([(0x24020001, 0x24020001)], ls, addr)[0] == "exact", ""))
    cases.append(("every class has a next move", all(k in NEXT_MOVE for k in
                  ("width", "extend", "materialise", "order", "layout", "alloc", "shape")), ""))
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, detail in cases:
        print("  %s %s%s" % ("PASS" if ok else "FAIL", name, "" if ok else " — " + str(detail)[:60]))
    print("%d/%d workbench self-test case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--at", help="IMAGE:ADDRESS, e.g. stage2:0x800b43a0")
    ap.add_argument("--queue", type=int, default=0, metavar="N", help="the cheapest N bodies left")
    ap.add_argument("--max-words", type=int, default=120)
    ap.add_argument("--words", action="store_true", help="print only the image's words")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args(argv)
    if args.self_test:
        return self_test()
    if args.queue:
        return queue(args.queue, args.max_words)
    if args.at:
        return report(args.at, args)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
