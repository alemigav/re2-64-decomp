#!/usr/bin/env python3
"""The recovered-function fixture: extents we have measured and proved, for the two exporters to agree on.

`fixtures/decomp/recovered.json` lists the functions this project reconstructed and pinned with a compile-probe
case. The provider's boundaries are wrong for most of them -- its body covers only the dispatch head, with the
arms as separate entries -- so the fixture carries the extent measured against the image plus the probe that
proves the reconstruction.

M289: this module is the single reader, because **two** projections have to agree about where a recovered
function ends (`export_src.py` publishes `src/` and the code index, `export_ranges.py` publishes the committed
range fixture that CI recomputes coverage from). A second, hand-kept copy of these numbers is exactly the drift
M205 and M210 were about.

Usage:
  import recovered
  per_image = recovered.load()          # image name -> [entry], ints in `start`/`end`, inclusive
  text = recovered.source(entry)        # the reconstruction, from tools/compile_probe.py
"""
import importlib.util
import json
from pathlib import Path

FIXTURE = Path("fixtures/decomp/recovered.json")


def load(fixture: Path = FIXTURE) -> dict:
    """image -> [{address, start, end, words, verdict, probe, source}] with ints, sorted by address."""
    if not fixture.exists():
        return {}
    doc = json.loads(fixture.read_text())
    out = {}
    for e in doc.get("functions", []):
        start = int(e["address"], 16)
        item = dict(e)
        item["start"] = start
        item["end"] = start + int(e["words"]) * 4 - 1          # inclusive, the convention of ranges.json
        item["words"] = int(e["words"])
        out.setdefault(e["image"], []).append(item)
    for v in out.values():
        v.sort(key=lambda x: x["start"])
    return out


MEASURED = Path("fixtures/decomp/measured_extents.json")


def load_measured(fixture: Path = MEASURED) -> dict:
    """image -> address -> {start, end, words, evidence} for extents measured from the bytes (M340).

    The third input to the projections, after the provider's ranges and the recovered reconstructions. It exists
    because a function can have a *measured extent* and no reconstruction at all: the 46-word DSP family is
    hand-written assembly, so there is no C to pin, but the provider's range stops at the head because the body
    has no `jr ra` where it expected one -- the census was calling a 96-caller function a three-word stub.

    Adopted by `export_src.py` (status `extent-measured`, extent in the header), by `counts._corpus()` (coverage
    union) and by `classify_image.py` (function_body). One reader, three projections -- M289's rule.
    """
    if not fixture.exists():
        return {}
    out = {}
    for c in json.loads(fixture.read_text()).get("corrections", []):
        start = int(c["address"], 16)
        out.setdefault(c["image"], {})[start] = {
            "start": start, "end": start + int(c["words"]) * 4 - 1,
            "census_words": int(c["census_words"]), "words": int(c["words"]),
            "evidence": c.get("evidence", "")}
    return out


def source(entry: dict) -> str:
    """The reconstruction text for one entry, from the compile-probe corpus (its single source of truth)."""
    path = Path("tools/compile_probe.py")
    spec = importlib.util.spec_from_file_location("_cp_recovered", path)
    cp = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cp)
    return getattr(cp, entry["source"]).rstrip("\n") + "\n"
