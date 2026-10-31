#!/usr/bin/env python3
"""Distil the Ghidra decompile indices into the address metadata the analyses actually use.

`build/decomp/<image>/decompile-index.json` is 9.5 MB across 36 images, almost none of which is addresses:
each function entry also carries a `relative_path`, a `sha256`, a `limitations` list and `status` prose. The
analyses only ever read `body.ranges` — the function start/end pairs.

M129 put the *synthetic* corpus in CI. The real acceptance checks need two things a runner does not have:

  * **stage2's bytes** (1.17 MB of cartridge code) — cartridge content, and this project does not commit ROM
    bytes, so CI can only get them from an owner-provided secret;
  * **exact region boundaries** — measured, not assumed: with the prologue heuristic in place of the index,
    acceptance test 1b fails and revives the M117 artifact (`a0 = ret(80001180)` instead of `unk`).

The boundary half is pure address metadata — the same class of fact `src/INDEX.md` already publishes — so it
is distilled to `fixtures/decomp/ranges.json` (~100 KB) and committed. That way a runner that *is* given the
cartridge needs nothing else, and drift between the fixture and `build/decomp` is detectable.

Usage:
  ./export_ranges.py                 # write fixtures/decomp/ranges.json from build/decomp
  ./export_ranges.py --check         # verify the fixture still matches build/decomp (exit 1 on drift)
"""
import argparse
import json
import sys
from pathlib import Path

DECOMP = Path("build/decomp")
OUT = Path("fixtures/decomp/ranges.json")


def collect():
    images = {}
    for path in sorted(DECOMP.glob("*/decompile-index.json")):
        name = path.parent.name
        ranges = []
        for fn in json.loads(path.read_text()).get("functions", []):
            for r in (fn.get("body") or {}).get("ranges") or []:
                ranges.append([int(r["start"], 16), int(r["end"], 16)])
        images[name] = sorted(ranges)
    return images


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="compare against the committed fixture")
    args = ap.parse_args()

    if not DECOMP.exists():
        print("%s not present — nothing to distil (this is expected on a fresh clone)" % DECOMP)
        return 0 if args.check else 1

    got = collect()
    if args.check:
        if not OUT.exists():
            print("FAIL %s is missing" % OUT)
            return 1
        want = json.loads(OUT.read_text())["images"]
        if {k: [list(r) for r in v] for k, v in want.items()} != got:
            drift = [k for k in set(want) | set(got) if want.get(k) != got.get(k)]
            print("FAIL fixture differs from build/decomp for: %s" % ", ".join(sorted(drift)[:6]))
            return 1
        print("PASS fixtures/decomp/ranges.json matches build/decomp (%d images, %d ranges)"
              % (len(got), sum(len(v) for v in got.values())))
        return 0

    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps({"note": "address metadata distilled from build/decomp/*/decompile-index.json; "
                                       "regenerate with tools/export_ranges.py",
                               "images": got}, indent=0, sort_keys=True) + "\n")
    print("wrote %s: %d images, %d ranges, %d bytes" % (
        OUT, len(got), sum(len(v) for v in got.values()), OUT.stat().st_size))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
