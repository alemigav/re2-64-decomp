#!/usr/bin/env python3
"""The verifier's entry point. One run, one verdict, and one rule it does not get to reinterpret.

The rule: **a result is only admissible if the gates that produced it have been shown to fail.** In this
repository that is `tools/audit_gates.py` — every check's mechanism is disabled in a throw-away copy and the
check must then fail. If the audit reports any vacuous or broken entry, then whatever else passed did so for
reasons nobody has established, and the verdict is `INCONCLUSIVE` **no matter how green everything else is**.
That is deliberately not a judgement call: it is the first branch of `adjudicate`, and `--self-test` proves
each branch by feeding it synthetic results.

So the verifier does not decide whether an artefact is correct, and it does not invent a procedure. It runs
the procedures the project already maintains, in a fixed order, and reports what they said:

    tools/ci.sh              acceptance (expected case counts), tracked artefacts, cartridge digest
    tools/ratchet.py         the registry has not drifted and src/ has not moved, silently
    tools/counts.py          the seven numbers quoted in four files still agree with the registry
    tools/audit_gates.py     every gate still fails when its own mechanism is disabled  <- admission

The first three are *evidence*. The fourth is *admissibility*, and it runs last so that it is graded against
the tree as it actually is at the end of the run.

  ./verify.py               # human-readable report
  ./verify.py --json        # the same, machine-readable, for the primary agent to read
  ./verify.py --self-test   # prove each branch of the verdict, including the inadmissible one
"""
import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CARTRIDGE = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
REPORT = ROOT / "build" / "verify-report.json"

PROCEDURES = [
    ("ci", ["sh", "tools/ci.sh"], "acceptance, artefact scan and cartridge digest"),
    ("ratchet", [sys.executable, "tools/ratchet.py", "--check"], "registry drift and src/ freeze"),
    ("counts", [sys.executable, "tools/counts.py", "--check"], "documented numbers vs the registry"),
]
ADMISSION = ("audit", [sys.executable, "tools/audit_gates.py"], "every gate must fail when disabled")

COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")
AUDIT = re.compile(r"(\d+)/(\d+) audit case\(s\);\s*(\d+) vacuous,\s*(\d+) broken")
SKIP = re.compile(r"Skipped for want of the cartridge|SKIP \(needs the cartridge\)")
# `ci.sh` ends with the artefact scan's own `5/5`, which is not what it covers. Its coverage is the
# acceptance summary, so that is what the report quotes for it — the verifier's report must not be the
# one place in this repository where a number means something other than what it says.
CI_SUMMARY = re.compile(r"all (\d+) runnable suite\(s\) pass \((\d+) cases\)")


def run(cmd):
    proc = subprocess.run(cmd, cwd=str(ROOT), capture_output=True, text=True)
    return proc.returncode, proc.stdout + proc.stderr


def verdict_of(text):
    """The last `N/M` line — the same rule `acceptance.py` uses, so a tool cannot pass by printing PASS."""
    for line in reversed(text.splitlines()):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def adjudicate(procedures, audit):
    """-> (verdict, why). Pure, so `--self-test` grades the rule rather than a subprocess.

    `procedures` is [(name, exit_code, (passed, total) or None)], `audit` is (passed, total, vacuous,
    broken) or None. Order matters: admissibility is checked before anything else.
    """
    if audit is None:
        return "INCONCLUSIVE", "the gate audit produced no N/M verdict, so no result can be admitted"
    ap, at, vac, brk = audit
    if vac or brk:
        return "INCONCLUSIVE", (f"the gate audit reports {vac} vacuous and {brk} broken — the checks that "
                                f"produced this evidence have not been shown to fail")
    if at == 0 or ap != at:
        return "INCONCLUSIVE", f"the gate audit itself did not pass ({ap}/{at})"
    failed = [(n, c) for n, c, _ in procedures if c != 0]
    if failed:
        return "FAIL", "procedures failed: " + ", ".join(f"{n} (exit {c})" for n, c in failed)
    partial = [n for n, _, v in procedures if v is not None and v[0] != v[1]]
    if partial:
        return "FAIL", "procedures reported fewer cases than they ran: " + ", ".join(partial)
    return "PASS", f"every procedure passed and the gate audit is {ap}/{at} with nothing vacuous"


def collect():
    results, screens, details = [], {}, {}
    for name, cmd, _why in PROCEDURES:
        code, out = run(cmd)
        m = CI_SUMMARY.search(out)
        if name == "ci" and m:
            suites, cases = int(m.group(1)), int(m.group(2))
            results.append((name, code, (cases, cases)))
            details[name] = f"{suites} suites / {cases} cases"
        else:
            results.append((name, code, verdict_of(out)))
            v = verdict_of(out)
            details[name] = f"{v[0]}/{v[1]}" if v else "-"
        screens[name] = out
    code, out = run(ADMISSION[1])
    m = AUDIT.search(out)
    audit = (int(m.group(1)), int(m.group(2)), int(m.group(3)), int(m.group(4))) if m else None
    results.append((ADMISSION[0], code, verdict_of(out)))
    screens[ADMISSION[0]] = out
    v = verdict_of(out)
    details[ADMISSION[0]] = f"{v[0]}/{v[1]}" if v else "-"
    return results, screens, audit, details


def report(as_json: bool) -> int:
    results, screens, audit, details = collect()
    verdict, why = adjudicate(results, audit)
    have_cart = CARTRIDGE.exists()
    skipped = bool(SKIP.search(screens["ci"]))
    sha = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=str(ROOT),
                         capture_output=True, text=True).stdout.strip()
    dirty = bool(subprocess.run(["git", "status", "--porcelain"], cwd=str(ROOT),
                                capture_output=True, text=True).stdout.strip())
    out = {
        "artifact": {"commit": sha or "(unknown)", "dirty": dirty, "cartridge": have_cart},
        "procedures": [{"name": n, "exit": c, "detail": details[n]} for n, c, _v in results],
        "admission": {"gate_audit": f"{audit[0]}/{audit[1]}" if audit else None,
                      "vacuous": audit[2] if audit else None,
                      "broken": audit[3] if audit else None,
                      "admissible": verdict != "INCONCLUSIVE"},
        "verdict": verdict,
        "why": why,
        "coverage": "partial" if skipped else "full",
        "note": ("cartridge-gated suites SKIPped: any claim that depends on them is INCONCLUSIVE here"
                 if skipped else "all suites ran"),
        "blocks_milestone": verdict != "PASS",
    }
    REPORT.parent.mkdir(parents=True, exist_ok=True)
    REPORT.write_text(json.dumps(out, indent=1) + "\n")
    if as_json:
        print(json.dumps(out, indent=1))
    else:
        print(f"verifier report — {out['artifact']['commit']}"
              f"{' (dirty tree)' if dirty else ''}, cartridge {'present' if have_cart else 'ABSENT'}")
        print(f"  {'procedure':10s} {'covers':>28s}  exit")
        for p in out["procedures"]:
            print(f"  {p['name']:10s} {p['detail']:>28s}  {p['exit']}")
        print(f"  admission  gate audit {out['admission']['gate_audit'] or '-'}, "
              f"{out['admission']['vacuous']} vacuous, {out['admission']['broken']} broken")
        print(f"\nVERDICT {verdict} — {why}")
        print(f"coverage {out['coverage']}: {out['note']}")
        print(f"report written to {REPORT}")
    return 0 if verdict == "PASS" else 1


def self_test() -> int:
    clean = (39, 39, 0, 0)
    allpass = [("a", 0, (10, 10)), ("b", 0, (4, 4))]
    cases = [
        ("a clean audit and every procedure passing is PASS",
         adjudicate(allpass, clean)[0] == "PASS"),
        # the rule the verifier is not allowed to reinterpret: vacuity outranks greenness
        ("one vacuous audit entry makes a fully green run INCONCLUSIVE, not PASS",
         adjudicate(allpass, (39, 39, 1, 0))[0] == "INCONCLUSIVE"),
        ("one broken audit entry is INCONCLUSIVE too", adjudicate(allpass, (39, 39, 0, 1))[0] == "INCONCLUSIVE"),
        ("an audit with no verdict is INCONCLUSIVE", adjudicate(allpass, None)[0] == "INCONCLUSIVE"),
        ("an audit that did not pass is INCONCLUSIVE, not FAIL",
         adjudicate(allpass, (38, 39, 0, 0))[0] == "INCONCLUSIVE"),
        # The exit status must be the *only* defect here — a tally of (2, 3) would also trip the
        # "fewer cases than it ran" branch below, and this case was masked by it until the audit aimed at
        # the `failed` branch and found the case passing with that branch disabled (M181).
        ("a procedure exiting non-zero with a clean tally is FAIL when the audit is clean",
         adjudicate(allpass + [("c", 1, (3, 3))], clean)[0] == "FAIL"),
        ("a procedure reporting fewer cases than it ran is FAIL",
         adjudicate(allpass + [("c", 0, (2, 3))], clean)[0] == "FAIL"),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} verifier self-test case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    return self_test() if args.self_test else report(args.json)


if __name__ == "__main__":
    raise SystemExit(main())
