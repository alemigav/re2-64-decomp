"""Decode the RSP program the audio task hands the RCP, and say exactly what that buys.

`FUN_800a2e40` fills a task block at `0x80143c60` whose +0x10/+0x14 pair names `0x800b2700` and `0x1000`
(both folded out of `lui`/`addiu` pairs: no word of stage-2 contains the literal `0x800b2700`). The 4 096
bytes there are 1 024 words, and they are **not all program**: the project's own corpus declares a CPU
function at `0x800b3640`, 0xC0 bytes before the window ends, so the RSP program is the first 976 words and
the rest is the head of `FUN_800b3640` — the stride-0x1228 voice walk from M222. The declared size is IMEM's
capacity, not the code's length, and the overrun is recorded rather than corrected.

**What this decoder claims.** Four things, and nothing else:

  * **The word grid and the address rule.** An RSP program is 32-bit words in 4 KB of IMEM, so the program
    counter is 12 bits (Programming Manual p44: "The IMEM and DMEM are both 4 KB"). A `jal`/`j` therefore
    carries an absolute **IMEM offset** — `(instr_index << 2) & 0xFFF` — and is *not* PC-relative, while a
    branch is `PC + 4 + (offset << 2)`, also inside IMEM. This is measured: all 49 jump fields in the program
    have raw `instr_index << 2` inside one 4 KB page (`0x0400112c`-`0x04001eb4`), so the page bits carry no
    target information; unmasked, every one of them lies outside a 4 KB IMEM.
  * **The scalar subset's mnemonics**, as the *family* the manual names and nothing more: p44 says "The SU
    implements a subset of the R4000 instruction set" and p47 names the R4000 manual as that family's authority.
    Every scalar mnemonic is labelled `family` for that reason, with the page that delegates to it.
  * **DMEM-only data addressing**, from p139 ("The RSP software can only access DMEM") and p44 (4 KB of it):
    the 16-bit displacement of every `lw`/`sw`/`lhu`/… is a DMEM offset, and all 106 of them in this program
    land inside DMEM (max 0xd5c). `lwc2`/`swc2` move 128-bit rows between DMEM and the vector unit (p44: "The
    VU has eight 16-bit elements"); their immediate is a *different* field and is excluded from those counts.
  * **Control flow and boundaries**: entry at IMEM 0, the 19 `jal` targets as the other function roots, `jr`
    as returns, and every one of the 976 words either inside a function body, inside a listed gap, or
    accounted for as CPU code.

**What it refuses.** This repository holds no table of RSP encodings. The local manual settles the RSP's
*structure* (4 KB IMEM/DMEM p44, the SU's family p44/p47, DMEM-only data p139, physical addressing and the
16-entry segment table p47, the boot/task two-stage load p137) but tabulates **no opcode, no function code
and no COP2 encoding**. So:

  * the **vector unit's 254 words are identified and never named** — the function code is reported raw and the
    mnemonic is `null`, because the only way to name `4a00002c` would be to import a table this project does
    not hold. `unreadable` lists all 31 distinct field patterns with counts and first addresses. libdragon's
    `src/audio/rsp_mixer.S` was read as a *reference* for which instruction families real audio ucode uses,
    and it changed nothing here: it is a different, modern design and no byte of this cartridge is evidence
    about it or from it;
  * **COP0 register numbers are unnamed** — the SP register map is in no local document. `mfc0 a1,<reg 7>` is
    decoded as a COP0 move (family) with the number raw; the five repeated write-three-then-poll-a-fourth
    blocks are described by *shape* and no direction is asserted;
  * **no DMEM offset, no command opcode and no mixer behaviour is named.** The program's DMEM layout is its
    own; nothing on the CPU side mirrors it, which is why the same facts appear under `rsp_only`. A decoded
    RSP program is not an understood mixer.

The task block is re-derived, not quoted: every field is folded out of the instruction that stores it and
`--check` re-runs the fold, including `lui v0,0x800b` + `addiu v0,v0,0x2700` = 0x800b2700 and
`subu` of two folded halves = 0xd0.

Usage:
  ./rsp_decode.py --write     # regenerate manifests/rsp_ucode.json from the image
  ./rsp_decode.py --check     # validate the committed artefact against a fresh derivation
  ./rsp_decode.py --disasm    # print the listing this decoder claims (all 1 024 words)
"""
import argparse
import hashlib
import json
import math
import re
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

IMAGE = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
OUT = Path("manifests") / "rsp_ucode.json"

STAGE2_BASE = 0x80018A80          # the stage-2 member loads here (checkpoint/memory_regions.json)
TASK_BLOCK = 0x80143C60           # the audio task block FUN_800a2e40 fills
UCODE_VA = 0x800B2700             # task+0x10, the field this whole file is about
UCODE_SIZE = 0x1000               # task+0x14
TASK_WRITER = 0x800A2E40          # FUN_800a2e40: the only function that writes the block

SCHEMA = "rsp-ucode/1"
CORPUS = "src/stage2"
CORPUS_ADDR = re.compile(r"^ \* address (0x[0-9a-f]+)", re.M)
MANUAL = "docs/Nintendo_64_Programming_Manual_NU6-06-0030-001G_HQ.pdf"
MANUAL_PAGES = 534

# Every citation is a page of the local manual plus the sentence that page actually contains. The sentences
# were read out of the PDF's own text layer (PDFKit, 534 pp — `swiftc -O` a 20-line PDFDocument.string dump);
# none is paraphrased, and `--check` refuses a citation whose page is outside the manual or whose key is used
# without being defined here.
CITES = {
    "imem_dmem_4k": (44, "The IMEM and DMEM are\nboth 4 KB."),
    "su_r4000": (44, "The SU implements a\nsubset of the R4000 instruction set."),
    "vu_elements": (44, "The VU\nhas eight 16-bit elements."),
    "rsp_physical": (47, "The RSP hardware uses physical addresses."),
    "rsp_segments": (47, "Bits 24 through 27 of the segmented address are used to index into a 16-entry table"),
    "r4000_authority": (47, "see the MIPS Microprocessor R4000 User\u2019s Manual"),
    "task_pc0": (137, "the R4300 sets the RSP PC to 0."),
    "task_boot_ucode": (137, "the boot microcode takes over, loading the task microcode\n(and data) specified in the task list, and jumping to the beginning of the task."),
    "dmem_only": (139, "The RSP software can only access DMEM."),
    "dma_64bit": (139, "All data must first be transferred\ninto DMEM using DMA operations, which must be 64-bit aligned."),
}

# The rule the manifest states for every branch and jump the decoder follows.
ADDRESS_RULE = ("jal and j carry an absolute IMEM offset, not a PC-relative one: the RSP program counter is "
                "12 bits because IMEM is 4 KB (p44), so the target is (instr_index << 2) & 0xFFF. Measured, not "
                "assumed: all 49 jump fields in the program have raw instr_index<<2 inside one 4 KB page "
                "(0x0400112c-0x04001eb4), so the page bits are constant and carry no target information; "
                "unmasked, every one of the 49 lies outside a 4 KB IMEM. Branches are the opposite: PC + 4 + (offset<<2), "
                "also truncated to IMEM.")

FOLD_RULE = ("A stage-2 address is folded from the instructions that write the register before the store: "
             "`lui rt,imm16` sets rt = imm16 << 16, `addiu rt,rt,imm16` / `ori rt,rt,imm16` adds the low half, and "
             "`subu` folds when both halves are known. The fold records the instructions it used and --check "
             "re-derives it; no word of stage-2 contains the literal 0x800b2700 (0 occurrences), so the fold is "
             "the only evidence for the pointer.")

# Register names are the family's (p44/p47 name the R4000); the RSP has no names of its own in any local
# document, and r0 reads as zero everywhere.
REG = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

# Family label: the mnemonic comes from the R4000/MIPS III table that p44 ("a subset of the R4000 instruction
# set") and p47 ("see the MIPS Microprocessor R4000 User's Manual") name for the SU. It is *not* a citation of
# an encoding this project holds, and the manifest says so per entry.
FAMILY = "family"

# --- scalar encodings -----------------------------------------------------------------------------------
# (mnemonic, form). Form decides the operand rendering. `family` entries are the SU's R4000 subset.
SPECIAL = {
    0x00: ("sll", "shift"),
    0x02: ("srl", "shift"),
    0x03: ("sra", "shift"),
    0x06: ("srlv", "R"),
    0x08: ("jr", "jr"),
    0x0D: ("break", "break"),
    0x21: ("addu", "R"),
    0x23: ("subu", "R"),
    0x24: ("and", "R"),
    0x25: ("or", "R"),
    0x2A: ("slt", "R"),
    0x2B: ("sltu", "R"),
}
REGIMM = {0x00: "bltz", 0x01: "bgez", 0x10: "bltzal", 0x11: "bgezal"}

# opcode -> (mnemonic, form, cite)
OPCODES = {
    0x02: ("j", "J", "task_pc0"),
    0x03: ("jal", "J", "task_pc0"),
    0x04: ("beq", "branch2", "imem_dmem_4k"),
    0x05: ("bne", "branch2", "imem_dmem_4k"),
    0x06: ("blez", "branch1", "imem_dmem_4k"),
    0x07: ("bgtz", "branch1", "imem_dmem_4k"),
    0x09: ("addiu", "imm", "su_r4000"),
    0x0B: ("sltiu", "imm", "su_r4000"),
    0x0C: ("andi", "imm", "su_r4000"),
    0x0D: ("ori", "imm", "su_r4000"),
    0x0E: ("xori", "imm", "su_r4000"),
    0x0F: ("lui", "lui", "su_r4000"),
    0x10: ("cop0", "cop0", "rsp_physical"),
    0x12: ("cop2", "cop2", "vu_elements"),
    0x23: ("lw", "load", "dmem_only"),
    0x24: ("lbu", "load", "dmem_only"),
    0x25: ("lhu", "load", "dmem_only"),
    0x28: ("sb", "store", "dmem_only"),
    0x29: ("sh", "store", "dmem_only"),
    0x2B: ("sw", "store", "dmem_only"),
    0x32: ("lwc2", "cop2xfer", "vu_elements"),
    0x3A: ("swc2", "cop2xfer", "vu_elements"),
}

# Opcodes whose *existence* on the SU this repository cannot settle. They are decoded into their family shape
# for the listing, then listed in `unreadable` instead of being counted as understood instructions.
UNSETTLED = {
    0x14: ("beql", "the R4000 name of this shape is `beql`, a branch-likely; the local manual does not settle "
                   "whether the SU implements the branch-likely class, so the two words are listed, not assumed"),
}


def bits(word, hi, lo):
    return (word >> lo) & ((1 << (hi - lo + 1)) - 1)


def sx16(v):
    return v - 0x10000 if v & 0x8000 else v


def imem_target(word):
    """(raw, masked) for a J-form instruction: raw is the plain MIPS reading, masked the 12-bit IMEM offset."""
    raw = (word & 0x3FFFFFF) << 2
    return raw, raw & 0xFFF


def decode(word, va):
    """One word -> a decode record. Never names anything the local authority cannot support."""
    op = bits(word, 31, 26)
    rec = {"at": va, "word": word, "opcode": op, "mnemonic": None, "text": None,
           "cite": None, "status": FAMILY}
    if op == 0x00:
        funct = bits(word, 5, 0)
        if funct == 0x00 and word == 0:
            rec.update(mnemonic="nop", text="nop", cite="su_r4000")
            return rec
        if funct not in SPECIAL:
            return _unreadable(rec, "SPECIAL funct 0x%02x" % funct)
        mn, form = SPECIAL[funct]
        rs, rt, rd = bits(word, 25, 21), bits(word, 20, 16), bits(word, 15, 11)
        if form == "shift":
            rd, rt, sa = bits(word, 15, 11), bits(word, 20, 16), bits(word, 10, 6)
            rec.update(mnemonic=mn, text="%s %s,%s,%d" % (mn, REG[rd], REG[rt], sa), cite="su_r4000")
        elif form == "jr":
            rec.update(mnemonic=mn, text="jr %s" % REG[rs], cite="su_r4000",
                       jump_reg=rs, indirect=(rs != 31))
        elif form == "break":
            rec.update(mnemonic=mn, text="break", cite="su_r4000")
        else:
            rec.update(mnemonic=mn, text="%s %s,%s,%s" % (mn, REG[rd], REG[rs], REG[rt]), cite="su_r4000")
        return rec
    if op == 0x01:
        rt = bits(word, 20, 16)
        if rt not in REGIMM:
            return _unreadable(rec, "REGIMM rt 0x%02x" % rt)
        mn = REGIMM[rt]
        rs = bits(word, 25, 21)
        tgt = (va + 4 + (sx16(word & 0xFFFF) << 2)) & 0xFFF
        rec.update(mnemonic=mn, text="%s %s,0x%03x" % (mn, REG[rs], tgt), cite="imem_dmem_4k",
                   branch_target=tgt)
        return rec
    if op in (0x02, 0x03):
        mn = OPCODES[op][0]
        raw, masked = imem_target(word)
        rec.update(mnemonic=mn, text="%s 0x%03x" % (mn, masked), cite="task_pc0",
                   jump_target=masked, target_raw=raw)
        return rec
    if op in (0x04, 0x05, 0x06, 0x07):
        mn, form, cite = OPCODES[op]
        rs, rt = bits(word, 25, 21), bits(word, 20, 16)
        tgt = (va + 4 + (sx16(word & 0xFFFF) << 2)) & 0xFFF
        if form == "branch2":
            text = "%s %s,%s,0x%03x" % (mn, REG[rs], REG[rt], tgt)
        else:
            text = "%s %s,0x%03x" % (mn, REG[rs], tgt)
        rec.update(mnemonic=mn, text=text, cite=cite, branch_target=tgt)
        return rec
    if op in (0x09, 0x0B, 0x0D):
        mn = OPCODES[op][0]
        rs, rt, imm = bits(word, 25, 21), bits(word, 20, 16), sx16(word & 0xFFFF)
        rec.update(mnemonic=mn, text="%s %s,%s,%d" % (mn, REG[rt], REG[rs], imm), cite="su_r4000")
        return rec
    if op in (0x0C, 0x0E):
        mn = OPCODES[op][0]
        rs, rt = bits(word, 25, 21), bits(word, 20, 16)
        rec.update(mnemonic=mn, text="%s %s,%s,0x%04x" % (mn, REG[rt], REG[rs], word & 0xFFFF),
                   cite="su_r4000")
        return rec
    if op == 0x0F:
        rt = bits(word, 20, 16)
        rec.update(mnemonic="lui", text="lui %s,0x%04x" % (REG[rt], word & 0xFFFF), cite="su_r4000")
        return rec
    if op == 0x10:
        # COP0 move: the *kind* is family; the SP register's identity is in no local document, so `reg` is
        # reported raw and given no name.
        rs, rt, rd = bits(word, 25, 21), bits(word, 20, 16), bits(word, 15, 11)
        kind = {0x00: "mfc0", 0x04: "mtc0"}.get(rs)
        if kind is None:
            return _unreadable(rec, "COP0 rs 0x%02x" % rs)
        rec.update(mnemonic=kind, text="%s %s,<sp reg %d>" % (kind, REG[rt], rd), cite="rsp_physical",
                   sp_reg=rd, sp_reg_name=None)
        return rec
    if op == 0x12:
        return _vector(rec, word)
    if op in (0x23, 0x24, 0x25, 0x28, 0x29, 0x2B):
        mn, form, cite = OPCODES[op]
        rs, rt, off = bits(word, 25, 21), bits(word, 20, 16), sx16(word & 0xFFFF)
        rec.update(mnemonic=mn, text="%s %s,%d(%s)" % (mn, REG[rt], off, REG[rs]), cite=cite,
                   dmem_offset=off & 0xFFFF)
        return rec
    if op in (0x32, 0x3A):
        mn, form, cite = OPCODES[op]
        rs, rt, off = bits(word, 25, 21), bits(word, 20, 16), sx16(word & 0xFFFF)
        # The row (LQV/SQV/RFV/…) is a vector-unit function code and stays unresolved; the transfer class and
        # its DMEM operand do not.
        rec.update(mnemonic=mn, text="%s v%d,%d(%s)" % (mn, rt, off, REG[rs]), cite=cite,
                   dmem_offset=off & 0xFFFF, row=None)
        return rec
    if op in UNSETTLED:
        mn = UNSETTLED[op][0]
        rec.update(mnemonic=mn, text="%s (unsettled)" % mn, cite="imem_dmem_4k", unsettled=op)
        return _unreadable(rec, "opcode 0x%02x (%s)" % (op, mn))
    return _unreadable(rec, "opcode 0x%02x" % op)


def _unreadable(rec, key):
    rec["status"] = "unreadable"
    rec["unreadable_key"] = key
    if rec["text"] is None:
        rec["text"] = "?? 0x%08x" % rec["word"]
    return rec


def _vector(rec, word):
    """COP2. The word is *identified* as a vector-unit instruction and its fields are reported raw; no
    mnemonic is invented, because the VU's function codes are in no document this repository holds."""
    co = bits(word, 25, 25)
    if co == 0:
        rs = bits(word, 25, 21)
        kind = {0x00: "mfc2", 0x02: "cfc2", 0x04: "mtc2", 0x06: "ctc2"}.get(rs)
        if kind is None:
            return _unreadable(rec, "COP2 rs 0x%02x" % rs)
        rt, rd = bits(word, 20, 16), bits(word, 15, 11)
        rec.update(mnemonic=kind, text="%s %s,v%d" % (kind, REG[rt], rd), cite="vu_elements",
                   vector_kind="transfer", vu_reg=rd)
        rec["status"] = "vector"
        return rec
    e, vt, vs, vd, fn = bits(word, 24, 21), bits(word, 20, 16), bits(word, 15, 11), bits(word, 10, 6), bits(word, 5, 0)
    rec.update(mnemonic=None, status="vector", vector_kind="alu",
               vu={"e": e, "vt": vt, "vs": vs, "vd": vd, "funct": fn},
               text="cop2 e=%d vt=v%d vs=v%d vd=v%d funct=0x%02x (unnamed)" % (e, vt, vs, vd, fn),
               cite="vu_elements", unreadable_key="COP2 vector funct 0x%02x" % fn)
    return rec


# --- image access ---------------------------------------------------------------------------------------
def stage2():
    """The unpacked stage-2 member, or None. The cartridge itself is never committed, so a fresh clone has
    the unpacked member but nothing else; if even that is absent every image-dependent case SKIPs."""
    return IMAGE.read_bytes() if IMAGE.exists() else None


def word_at(image, va):
    off = va - STAGE2_BASE
    return int.from_bytes(image[off:off + 4], "big")


def ucode_blob(image):
    return image[UCODE_VA - STAGE2_BASE:UCODE_VA - STAGE2_BASE + UCODE_SIZE]


def entropy(data):
    counts = {}
    for b in data:
        counts[b] = counts.get(b, 0) + 1
    n = len(data)
    return -sum(c / n * math.log2(c / n) for c in counts.values())


# --- constant folding over stage-2 ----------------------------------------------------------------------
# The task block's pointers exist nowhere as literals (measured: 0 occurrences of 0x800b2700 in stage-2), so
# each field value is re-derived from the instructions that write the register. This is the rule the manifest
# states, and `--check` re-runs it: a manifest value that no fold reproduces is a failure.
SPECIAL_DST = {0x00, 0x02, 0x03, 0x06, 0x21, 0x23, 0x24, 0x25, 0x2A, 0x2B}


def dst_reg(word):
    op = bits(word, 31, 26)
    if op == 0x00:
        return bits(word, 15, 11) if bits(word, 5, 0) in SPECIAL_DST else None
    if op in (0x02, 0x03):
        return None
    return bits(word, 20, 16)


def fold(image, at_va, reg, window=32):
    """The 32-bit value in `reg` just before `at_va`, folded from lui/addiu/ori/subu, or None.

    Returns (value, [instruction, ...]) with the trace in the order the instructions are written. Deliberately
    not a dataflow: it walks back at most `window` instructions and gives up on anything but a constant arm, so
    a value it cannot fold is reported as unfolded instead of guessed.
    """
    for step in range(1, window + 1):
        va = at_va - 4 * step
        if va < STAGE2_BASE:
            return None
        w = word_at(image, va)
        op = bits(w, 31, 26)
        if dst_reg(w) != reg:
            continue
        ins = "%08x %s" % (va, decode(w, va)["text"])
        if op == 0x0F:
            return ((w & 0xFFFF) << 16, [ins])
        if op in (0x09, 0x0D) and bits(w, 25, 21) == 0:
            low = (w & 0xFFFF) if op == 0x0D else sx16(w & 0xFFFF)
            return (low & 0xFFFFFFFF, [ins])
        if op in (0x09, 0x0D) and bits(w, 25, 21) == reg:
            base = fold(image, va, reg, window)
            if base is None:
                return None
            low = (w & 0xFFFF) if op == 0x0D else sx16(w & 0xFFFF)
            return ((base[0] + low) & 0xFFFFFFFF, base[1] + [ins])
        if op == 0x00 and bits(w, 5, 0) == 0x23:               # subu rd,rs,rt
            a = fold(image, va, bits(w, 25, 21), window)
            b = fold(image, va, bits(w, 20, 16), window)
            if a is None or b is None:
                return None
            return ((a[0] - b[0]) & 0xFFFFFFFF, a[1] + b[1] + [ins])
        return None
    return None


def source_of(image, at_va, reg, window=32):
    """What the store at `at_va` puts in `reg`: a folded constant, a load, or nothing this tool can name."""
    const = fold(image, at_va, reg, window)
    if const is not None:
        return {"kind": "const", "value": const[0], "trace": const[1]}
    for step in range(1, window + 1):
        va = at_va - 4 * step
        if va < STAGE2_BASE:
            break
        w = word_at(image, va)
        if dst_reg(w) != reg:
            continue
        ins = "%08x %s" % (va, decode(w, va)["text"])
        kind = "load" if bits(w, 31, 26) in (0x23, 0x24, 0x25) else "unknown"
        return {"kind": kind, "value": None, "trace": [ins]}
    return {"kind": "unknown", "value": None, "trace": []}


# --- the task block -------------------------------------------------------------------------------------
# (offset, name, the store instruction that writes it). The stores are the only writers: FUN_800a2e40 is the
# one function in the corpus that names 0x80143c60 at all.
TASK_FIELDS = [
    (0x00, "type_or_kind", 0x800A2E6C),
    (0x04, "flags_or_zero", 0x800A2EC4),
    (0x08, "pair_a_pointer", 0x800A2EC8),
    (0x0C, "pair_a_size", 0x800A2E88),
    (0x10, "ucode_pointer", 0x800A2E94),
    (0x14, "ucode_size", 0x800A2E9C),
    (0x18, "data_pointer", 0x800A2EA8),
    (0x1C, "data_size", 0x800A2ECC),
    (0x30, "list_pointer", 0x800A2ED0),
    (0x34, "frame_count", 0x800A2ED8),
]

TASK_ROLE = {
    0x00: "written 2 — the only word in the block that says what kind of block it is",
    0x04: "written zero; nothing in the block reads it back on the CPU side",
    0x08: "a pointer whose 0xd0-byte extent is CPU-shaped MIPS, not RSP code (see evidence E2): the role is "
          "recorded, not named",
    0x0C: "the first pair's size, folded as 0x80028b50 - 0x80028a80 = 0xd0 rather than stored as a constant",
    0x10: "this blob: the RSP program the task runs",
    0x14: "the blob's size, exactly IMEM's capacity",
    0x18: "a 0x800-byte region at 0x80136b50 that no other stage-2 instruction names (0 references measured), "
          "and whose last 0x5c0 bytes run past the image's end (0x80136d90) into memory this image does not "
          "contain",
    0x1C: "the region's size, 0x800",
    0x30: "a value loaded from 0x80143f50, not a constant: the pointer the work list is published through",
    0x34: "a halfword loaded through 0x80143f54: the count of work units in that list. Its store sits in the "
          "delay slot of the flush call at 0x800a2ed4, so the count and the flush are published in one "
          "instruction pair",
}


def task_section(image):
    fields = []
    for off, name, site in TASK_FIELDS:
        w = word_at(image, site)
        rec = decode(w, site)
        base_reg, dest_reg = bits(w, 25, 21), bits(w, 20, 16)
        disp = sx16(w & 0xFFFF)
        base = fold(image, site, base_reg, window=32)
        resolved = (base[0] + disp) & 0xFFFFFFFF if base else None
        src = source_of(image, site, dest_reg)
        fields.append({
            "offset": off,
            "name": name,
            "role": TASK_ROLE[off],
            "writer": "%08x %s" % (site, rec["text"]),
            "block_address": hex(resolved) if resolved is not None else None,
            "block_address_trace": base[1] if base else
                                   ["the base register is only half formed here: %s" % rec["text"]],
            "value": src["value"] if src["kind"] == "const" else None,
            "value_hex": hex(src["value"]) if src["kind"] == "const" else None,
            "value_kind": src["kind"],
            "value_trace": src["trace"],
        })
    return {
        "block": hex(TASK_BLOCK),
        "written_by": "src/stage2/FUN_800a2e40.c (the corpus's only reference to the block); every store is "
                      "re-decoded here and its base folded",
        "address_rule": FOLD_RULE,
        "fields": fields,
        "submitted_to": {
            "site": "0x800a2ee4",
            "instruction": "%08x %s" % (0x800A2EE4, decode(word_at(image, 0x800A2EE4), 0x800A2EE4)["text"]),
            "argument": "a0 = the block address, set in the delay slot at 0x800a2ee8 (%s)"
                        % decode(word_at(image, 0x800A2EE8), 0x800A2EE8)["text"],
            "handler": "*(0x80143ff0) — a function pointer, installed by FUN_800b1fc0 "
                       "(src/stage2/FUN_800b1fc0.c:14 `_DAT_80143ff0 = *param_1;`), so the submit path is "
                       "whatever the driver installed and not a named OS entry point",
            "cache_flush": "between the stores and the submit, 0x800a2ed8 calls 0x8000efa0 with "
                           "(list, count*0xa10): the recipe at 0x800a2eb0-0x800a2ec0 is "
                           "`sll a1,a2,2 / addu a1,a1,a2 / sll a1,a1,5 / addu a1,a1,a2 / sll a1,a1,4`, i.e. "
                           "0xa10 bytes per work unit, which is the manual's requirement that the task header "
                           "be written back before the RSP reads it (p47)",
        },
    }


# --- what the window actually holds ---------------------------------------------------------------------
def corpus_functions():
    """Function starts this project's own corpus declares, from the `address` line of each FUN_*.c header.

    This is the only mechanical way to ask "does a CPU function begin inside the RSP window?", and the answer
    is yes: FUN_800b3640 starts 0xC0 bytes before the window's end, so the declared 0x1000 overruns the
    program. The window is therefore split at that boundary and the tail is not decoded as a program.
    """
    out = {}
    for p in sorted((ROOT / CORPUS).glob("FUN_*.c")):
        m = CORPUS_ADDR.search(p.read_text(errors="replace")[:600])
        if m:
            out[int(m.group(1), 16)] = str(p.relative_to(ROOT))
    return out


def foreign_start():
    """Offset inside the window at which a corpus CPU function begins (== SIZE when none does)."""
    inside = [a for a in corpus_functions() if UCODE_VA < a < UCODE_VA + UCODE_SIZE]
    return min(inside) - UCODE_VA if inside else UCODE_SIZE


# --- the program ----------------------------------------------------------------------------------------
def analyses(words):
    """Decode every word once; callers share this."""
    return [decode(w, i * 4) for i, w in enumerate(words)]


def functions_of(dec):
    """Functions are rooted at IMEM 0 and at every `jal` target — nothing else is invented.

    A body runs from its entry to its first `jr` (plus that jump's delay slot), capped at the next root: a body
    that reaches the next root without a `jr` falls through, and the manifest says so instead of extending it
    over the neighbour. `j` targets are recorded as jumps, not roots, because a `j` is not a call.
    """
    roots = sorted({0} | {d["jump_target"] for d in dec if d["mnemonic"] == "jal"})
    out = []
    for i, entry in enumerate(roots):
        limit = roots[i + 1] if i + 1 < len(roots) else len(dec) * 4
        body, end, returned = dec[entry // 4:limit // 4], limit, False
        for d in body:
            if d["mnemonic"] == "jr":
                end, returned = min(limit, d["at"] + 8), True
                break
        # A branch out of the body that lands between its first exit and the next root proves those words are
        # still this function's: extend to cover them, repeatedly, so a two-exit routine is one function.
        changed = True
        while changed and end < limit:
            changed = False
            targets = [d["branch_target"] for d in dec[entry // 4:end // 4] if d.get("branch_target")]
            beyond = [t for t in targets if end <= t < limit]
            if beyond:
                end, changed = max(beyond) + 4, True
                for d in dec[end // 4 - 1:limit // 4]:
                    if d["mnemonic"] == "jr":
                        end = min(limit, d["at"] + 8)
                        break
        body = dec[entry // 4:end // 4]
        calls = [d["jump_target"] for d in body if d["mnemonic"] == "jal"]
        out.append({
            "entry": entry,
            "end": end,
            "instructions": len(body),
            "calls": sorted(set(calls)),
            "call_sites": len(calls),
            "jumps": sorted({d["jump_target"] for d in body if d["mnemonic"] == "j"}),
            "returns": sum(1 for d in body if d["mnemonic"] == "jr" and d.get("jump_reg") == 31),
            "indirect_exits": sorted(d["at"] for d in body if d.get("indirect")),
            "ends_in_return": returned,
        })
    return roots, out


def coverage(dec, funcs):
    """The words no function body covers, as runs. Listed, not attributed."""
    covered = bytearray(len(dec))
    for f in funcs:
        for i in range(f["entry"] // 4, f["end"] // 4):
            covered[i] = 1
    runs, start = [], None
    for i, c in enumerate(covered):
        if not c and start is None:
            start = i
        elif c and start is not None:
            runs.append({"start": start * 4, "end": i * 4, "words": i - start})
            start = None
    if start is not None:
        runs.append({"start": start * 4, "end": len(dec) * 4, "words": len(dec) - start})
    return runs


def program_section(dec, words, foff):
    """Everything about the program proper: the RSP words only. `foff` is where CPU code takes over."""
    rsp = dec[:foff // 4]
    roots, funcs = functions_of(rsp)
    gaps = coverage(rsp, funcs)
    raw_targets = [d["target_raw"] for d in rsp if d.get("target_raw") is not None]
    dmem = [d["dmem_offset"] for d in rsp
            if "dmem_offset" in d and d["mnemonic"] in ("lw", "lbu", "lhu", "sb", "sh", "sw")]
    cop2_offsets = [d["dmem_offset"] for d in rsp if d["mnemonic"] in ("lwc2", "swc2")]
    sp_regs = {}
    for d in rsp:
        if "sp_reg" in d:
            key = "%s %d" % (d["mnemonic"], d["sp_reg"])
            sp_regs[key] = sp_regs.get(key, 0) + 1
    unresolved = [{"at": d["at"], "kind": "jr r%d (register indirect)" % d["jump_reg"],
                   "why": "the target is whatever the register holds at run time; the edge exists and its "
                          "destination does not. 0xf34 `jr t0` returns through r8, which the routine at 0xe34 "
                          "saves from ra in its first instruction (`or t0,zero,ra` at 0xe34), so the exit is a "
                          "return through a saved link rather than an unknown call"}
                  for d in rsp if d.get("indirect")]
    unresolved += [{"at": g["start"], "kind": "words no function covers",
                    "why": "%d words from 0x%03x are reached by no jal target and by no modelled fall-through; "
                           "listed as uncovered rather than assigned to a neighbour" % (g["words"], g["start"])}
                   for g in gaps]
    return {
        "words": len(dec),
        "rsp_words": len(rsp),
        "instructions": sum(1 for d in rsp if d["text"]),
        "entry": 0,
        "roots": roots,
        "functions": funcs,
        "gaps": gaps,
        "foreign": {
            "offset": foff,
            "words": len(dec) - len(rsp),
            "ident": hex(UCODE_VA + foff),
            "evidence": [
                "the corpus declares a CPU function at 0x%x: %s" % (UCODE_VA + foff,
                                                                   corpus_functions()[UCODE_VA + foff]),
                "the RSP program's last exit is 0xf34 `jr t0` with its delay slot at 0xf38, followed by a "
                "`nop` fill at 0xf3c; the next word is the CPU function's body",
                "the words from 0x%03x build a KSEG0 address (`lui v0,0x8016` + `addiu v0,v0,-0x74e0` = "
                "0x80158b20) and load/store through it — an RSP load cannot name RDRAM (p139: the RSP software "
                "can only access DMEM), so these are not RSP instructions" % foff,
                "the arithmetic agrees with the corpus body: FUN_800b3640 walks a 0x1228-stride table and "
                "compares +0x1224 against _DAT_8015af70 (src/stage2/FUN_800b3640.c:22-27), and the words here "
                "carry `addiu a0,a0,0x1228` and `lw v0,0x1224(a0)`",
            ],
            "not_decoded_as": "program words: they are listed in no function, contribute to no jump target and "
                              "to no DMEM statistic",
        },
        "unresolved_targets": unresolved,
        "jump_encoding": {
            "rule": ADDRESS_RULE,
            "count": len(raw_targets),
            "raw_first": hex(min(raw_targets)),
            "raw_last": hex(max(raw_targets)),
            "raw_page_base": hex(min(raw_targets) & 0xFFFFF000),
            "raw_pages": len({t & 0xFFFFF000 for t in raw_targets}),
            "raw_outside_imem": sum(1 for t in raw_targets if t >= UCODE_SIZE),
            "masked_inside": sum(1 for t in raw_targets if (t & 0xFFF) < UCODE_SIZE),
            "masked_first": hex(min(t & 0xFFF for t in raw_targets)),
            "masked_last": hex(max(t & 0xFFF for t in raw_targets)),
            "note": "counted over RSP words only. The one jump in the CPU tail (0xfa8 `j`, raw target "
                    "0xb3650 = 0x800b3650) is excluded and is itself a CPU jump, which corroborates where the "
                    "program ends",
        },
        "dmem": {
            "words_with_displacement": len(dmem),
            "distinct_offsets": len(set(dmem)),
            "min": hex(min(dmem)),
            "max": hex(max(dmem)),
            "above_4k": sorted({o for o in dmem if o > 0xFFF})[:8],
            "excluded_cop2_transfers": len(cop2_offsets),
            "cop2_note": "the lwc2/swc2 immediate is not the same field as a scalar load's displacement: the "
                         "words at 0x4a4/0x4a8 carry 0x2000/0x2001, which no 16-bit DMEM displacement can be, "
                         "so the %d vector transfers are excluded from these statistics instead of widening "
                         "them" % len(cop2_offsets),
            "note": "the 16-bit displacements of lw/lbu/lhu/sb/sh/sw are DMEM offsets (p139: the RSP software "
                    "can only access DMEM; p44: 4 KB of it). No offset is given a name: a name would have to "
                    "come from the ucode's own layout, and nothing on the CPU side records it",
        },
        "sp_registers": {
            "moves": sp_regs,
            "note": "COP0 register numbers, raw. The SP register map is in no local document, so this counts "
                    "which numbers are written and which are polled and names none of them",
        },
    }


# --- identity -------------------------------------------------------------------------------------------
def identity_section(image, dec, prog, blob, foff):
    """Measure the ABI shape, and decide only if a measurement forces one name."""
    dec = dec[:foff // 4]
    cop0 = [d for d in dec if d.get("sp_reg") is not None]
    writes = sorted({d["sp_reg"] for d in cop0 if d["mnemonic"] == "mtc0"})
    reads = sorted({d["sp_reg"] for d in cop0 if d["mnemonic"] == "mfc0"})
    lui_consts = ["%04x:0x%04x" % (d["at"], d["word"] & 0xFFFF) for d in dec if d["mnemonic"] == "lui"]
    entry = dec[:10]
    evidence = [
        {"id": "E0",
         "measurement": "IMEM 0x000-0x024 is a status poll and nothing else: `mfc0 a2,<cop0 11>` / "
                        "`andi a1,a2,1` / `beq a1,zero,0x028` / `andi a1,a2,0x100` / `beq a1,zero,0x028`, then a "
                        "spin `mfc0 a1,<cop0 11>` / `andi a1,a1,0x100` / `bgtz a1,0x018`, and only then does the "
                        "program touch anything (0x028 is the first vector instruction). %d of the program's %d "
                        "COP0 moves are in its first 0x3d0 bytes, and %d words are COP0 moves."
                        % (sum(1 for d in dec[:0x3d4 // 4] if d.get("sp_reg") is not None), len(cop0), len(cop0)),
         "reading": "a program that begins by polling a hardware status word and issuing no work before it is "
                    "reachable is ucode driven by a task, not a data table: the wait has to be for the engine "
                    "that started it. Register 11 is called the RSP status register by N64 documentation this "
                    "repository does not hold — the name is recorded as coming from outside this repository's "
                    "authority, the number and the poll are measured, and nothing downstream depends on the "
                    "name.",
         "status": "measured; register name outside local authority"},
        {"id": "E1",
         "measurement": "the task block carries four pointer+size pairs — +0x08/+0x0c, +0x10/+0x14, "
                        "+0x18/+0x1c, +0x30/+0x34 — and the +0x10/+0x14 pair names this blob (0x800b2700, "
                        "0x1000). Each value was folded out of the store that writes it, not quoted.",
         "reading": "the block is a task header in the p137 sense: a structure the CPU fills and hands over "
                    "with a pointer to the microcode and a pointer to the data to process.",
         "status": "measured"},
        {"id": "E2",
         "measurement": "the +0x08/+0x0c pair names 0x80028a80 with size 0xd0 (= 0x80028b50-0x80028a80), and the "
                        "bytes there are CPU-shaped MIPS: `lw v1,0(s0)`, `sw v0,0x14(v1)`, `jalr v0`, and a "
                        "`jr ra` at 0x80028b14 whose delay slot is `addiu sp,sp,0x28`. This project's corpus has "
                        "FUN_80028b1c starting 0x9c bytes later, so the 0xd0 extent straddles a function "
                        "boundary.",
         "reading": "the manual gives that pair the *boot microcode* role — RSP code the R4300 DMAs into IMEM "
                    "before the task microcode (p137) — and these bytes are not RSP code. Either the pair carries "
                    "something else in this cartridge, or the block is not the OSTask of p137. Recorded against "
                    "both candidates rather than smoothed.",
         "status": "measured, unresolved"},
        {"id": "E3",
         "measurement": "the declared size is 0x1000 = all of IMEM (p44), but the program is 0x%x bytes: the "
                        "corpus's own function FUN_800b3640 begins at 0x%x, 0x%x bytes before the window ends, "
                        "and the RSP program's last exit is 0xf34 `jr t0` (delay 0xf38, `nop` fill 0xf3c)."
                        % (foff, UCODE_VA + foff, UCODE_SIZE - foff),
         "reading": "the size field is IMEM's capacity, not the code's length: the declared 0x%x overruns the "
                    "program by 0x%x bytes into the next CPU function. A task that DMAs 0x1000 bytes into IMEM "
                    "therefore loads the whole program plus 0x%x bytes of CPU code that no exit reaches. The "
                    "overrun is recorded, not corrected."
                        % (UCODE_SIZE, UCODE_SIZE - foff, UCODE_SIZE - foff),
         "status": "measured"},
        {"id": "E3b",
         "measurement": "IMEM 0x02c-0x030 (`lw a0,0x30(r1)` and `lw v1,0x34(r1)`) read DMEM 0x30 and 0x34 — the "
                        "same two offsets the CPU writes at 0x800a2ed0/0x800a2ed4 as the work-list pointer and "
                        "its count — before the program has written anything to DMEM.",
         "reading": "the block at 0x80143c60 is in DMEM when the program starts, which is the mechanism p137 "
                    "describes (the R4300 DMAs the task header into DMEM, sets PC to 0). It also means the "
                    "program assumes r1 holds zero at entry, and nothing in this repository establishes what the "
                    "RSP's general registers hold when a task starts — the manual lists the boot ucode, the task "
                    "header, PC and the halt status and no register state (p137). The assumption is recorded; it "
                    "is not explained.",
         "status": "measured; entry register state unresolved"},
        {"id": "E4",
         "measurement": "%d COP0 moves: registers %s are written, registers %s are read. Five blocks repeat one "
                        "shape — write three registers carrying data, then poll a fourth, and clear register 7 "
                        "with `mtc0 zero` — at 0x350, 0x384, 0x3b4 and 0x228-0x3c8."
                        % (len(cop0), writes, reads),
         "reading": "the shape is one DMA primitive copied: a source, a destination and a length are written and a "
                    "busy flag is polled. Which number is which is *not* claimed — no local document maps the SP "
                    "registers — so the copy's direction stays unresolved even though the idiom is measured.",
         "status": "measured, names unresolved"},
        {"id": "E5",
         "measurement": "%d words address DMEM by 16-bit displacement, across %d distinct offsets from 0x%03x to "
                        "0x%03x. No offset is named."
                        % (prog["dmem"]["words_with_displacement"], prog["dmem"]["distinct_offsets"],
                           int(prog["dmem"]["min"], 16), int(prog["dmem"]["max"], 16)),
         "reading": "the program's whole interface with the CPU is DMEM plus DMA, and the layout it builds there "
                    "is the ucode's own. Nothing on the CPU side mirrors it, so no field of it can be matched "
                    "against a documented ABI from inside this repository.",
         "status": "measured, ABI match unavailable"},
        {"id": "E6",
         "measurement": "the +0x18 pair names 0x80136b50 with size 0x800, and no other instruction in stage-2 "
                        "names that address — 0 references, scanned as a `lui 0x8013` + `addiu 0x6b50` pair and "
                        "as a literal. Its last 0x5c0 bytes run past the image's end at 0x80136d90.",
         "reading": "the region the ucode is handed as data is never touched by the CPU: it is either the ucode's "
                    "own DMA target or its scratch, and which one is `rsp_only`.",
         "status": "measured"},
        {"id": "E7",
         "measurement": "the program's only four `lui` constants are %s." % ", ".join(lui_consts),
         "reading": "the last 0xc0 bytes build RDRAM addresses in code instead of taking them from a pointer, and "
                    "0x8016xxxx sits above this image's end. The scheme the manual describes is that the task "
                    "header carries the pointer to the data to process (p137), so a hard-coded RDRAM address is a "
                    "departure from it. It does not by itself name the ucode's author.",
         "status": "measured"},
    ]
    return {
        "candidates": [
            {"name": "Nintendo libaudio aspMain (the AL* / alAudioFrame ABI)",
             "would_predict": ["a task header whose microcode pointer and boot pointer both name RSP code (p137)",
                               "a command list of fixed-format 64-bit commands the ucode dispatches on",
                               "work items read through DMEM structures the CPU filled"],
             "against": ["E2: the pair the manual gives the boot-ucode role names CPU code, not RSP code"],
             "verdict": "not established — the ABI's command opcodes cannot be read out of this blob without a "
                        "table this repository does not hold"},
            {"name": "a Factor 5 / MusyX driver",
             "would_predict": ["a private task shape and a private command format",
                               "a streaming ring fed by the CPU rather than a per-frame command list"],
             "against": ["nothing in this repository measures Factor 5 or MusyX: no string, no signature, no "
                         "shape attributable to either. The cartridge's sound path is already known to be a "
                         "private codec (M221/M222), which is a different claim"],
             "verdict": "unresolved — no measurement here bears on it"},
            {"name": "a cartridge-private ucode",
             "would_predict": ["a task block only this cartridge's submit path consumes",
                               "hard-coded RDRAM addresses in the ucode's tail",
                               "no dependence on a documented command format"],
             "against": ["E7 fits and E1/E2 are consistent, but 'private' is the residual rather than a positive "
                         "identification: it is what is left when the two named families fail to be forced"],
             "verdict": "the reading the measurements leave standing, not a name"},
        ],
        "evidence": evidence,
        "verdict": "unresolved",
        "deciding_measurement": None,
        "what_would_decide": [
            "an RSP encoding table this repository could cite: it would name the 254 vector words and the COP0 "
            "registers, and the jal fan-out at 0x3c-0x2e0 would read as a command switch",
            "a CPU-side consumer of the 0x800 bytes at 0x80136b50 (E6): what the ucode is expected to write "
            "there is an ABI fingerprint",
            "an independent copy of the same ucode from another N64 title: byte equality would settle provenance "
            "without a table",
        ],
    }


# --- rsp_only -------------------------------------------------------------------------------------------
def rsp_only_section(prog, blob, dec):
    return [
        {"what": "the DMEM layout the ucode builds",
         "why": "the program's only data addressing is a 16-bit DMEM displacement (%d words, %d distinct, "
                "0x%03x-0x%03x). The CPU writes no structure the ucode reads by name, so every offset is decided "
                "inside the RSP and nothing on the CPU side can be cited for it"
                % (prog["dmem"]["words_with_displacement"], prog["dmem"]["distinct_offsets"],
                   int(prog["dmem"]["min"], 16), int(prog["dmem"]["max"], 16)),
         "cpu_evidence": "none — measured by scanning every stage-2 instruction that touches the task's own "
                         "structures"},
        {"what": "the vector unit's %d words" % sum(1 for d in dec if d.get("vector_kind")),
         "why": "each carries a function code in bits 5:0 and an element in bits 24:21, and no document this "
                "repository holds maps either. The mixer's arithmetic is in those words; naming them would mean "
                "importing another architecture's table, so they stay unnamed and counted",
         "cpu_evidence": "none — the CPU never writes a vector register"},
        {"what": "the meaning of the 0x800 bytes at 0x80136b50 (task+0x18)",
         "why": "no stage-2 instruction reads or writes that address (0 references) and its tail runs past the "
                "image. Whether the ucode treats it as input or scratch is decided only by the RSP",
         "cpu_evidence": "the task field that names it, and nothing else"},
        {"what": "the command format the ucode dispatches on",
         "why": "the list the task publishes (task+0x30, from 0x80143f50) is only handed over; the ucode must DMA "
                "it into DMEM itself and what it does with the bytes is inside the RSP. The jal fan-out at the "
                "top of the program is the dispatch, but its arms are unnamed until the encodings are",
         "cpu_evidence": "src/stage2/FUN_800a4d30.c writes the list base; the list's contents come from the voice "
                         "path (M222), which stops at this same boundary"},
        {"what": "whether the ucode is correct, or what it sounds like",
         "why": "this tool decodes instructions. Nothing here has been executed, so no claim is made that the "
                "program runs, terminates, or mixes",
         "cpu_evidence": "none — by construction"},
    ]


# --- the manifest ---------------------------------------------------------------------------------------
def derive(image):
    """The whole artefact, from the image alone. --check compares the committed file to this."""
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    dec = analyses(words)
    foff = foreign_start()
    prog = program_section(dec, words, foff)

    scalar, vector, unreadable = {}, {}, {}
    counts = {"scalar": 0, "vector": 0, "unreadable": 0, "foreign": len(words) - foff // 4}
    for d in dec[:foff // 4]:
        if d["status"] == "unreadable":
            counts["unreadable"] += 1
            key = d["unreadable_key"]
            g = unreadable.setdefault(key, {"key": key, "kind": "opcode", "words": 0, "first": d["at"],
                                            "cite": d["cite"],
                                            "why": "named in no document this repository holds"})
            g["words"] += 1
        elif d["status"] == "vector":
            counts["vector"] += 1
            if d["vector_kind"] == "alu":
                key = "COP2 vector funct 0x%02x" % d["vu"]["funct"]
                ex = d["text"]
            else:
                key = "COP2 %s v%d" % (d["mnemonic"], d["vu_reg"])
                ex = d["text"]
            v = vector.setdefault(key, {"key": key, "words": 0, "first": d["at"], "mnemonic": None,
                                        "cite": d["cite"], "status": "unresolved", "fields_example": ex})
            v["words"] += 1
        else:
            counts["scalar"] += 1
            s = scalar.setdefault(d["mnemonic"], {"mnemonic": d["mnemonic"], "words": 0, "first": d["at"],
                                                  "cite": d["cite"], "status": FAMILY,
                                                  "form_example": d["text"]})
            s["words"] += 1
    for key in list(unreadable):
        if key.startswith("opcode 0x14"):
            unreadable[key]["why"] = UNSETTLED[0x14][1]
    # The vector words are unnamed too, so `unreadable` lists them as well: the schema's one place to look for
    # "what this decoder will not name" must not omit its largest group.
    for key, v in vector.items():
        unreadable[key] = {"key": key, "kind": "vector-unit", "words": v["words"], "first": v["first"],
                           "cite": v["cite"],
                           "why": "the RSP's vector function codes are in no document this repository holds, so "
                                  "the word is identified as a vector-unit instruction and left unnamed"}
    for d in dec[foff // 4:]:
        d["status"] = "foreign"
        d["text"] = "%s  [cpu code, %s]" % (d["text"], hex(UCODE_VA + foff))
    return {
        "tool": "rsp_decode.py",
        "schema": SCHEMA,
        "inputs": {
            "image": str(IMAGE.relative_to(ROOT)),
            "base": hex(STAGE2_BASE),
            "cartridge": "not needed: the blob is an unpacked member of stage-2",
            "manual": MANUAL,
            "manual_pages": MANUAL_PAGES,
            "reference": "DragonMinded/libdragon src/audio/rsp_mixer.S (Unlicense) was read as a coverage "
                         "reference for which instruction families a real RSP audio mixer uses (scalar "
                         "loads/stores, LWC2/SWC2 row transfers, COP2 ALU, COP0 clock/DMA moves). It named "
                         "nothing here: no encoding, no DMEM offset and no command opcode comes from it, and it "
                         "is a different, modern design — no byte of this cartridge is evidence about it or "
                         "from it",
        },
        "blob": {
            "addr": hex(UCODE_VA),
            "size": UCODE_SIZE,
            "image_offset": UCODE_VA - STAGE2_BASE,
            "sha256": hashlib.sha256(blob).hexdigest(),
            "entropy": round(entropy(blob), 3),
            "zero_bytes": blob.count(0),
            "bounded_by": [
                "before: the CPU function ending `lw ra,0x10(sp) / jr ra / addiu sp,sp,0x18` at 0x99c74, so "
                "0x99c80 is a function boundary and not the middle of one",
                "after: 0x9ac80 is `nop` then `addiu sp,sp,-0x40` at 0x9ac84, the next CPU function's prologue",
                "the blob's last word is `jr ra` at 0xffc and its delay slot is the first word outside the "
                "declared size — recorded, because that is the one place the declared 0x1000 cuts a pair",
            ],
            "contains_cartridge_bytes": False,
        },
        "decoder": {
            "coverage_rule": (
                "Every word is one of three things. `scalar`: named from the R4000/MIPS III table that p44 and "
                "p47 name for the SU — the manual does not tabulate the encoding, so each such entry is labelled "
                "`family`, not `cited`. `vector`: identified as a COP2 vector-unit instruction with its fields "
                "reported raw, its mnemonic null, and listed in `unreadable`. `unreadable`: named in no document "
                "this repository holds. Nothing is imported from another architecture's table, and no DMEM "
                "offset, SP register or command opcode acquires a name."),
            "scalar_ops": {k: scalar[k] for k in sorted(scalar)},
            "vector_ops": {k: vector[k] for k in sorted(vector)},
            "unreadable": [unreadable[k] for k in sorted(unreadable)],
            "counts": dict(counts, words=len(dec)),
        },
        "program": prog,
        "identity": identity_section(image, dec, prog, blob, foff),
        "task": task_section(image),
        "rsp_only": rsp_only_section(prog, blob, dec),
        "citations": {k: {"page": v[0], "quote": v[1]} for k, v in sorted(CITES.items())},
    }




# --- checks ---------------------------------------------------------------------------------------------
def check(committed, image):
    """Every claim the manifest makes, re-derived. Returns [(label, ok), ...]; the caller prints them."""
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    dec = analyses(words)
    fresh = derive(image)
    cases = []

    cases.append((f"the task block's +0x10 field names 0x{UCODE_VA:x}, which resolves to image offset "
                  f"0x{UCODE_VA - STAGE2_BASE:x} and {len(blob)} bytes there",
                  committed["blob"]["image_offset"] == UCODE_VA - STAGE2_BASE and len(blob) == UCODE_SIZE))

    cases.append((f"words × 4 == size ({len(words)} × 4 == {UCODE_SIZE})",
                  len(words) * 4 == committed["blob"]["size"] == UCODE_SIZE))

    cases.append((f"blob sha256 matches the committed record ({committed['blob']['sha256'][:16]}…)",
                  hashlib.sha256(blob).hexdigest() == committed["blob"]["sha256"]
                  == fresh["blob"]["sha256"]))

    cases.append((f"entropy matches ({committed['blob']['entropy']}, {committed['blob']['zero_bytes']} zero bytes)",
                  abs(entropy(blob) - committed["blob"]["entropy"]) < 5e-4
                  and blob.count(0) == committed["blob"]["zero_bytes"]))

    c = committed["decoder"]["counts"]
    cases.append((f"every word is classified: {c['scalar']} scalar + {c['vector']} vector + "
                  f"{c['unreadable']} unreadable + {c['foreign']} CPU = {len(words)}",
                  c["scalar"] + c["vector"] + c["unreadable"] + c["foreign"] == len(words) == c["words"]))

    foff = committed["program"]["foreign"]["offset"]
    corpus = corpus_functions()
    cases.append((f"the window is split where the project's corpus says a CPU function starts "
                  f"(0x{UCODE_VA + foff:x} = {corpus.get(UCODE_VA + foff, 'absent')}), and the split "
                  f"re-derives",
                  foreign_start() == foff == committed["program"]["foreign"]["offset"]
                  and f"{foff // 4}" and committed["program"]["foreign"]["words"] * 4 + foff == UCODE_SIZE
                  and (UCODE_VA + foff) in corpus))

    ops = committed["decoder"]["scalar_ops"]
    cited = {k: v["cite"] for k, v in ops.items()}
    bad_cite = [(k, v) for k, v in cited.items() if v not in CITES]
    cases.append((f"every named encoding cites a page of the local manual "
                  f"({len(ops)} scalar ops, {len(set(cited.values()))} distinct citations)",
                  not bad_cite and all(0 < CITES[v][0] <= MANUAL_PAGES for v in cited.values())))

    unre = committed["decoder"]["unreadable"]
    totale = sum(u["words"] for u in unre)
    cases.append((f"every unnamed word is listed with a count and a first address "
                  f"({len(unre)} groups, {totale} words = vector {c['vector']} + unsettled "
                  f"{c['unreadable']})",
                  totale == c["vector"] + c["unreadable"]
                  and all(u.get("why") and u.get("key") and isinstance(u["first"], int) for u in unre)))

    je = committed["program"]["jump_encoding"]
    cases.append((f"call and jump targets are inside the program under the 12-bit IMEM rule "
                  f"({je['count']} fields, raw {je['raw_first']}..{je['raw_last']}, "
                  f"{je['raw_pages']} page(s), {je['raw_outside_imem']} raw targets outside a 4 KB IMEM, "
                  f"{je['masked_inside']} masked targets inside)",
                  je["raw_outside_imem"] == je["count"] == je["masked_inside"] and je["raw_pages"] == 1))

    funcs = committed["program"]["functions"]
    covered = sum(f["instructions"] for f in funcs) + sum(g["words"] for g in committed["program"]["gaps"])
    cases.append((f"function bodies plus listed gaps account for every RSP word "
                  f"({len(funcs)} functions, {covered} words == {committed['program']['rsp_words']})",
                  covered == committed["program"]["rsp_words"]))

    starts = [f["entry"] for f in funcs]
    cases.append(("no two function bodies overlap and every body starts at a root",
                  len({f["entry"] for f in funcs}) == len(funcs)
                  and all(f["end"] > f["entry"] for f in funcs)
                  and sorted(starts) == starts
                  and all(b["entry"] >= a["end"] for a, b in zip(funcs, funcs[1:]))))

    entry_ok = funcs[0]["entry"] == 0 and committed["program"]["entry"] == 0
    jal_roots = {d["jump_target"] for d in dec if d["mnemonic"] == "jal"}
    cases.append((f"the entry is IMEM 0 and the {len(jal_roots)} jal targets are exactly the other roots",
                  entry_ok and set(starts[1:]) == jal_roots))

    tf = committed["task"]["fields"]
    sites_ok, fold_ok = True, True
    for f in tf:
        want = TASK_BLOCK + f["offset"]
        try:
            have = int(f["block_address"], 16)
        except (TypeError, ValueError):
            have = None
        sites_ok &= have == want
        src = source_of(image, int(f["writer"].split()[0], 16),
                        bits(word_at(image, int(f["writer"].split()[0], 16)), 20, 16))
        fold_ok &= (src["kind"] == f["value_kind"]) and (
            src["value"] is None or src["value"] == f["value"])
    cases.append((f"all {len(tf)} task fields re-fold: each writer stores to 0x{TASK_BLOCK:x}+offset and each "
                  f"value re-derives", sites_ok))
    cases.append(("every task field's value is either a folded constant that re-derives or a load that is "
                  "recorded as a load", fold_ok))

    pair = [f for f in tf if f["offset"] == 0x10][0]
    literal = image.count(UCODE_VA.to_bytes(4, "big"))
    cases.append((f"the ucode pointer is a lui+addiu fold ({pair['value']:#x}) and the literal 0x{UCODE_VA:x} "
                  f"appears {literal} times in stage-2",
                  pair["value"] == UCODE_VA and literal == 0
                  and all("lui" in t for t in pair["value_trace"][:1])))

    ident = committed["identity"]
    cases.append((f"the identity verdict is one of the allowed words ({ident['verdict']}) and every candidate "
                  f"carries what would confirm or refute it",
                  ident["verdict"] in ("aspMain", "musyx", "unresolved")
                  and len(ident["candidates"]) >= 2
                  and all(x.get("verdict") and x.get("would_predict") and x.get("against")
                          for x in ident["candidates"])
                  and all(e.get("measurement") and e.get("reading") for e in ident["evidence"])))

    cases.append((f"every rsp_only entry says what is out of reach and why ({len(committed['rsp_only'])} entries)",
                  all(r.get("what") and r.get("why") and r.get("cpu_evidence")
                      for r in committed["rsp_only"])))

    committed_s = json.dumps(committed, sort_keys=True)
    fresh_s = json.dumps(fresh, sort_keys=True)
    cases.append(("the committed manifest equals a fresh derivation of the image", committed_s == fresh_s))
    return cases


def disasm(image, first=0, last=None):
    blob = ucode_blob(image)
    words = [int.from_bytes(blob[i:i + 4], "big") for i in range(0, len(blob), 4)]
    for i, w in enumerate(words):
        if i * 4 < first or (last is not None and i * 4 >= last):
            continue
        d = decode(w, i * 4)
        print("%04x  %08x  %-34s %s" % (i * 4, w, d["text"], "" if d["status"] != "unreadable"
                                        else "[unreadable]" if d["status"] == "unreadable" else ""))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--disasm", action="store_true")
    ap.add_argument("--first", type=lambda s: int(s, 0), default=0)
    ap.add_argument("--last", type=lambda s: int(s, 0), default=None)
    a = ap.parse_args()

    image = stage2()
    if a.write:
        if image is None:
            print("REFUSED: %s is not present, so there is nothing to decode" % IMAGE.relative_to(ROOT))
            return 2
        rep = derive(image)
        (ROOT / OUT).write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        c = rep["decoder"]["counts"]
        print("wrote %s — %d words: %d RSP (%d scalar, %d vector unnamed, %d unreadable) + %d CPU; "
              "%d functions, %d gaps; identity %s"
              % (OUT, c["words"], rep["program"]["rsp_words"], c["scalar"], c["vector"], c["unreadable"],
                 c["foreign"], len(rep["program"]["functions"]), len(rep["program"]["gaps"]),
                 rep["identity"]["verdict"]))
        return 0

    if a.disasm:
        if image is None:
            print("SKIP (needs the unpacked stage-2 image)")
            return 0
        disasm(image, a.first, a.last)
        return 0

    if not a.check:
        ap.error("one of --write, --check, --disasm is required")

    if image is None:
        print("SKIP (needs the unpacked stage-2 image: %s)" % IMAGE.relative_to(ROOT))
        return 0

    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed, image)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d rsp case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
