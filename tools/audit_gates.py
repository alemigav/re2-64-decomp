#!/usr/bin/env python3
"""Audit the gates: disable each check's mechanism and require that the check fails.

Three defects in three milestones (M149's phantom tail, M151's shared node budget, M152/M154's guard order)
had the same shape: a check that could not fail for the right reason. A passing check therefore proves
nothing until it has been shown to fail. This tool does that mechanically.

For each audit it builds a throw-away copy of the tools, fixtures and docs, **mutates one mechanism** in that
copy, runs the same command `acceptance.py` runs, and requires a failure. A check that still passes with its
mechanism disabled is reported as **VACUOUS**, and the tool exits non-zero.

Cartridge-dependent audits get `rom/` and `assets/` **symlinked**, never copied.

  ./audit_gates.py            # run every audit
  ./audit_gates.py --list     # what each audit disables
"""
import argparse
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

AUDITS = [
    # --- walk_stream: the length scan's own mechanisms
    dict(name="walk_stream: cross-register fallback disabled",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         old="        if length is None:\n            length = cross(h)",
         new="        if False:\n            length = cross(h)"),
    dict(name="walk_stream: advance scan returns a constant (vacuous lengths)",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         old="    return sorted(out)\n\n\nDYNAMIC = {",
         new="    return [4]\n\n\nDYNAMIC = {"),
    dict(name="walk_stream: name taken from list order instead of the chosen size",
         tool="walk_stream.py", args=["--self-test"],
         file="tools/walk_stream.py",
         old="            same = [v for v in variants if v[1] == chosen]",
         new="            same = []"),
    # --- the walk itself
    dict(name="walk_stream: unconditional jump is not followed",
         tool="rdram_fixture.py", args=[],
         file="tools/walk_stream.py",
         old="                if not near_conditional(op, sups):",
         new="                if True:"),
    dict(name="walk_stream: GoSub table stride changed 2 -> 64",
         tool="room_script.py", args=["--check"],
         file="tools/walk_stream.py",
         old='RAW_SCRIPT_TABLE = lambda idx: (struct.unpack_from(">H", blob, 2 * idx)[0]',
         new='RAW_SCRIPT_TABLE = lambda idx: (struct.unpack_from(">H", blob, 64 * idx)[0]'),
    # --- reachability
    dict(name="cfg_reach: block pops are ignored",
         tool="cfg_reach.py", args=["--check"],
         file="tools/cfg_reach.py",
         # disable the mechanism, not one branch of it: with only the plain branch muted the generous
         # branch still fires and the check passes, which is how this audit was itself vacuous at first.
         old="POPPERS = {0x10, 0x12, 0x1A}                  # pop a block slot",
         new="POPPERS = set()                              # pop a block slot"),
    dict(name="cfg_reach: reachability returns nothing",
         tool="cfg_reach.py", args=["--check"],
         file="tools/cfg_reach.py",
         old="    positions = set()\n    for start in starts:",
         new="    return set()\n    for start in starts:"),
    dict(name="cfg_reach: the room-script filter is disabled",
         tool="cfg_reach.py", args=["--check-rooms"],
         file="tools/cfg_reach.py",
         old="    only_ids = room_script_ids() if (args.rooms or args.check_rooms) else None",
         new="    only_ids = None"),
    dict(name="container_0141: the unit size is wrong (32 not 16)",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="UNIT = 16",
         new="UNIT = 32"),
    dict(name="container_0141: N forced equal to the distinct-value count",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="        pairs.append((n, len(set(payload))))",
         new="        pairs.append((n, n))"),
    dict(name="container_0141: the GBI opcode window is widened to everything",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old="    gbi = sum(c for b, c in heads.items() if 0xE4 <= b <= 0xFF)",
         new="    gbi = sum(c for b, c in heads.items())"),
    dict(name="container_0141: the ITP loader table is swapped for the TM3 one",
         tool="container_0141.py", args=["--check"],
         file="tools/container_0141.py",
         old='    "ITP": 0x8012BEC0,',
         new='    "ITP": 0x8010DBC0,'),
    # --- the corpus profiler
    dict(name="script_profile: the script heuristic admits nothing",
         tool="script_profile.py", args=["--check"],
         file="tools/script_profile.py",
         old="MIN_COMMANDS = 4",
         new="MIN_COMMANDS = 10**9"),
    # --- the doc gates
    dict(name="check_markers: a handover heading disappears",
         tool="check_markers.py", args=[],
         file="docs/handover.md",
         old="## Immediate next step",
         new="## Immediate next step (renamed by the audit)"),
    # --- the routine-index bounds question: one audit per leg of its answer, so that no single
    # disabled mechanism can leave the answer standing.
    dict(name="routine_index: a table base shifted by one word",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old="CLASS_A = [0x8011AF80,",
         new="CLASS_A = [0x8011AF84,"),
    dict(name="routine_index: every +5 index counted as masked",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old='                       and ((b["w"] >> 6) & 0x1F) == 2)        # sll reg,reg,2',
         new='                       and ((b["w"] >> 6) & 0x1F) == 3)        # sll reg,reg,2'),
    dict(name="routine_index: the out-of-range writer values are dropped",
         tool="routine_index.py", args=[],
         file="tools/routine_index.py",
         old="                out.append((v, p.name, expr))",
         new="                out.append((v, p.name, expr)) if v < ROW else None"),
    dict(name="workflow_lint: the broken-plain-scalar check never fires",
         tool="workflow_lint.py", args=[],
         file="tools/workflow_lint.py",
         old='    if ": " in val:',
         new="    if False:"),
    dict(name="patch_text: a no-op replacement is accepted",
         tool="patch_text.py", args=["--self-test"],
         file="tools/patch_text.py",
         old="        if old == new:",
         new="        if False:"),
]

# things a mutated tool must be able to read; the heavy ones are symlinked
# `.github` is copied rather than linked because the workflow lint reads it — an audit of that lint that
# runs in an environment with no workflows passes for the wrong reason, which is how this list grew (M174).
COPY = ["tools", "fixtures", "docs/log", ".github"]
COPY_FILES = ["docs/handover.md", "docs/reverse_engineering_log.md"]
# `build/elfs` holds the built images and `src/` the decompiled corpus; both are read-only for every
# audit, and a copy is 18 MB per audit for nothing. Not linking them was invisible until an image-
# dependent tool was audited: the mutated copy failed on a missing `images.json`, not on its mutation.
LINK = ["rom", "assets", "build/elfs", "src"]


def build_env(dst: Path) -> None:
    for item in COPY:
        src = ROOT / item
        if src.is_dir():
            shutil.copytree(src, dst / item)
    for item in COPY_FILES:
        src = ROOT / item
        if src.exists():
            (dst / item).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst / item)
    for item in LINK:
        src = ROOT / item
        if src.exists():
            (dst / item).parent.mkdir(parents=True, exist_ok=True)   # build/elfs has no build/ yet
            (dst / item).symlink_to(src)


def run_audit(audit, keep: Path = None) -> tuple:
    """Returns (detected, detail). `detected` is True when the mutated check failed, as it must."""
    tmp = Path(tempfile.mkdtemp(prefix="gate-audit."))
    try:
        build_env(tmp)
        target = tmp / audit["file"]
        text = target.read_text()
        if audit["old"] not in text:
            return None, f"mutation anchor not found in {audit['file']}"
        mutated = text.replace(audit["old"], audit["new"], 1)
        if mutated == text:
            return None, "mutation changed nothing"
        target.write_text(mutated)
        proc = subprocess.run([sys.executable, str(tmp / "tools" / audit["tool"])] + audit["args"],
                              capture_output=True, text=True, cwd=str(tmp))
        out = proc.stdout + proc.stderr
        detected = proc.returncode != 0 or "FAIL" in out
        tail = [l for l in out.splitlines() if "FAIL" in l or "PASS" in l][-1:] or out.splitlines()[-1:]
        return detected, f"exit {proc.returncode}; {tail[0][:90] if tail else ''}"
    finally:
        if keep:
            shutil.move(str(tmp), str(keep))
        else:
            shutil.rmtree(tmp, ignore_errors=True)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true", help="describe each audit and exit")
    args = ap.parse_args()

    if args.list:
        for a in AUDITS:
            print(f"  {a['name']}\n      {a['tool']} {' '.join(a['args'])}  <- mutation in {a['file']}")
        return 0

    passed = 0
    vacuous = []
    broken = []
    for a in AUDITS:
        detected, detail = run_audit(a)
        if detected is None:
            broken.append((a["name"], detail))
            print(f"  BROKEN   {a['name']}: {detail}")
            continue
        if detected:
            passed += 1
            print(f"  PASS     {a['name']}  ({detail})")
        else:
            vacuous.append(a["name"])
            print(f"  VACUOUS  {a['name']}  ({detail}) — the check passed with its mechanism disabled")
    total = len(AUDITS)
    print(f"\n{passed}/{total} audit case(s); {len(vacuous)} vacuous, {len(broken)} broken")
    if vacuous:
        print("VACUOUS checks (they cannot fail for the right reason):")
        for name in vacuous:
            print(f"  - {name}")
    return 0 if passed == total else 1


if __name__ == "__main__":
    raise SystemExit(main())
