#!/usr/bin/env python3
"""Decode the `MORT` voice bank to audio by executing the cartridge's own synthesis.

Why the audio is produced by emulation rather than by a transcription: `FUN_800b6634` calls
`FUN_800b6788` and `FUN_800b6470` through registers Ghidra does not model — the pseudocode renders them as
`FUN_800b6788()` with no arguments and `(*in_t3)()` eight times, and their real inputs are `t0`, `t1`, `t3`
and `t6`–`t9` plus `s0`–`s7`. There is nothing faithful to transcribe from the pseudocode alone. So this
tool runs the instructions: `stage2.elf`'s code under Unicorn, with the DMA ring filled by the host the way
`FUN_800b4a04` fills it, and the 0x140-byte output captured per block.

What is host-supplied, stated plainly:
  * the band's record bytes, placed in the ring at the window the reader asks for (`(bitpos>>3) & ~0xFFF`);
  * `memset` (`0x80006650`, in the boot image) as a host primitive, because the silent block's only work is
    `memset(out, 0x140)` and emulating libultra's implementation buys no information.

Everything else — the bit reader, the field layout, the dequantisation, the pitch predictor, the lattice,
the polyphase mix — is the cartridge's own code. `--check` reports what came out, and the numbers are the
cartridge's, not a claim about a reimplementation.

  ./voice_decode.py --check                 # the gated cases
  ./voice_decode.py --audio <clip>          # write assets/sound/mort_<clip>.wav
  ./voice_decode.py --clips                 # the bank census
"""
import argparse
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

ROM = ROOT / "rom" / "Resident Evil 2 (USA) (Rev 1).z64"
STAGE2 = ROOT / "assets" / "unpacked" / "00000_0014420_1172240.bin"
WAVDIR = ROOT / "assets" / "sound"

BASE, HEADER = 0x0C8624, 0x28
BANK_CART, BANK_SIZE = 0x0338FEA, 8560916
MORT = b"MORT"

# The synthesis, as addresses. `CODE` is FUN_800b53f4: one 160-sample block per call.
CODE = 0x800B53F4
MEMSET = 0x80006650
SENT = 0x80300000
CTX, OUT, PAY = 0x00180000, 0x00190000, 0x001A0000
RING, BLOCK_BYTES, BLOCK_SAMPLES = 0x1A0, 0x140, 160
STAGE2_MIRROR = 0x18A80          # KSEG0 0x80018a80, seen through the physical mirror


def records():
    """The 588 `MORT` records of id 1979, as (index, blocks, rate, record bytes)."""
    d = ROM.read_bytes()
    r4 = d[BANK_CART:BANK_CART + BANK_SIZE]
    n = struct.unpack_from(">I", r4, 0)[0]
    vals = struct.unpack_from(">" + str(n) + "I", r4, 4)
    offs = [v & 0xFFFFFF for v in vals] + [len(r4)]
    out = []
    for k in range(n):
        rec = r4[offs[k]:offs[k + 1]]
        if rec[:4] == MORT:
            blocks, rate, _extent4 = struct.unpack_from(">HHI", rec, 4)
            out.append((k, blocks, rate, rec))
    return out


ENGINE = "unicorn"


def _unicorn():
    try:
        from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_BIG_ENDIAN, UC_HOOK_CODE
        from unicorn.mips_const import (UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3,
                                        UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP)
    except ImportError:
        return None
    return (Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_BIG_ENDIAN, UC_HOOK_CODE,
            UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3,
            UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP)


def ensure_engine(argv=None):
    """Re-run under the project's venv when this interpreter has no emulator.

    The gates are stdlib-only and run under `sys.executable`; the emulator is a development-only package
    (`.venv`, not a dependency of any other gate). So the tool looks for one the way `t64_selftest.py`
    looks for a C compiler: try, then a known location, then say so out loud. It never quietly passes.
    """
    if _unicorn() is not None:
        return True
    venv = ROOT / ".venv"
    venv_py = venv / "bin" / "python"
    # Compare `sys.prefix`, not the executables: a venv's `bin/python` is usually a symlink to the system
    # interpreter, so resolving paths makes the two indistinguishable while the *site-packages* differ.
    if venv_py.exists() and Path(sys.prefix).resolve() != venv.resolve():
        import os
        os.execv(str(venv_py), [str(venv_py), str(Path(__file__).resolve())]
                 + (argv if argv is not None else sys.argv[1:]))
    return False


def _session(record, uc_mod):
    """A mapped 4 MiB machine with the stage-2 image, the boot `memset`, and this record's bytes."""
    (Uc, ARCH, MODE32, BE, HOOK, R_A0, R_A1, R_A2, R_A3, R_PC, R_RA, R_SP) = uc_mod
    ram = bytearray(0x400000)
    s2 = STAGE2.read_bytes()
    ram[STAGE2_MIRROR:STAGE2_MIRROR + len(s2)] = s2
    ram[0x480:0x480 + len(ROM.read_bytes()[0x1000:0x14600])] = ROM.read_bytes()[0x1000:0x14600]
    ram[PAY:PAY + len(record)] = record
    uc = Uc(ARCH, MODE32 | BE)
    uc.mem_map(0x0, len(ram))
    uc.mem_write(0x0, bytes(ram))
    uc.mem_write(CTX + 0x11C8, struct.pack(">I", 0x60))     # the reader starts at byte 12: the header
    stats = {"steps": 0, "memset": 0}
    uc.mem_write(CTX + 0x11C8, struct.pack(">I", 0x60))

    def hook(u, addr, size, data):
        # Per-block budget, not cumulative: `emu_start` is called once per block, so a running total would
        # start cutting blocks off once the clip as a whole passed the limit.
        stats["block_steps"] = stats.get("block_steps", 0) + 1
        stats["steps"] += 1
        if stats["block_steps"] > 400000:
            u.emu_stop()
        if addr == MEMSET:
            u.mem_write(u.reg_read(R_A0), bytes(u.reg_read(R_A1)))
            stats["memset"] += 1
            u.reg_write(R_PC, u.reg_read(R_RA))

    uc.hook_add(HOOK, hook)
    return uc, ram, stats


def decode(record, blocks, uc_mod, verbose=False):
    """Run the cartridge's synthesis for `blocks` blocks; returns (samples, stats)."""
    (Uc, ARCH, MODE32, BE, HOOK, R_A0, R_A1, R_A2, R_A3, R_PC, R_RA, R_SP) = uc_mod
    uc, ram, stats = _session(record, uc_mod)
    samples, silent = [], 0
    for bi in range(blocks):
        bitpos = struct.unpack(">I", uc.mem_read(CTX + 0x11C8, 4))[0]
        win = (bitpos >> 3) & ~0xFFF
        chunk = bytes(ram[PAY + win:PAY + win + 0x1000])
        uc.mem_write(CTX + RING, chunk + bytes(0x1000 - len(chunk)))
        uc.reg_write(R_SP, 0x003FF000)
        uc.reg_write(R_RA, SENT)
        uc.reg_write(R_A0, CTX)
        uc.reg_write(R_A1, OUT)
        uc.reg_write(R_A2, 0)
        uc.reg_write(R_A3, 0)
        stats["block_steps"] = 0
        uc.emu_start(CODE, SENT, count=4000000)
        blk = struct.unpack(">160h", uc.mem_read(OUT, BLOCK_BYTES))
        if not any(blk):
            silent += 1
        samples.extend(blk)
        if verbose:
            print("  block %3d  bitpos 0x%05x  peak %5d" % (bi, struct.unpack(">I", uc.mem_read(
                CTX + 0x11C8, 4))[0], max(map(abs, blk))))
    stats["silent"] = silent
    return samples, stats


def stats_of(s):
    n = len(s)
    mean = sum(s) / n
    den = sum((x - mean) ** 2 for x in s)
    r1 = (sum((s[i] - mean) * (s[i + 1] - mean) for i in range(n - 1)) / den) if den else 0.0
    return {"samples": n, "peak": max(map(abs, s)), "rms": (sum(x * x for x in s) / n) ** 0.5,
            "clipped": sum(1 for x in s if abs(x) >= 32767), "lag1": r1,
            "zero": sum(1 for x in s if x == 0)}


def write_wav(path, samples, rate):
    import wave
    path.parent.mkdir(parents=True, exist_ok=True)
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(struct.pack("<%dh" % len(samples), *samples))


CLIP = 27            # 26 blocks, 0.26 s: short enough to run in the suite, long enough to have a frame


def check():
    cases = []
    rows = records()
    cases.append(("588 `MORT` records in id 1979", len(rows) == 588))
    mod = _unicorn()
    if mod is None:
        # A loud failure, not a skip: a suite that goes quiet when its engine is missing is the failure
        # mode this repository audits. `--check` re-executes under `.venv` when it can (see
        # `ensure_engine`), so reaching here means no interpreter on this machine has the emulator.
        print("  FAIL no interpreter has %s: `.venv/bin/python` is absent and this python cannot import it"
              % ENGINE)
        print("       the audio cases need it; `python3 -m pip install unicorn` or a project venv")
        print("\n1/7 voice-decode case(s)")
        return 1
    rec = [r for r in rows if r[0] == CLIP][0]
    samples, st = decode(rec[3], rec[1], mod)
    s = stats_of(samples)
    cases.append(("clip %d decodes to %d blocks x %d samples = %d" % (CLIP, rec[1], BLOCK_SAMPLES,
                                                                    len(samples)),
                  len(samples) == rec[1] * BLOCK_SAMPLES))
    cases.append(("the synthesis ran: the silent blocks are exactly zero and the rest are not (%d/%d silent)"
                  % (st["silent"], rec[1]), 0 < st["silent"] < rec[1]))
    cases.append(("nothing is railed: %d samples at full scale, peak %d" % (s["clipped"], s["peak"]),
                  s["clipped"] == 0 and 0 < s["peak"] < 32767))
    cases.append(("it is voiced, not noise: lag-1 correlation %+.3f" % s["lag1"], s["lag1"] > 0.5))
    cases.append(("the level is a level: rms %.0f inside (0, peak]" % s["rms"],
                  0 < s["rms"] <= s["peak"]))
    cases.append(("the `memset` path was taken %d time(s), i.e. a silent run was decoded" % st["memset"],
                  st["memset"] > 0))
    passed = sum(1 for _l, ok in cases if ok)
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("\n%d/%d voice-decode case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true", help="the gated cases")
    ap.add_argument("--clips", action="store_true", help="the bank census")
    ap.add_argument("--audio", type=int, metavar="CLIP", help="decode one clip to assets/sound/")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    if not ROM.exists():
        sys.exit("cartridge not found: %s" % ROM)
    if not ensure_engine():
        sys.exit("no interpreter has %s; run under `.venv/bin/python`" % ENGINE)

    if args.check:
        return check()
    rows = records()
    if args.clips:
        print("%d records; blocks %d..%d, total %d samples (%.1f s at 16000 Hz)"
              % (len(rows), min(r[1] for r in rows), max(r[1] for r in rows),
                 sum(r[1] for r in rows) * BLOCK_SAMPLES,
                 sum(r[1] for r in rows) * BLOCK_SAMPLES / 16000))
        return 0
    if args.audio is None:
        ap.error("one of --check, --clips, --audio N")
    rec = [r for r in rows if r[0] == args.audio]
    if not rec:
        sys.exit("no MORT record with index %d" % args.audio)
    k, blocks, rate, record = rec[0]
    mod = _unicorn()
    if mod is None:
        sys.exit("the emulator (unicorn) is not importable")
    samples, st = decode(record, blocks, mod, verbose=args.verbose)
    out = WAVDIR / ("mort_%d.wav" % k)
    write_wav(out, samples, rate)
    s = stats_of(samples)
    print("clip %3d: %5d blocks -> %6d samples (%.2f s) @ %d Hz  peak %5d rms %6.0f lag1 %+.3f"
          % (k, blocks, s["samples"], s["samples"] / rate, rate, s["peak"], s["rms"], s["lag1"]))
    print("  silent blocks %d, clipped %d, steps %d, memset %d"
          % (st["silent"], s["clipped"], st["steps"], st["memset"]))
    print("  wrote %s" % out.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
