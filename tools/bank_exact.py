#!/usr/bin/env python3
"""Bank the bodies that already compile byte-exact: give each a reconstruction file, a pin and a provenance.

`distance_map.py` found **188 bodies that compile to the cartridge's own bytes and that nobody had claimed**. This tool
turns them into claims — but the claim it makes is deliberately narrow, because the provenance is not ours:

  * **`provenance: "provider"`** — the C is the decompiler's, adapted only in its scaffolding (type names, `extern`
    declarations). The project did not write it, and every count that mixes it with our own work has to say so.
  * **`provenance: "project"`** (the existing 274, and the default for an entry without the field) — the C is ours.

So the ledger gains a number rather than an ambiguity: `recovered` stays "C we wrote", `banked` is "C verified from the
provider", and only their sum is "bodies whose C reproduces the cartridge". A project whose whole value is that every
claim is checkable cannot quietly relabel somebody else's output as its own work, and 188 functions is exactly the size
of temptation where that would be tempting.

What it writes, per body:

  * `fixtures/decomp/authored/<image>/<address>.c` — self-contained and **comment-free** (this `cc1` has no comment
    parser; it segfaults), with the type preamble and `extern`s that `distance_map.py` measured with. The rung recorded
    in the fixture (`t`: scalar/array/pointer) is reused, so the banked file is byte-for-byte the source that was
    measured — never a re-derived one that might differ.
  * one `fixtures/decomp/recovered.json` entry with `provenance: "provider"`, `source_file`, `syms` and the measured
    verdict. `compile_probe.py` imports every `source_file` entry as a case, so the pin is automatic and can fail.

Then `export_src.py --write` projects it into `src/` with the standard header, exactly as it does for our own
reconstructions — one channel, one reader.

Usage:
  ./bank_exact.py --write [--limit N]   # bank N (or all) of the unclaimed byte-exact bodies
  ./bank_exact.py --check               # every banked entry still has its file, its pin and its provenance
  ./bank_exact.py --self-test
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DISTANCE = ROOT / "fixtures" / "decomp" / "distance.json"
RECOVERED = ROOT / "fixtures" / "decomp" / "recovered.json"
AUTHORED = ROOT / "fixtures" / "decomp" / "authored"
PROVENANCE = "provider"
PROBE_NOTE = "imported: the whole body matches by offset and content (M410, banked from the distance map)"



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

def distance_map():
    spec = importlib.util.spec_from_file_location("dm", str(ROOT / "tools" / "distance_map.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def provider_source(image: str, addr: int):
    """The PROVIDER's text for one body: `build/decomp/<image>/functions/0x<addr>.c`, or None.

    Not `src/`. `src/` is a projection of `recovered.json`, so once a body is banked its `src/` file holds *our*
    reconstruction — with the preamble this tool added. Re-banking read that projection and prepended a second
    preamble, which is how two bodies ended up "redeclared as different kind of symbol". The provider artifact is the
    only input that does not change when the fixture does.
    """
    path = ROOT / "build" / "decomp" / image / "functions" / ("0x%08x.c" % addr)
    return path if path.exists() else None


def body_for(dm, source: str, rung: str, image: str = None, addr: int = None, words: int = None):
    """(authored text, syms, problem) for one body: the provider's text, made self-contained."""
    path = provider_source(image, addr) if image and addr is not None else None
    if path is None:
        path = ROOT / source
    if not path or not path.exists():
        return None, {}, "no source file"
    raw = dm.strip_comments(path.read_text())
    if "{" not in raw.strip():
        return None, {}, "empty body"
    clean = dm.MODIFIERS.sub("", raw)
    code, data = dm.symbols_of(clean)
    # The widths the IMAGE uses, so a banked file and the map that found it cannot disagree about a symbol's type.
    widths = dm.data_widths(dm.probe(), image, addr, words) if (image and addr and words) else {}
    text = dm.typedecls(clean) + "".join(
        dm.declaration(n, clean, rung, widths.get(n)) + "\n"
        for n, _a in data if not dm.already_declared(clean, n)) + clean
    # BOTH channels: a body that calls `FUN_…` needs that name at its address to link, exactly as a body that reads
    # `DAT_…` does. Recording only the data half made four of the first six banked pins "not run" — the probe could
    # compile them and could not link them.
    syms = dict(code)
    syms.update(data)
    return text.rstrip("\n") + "\n", syms, None


def pins(dm, text: str, image: str, addr: int, words: int, syms: dict):
    """(identical, status) — compile, assemble, link and compare EXACTLY as the gate will.

    The pin is decided here, before the entry is written, because a claim the probe cannot check is not a claim.
    Mirrors `compile_probe.single_probe` step for step (same flags, same `as`, `.rodata` discarded): 184 of the 188
    pin, and the four that do not are refused with their cause rather than banked and discovered later. Their defect
    is a binutils 2.7 object that binutils 2.42 will not link (`local symbol at index N (>= sh_info)`) — the same
    generation gap `build_corpus.py` documents — and it is a harness limit, not a property of the code.
    """
    cp = dm.probe()
    win = cp.image_window(image, cp.image_inventory())
    if win is None:
        return 0, "no image"
    blob, base = win
    want = blob[addr - base:addr - base + 4 * words]
    if len(want) < 4 * words:
        return 0, "past the window"
    import tempfile as _tf
    d = Path(_tf.mkdtemp(prefix="pin_", dir=str(cp.WORK)))
    f = d / "f"
    (d / "f.c").write_text(text)
    cc1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    if subprocess.run([str(cc1), "-quiet", "-O2", "-G", "0", "-mips2", "-mcpu=r4300", str(d / "f.c"),
                       "-o", str(f.with_suffix(".s"))], capture_output=True).returncode:
        return 0, "cc1 refused"
    if subprocess.run([str(gas), "-EB", "-mips2", "-mcpu=r4300", "-g", "-G", "0", "-o",
                       str(f.with_suffix(".o")), str(f.with_suffix(".s"))], capture_output=True).returncode:
        return 0, "as refused"
    cp.normalise_object(f.with_suffix(".o"))
    # The probe runs objcopy between assemble and link, and it is not cosmetic: the rewrite normalises the
    # binutils-2.7 symtab that binutils 2.42 refuses (`local symbol at index N (>= sh_info)`). Linking the raw
    # object instead refused all 188 bodies with that message — a harness difference of one step, not a property
    # of any body.
    subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(f.with_suffix(".o")), str(f.with_suffix(".fix.o"))],
                   capture_output=True)
    (d / "l.ld").write_text(
        "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) "
        "*(.comment) *(.pdr) *(.data) *(.bss) *(.sbss) *(.mdebug*) *(.rodata) *(.gnu.attributes) }\n}\n" % addr
        + "".join("%s = 0x%X;\n" % (k, v) for k, v in syms.items()))
    link = subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(d / "l.ld"), "-o",
                           str(f.with_suffix(".elf")), str(f.with_suffix(".fix.o"))],
                          capture_output=True, text=True, errors="replace")
    if link.returncode:
        why = "ld refused"
        if "local symbol at index" in (link.stderr or ""):
            why = "ld refused: binutils 2.7 object vs binutils 2.42 (local symbol index)"
        return 0, why
    got = cp.text_of(f.with_suffix(".elf"))
    return sum(1 for i in range(words) if got[4 * i:4 * i + 4] == want[4 * i:4 * i + 4]), "linked"


def candidates() -> list[dict]:
    """The unclaimed byte-exact bodies, largest first — the biggest claims first, so a failure shows up early."""
    doc = json.loads(DISTANCE.read_text())
    claimed = {(f["image"], int(f["address"], 16))
               for f in json.loads(RECOVERED.read_text())["functions"]}
    out = []
    for key, rec in doc["records"].items():
        if rec["s"] != "exact":
            continue
        image, addr = key.split(":")
        addr = int(addr, 16)
        if (image, addr) in claimed:
            continue
        out.append({"image": image, "address": addr, "words": rec["w"], "rung": rec.get("t", "scalar")})
    out.sort(key=lambda c: (-c["words"], c["image"], c["address"]))
    return out


def write(args) -> int:
    dm = distance_map()
    index = json.loads((ROOT / "manifests" / "code_index.json").read_text())
    files = {}
    for image in index["images"]:
        for fn in image.get("functions_list") or []:
            files[(image["name"], int(fn["address"], 16))] = fn.get("file")
    todo = candidates()
    if args.limit:
        todo = todo[:args.limit]
    fixture = json.loads(RECOVERED.read_text())
    existing = {(e["image"], int(e["address"], 16)) for e in fixture["functions"]}
    banked, skipped = 0, []
    for cand in todo:
        key = (cand["image"], cand["address"])
        source = files.get(key)
        if not source:
            skipped.append("%s:0x%08x no source in the index" % key)
            continue
        text, syms, problem = body_for(dm, source, cand["rung"], cand["image"], cand["address"])
        if text is None:
            skipped.append("%s:0x%08x %s" % (key[0], key[1], problem))
            continue
        matched, why = pins(dm, text, cand["image"], cand["address"], cand["words"], syms)
        if matched != cand["words"]:
            skipped.append("%s:0x%08x pins %d of %d — %s" % (key[0], key[1], matched, cand["words"], why))
            continue
        out = AUTHORED / cand["image"] / ("%08x.c" % cand["address"])
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text)
        if key not in existing:
            fixture["functions"].append({
                "image": cand["image"], "address": "0x%08x" % cand["address"], "words": cand["words"],
                "verdict": "byte-exact", "provenance": PROVENANCE, "probe": PROBE_NOTE,
                "source_file": str(out.relative_to(ROOT)), "syms": syms})
            existing.add(key)
        banked += 1
    fixture["functions"].sort(key=lambda e: (e["image"], int(e["address"], 16)))
    RECOVERED.write_text(json.dumps(fixture, indent=1) + "\n")
    print("banked %d body(ies); %d REFUSED (pin failed)" % (banked, len(skipped)))
    for line in skipped:
        print("  refused", line)
    print("recovered.json now holds %d entries (%d provider, %d project)"
          % (len(fixture["functions"]),
             sum(1 for e in fixture["functions"] if e.get("provenance") == PROVENANCE),
             sum(1 for e in fixture["functions"] if e.get("provenance") != PROVENANCE)))
    return 0


def check(args) -> int:
    """Every banked entry must still have its file, its provenance and its pin. A banked claim that lost its file is
    exactly the M391 defect (a score with no draft), so it fails here before the probe has to."""
    fixture = json.loads(RECOVERED.read_text())
    banked = [e for e in fixture["functions"] if e.get("provenance") == PROVENANCE]
    missing = [e["address"] for e in banked if not (ROOT / (e.get("source_file") or "")).exists()]
    unproven = [e["address"] for e in banked if not e.get("source_file")]
    comments = []
    for entry in banked:
        text = (ROOT / entry["source_file"]).read_text()
        if "/*" in text or "//" in text:
            comments.append(entry["address"])
    cases = [
        ("every banked entry has a source file", not missing and not unproven,
         "missing: %s" % ", ".join(missing[:3] + unproven[:3])),
        ("a banked file carries no comment (cc1 2.8 cannot parse one)", not comments,
         "commented: %s" % ", ".join(comments[:3])),
        ("provenance is declared, never implied", all(e.get("provenance") == PROVENANCE for e in banked), ""),
    ]
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, detail in cases:
        print("  %s %s%s" % ("PASS" if ok else "FAIL", name, (" — " + detail) if detail and not ok else ""))
    print("%d/%d banked-exact case(s); %d banked of %d entries"
          % (len(cases) - bad, len(cases), len(banked), len(fixture["functions"])))
    return 0 if bad == 0 else 1


def self_test() -> int:
    dm = distance_map()
    index = json.loads((ROOT / "manifests" / "code_index.json").read_text())
    first = next(fn for image in index["images"] for fn in (image.get("functions_list") or [])
                 if fn.get("status") == "written")
    text, _syms, problem = body_for(dm, first["file"], "scalar")
    cases = [
        ("a provider body becomes self-contained C", text is not None and "typedef" in text and "{" in text, str(problem)),
        ("the text carries no comment", text is not None and "/*" not in text, ""),
    ]
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, detail in cases:
        print("  %s %s%s" % ("PASS" if ok else "FAIL", name, (" — " + detail) if detail and not ok else ""))
    print("%d/%d banked-exact self-test case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--limit", type=int, default=0)
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
