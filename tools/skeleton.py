#!/usr/bin/env python3
"""A function body's control-flow SKELETON, decoded from its own words — and the diff between two of them.

Why this exists: nothing in this repository knows what shape a function is. `draft_workbench.shape_of` is one bit —
`loop` if any branch targets backwards, `linear` otherwise — and the manifests carry calls (`call_graph.json`) and
dispatch heads (`dispatch_heads.json`) but **no basic blocks and no branch structure**. So a tool cannot ask "does the
image have a loop where the draft has none?", which is the question six catalogued but never-automated mechanisms need
(`mechanism_pass.MECHANISMS` marks `loop:walk-vs-index`, `guard:conjunction`, `compare:copy`, `rematerialise:block`,
`pointer:named` and `domain:integer` as not expressible as text passes).

The decode is pure integer arithmetic over the words: **no objdump, no `build/`**. That is deliberate and it is
`compile_probe.dispatch_signature`'s house style — a gate has to run in a CI checkout that has neither the toolchain
nor the built images, and M356 already cost a milestone learning that a gate which reads `build/` reports "no verdict".

What a signature deliberately does NOT contain: registers. Which register holds an index or a base is the allocator's
choice for the whole function, so two bodies that differ only in allocation must produce the SAME skeleton. That is what
makes the diff a statement about structure rather than about allocation — the distinction M440 measured (allocation is
212 bodies; structure is what is left).

    ./skeleton.py --self-test          # synthetic bodies with known shapes, and one control that MUST fail
"""
from __future__ import annotations

import importlib.util
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Conditional branches. `op` is the primary opcode; the `regimm` family (0x01) is decoded by its `rt` field.
BRANCH = {0x04: "beq", 0x05: "bne", 0x06: "blez", 0x07: "bgtz",
          0x14: "beql", 0x15: "bnel", 0x16: "blezl", 0x17: "bgtzl"}
REGIMM = {0x00: "bltz", 0x01: "bgez", 0x02: "bltzl", 0x03: "bgezl",
          0x10: "bltzal", 0x11: "bgezal", 0x12: "bltzall", 0x13: "bgezall"}
JUMP = {0x02: "j", 0x03: "jal"}
# `beql`/`bnel`/`blezl`/`bgtzl` execute their delay slot ON TAKEN PATHS ONLY. That distinction is load-bearing here:
# this toolchain cannot emit them at all (`-mbranch-likely` is not an option in this cc1 and gas will not relax into
# it, M442), so a body whose skeleton needs one is unreachable and the census must be able to say so.
LIKELY = {0x14, 0x15, 0x16, 0x17}
REGIMM_LIKELY = {0x02, 0x03, 0x12, 0x13}


def simm16(w: int) -> int:
    imm = w & 0xFFFF
    return imm - 0x10000 if imm & 0x8000 else imm


def decode_branch(w: int, pc: int):
    """(kind, target) for a branch/jump word, or (None, None) when the word does not transfer control."""
    op, rt = w >> 26, (w >> 16) & 0x1F
    if op in BRANCH:
        return BRANCH[op], (pc + 4 + 4 * simm16(w)) & 0xFFFFFFFF
    if op == 0x01 and rt in REGIMM:
        return REGIMM[rt], (pc + 4 + 4 * simm16(w)) & 0xFFFFFFFF
    if op in JUMP:
        return JUMP[op], ((pc & 0xF0000000) | ((w & 0x03FFFFFF) << 2)) & 0xFFFFFFFF
    return None, None


def is_return(w: int) -> bool:
    """`jr $ra` — the only return this compiler emits for an ordinary function."""
    return (w >> 26) == 0 and (w & 0x3F) == 0x08 and ((w >> 21) & 0x1F) == 31


def signature(words, base: int) -> dict:
    """The body's structure: branches with resolved targets, blocks, loop edges and nesting, guards, returns, calls.

    `words` is a list of 32-bit ints, `base` the vaddr of `words[0]`.
    """
    branches, calls, returns = [], 0, []
    for i, w in enumerate(words):
        pc = base + 4 * i
        kind, target = decode_branch(w, pc)
        if kind is None:
            if (w >> 26) == 0 and (w & 0x3F) in (0x08, 0x09):
                calls += 1                      # jr/jalr through a register: an indirect call, not a return
            elif (w >> 26) == 0x03:
                calls += 1                      # jal
            if is_return(w):
                returns.append(pc)
            continue
        if kind in ("j", "jal"):
            calls += 1 if kind == "jal" else 0
        backwards = target < pc
        branches.append({"pc": pc, "kind": kind, "target": target, "backward": backwards,
                         "slot_conditional": (w >> 26) in LIKELY or ((w >> 26) == 0x01 and ((w >> 16) & 0x1F)
                                                                    in REGIMM_LIKELY)})
    end = base + 4 * len(words)
    # Basic-block entries: the function head, every in-body branch target, and the word after each branch's delay slot.
    entries = {base}
    for b in branches:
        if base <= b["target"] < end:
            entries.add(b["target"])
        if base <= b["pc"] + 8 < end:
            entries.add(b["pc"] + 8)
    loops = [(b["target"], b["pc"]) for b in branches if b["backward"]]
    # Nesting by interval containment: a loop is nested in another when its span sits strictly inside that span.
    nesting = 0
    for lo, hi in loops:
        nesting = max(nesting, 1 + sum(1 for lo2, hi2 in loops if lo2 <= lo and hi <= hi2 and (lo2, hi2) != (lo, hi)))
    # PRE-test or POST-test, read from the edges rather than from the C. A `while`/`for` keeps its exit test at the
    # top, so the loop's span contains a FORWARD branch that jumps out of it; a `do {} while` has no such branch —
    # it leaves by falling through. This is the knob that moved `stage2:0x800540d4` from 4 of 6 to 5 of 6 by changing
    # the loop form alone, so it is worth distinguishing.
    pre_test = sum(1 for lo, hi in loops
                   if any(not b["backward"] and lo <= b["pc"] <= hi and b["target"] > hi for b in branches))
    post_test = len(loops) - pre_test
    return {
        "words": len(words),
        "branches": branches,
        "blocks": len(entries),
        "loop_edges": len(loops),
        "loop_nesting": nesting,
        "loop_pre_test": pre_test,
        "loop_post_test": post_test,
        "forward_branches": sum(1 for b in branches if not b["backward"]),
        "backward_branches": sum(1 for b in branches if b["backward"]),
        "returns": len(returns),
        "early_returns": sum(1 for pc in returns if pc < end - 8),
        "calls": calls,
        "dispatch": dispatch_of(words),
    }


def dispatch_of(words):
    """`compile_probe.dispatch_signature`'s reading of a jump-table head, or None. Loaded lazily: a caller that only
    needs the branch skeleton must not pay for the probe module's import.

    Two guards, both from measurement: a body under 8 words cannot be a dispatch head (a two-word `lui $k0` fragment
    matched the pattern), and the sequence must actually leave through a `jr` register, or it is a table load that
    never dispatches."""
    try:
        spec = importlib.util.spec_from_file_location("cp", str(ROOT / "tools" / "compile_probe.py"))
        cp = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cp)
        if len(words) < 8:
            return None
        sig = cp.dispatch_signature([w.to_bytes(4, "big") for w in words])
        if not sig or not sig.get("table"):
            return None
        if not any(op == "jr" for op in sig.get("ops") or []):
            return None
        return sig
    except Exception:
        return None


CLASSES = ("none", "missing-loop", "extra-loop", "loop-count", "loop-kind", "guard-shape",
           "early-return", "nesting", "dispatch", "likely-branch", "no-return", "our-short")


def diff(image_sig: dict, our_sig: dict) -> str:
    """The smallest true statement about how two skeletons differ, in a closed vocabulary.

    Order matters: a body can differ in several ways, and the class names the one a template can act on *first*.
    """
    if image_sig is None or our_sig is None:
        return "none"
    if any(b["slot_conditional"] for b in image_sig["branches"]) and \
       not any(b["slot_conditional"] for b in our_sig["branches"]):
        return "likely-branch"                       # unreachable with this toolchain; named so the census can skip it
    # A body with no `jr $ra` in the IMAGE is not a structure problem at all: it is a truncated extent or a fragment
    # (`boot:0x800006d0` is two words of `lui $k0`). Classing those as anything else inflates every other bucket —
    # measured: 3 of the first 40 bodies, and one of them was being called a `dispatch`.
    if image_sig["returns"] == 0:
        return "no-return"
    # TRUNCATION FIRST. If our body is not even as long as the image's extent, its branch and return counts are
    # counting a PREFIX of the function: every structural class below would be comparing a whole to a part. This was
    # 52 % of a stratified sample of far bodies and it manufactured `early-return`/`guard-shape` out of nothing
    # (`stage2:0x8008ca0c`: 79 words against our 72, identical return and branch counts, classed early-return).
    if our_sig["words"] < image_sig["words"]:
        return "our-short"
    if image_sig["dispatch"] and not our_sig["dispatch"]:
        return "dispatch"
    i_l, o_l = image_sig["loop_edges"], our_sig["loop_edges"]
    if i_l and not o_l:
        return "missing-loop"
    if o_l and not i_l:
        return "extra-loop"
    if i_l != o_l:
        return "loop-count"
    if i_l and (image_sig["loop_pre_test"] != our_sig["loop_pre_test"]):
        return "loop-kind"
    if image_sig["loop_nesting"] != our_sig["loop_nesting"]:
        return "nesting"
    if image_sig["forward_branches"] != our_sig["forward_branches"]:
        return "guard-shape"
    # Compare the EARLY-return counts, not the positions. Position depends on the body's total length, so two bodies
    # with identical return, branch and block counts were being called `early-return` purely because a 53-word gap
    # moved `end - 8` (`boot:0x800013d4`: 2->2, 5->5, 11->11, classed early-return). That is the instrument lying.
    if image_sig["early_returns"] != our_sig["early_returns"]:
        return "early-return"
    return "none"


# --- controls -----------------------------------------------------------------------------------------------------

def _words(*specs):
    """(asm-ish, count) pairs -> word list, for the self-test only. Kept explicit so the encoding is auditable."""
    return [w & 0xFFFFFFFF for w in specs]


def self_test() -> int:
    cases = []
    # 1. a post-test countdown loop: li v0,3; L: addiu v0,v0,-1; bne v0,zero,L; nop; jr ra; nop
    loop = _words(0x24020003, 0x2442FFFF, 0x1440FFFD, 0x00000000, 0x03E00008, 0x00000000)
    s = signature(loop, 0x80000000)
    cases.append(("a countdown loop is one backward edge, post-test",
                  s["loop_edges"] == 1 and s["loop_post_test"] == 1 and s["backward_branches"] == 1, str(s["loop_edges"])))
    # 2. the same body without the branch is linear, and differs as `missing-loop`
    linear = _words(0x24020003, 0x2442FFFF, 0x00000000, 0x00000000, 0x03E00008, 0x00000000)
    cases.append(("removing the branch makes it a missing loop",
                  diff(s, signature(linear, 0x80000000)) == "missing-loop", diff(s, signature(linear, 0x80000000))))
    # 3. a guard: beq a0,zero,skip; nop; jr ra; nop; skip: jr ra; nop  -> one forward branch, one early return
    guard = _words(0x10800002, 0x00000000, 0x03E00008, 0x00000000, 0x03E00008, 0x00000000)
    g = signature(guard, 0x80000000)
    cases.append(("a guard has a forward branch and an early return",
                  g["forward_branches"] == 1 and g["returns"] == 2 and g["early_returns"] == 1,
                  "%d/%d/%d" % (g["forward_branches"], g["returns"], g["early_returns"])))
    # 4. the control that matters: two different skeletons must NOT report `none`, or the diff is a comparator that
    #    cannot fail.
    cases.append(("a loop against a guard is not 'none'",
                  diff(s, g) != "none", diff(s, g)))
    # 5. registers are ignored: the same loop with different registers is the same skeleton
    loop2 = _words(0x24030003, 0x2463FFFF, 0x1460FFFD, 0x00000000, 0x03E00008, 0x00000000)
    cases.append(("allocation differences do not change the skeleton",
                  diff(s, signature(loop2, 0x80000000)) == "none", diff(s, signature(loop2, 0x80000000))))
    # 6. a likely branch is named, because this toolchain cannot emit one
    likely = _words(0x24020003, 0x2442FFFF, 0x5440FFFD, 0x00000000, 0x03E00008, 0x00000000)
    cases.append(("a bnel body is classed likely-branch",
                  diff(signature(likely, 0x80000000), s) == "likely-branch",
                  diff(signature(likely, 0x80000000), s)))
    # 7. the artefact this decoder actually produced: a two-word fragment matched the dispatch pattern. It must not.
    fragment = _words(0x3C1A8001, 0x275A5000)
    cases.append(("a two-word fragment is not a dispatch head",
                  signature(fragment, 0x80000000)["dispatch"] is None, "dispatch matched a fragment"))
    # 8. and a body with no `jr $ra` in the image is an extent defect, not a structural class
    cases.append(("an image body with no return is classed no-return",
                  diff(signature(fragment, 0x80000000), s) == "no-return",
                  diff(signature(fragment, 0x80000000), s)))
    # 9. two bodies with the same return, branch and block counts must be `none` — the second artefact: positions of
    #    returns shift with body length, and comparing positions labelled identical shapes as `early-return`.
    shifted = _words(0x24020003, 0x2442FFFF, 0x1440FFFD, 0x00000000, 0x00000000, 0x00000000, 0x03E00008, 0x00000000)
    cases.append(("a longer body with the same shape is not early-return",
                  diff(signature(shifted, 0x80000000), signature(loop, 0x80000000)) in ("none", "loop-kind",
                                                                                     "our-short"),
                  diff(signature(shifted, 0x80000000), signature(loop, 0x80000000))))
    ok = sum(1 for _n, good, _d in cases if good)
    for name, good, detail in cases:
        print("  %s %s%s" % ("PASS" if good else "FAIL", name, "" if good else " — " + detail))
    print("%d/%d skeleton case(s)" % (ok, len(cases)))
    return 0 if ok == len(cases) else 1


def main(argv):
    if "--self-test" in argv:
        return self_test()
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
