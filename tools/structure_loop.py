#!/usr/bin/env python3
"""Propose STATEMENT STRUCTURE to a draft, from the image's control-flow skeleton, and iterate to a fixpoint.

This is the piece the plan called for: not substitutions. `type_repair` swaps a token; `mechanism_pass` edits one
statement; this rewrites the SHAPE — which branch carries the `return`, whether two conditions are nested or conjoined,
which form the loop takes. The census put that population at **1 785 of 2 478 open bodies (72 %)**, dominated by
`early-return` (820) and `guard-shape` (351).

Three rules, each learned the hard way in this repository:

  * the objective is the **byte metric**, not a score of our own. Every variant is judged by `bank_exact.pins`, the same
    compile/assemble/link/compare the gate uses (M390: the permuter's own score is not the verdict).
  * a variant is accepted only on a **strict improvement** in identical words, and the loop records a stall rather than
    pretending a tie is progress (M431).
  * a template that hard-codes one body's constants would be a lookup table. Every template here is a
    **semantics-preserving rewrite** of the draft's own text, so it cannot invent an answer; and the positive control
    (`--self-test`) mechanically BREAKS a body whose answer is known and requires the loop to put it back.

    ./structure_loop.py --at ovl_009dd02:0x80166408 [--rounds 6] [--dry-run]
    ./structure_loop.py --self-test        # break/restore controls
    ./structure_loop.py --check            # the fixture is derived from the traces
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
FIXTURE = ROOT / "fixtures" / "decomp" / "structure_loops.json"
AUTHORED = ROOT / "fixtures" / "decomp" / "authored"
VARIANT_CAP = 48          # M432: a cap applied by TEXT ORDER discards the variant that closes the body


def _load(name, path):
    spec = importlib.util.spec_from_file_location(name, str(path))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


skeleton = _load("skeleton", ROOT / "tools" / "skeleton.py")
dm = _load("dm", ROOT / "tools" / "distance_map.py")


def bank():
    return _load("be", ROOT / "tools" / "bank_exact.py")


# --- a minimal brace matcher: enough C structure to rewrite a shape, and no more -------------------------------

def match(text: str, i: int, open_ch: str = "{", close_ch: str = "}") -> int:
    """Index just past the block that opens at `i`, or -1. Skips strings and character literals."""
    depth, n = 0, len(text)
    while i < n:
        c = text[i]
        if c in "\"'":
            q, i = c, i + 1
            while i < n and text[i] != q:
                i += 2 if text[i] == "\\" else 1
        elif c == open_ch:
            depth += 1
        elif c == close_ch:
            depth -= 1
            if depth == 0:
                return i + 1
        i += 1
    return -1


IF = re.compile(r"(?m)^([ \t]*)if\s*\(")


def if_sites(text: str):
    """Every `if (cond) { body }` with an optional `else { body }`, as byte offsets. Top-level of the search only —
    nested sites are found by scanning the whole text, so a rewrite can carry its own sub-sites."""
    out = []
    for m in IF.finditer(text):
        indent, p = m.group(1), m.end() - 1                 # p is at '('
        cond_end = match(text, p, "(", ")")
        if cond_end < 0:
            continue
        j = cond_end
        while j < len(text) and text[j] in " \t\r\n":
            j += 1
        if j >= len(text) or text[j] != "{":
            continue
        body_end = match(text, j)
        if body_end < 0:
            continue
        site = {"start": m.start(), "indent": indent, "cond": text[p + 1:cond_end - 1].strip(),
                "cond_open": p, "cond_close": cond_end - 1, "body_open": j, "body_close": body_end - 1,
                "body": text[j + 1:body_end - 1], "else": None}
        k = body_end
        while k < len(text) and text[k] in " \t\r\n":
            k += 1
        if text.startswith("else", k):
            k += 4
            while k < len(text) and text[k] in " \t\r\n":
                k += 1
            if k < len(text) and text[k] == "{":
                eb = match(text, k)
                if eb > 0:
                    site["else"] = {"open": k, "close": eb - 1, "body": text[k + 1:eb - 1]}
                    site["end"] = eb
            elif k < len(text) and text.startswith("if", k):
                # `else if (...)`: treat the tail as the else body, brace-matched through its own chain
                eb = text.find("{", k)
                eb2 = match(text, eb) if eb >= 0 else -1
                if eb2 > 0:
                    site["else"] = {"open": eb, "close": eb2 - 1, "body": text[eb + 1:eb2 - 1], "chain": True}
                    site["end"] = eb2
        if site.get("end") is None:
            site["end"] = body_end
        out.append(site)
    return out


NEGATE = [("==", "!="), ("!=", "=="), ("<=", ">"), (">=", "<"), ("<", ">="), (">", "<=")]


def negate(cond: str) -> str:
    """A condition's opposite, written the way the compiler sees it. `<` and `>=` are different opcodes, so a
    comparison is inverted as a comparison rather than wrapped in `!` wherever the text allows it."""
    cond = cond.strip()
    m = re.match(r"^(.*?)\s*(==|!=|<=|>=|<|>)\s*(.*)$", cond, re.S)
    if m and m.group(1).strip() and m.group(3).strip():
        for a, b in NEGATE:
            if m.group(2) == a:
                return "%s %s %s" % (m.group(1).strip(), b, m.group(3).strip())
    if cond.startswith("!") and not cond.startswith("!="):
        return cond[1:].strip()
    return "!(%s)" % cond


# --- the templates: whole-body rewrites, each semantics-preserving by construction -----------------------------

def t_swap(text: str):
    """`if (c) { A } else { B }` -> `if (!c) { B } else { A }`. Same branches, opposite test."""
    for s in if_sites(text):
        if not s["else"] or s["else"].get("chain"):
            continue
        new = "%sif (%s) { %s } else { %s }" % (s["indent"], negate(s["cond"]),
                                                s["else"]["body"].strip(), s["body"].strip())
        yield "guard:swap", text[:s["start"]] + new + text[s["end"]:]


def t_collapse(text: str):
    """`if (c) { if (d) { A } }` -> `if (c && d) { A }`. One branch fewer, same predicate."""
    for s in if_sites(text):
        if s["else"]:
            continue
        inner = [t for t in if_sites(s["body"]) if not t["else"]]
        if len(inner) != 1:
            continue
        i = inner[0]
        if s["body"][:i["start"]].strip() or s["body"][i["end"]:].strip():
            continue                                        # only when the inner if is the entire outer body
        new = "%sif (%s && %s) { %s }" % (s["indent"], s["cond"], i["cond"], i["body"].strip())
        yield "guard:collapse", text[:s["start"]] + new + text[s["end"]:]


def t_expand(text: str):
    """`if (c && d) { A }` -> `if (c) { if (d) { A } }`, split at the LAST top-level `&&`."""
    for s in if_sites(text):
        if s["else"] or " && " not in s["cond"]:
            continue
        cut = s["cond"].rfind(" && ")
        outer, inner = s["cond"][:cut].strip(), s["cond"][cut + 4:].strip()
        new = "%sif (%s) {\n%s  if (%s) { %s }\n%s}" % (s["indent"], outer, s["indent"], inner,
                                                       s["body"].strip(), s["indent"])
        yield "guard:expand", text[:s["start"]] + new + text[s["end"]:]


def t_lineloop(text: str):
    """`for (A; B; C) { D }` -> `A; while (B) { D; C; }` when A and C are single simple clauses. The two forms compile
    to different loop shapes (pre-test placement and where the increment lands), which is the `loop-kind` class."""
    for m in re.finditer(r"(?m)^([ \t]*)for\s*\(", text):
        indent, p = m.group(1), m.end() - 1
        ce = match(text, p, "(", ")")
        if ce < 0:
            continue
        parts = text[p + 1:ce - 1].split(";")
        if len(parts) != 3:
            continue
        init, cond, incr = (x.strip() for x in parts)
        j = ce
        while j < len(text) and text[j] in " \t\r\n":
            j += 1
        if j >= len(text) or text[j] != "{":
            continue
        bend = match(text, j)
        if bend < 0:
            continue
        body = text[j + 1:bend - 1].strip()
        new = "%s%s;\n%swhile (%s) { %s; %s; }" % (indent, init, indent, cond or "1", body, incr)
        if not init:
            new = "%swhile (%s) { %s; %s; }" % (indent, cond or "1", body, incr)
        yield "loop:for-to-while", text[:m.start()] + new + text[bend:]


def _is_tail(text: str, end: int) -> bool:
    """True when only a `return;` and closing braces follow `end` — i.e. the block is the function's last act."""
    rest = text[end:].strip()
    return bool(re.fullmatch(r"(return\s*;)?\s*\}*\s*", rest))


def t_guard_early(text: str):
    """The class the census says is biggest (551 bodies): a WRAPPING `if` and an EARLY-RETURN guard are the same
    program with a different number of returns, and Ghidra's drafts are written the first way almost always.

        if (c) { A }            ->   if (!c) { return; } A          (guard:early+)
        if (c) { return; } A    ->   if (!c) { A }                   (guard:early-)

    Both are semantics-preserving at a function's tail, which is why the tail test is explicit rather than assumed.
    """
    for s in if_sites(text):
        if s["else"]:
            continue
        at_tail = _is_tail(text, s["end"])
        body = s["body"].strip()
        if at_tail and not re.match(r"^return\s*;", body):
            new = "%sif (%s) { return; }%s%s" % (s["indent"], negate(s["cond"]), "\n" if body else "", body)
            if body:
                new = "%sif (%s) { return; }\n%s%s" % (s["indent"], negate(s["cond"]), s["indent"], body)
            yield "guard:early+", text[:s["start"]] + new + text[s["end"]:]
        m = re.match(r"^return\s*;\s*(.*)$", body, re.S)
        if m and m.group(1).strip():
            new = "%sif (%s) { %s }" % (s["indent"], negate(s["cond"]), m.group(1).strip())
            yield "guard:early-", text[:s["start"]] + new + text[s["end"]:]


TEMPLATES = [t_guard_early, t_collapse, t_expand, t_swap, t_lineloop]
BY_CLASS = {
    "early-return": [t_guard_early, t_swap, t_collapse, t_expand],
    "guard-shape": [t_guard_early, t_collapse, t_expand, t_swap],
    "loop-kind": [t_lineloop],
    "loop-count": [t_lineloop],
    "nesting": [t_collapse, t_expand],
    "extra-loop": [t_lineloop],
    "missing-loop": [t_lineloop],
    "dispatch": [],
    "none": [t_guard_early, t_collapse, t_expand, t_swap, t_lineloop],
}


def variants(text: str, cls: str):
    """[(label, whole_body_text)] for the templates this difference class can act on, deduped, capped."""
    out, seen = [], {text}
    for fn in BY_CLASS.get(cls, TEMPLATES):
        for label, cand in fn(text):
            if cand in seen:
                continue
            seen.add(cand)
            out.append((label, cand))
            if len(out) >= VARIANT_CAP:
                return out
    return out


# --- scoring: the canonical pin, never a local approximation --------------------------------------------------

def make_scorer():
    be = bank()
    dm_mod = dm
    cp = dm_mod.probe()

    def score(text: str, image: str, addr: int, words: int, syms):
        # `bank_exact.pins` returns `(identical, status)`; the loop wants a record. The status matters as much as the
        # count: `ld refused` bodies (`.rodata` is DISCARDed by the pin's link script) can never be banked, so they
        # must be refusals here rather than low scores.
        matched, status = be.pins(dm_mod, text, image, addr, words, syms)
        return {"matched": matched, "status": status}
    return score, be, cp


def body_for(image: str, addr: int, words: int, source: str):
    """(text, syms) for a body. `body_for` prefers the provider artifact and needs a non-None fallback: passing
    `None` raises `TypeError: unsupported operand type(s) for /: 'PosixPath' and 'NoneType'` on the 59 records whose
    provider draft is absent — a live crash the design review caught before the loop ever ran."""
    be = bank()
    return be.body_for(dm, source, "scalar", image, addr, words)


def skeleton_of(text: str, image: str, addr: int, words: int, syms):
    """Compile `text` and decode ITS skeleton, so the diff is between two word lists and never between two guesses."""
    score, be, cp = make_scorer()
    got = words_of(text, image, addr, words, syms, cp)
    if got is None:
        return None
    blob, base = cp.image_window(image, cp.image_inventory())
    want = [int.from_bytes(blob[addr - base + 4 * i:addr - base + 4 * i + 4], "big") for i in range(words)]
    return want, got


def words_of(text, image, addr, words, syms, cp):
    import subprocess
    import tempfile
    scratch = Path(tempfile.mkdtemp(prefix="sl_", dir=str(cp.WORK)))
    (scratch / "f.c").write_text(text)
    cc1 = cp.TC / "mips-gcc-2.8.1" / "bin" / "cc1"
    gas = cp.AS27 if cp.AS27.exists() else cp.GAS / "mips-linux-gnu-as"
    if subprocess.run([str(cc1), "-quiet"] + dm.CFLAGS + [str(scratch / "f.c"), "-o", str(scratch / "f.s")],
                      capture_output=True).returncode:
        return None
    if subprocess.run([str(gas)] + dm.ASFLAGS + ["-o", str(scratch / "f.o"), str(scratch / "f.s")],
                      capture_output=True).returncode:
        return None
    cp.normalise_object(scratch / "f.o")
    subprocess.run([str(cp.GAS / "mips-linux-gnu-objcopy"), "--set-section-alignment", ".text=4",
                    "--set-section-alignment", ".rodata=8", str(scratch / "f.o"), str(scratch / "f.fix.o")],
                   capture_output=True)
    known = list(syms.items()) if isinstance(syms, dict) else list(syms)
    (scratch / "l.ld").write_text(
        "SECTIONS {\n  . = %#x;\n  .text : { *(.text) }\n  . = 0x90000000;\n  .rodata : { *(.rodata) }\n"
        "  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.comment) *(.pdr) *(.mdebug*) *(.gnu.attributes) "
        "*(.data) *(.bss) *(.sbss) }\n}\n" % addr
        + "__bss_start = 0x80100000; __bss_end = 0x80100000;\n"
        + "".join("%s = 0x%X;\n" % (n, a) for n, a in known + list(dm.image_symbols().items())))
    if subprocess.run([str(cp.GAS / "mips-linux-gnu-ld"), "-T", str(scratch / "l.ld"), "-o",
                       str(scratch / "f.elf"), str(scratch / "f.fix.o")], capture_output=True).returncode:
        return None
    got = cp.text_of(scratch / "f.elf")
    return [int.from_bytes(got[4 * i:4 * i + 4], "big") for i in range(len(got) // 4)]


def run_body(image: str, addr: int, words: int, source: str, rounds: int = 6, dry: bool = False) -> dict:
    """The loop: score, diff the skeletons, propose, keep only strict improvements, repeat."""
    text, syms, problem = body_for(image, addr, words, source)
    if problem:
        return {"image": image, "address": "0x%08x" % addr, "words": words, "identical": 0, "exact": False,
                "trace": [{"round": 0, "template": "-", "status": "refused: " + problem}], "text": None, "syms": {}}
    score, be, cp = make_scorer()
    best = score(text, image, addr, words, syms)
    trace = [{"round": 0, "template": "-", "identical": best.get("matched"), "words": words,
              "class": None, "status": best.get("status")}]
    for rnd in range(1, rounds + 1):
        if best.get("matched") == words:
            break
        pair = skeleton_of(text, image, addr, words, syms)
        if pair is None:
            trace.append({"round": rnd, "template": "-", "status": "refused: body does not compile"})
            break
        want, got = pair
        cls = skeleton.diff(skeleton.signature(want, addr), skeleton.signature(got, addr))
        trace[-1]["class"] = cls
        cands = variants(text, cls)
        if dry:
            trace.append({"round": rnd, "template": "%d candidate(s) for %s" % (len(cands), cls),
                          "identical": best.get("matched"), "words": words})
            break
        winner = None
        for label, cand in cands:
            res = score(cand, image, addr, words, syms)
            if res.get("status") != "linked":
                continue
            if res.get("matched", 0) > best.get("matched", 0):
                winner = (label, cand, res)
                break
        if winner is None:
            trace.append({"round": rnd, "template": "-", "identical": best.get("matched"), "words": words,
                          "class": cls, "status": "stalled"})
            break
        label, text, best = winner
        trace.append({"round": rnd, "template": label, "identical": best.get("matched"), "words": words,
                      "class": cls, "status": "improved"})
    return {"image": image, "address": "0x%08x" % addr, "words": words, "trace": trace,
            "identical": best.get("matched"), "exact": best.get("matched") == words,
            "text": None if dry else text, "syms": syms}


# --- the positive control: break a body whose answer is known, and require the loop to put it back -------------

BREAKERS = {
    # each breaker is the INVERSE of a template, so a failure is unambiguously the template's fault
    "swap": t_swap,          # applying the swap twice returns the original
    "expand": t_expand,
    "collapse": t_collapse,
    "lineloop": t_lineloop,
}


def self_test(limit: int = 6) -> int:
    """Break byte-exact bodies we hold, then require the loop to restore byte-exactness."""
    cases = []
    candidates = []
    for path in sorted(AUTHORED.rglob("*.c")):
        image = path.parent.name
        try:
            addr = int(path.stem, 16)
        except ValueError:
            continue
        candidates.append((image, addr, path))
    score, be, cp = make_scorer()
    tried = restored = 0
    detail = []
    for image, addr, path in candidates:
        if tried >= limit:
            break
        blob, base = cp.image_window(image, cp.image_inventory())
        if blob is None:
            continue
        text = path.read_text(errors="replace")
        # find the extent: the authored body's own words length is not recorded here, so measure by probing upward
        recs = json.loads((ROOT / "fixtures" / "decomp" / "recovered.json").read_text())["functions"]
        match_rec = next((r for r in recs if r["image"] == image and int(r["address"], 16) == addr), None)
        if not match_rec:
            continue
        words, syms = match_rec["words"], match_rec.get("syms") or {}
        base_res = score(text, image, addr, words, syms)
        if base_res.get("matched") != words:
            continue                                   # only a body that IS exact can be a control
        # break it: the first breaker that produces a non-exact variant
        broken = None
        for label, cand in BREAKERS["swap"](text):
            r = score(cand, image, addr, words, syms)
            if r.get("status") == "linked" and r.get("matched", 0) < words:
                broken = (label, cand)
                break
        if broken is None:
            continue
        tried += 1
        # restore: brute-force the template set over rounds, exactly as `run_body` does
        cur_text, cur = broken[1], score(broken[1], image, addr, words, syms)
        labels = []
        for _ in range(6):
            if cur.get("matched") == words:
                break
            pair = skeleton_of(cur_text, image, addr, words, syms)
            cls = skeleton.diff(skeleton.signature(pair[0], addr), skeleton.signature(pair[1], addr)) if pair else "none"
            moved = False
            for lab, cand in variants(cur_text, cls):
                r = score(cand, image, addr, words, syms)
                if r.get("status") == "linked" and r.get("matched", 0) > cur.get("matched", 0):
                    cur_text, cur, moved = cand, r, True
                    labels.append(lab)
                    break
            if not moved:
                break
        ok = cur.get("matched") == words
        restored += 1 if ok else 0
        detail.append("%s:%08x %s -> %d/%d %s" % (image, addr, broken[0], cur.get("matched", 0), words,
                                                   "RESTORED" if ok else "stalled"))
    for d in detail:
        print("  " + d)
    if tried == 0:
        print("  FAIL no control body could be broken — the control is vacuous, which is not a pass")
        return 1
    cases.append(("the loop restores a structurally broken body it knows the answer to",
                  restored >= 2 or (tried == 1 and restored == 1), "%d of %d" % (restored, tried)))
    ok = sum(1 for _n, g, _d in cases if g)
    for n, g, det in cases:
        print("  %s %s (%s)" % ("PASS" if g else "FAIL", n, det))
    print("%d/%d structure-loop case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--at")
    ap.add_argument("--rounds", type=int, default=6)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--band", default="early-return,guard-shape",
                    help="difference classes to run, comma separated (from skeletons.json)")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--max-words", type=int, default=60)
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.check:
        if not FIXTURE.exists():
            print("FAIL no fixture at %s — run --write" % FIXTURE)
            return 1
        doc = json.loads(FIXTURE.read_text())
        derived = summarise(doc["runs"])
        same = derived == doc["summary"]
        print("  %s summary is derived from the runs" % ("PASS" if same else "FAIL"))
        print("%d/%d structure-loop case(s)" % (1 if same else 0, 1))
        return 0 if same else 1
    if a.write:
        return run_band(a)
    if not a.at:
        ap.print_help()
        return 2
    image, _, hexa = a.at.partition(":")
    addr = int(hexa, 16)
    rec = next((t for t in dm.functions_to_measure([image]) if t[1] == addr), None)
    if rec is None:
        print("no such body: %s" % a.at)
        return 2
    res = run_body(image, addr, rec[2], rec[4], rounds=a.rounds, dry=a.dry_run)
    for step in res["trace"]:
        print("  round %d  %-18s %s/%s  %s" % (step["round"], step.get("template", "-"),
                                               step.get("identical"), step.get("words"),
                                               step.get("status") or ""))
    print("%s %d of %d" % ("EXACT" if res["exact"] else "not exact", res["identical"], res["words"]))
    return 0


def run_band(a) -> int:
    """Run the loop over the addressable class and write the trace fixture — the rate, not an anecdote."""
    census = ROOT / "fixtures" / "decomp" / "skeletons.json"
    if not census.exists():
        print("no census at %s — run skeleton_census.py --write" % census, file=sys.stderr)
        return 2
    want = tuple(x.strip() for x in a.band.split(",") if x.strip())
    recs = json.loads(census.read_text())["records"]
    keys = [k for k, v in recs.items()
            if v["class"] in want and v["gap"] > 4 and v["words"] <= a.max_words]
    keys.sort(key=lambda k: (recs[k]["gap"], recs[k]["words"], k))
    if a.limit:
        keys = keys[:a.limit]
    print("running %d bodies from classes %s (gap>4, <=%d words)" % (len(keys), ",".join(want), a.max_words),
          file=sys.stderr)
    bykey = {"%s:%08x" % (t[0], t[1]): t for t in dm.functions_to_measure(None)}
    runs = {}
    for i, key in enumerate(keys, 1):
        t = bykey.get(key)
        if t is None:
            continue
        res = run_body(t[0], t[1], t[2], t[4], rounds=a.rounds)
        runs[key] = {k: res[k] for k in ("words", "identical", "exact", "trace")}
        if i % 10 == 0:
            print("  %d/%d ..." % (i, len(keys)), file=sys.stderr)
    doc = {"tool": "structure_loop.py",
           "note": ("One run per body over the census's addressable class. `trace` is the round-by-round record: the "
                    "skeleton difference class the round acted on, the template that won, and the identical-word count "
                    "before and after. `exact` is only set when `bank_exact.pins` reached the full word count; nothing "
                    "was banked by this fixture."),
           "band": list(want), "summary": summarise(runs), "runs": dict(sorted(runs.items()))}
    FIXTURE.parent.mkdir(parents=True, exist_ok=True)
    FIXTURE.write_text(json.dumps(doc, indent=1) + "\n")
    s = doc["summary"]
    print("%d bodies: %d exact, %d improved, %d stalled/refused"
          % (s["bodies"], s["closed"], s["improved"], s["refused"]))
    return 0


def summarise(runs):
    """Closure and improvement counts. `improved` means the loop moved the body at all, which is a different and much
    larger claim than `closed` — the two are never added together."""
    closed = sum(1 for r in runs.values() if r.get("exact"))
    moved = sum(1 for r in runs.values()
                if not r.get("exact") and any(s.get("status") == "improved" for s in r.get("trace") or []))
    return {"bodies": len(runs), "closed": closed, "improved": moved,
            "refused": len(runs) - closed - moved}


if __name__ == "__main__":
    sys.exit(main())
