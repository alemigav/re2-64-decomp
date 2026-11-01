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

CARTRIDGE = Path("rom/Resident Evil 2 (USA) (Rev 1).z64")

# (name, command, expected case count, needs the cartridge). The cartridge is gitignored by design, so a
# fresh clone — and therefore any CI runner — cannot supply it. Suites that need it report SKIP rather than
# PASS or FAIL: pretending they ran would be the same class of error as a fixture that asserts nothing.
SUITES = [
    ("provenance self-test", [sys.executable, "tools/provenance.py", "--self-test"], 10, False),
    ("provenance self-test2", [sys.executable, "tools/provenance.py", "--self-test2"], 12, False),
    ("provenance acceptance", [sys.executable, "tools/provenance.py", "--acceptance"], 3, True),
    ("corpus pipeline (synthetic)", [sys.executable, "tools/provenance.py", "--corpus-self-test"], 6, False),
    ("pad_layout self-test", [sys.executable, "tools/pad_layout.py", "--self-test"], 8, False),
    ("patch_text self-test", [sys.executable, "tools/patch_text.py", "--self-test"], 8, False),
    ("doc markers (synthetic)", [sys.executable, "tools/check_markers.py", "--self-test"], 12, False),
    ("doc markers (repository)", [sys.executable, "tools/check_markers.py"], 21, False),
    ("walk_stream length map", [sys.executable, "tools/walk_stream.py", "--self-test"], 23, False),
    # `rdram_fixture.py` builds its bytes synthetically but walks them with `walk_stream.py`, which loads
    # the stage-2 image from `assets/unpacked/` — an unpacked cartridge member. Green locally, red on any
    # fresh clone, so it is cartridge-dependent in fact even though its input memory is synthetic (M174).
    ("synthetic-rdram walk", [sys.executable, "tools/rdram_fixture.py"], 7, True),
    ("room script (cartridge)", [sys.executable, "tools/room_script.py", "--check"], 4, True),
    ("script profile (cartridge)", [sys.executable, "tools/script_profile.py", "--check"], 5, True),
    ("cfg reachability (cartridge)", [sys.executable, "tools/cfg_reach.py", "--check"], 6, True),
    ("room scripts only (cartridge)", [sys.executable, "tools/cfg_reach.py", "--check-rooms"], 3, True),
    ("01 41 container (cartridge)", [sys.executable, "tools/container_0141.py", "--check"], 29, True),
    ("exception path (cartridge)", [sys.executable, "tools/exception_path.py", "--check"], 8, True),
    ("t64info (C header)", [sys.executable, "tools/t64_selftest.py"], 4, True),
    ("routine index bounds (cartridge)", [sys.executable, "tools/routine_index.py"], 14, True),
    ("gate audit (mechanisms disabled)", [sys.executable, "tools/audit_gates.py"], 44, True),
    # CI cannot test the file that makes CI run: an invalid workflow is never scheduled, so nothing
    # reports it. This suite does — and it needs no cartridge, so a runner checks its own definition (M174).
    ("workflow lint", [sys.executable, "tools/workflow_lint.py"], 14, False),
    # The full tier's guard and the fetch verification are shell, but they are gates: both are tested in
    # both directions, and neither needs a cartridge, so a runner tests them too (M176).
    # The milestone index is generated: --check fails when it drifts from the log, the notes or the gaps.
    ("artefact scan (repository)", [sys.executable, "tools/artefact_scan.py"], 5, False),
    ("artefact scan (synthetic)", [sys.executable, "tools/artefact_scan.py", "--self-test"], 7, False),
    ("milestone index (repository)", [sys.executable, "tools/milestone_index.py", "--check"], 10, False),
    ("milestone index (synthetic)", [sys.executable, "tools/milestone_index.py", "--self-test"], 11, False),
    ("full-tier guard", ["sh", "tools/ci_full.sh", "--self-test"], 3, False),
    ("cartridge fetch", ["sh", "tools/cart_fetch.sh", "--self-test"], 4, False),
    ("mips harness", [sys.executable, "tools/test_harness.py"], 15, False),
    # The file table is the cartridge's whole file system, and it is mostly *not* zlib (M178). One
    # suite because the finding is one object: the census, the two files the 17.6 MB turned out to be,
    # the MORT record format, and the refutations that keep the unsolved field unsolved.
    ("file table (cartridge)", [sys.executable, "tools/file_table.py", "--check"], 43, True),
    # The ratchet guards the registry itself. `--self-test` breaks each invariant on a synthetic root
    # (a lowered count, a deleted suite, an unbaselined addition, an edit to src/) and requires
    # detection; `--check` applies the same two invariants to this repository. Both are needed: without
    # the self-test `--check` passes on a healthy tree whether or not either invariant is wired.
    ("ratchet self-test", [sys.executable, "tools/ratchet.py", "--self-test"], 9, False),
    ("ratchet (repository)", [sys.executable, "tools/ratchet.py", "--check"], 4, False),
    # The counts are derived from this very list, so registering a suite changes them — and this suite
    # is the one that notices the docs no longer agree. It caught its own registration (M180).
    ("counts self-test", [sys.executable, "tools/counts.py", "--self-test"], 4, False),
    ("counts (repository)", [sys.executable, "tools/counts.py", "--check"], 12, False),
    # The verifier's own rule, graded before anyone relies on it: a vacuous audit must force INCONCLUSIVE
    # rather than PASS. The full run is *not* registered here — it invokes `ci.sh`, which runs this list,
    # so registering it would recurse.
    ("verifier self-test", [sys.executable, "tools/verify.py", "--self-test"], 7, False),
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

    have_cart = (HERE.parent / CARTRIDGE).exists()
    print("cartridge: %s" % ("present" if have_cart else
                             "ABSENT — suites that need it will report SKIP"))
    failures, skipped = [], 0
    print("%-24s %-10s %s" % ("suite", "cases", "verdict"))
    for name, cmd, expected, needs_rom in SUITES:
        if needs_rom and not have_cart:
            print("%-24s %-10s %s" % (name, "-", "SKIP (needs the cartridge)"))
            skipped += 1
            continue
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
    ran = [s for s in SUITES if not (s[3] and not have_cart)]
    print("all %d runnable suite(s) pass (%d cases)%s" % (
        len(ran), sum(e for _, _, e, _ in ran),
        "" if not skipped else "; %d skipped for want of the cartridge" % skipped))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
