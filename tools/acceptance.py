#!/usr/bin/env python3
"""Run every suite in this repository and report one verdict.

Each tool owns its own fixture, which means five places to remember. This runs them all, checks the
**expected case count** (so a fixture that quietly loses cases fails), and exits non-zero on any failure.
Nothing here re-implements a check: it only invokes, parses and aggregates.

Suites:
  tools/provenance.py --self-test     the intra-procedural provenance fixture
  tools/provenance.py --self-test2    the interprocedural / summary / path fixture
  tools/provenance.py --acceptance    the two pre-registered experiment-B acceptance tests
  tools/pad_layout.py --self-test     the SI command-block / CHNL_ERR fixture
  tools/test_harness.py               the MIPS execution fixture (the verified CPU path)

Usage:
  ./acceptance.py            # all suites
  ./acceptance.py -v         # show each suite's own output
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

SUITES = [
    ("provenance self-test", [sys.executable, "tools/provenance.py", "--self-test"], 10),
    ("provenance self-test2", [sys.executable, "tools/provenance.py", "--self-test2"], 12),
    ("provenance acceptance", [sys.executable, "tools/provenance.py", "--acceptance"], 3),
    ("pad_layout self-test", [sys.executable, "tools/pad_layout.py", "--self-test"], 8),
    ("mips harness", [sys.executable, "tools/test_harness.py"], 15),
]

COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")


def run(cmd):
    proc = subprocess.run(cmd, cwd=str(HERE.parent), capture_output=True, text=True)
    return proc.returncode, proc.stdout + proc.stderr, proc.stdout.splitlines()


def tally(lines):
    """The last `N/M` line in a suite's output is its verdict."""
    for line in reversed(lines):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()

    failures = []
    print("%-24s %-10s %s" % ("suite", "cases", "verdict"))
    for name, cmd, expected in SUITES:
        code, text, lines = run(cmd)
        got = tally(lines)
        if got is None:
            print("%-24s %-10s FAIL (no N/M verdict; exit %d)" % (name, "-", code))
            failures.append((name, "no verdict, exit %d" % code))
            if args.verbose:
                print(text)
            continue
        passed, total = got
        ok = code == 0 and passed == total
        note = "" if total == expected else "  EXPECTED %d CASES, found %d" % (expected, total)
        if total != expected:
            ok = False
        print("%-24s %-10s %s%s" % (name, "%d/%d" % (passed, total), "PASS" if ok else "FAIL", note))
        if not ok:
            failures.append((name, "%d/%d, exit %d" % (passed, total, code)))
        if args.verbose and not ok:
            print(text)

    print()
    if failures:
        for name, why in failures:
            print("FAIL %s: %s" % (name, why))
        return 1
    print("all suites pass (%d cases across %d fixtures)" % (
        sum(e for _, _, e in SUITES), len(SUITES)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
