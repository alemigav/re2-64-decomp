#!/usr/bin/env python3
"""Pointer provenance, layer 1: what an address is, inside one function.

The two scanners this project already has answer a narrower question than the one that keeps being asked.
`find_readers.py` computes an address when it is **built in the same function** (`lui` + `ori`/`addiu`);
`xref_registry.py` adds pointers stored into globals and reloaded. Between them they cannot see a pointer
that spends the night in a **stack slot**, arrives as an **argument**, or comes back as a **return value**
— which is exactly where the four hand-composed-address incidents lived (M84/M86/M87/M94).

This file is step 1 of experiment B (`docs/format_notes.md`, "Experiments B and C: scoped, not done"): the
intra-procedural dataflow, and nothing else. Specifically:

  * an abstract value per register and per stack slot — `const(addr)`, `param(k)`, `ret(fn)`, `load`, `unk`;
  * a real **CFG per function** with a merge at every join (a value survives a join only if every predecessor
    agrees), because a linear scan that ignores branches is the unsoundness that produced 167 false
    near-misses (M95);
  * **invalidate on loads**: a loaded register is `load`, never a stale constant — the same rule that bug
    violated;
  * caller-saved clobber across `jal`/`jalr`, and `v0 = ret(target)` recorded but **deliberately not
    resolved**: cross-function resolution is step 2 and is forbidden until this fixture is 10/10.

The fixture is synthetic MIPS with hand-computed answers, in the spirit of `test_harness.py`: each case is a
mistake this project actually made, or a merge rule that a linear scan would get wrong.

Usage:
  ./provenance.py --self-test
  ./provenance.py --target 0x800eb260 [--window 0x10]     # accesses to a window, with their abstract base
  ./provenance.py --census [--json manifests/provenance.json]
"""
import argparse
import json
import struct
import sys
from pathlib import Path

CALLER_SAVED = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 31}
ZERO, V0, SP, RA = 0, 2, 29, 31

CONST = "const"
PARAM = "param"
RET = "ret"
LOAD = "load"
UNK = "unk"

LOADS = {0x23: "lw", 0x24: "lbu", 0x25: "lhu", 0x21: "lh", 0x37: "ld", 0x1F: "lwu"}
STORES = {0x2B: "sw", 0x28: "sb", 0x29: "sh", 0x3F: "sd"}
BRANCHES = {0x01, 0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17}

U = (UNK, 0)


def sext16(imm):
    return imm - 0x10000 if imm >= 0x8000 else imm


def fmt(v):
    kind, a = v
    if kind == CONST:
        return "const(%08x)" % a
    if kind == PARAM:
        return "param(a%d)" % a
    if kind == RET:
        return "ret(%08x)" % a
    return kind


class Instr:
    __slots__ = ("pc", "word", "op", "rs", "rt", "rd", "sa", "imm", "simm")

    def __init__(self, pc, word):
        self.pc, self.word = pc, word
        self.op = (word >> 26) & 0x3F
        self.rs = (word >> 21) & 0x1F
        self.rt = (word >> 16) & 0x1F
        self.rd = (word >> 11) & 0x1F
        self.sa = (word >> 6) & 0x1F
        self.imm = word & 0xFFFF
        self.simm = sext16(self.imm)

    @property
    def funct(self):
        return self.word & 0x3F

    @property
    def name(self):
        if self.op == 0x0F:
            return "lui"
        if self.op == 0x0D:
            return "ori"
        if self.op in (0x08, 0x09, 0x18, 0x19):
            return {0x08: "addi", 0x09: "addiu", 0x18: "daddi", 0x19: "daddiu"}[self.op]
        if self.op in LOADS:
            return LOADS[self.op]
        if self.op in STORES:
            return STORES[self.op]
        if self.op == 0x03:
            return "jal"
        if self.op == 0x02:
            return "j"
        if self.op == 0x00:
            return {0x21: "addu", 0x2D: "daddu", 0x25: "or", 0x23: "subu", 0x08: "jr",
                    0x09: "jalr", 0x02: "srl", 0x00: "nop"}.get(self.funct, "special:0x%02x" % self.funct)
        if self.op in BRANCHES:
            return "branch:0x%02x" % self.op
        return "op:0x%02x" % self.op


class State:
    """Abstract state: register -> value, stack offset -> value, plus the accesses seen so far."""

    __slots__ = ("reg", "slot")

    def __init__(self, reg=None, slot=None):
        self.reg = dict(reg or {})
        self.slot = dict(slot or {})

    def copy(self):
        return State(self.reg, self.slot)

    def __eq__(self, other):
        return self.reg == other.reg and self.slot == other.slot

    def merge(self, other):
        """A value survives a join only if both predecessors agree; otherwise it becomes unknown."""
        out = State()
        for k in set(self.reg) | set(other.reg):
            a, b = self.reg.get(k, U), other.reg.get(k, U)
            out.reg[k] = a if a == b else U
        for k in set(self.slot) | set(other.slot):
            a, b = self.slot.get(k, U), other.slot.get(k, U)
            out.slot[k] = a if a == b else U
        return out

    def get(self, r):
        if r == ZERO:
            return (CONST, 0)                    # $zero is a constant, not an unknown
        return self.reg.get(r, U)

    def put(self, r, v):
        if r == ZERO:
            return
        self.reg[r] = v


class Access:
    __slots__ = ("pc", "name", "base", "offset", "target", "unreached")

    def __init__(self, pc, name, base, offset, unreached=False):
        self.pc, self.name, self.base, self.offset = pc, name, base, offset
        self.target = base[1] + offset if base[0] == CONST else None
        self.unreached = unreached

    def attributed(self):
        return self.target is not None

    def __str__(self):
        if self.target is not None:
            return "%08x  %-4s %08x  [%s%+d] attributed" % (self.pc, self.name, self.target,
                                                            fmt(self.base), self.offset)
        return "%08x  %-4s      -     [%s%+d] unrecognised base" % (self.pc, self.name,
                                                                    fmt(self.base), self.offset)


def transfer(state, ins, accesses):
    """Apply one instruction. Returns (state, kind) where kind is None | 'branch' | 'jump' | 'return'."""
    op, rs, rt, rd = ins.op, ins.rs, ins.rt, ins.rd
    if op == 0x0F:                                              # lui
        state.put(rt, (CONST, (ins.imm << 16) & 0xFFFFFFFF))
        return state, None
    if op == 0x0D:                                              # ori
        base = state.get(rs)
        state.put(rt, (CONST, base[1] | ins.imm) if base[0] == CONST else U)
        return state, None
    if op in (0x08, 0x09, 0x18, 0x19):                          # addi/addiu/daddi/daddiu
        base = state.get(rs)
        if base[0] == CONST:
            state.put(rt, (CONST, (base[1] + ins.simm) & 0xFFFFFFFF))   # immediate is SIGNED
        elif rs == ZERO:
            state.put(rt, (CONST, ins.simm & 0xFFFFFFFF))              # li rt, imm
        else:
            state.put(rt, U)
        return state, None
    if op == 0x00:
        f = ins.funct
        if f == 0x00:
            return state, None
        if f in (0x21, 0x2D):                                   # addu / daddu: also `move rd, rs`
            a, b = state.get(rs), state.get(rt)
            if a[0] == CONST and b[0] == CONST:
                state.put(rd, (CONST, (a[1] + b[1]) & 0xFFFFFFFF))
            elif b == (CONST, 0):
                state.put(rd, a)
            elif a == (CONST, 0):
                state.put(rd, b)
            else:
                state.put(rd, U)
            return state, None
        if f == 0x25:                                           # or
            a, b = state.get(rs), state.get(rt)
            if a[0] == CONST and b[0] == CONST:
                state.put(rd, (CONST, a[1] | b[1]))
            elif b == (CONST, 0):
                state.put(rd, a)
            elif a == (CONST, 0):
                state.put(rd, b)
            else:
                state.put(rd, U)
            return state, None
        if f == 0x23:                                           # subu
            a, b = state.get(rs), state.get(rt)
            state.put(rd, (CONST, (a[1] - b[1]) & 0xFFFFFFFF) if a[0] == b[0] == CONST else U)
            return state, None
        if f == 0x08:                                           # jr
            return state, "return" if rs == RA else "jump"
        if f == 0x09:                                           # jalr: unknown target
            for r in CALLER_SAVED:
                state.put(r, U)
            state.put(V0, (RET, 0))
            return state, "call"
        state.put(rd, U)
        return state, None
    if op in LOADS:
        offset = ins.simm                                       # lw offsets are SIGN-EXTENDED
        base = state.get(rs)
        accesses.append(Access(ins.pc, ins.name, base, offset))
        if rs == SP and ins.simm in state.slot:                  # reload from a tracked stack slot
            v = state.slot[ins.simm]
        elif base[0] == CONST:
            v = (LOAD, base[1] + offset)                         # concrete address, unknown contents
        else:
            v = U
        state.put(rt, v)
        return state, None
    if op in STORES:
        base = state.get(rs)
        accesses.append(Access(ins.pc, ins.name, base, ins.simm))
        if rs == SP:
            state.slot[ins.simm] = state.get(rt)                 # spilled value is remembered
        return state, None
    if op == 0x03:                                              # jal
        return state, "call"
    if op == 0x02:
        return state, "jump"
    if op in BRANCHES:
        return state, "branch"
    state.put(rt, U)                                            # anything unmodelled writes rt
    return state, None


def build_cfg(words, base):
    """Basic blocks over one function's words; leaders are the entry, branch targets and branch tails."""
    n = len(words)
    ins = [Instr(base + 4 * i, words[i]) for i in range(n)]
    leaders = {0}
    for i, x in enumerate(ins):
        kind = None
        if x.op in BRANCHES:
            target = i + 1 + x.simm
            if 0 <= target < n:
                leaders.add(target)
            leaders.add(min(i + 2, n))
        elif x.op in (0x02, 0x03) or (x.op == 0x00 and x.funct in (0x08, 0x09)):
            leaders.add(min(i + 2, n))
        elif x.op == 0x00 and x.funct == 0x08 and x.rs == RA:
            leaders.add(min(i + 2, n))
    starts = sorted(i for i in leaders if i < n)
    blocks = {}
    for bi, s in enumerate(starts):
        e = starts[bi + 1] if bi + 1 < len(starts) else n
        blocks[s] = {"end": e, "succ": set()}
    for s, b in blocks.items():
        i, last = s, None
        while i < b["end"]:
            last = i
            if ins[i].op in BRANCHES or ins[i].op in (0x02, 0x03) or \
               (ins[i].op == 0x00 and ins[i].funct in (0x08, 0x09)):
                break
            i += 1
        if last is None:
            continue
        x = ins[last]
        nxt = b["end"]
        if x.op in BRANCHES:
            t = last + 1 + x.simm
            for cand in (last + 2, t):
                if cand in blocks:
                    b["succ"].add(cand)
        elif x.op == 0x02:
            t = ((x.pc + 4) & 0xF0000000) | (x.imm << 2)
            t = (t - base) // 4
            if t in blocks:
                b["succ"].add(t)
        elif x.op == 0x03:
            t = last + 2
            if t in blocks:
                b["succ"].add(t)
        elif x.op == 0x00 and x.funct in (0x08, 0x09):
            pass
        else:
            if nxt in blocks:
                b["succ"].add(nxt)
    return ins, blocks


def _apply_call(state, ins, accesses):
    """A call clobbers caller-saved registers and leaves `ret(target)` in v0."""
    for r in CALLER_SAVED:
        state.put(r, U)
    target = (((ins.pc + 4) & 0xF0000000) | (ins.imm << 2)) if ins.op == 0x03 else 0
    state.put(V0, (RET, target))
    accesses.append(Access(ins.pc, "jal" if ins.op == 0x03 else "jalr", (RET, target), 0))


def _walk(state, ins, s, e, accesses, tag_unreached=False):
    """Run one basic block, honouring MIPS delay slots. Returns the outgoing state."""
    cur = state.copy()
    found = []
    for i in range(s, e):
        _, kind = transfer(cur, ins[i], found)
        if kind is None:
            continue
        delay = i + 1
        if delay < len(ins):                                 # the delay slot ALWAYS executes
            transfer(cur, ins[delay], found)
        if kind == "call":
            _apply_call(cur, ins[i], found)
        if tag_unreached:
            for a in found:
                a.unreached = True
        accesses.extend(found)
        return cur
    if tag_unreached:
        for a in found:
            a.unreached = True
    accesses.extend(found)
    return cur


def analyse(words, base):
    """Fixpoint over the CFG, then ONE collection pass so accesses are reported once each."""
    if not words:
        return [], 0, 0
    ins, blocks = build_cfg(words, base)
    state_in = {s: None for s in blocks}
    entry = State()
    for k in range(4):                                   # a0-a3: NAMED here, resolved only in step 2
        entry.put(4 + k, (PARAM, k))
    state_in[0] = entry
    sink = []
    changed, rounds = True, 0
    while changed and rounds < 200:
        changed, rounds = False, rounds + 1
        for s in sorted(blocks):
            if state_in[s] is None:
                continue
            out = _walk(state_in[s], ins, s, blocks[s]["end"], sink)
            for t in blocks[s]["succ"]:
                merged = out if state_in[t] is None else state_in[t].merge(out)
                if state_in[t] is None or merged != state_in[t]:
                    state_in[t] = merged
                    changed = True
    accesses = []
    for s in sorted(blocks):
        if state_in[s] is None:
            # no entry state reached this block (indirect jump, unresolved edge): count its operands
            # as `unreached` so the totals reconcile instead of quietly vanishing
            _walk(State(), ins, s, blocks[s]["end"], accesses, tag_unreached=True)
        else:
            _walk(state_in[s], ins, s, blocks[s]["end"], accesses)
    # attribution requires BOTH: a constant base AND a block we can prove is reachable. An unreached
    # block still develops constants locally, and counting those as attributed made the published
    # attributed total (2910) exceed the `const` bucket (1293) — two numbers for one question.
    attributed = sum(1 for a in accesses if a.attributed() and not a.unreached)
    return accesses, attributed, rounds


# --------------------------------------------------------------------------------------------- fixtures
def enc_lui(rt, imm):        return (0x0F << 26) | (rt << 16) | (imm & 0xFFFF)
def enc_ori(rt, rs, imm):    return (0x0D << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
def enc_addiu(rt, rs, imm):  return (0x09 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)
def enc_lw(rt, off, rs):     return (0x23 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_sw(rt, off, rs):     return (0x2B << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_addu(rd, rs, rt):    return (rs << 21) | (rt << 16) | (rd << 11) | 0x21
def enc_jal(target):         return (0x03 << 26) | ((target >> 2) & 0x03FFFFFF)
def enc_jr(rs):              return (rs << 21) | 0x08
def enc_beq(rs, rt, off):    return (0x04 << 26) | (rs << 21) | (rt << 16) | (off & 0xFFFF)
def enc_nop():               return 0


BASE = 0x80001000


def fixture_cases():
    """Ten cases. Each returns (name, words, predicate over (accesses, attributed))."""

    def base_addr(a):
        return a[0][0] if a else None

    cases = []

    w = [enc_lui(2, 0x800E), enc_ori(2, 2, 0xB204), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("1 lui+ori builds a constant and the load through it is attributed",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB204))

    w = [enc_lui(2, 0x800C), enc_addiu(2, 2, -23464), enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("2 addiu immediate is signed: 0x800c0000 - 23464 = 0x800ba458",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800BA458))

    w = [enc_lui(2, 0x800F), enc_lw(3, 0xB264, 2), enc_jr(RA), enc_nop()]
    cases.append(("3 lw offset is sign-extended: 0x800f0000 + sext(0xb264) = 0x800eb264",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB264))

    w = [enc_addiu(SP, SP, -32), enc_sw(5, 0x10, SP), enc_lw(3, 0x10, SP),
         enc_lw(4, 0, 3), enc_jr(RA), enc_nop()]
    cases.append(("4 a value spilled to the stack and reloaded keeps its provenance",
                  w, lambda acc, n: len(acc) == 3 and acc[2].base == (PARAM, 1)))

    w = [enc_lw(3, 8, 4), enc_jr(RA), enc_nop()]
    cases.append(("5 a parameter used as a base is reported as param, not unknown",
                  w, lambda acc, n: n == 0 and acc[0].base == (PARAM, 0)))

    w = [enc_lui(8, 0x8011), enc_lw(8, 0, 4), enc_lw(3, 0, 8), enc_jr(RA), enc_nop()]
    cases.append(("6 a load invalidates the register: no stale constant survives it",
                  w, lambda acc, n: n == 0 and acc[1].base == U and acc[1].target is None))

    w = [enc_lui(8, 0x8011), enc_jal(0x80002000), enc_nop(), enc_lw(3, 0, 8), enc_jr(RA), enc_nop()]
    cases.append(("7 call clobbers caller-saved: t0 is dead after jal",
                  w, lambda acc, n: n == 0 and acc[1].base == U
                  and any(a.name == "jal" and a.base == (RET, 0x80002000) for a in acc)))

    w = [enc_beq(4, 0, 2), enc_nop(), enc_lui(2, 0x8011),
         enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("8 a join disagrees, so the value becomes unknown",
                  w, lambda acc, n: n == 0 and acc[0].target is None))

    w = [enc_lui(2, 0x800E), enc_ori(2, 2, 0xB204), enc_beq(4, 0, 1), enc_nop(),
         enc_lw(3, 0, 2), enc_jr(RA), enc_nop()]
    cases.append(("9 a join where both paths agree keeps the constant",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x800EB204))

    w = [enc_addiu(2, ZERO, 0x1234), enc_addu(3, 2, ZERO), enc_lw(4, 0, 3), enc_jr(RA), enc_nop()]
    cases.append(("10 li + move preserve the constant",
                  w, lambda acc, n: n == 1 and acc[0].target == 0x1234))

    return cases


def self_test():
    passed = 0
    cases = fixture_cases()
    for name, words, check in cases:
        accesses, attributed, _ = analyse(words, BASE)
        try:
            ok = bool(check(accesses, attributed))
        except Exception as exc:                                # a fixture may legitimately run out of data
            ok = False
            print("    exception in the check: %r" % exc)
        print("%s  %s" % ("PASS" if ok else "FAIL", name))
        if not ok:
            for a in accesses:
                print("      %s  (%s)" % (a, fmt(a.base)))
        passed += 1 if ok else 0
    total = len(cases)
    print("\n%d/%d" % (passed, total))
    if total != 10:
        print("the fixture must contain exactly 10 cases; it has %d" % total)
        return 1
    return 0 if passed == total else 1


# --------------------------------------------------------------------------------------------- real images
def load_images(manifest="build/elfs/images.json"):
    data = json.loads(Path(manifest).read_text())
    cart_sha = data.get("cart_sha256")
    rom = Path("rom/Resident Evil 2 (USA) (Rev 1).z64")
    if not rom.exists():
        sys.exit("cartridge not found at %s" % rom)
    blob = rom.read_bytes()
    import hashlib
    if hashlib.sha256(blob).hexdigest() != cart_sha:
        sys.exit("cartridge sha256 does not match the manifest — refusing to analyse")
    return [(im["name"], im["base"], im["size"]) for im in data["images"]], blob


def image_words(blob, base, size):
    off = base - 0x7FFFF480
    raw = blob[off:off + size]
    return list(struct.unpack(">%dI" % (len(raw) // 4), raw[:len(raw) // 4 * 4]))


def function_bounds(words):
    """Region boundaries: a prologue (`addiu sp,sp,-N`) or the instruction after a `jr ra`.

    An earlier version cut each function at its first `jr ra`, which silently **dropped every leaf
    function** — code after a `jr ra` with no prologue of its own got no entry state, so nothing in it
    was ever analysed. That was visible as a suspicious zero at a target the boot code demonstrably
    reaches. Both boundaries are heuristics; the honest statement is that they delimit *regions*, not
    proven functions.
    """
    starts = {0}
    for i, w in enumerate(words):
        if (w >> 26) == 0x09 and ((w >> 21) & 0x1F) == SP and ((w >> 16) & 0x1F) == SP \
                and sext16(w & 0xFFFF) < 0:
            starts.add(i)                                        # prologue
        if i > 0 and words[i - 1] == 0x03E00008 and i < len(words):
            starts.add(i)                                        # code after `jr ra`: likely an entry
    starts = sorted(s for s in starts if s < len(words))
    bounds = []
    for bi, s in enumerate(starts):
        e = starts[bi + 1] if bi + 1 < len(starts) else len(words)
        bounds.append((s, e))
    return bounds


def run_images(target=None, window=0x10, census=False, out=None):
    images, blob = load_images()
    report = {"images": [], "target": None}
    for name, base, size in images:
        words = image_words(blob, base, size)
        total_acc = attr = 0
        kinds = {}
        for s, e in function_bounds(words):
            accesses, attributed, _ = analyse(words[s:e], base + 4 * s)
            total_acc += len(accesses)
            attr += attributed
            for a in accesses:
                if a.unreached:
                    k = "unreached+const" if a.base[0] == CONST else "unreached"
                else:
                    k = a.base[0]
                kinds[k] = kinds.get(k, 0) + 1
            if target is not None:
                for a in accesses:
                    if a.target is not None and target <= a.target < target + window:
                        print("%-8s %08x  %-4s %08x  base=%s%+d" % (
                            name, a.pc, a.name, a.target, fmt(a.base), a.offset))
                        report["target"] = report["target"] or []
                        report["target"].append({"image": name, "pc": a.pc, "op": a.name,
                                                 "target": a.target})
        report["images"].append({"image": name, "accesses": total_acc, "attributed": attr,
                                 "unattributed": total_acc - attr,
                                 "bases": dict(kinds)})
        if census:
            print("%-10s %6d memory operands, %6d attributed (%.1f%%), %6d unrecognised" % (
                name, total_acc, attr, 100.0 * attr / max(total_acc, 1), total_acc - attr))
    tot = sum(r["accesses"] for r in report["images"])
    at = sum(r["attributed"] for r in report["images"])
    dist = {}
    for r in report["images"]:
        for k, v in r["bases"].items():
            dist[k] = dist.get(k, 0) + v
    print("base kinds: " + ", ".join("%s %d" % (k, v) for k, v in sorted(dist.items(), key=lambda x: -x[1])))
    print("\n%d images: %d memory operands, %d attributed (%.1f%%), %d unrecognised "
          "(parameters, loaded bases, returns — step 2's input)" % (
              len(images), tot, at, 100.0 * at / max(tot, 1), tot - at))
    if out:
        Path(out).parent.mkdir(parents=True, exist_ok=True)
        Path(out).write_text(json.dumps(report, indent=1) + "\n")
        print("wrote %s" % out)
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--target", type=lambda s: int(s, 0))
    ap.add_argument("--window", type=lambda s: int(s, 0), default=0x10)
    ap.add_argument("--census", action="store_true")
    ap.add_argument("--json", default="manifests/provenance.json")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    return run_images(args.target, args.window, args.census or args.target is None, args.json)


if __name__ == "__main__":
    raise SystemExit(main())
