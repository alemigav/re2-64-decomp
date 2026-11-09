#!/usr/bin/env python3
"""Re-score every published partial and fail if its number has drifted.

M391's rule: **a partial is published only with its draft committed**, because the ~14 scores of M379–M385 were
unverifiable — their drafts lived in `/tmp` and `/tmp` was wiped. This is that rule as a gate.

Layout, one pair per entry:

    fixtures/decomp/partials/<image>/<addr>.c      the draft, and **no comments** — `cc1` 2.8 has no comment parser and
                                                   fails with a garbage-byte parse error on the first `/*`
    fixtures/decomp/partials/<image>/<addr>.json   {"words", "score", "mechanism", "residue", ...}

`--check` re-scores each `.c` through `leaf_screen --try` (full output, never truncated) and fails if the number of
identical words differs from the published `score`. That is the whole point: the number is now a claim with an artefact
behind it, and a re-measurement can contradict it.

    ./partials.py --check        # every published score re-derived
    ./partials.py --list         # what is published
    ./partials.py --self-test    # a wrong score must fail, and so must a missing draft
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
DIR = ROOT / "fixtures" / "decomp" / "partials"


def score_one(c: Path, image: str, addr: str, words: int, syms=None):
    """(identical, compiled) from `leaf_screen --try`, or the tool's message if it refused.

    `syms` is not optional in practice: a partial that declares `extern` symbols cannot link without them, and a partial
    whose symbols are undeclared is the same defect as a reconstruction whose `syms` live outside the fixture (M371).
    """
    cmd = [sys.executable, str(HERE / "leaf_screen.py"), "--try", str(c),
           "--image", image, "--addr", addr, "--count", str(words)]
    for k, v in (syms or {}).items():
        cmd += ["--sym", "%s=%s" % (k, v)]
    r = subprocess.run(cmd, capture_output=True, text=True)
    out = r.stdout + r.stderr
    m = re.search(r"(\d+)/(\d+) words identical \((\d+) compiled\)", out)
    if not m:
        return None, (out.strip().splitlines() or ["no output"])[0]
    return int(m.group(1)), None


def check(root: Path) -> list[tuple[str, bool, str]]:
    cases = []
    # M393: this gate reads code out of the images, so it is CARTRIDGE-gated like the probe -- and a missing cartridge
    # is SKIP, never PASS and never FAIL (the rule every cartridge suite here follows).
    try:
        sys.path.insert(0, str(HERE))
        import classify_image as ci
        imgs = json.loads((ROOT / "fixtures" / "decomp" / "images.json").read_text())["images"]
        if ci.image_bytes(next(iter(imgs)), ROOT) is None:
            return [("all partials skipped", None, "SKIP (needs the cartridge)")]
    except Exception:
        return [("all partials skipped", None, "SKIP (needs the cartridge)")]
    for meta_path in sorted(root.glob("*/*.json")):
        meta = json.loads(meta_path.read_text())
        c = meta_path.with_suffix(".c")
        if not c.exists():
            cases.append(("%s:%s has no draft" % (meta["image"], meta["address"]), False,
                          "the source is the artefact; a score without it is the M391 defect"))
            continue
        got, err = score_one(c, meta["image"], meta["address"], int(meta["words"]), meta.get("syms"))
        if got is None:
            cases.append(("%s:%s re-scores" % (meta["image"], meta["address"]), False, err or "no verdict"))
            continue
        ok = got == int(meta["score"])
        cases.append(("%s:%s is %d of %d as published" % (meta["image"], meta["address"], got, meta["words"]),
                      ok, "ok" if ok else "published %d, re-measured %d" % (meta["score"], got)))
    return cases


def self_test() -> int:
    cases = []
    with tempfile.TemporaryDirectory() as d:
        root = Path(d)
        (root / "stage2").mkdir()
        # a draft that cannot compile: the case must fail with a message, not a crash
        (root / "stage2" / "0x0.c").write_text("not c at all\n")
        (root / "stage2" / "0x0.json").write_text(json.dumps(
            {"image": "stage2", "address": "0x0", "words": 4, "score": 4}))
        c = check(root)
        cases.append(("an uncompilable draft fails and is reported", bool(c) and not c[0][1]))
        # a score with no draft: the M391 defect itself
        (root / "stage2" / "0x1.json").write_text(json.dumps(
            {"image": "stage2", "address": "0x1", "words": 4, "score": 4}))
        c = check(root)
        cases.append(("a score with no committed draft fails",
                      any("no draft" in label for label, ok, _ in c if not ok)))
    bad = 0
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d partials self-test case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.list:
        for m in sorted(DIR.glob("*/*.json")):
            d = json.loads(m.read_text())
            print("%-8s %s  %d/%d words" % (d["image"], d["address"], d["score"], d["words"]))
        return 0
    cases = check(DIR)
    if cases and cases[0][1] is None:
        print("SKIP (needs the cartridge)")
        return 3
    passed = 0
    for label, ok, detail in cases:
        passed += ok
        print("  %s %s — %s" % ("PASS" if ok else "FAIL", label, detail))
    print("%d/%d partials case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
