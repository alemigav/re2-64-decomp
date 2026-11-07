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


def table_map() -> dict:
    """image -> [(dispatcher, table, declared_cases)] from `manifests/jump_tables.json` (M374).

    The manifest was built by `find_jump_tables.py`, which finds the `lui`/`addiu` pair that feeds a `jr v0` and
    records the table it addresses. Keyed by *dispatcher* -- an address inside the function, not its head -- which is
    exactly what containment needs.
    """
    out = {}
    for img in json.loads((ROOT / "manifests" / "jump_tables.json").read_text())["images"]:
        out[img["name"]] = [(int(t["dispatcher"], 16), int(t["table"], 16), t.get("declared_cases"))
                            for t in img.get("tables", [])]
    return out


def pool_address(tables, image, addr: int, words: int):
    """Where this function's constant pool belongs in the image, or (None, why).

    A function whose C emits a jump table refers to it through `lui`/`addiu`, so the object carries a `.rodata` that
    the build has to *place*. Parking it at `0x90000000` (the M356 lesson, kept as the fallback) makes the function
    differ for a reason that has nothing to do with its code; the image's own address is what makes the linked words
    match, and that address is not new knowledge -- the manifest already holds it, and containment finds it without a
    new fixture key:

        the unique table whose dispatcher lies inside [addr, addr + 4·words)

    Zero matches means the pool is not a jump table (or the manifest missed it); more than one means the function
    dispatches twice and the build cannot know which table its `.rodata` corresponds to. Both are reported, never
    guessed -- a wrong pool would look like a code difference, which is the confusion this tool exists to end.
    """
    hits = {(d, t) for d, t, _n in tables.get(image, []) if addr <= d < addr + 4 * words}
    if len(hits) == 1:
        pool = sorted(hits)[0][1]
        # the link script places `.text` first and `.rodata` afterwards, and ld cannot move the location counter
        # backwards -- so a table that lives *before* the body has to keep the far fallback rather than fail the link
        if pool < addr + 4 * words:
            return None, "table 0x%08x precedes the body's end" % pool
        return pool, "one dispatcher in extent"
    if len(hits) > 1:
        return None, "%d dispatchers in extent: %s" % (len(hits), ", ".join("0x%08x" % t for _d, t in sorted(hits)))
    return None, "no dispatcher in extent"


def recovered_by_image(cp) -> dict:
    """image -> [(address, words, text, syms, label, verdict)] from the fixture, which stays the single reader.

    The symbols of a constant-based reconstruction live in the probe's `SINGLES` table, not in the fixture (the
    file-based ones carry theirs), so both channels are read here — the same two the probe itself uses. The verdict
    travels with the row because `--check` now distinguishes "a body that differs because it is a published partial"
    from "a body that differs because the build is wrong", and only the fixture can tell them apart.
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
            (int(entry["address"], 16), int(entry["words"]), text, syms, entry.get("probe", "")[:60],
             entry.get("verdict", "")))
    for rows in out.values():
        rows.sort()
    return out


def build_image(cp, name, rows, check: bool, tables=None) -> dict:
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
    records, matched, mismatched, unexpected = [], 0, 0, []
    tables = tables or {}
    for index, (addr, words, text, syms, label, verdict) in enumerate(rows):
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
        # discarded section is a link error (M356's lesson, applied here). M374: placed at the *image's* address for
        # that pool when the manifest names it, because 0x90000000 makes twelve byte-exact bodies look like
        # differences; the far address stays the fallback for a pool the manifest cannot locate.
        pool, why = pool_address(tables, name, addr, words)
        (stem.with_suffix(".ld")).write_text(
            "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = %#x;\n"
            "  .rodata : { *(.rodata) *(.rodata.*) }\n  .data : { *(.data) *(.bss) *(.sbss) }\n"
            "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) }\n}\n"
            % (addr, pool if pool else 0x90000000)
            + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms))
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
        has_pool = bool(cp.text_of(o, ".rodata")) if hasattr(cp, "text_of") else False
        if ok:
            off = addr - base
            image[off:off + 4 * words] = want
            for k in range(off, off + 4 * words):
                claimed[k] = 1
        if check:
            matched += 1 if ok else 0
            mismatched += 0 if ok else 1
            # a difference is only the build's fault if the fixture claims the body byte-exact; a published partial
            # is expected to differ, and M374 is where that distinction becomes the exit status of `make check`
            if not ok and verdict == "byte-exact":
                unexpected.append("0x%08x" % addr)
        if ok:
            status = "exact"
        elif has_pool and not pool:
            status = "differs (constant pool not placed)"
        else:
            status = "differs"
        records.append({**record, "status": status,
                        "pool": ("0x%08x" % pool) if (has_pool and pool) else None,
                        "pool_evidence": why if has_pool else None,
                        "sha256": hashlib.sha256(code).hexdigest()[:16]})
    covered = sum(4 * w for _a, w, _t, _s, _l, _v in rows)
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
            "exact": matched, "mismatched": mismatched, "unexpected": unexpected,
            "pool_placed": sum(1 for r in records if r.get("pool")),
            "functions_list": records}


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
    tables = table_map()
    if a.self_test:
        name = "ovl_00b2d7a"
        record = build_image(cp, name, by_image.get(name, []), True, tables)
        ok = record.get("compiled", 0) == record.get("functions", -1) > 0 and record.get("mismatched", 1) == 0
        print("  %s %s: %d of %d functions linked and byte-exact"
              % ("PASS" if ok else "FAIL", name, record.get("exact", 0), record.get("functions", 0)))
        # M374: the second case cross-validates the two independent sources for a pool address. The probe places
        # each of its twelve switch tables *by hand* (`P7_TABLE` 0x800B8F78, `P8_TABLE` 0x800B69B0, ...); the build
        # derives the same address by containment in `manifests/jump_tables.json`. If either drifts -- a regenerated
        # manifest, a renamed constant -- the two stop agreeing, and this case is what notices. Manifest-only, so it
        # would hold even if every compile were skipped.
        consts = {v for k, v in vars(cp).items() if k.endswith("_TABLE") and isinstance(v, int)}
        found = set()
        for img, rows in by_image.items():
            for row in rows:
                pool, _why = pool_address(tables, img, row[0], row[1])
                if pool:
                    found.add(pool)
        missing = sorted(consts - found)
        ok2 = not missing and len(consts) >= 12
        print("  %s every table the probe places by hand is also found by containment: %d constant(s), "
              "%d found%s" % ("PASS" if ok2 else "FAIL", len(consts), len(consts & found),
                              "" if ok2 else " -- missing %s" % [hex(m) for m in missing]))
        print("%d/2 build-corpus case(s)" % (sum(1 for x in (ok, ok2) if x)))
        return 0 if (ok and ok2) else 1
    names = a.image or sorted(by_image)
    if OUT.exists() and not a.image:
        shutil.rmtree(OUT)
    OUT.mkdir(parents=True, exist_ok=True)
    index, ok = [], True
    for name in names:
        rows = by_image.get(name, [])
        record = build_image(cp, name, rows, a.check, tables) if rows else {"image": name, "functions": 0}
        index.append(record)
        # M374: `--check` is now a verdict, not a report. A body that differs from the cartridge is the build's
        # fault *unless* the fixture already publishes it as a partial (`0x8007e590`, 226 of 229) -- so the exit
        # status turns on that distinction instead of on "there are still residues", which is what made
        # `make check` red by construction for every milestone since the build existed.
        if a.check and record.get("unexpected"):
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
            if r.get("unexpected"):
                verdict += " (UNEXPECTED: %s)" % ", ".join(r["unexpected"])
        print("%-14s %6d %6d %9d %6.1f%% %s" % (r["image"], r["functions"], r["compiled"], r["covered_bytes"],
                                                 100.0 * r["share"], verdict))
    total = sum(r.get("covered_bytes", 0) for r in index)
    print("\n%d functions over %d images, %d bytes of the corpus built into ELFs under build/corpus/"
          % (sum(r.get("functions", 0) for r in index), len(index), total))
    if a.check:
        ex = sum(r.get("exact", 0) for r in index)
        mm = sum(r.get("mismatched", 0) for r in index)
        pl = sum(r.get("pool_placed", 0) for r in index)
        print("%d exact, %d differ (%d with the image's own pool address placed); unexpected differences: %s"
              % (ex, mm, pl, sum(len(r.get("unexpected", [])) for r in index)))
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
