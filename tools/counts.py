#!/usr/bin/env python3
"""Derive the suite/case counts from the registry, and assert every place the docs quote them.

Six numbers describe the gate suite — total suites, total cases, the runnable pair and the
cartridge-gated pair — plus the audit suite's own case count, which is the seventh and the one that
actually drifted (26 → 30 → 35 → 37 across three milestones). They are quoted in four files, in eight
different phrasings. Until now each milestone re-derived them by hand and edited every site, which cost
three propagation errors in one arc: `273` left in the README after the suite grew, `129` written where
the gated total was `133`, and `177` where the runnable tier was `178`.

So they are derived once, here, from `tools/acceptance.py` — the same list `acceptance.py` runs — and
every quoting site is checked against them.

The subtlety that makes this more than a grep: **a phrase that disappears must fail.** A gate that only
compares numbers passes silently when the line it was checking is deleted, which is this project's
signature defect in its purest form. Every check therefore requires its pattern to be present exactly
the expected number of times, and a missing phrase is a failure, not a skip.

  ./counts.py --check        # every quoting site agrees with the registry
  ./counts.py --derive       # just print the seven numbers
  ./counts.py --self-test    # a wrong number fails, and a deleted phrase fails
"""
import argparse
import json
import re
import shutil
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# (file, pattern, the derived numbers its groups must equal, expected occurrences)
CHECKS = [
    ("README.md", r"\*\*(\d+)-case verification suite\*\*", ("total_cases",), 1),
    ("README.md", r"# (\d+) suites / (\d+) of (\d+) cases run; the other (\d+) suites SKIP",
     ("runnable_suites", "runnable_cases", "total_cases", "gated_suites"), 1),
    ("README.md", r"tools/audit_gates\.py\s+# (\d+)/(\d+)", ("audit_cases",) * 2, 1),
    # The README quotes four more numbers that used to rot silently: the marker count, how much of the
    # milestone record exists, how many notes there are, and how many tools. Each is derived, not typed.
    ("README.md", r"tools/check_markers\.py\s+# (\d+)/(\d+)", ("marker_cases",) * 2, 1),
    ("README.md", r"\*\*(\d+)\*\* numbers, 0-(\d+): \*\*(\d+)\*\* with a row, and \*\*(\d+)\*\* "
                  r"named gaps", ("milestone_total", "milestone_top", "milestone_rows", "gap_count"), 1),
    ("README.md", r"tools/\s+(\d+) analysis and gate scripts", ("tool_count",), 1),
    ("README.md", r"docs/log/\s+(\d+) notes", ("note_count",), 1),
    ("README.md", r"\*\*(\d+) of (\d+) cases cannot run without your dump\*\*",
     ("gated_cases", "total_cases"), 1),
    ("docs/handover.md", r"# (\d+) suites, (\d+) cases", ("total_suites", "total_cases"), 1),
    ("docs/handover.md", r"audit_gates\.py\s+# (\d+)/(\d+):", ("audit_cases",) * 2, 1),
    ("docs/handover.md", r"\*\*(\d+) of (\d+) cases\*\*\. Their enforcement",
     ("gated_cases", "total_cases"), 1),
    ("docs/handover.md", r"vouch for those (\d+) cases", ("gated_cases",), 1),
    ("tools/ci.sh", r"# (\d+) suites, (\d+) of (\d+) cases\)",
     ("total_suites", "runnable_cases", "total_cases"), 1),
    (".github/workflows/acceptance.yml", r"#   (\d+) suites / (\d+) cases  PASS",
     ("runnable_suites", "runnable_cases"), 1),
    (".github/workflows/acceptance.yml", r"#   (\d+) suites / (\d+) cases  SKIP",
     ("gated_suites", "gated_cases"), 1),
    (".github/workflows/acceptance.yml", r"all (\d+) suites / (\d+) cases",
     ("total_suites", "total_cases"), 3),
]

AUDIT_SUITE = "gate audit (mechanisms disabled)"


def derive(root: Path) -> dict:
    """The seven numbers, from the same `SUITES` list that `acceptance.py` executes."""
    path = root / "tools" / "acceptance.py"
    ns = {"__file__": str(path), "__name__": "_acceptance"}
    exec(compile(path.read_text(), str(path), "exec"), ns)
    suites = ns["SUITES"]
    runnable = [s for s in suites if not s[3]]
    gated = [s for s in suites if s[3]]
    audit = next(s for s in suites if s[0] == AUDIT_SUITE)
    logrows = [l for l in (root / "docs" / "reverse_engineering_log.md").read_text().splitlines()
               if re.match(r"^\| M\d+[a-z]? \|", l)]
    nums = {int(re.match(r"^\| M(\d+)", l).group(1)) for l in logrows}
    top = max(nums)
    gaps = json.loads((root / "fixtures" / "milestones" / "gaps.json").read_text())["gaps"]
    return {
        "total_suites": len(suites),
        "total_cases": sum(s[2] for s in suites),
        "runnable_suites": len(runnable),
        "runnable_cases": sum(s[2] for s in runnable),
        "gated_suites": len(gated),
        "gated_cases": sum(s[2] for s in gated),
        "audit_cases": audit[2],
        "marker_cases": next(e for n, _c, e, _r in suites if n == "doc markers (repository)"),
        "milestone_top": top,
        "milestone_total": top + 1,
        "milestone_rows": len(nums),
        "gap_count": len(gaps),
        "note_count": len(list((root / "docs" / "log").glob("M*.md"))),
        "tool_count": len([p for p in (root / "tools").iterdir()
                           if p.suffix in (".py", ".sh", ".c", ".swift")]),
    }


def check(root: Path, quiet: bool = False):
    """[(label, ok, detail)] — one case per quoting site, with absence counted as failure."""
    vals = derive(root)
    cases = []
    for fname, pattern, keys, want_n in CHECKS:
        path = root / fname
        if not path.exists():
            cases.append((f"{fname}: {pattern[:40]}", False, "file missing"))
            continue
        ms = list(re.finditer(pattern, path.read_text()))
        label = f"{fname}: {keys[0]}" + (f" ... {keys[-1]}" if len(keys) > 1 else "")
        if len(ms) != want_n:
            cases.append((label, False,
                          f"phrase found {len(ms)}x, expected {want_n} — a deleted phrase is a failure"))
            continue
        bad = []
        for m in ms:
            got = [int(g) for g in m.groups()]
            want = [vals[k] for k in keys]
            if got != want:
                bad.append(f"{got} != {want}")
        cases.append((label, not bad, "; ".join(bad) if bad else f"{[vals[k] for k in keys]} ok"))
    if not quiet:
        passed = 0
        for label, ok, detail in cases:
            passed += ok
            print(f"  {'PASS' if ok else 'FAIL'} {label} — {detail}")
        print(f"{passed}/{len(cases)} counts case(s)")
    return cases


def self_test() -> int:
    """A wrong digit must fail, and so must a deleted phrase — on a copy of the real files, so the
    self-test cannot drift from the phrasings it is meant to protect."""
    tmp = Path(tempfile.mkdtemp())
    files = sorted({f for f, *_ in CHECKS})
    cases = []
    try:
        # The synthetic root must contain everything `derive()` reads, not just the quoting sites: the
        # milestone log, the gaps fixture, the note directory and the tool directory. Missing them made this
        # self-test raise FileNotFoundError, which is the audit-environment gap again — inside the tool that
        # exists to catch it.
        for d in ("tools", "docs/log"):
            shutil.copytree(ROOT / d, tmp / d)
        (tmp / "fixtures" / "milestones").mkdir(parents=True, exist_ok=True)
        shutil.copy2(ROOT / "fixtures" / "milestones" / "gaps.json",
                     tmp / "fixtures" / "milestones" / "gaps.json")
        for f in files + ["docs/reverse_engineering_log.md"]:
            (tmp / f).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / f, tmp / f)

        cases.append(("an untouched copy agrees with the registry", not any(not c[1] for c in check(tmp, quiet=True))))

        vals = derive(tmp)
        readme = tmp / "README.md"
        original = readme.read_text()
        readme.write_text(original.replace(f"**{vals['total_cases']}-case",
                                           f"**{vals['total_cases'] + 1}-case", 1))
        cases.append(("a wrong total in the README is caught", any(not c[1] for c in check(tmp, quiet=True))))

        readme.write_text(original)
        handover = tmp / "docs" / "handover.md"
        ho = handover.read_text()
        handover.write_text(re.sub(r"vouch for those \d+ cases", "vouch for those cases", ho))
        cases.append(("a phrase that disappears is caught", any(not c[1] for c in check(tmp, quiet=True))))

        handover.write_text(ho)
        workflow = tmp / ".github" / "workflows" / "acceptance.yml"
        wf = workflow.read_text()
        workflow.write_text(wf.replace("all {0} suites / {1} cases".format(vals["total_suites"], vals["total_cases"]),
                                       "all {0} suites / {1} cases".format(vals["total_suites"], vals["total_cases"] + 5), 1))
        cases.append(("one wrong among three identical phrases is caught",
                      any(not c[1] for c in check(tmp, quiet=True))))
    finally:
        shutil.rmtree(tmp)

    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} counts self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--derive", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    if args.derive:
        for k, v in derive(ROOT).items():
            print(f"{k}: {v}")
        return 0
    cases = check(ROOT)
    return 0 if all(ok for _, ok, _ in cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
