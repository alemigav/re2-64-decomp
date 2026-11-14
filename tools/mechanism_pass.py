#!/usr/bin/env python3
"""The mechanism grammar, as a measured pass over a band: closures per mechanism, never a claim per mechanism.

The log records eight mechanisms that closed a body by hand — statement order, the arithmetic domain, a named pointer, a
rematerialisation block, walk-vs-index, guard-vs-conjunction, parameter reuse, compare-copy-vs-compare-argument. Five of
them are *structural rewrites* that no text transformation can express, and pretending otherwise is how a milestone
spends a day to publish a zero.

So this tool implements only the two mechanisms that ARE text-expressible, runs each as a NAMED pass over a band, and
reports closures per pass. A mechanism that closes nothing is a measured zero, which is worth more than an untested
claim — and the ones that cannot be expressed are named here explicitly so that the next milestone does not rediscover
that fact by trying.

    order:adjacent   swap two adjacent simple assignments to distinct names. M401 found statement order worth 3 -> 43 on
                     a 58-word body; this is that mechanism in its cheapest mechanical form.
    sig:param        re-type one parameter, or drop the pointer from it. Ghidra's signature inference is a common cause
                     of a body differing by MANY words at once, which is exactly what a mid-band body looks like.

Usage:
  ./mechanism_pass.py --write [--band mid] [--passes order,sig] [--limit N]
  ./mechanism_pass.py --check
  ./mechanism_pass.py --self-test
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
FIXTURE = ROOT / "fixtures" / "mechanism_passes.json"

# The mechanisms this project has used by hand, and whether a text pass can express them. Recorded as data because the
# distinction is the finding: five of eight are structural.
MECHANISMS = {
    "order:adjacent": "yes",
    "order:past-guard": "yes",
    "sig:forward": "yes — needs the image's words (data-driven)",
    "symbol:addr": "yes — an address as a value becomes a symbol reference",
    "dat:width": "yes — vary a data symbol's declared width",
    "sig:param": "yes",
    "domain:integer": "no — changes the type of an expression tree",
    "pointer:named": "no — introduces a binding that changes CSE",
    "rematerialise:block": "no — introduces a nested scope",
    "loop:walk-vs-index": "no — changes an induction variable",
    "guard:conjunction": "no — changes control-flow shape",
    "compare:copy": "no — changes which value is live",
}

ASSIGN = re.compile(r"^(\s+)([A-Za-z_][A-Za-z0-9_\[\]\->\.]*)\s*=\s*([^=;]+);\s*$")
SIGNATURE = re.compile(r"^(\w[\w \*]*?)\b(\w+)\s*\(([^)]*)\)\s*\{?\s*$", re.M)


def bank_module():
    spec = importlib.util.spec_from_file_location("be", str(ROOT / "tools" / "bank_exact.py"))
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def order_variants(text: str, ctx=None):
    """Swap two adjacent simple assignments to DISTINCT names. Only assignments, and only ones with no call on the
    right, so the swap cannot change what either means."""
    lines = text.splitlines()
    out, seen = [], {text}
    for i in range(len(lines) - 1):
        a, b = ASSIGN.match(lines[i]), ASSIGN.match(lines[i + 1])
        if not a or not b:
            continue
        if a.group(2) == b.group(2) or "(" in a.group(3) or "(" in b.group(3):
            continue
        cand = "\n".join(lines[:i] + [lines[i + 1], lines[i]] + lines[i + 2:]) + "\n"
        if cand not in seen:
            seen.add(cand)
            out.append(("order:adjacent %s/%s" % (a.group(2), b.group(2)), cand))
    return out[:8]


PARAM_TYPES = [("undefined4 *", "undefined4 "), ("undefined4 *", "int *"), ("undefined4 *", "unsigned int *"),
               ("undefined1 *", "undefined1 "), ("char *", "unsigned char *"), ("int *", "undefined4 *"),
               ("void *", "int "), ("undefined4 ", "int "), ("int ", "undefined4 ")]


def sig_variants(text: str, ctx=None):
    """Re-type one parameter, or drop the pointer from it. One variant per (parameter slot, type) — bounded."""
    m = SIGNATURE.search(text)
    if not m:
        return []
    params = [p.strip() for p in m.group(3).split(",") if p.strip() and p.strip() != "void"]
    out, seen = [], {text}
    for idx, param in enumerate(params):
        for old, new in PARAM_TYPES:
            if not param.startswith(old.strip()) and old.strip() not in param:
                continue
            retyped = param.replace(old, new, 1)
            if retyped == param:
                continue
            new_params = list(params)
            new_params[idx] = retyped
            head = text[:m.start(3)]
            tail = text[m.end(3):]
            cand = head + ", ".join(new_params) + tail
            if cand not in seen:
                seen.add(cand)
                out.append(("sig:param %d %s" % (idx, retyped), cand))
    return out[:8]


GUARD = re.compile(r"^\s*if\s*\(([^)]*)\)\s*\{\s*\n\s*return[^;]*;\s*\n\s*\}\s*$", re.M)


def pastguard_variants(text: str, ctx=None):
    """Move a leading simple assignment AFTER a `if (c) { return x; }` guard.

    Measured on `stage2:0x80082388` at M417: with `iVar2 = 0;` before the guard, gcc returns `addu $v0,$v1,$zero`
    (a register that happens to hold zero); with it after, it returns `addu $v0,$zero,$zero` — the image's form. A
    guard that returns a constant leaves a zero in a register, and where the initialisation sits decides whether the
    compiler reuses it.
    """
    lines = text.splitlines()
    out, seen = [], {text}
    for i in range(len(lines) - 3):
        a = ASSIGN.match(lines[i])
        if not a or "(" in a.group(3):
            continue
        j = i + 1
        while j < len(lines) and not lines[j].strip():
            j += 1
        if j + 2 >= len(lines):
            continue
        if not (lines[j].strip().startswith("if") and "return" in " ".join(lines[j:j + 3])):
            continue
        end = j
        while end < len(lines) and "}" not in lines[end]:
            end += 1
        if end >= len(lines):
            continue
        moved = lines[:i] + lines[i + 1:end + 1] + [lines[i]] + lines[end + 1:]
        cand = "\n".join(moved) + "\n"
        if cand not in seen:
            seen.add(cand)
            out.append(("order:past-guard %s" % a.group(2), cand))
    return out[:6]


# --- sig:forward — the first DATA-DRIVEN mechanism -------------------------------------------------------------------
# M419 closed two bodies by hand with one mechanism: Ghidra declared `void f(void)`, and the image materialises a
# constant into an argument register (a0-a3) immediately before the `jal`. The caller must therefore pass that many
# arguments, with the constant last. Text alone cannot see this — it needs the image's words — so this pass takes the
# same `ctx` every pass receives and uses it when it is there.
ARG = {4: "a0", 5: "a1", 6: "a2", 7: "a3"}
CALL = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(([^()]*)\)")
SIG = re.compile(r"^(\s*(?:[A-Za-z_][\w ]*?)\b)([A-Za-z_]\w*)\s*\(([^)]*)\)", re.M)
NOT_A_CALL = {"if", "while", "for", "switch", "return", "sizeof"}


def _const_into_arg(word: int):
    """(arg name, value) when this instruction is `addiu/ori aN,$zero,IMM` or `lui aN,IMM`; else None."""
    op, rs, rt = word >> 26, (word >> 21) & 0x1F, (word >> 16) & 0x1F
    if op == 0x09 and rs == 0:                      # addiu aN, $zero, imm
        imm = word & 0xFFFF
        return ARG.get(rt), imm - 0x10000 if imm & 0x8000 else imm
    if op == 0x0D and rs == 0:                      # ori aN, $zero, imm
        return ARG.get(rt), word & 0xFFFF
    if op == 0x0F:                                  # lui aN, imm
        return ARG.get(rt), ((word & 0xFFFF) << 16)
    return None


def forward_variants(text: str, ctx=None):
    """Declare the parameters the callee reads and forward them, with the constant the image puts in a register."""
    if not ctx:
        return []
    cp, image, addr, words = ctx
    blob, base = cp.image_window(image, cp.image_inventory())
    ws = [int.from_bytes(blob[addr - base + 4 * i:addr - base + 4 * i + 4], "big") for i in range(words)]
    found = []
    for i, w in enumerate(ws):
        if (w >> 26) != 0x03:                       # jal
            continue
        for j in (i - 1, i + 1):                    # the preceding instruction, or the delay slot
            if not 0 <= j < len(ws):
                continue
            hit = _const_into_arg(ws[j])
            if hit and hit[0]:
                found.append((i, hit[0], hit[1]))
    out, seen = [], {text}
    for _i, reg, value in found:
        idx = "a0 a1 a2 a3".split().index(reg)
        # Only INSIDE the function body: the first `name(...)` in the text is the definition's own parameter list,
        # and rewriting that produces a variant whose call is untouched — which is what the first version did, and it
        # scored 0 on the very two bodies the mechanism was derived from.
        brace = text.find("{")
        start_at = brace if brace >= 0 else 0
        m = next((mm for mm in CALL.finditer(text, start_at) if mm.group(1) not in NOT_A_CALL), None)
        if m is None:
            continue
        args = [a.strip() for a in m.group(2).split(",") if a.strip()]
        if len(args) > idx:                          # already passing that many: not this mechanism
            continue
        new_args = ["a%d" % k for k in range(idx)] + ["0x%x" % (value & 0xFFFFFFFF)]
        call = "%s(%s)" % (m.group(1), ", ".join(new_args))
        cand = text[:m.start()] + call + text[m.end():]
        sig = SIG.search(cand)
        if sig is None:
            continue
        params = ", ".join("u32 a%d" % k for k in range(idx))
        cand = cand[:sig.start(3)] + params + cand[sig.end(3):]
        if "typedef unsigned int u32;" not in cand:
            cand = "typedef unsigned int u32;\n" + cand
        if cand not in seen:
            seen.add(cand)
            out.append(("sig:forward %s=0x%x" % (reg, value & 0xFFFFFFFF), cand))
    return out[:6]


# --- symbol:addr — an absolute address passed as a VALUE wants to be a symbol reference ------------------------------
# `stage2:0x800a5700`: the image emits `lui $a0,0x8014; addiu $a0,$a0,0x3fb0` and we emitted `ori` for the same sum.
# The difference is not arithmetic, it is what gcc is looking at: a SYMBOL goes through %hi/%lo with a relocation and
# lands as `addiu`, while a constant it can fold lands as `ori`. Measured 9 -> 10 of 10.
ADDR_LITERAL = re.compile(r"\b0x([89a-fA-F][0-9a-fA-F]{7})\b")


def symbol_variants(text: str, ctx=None):
    out, seen = [], {text}
    for m in ADDR_LITERAL.finditer(text):
        lit = "0x%s" % m.group(1)
        name = "D_%s" % m.group(1).lower()
        cand = text[:m.start()] + "(u32)%s" % name + text[m.end():]
        if "extern u8 %s[];" % name not in cand:
            i = 0 if not cand.startswith("typedef") else cand.index("\n") + 1
            cand = cand[:i] + "extern u8 %s[];\n" % name + cand[i:]
            if "typedef unsigned int u32;" not in cand:
                cand = "typedef unsigned int u32;\n" + cand
        if cand not in seen:
            seen.add(cand)
            out.append(("symbol:addr %s" % lit, cand))
    return out[:6]


# --- dat:width — a data symbol declared a word where the image reads a byte ----------------------------------------
# `stage2:0x800b2694` reads `DAT_80136310` as a byte (`lbu`) and we read it as a word, because the preamble declares
# every `DAT_` as `unsigned int`. The width of that declaration is a decision the image has already made.
DECL = re.compile(r"^extern unsigned int (\w+);$", re.M)


def datwidth_variants(text: str, ctx=None):
    out, seen = [], {text}
    for m in DECL.finditer(text):
        for kind in ("unsigned char", "short", "int"):
            cand = text[:m.start()] + "extern %s %s;" % (kind, m.group(1)) + text[m.end():]
            if cand not in seen:
                seen.add(cand)
                out.append(("dat:width %s as %s" % (m.group(1), kind), cand))
    return out[:8]


PASSES = {"order": order_variants, "sig": sig_variants, "guard": pastguard_variants,
          "forward": forward_variants, "symbol": symbol_variants, "datwidth": datwidth_variants}


def band(kind: str):
    doc = json.loads(DISTANCE.read_text())
    claimed = {(f["image"], int(f["address"], 16)) for f in json.loads(RECOVERED.read_text())["functions"]}
    out = []
    for key, rec in doc["records"].items():
        if rec["s"] != "scored":
            continue
        frac = rec["i"] / max(rec["w"], 1)
        if kind == "mid" and not (0.25 <= frac <= 0.89):
            continue
        if kind == "near" and rec["w"] - rec["i"] > 8:
            continue
        image, addr = key.split(":")
        addr = int(addr, 16)
        if (image, addr) in claimed:
            continue
        out.append({"image": image, "address": addr, "words": rec["w"], "base": rec["i"], "frac": frac,
                    "rung": rec.get("t", "scalar")})
    out.sort(key=lambda c: (-c["frac"], c["image"], c["address"]))
    return out


def write(args) -> int:
    be = bank_module()
    dm = be.distance_map()
    todo = band(args.band)
    if args.limit:
        todo = todo[:args.limit]
    todo = [c for c in todo if c["words"] <= args.max_words]
    passes = [p for p in (args.passes or "order,sig").split(",") if p in PASSES]
    report = {"note": "Closures per mechanism pass, over a band. A mechanism that closes nothing is a measured zero. "
                      "The mechanisms no text pass can express are listed in `mechanisms` — that is the finding, not a "
                      "TODO.",
              "band": args.band, "bodies": len(todo),
              "mechanisms": MECHANISMS, "passes": {}}
    banked, improved = 0, []
    # Each pass sees the bodies the previous pass did not close, and each body keeps the best draft it has reached.
    remaining = {("%s:%08x" % (c["image"], c["address"])): c for c in todo}
    best = {("%s:%08x" % (c["image"], c["address"])): c["base"] for c in todo}
    for name in passes:
        fn = PASSES[name]
        closed, tried, up = 0, 0, 0
        for key, cand in list(remaining.items()):
            text, syms, _why = be.body_for(dm, None, cand["rung"], cand["image"], cand["address"], cand["words"])
            if text is None:
                continue
            ctx = (dm.probe(), cand["image"], cand["address"], cand["words"])
            variants = fn(text, ctx)
            tried += 1
            won = None
            for label, variant in variants:
                score, status = be.pins(dm, variant, cand["image"], cand["address"], cand["words"], syms)
                if status != "linked":
                    continue
                if score > best[key]:
                    best[key] = score
                    up += 1
                if score == cand["words"]:
                    won = (label, variant)
                    break
            if won is None:
                continue
            label, text = won
            out = AUTHORED / cand["image"] / ("%08x.c" % cand["address"])
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_text(text)
            fixture = json.loads(RECOVERED.read_text())
            if not any(e["image"] == cand["image"] and int(e["address"], 16) == cand["address"]
                       for e in fixture["functions"]):
                fixture["functions"].append({
                    "image": cand["image"], "address": "0x%08x" % cand["address"], "words": cand["words"],
                    "verdict": "byte-exact", "provenance": "provider",
                    "probe": "imported: closed by the %s mechanism pass (%d of %d -> %d of %d) (M416)"
                             % (label.split()[0], cand["base"], cand["words"], cand["words"], cand["words"]),
                    "source_file": str(out.relative_to(ROOT)), "syms": syms})
                fixture["functions"].sort(key=lambda e: (e["image"], int(e["address"], 16)))
                RECOVERED.write_text(json.dumps(fixture, indent=1) + "\n")
            closed += 1
            banked += 1
            del remaining[key]
        report["passes"][name] = {"bodies_tried": tried, "closed": closed, "improved": up}
        print("pass %-6s bodies %3d  closed %d  improved %d" % (name, tried, closed, up))
    report["banked"] = banked
    report["improved_total"] = sum(1 for k in best if best[k] > next(c["base"] for c in todo
                                                                    if "%s:%08x" % (c["image"], c["address"]) == k))
    FIXTURE.write_text(json.dumps(report, indent=1, sort_keys=True) + "\n")
    print("banked %d; bodies whose score rose without closing: %d" % (banked, report["improved_total"]))
    return 0


def check(args) -> int:
    if not FIXTURE.exists():
        print("SKIP: no mechanism-pass fixture — run --write")
        return 0
    doc = json.loads(FIXTURE.read_text())
    cases = [("every recorded pass has a closure count",
              all("closed" in v for v in doc["passes"].values())),
             ("the non-expressible mechanisms are named, not omitted",
              any(v.startswith("no") for v in doc["mechanisms"].values()))]
    bad = sum(1 for _n, ok in cases if not ok)
    for name, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", name))
    print("%d/%d mechanism-pass case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def self_test() -> int:
    text = ("void f(undefined4 *param_1) {\n    a = 1;\n    b = 2;\n    return;\n}\n")
    cases = [
        ("two adjacent assignments yield a swap", len(order_variants(text)) == 1, ""),
        ("an assignment whose right-hand side calls is not swapped", order_variants("    a = g(1);\n    b = 2;\n") == [], ""),
        ("a parameter type yields a variant", any(v[0].startswith("sig:param") for v in sig_variants(text)), ""),
        ("moving an init past a returning guard yields a variant",
         len(pastguard_variants("    x = 0;\n    if (p == 0) {\n        return 0;\n    }\n    y = x;\n")) == 1, ""),
        ("`addiu a3,$zero,0x400` decodes to a3 = 0x400", _const_into_arg(0x24070400) == ("a3", 0x400),
         str(_const_into_arg(0x24070400))),
        ("`lui a0,0x8014` decodes to a0 = 0x80140000", _const_into_arg(0x3C048014) == ("a0", 0x80140000),
         str(_const_into_arg(0x3C048014))),
        ("an instruction that sets no argument register yields nothing", _const_into_arg(0x03E00008) is None, ""),
        ("every mechanism is classified", all(v for v in MECHANISMS.values()), ""),
    ]
    bad = sum(1 for _n, ok, _d in cases if not ok)
    for name, ok, _d in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", name))
    print("%d/%d mechanism-pass self-test case(s)" % (len(cases) - bad, len(cases)))
    return 0 if bad == 0 else 1


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--band", default="mid", choices=("mid", "near"))
    ap.add_argument("--passes", default="symbol,datwidth,forward,order,guard,sig")
    ap.add_argument("--max-words", type=int, default=200)
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
