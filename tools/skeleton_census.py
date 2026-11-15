#!/usr/bin/env python3
"""How many open bodies differ from the cartridge in STRUCTURE, and in which way — measured before anything is built.

This is the plan's kill switch. `distance.json` says how many words differ and where the first one is; it cannot say
whether the skeleton is wrong, because the image's control flow was never decoded. `skeleton.py` decodes it, and this
tool compiles every open scored body once and classifies the difference between the image's skeleton and ours.

The population is deliberately the **open far band** — `scored`, not already claimed, gap > 0 — because that is where
the work is. The near band was measured out at M441 (19 bodies, every instrument 0).

The decision rule, fixed before the run: if fewer than `--threshold` (default 50) open bodies carry a **repairable**
class — every class except `none` and `likely-branch` — the structure loop is not worth building and this table is the
deliverable instead. `likely-branch` is excluded on measurement, not judgement: this cc1 has no `-mbranch-likely` and
gas will not relax into it (M442), so those bodies are unreachable and must not inflate the count.

    ./skeleton_census.py --write [--jobs 8] [--limit N]
    ./skeleton_census.py --check          # summary from the fixture + a deterministic sample, no corpus recompile
    ./skeleton_census.py --self-test
"""
from __future__ import annotations

import argparse
import concurrent.futures
import importlib.util
import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FIXTURE = ROOT / "fixtures" / "decomp" / "skeletons.json"
DISTANCE = ROOT / "fixtures" / "decomp" / "distance.json"
RECOVERED = ROOT / "fixtures" / "decomp" / "recovered.json"
MEASURED = ROOT / "fixtures" / "decomp" / "measured_extents.json"

import skeleton  # noqa: E402  — same directory; the decoder is the point of this tool


def _load(name, path):
    spec = importlib.util.spec_from_file_location(name, str(path))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


dm = _load("dm", ROOT / "tools" / "distance_map.py")
cp = dm.probe()
CC1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"


def compile_words(args):
    """(ours, target) word lists for one body, or None. Mirrors `distance_map.compile_one`'s ladder exactly."""
    image, addr, words, name, source, code, data = args
    scratch = Path(tempfile.mkdtemp(prefix="sk_", dir=str(cp.WORK)))
    body = dm.strip_comments((ROOT / source).read_text(errors="replace"))
    widths = dm.data_widths(cp, image, addr, words)
    attempts = [("scalar", body)] if dm.form_is_scalar(body, data) else \
        [("scalar", body), ("array", body), ("pointer", body)]
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    for _form, text in attempts:
        (scratch / "f.c").write_text(dm.build_source(text, data, _form, widths))
        if subprocess.run([str(CC1), "-quiet"] + dm.CFLAGS + [str(scratch / "f.c"), "-o", str(scratch / "f.s")],
                          capture_output=True).returncode:
            continue
        if subprocess.run([str(gas)] + dm.ASFLAGS + ["-o", str(scratch / "f.o"), str(scratch / "f.s")],
                          capture_output=True).returncode:
            continue
        cp.normalise_object(scratch / "f.o")
        subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                        "--set-section-alignment", ".rodata=8", str(scratch / "f.o"), str(scratch / "f.fix.o")],
                       capture_output=True)
        known = list(code) + list(data) + list(dm.image_symbols().items())

        def link(syms):
            (scratch / "l.ld").write_text(
                "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = 0x90000000;\n  .rodata : { *(.rodata) }\n"
                "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) "
                "*(.data) *(.bss) *(.sbss) }\n}\n" % addr
                + "__bss_start = 0x80100000; __bss_end = 0x80100000;\n"
                + "".join("%s = 0x%X;\n" % (n, a) for n, a in syms))
            return subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(scratch / "l.ld"), "-o",
                                   str(scratch / "f.elf"), str(scratch / "f.fix.o")],
                                  capture_output=True, text=True, errors="replace")

        result = link(known)
        if result.returncode:
            # Mirror `compile_one`: a helper this project does not model costs its own call word, not the whole body.
            # Without this the census silently dropped 11 of every 40 bodies — a refusal masquerading as absence.
            import re as _re
            missing = sorted(set(_re.findall(r"undefined reference to `([^']+)'", result.stderr or "")))
            far = [(n, 0x8F000000 + 4 * i) for i, n in enumerate(missing)]
            result = link(known + far)
        if result.returncode:
            continue
        got = cp.text_of(scratch / "f.elf")
        blob, base = cp.image_window(image, cp.image_inventory())
        want = blob[addr - base:addr - base + 4 * words]
        return ([int.from_bytes(got[4 * i:4 * i + 4], "big") for i in range(len(got) // 4)],
                [int.from_bytes(want[4 * i:4 * i + 4], "big") for i in range(words)])
    return None


def measure_one(args):
    """One body's record: skeleton of both sides, the difference class, and its size."""
    image, addr, words, _name, _source, _code, _data = args
    res = compile_words(args)
    if res is None:
        return None
    ours, want = res
    si = skeleton.signature(want, addr)
    so = skeleton.signature(ours, addr)
    cls = skeleton.diff(si, so)
    same = sum(1 for i in range(words) if i < len(ours) and ours[i] == want[i])
    return {"class": cls, "words": words, "gap": words - same,
            "image_loops": si["loop_edges"], "our_loops": so["loop_edges"],
            "image_forward": si["forward_branches"], "our_forward": so["forward_branches"],
            "image_returns": si["returns"], "our_returns": so["returns"],
            "image_early": si["early_returns"], "our_early": so["early_returns"],
            "image_pre": si["loop_pre_test"], "our_pre": so["loop_pre_test"],
            "image_blocks": si["blocks"], "our_blocks": so["blocks"], "our_words": so["words"]}


def open_targets():
    """Open = scored, not claimed by recovered.json, not claimed by measured_extents.json."""
    records = json.loads(DISTANCE.read_text())["records"]
    claimed = {(f["image"], int(f["address"], 16)) for f in json.loads(RECOVERED.read_text())["functions"]}
    claimed |= {(f["image"], int(f["address"], 16)) for f in json.loads(MEASURED.read_text())["functions"]}
    out = []
    for t in dm.functions_to_measure(None):
        key = "%s:%08x" % (t[0], t[1])
        if key not in records or records[key]["s"] != "scored":
            continue
        if (t[0], t[1]) in claimed:
            continue
        out.append(t)
    return out


REPAIRABLE = ("missing-loop", "extra-loop", "loop-count", "loop-kind", "guard-shape",
              "early-return", "nesting", "dispatch")
# `no-return` (a truncated extent) and `likely-branch` (unemittable, M442) are named and counted, never repairable.


def summarise(records: dict) -> dict:
    """The table. Derived from the records only, so `--check` can re-derive it without compiling anything."""
    classes, words_of = {}, {}
    for rec in records.values():
        classes[rec["class"]] = classes.get(rec["class"], 0) + 1
        words_of[rec["class"]] = words_of.get(rec["class"], 0) + rec["words"]
    repairable = sum(n for c, n in classes.items() if c in REPAIRABLE)
    return {"bodies": len(records), "classes": dict(sorted(classes.items(), key=lambda kv: -kv[1])),
            "words": dict(sorted(words_of.items(), key=lambda kv: -kv[1])),
            "repairable": repairable,
            "far": sum(1 for r in records.values() if r["gap"] > 4),
            "far_repairable": sum(1 for r in records.values() if r["gap"] > 4 and r["class"] in REPAIRABLE)}


def write(args) -> int:
    targets = open_targets()
    if args.limit:
        targets = targets[:args.limit]
    print("measuring %d open scored bodies with %d job(s)" % (len(targets), args.jobs), file=sys.stderr)
    records = {}
    with concurrent.futures.ProcessPoolExecutor(max_workers=args.jobs) as pool:
        for t, rec in zip(targets, pool.map(measure_one, targets, chunksize=8)):
            if rec is not None:
                records["%s:%08x" % (t[0], t[1])] = rec
    document = {
        "tool": "skeleton_census.py",
        "note": ("The control-flow skeleton of every open scored body, ours against the cartridge's. 'open' means "
                 "status scored and claimed by neither recovered.json nor measured_extents.json. 'class' is "
                 "skeleton.diff's closed vocabulary; 'likely-branch' is named because this toolchain cannot emit one "
                 "(M442), so it must not count toward the addressable set. A body absent from `records` compiled "
                 "under no rung of the ladder — a refusal, never a zero."),
        "classes": list(skeleton.CLASSES),
        "summary": summarise(records),
        "records": dict(sorted(records.items())),
    }
    FIXTURE.parent.mkdir(parents=True, exist_ok=True)
    FIXTURE.write_text(json.dumps(document, indent=1) + "\n")
    s = document["summary"]
    print("%d bodies: %d repairable (%.0f%%), %d far (gap>4) of which %d repairable"
          % (s["bodies"], s["repairable"], 100.0 * s["repairable"] / max(s["bodies"], 1),
             s["far"], s["far_repairable"]))
    for c, n in s["classes"].items():
        print("   %-14s %5d" % (c, n))
    return 0


def check(args) -> int:
    if not FIXTURE.exists():
        print("FAIL no fixture at %s — run --write" % FIXTURE, file=sys.stderr)
        return 1
    doc = json.loads(FIXTURE.read_text())
    records = doc["records"]
    bad = 0
    derived = summarise(records)
    same = derived == doc["summary"]
    print("  %s summary is derived from the records" % ("PASS" if same else "FAIL"))
    bad += 0 if same else 1
    # A deterministic sample re-measured through the same pipeline, so the fixture cannot drift from the pipeline.
    keys = sorted(records)
    step = max(len(keys) // 16, 1)
    sample = keys[::step][:16]
    bykey = {"%s:%08x" % (t[0], t[1]): t for t in dm.functions_to_measure(None)}
    drift = []
    for key in sample:
        if key not in bykey:
            continue
        again = measure_one(bykey[key])
        if again is None or again["class"] != records[key]["class"] or again["gap"] != records[key]["gap"]:
            drift.append(key)
    print("  %s a %d-body sample re-measures to the same class and gap%s"
          % ("PASS" if not drift else "FAIL", len(sample), "" if not drift else " — " + ", ".join(drift[:3])))
    bad += 0 if not drift else 1
    print("%d/%d skeleton-census case(s)" % (2 - bad, 2))
    return 0 if not bad else 1


def self_test() -> int:
    # The decoder's own controls are the substance; this checks the census's arithmetic on a synthetic record set.
    fake = {"a": {"class": "missing-loop", "words": 10, "gap": 5},
            "b": {"class": "none", "words": 4, "gap": 1},
            "c": {"class": "likely-branch", "words": 6, "gap": 2}}
    s = summarise(fake)
    cases = [("repairable excludes none and likely-branch", s["repairable"] == 1, str(s["repairable"])),
             ("far counts only gap > 4", s["far"] == 1 and s["far_repairable"] == 1,
              "%d/%d" % (s["far"], s["far_repairable"])),
             ("the table sums every record", sum(s["classes"].values()) == 3, str(s["classes"]))]
    ok = sum(1 for _n, g, _d in cases if g)
    for n, g, d in cases:
        print("  %s %s%s" % ("PASS" if g else "FAIL", n, "" if g else " — " + d))
    print("%d/%d census case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--threshold", type=int, default=50,
                    help="fewer repairable bodies than this and the structure loop is not worth building")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.check:
        return check(a)
    if a.write:
        return write(a)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
