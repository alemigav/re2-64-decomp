#!/usr/bin/env python3
"""Close the one-word residues by fixing the ACCESS TYPE — the lever the distance map's classification found.

M409 left 71 bodies one word from byte-exact. Classified by kind, **62 of 65 differ by OPCODE, not by register**, and
the opcodes are all load/store width or signedness:

    had lbu $v0,6($a0)     ours lb  $v0,6($a0)      -- a signed access where the image reads unsigned
    had andi $v0,$v0,0xff  ours sll $v0,$v0,24      -- the same defect one step later, in the extension
    had lbu $a0,-24972($v1) ours lw $a0,-24972($v1) -- byte width against word width
    had sll $a0,$a0,7      ours sll $a0,$a0,9       -- a shift amount, i.e. a different operand width

So the residue is not allocation, which is what every one of the last twenty milestones assumed. It is **the type of the
access**, and it is mechanical: the provider's C says `*(char *)`, the cartridge says `lbu`, and `*(unsigned char *)`
is the spelling that emits it. Proven on `ovl_008505e:0x80164108`: 13 of 14 → **14 of 14** with that one substitution.

This tool tries a bounded set of width/signedness substitutions per body, pins every variant through the same pipeline
the gate uses, banks the first that reaches the full word count, and refuses the rest with a recorded reason.

Provenance is unchanged: these are still the decompiler's C, `provenance: "provider"`, with a pinned reconstruction.

Usage:
  ./type_repair.py --write [--max-gap 1] [--limit N]   # close what it can, bank it
  ./type_repair.py --check                             # every banked body still pins
  ./type_repair.py --self-test                         # the substitution table is the one measured
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

# The substitution table, and every row of it is a width or a signedness — never a guess about behaviour. A body that
# needs an entry here needs exactly one thing: the access spelled the way the cartridge spells it.
# The substitution table, in CLASSES, because the closure rate per class is what says which instrument to build next.
# Every row is a width, a signedness or a declaration type -- never a guess about behaviour.
SUBS = [
    ("width", "*(char *)", "*(unsigned char *)"),
    ("width", "*(unsigned char *)", "*(char *)"),
    ("width", "*(signed char *)", "*(unsigned char *)"),
    ("width", "*(short *)", "*(unsigned short *)"),
    ("width", "*(unsigned short *)", "*(short *)"),
    ("width", "*(int *)", "*(unsigned int *)"),
    ("width", "*(unsigned int *)", "*(int *)"),
    ("width", "*(undefined1 *)", "*(signed char *)"),
    ("width", "*(undefined2 *)", "*(short *)"),
    ("width", "*(undefined4 *)", "*(int *)"),
    ("width", "(char)", "(unsigned char)"),
    ("width", "(unsigned char)", "(char)"),
    ("width", "(short)", "(unsigned short)"),
    ("width", "(unsigned short)", "(short)"),
    ("width", "(int)", "(unsigned int)"),
    ("width", "(unsigned int)", "(int)"),
    # A declaration's type, not a cast: `undefined2 uVar1` against `short uVar1` changes the width of every use.
    ("decltype", "undefined1 ", "unsigned char "),
    ("decltype", "undefined2 ", "short "),
    ("decltype", "undefined4 ", "int "),
    ("decltype", "short ", "unsigned short "),
    # The M396c lever, as a text substitution: a constant that the image materialises in a REGISTER often wants an
    # integer addition rather than pointer arithmetic (or the reverse).
    ("materialise", "*(undefined4 *)(param_1 + ", "*(undefined4 *)((int)param_1 + "),
    ("materialise", "*(int *)(param_1 + ", "*(int *)((int)param_1 + "),
    ("materialise", "*(unsigned char *)(param_1 + ", "*(unsigned char *)((int)param_1 + "),
]

# ORDER, as a separate grammar because it is not a substitution on one token: two operands of a COMMUTATIVE operator
# can be exchanged with no change of meaning, and the image sometimes has them the other way round. This is the
# mechanism M401 found worth 3 -> 43 on a 58-word body, in its cheapest mechanical form.
# Declaration-line signedness, as its own class: `char cVar1;` compiles to `sll 24` where the image has `andi 0xff`,
# and every use of that variable differs with it. A text substitution cannot express this (the word `char ` also
# occurs inside `unsigned char `), so the class works on declaration LINES.
DECLARE = re.compile(r"^(\s*)(unsigned\s+|signed\s+)?(char|short|int)(\s+\**[A-Za-z_])", re.M)
COMMUTATIVE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*(?:\[[^\]]*\])?)\s*([+&|^*])\s*"
                         r"([A-Za-z_][A-Za-z0-9_]*(?:\[[^\]]*\])?)\b")


def bank_module():
    spec = importlib.util.spec_from_file_location("be", str(ROOT / "tools" / "bank_exact.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def order_variants(text: str):
    """One variant per distinct commutative swap site, so a body with three candidates yields three variants."""
    out, seen = [], {text}
    for m in COMMUTATIVE.finditer(text):
        a, op, b = m.group(1), m.group(2), m.group(3)
        if a == b:
            continue
        cand = text[:m.start()] + "%s %s %s" % (b, op, a) + text[m.end():]
        if cand not in seen:
            seen.add(cand)
            out.append(("order: %s %s %s" % (a, op, b), cand))
    return out[:12]


def decl_variants(text: str):
    """One variant per distinct declaration signedness, so a body with two declarations yields two variants."""
    out, seen = [], {text}
    for m in DECLARE.finditer(text):
        indent, sign, base, tail = m.group(1), m.group(2) or "", m.group(3), m.group(4)
        new_sign = "" if sign.strip() == "unsigned" else "unsigned "
        cand = text[:m.start()] + "%s%s%s%s" % (indent, new_sign, base, tail) + text[m.end():]
        if cand not in seen:
            seen.add(cand)
            out.append(("declsign: %s%s -> %s%s" % (sign.strip(), base, new_sign.strip(), base), cand))
    return out[:12]


def variants(text: str):
    """Every single-substitution variant with the CLASS it belongs to — bounded and deterministic."""
    out = []
    seen = {text}
    for kind, old, new in SUBS:
        if old in text:
            cand = text.replace(old, new)
            if cand not in seen:
                seen.add(cand)
                out.append(("%s: %s -> %s" % (kind, old.strip("*() ") or old, new.strip("*() ") or new), cand))
    return out


def candidates(max_gap: int):
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
        out.append({"image": image, "address": addr, "words": rec["w"], "rung": rec.get("t", "scalar"),
                    "gap": rec["w"] - rec["i"]})
    out.sort(key=lambda c: (c["gap"], -c["words"], c["image"], c["address"]))
    return out


def write(args) -> int:
    be = bank_module()
    dm = be.distance_map()
    fixture = json.loads(RECOVERED.read_text())
    existing = {(e["image"], int(e["address"], 16)) for e in fixture["functions"]}
    todo = candidates(args.max_gap)
    if args.limit:
        todo = todo[:args.limit]
    closed, refused = 0, []
    per_class, per_gap = {}, {}
    for cand in todo:
        text, syms, problem = be.body_for(dm, None, cand["rung"], cand["image"], cand["address"])
        if text is None:
            refused.append("%s:0x%08x %s" % (cand["image"], cand["address"], problem))
            continue
        winner = None
        for label, variant in variants(text) + decl_variants(text) + order_variants(text):
            matched, why = be.pins(dm, variant, cand["image"], cand["address"], cand["words"], syms)
            if matched == cand["words"]:
                winner = (label, variant)
                per_class[label.split(":")[0]] = per_class.get(label.split(":")[0], 0) + 1
                per_gap[cand["gap"]] = per_gap.get(cand["gap"], 0) + 1
                break
        if winner is None:
            refused.append("%s:0x%08x still %d of %d — no width/signedness substitution closes it"
                           % (cand["image"], cand["address"], cand["words"] - cand["gap"], cand["words"]))
            continue
        label, text = winner
        out = AUTHORED / cand["image"] / ("%08x.c" % cand["address"])
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text)
        if (cand["image"], cand["address"]) not in existing:
            fixture["functions"].append({
                "image": cand["image"], "address": "0x%08x" % cand["address"], "words": cand["words"],
                "verdict": "byte-exact", "provenance": "provider",
                "probe": "imported: closed by access type (%s) and pinned word for word (M411)" % label,
                "source_file": str(out.relative_to(ROOT)), "syms": syms})
            existing.add((cand["image"], cand["address"]))
        closed += 1
    fixture["functions"].sort(key=lambda e: (e["image"], int(e["address"], 16)))
    RECOVERED.write_text(json.dumps(fixture, indent=1) + "\n")
    print("closed %d body(ies) by substitution; %d refused" % (closed, len(refused)))
    print("closure by class: " + (", ".join("%s=%d" % kv for kv in sorted(per_class.items())) or "none"))
    print("closure by gap:   " + (", ".join("gap%d=%d" % kv for kv in sorted(per_gap.items())) or "none"))
    for line in refused[:12]:
        print("  refused", line)
    print("recovered.json now holds %d entries (%d provider)"
          % (len(fixture["functions"]), sum(1 for e in fixture["functions"] if e.get("provenance") == "provider")))
    return 0


def check(args) -> int:
    be = bank_module()
    dm = be.distance_map()
    fixture = json.loads(RECOVERED.read_text())
    typed = [e for e in fixture["functions"] if "access type" in (e.get("probe") or "")]
    bad = []
    for entry in typed:
        text = (ROOT / entry["source_file"]).read_text()
        matched, why = be.pins(dm, text, entry["image"], int(entry["address"], 16), int(entry["words"]),
                               {k: v for k, v in (entry.get("syms") or {}).items()})
        if matched != int(entry["words"]):
            bad.append("%s:0x%s %d of %s (%s)" % (entry["image"], entry["address"], matched, entry["words"], why))
    print("  %s every type-repaired body still pins (%d checked)%s"
          % ("PASS" if not bad else "FAIL", len(typed), "" if not bad else " — " + "; ".join(bad[:3])))
    print("%d/1 type-repair case(s)" % (0 if bad else 1))
    return 0 if not bad else 1


def self_test() -> int:
    text = "x = *(char *)(p + 6);"
    got = [c for label, c in variants(text)]
    cases = [
        ("a signed byte access offers its unsigned spelling", any("unsigned char *)" in c for c in got), ""),
        ("no substitution adds or removes a statement", all(c.count(";") == text.count(";") for c in got), ""),
        ("a body with no cast yields no variant", variants("x = 1;") == [], ""),
    ]
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, detail in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", name))
    print("%d/%d type-repair self-test case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--max-gap", type=int, default=1, help="try bodies at most this many words from exact")
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
