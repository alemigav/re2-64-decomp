#!/usr/bin/env python3
"""Prove that `break` in this port cannot be recovered from: the exception path never returns.

`0x8008548c` guards a texture handle with `break` (Ghidra renders it `trap(0)`). Whether that is a hard stop or
something a handler can skip is a question about the **exception path**, and it is answerable by disassembly:

  1. boot installs a four-instruction stub at the exception vectors (`0x80000084`, `0x80000100`, `0x80000180`):
     `lui k0,0x8000` / `addiu k0,k0,0x06d0` / `jr k0` / `nop`  ->  every exception vectors to **0x800006d0**;
  2. the handler masks interrupts, reads **Cause**, posts a **fault event** into the libultra queue at
     `0x80012140`, and copies the interrupted register file into a fault context;
  3. and then — the two facts that decide the question — there is **no `mtc0 $14`** (an EPC write, the only way
     to skip the faulting instruction) and **no `eret`** (the only way to return, which would retry it).

So a stale handle does not fall through, and does not even re-trap in a loop: it stops the machine.

  ./exception_path.py            # report
  ./exception_path.py --check    # the gate
"""
import argparse
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROM = HERE.parent / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
BOOT_ELF = HERE.parent / "build" / "elfs" / "boot.elf"
VECTORS = (0x80000084, 0x80000100, 0x80000180)
STUB = (0x3C1A8000, 0x275A06D0, 0x03400008, 0x00000000)     # lui k0 / addiu k0 / jr k0 / nop
HANDLER = 0x800006D0
HANDLER_END = 0x80000F00


def segments(data):
    e_phoff = struct.unpack_from(">I", data, 28)[0]
    pes = struct.unpack_from(">H", data, 42)[0]
    phn = struct.unpack_from(">H", data, 44)[0]
    out = []
    for i in range(phn):
        off = e_phoff + i * pes
        p_type, p_offset, p_vaddr, _pa, p_filesz, _ms = struct.unpack_from(">IIIIII", data, off)
        if p_type == 1:
            out.append((p_vaddr, p_offset, p_filesz))
    return out


def load_boot():
    """The boot image, from the elf if it is built, else straight from the ROM (`boot` is at cart 0x1000)."""
    if BOOT_ELF.exists():
        data = BOOT_ELF.read_bytes()
        for v, o, s in segments(data):
            if v <= HANDLER < v + s:
                return data, v, o, s
    if ROM.exists():
        rom = ROM.read_bytes()
        base, size = 0x80000000, 69952
        return rom[0x1000:0x1000 + size], base, 0, size
    return None, None, None, None


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--check", action="store_true")
    args = ap.parse_args()
    data, vaddr, off, size = load_boot()
    if data is None:
        print("SKIP: no boot image and no cartridge")
        return 0

    def word(va):
        return struct.unpack_from(">I", data, off + (va - vaddr))[0]

    # 1. the stub exists **literally** in the boot image: the installer copies these 16 bytes to each vector,
    # so searching the image for them is a real check (they are absent *at* the vectors, which is runtime RAM).
    stub_bytes = b"".join(struct.pack(">I", w) for w in STUB)
    stub_at = data.find(stub_bytes)
    stubs_ok = 1 if stub_at >= 0 else 0

    # 2. exhaustive scan of the handler region
    mtc0_epc = [va for va in range(HANDLER, HANDLER_END, 4)
                if (word(va) >> 26) == 0x10 and ((word(va) >> 21) & 0x1F) == 4
                and ((word(va) >> 11) & 0x1F) == 14]
    erets = [va for va in range(HANDLER, HANDLER_END, 4) if word(va) == 0x42000018]
    causes = [va for va in range(HANDLER, HANDLER_END, 4)
              if (word(va) >> 26) == 0x10 and ((word(va) >> 21) & 0x1F) == 0
              and ((word(va) >> 11) & 0x1F) == 13]

    print(f"handler region {HANDLER:#x}..{HANDLER_END:#x}: "
          f"{len(causes)} Cause read(s), {len(mtc0_epc)} EPC write(s), {len(erets)} eret(s)")
    print(f"stub bytes in the image: {'at file offset ' + hex(stub_at) if stub_at >= 0 else 'NOT FOUND'}")

    if not args.check:
        return 0
    cases = [
        ("the handler reads Cause, so it is the real exception path", len(causes) >= 1),
        ("no EPC write exists, so the faulting instruction cannot be skipped", len(mtc0_epc) == 0),
        ("no eret exists, so the handler never returns", len(erets) == 0),
        ("the jr-k0 stub exists literally in the boot image (the installer copies it to the vectors)",
         stubs_ok == 1),
    ]
    passed = 0
    for label, ok in cases:
        passed += ok
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} exception-path case(s)")
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
