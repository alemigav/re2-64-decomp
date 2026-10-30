#!/usr/bin/env python3
"""Partial MIPS III harness: execute one function with the real images mapped.

Scope, stated plainly: this is not a console emulator. It implements the integer
subset these functions use, maps the two known RAM images (boot bank at
0x80000480, stage-2 at 0x80018a80), maps the cartridge at KSEG1 0xB0000000 so a
`0xB0…` descriptor pointer resolves to actual ROM bytes, and replaces the loader
primitives with host hooks — inflate is Python's zlib reading emulated memory.

What that buys: a load trace produced by *running* the game's own instructions
(address arithmetic, descriptor field loads, argument setup) with only the
compression primitive supplied by the host. No thread scheduler, no video, no
interrupts; calls into the OS are stubs that return 0 and are logged.

Every run prints HOST-HOOK and STUB call lists, so what was executed and what was
faked is visible in the output rather than buried in a docstring.
"""
import struct, sys, zlib

RAM_BASE, RAM_SIZE = 0x80000000, 0x00400000
CART_BASE, CART_MASK = 0xB0000000, 0x0FFFFFFF
SENTINEL = 0xDEADBEEF

class Memory:
    def __init__(self, ram, rom):
        self.ram, self.rom = bytearray(ram), rom
    def _loc(self, a, n):
        if RAM_BASE <= a and a + n <= RAM_BASE + len(self.ram): return self.ram, a - RAM_BASE
        if CART_BASE <= a < CART_BASE + 0x04000000:
            o = a & CART_MASK
            if o + n <= len(self.rom): return self.rom, o
        raise Fault(f"unmapped {'read' if False else 'access'} at {a:#010x}+{n}")
    def read(self, a, n):
        buf, o = self._loc(a, n)
        v = int.from_bytes(buf[o:o+n], "big")
        return v
    def write(self, a, n, v):
        buf, o = self._loc(a, n)
        if isinstance(buf, bytes): raise Fault(f"write to ROM at {a:#010x}")
        buf[o:o+n] = (v & ((1 << (8*n)) - 1)).to_bytes(n, "big")

class Fault(Exception): pass

class Cpu:
    def __init__(self, mem, hooks, steps=400000):
        self.m = mem; self.hooks = hooks; self.steps = steps
        self.r = [0]*32; self.delay = None; self.pc = 0
        self.calls = []          # (kind, target, args)
        self.trace = []
    def s32(self, v): return v - (1 << 32) if v & 0x80000000 else v
    def run(self, entry, a0=0, a1=0, a2=0, a3=0, sp=0x803FF000):
        self.r = [0]*32; self.r[4], self.r[5], self.r[6], self.r[7] = a0, a1, a2, a3
        self.r[29] = sp; self.r[31] = SENTINEL
        self.pc, self.delay = entry, None
        n = 0
        while self.pc != SENTINEL and n < self.steps:
            if self.pc in self.hooks:
                fn = self.hooks[self.pc]
                self.calls.append((fn.__name__, self.pc, self.r[4:8]))
                ret = fn(self, self.r[4], self.r[5], self.r[6], self.r[7])
                self.r[2] = (ret or 0) & 0xFFFFFFFF
                self.pc = self.r[31]
                n += 1
                continue
            cur, after = self.pc, self.delay
            self.delay = None
            self.step(cur)
            self.pc = after if after is not None else cur + 4
            n += 1
        return n
    def step(self, pc):
        w = self.m.read(pc, 4); r = self.r
        op = w >> 26; rs = (w >> 21) & 0x1F; rt = (w >> 16) & 0x1F
        rd = (w >> 11) & 0x1F; imm = w & 0xFFFF
        si = imm - 0x10000 if imm >= 0x8000 else imm
        if op == 0x0F: r[rt] = (imm << 16) & 0xFFFFFFFF
        elif op == 0x09: r[rt] = (r[rs] + si) & 0xFFFFFFFF
        elif op == 0x19: r[rt] = (r[rs] + si) & 0xFFFFFFFF     # daddiu (32-bit view)
        elif op == 0x18: r[rt] = (r[rs] + si) & 0xFFFFFFFF     # daddi
        elif op == 0x37: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 8) & 0xFFFFFFFF  # ld
        elif op == 0x3F: self.m.write((r[rs] + si) & 0xFFFFFFFF, 8, r[rt])               # sd
        elif op == 0x2D: r[rt] = (r[rs] + r[rt]) & 0xFFFFFFFF  # daddu
        elif op == 0x0D: r[rt] = r[rs] | imm
        elif op == 0x0C: r[rt] = r[rs] & imm
        elif op == 0x0E: r[rt] = r[rs] ^ imm
        elif op == 0x0A: r[rt] = (0 if self.s32(r[rs]) < si else 1)
        elif op == 0x0B: r[rt] = (1 if r[rs] < (imm & 0xFFFFFFFF) else 0)
        elif op == 0x08: r[rt] = (r[rs] + si) & 0xFFFFFFFF
        elif op == 0x23: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 4)
        elif op == 0x20: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 1)
        elif op == 0x24: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 1)
        elif op == 0x21: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 2)
        elif op == 0x25: r[rt] = self.m.read((r[rs] + si) & 0xFFFFFFFF, 2)
        elif op == 0x2B: self.m.write((r[rs] + si) & 0xFFFFFFFF, 4, r[rt])
        elif op == 0x28: self.m.write((r[rs] + si) & 0xFFFFFFFF, 1, r[rt])
        elif op == 0x29: self.m.write((r[rs] + si) & 0xFFFFFFFF, 2, r[rt])
        elif op == 0x04:
            if r[rs] == r[rt]: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x05:
            if r[rs] != r[rt]: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x06:
            if self.s32(r[rs]) <= 0: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x07:
            if self.s32(r[rs]) > 0: self.delay = ((pc + 4) + (si << 2)) & 0xFFFFFFFF
        elif op == 0x01:
            kind = rt
            if kind in (0x00, 0x10) and self.s32(r[rs]) < 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind in (0x01, 0x11) and self.s32(r[rs]) >= 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind == 0x02 and self.s32(r[rs]) <= 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            elif kind == 0x03 and self.s32(r[rs]) > 0: self.delay = ((pc+4)+(si<<2)) & 0xFFFFFFFF
            else: r[31] = (pc + 8) & 0xFFFFFFFF
        elif op == 0x02: self.delay = ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        elif op == 0x03:
            r[31] = (pc + 8) & 0xFFFFFFFF
            self.delay = ((pc + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
        elif op == 0:
            f = w & 0x3F
            if f == 0: r[rd] = (r[rt] << ((w >> 6) & 0x1F)) & 0xFFFFFFFF
            elif f == 2: r[rd] = r[rt] >> ((w >> 6) & 0x1F)
            elif f == 3: r[rd] = (self.s32(r[rt]) >> ((w >> 6) & 0x1F)) & 0xFFFFFFFF
            elif f == 0x21: r[rd] = (r[rs] + r[rt]) & 0xFFFFFFFF
            elif f == 0x23: r[rd] = (r[rs] - r[rt]) & 0xFFFFFFFF
            elif f == 0x24: r[rd] = r[rs] & r[rt]
            elif f == 0x25: r[rd] = r[rs] | r[rt]
            elif f == 0x26: r[rd] = r[rs] ^ r[rt]
            elif f == 0x27: r[rd] = (~(r[rs] | r[rt])) & 0xFFFFFFFF
            elif f == 0x2A: r[rd] = (0 if self.s32(r[rs]) < self.s32(r[rt]) else 1)
            elif f == 0x2B: r[rd] = (1 if r[rs] < r[rt] else 0)
            elif f == 0x08: self.delay = r[rs]
            elif f == 0x09:
                t = r[rs]; r[rd] = (pc + 8) & 0xFFFFFFFF; self.delay = t
            else: raise Fault(f"unimplemented SPECIAL {f:#x} at {pc:#x}")
        else: raise Fault(f"unimplemented op {op:#x} at {pc:#x}")

# ---------------------------------------------------------------- driver ----
BOOT_ROM, BOOT_VA = 0x1000, 0x80000480
STAGE2_VA = 0x80018A80
DESC_TABLE = 0x80012150
REGISTRY = 0x8010B2E0

class Harness:
    def __init__(self, rom, stage2):
        self.rom = rom
        ram = bytearray(RAM_SIZE)
        # copy code AND the boot data that follows it, because the descriptor table
        # lives at ROM 0x12cd0 (vram 0x80012150) — past the code end at 0x12140.
        # Clipping at the code end silently makes every descriptor read as zeros.
        boot_len = 0x14600 - 0x1000
        ram[BOOT_VA - RAM_BASE:BOOT_VA - RAM_BASE + boot_len] = rom[0x1000:0x14600]
        ram[STAGE2_VA - RAM_BASE:STAGE2_VA - RAM_BASE + len(stage2)] = stage2
        self.mem = Memory(ram, rom)
        self.trace = []
        self.hooks = {}
        self._install()
    # ---- hooks: the compression primitive is real, the OS is stubbed --------
    def _install(self):
        st = {}
        def inflate_init(cpu, a0, a1, a2, a3):
            st[a0] = a1; return 0
        def inflate_run(cpu, a0, a1, a2, a3):
            raw = bytes(cpu.m.read(a1 + i, 1) for i in range(a3))
            try: out = zlib.decompress(raw)
            except Exception as e:
                self.trace.append({"src": a1, "dst": a2, "csize": a3, "usize": -1,
                                   "err": str(e)[:40]}); return 1
            for i, b in enumerate(out): cpu.m.write(a2 + i, 1, b)
            self.trace.append({"src": a1, "dst": a2, "csize": a3, "usize": len(out)})
            return 0
        def inflate_free(cpu, a0, a1, a2, a3): return 0
        def raw_pi_dma(cpu, a0, a1, a2, a3):
            for i in range(a3): cpu.m.write(a2 + i, 1, self.rom[(a1 + i) & CART_MASK])
            self.trace.append({"dma_cart": a1, "dma_dst": a2, "len": a3})
            return 0
        def wait(cpu, *a): return 0
        self.hooks.update({
            0x80004550: inflate_init, 0x800045DC: inflate_run, 0x80004594: inflate_free,
            0x8000C870: raw_pi_dma, 0x8000BE50: wait, 0x8000BE60: wait,
            0x80006D60: wait, 0x8000DB90: wait, 0x80006D30: wait, 0x8000C9E0: wait,
            0x8000CB60: wait, 0x8000E920: wait, 0x8000CEC0: wait, 0x8000E350: wait,
            0x800072E0: wait, 0x80007300: wait, 0x8000CC90: wait, 0x8000E4C0: wait,
            0x8000E800: wait,
        })
    def run(self, entry, **kw):
        cpu = Cpu(self.mem, self.hooks)
        n = cpu.run(entry, **kw)
        return cpu, n
    def u32(self, va): return self.mem.read(va, 4)

def main():
    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    stage2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    h = Harness(rom, stage2)

    print("=== run 1: FUN_8004d190 (stage-2 init), OS calls stubbed ===")
    h.hooks[0x8008AF6C] = lambda c, *a: 0
    h.hooks[0x80088910] = lambda c, *a: 0
    h.hooks[0x8006CB94] = lambda c, *a: 0
    h.hooks[0x80000518] = lambda c, *a: 0
    cpu, n = h.run(0x8004D190)
    print(f"  {n} instructions, {len(cpu.calls)} hook call(s): "
          f"{[c[0] for c in cpu.calls]}")
    for g, label in ((0x8010B6FC, "inflate window"), (0x801137F0, "screen w"), (0x801137F4, "screen h")):
        print(f"  {label:14} @{g:#010x} = {h.u32(g):#010x}")

    print("\n=== run 2: func_0x80000518 (the last call in FUN_8004d190, boot bank) ===")
    h.hooks.pop(0x80000518, None)   # run 1 stubbed it; remove so it actually executes
    cpu2, n2 = h.run(0x80000518)
    print(f"  {n2} instructions, hooks: "
          f"{[(c[0], format(c[1],'#010x'), [hex(x) for x in c[2]]) for c in cpu2.calls]}")
    print(f"  trace rows from this run: {len(h.trace)}")

    print("\n=== run 3: FUN_8004cbf4(desc) for every registry slot, inflate real ===")
    h.trace.clear()
    print(f"  {'slot':>4} {'desc idx':>8} {'src ptr':>11} {'csize':>9} {'dst':>11} {'usize':>9}  manifest")
    import json
    man = {m["rom_offset"]: m for m in json.load(open("assets/unpacked/manifest.json"))["members"]}
    for slot in range(9):
        idx = rom and h.mem.read(REGISTRY + slot*8, 1)
        dp = DESC_TABLE + idx*16
        before = len(h.trace)
        cpu3, n3 = h.run(0x8004CBF4, a0=dp)
        row = h.trace[before] if len(h.trace) > before else None
        if row and "src" in row:
            cartoff = row["src"] & CART_MASK
            m = man.get(cartoff)
            ok = "match" if m and m["uncompressed"] == row["usize"] else "CHECK"
            print(f"  {slot:>4} {idx:>8} {format(row['src'],'#010x')} {row['csize']:>9,} "
                  f"{format(row['dst'],'#010x')} {row['usize']:>9,}  {ok}")
        else:
            print(f"  {slot:>4} {idx:>8} — no inflate call ({n3} instructions)")
    print(f"\n  total inflate trace rows: {len(h.trace)}")

if __name__ == "__main__":
    main()
