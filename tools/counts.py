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

import recovered

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# (file, pattern, the derived numbers its groups must equal, expected occurrences)
CHECKS = [
    ("README.md", r"\*\*(\d+)-case verification suite\*\*", ("total_cases",), 1),
    ("README.md", r"# (\d+) suites / (\d+) of (\d+) cases run; the other (\d+) suites SKIP",
     ("runnable_suites", "runnable_cases", "total_cases", "gated_suites"), 1),
    ("README.md", r"tools/audit_gates\.py\s+# (\d+)/(\d+)", ("audit_cases",) * 2, 1),
    # --- the corpus (M205). The figure this replaced -- 1 212 984 B, "62.3 %" -- was quoted for thirty
    # milestones and never recomputed: `export_src.py` claimed one 4-byte word past every function body, so
    # the union was 2 384 B high. These two sentences are now derived from `fixtures/decomp/` and must agree
    # with the tool, which is the only thing that makes a headline number a claim rather than a habit.
    ("README.md",
     r"\*\*([\d\s,]+?)\s+functions\*\*\s+over\s+\*\*([\d\s,]+?)\*\*\s+ranges,\s+\*\*(\d+)\.(\d)\s+%\*\*\s+of\s+the\s+\*\*([\d\s,]+?)\*\*\s+image\s+bytes\s+inside\s+a\s+known\s+body\s+\(\*\*([\d\s,]+?)\s+B\*\*\)",
     ("functions", "ranges", "coverage_whole", "coverage_dec", "image_bytes", "covered_bytes"), 1),
    ("README.md",
     r"of\s+\*\*([\d\s,]+?)\s+functions\*\*,\s+\*\*([\d\s,]+?)\*\*\s+resolve\s+every\s+call\s+"
     r"target(?:\s+in\s+their\s+bodies)?,\s+"
     r"\*\*([\d\s,]+?)\*\*\s+carry\s+a\s+curated\s+name,\s+and\s+\*\*([\d\s,]+?)\*\*\s+have\s+behaviour\s+pinned",
     ("functions", "status_f2", "status_named", "status_validated"), 1),
    # M210: the published length count was 15 while the artifact measured 17, and nothing compared them.
    ("README.md", r"\*\*(\d+) distinct instruction lengths\*\*", ("distinct_lengths",), 1),
    ("docs/handover.md", r"\*\*(\d+) distinct(?: instruction)? lengths\*\*", ("distinct_lengths",), 2),
    ("docs/handover.md",
     r"\*\*([\d\s,]+?)\s+functions\*\*\s+over\s+\*\*([\d\s,]+?)\*\*\s+ranges,\s+\*\*(\d+)\.(\d)\s+%\*\*\s+of\s+the\s+\*\*([\d\s,]+?)\*\*\s+image\s+bytes\s+inside\s+a\s+known\s+body\s+\(\*\*([\d\s,]+?)\s+B\*\*\)",
     ("functions", "ranges", "coverage_whole", "coverage_dec", "image_bytes", "covered_bytes"), 2),
    # The README quotes four more numbers that used to rot silently: the marker count, how much of the
    # milestone record exists, how many notes there are, and how many tools. Each is derived, not typed.
    ("README.md", r"tools/check_markers\.py\s+# (\d+)/(\d+)", ("marker_cases",) * 2, 1),
    ("README.md", r"\*\*(\d+)\*\* numbers, 0-(\d+): \*\*(\d+)\*\* with a row, and \*\*(\d+)\*\* "
                  r"named gaps", ("milestone_total", "milestone_top", "milestone_rows", "gap_count"), 1),
    # M335: the project's headline pair. It was quoted twice and asserted nowhere, so it could sit a
    # milestone behind the corpus (130/129 against 147/146) and no gate noticed. A number that is the point of
    # the repository gets a case.
    ("README.md", r"\*\*(\d+) functions reconstructed in C and recompiled \u2014 (\d+) of them matching",
     ("recovered", "recovered_exact"), 1),
    # M409: the distance map's line. "Already byte-exact" and "nobody had noticed" are the two sentences a reader
    # needs to judge the remaining work, and both are derived from the fixture, never typed.
    # The sentence leads with the BANKED count, not with the map's `exact`: the map measures the provider artifact
    # where one exists and `src/` otherwise, so its exact total mixes provenances. `banked_exact` comes from the
    # fixture and means one thing.
    ("README.md", r"\*\*(\d+) bodies of the decompiler's own C were already byte-exact and unclaimed\*\* — M410 and "
                  r"M411 banked them — and \*\*(\d+) more are within eight words",
     ("banked_exact", "distance_within_8"), 1),
    # M389: the front page's pictures. A generated block is not a licence to stop asserting -- the waffle's legend and
    # its headline are the two sentences a newcomer reads first, so they get cases like every other number on the page.
    ("README.md", r"\u2588 (\d+)\*\* reconstructed and byte-exact, \*\*\u2592 (\d+)\*\* a body the bytes give but "
                  r"nobody has written, \*\*\u2591 ([\d\s,]+?)\*\* the decompiler's pseudocode",
     # the legend says "reconstructed AND byte-exact", so the waffle's first number is the exact count, not the
     # total: M410 made those two different numbers (460 of 461) and the page must print the one its words describe.
     ("recovered_exact", "status_extent_measured", "status_pseudocode"), 1),
    ("README.md", r"the remaining ([\d\s,]+?) would take about \*\*(\d+) more milestones\*\*",
     ("status_remaining", "front_milestones_left"), 1),
    # M366: three front-page claims that had rotted silently -- the shape census, and the two split counts in the
    # "verify it without the cartridge" table. A third party found them by reading; a regex is cheaper than a reader.
    ("README.md", r"(\d+) of them are copies of (\d+) proven body shapes",
     ("cohort_copies", "cohort_shapes"), 1),
    # M373: the block M366 left behind. Four sentences on the front page and its companion counted the 194
    # third-party reconstructions that M369 removed, or an audit case count forty milestones out of date, and
    # `docs/README-extended.md` was not a file this tool read *at all* -- so the page that explains the numbers was
    # the one page nothing checked. Each of those sentences now carries derived numbers.
    ("README.md",
     r"\*\*(\d+) functions match the cartridge exactly\*\*, to the last byte, out of \*\*(\d+) reconstructed in C\*\*",
     ("recovered_exact", "recovered"), 1),
    ("README.md", r"\*\*(\d+)\*\* landed\s+from the screening tool, \*\*(\d+)\*\* read by hand\s+from the "
                  r"disassembly, \*\*(\d+)\*\* one-off probes",
     ("split_screened", "split_read", "split_named"), 1),
    ("README.md", r"disables each check's mechanism\*\* and requires the check to fail, (\d+) mechanisms and (\d+)",
     ("audit_cases",) * 2, 1),
    ("docs/README-extended.md",
     r"The corpus of recovered functions is \*{0,2}(\d+) entries, (\d+) of them byte-exact",
     ("recovered", "recovered_exact"), 1),
    # M389: the front page's pictures. A generated block is not a licence to stop asserting -- the waffle's legend and
    # its headline are the two sentences a newcomer reads first, so they get cases like every other number on the page.
    ("docs/README-extended.md",
     r"\*\*(\d+)\*\* by hand from the disassembly, \*\*(\d+)\*\* from the screening tool, \*\*(\d+)\*\* as "
     r"one-off probes,\s+and \*\*(\d+)\*\* copies of a proven shape",
     ("split_read", "split_screened", "split_named", "cohort_copies"), 1),
    ("docs/README-extended.md", r"disables each check's mechanism and requires the check to fail\.\*\* (\d+) mechanisms, (\d+)",
     ("audit_cases",) * 2, 1),
    # the byte map's four totals, on the handover page: the sentence still said 330 176 B (16.9 %) unclassified,
    # which the twelve-milestone byte-map arc closed at 440 B (0.0 %) in M349
    ("docs/handover.md",
     r"\*\*([\d\s,]+?) B padding\*\*, \*\*([\d\s,]+?) B\*\* `DAT_`-named data, \*\*([\d\s,]+?) B\*\* jump tables, "
     r"\*\*([\d\s,]+?) B \((\d+)\.(\d) %\) unclassified",
     ("bm_padding", "bm_data_named", "bm_jump_table", "bm_unclassified", "bm_unclass_whole",
      "bm_unclass_dec"), 1),
    ("docs/handover.md", r"indexes \*\*all (\d+) milestones\*\*", ("milestone_total",), 1),
    ("docs/handover.md", r"\*\*([\d\s,]+?) of ([\d\s,]+?) suites, ([\d\s,]+?) of ([\d\s,]+?) cases\*\*",
     ("runnable_suites", "total_suites", "runnable_cases", "total_cases"), 1),
    ("docs/handover.md", r"\*\*all ([\d\s,]+?) suites / ([\d\s,]+?) cases\*\*",
     ("total_suites", "total_cases"), 2),
    ("README.md", r"\*\*(\d+) of ([\d\s,]+?) functions match the cartridge exactly \u2014 (\d+)\.(\d) %\.\*\*",
     ("recovered_exact", "functions", "front_pct_whole", "front_pct_dec"), 1),
    ("README.md", r"\*\*(\d+) checks run with no ROM, no assets and no emulator\*\* \u2014 the other (\d+) need",
     ("runnable_cases", "gated_cases"), 1),
    ("README.md", r"PASS-FAST: (\d+) cases run, (\d+) SKIP", ("runnable_cases", "gated_cases"), 1),
    ("README.md", r"compares every function against the cartridge: (\d+) exact, (\d+) differs",
     ("recovered_exact", "build_differs"), 1),
    ("README.md", r"tools/\s+(\d+) analysis and gate scripts", ("tool_count",), 1),
    # M410: the provenance split. "Bodies whose C reproduces the cartridge" and "bodies this project wrote" are two
    # numbers, and the page must never let the first stand in for the second.
    ("README.md", r"(\d+) entries, (\d+) byte-exact\*\* — of which \*\*(\d+)\*\* are the decompiler's own C "
                  r"verified word for word, and \*\*(\d+)\*\* are ours",
     ("recovered", "recovered_exact", "banked_exact", "project_recovered"), 1),
    ("README.md", r"docs/log/\s+(\d+) notes", ("note_count",), 1),
    # the codec claim on the front page, tied to the committed fixture rather than to prose
    ("README.md", r"\*\*([\d\s,]+)\*\*-byte shared codebook, with\s+\*\*([\d\s,]+)\*\* of\s+"
                  r"\*\*([\d\s,]+)\*\* groups structurally valid and\s+\*\*([\d\s,]+)\*\* of\s+"
                  r"\*\*([\d\s,]+)\*\* samples decoding to audio",
     ("codec_codebook_bytes", "codec_groups_ok", "codec_groups_total", "codec_good", "codec_samples"), 1),
    ("README.md", r"\*\*(\d+) of (\d+) cases cannot run without your dump\*\*",
     ("gated_cases", "total_cases"), 1),
    ("docs/handover.md", r"# (\d+) suites, (\d+) cases", ("total_suites", "total_cases"), 1),
    ("docs/handover.md", r"audit_gates\.py\s+# (\d+)/(\d+):", ("audit_cases",) * 2, 1),
    ("docs/handover.md", r"\*\*(\d+) of (\d+) cases\*\*\. Their enforcement",
     ("gated_cases", "total_cases"), 1),
    ("docs/handover.md", r"vouch for those (\d+) cases", ("gated_cases",), 1),
    # Written as "N of M suites, N of M cases" on ONE line because the first pair used to be split across a
    # line break, which is how `ci.sh` came to claim "10 of 34 suites" for several milestones while the
    # case figures beside it stayed correct: the pattern pinned the cases and could not see the suites (M196).
    ("tools/ci.sh", r"# (\d+) of (\d+) suites, (\d+) of (\d+) cases",
     ("runnable_suites", "total_suites", "runnable_cases", "total_cases"), 1),
    (".github/workflows/acceptance.yml", r"#   (\d+) suites / (\d+) cases  PASS",
     ("runnable_suites", "runnable_cases"), 1),
    (".github/workflows/acceptance.yml", r"#   (\d+) suites / (\d+) cases  SKIP",
     ("gated_suites", "gated_cases"), 1),
    (".github/workflows/acceptance.yml", r"all (\d+) suites / (\d+) cases",
     ("total_suites", "total_cases"), 3),
]

AUDIT_SUITE = "gate audit (mechanisms disabled)"


def derive(root: Path) -> dict:
    """Every asserted number: the suite totals from `acceptance.py`, the corpus from `fixtures/decomp/`."""
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
    _codec = json.loads((root / "fixtures" / "sound" / "codec.json").read_text())
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
        "codec_codebook_bytes": _codec["codebook_bytes"],
        "codec_good": _codec["samples_good"],
        "codec_samples": _codec["sample_count"],
        "codec_groups_ok": _codec["groups_total"] - _codec["groups_failing"],
        "codec_groups_total": _codec["groups_total"],
        "distinct_lengths": len({v["length"] for v in
                                 json.loads((root / "fixtures" / "scd" / "profile.json").read_text())["opcodes"].values()
                                 if v.get("length")}),
        **_status(root),
        **_recovered(root),
        **_distance(root),
        "tool_count": len([p for p in (root / "tools").iterdir()
                           if p.suffix in (".py", ".sh", ".c", ".swift")]),
        **_corpus(root),
        **_bytemap(root),
    }


def _distance(root: Path) -> dict:
    """M409: the distance map's published figures, derived from the fixture the tool writes.

    The front page now carries the one number the last thirty milestones could not see: how many bodies are already
    byte-exact, and how many of those nobody had noticed. Derived from `fixtures/decomp/distance.json` so the page
    cannot drift from the measurement.
    """
    path = root / "fixtures" / "decomp" / "distance.json"
    if not path.exists():
        return {"distance_exact": 0, "distance_unclaimed": 0, "distance_within_8": 0, "distance_measured": 0}
    doc = json.loads(path.read_text())
    hist = doc["histogram"]
    return {"distance_exact": doc["overlap"]["exact"],
            "distance_unclaimed": doc["overlap"]["exact_unclaimed"],
            "distance_within_8": hist["within_1"] + hist["within_2"] + hist["within_4"] + hist["within_8"],
            "distance_measured": doc["totals"]["measured"]}


def _recovered(root: Path) -> dict:
    """How many functions are reconstructed, and how many of them are byte-exact (M335).

    The headline of the whole project -- "N reconstructed, M matching" -- was quoted in prose and asserted
    **nowhere** until M335, which is how it could sit at 130/129 while the corpus moved to 147/146. It is
    derived from the same fixture `export_src.py` and `export_ranges.py` read, so the two exporters and the
    front page cannot disagree about it.
    """
    per_image = recovered.load(root / "fixtures" / "decomp" / "recovered.json")
    entries = [e for group in per_image.values() for e in group]
    # M366: the front page's *other* two numbers -- how many of the corpus are copies of a proven shape, and how
    # many shapes that is -- were quoted and asserted nowhere, exactly like the headline pair before M335. They are
    # grouped from the same fixture: a source shared by two or more functions is a cohort, a unique one is a single.
    from collections import Counter as _Counter
    groups = _Counter((e.get("source") or e.get("source_file")) for e in entries)
    copies = sum(v for v in groups.values() if v > 1)
    # M373: and the split of the non-cohort remainder was typed, not derived -- "46 by hand + 55 singles" summed to
    # 198 against a corpus of 210 and had been short since M369. It is derivable after all, from the `probe` string
    # that every entry carries, so it is derived: three provenances, and they must add up to the solo count.
    solo = [e for e in entries if groups[(e.get("source") or e.get("source_file"))] == 1]
    screened = sum(1 for e in solo if (e.get("probe") or "").startswith("single"))
    read = sum(1 for e in solo if (e.get("probe") or "").startswith("read from the words"))
    return {"recovered": len(entries),
            "recovered_exact": sum(1 for e in entries if e["verdict"] == "byte-exact"),
            # M374: what `make check` prints, tied to the fixture rather than typed. The build compares every body
            # against the cartridge, so the two numbers it reports are the fixture's own split -- byte-exact, and
            # everything else (the published partial). If a byte-exact body ever fails to build, `make check` fails,
            # which is the cartridge tier's job; what this key stops is the *prose* drifting between builds.
            "build_differs": sum(1 for e in entries if e["verdict"] != "byte-exact"),
            "cohort_copies": copies,
            "cohort_shapes": sum(1 for v in groups.values() if v > 1),
            "solo": len(solo),
            "split_screened": screened,
            "split_read": read,
            # M410: a FIFTH provenance, and it exists so that 187 bodies of the decompiler's own C are never counted
            # as work this project did. They were byte-exact all along; the bank says so with `provenance: provider`,
            # and the label is derived from the same `probe` channel as the other three.
            "split_banked": sum(1 for e in solo if (e.get("probe") or "").startswith("imported:")),
            "split_named": len(solo) - screened - read
                           - sum(1 for e in solo if (e.get("probe") or "").startswith("imported:")),
            "banked": sum(1 for e in entries if e.get("provenance") == "provider"),
            "banked_exact": sum(1 for e in entries
                                if e.get("provenance") == "provider" and e["verdict"] == "byte-exact"),
            "project_recovered": sum(1 for e in entries if e.get("provenance") != "provider"),
            # M369: this key used to be called `imported`, which was the conflation M368 found -- it counts entries
            # whose C is a *file*, and after the removal every one of those is authored here. The name went with the
            # population; the invariant that no third-party corpus is present is a case in `check()`, not a number.
            "authored_files": sum(1 for e in entries if e.get("source_file"))}


def _status(root: Path) -> dict:
    """The analysis ladder (M209), read from the committed status manifest.

    `F2`, `named` and `validated` are three different claims about 3 638 functions, and quoting any one of them
    as "understood" is the substitution this project keeps catching. They are derived here so a document
    sentence cannot drift from the artifact that measures them.
    """
    t = json.loads((root / "manifests" / "analysis_status.json").read_text())["totals"]
    out = {"status_f2": t["F2"], "status_named": t["named"], "status_validated": t["validated"],
           "status_extent_measured": t["extent_measured"]}
    # M389: the front page's own arithmetic, derived here so the pictures cannot disagree with the ladder.
    rec = _recovered(root)
    out["status_pseudocode"] = t["F0"] - rec["recovered"] - t["extent_measured"]
    out["status_remaining"] = t["F0"] - rec["recovered"]
    tenths = (1000 * rec["recovered_exact"] + t["F0"] // 2) // t["F0"] if t["F0"] else 0
    out["front_pct_whole"], out["front_pct_dec"] = tenths // 10, tenths % 10
    out["front_milestones_left"] = int((t["F0"] - rec["recovered"]) / (53 / 10) + 0.5)
    return out


def _corpus(root: Path) -> dict:
    """The corpus metrics, from committed fixtures only -- so CI can recompute them without a cartridge.

    `fixtures/decomp/images.json` is the 36-image inventory (layout metadata, no bytes) and
    `fixtures/decomp/ranges.json` is the provider's body ranges. Coverage is the union of the inclusive
    body ranges over the image extents: `end - start + 1`, never `end - start + 4`, which is the M205 bug
    that inflated this total by one 4-byte word per function body. The function count comes from the
    committed tree itself, because the index that produced it is not committed.
    """
    images = json.loads((root / "fixtures" / "decomp" / "images.json").read_text())["images"]
    ranges = json.loads((root / "fixtures" / "decomp" / "ranges.json").read_text())["images"]
    # Per image, then summed: twenty overlays load at 0x80161cf0, so their body ranges share addresses.
    # A single global set would collapse them and report 732 468 B -- 37.6 % -- which is the arithmetic
    # M205 caught in its own first draft.
    covered = 0
    # M289: `fixtures/decomp/ranges.json` is the *provider's* boundaries and stays authoritative for every
    # analysis that classifies bytes. Fourteen functions have been reconstructed and pinned, and the provider's
    # body for them covers only the dispatch head -- so coverage is the union of its ranges with the measured
    # extents in `fixtures/decomp/recovered.json`, which is stated rather than folded into the range fixture.
    # M340: and with the *measured* extents (`fixtures/decomp/measured_extents.json`) -- functions whose body
    # length the bytes give but whose C does not exist, so `recovered.json` cannot carry them. Three
    # projections read this fixture (here, `export_src.py` and `classify_image.py`) through one reader.
    rec = recovered.load()
    meas = recovered.load_measured()
    add = recovered.load_additions()
    for name, pairs in ranges.items():
        words = set()
        for s, e in pairs:
            words.update(range(int(s), int(e) + 1))
        for e in rec.get(name, []):
            words.update(range(e["start"], e["end"] + 1))
        for e in meas.get(name, {}).values():
            words.update(range(e["start"], e["end"] + 1))
        for e in add.get(name, []):
            words.update(range(e["start"], e["end"] + 1))
        covered += len(words)
    image_bytes = sum(i["size"] for i in images)
    tenths = (1000 * covered + image_bytes // 2) // image_bytes if image_bytes else 0
    ci = json.loads((root / "manifests" / "code_index.json").read_text())["images"]
    return {
        "images": len(images),
        "image_bytes": image_bytes,
        "functions": len(list((root / "src").glob("*/*.c"))),
        # M288: the provider labels a jump table's case bodies `switchD_::caseD_`; they are code, not
        # functions, and the projection keeps them under `src/<image>/switch/`.
        "fragments": sum(i.get("fragments", 0) for i in ci),
        "ranges": sum(len(v) for v in ranges.values()),
        "covered_bytes": covered,
        "coverage_whole": tenths // 10,
        "coverage_dec": tenths % 10,
    }


def _bytemap(root: Path) -> dict:
    """The byte map's own totals, so the sentence that describes the residue cannot rot (M373).

    `manifests/byte_map.json` tiles all 1 956 560 B and is regenerated by `classify_image.py --write`; the prose
    that quotes its residue was last correct before the byte-map arc closed, still claiming 330 176 B (16.9 %)
    unclassified where the arc ended at 440 B (0.0 %). Derived per class here, summed over the runs, so a
    regenerated map moves the sentence or fails the check.
    """
    bm = json.loads((root / "manifests" / "byte_map.json").read_text())
    tot = {}
    for runs in bm["images"].values():
        for lo, hi, cls, _why in runs:
            tot[cls] = tot.get(cls, 0) + hi - lo + 1
    image_bytes = sum(tot.values()) or 1
    unc = tot.get("unclassified", 0)
    tenths = (1000 * unc + image_bytes // 2) // image_bytes
    return {"bm_padding": tot.get("padding", 0),
            "bm_data_named": tot.get("data_named", 0),
            "bm_jump_table": tot.get("jump_table", 0),
            "bm_unclassified": unc,
            "bm_unclass_whole": tenths // 10,
            "bm_unclass_dec": tenths % 10}


def _overlap(root: Path) -> int:
    """Bytes a measured extent shares with another published body (M340).

    `0x80000dd4`'s 95-word body contains the separately published `0x80000f08`, whose three direct `jal` callers
    make it a real function reached through the shared tail. The two extents therefore overlap, and the header
    sum counts the shared words twice -- so the invariant is "headers == union + overlap", stated with its
    number instead of quietly equal. Absorbing the inner function is not an option: it is called directly.
    """
    ranges = json.loads((root / "fixtures" / "decomp" / "ranges.json").read_text())["images"]
    meas = recovered.load_measured(root / "fixtures" / "decomp" / "measured_extents.json")
    total = 0
    for name, corr in meas.items():
        spans = [(int(a, 16) if isinstance(a, str) else a, int(b, 16) if isinstance(b, str) else b)
                 for a, b in ranges.get(name, [])]
        for m in corr.values():
            for a, b in spans:
                if a == m["start"]:
                    continue                      # the entry being corrected is not an overlap
                lo, hi = max(a, m["start"]), min(b, m["end"])
                if lo <= hi:
                    total += hi - lo + 1
    return total


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
            # numbers in prose may carry thin spaces or commas for readability; normalise rather than
            # dictate a format, which is what made this check miss its own sentence on the first run
            got = [int(re.sub(r"[,\s]", "", g)) for g in m.groups()]
            want = [vals[k] for k in keys]
            if got != want:
                bad.append(f"{got} != {want}")
        cases.append((label, not bad, "; ".join(bad) if bad else f"{[vals[k] for k in keys]} ok"))

    # --- the generated artifacts must agree with the derivation (M205). Quoting the numbers in the docs is
    # not enough: the tree that publishes them is *written by a tool*, and that tool claimed one 4-byte word
    # past every body for thirty milestones. These two cases tie the generated files to the fixtures, so a
    # regeneration that reintroduces the arithmetic, or a tree that was never regenerated, fails here.
    index = root / "src" / "INDEX.md"
    head = re.search(r"(\d[\d,]*) functions across (\d+) images, (\d[\d,]*) of (\d[\d,]*) image bytes",
                     index.read_text()) if index.exists() else None
    if head is None:
        cases.append(("src/INDEX.md agrees with the derived corpus", False, "headline not found"))
    else:
        got = [int(re.sub(r"[,\s]", "", g)) for g in head.groups()]
        want = [vals["functions"], vals["images"], vals["covered_bytes"], vals["image_bytes"]]
        cases.append((f"src/INDEX.md agrees with the derived corpus — {got[0]} functions, {got[1]} images, "
                      f"{got[2]:,} of {got[3]:,} B", got == want, f"{got} != {want}" if got != want else "ok"))

    sizes = []
    # M288: `src/<image>/*.c` is the function list; `src/<image>/switch/*.c` holds the provider's
    # `switchD_::caseD_` bodies, which are code but not functions. Both carry a body size, and the sum of the
    # two is what has to equal coverage -- counting only the first would under-report by every case body.
    for p in sorted(list((root / "src").glob("*/*.c")) + list((root / "src").glob("*/switch/*.c"))):
        m = re.search(r"size (\d+) B", p.read_text()[:600])
        if m:
            sizes.append(int(m.group(1)))
    total = sum(sizes)
    # M206: `code_index.json` published a 4-byte word count under a byte-shaped name. The per-image
    # figures must now sum to the derived coverage, and covered + unclaimed must tile each image exactly --
    # one invariant that catches both a word/byte slip and a body that was dropped from the map.
    ci_path = root / "manifests" / "code_index.json"
    if not ci_path.exists():
        cases.append(("manifests/code_index.json tiles the images", False, "file missing"))
    else:
        imgs = json.loads(ci_path.read_text())["images"]
        cov = sum(i["covered_bytes"] for i in imgs)
        tile = [i["name"] for i in imgs if i["covered_bytes"] + i["unclaimed_bytes"] != i["size"]]
        ok = cov == vals["covered_bytes"] and not tile and len(imgs) == vals["images"]
        cases.append((f"manifests/code_index.json publishes bytes, not words — {cov:,} covered, "
                      f"covered + unclaimed tiles all {len(imgs)} images", ok,
                      "ok" if ok else f"covered {cov} vs {vals['covered_bytes']}; untiled {tile[:3]}"))

    # M373: two invariants the record had no case for. (a) `fixtures/decomp/measured_extents.json` publishes a
    # `summary` block that said 188 functions / 23 868 B while its own list held 382 / 40 516 B -- and it said so
    # for four milestones, because `extent_scan.py --write` computes the summary from a *rescan*, while M365 and
    # M369 edited the lists. The lists are the source of truth now, so the summary is checked against them and
    # rebuilt from them (`extent_scan.py --resummary`). (b) the third-party corpus stays removed: M369 deleted it,
    # and nothing stops a future milestone from importing it again.
    meas_path = root / "fixtures" / "decomp" / "measured_extents.json"
    if not meas_path.exists():
        cases.append(("the rung's summary agrees with its own list", False, "file missing"))
    else:
        rung = json.loads(meas_path.read_text())
        want = {"functions": len(rung.get("functions", [])),
                "bytes": 4 * sum(f["words"] for f in rung.get("functions", [])),
                "regions": len(rung.get("regions", [])),
                "rejected": sum(len(r["rejected"]) for r in rung.get("regions", [])),
                "tail_jumps": sum(len(r["tail_jumps"]) for r in rung.get("regions", []))}
        got = rung.get("summary", {})
        ok = all(got.get(k) == v for k, v in want.items())
        cases.append((f"the rung's summary agrees with its own list — {want['functions']} functions, "
                      f"{want['bytes']:,} B", ok,
                      "ok" if ok else "; ".join(f"{k} {got.get(k)} != {v}" for k, v in want.items()
                                                if got.get(k) != v)))
    cases.append(("the imported third-party corpus stays removed (M369)",
                  not (root / "fixtures" / "decomp" / "imported").exists(),
                  "ok" if not (root / "fixtures" / "decomp" / "imported").exists()
                  else "fixtures/decomp/imported/ exists again — no licence, no corpus"))

    ovl = _overlap(root)
    ok = (len(sizes) == vals["functions"] + vals["fragments"]
          and total == vals["covered_bytes"] + ovl)
    cases.append((f"the {len(sizes)} body headers ({vals['functions']} functions + {vals['fragments']} switch "
                  f"case bodies) sum to the covered bytes plus the {ovl} B two extents share — {total:,} B, "
                  f"which is the union and not {total + 2384:,}", ok,
                  "ok" if ok else f"{len(sizes)} headers, {total} B vs {vals['covered_bytes']} + {ovl} B"))
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
        # everything `derive()` reads, not just the milestones: this self-test has now failed twice on a
        # missing input, which is the audit-environment gap in miniature
        # M205 added three more inputs -- the image inventory, the body ranges and the generated tree.
        # The tree is a symlink: this self-test only reads it, and copying 3 638 files to read one
        # header line each would cost more than the check it protects. (A *mutation* must never
        # target a symlinked path -- see the guard in audit_gates.build_env.)
        # M335: the third time this list has been short — `_recovered()` reads `fixtures/decomp/
        # recovered.json`, so an untouched copy of the real files reported 0 recovered against a README that
        # says 147. The rule is mechanical: **every input `derive()` reads belongs in this tuple.**
        for rel in ("fixtures/milestones/gaps.json", "fixtures/sound/codec.json",
                    "fixtures/decomp/images.json", "fixtures/decomp/ranges.json",
                    "fixtures/decomp/recovered.json", "fixtures/decomp/measured_extents.json",
                    "fixtures/decomp/distance.json",
                    "fixtures/scd/profile.json", "manifests/code_index.json",
                    "manifests/analysis_status.json", "manifests/byte_map.json"):
            (tmp / rel).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / rel, tmp / rel)
        (tmp / "src").symlink_to(ROOT / "src")
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
