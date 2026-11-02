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
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CARTRIDGE = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"

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
    dict(name="patch_text: an edit drops the file mode",
         tool="patch_text.py", args=["--self-test"],
         file="tools/patch_text.py",
         old="        shutil.copymode(path, tmp)",
         new="        pass"),
    # --- the artefact scan: the two ways a content guard silently stops guarding
    # Mutate the *comparison*, not the constant: emptying `MAGICS` makes the self-test crash on an
    # index error, and raising `FILE_MAX` makes it try to allocate petabytes — both "fail", neither for
    # the reason under audit. That was this audit's second attempt; the first was vacuous.
    dict(name="artefact_scan: the cartridge magics are never compared",
         tool="artefact_scan.py", args=["--self-test"],
         file="tools/artefact_scan.py",
         old="        if head in MAGICS:",
         new="        if False:"),
    dict(name="artefact_scan: the size ceiling is never applied",
         tool="artefact_scan.py", args=["--self-test"],
         file="tools/artefact_scan.py",
         old="        if size > FILE_MAX:",
         new="        if False:"),
    # --- the milestone index: the two ways it could stop following the record
    dict(name="milestone_index: note titles ignored (the index stops following the notes)",
         tool="milestone_index.py", args=["--check"],
         file="tools/milestone_index.py",
         old="            note = note_for(num, row)",
         new="            note = None"),
    dict(name="milestone_index: the gap list is ignored",
         tool="milestone_index.py", args=["--check"],
         file="tools/milestone_index.py",
         old="    gaps = load_gaps(root) if gaps is None else gaps\n    rows = parse_log(log_text)",
         new="    gaps = [] if gaps is None else gaps\n    rows = parse_log(log_text)"),
    # --- the commit-subject gate (M183). Two-sided, and each leg is aimed at its own comparison: the
    # accounting leg is graded by a synthetic bed (a real record has nothing unaccounted, so disabling the
    # comparison there would be invisible), the freshness leg by a bed whose fixture is deliberately stale.
    dict(name="milestone_index: a commit subject with no record is accepted",
         tool="milestone_index.py", args=["--self-test"],
         file="tools/milestone_index.py",
         old="                  not unaccounted_commits,",
         new="                  True,"),
    dict(name="milestone_index: a stale commit fixture is accepted",
         tool="milestone_index.py", args=["--self-test"],
         file="tools/milestone_index.py",
         old="    fresh = fixture.exists() and bool(committed) and highest - top <= CYCLE",
         new="    fresh = True"),
    # --- the full CI tier: one mutation per leg, so neither the skip guard nor the digest check can rot
    dict(name="ci_full: the skip guard never fires",
         tool="ci_full.sh", args=["--self-test"], interp="sh",
         file="tools/ci_full.sh",
         old="	if grep -q 'skipped for want of the cartridge' \"$log\"; then\n\t\treturn 1",
         new="	if false; then\n\t\treturn 1"),
    dict(name="cart_fetch: the digest comparison always passes",
         tool="cart_fetch.sh", args=["--self-test"], interp="sh",
         file="tools/cart_fetch.sh",
         old="\t[ \"$(sha_of \"$1\")\" = \"$2\" ]",
         new="\ttrue"),
    dict(name="patch_text: a no-op replacement is accepted",
         tool="patch_text.py", args=["--self-test"],
         file="tools/patch_text.py",
         old="        if old == new:",
         new="        if False:"),
    # --- the file table (M178): one mutation per leg, including the exact bug this tool had on its
    # first run — the entry offsets are relative to the table base, and slicing the cartridge with one
    # double-counts it. That mutation reads a plausible file out of the wrong place and still looks sane.
    dict(name="file_table: the directory is read one word early (the count taken as an offset)",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    vals = struct.unpack_from(">" + str(count) + "I", r4, 4)',
         new='    vals = struct.unpack_from(">" + str(count) + "I", r4, 0)'),
    dict(name="file_table: no offset is ever seen without the top byte",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    noflag = {k for k, v in enumerate(vals) if v >> 24 == 0}',
         new='    noflag = set()'),
    dict(name="file_table: every entry counted as a walked member",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    named = {BASE + o for _, o, _ in zl}',
         new='    named = {BASE + o for _, o, _ in real}'),
    dict(name="file_table: id 1983 sliced with the relative offset",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='    r3 = d[OTHER_CART:OTHER_CART + OTHER_SIZE]',
         new='    r3 = d[OTHER_REL:OTHER_REL + OTHER_SIZE]'),
    # --- the ratchet (M179): one mutation per invariant, plus the "make it disappear" route. Each is
    # aimed at the comparison, and each is caught by `--self-test` rather than `--check`, because on a
    # healthy repository `--check` passes whether or not these comparisons are wired at all — which is
    # the whole reason the self-test exists.
    dict(name="ratchet: a lowered expected count is accepted",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="    lowered = sorted(n for n in was if n in now and now[n] < was[n])",
         new="    lowered = []"),
    dict(name="ratchet: a deleted suite is not noticed",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="    deleted = sorted(set(was) - set(now))",
         new="    deleted = []"),
    dict(name="ratchet: registry drift (a raised count) is accepted without --write",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old='("the registry matches the baseline (any change needs --write)", not drift,',
         new='("the registry matches the baseline (any change needs --write)", True,'),
    dict(name="ratchet: --write lowers a count without --allow-decrease",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old="        if (lowered or deleted) and not allow_decrease:",
         new="        if False:"),
    # --- the M179 claim classes. A *code reading* is gated by pinning the expressions that make it a
    # reading, so the audit aims at the needle: with a needle that is not in the source, a wired case fails
    # and a vacuous one still passes — which is exactly the discrimination the audit is for. The measured
    # band is aimed at from the inside, by narrowing it until real records violate it.
    dict(name="file_table: the rate-byte reading looks for an expression that is not there",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old='and "param_2 = 16000" in f3704 and "param_2 = 8000;" in f3704',
         new='and "param_2 = 32000" in f3704 and "param_2 = 8000;" in f3704'),
    dict(name="file_table: the +4 band is narrowed until real records violate it",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old="all(0.03 < field[k] / pay[k] < 0.115 for k in range(n))",
         new="all(0.05 < field[k] / pay[k] < 0.115 for k in range(n))"),
    # --- the M195 bit-stream walk (M196). It used to be the suite's most expensive case and the only one
    # with no audit entry, which is the wrong way round. The mutation removes the block's 260-bit body,
    # which is the mechanism the case turns on: the cursor then stops at the header, nothing ever overruns,
    # and both pinned verdicts move from 362/588 and 339/588 to 0. Aiming at `lim` instead would be
    # vacuous — no clip is over 512 KiB, so the guard never binds and removing it changes nothing.
    dict(name="file_table: a normal block consumes no sample bits",
         tool="file_table.py", args=["--check"],
         file="tools/file_table.py",
         old="                p += SAMPLE_BITS * m",
         new="                p += 0"),
    # --- the pool (M196). One mutation per lie a scheduler can tell: a result that never reaches the
    # report, a report assembled in completion order, and a failing suite that is judged a pass. Each is
    # aimed at the acceptance self-test, which is the only thing that looks at the pool rather than through
    # it -- `--check` on a healthy tree passes whether or not any of this is wired.
    dict(name="acceptance: a worker's result never reaches the report",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="            lines.append(line)",
         new="            pass"),
    dict(name="acceptance: the report is assembled in completion order, not registry order",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="    return lines, failures, skipped, deferred, verbose",
         new="    return lines[::-1], failures, skipped, deferred, verbose"),
    dict(name="acceptance: a suite is a pass regardless of its exit status or tally",
         tool="acceptance.py", args=["--self-test"],
         file="tools/acceptance.py",
         old="    ok = code == 0 and passed == total and total == expected",
         new="    ok = True"),
    # --- the M200 class mapping. The tag is `(key >> 14) & 3`; widening the mask mixes the sections
    # and the data case must fail. The second mutation drops the length argument from the resolver's
    # reading, which is the only thing distinguishing cache C.
    dict(name="file_table: the pool class tag is not masked to two bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="    _tag = lambda k: (k >> 14) & 3",
         new="    _tag = lambda k: 0"),
    dict(name="file_table: the resolver's length-bearing dispatch is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='(int)piVar5 + 10" in _res',
         new='(int)piVar5 + 99" in _res'),
    dict(name="file_table: the class-3 parameters are read big-endian",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _sw = lambda v: ((v & 0xFF) << 8) | (v >> 8)',
         new='    _sw = lambda v: v'),
    dict(name="file_table: the +12 parameter is read big-endian",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _p12 = Counter(_sw(struct.unpack_from(">H", pool, _r + 12)[0]) for _r in _recs16)',
         new='    _p12 = Counter(struct.unpack_from(">H", pool, _r + 12)[0] for _r in _recs16)'),
    dict(name="file_table: list[5] is treated as an independent key set",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="                  len(_s5) == 290 and len(_t0) == 142 and len(_t3) == 148 and _t0 <= _s2))",
         new="                  len(_s5) == 290 and len(_t0) == 142 and len(_t3) == 148 and _t0 >= _s2))"),
    dict(name="file_table: cache C's rate argument is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  "FUN_800ace1c(*psVar6,piVar5+3,*(undefined2*)((int)piVar5+10));" in _resn))',
         new='                  "FUN_800ace1c(*psVar6,piVar5+3,*(undefined2*)((int)piVar5+99));" in _resn))'),
    dict(name="file_table: list[2] is allowed to stop short of the sample space",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old="                  len(_s2b) == 2027 and 0 in _s2b and 2026 in _s2b and _dkeys <= _s2b))",
         new="                  len(_s2b) == 2027 and 0 in _s2b and 2027 in _s2b and _dkeys <= _s2b))"),
    dict(name="file_table: list[2]'s handler is not checked for cache tables",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  not any(g in _h2 for g in ("8014e1d0", "801521e0", "801529f0"))))',
         new='                  any(g in _h2 for g in ("8014e1d0", "801521e0", "801529f0"))))'),
    # --- the M203 loop fields. One mutation per falsification the case turns on: the loop word ignored
    # (so no record is looped), the length read as 16 bits (so four loop regions no longer fit), the
    # start/end comparison inverted, the loop word truncated to 16 bits, and the decoded frame read as 32
    # samples instead of 64. Aiming at the prose instead would be vacuous — the case asserts numbers.
    dict(name="file_table: the loop word at +24 is ignored",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _w24 = lambda r: struct.unpack_from(">I", r, 24)[0]',
         new='    _w24 = lambda r: 1'),
    dict(name="file_table: the declared length is read as 16 bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    _wlen = lambda r: struct.unpack_from(">I", r, 16)[0] & 0xFFFFFF',
         new='    _wlen = lambda r: struct.unpack_from(">I", r, 16)[0] & 0xFFFF'),
    dict(name="file_table: the start/end comparison is inverted",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  sum(1 for _k, a, b, l in loops if a < b) == 123))',
         new='                  sum(1 for _k, a, b, l in loops if a > b) == 123))'),
    dict(name="file_table: the loop length is truncated to its low 16 bits",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    loop_len = [_w24(r) for r in srec[:n_smp]]',
         new='    loop_len = [struct.unpack_from(">H", r, 26)[0] for r in srec[:n_smp]]'),
    dict(name="file_table: a decoded frame is taken as 32 samples, not 64",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    stream_len = [((len(smp) - 256) // 40) * 64 for smp in smp_blobs]',
         new='    stream_len = [((len(smp) - 256) // 40) * 32 for smp in smp_blobs]'),
    dict(name="file_table: the reader's +0x14 load is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"param_2[4] = *(undefined4 *)(iVar1 + 0x14);" in s_dir',
         new='"param_2[4] = *(undefined4 *)(iVar1 + 0x15);" in s_dir'),
    dict(name="file_table: the remainder arithmetic is read as length - (start - length)",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) + *(int *)(iVar1 + 0x38));"',
         new='"uVar3 = *(int *)(iVar1 + 0x30) - (*(int *)(iVar1 + 0x34) - *(int *)(iVar1 + 0x38));"'),
    dict(name="file_table: the mixer's post-wrap segment is no longer read",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='and "local_40 = (*(int *)(param_1 + 0x34) - local_48) + *(int *)(param_1 + 0x38);" in s_mix',
         new='and "local_40 = (*(int *)(param_1 + 0x38) - local_48) + *(int *)(param_1 + 0x34);" in s_mix'),
    dict(name="file_table: the note-off no longer clears the per-voice flag byte",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='"_DAT_80143f0c + 1) = 0;" in s_off',
         new='"_DAT_80143f0c + 2) = 0;" in s_off'),
    # --- M210: the hook certificate. The mutation inverts the hash comparison, which must break the
    # "a matching certificate validates" case -- otherwise the hook would skip the suite for any tree.
    dict(name="hook_cert: the worktree hash comparison is inverted",
         tool="hook_cert.py", args=["--self-test"], file="tools/hook_cert.py",
         old='    if cert.get("worktree") != want_hash:', new='    if cert.get("worktree") == want_hash:'),
    # --- M210: the scheduler contract, pinned by source shape after M152 left it ungated. The mutation
    # changes the needle, so the case must report that the loop is not the one it claims.
    dict(name="cfg_reach: the scheduler's return convention is no longer read",
         tool="cfg_reach.py", args=["--check"], file="tools/cfg_reach.py",
         old='    return ("} while (iVar1 == 1);" in s', new='    return ("} while (iVar1 == 2);" in s'),
    # --- M210: the image inventory that had no producer. Mutating the committed fixture (not the tool) is
    # the honest target: the case compares the fixture with a fresh distillation, so a hand-edited extent --
    # the drift the missing generator allowed for a milestone -- must fail it.
    dict(name="image inventory: a committed extent is edited by hand",
         tool="export_ranges.py", args=["--check-images"], file="fixtures/decomp/images.json",
         old='"size": 69952', new='"size": 69960'),
    # --- M211/M215: the two derived artefacts this cycle adds. Each mutation attacks the property that makes
    # the artefact worth having: the registry's refusal to call a variable path a constant, and the graph's
    # refusal to invent a target.
    dict(name="opcode_registry: the folded 12 is recorded as a constant advance",
         tool="opcode_registry.py", args=["--check"], file="tools/opcode_registry.py",
         old='        constant, variable = CONSTANT_PATH.get(number), VARIABLE_PATH.get(number)',
         new='        constant, variable = (CONSTANT_PATH.get(number) or 0) + 6, None'),
    dict(name="opcode_registry: an unclassified handler is counted as being in a function body",
         tool="opcode_registry.py", args=["--check"], file="tools/opcode_registry.py",
         old='    return any(start <= handler < end for start, end in bodies)', new='    return True'),
    dict(name="call_graph: the callees reconciliation reads no callees",
         tool="call_graph.py", args=["--check"], file="tools/call_graph.py",
         old='            callees[f"{img[\'name\']}:{f[\'address\']}"] = {int(x, 16) for x in f["callees"]}',
         new='            callees[f"{img[\'name\']}:{f[\'address\']}"] = set()'),
    dict(name="call_graph: node identity drops the image qualifier",
         tool="call_graph.py", args=["--check"], file="tools/call_graph.py",
         old='node = dict(id=f"{img[\'name\']}:{f[\'address\']}"',
         new='node = dict(id=f"{f[\'address\']}"'),
    # --- M209: the analysis-status index. Two ways it could flatter the corpus: the naming axis counted
    # without the curated-name rule, and the validated axis made free by an empty rule.
    dict(name="analysis_status: every function counts as named",
         tool="analysis_status.py", args=["--check"], file="tools/analysis_status.py",
         old='            named = not f["name"].startswith(("FUN_", "func_"))',
         new='            named = True'),
    dict(name="analysis_status: the validated axis is never set",
         tool="analysis_status.py", args=["--check"], file="tools/analysis_status.py",
         old='            validated = fid in F4', new='            validated = False'),
    # --- M208: the census that was a corpus generation stale. The mutation restores the `+4` that M205
    # fixed, so the fresh derivation disagrees with the committed census and the drift case must fire.
    dict(name="census: the covered set claims a word past every body again",
         tool="find_missed_functions.py", args=["--check"], file="tools/find_missed_functions.py",
         old='                    covered.update(range(int(r["start"], 16), int(r["end"], 16) + 1, 4))',
         new='                    covered.update(range(int(r["start"], 16), int(r["end"], 16) + 4, 4))'),
    # --- M207: the per-image byte map. Each mutation is a way the partition could lie: padding allowed to
    # overwrite a function body (so the body total moves), the unclassified bucket renamed to data (so the
    # hole disappears), and the padding run rounded out to the word boundary (so it stops being 0x00/0xFF).
    dict(name="byte_map: padding overwrites a function body",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            claimed.setdefault(w, ("padding", f"run of 0x{value:02x} in the unpacked image"))',
         new='            claimed[w] = ("padding", f"run of 0x{value:02x} in the unpacked image")'),
    dict(name="byte_map: the unclassified bucket is renamed to data",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            cls, src = claimed.get(w, ("unclassified", "no artifact names it"))',
         new='            cls, src = claimed.get(w, ("data_named", "no artifact names it"))'),
    dict(name="byte_map: a padding run is rounded out to the word boundary",
         tool="classify_image.py", args=["--check-cartridge"], file="tools/classify_image.py",
         old='            start = i + (-i % 4)',
         new='            start = i'),
    # --- M206: the manifest that published a word count as `covered_bytes`. The mutation restores the
    # word count, which the tiling case catches because covered + unclaimed then falls short of the image.
    dict(name="counts: code_index's covered_bytes is a word count again",
         tool="counts.py", args=["--check"], file="manifests/code_index.json",
         old='"covered_bytes": 57636', new='"covered_bytes": 14409'),
    # --- the M205 coverage arithmetic. The published figure was one 4-byte word per function body too
    # high; these four mutations are the ways to reintroduce it or to undermine the derivation that now
    # catches it: an exclusive end one word too far, a union taken across images instead of within one
    # (twenty overlays share a base, so that collapses 478 132 B), a function count that stops counting,
    # and a header sum allowed one word per range too high.
    dict(name="counts: the coverage union uses an exclusive end one word too far",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='            words.update(range(int(s), int(e) + 1))',
         new='            words.update(range(int(s), int(e) + 4))'),
    dict(name="counts: the per-image union is not reset between images",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='    covered = 0\n    for name, pairs in ranges.items():\n        words = set()',
         new='    covered = 0\n    words = set()\n    for name, pairs in ranges.items():'),
    dict(name="counts: the function count stops matching source files",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='        "functions": len(list((root / "src").glob("*/*.c"))),',
         new='        "functions": len(list((root / "src").glob("*.c"))),'),
    dict(name="counts: the header sum is allowed one word per range too high",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='    ok = len(sizes) == vals["functions"] and total == vals["covered_bytes"]',
         new='    ok = len(sizes) == vals["functions"] and total == vals["covered_bytes"] + 3 * vals["ranges"]'),
    dict(name="counts: the generated index headline is no longer parsed",
         tool="counts.py", args=["--check"], file="tools/counts.py",
         old='(\\d+) images, (\\d[\\d,]*) of',
         new='(\\d+) imagez, (\\d[\\d,]*) of'),
    # --- the M204 addressing cases. The claim is that nothing exists past byte 27, so the mutations are
    # the two ways a record could be wider than it is: a stride of 32 bytes instead of 28, and a member
    # that ends 8 bytes after the terminator. The third breaks the walker's own stride.
    dict(name="file_table: the adjacency is checked four bytes too far into the next record",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  if struct.unpack_from(">H", sdir, 28 * k + 28)[0] == smp_idx[k + 1])',
         new='                  if struct.unpack_from(">H", sdir, 28 * k + 32)[0] == smp_idx[k + 1])'),
    dict(name="file_table: the record stride is taken as 32 bytes, not 28",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='    nxt_idx = sum(1 for k in range(n_smp - 1)',
         new='    nxt_idx = sum(1 for k in range(n_smp - 2)'),
    dict(name="file_table: the directory is taken as ending 8 bytes after the terminator",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  sdir[28 * n_smp:] == b"\\xff\\xff\\xff\\xff" and len(sdir) == 28 * n_smp + 4))',
         new='                  sdir[28 * n_smp:] == b"\\xff\\xff\\xff\\xff" and len(sdir) == 28 * n_smp + 12))'),
    dict(name="file_table: the count walker's stride is read as 16 bytes",
         tool="file_table.py", args=["--check"], file="tools/file_table.py",
         old='                  and "psVar5 = psVar5 + 0xe;" in s_count and "param_1 = param_1 + 0xe;" in s_count',
         new='                  and "psVar5 = psVar5 + 0x10;" in s_count and "param_1 = param_1 + 0xe;" in s_count'),
    # --- the counts gate (M180). Its `--check` runs on a repository that is by definition consistent, so
    # aiming at the comparison is invisible; the mutation is aimed at the *derived* number instead. The
    # second audit disables the phrasectomy in the self-test, so the "a deleted phrase is caught" case
    # becomes the vacuous case it is meant to prevent.
    dict(name="counts: the derived total is off by one",
         tool="counts.py", args=["--check"],
         file="tools/counts.py",
         old='        "total_cases": sum(s[2] for s in suites),',
         new='        "total_cases": sum(s[2] for s in suites) + 1,'),
    dict(name="counts: the self-test stops deleting the phrase it checks for",
         tool="counts.py", args=["--self-test"],
         file="tools/counts.py",
         old='re.sub(r"vouch for those \\d+ cases", "vouch for those cases", ho)',
         new='re.sub(r"vouch for those \\d+ cases", lambda m: m.group(0), ho)'),
    # --- the verifier (M181). One mutation per branch of `adjudicate`, because the whole point of that
    # function is that admissibility outranks greenness, and a branch that stops firing turns the entry
    # point into a tool that reports PASS on evidence nobody has shown can fail.
    dict(name="verifier: vacuity no longer outranks greenness",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if vac or brk:",
         new="    if False:"),
    dict(name="verifier: an audit that did not pass is admitted",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if at == 0 or ap != at:",
         new="    if at == 0:"),
    dict(name="verifier: a failing procedure is reported as PASS",
         tool="verify.py", args=["--self-test"],
         file="tools/verify.py",
         old="    if failed:",
         new="    if False:"),
    dict(name="ratchet: src/ changes are never compared",
         tool="ratchet.py", args=["--self-test"],
         file="tools/ratchet.py",
         old='("src/ is byte-identical to the baseline", tree_now == tree_was,',
         new='("src/ is byte-identical to the baseline", True,'),
]

# things a mutated tool must be able to read; the heavy ones are symlinked
# `.github` is copied rather than linked because the workflow lint reads it — an audit of that lint that
# runs in an environment with no workflows passes for the wrong reason, which is how this list grew (M174).
COPY = ["tools", "fixtures", "docs/log", ".github"]
# `docs/MILESTONES.md` is here because a check of it runs: without the file, every audit of
# `milestone_index.py` "detects" a missing output and proves nothing (fifth environment gap in this arc,
# after build/elfs, src, .github/ and the shell interpreter).
# `README.md` is here because the counts gate reads it: the sixth environment gap in this arc if it is
# missing, and the failure it produced was a FileNotFoundError inside a *different* tool's self-test, which
# the audit then recorded as a detection (M180). A missing input and a caught mutation look identical from
# an exit code.
COPY_FILES = ["docs/handover.md", "docs/reverse_engineering_log.md", "docs/MILESTONES.md",
              "manifests/manifest.json", "manifests/code_index.json", "manifests/byte_map.json",
              "manifests/jump_tables.json", "manifests/analysis_status.json", "README.md"]
# `manifests/code_index.json` is here because `counts.py` now tiles the images with it (M206): without it
# every audit of the counts gate would "detect" a missing file, which is the environment gap this file's
# comment history already names four times.
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


COUNT = re.compile(r"^(\d+)\s*/\s*(\d+)")


def verdict(out: str):
    """The last `N/M` line in a tool's own output, or None — the same rule `acceptance.py` uses."""
    for line in reversed(out.splitlines()):
        m = COUNT.match(line.strip())
        if m:
            return int(m.group(1)), int(m.group(2))
    return None


def run_audit(audit, keep: Path = None) -> tuple:
    """Returns (detected, detail). `detected` is True when the mutated check failed, as it must."""
    tmp = Path(tempfile.mkdtemp(prefix="gate-audit."))
    try:
        build_env(tmp)
        target = tmp / audit["file"]
        if not target.exists():
            return None, f"mutation target absent from the sandbox: {audit['file']}"
        # `build_env` *links* src, build/elfs, rom and assets instead of copying them, so a mutation
        # aimed at a path under one of those edits the live repository. M205 did exactly that: an
        # audit of `src/INDEX.md` wrote through the link, left the worktree mutated and was then
        # judged on its own damage. A mutation must land inside the sandbox or not at all.
        if not str(target.resolve()).startswith(str(tmp.resolve()) + "/"):
            return None, f"mutation target resolves outside the sandbox: {audit['file']}"
        text = target.read_text()
        if audit["old"] not in text:
            return None, f"mutation anchor not found in {audit['file']}"
        mutated = text.replace(audit["old"], audit["new"], 1)
        if mutated == text:
            return None, "mutation changed nothing"
        target.write_text(mutated)
        # `interp` defaults to Python, but a gate written in shell must be run by shell: with the wrong
        # interpreter the mutated copy fails on a `SyntaxError` and the audit reports a detection that has
        # nothing to do with the mutation. Both M176 gates are shell, and both were vacuous until this
        # default existed. (Fourth time in this arc that an audit environment was wrong for the tool.)
        interp = audit.get("interp", sys.executable)
        proc = subprocess.run([interp, str(tmp / "tools" / audit["tool"])] + audit["args"],
                              capture_output=True, text=True, cwd=str(tmp))
        out = proc.stdout + proc.stderr
        # Judge the mutation the way `acceptance.py` judges a suite: by exit status and the `N/M` verdict
        # line, never by the presence of the word "FAIL". That fallback was itself the loophole this
        # audit exists to find — a gate whose *output* legitimately contains "FAIL" (the ratchet's
        # self-test prints one per deliberately broken invariant) read as "detected" no matter what, so
        # its three audits were unconditionally green while one of them caught nothing at all.
        detected = proc.returncode != 0 or (verdict(out) not in (None, (1, 1)) and verdict(out)[0] != verdict(out)[1])
        tail = [l for l in out.splitlines() if "FAIL" in l or "PASS" in l][-1:] or out.splitlines()[-1:]
        return detected, f"exit {proc.returncode}; {tail[0][:90] if tail else ''}"
    finally:
        if keep:
            shutil.move(str(tmp), str(keep))
        else:
            shutil.rmtree(tmp, ignore_errors=True)


def gated_tools() -> set:
    """The tools whose suites are registered as needing the cartridge, read from `acceptance.py`.

    Without this, an audit of a cartridge-gated tool reports VACUOUS on a machine with no cartridge: the
    mutated copy fails for want of the ROM, which acceptance reports as SKIP, and a mutation that cannot
    demonstrate anything was being counted as a check that cannot fail. Those are different things — a skip
    is an unrun check, a vacuous one is a broken check — and conflating them made `verify.py` report
    INCONCLUSIVE on every fresh clone, including the one the release notes tell a stranger to run.
    """
    ns = {"__file__": str(HERE / "acceptance.py"), "__name__": "_acceptance"}
    try:
        exec(compile((HERE / "acceptance.py").read_text(), "acceptance.py", "exec"), ns)
    except OSError:
        return set()
    out = set()
    for _name, cmd, _cases, needs_rom in ns["SUITES"]:
        if not needs_rom:
            continue
        for part in cmd:
            if isinstance(part, str) and part.startswith("tools/") and part.endswith(".py"):
                out.add(Path(part).name)
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true", help="describe each audit and exit")
    args = ap.parse_args()

    if args.list:
        for a in AUDITS:
            print(f"  {a['name']}\n      {a['tool']} {' '.join(a['args'])}  <- mutation in {a['file']}")
        return 0

    skipped = []
    gated = gated_tools() if not CARTRIDGE.exists() else set()
    passed = 0
    vacuous = []
    broken = []
    for a in AUDITS:
        if a["tool"] in gated:
            skipped.append(a["name"])
            print(f"  SKIP     {a['name']} — needs the cartridge, so its mutation cannot be demonstrated here")
            continue
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
    total = len(AUDITS) - len(skipped)
    print(f"\n{passed}/{total} audit case(s); {len(vacuous)} vacuous, {len(broken)} broken"
          + (f", {len(skipped)} skipped (needs the cartridge)" if skipped else ""))
    if vacuous:
        print("VACUOUS checks (they cannot fail for the right reason):")
        for name in vacuous:
            print(f"  - {name}")
    return 0 if passed == total else 1


if __name__ == "__main__":
    raise SystemExit(main())
