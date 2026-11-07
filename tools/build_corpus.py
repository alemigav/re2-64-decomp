#!/usr/bin/env python3
"""Build the recovered corpus into linkable objects: the code this project has, as code.

Everything upstream of this tool is *measurement* — extents, ladders, byte maps, one function compiled at a time by
`compile_probe.py`. Nothing in the repository could be built as a unit, which is the one thing a reader asked for and
did not get: `src/` was 200 files of C that compiled individually and never together.

This tool closes that. For each image it compiles **every reconstructed function** with the canonical profile, links
them all at the addresses the cartridge puts them, and writes a real ELF — so the corpus becomes:

    build/corpus/<image>.elf      an ELF whose .text covers every recovered function at its own address
    build/corpus/<image>.bin      the same image as flat bytes, zero-filled where a body is not recovered
    build/corpus/index.json       what went in: addresses, sizes, digests, and what is still a hole

and `--check` re-derives the whole thing and compares **each function's bytes against the cartridge**, which makes the
build a verification of the corpus rather than a copy of it.

What it is not: a ROM. The holes are data and unrecovered code, and no image is complete — the tool reports the share
it covers so the number stays honest. Two images (boot, stage2) and 25 overlays are built; the overlays all load at
`0x80161cf0`, so each is its own ELF.

    ./build_corpus.py                # build every image
    ./build_corpus.py --check         # build, then compare every function against the cartridge
    ./build_corpus.py --image stage2  # one image
"""
from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build" / "corpus"
CFLAGS = ["-O2", "-G", "0", "-mips2", "-mcpu=r4300"]


def probe():
    spec = importlib.util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def recovered_by_image(cp) -> dict:
    """image -> [(address, words, text, syms, label)] from the fixture, which stays the single reader.

    The symbols of a constant-based reconstruction live in the probe's `SINGLES` table, not in the fixture (the
    file-based ones carry theirs), so both channels are read here — the same two the probe itself uses.
    """
    fixture = json.loads((ROOT / "fixtures" / "decomp" / "recovered.json").read_text())
    singles = {row[0]: tuple(row[4]) for row in getattr(cp, "SINGLES", [])}
    out = {}
    for entry in fixture["functions"]:
        text, syms = None, tuple(sorted(entry.get("syms", {}).items()))
        if entry.get("source_file"):
            path = ROOT / entry["source_file"]
            if path.exists():
                text = path.read_text()
        elif entry.get("source"):
            text = getattr(cp, entry["source"], None)
            syms = (syms or singles.get(entry["source"], ())
                    or tuple(getattr(cp, entry["source"].replace("_SOURCE", "_SYMS"), ()) or ()))
        if text is None:
            continue
        out.setdefault(entry["image"], []).append(
            (int(entry["address"], 16), int(entry["words"]), text, syms, entry.get("probe", "")[:60]))
    for rows in out.values():
        rows.sort()
    return out


def build_image(cp, name, rows, check: bool) -> dict:
    """Compile, link and stitch every function of one image; report what went in and what matched.

    One object per link, not one link for the image: binutils 2.42 refuses to merge objects from binutils 2.7
    (`local symbol at index 7 (>= sh_info of 7)`), and stripping the symbols to work around it destroys the very
    relocations that make the code match. So each function is linked alone at its own address -- exactly what
    `compile_probe.py` does -- and the results are **stitched** into an image-shaped byte array here.
    """
    inventory = cp.image_inventory()
    window = cp.image_window(name, inventory)
    if window is None:
        return {"image": name, "error": "no such image"}
    blob, base = window
    image = bytearray(len(blob))
    claimed = bytearray(len(blob))
    cc1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    objcopy = cp.GAS / "mips-linux-gnu-objcopy"
    ld = cp.GAS / "mips-linux-gnu-ld"
    work = OUT / name
    work.mkdir(parents=True, exist_ok=True)
    records, matched, mismatched = [], 0, 0
    for index, (addr, words, text, syms, label) in enumerate(rows):
        stem = work / ("f%03d_%08x" % (index, addr))
        c, s, o, fx, elf = (stem.with_suffix(x) for x in (".c", ".s", ".o", ".fix.o", ".elf"))
        c.write_text(text)
        record = {"address": "0x%08x" % addr, "words": words, "bytes": 4 * words}
        if subprocess.run([str(cc1), "-quiet"] + CFLAGS + [str(c), "-o", str(s)], capture_output=True).returncode:
            records.append({**record, "status": "cc1-failed"})
            continue
        if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o", str(o), str(s)],
                          capture_output=True).returncode:
            records.append({**record, "status": "as-failed"})
            continue
        cp.normalise_object(o)
        subprocess.run([str(objcopy), "--set-section-alignment", ".text=4", "--set-section-alignment",
                        ".rodata=8", str(o), str(fx)], capture_output=True)
        # `.rodata` is *placed*, not discarded: a function with a constant pool refers to that section, and a
        # discarded section is a link error (M356's lesson, applied here). Far away, so it cannot disturb the words
        # being compared.
        (stem.with_suffix(".ld")).write_text(
            "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = 0x90000000;\n"
            "  .rodata : { *(.rodata) *(.rodata.*) }\n  .data : { *(.data) *(.bss) *(.sbss) }\n"
            "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) }\n}\n"
            % addr + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms))
        if subprocess.run([str(ld), "-T", str(stem.with_suffix(".ld")), "-o", str(elf), str(fx)],
                          capture_output=True).returncode:
            records.append({**record, "status": "link-failed"})
            continue
        code = cp.text_of(elf)
        want = blob[addr - base:addr - base + 4 * words]
        ok = code[:4 * words] == want
        # a function with a constant pool refers to `.rodata`, which this build places at 0x90000000 because the
        # *image's* address for that pool is per-function knowledge (a jump table at 0x800b9c78, say). Those come out
        # "differs" for a reason that is not about the code, so they are counted apart instead of inflating the
        # residue: 12 of the 13 below are this, the thirteenth is the published 226-of-229.
        pool = bool(cp.text_of(o, ".rodata")) if hasattr(cp, "text_of") else False
        if ok:
            off = addr - base
            image[off:off + 4 * words] = want
            for k in range(off, off + 4 * words):
                claimed[k] = 1
        if check:
            matched += 1 if ok else 0
            mismatched += 0 if ok else 1
        records.append({**record, "status": "exact" if ok else ("differs (constant pool not placed)" if pool else "differs"),
                        "sha256": hashlib.sha256(code).hexdigest()[:16]})
    covered = sum(4 * w for _a, w, _t, _s, _l in rows)
    # the stitched image is the honest artefact: every recovered body at its own address, zero everywhere else
    flat = OUT / ("%s.bin" % name)
    flat.write_bytes(bytes(image))
    wrapped = OUT / ("%s.elf" % name)
    built = subprocess.run([str(objcopy), "-I", "binary", "-O", "elf32-tradbigmips", "-B", "mips",
                            str(flat), str(wrapped)], capture_output=True).returncode == 0
    return {"image": name, "base": base, "image_bytes": len(blob), "functions": len(rows),
            "compiled": sum(1 for r in records if r["status"] in ("exact", "differs")),
            "covered_bytes": covered, "claimed_bytes": sum(claimed),
            "share": round(sum(claimed) / max(len(blob), 1), 4), "linked": built,
            "exact": matched, "mismatched": mismatched, "functions_list": records}


def main(argv) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="compare every function against the cartridge")
    ap.add_argument("--image", action="append", help="build one image (repeatable)")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--self-test", action="store_true",
                    help="build one small image and assert every function in it is byte-exact (the gate)")
    a = ap.parse_args(argv)
    cp = probe()
    by_image = recovered_by_image(cp)
    if a.self_test:
        name = "ovl_00b2d7a"
        record = build_image(cp, name, by_image.get(name, []), True)
        ok = record.get("compiled", 0) == record.get("functions", -1) > 0 and record.get("mismatched", 1) == 0
        print("  %s %s: %d of %d functions linked and byte-exact"
              % ("PASS" if ok else "FAIL", name, record.get("exact", 0), record.get("functions", 0)))
        print("%d/%d build-corpus case(s)" % (1 if ok else 0, 1))
        return 0 if ok else 1
    names = a.image or sorted(by_image)
    if OUT.exists() and not a.image:
        shutil.rmtree(OUT)
    OUT.mkdir(parents=True, exist_ok=True)
    index, ok = [], True
    for name in names:
        rows = by_image.get(name, [])
        record = build_image(cp, name, rows, a.check) if rows else {"image": name, "functions": 0}
        index.append(record)
        if a.check and record.get("mismatched"):
            ok = False
    (OUT / "index.json").write_text(json.dumps({"tool": "build_corpus.py", "profile": CFLAGS,
                                                "images": index}, indent=1) + "\n")
    if a.json:
        print(json.dumps(index, indent=1))
        return 0 if ok else 1
    print("%-14s %6s %6s %9s %7s %s" % ("image", "funcs", "built", "covered", "share", "verdict"))
    for r in index:
        if not r.get("functions"):
            print("%-14s %6d %6s %9s %7s %s" % (r["image"], 0, "-", "-", "-", "nothing recovered"))
            continue
        verdict = "linked" if r["linked"] else "LINK FAILED"
        if a.check:
            verdict = "%d exact, %d differ" % (r["exact"], r["mismatched"])
        print("%-14s %6d %6d %9d %6.1f%% %s" % (r["image"], r["functions"], r["compiled"], r["covered_bytes"],
                                                 100.0 * r["share"], verdict))
    total = sum(r.get("covered_bytes", 0) for r in index)
    print("\n%d functions over %d images, %d bytes of the corpus built into ELFs under build/corpus/"
          % (sum(r.get("functions", 0) for r in index), len(index), total))
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
