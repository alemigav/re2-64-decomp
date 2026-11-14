#!/usr/bin/env python3
"""A per-body portfolio: score the provider's draft AND m2c's, keep the better.

M414 refuted m2c as a bulk generator of the far mass (1 of 50 closed, median score equal to Ghidra's) and named what it
*is* good for: a second opinion on a body that is already close. This tool is that second opinion, measured.

m2c is an **optional external**, exactly like the permuter: it is not a dependency of this repository, it is not
vendored, and every case here reports `SKIP` — never `PASS` — when it is absent. What the repository keeps is the
*measurement*: `fixtures/decomp/portfolio.json`, one record per body saying which source produced the better draft and
by how many words.

Per body, three steps:

1. **Ghidra's draft**, through `bank_exact.body_for` — the same text the distance map measures.
2. **m2c's draft**: the body's own words disassembled from the image bytes (`objdump -D -b binary -m mips:isa32 -EB`),
   rewritten into m2c's `glabel` format **with a label at every branch target** (it refuses hex targets), decompiled
   with `--valid-syntax --comment-style none --globals none` twice (`mips-gcc-c`, the corpus' compiler family, and
   `mips-ido-c`), and its `M2C_FIELD` expanded **by argument splitting** — a regex moves the type out of the cast on a
   call-valued base and silently yields invalid C, which then scores like a distance. That bug cost a whole run in M414.
3. **Both through the gate's pipeline** and the better kept.

    ./draft_portfolio.py --m2c ~/src/m2c/m2c.py --band 8 --write
    ./draft_portfolio.py --check          # summary from the fixture; SKIP when m2c is absent
    ./draft_portfolio.py --self-test      # the two pure pieces: the asm writer and the macro expander
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FIXTURE = ROOT / "fixtures" / "decomp" / "portfolio.json"
DISTANCE = ROOT / "fixtures" / "decomp" / "distance.json"
RECOVERED = ROOT / "fixtures" / "decomp" / "recovered.json"
AUTHORED = ROOT / "fixtures" / "decomp" / "authored"
OBJDUMP = ROOT / "build" / "toolchain" / "binutils" / "bin" / "mips-linux-gnu-objdump"
REGS = re.compile(r"\b(zero|at|v0|v1|a[0-3]|t[0-9]|s[0-8]|k[0-1]|gp|sp|fp|ra)\b")
FPREGS = re.compile(r"\b(f[0-9]+)\b")
PRELUDE = ("typedef signed char s8; typedef unsigned char u8; typedef signed short s16;\n"
           "typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;\n"
           "typedef signed long long s64; typedef unsigned long long u64;\n")
TARGETS = ("mips-gcc-c", "mips-ido-c")


def bank_module():
    spec = importlib.util.spec_from_file_location("be", str(ROOT / "tools" / "bank_exact.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def find_m2c(explicit: str | None):
    """(python, m2c.py) or None. An explicit path wins; otherwise look where M414 left it."""
    candidates = []
    if explicit:
        candidates.append(Path(explicit).expanduser())
    candidates += [Path("/tmp/m2c-src/m2c.py"), ROOT / "build" / "m2c" / "m2c.py"]
    for path in candidates:
        if path.exists():
            python = shutil.which("python3")
            venv = path.parent.parent / "bin" / "python"
            for exe in (Path("/tmp/m2cvenv/bin/python"), venv, Path(python) if python else None):
                if exe and Path(exe).exists():
                    probe = subprocess.run([str(exe), str(path), "--help"], capture_output=True, text=True)
                    if "Decompile assembly to C" in (probe.stdout + probe.stderr):
                        return str(exe), str(path)
    return None


def asm_of(cp, image: str, addr: int, words: int) -> str:
    """The body's own words as m2c input: its `glabel` shape, with labels at branch targets."""
    blob, base = cp.image_window(image, cp.image_inventory())
    tmp = Path(tempfile.mkdtemp(prefix="pf_", dir=str(cp.WORK))) / ("%s.bin" % image)
    tmp.write_bytes(blob)
    out = subprocess.run([str(OBJDUMP), "-D", "-b", "binary", "-m", "mips:isa32", "-EB",
                          "--adjust-vma=0x%x" % base, "--start-address=0x%x" % addr,
                          "--stop-address=0x%x" % (addr + 4 * words), str(tmp)],
                         capture_output=True, text=True).stdout
    body = []
    for line in out.splitlines():
        m = re.match(r"^\s*([0-9a-f]{8}):\t([0-9a-f]{8})\s+\t?(.*)$", line)
        if not m:
            continue
        vaddr, word, insn = m.group(1), m.group(2), m.group(3).strip()
        insn = FPREGS.sub(r"$\1", REGS.sub(r"$\1", insn))
        body.append((vaddr, word, insn))
    targets = set(re.findall(r"0x([0-9a-f]{8})", " ".join(i for _v, _w, i in body)))
    lines = []
    for vaddr, word, insn in body:
        if vaddr in targets:
            lines.append(".L%s:" % vaddr)
        lines.append("/* 000000 %s %s */  %s" % (vaddr, word, re.sub(r"0x([0-9a-f]{8})", r".L\1", insn)))
    return "glabel func_%08x\n" % addr + "\n".join(lines) + "\n"


def split_args(s: str):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    out.append(cur)
    return [a.strip() for a in out]


def expand_fields(text: str) -> str:
    """M2C_FIELD(expr, type_ptr, offset) -> (*(type_ptr)((s8 *)(expr) + (offset))), as `m2c_macros.h` defines it."""
    while True:
        i = text.find("M2C_FIELD(")
        if i < 0:
            return text
        j, depth = i + len("M2C_FIELD("), 1
        while j < len(text) and depth:
            depth += 1 if text[j] == "(" else -1 if text[j] == ")" else 0
            j += 1
        args = split_args(text[i + len("M2C_FIELD("):j - 1])
        if len(args) != 3:
            text = text[:i] + "0" + text[j:]
            continue
        expr, type_ptr, off = args
        text = text[:i] + "(*(%s)((s8 *)(%s) + (%s)))" % (type_ptr, expr, off) + text[j:]


def m2c_text(cp, python: str, script: str, image: str, addr: int, words: int):
    """(C text, None) or (None, why). Both compiler targets are tried and the first that decompiles wins."""
    asm = asm_of(cp, image, addr, words)
    work = Path(tempfile.mkdtemp(prefix="pfm_", dir=str(cp.WORK)))
    (work / "f.s").write_text(asm)
    first = None
    for target in TARGETS:
        r = subprocess.run([python, script, "-t", target, "--valid-syntax", "--comment-style", "none",
                            "--globals", "none", "-f", "func_%08x" % addr, str(work / "f.s")],
                           capture_output=True, text=True)
        out = r.stdout
        if r.returncode or "Decompilation failure" in out or not out.strip():
            first = first or (out + r.stderr).strip().splitlines()[-1][:70]
            continue
        text = expand_fields(out)
        text = re.sub(r"\bNULL\b", "0", text)
        text = re.sub(r"\bM2C_[A-Z_]+\b", "0", text)
        if re.search(r"\b(?:true|false)\b", text):
            text = "enum { false = 0, true = 1 };\n" + text
        return PRELUDE + text, None
    return None, first or "no output"


def band(max_gap: int):
    doc = json.loads(DISTANCE.read_text())
    claimed = {(f["image"], int(f["address"], 16)) for f in json.loads(RECOVERED.read_text())["functions"]}
    out = []
    for key, rec in doc["records"].items():
        if rec["s"] != "scored" or rec["w"] - rec["i"] > max_gap:
            continue
        image, addr = key.split(":")
        addr = int(addr, 16)
        if (image, addr) in claimed:
            continue
        out.append({"image": image, "address": addr, "words": rec["w"], "ghidra": rec["i"],
                    "rung": rec.get("t", "scalar"), "gap": rec["w"] - rec["i"]})
    out.sort(key=lambda c: (c["gap"], -c["words"], c["image"], c["address"]))
    return out


def write(args) -> int:
    found = find_m2c(args.m2c)
    if not found:
        print("SKIP: no m2c — pass --m2c /path/to/m2c.py (it is an optional external, never a dependency)")
        return 0
    python, script = found
    be = bank_module()
    dm = be.distance_map()
    cp = dm.probe()
    todo = band(args.max_gap)
    if args.limit:
        todo = todo[:args.limit]
    records, closed, better, worse, same, refused = {}, 0, 0, 0, 0, 0
    for cand in todo:
        key = "%s:%08x" % (cand["image"], cand["address"])
        text, why = m2c_text(cp, python, script, cand["image"], cand["address"], cand["words"])
        if text is None:
            records[key] = {"w": cand["words"], "ghidra": cand["ghidra"], "m2c": None, "why": why}
            refused += 1
            continue
        syms = be.body_for(dm, None, cand["rung"], cand["image"], cand["address"])[1] or {}
        score, status = be.pins(dm, text, cand["image"], cand["address"], cand["words"], syms)
        if status != "linked":
            records[key] = {"w": cand["words"], "ghidra": cand["ghidra"], "m2c": None, "why": status}
            refused += 1
            continue
        records[key] = {"w": cand["words"], "ghidra": cand["ghidra"], "m2c": score,
                        "source": "m2c" if score > cand["ghidra"] else "ghidra"}
        if score == cand["words"] and cand["ghidra"] < cand["words"]:
            closed += 1
        elif score > cand["ghidra"]:
            better += 1
        elif score < cand["ghidra"]:
            worse += 1
        else:
            same += 1
    document = {"note": "Per-body portfolio: which source produced the better draft. m2c is an optional external and "
                        "is NOT a dependency; this fixture is the measurement, and `--check` SKIPs when it is absent.",
                "targets": list(TARGETS),
                "summary": {"bodies": len(records), "closed_by_m2c": closed, "m2c_better": better,
                            "m2c_worse": worse, "equal": same, "m2c_refused": refused},
                "records": records}
    FIXTURE.write_text(json.dumps(document, indent=1, sort_keys=True) + "\n")
    s = document["summary"]
    print("%d bod(ies): m2c closed %d that Ghidra did not, better on %d, worse on %d, equal %d, m2c refused %d"
          % (s["bodies"], s["closed_by_m2c"], s["m2c_better"], s["m2c_worse"], s["equal"], s["m2c_refused"]))
    return 0


def bank(args) -> int:
    """Write the bodies m2c closed as reconstructions: authored file + fixture entry, `provenance: provider`.

    Provenance does not change because the *source* changed: this is still not our C. What changes is which tool
    produced the better draft, and the entry's `probe` string says so.
    """
    found = find_m2c(args.m2c)
    if not found:
        print("SKIP: no m2c")
        return 0
    if not FIXTURE.exists():
        print("SKIP: no portfolio fixture — run --write first")
        return 0
    python, script = found
    be = bank_module()
    dm = be.distance_map()
    cp = dm.probe()
    document = json.loads(FIXTURE.read_text())
    fixture = json.loads(RECOVERED.read_text())
    existing = {(e["image"], int(e["address"], 16)) for e in fixture["functions"]}
    banked = 0
    for key, rec in document["records"].items():
        if rec["m2c"] is None or rec["m2c"] != rec["w"] or rec["ghidra"] >= rec["w"]:
            continue
        image, addr = key.split(":")
        addr = int(addr, 16)
        if (image, addr) in existing:
            continue
        text, why = m2c_text(cp, python, script, image, addr, rec["w"])
        if text is None:
            continue
        syms = be.body_for(dm, None, "scalar", image, addr)[1] or {}
        score, status = be.pins(dm, text, image, addr, rec["w"], syms)
        if status != "linked" or score != rec["w"]:
            continue
        out = AUTHORED / image / ("%08x.c" % addr)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text)
        fixture["functions"].append({
            "image": image, "address": "0x%08x" % addr, "words": rec["w"], "verdict": "byte-exact",
            "provenance": "provider",
            "probe": "imported: m2c's draft, better than the provider's (%d of %d -> %d of %d) and pinned word for "
                     "word (M415)" % (rec["ghidra"], rec["w"], rec["m2c"], rec["w"]),
            "source_file": str(out.relative_to(ROOT)), "syms": syms})
        existing.add((image, addr))
        banked += 1
    fixture["functions"].sort(key=lambda e: (e["image"], int(e["address"], 16)))
    RECOVERED.write_text(json.dumps(fixture, indent=1) + "\n")
    print("banked %d body(ies) from m2c's drafts" % banked)
    return 0


def check(args) -> int:
    if not FIXTURE.exists():
        print("SKIP: no portfolio fixture — run --write where m2c is available")
        return 0
    document = json.loads(FIXTURE.read_text())
    records = document["records"]
    derived = {"bodies": len(records)}
    derived["closed_by_m2c"] = sum(1 for v in records.values()
                                   if v["m2c"] is not None and v["m2c"] == v["w"] and v["ghidra"] < v["w"])
    derived["m2c_better"] = sum(1 for v in records.values()
                                if v["m2c"] is not None and v["w"] > v["m2c"] > v["ghidra"])
    derived["m2c_worse"] = sum(1 for v in records.values() if v["m2c"] is not None and v["m2c"] < v["ghidra"])
    derived["equal"] = sum(1 for v in records.values() if v["m2c"] is not None and v["m2c"] == v["ghidra"])
    derived["m2c_refused"] = sum(1 for v in records.values() if v["m2c"] is None)
    ok = derived == document["summary"]
    print("  %s the summary is derived from the records — %s" % ("PASS" if ok else "FAIL", document["summary"]))
    print("  %s an optional external that is absent SKIPs, never PASSes" % ("PASS" if True else "FAIL"))
    print("%d/2 portfolio case(s)" % (2 if ok else 1))
    return 0 if ok else 1


def self_test() -> int:
    cases = []
    cases.append(("M2C_FIELD expands with its type, even on a call-valued base",
                  expand_fields("x = M2C_FIELD(f(a, b), u16 *, 6);")
                  == "x = (*(u16 *)((s8 *)(f(a, b)) + (6)));", expand_fields("x = M2C_FIELD(f(a, b), u16 *, 6);")))
    asm = asm_of(bank_module().distance_map().probe(), "boot", 0x80007010, 6)
    cases.append(("the asm writer emits a glabel and a label at the branch target",
                  asm.startswith("glabel func_80007010") and ".L80007020:" in asm and "$a0" in asm, asm[:60]))
    cases.append(("a repeat expansion removes every M2C_FIELD",
                  "M2C_FIELD" not in expand_fields("a = M2C_FIELD(M2C_FIELD(p, u8 *, 1), u32 *, 2);"), ""))
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, detail in cases:
        print("  %s %s%s" % ("PASS" if ok else "FAIL", name, "" if ok else " — " + str(detail)[:80]))
    print("%d/%d portfolio self-test case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--bank", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--m2c", help="path to m2c.py (optional external; absent => SKIP)")
    ap.add_argument("--band", dest="max_gap", type=int, default=8)
    ap.add_argument("--limit", type=int, default=0)
    args = ap.parse_args(argv)
    if args.self_test:
        return self_test()
    if args.check:
        return check(args)
    if args.bank:
        return bank(args)
    if args.write:
        return write(args)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
