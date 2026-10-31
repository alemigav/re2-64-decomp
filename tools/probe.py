#!/usr/bin/env python3
"""One-command interrupt probe: inject a device interrupt, log what the guest does.

Consolidates the ad-hoc experiment scripts used during M78-M79 so any of those results can be
reproduced with a single command.

Two lessons from that work are baked in, because getting either wrong produces misleading
results rather than errors:

  * NEVER write MI_INTR_MASK. The guest restores it from the thread context on every dispatch
    (M47), so a host write survives only until the next context restore - pending stays set,
    the mask loses the bit, and the interrupt silently stops firing (M79 §10).
  * Assert the PENDING line only, and let the guest's own handler clear it by writing
    MI_INTR. Acknowledging on the host's side before the handler reads the register makes the
    handler mis-identify the source.

Examples
--------
  # boot to idle, then inject PI completions and report every queue post with attribution
  python3 tools/probe.py

  # log t3 (r10 is used by this handler's exit) at the handler's indirect jump
  python3 tools/probe.py --reg 10@0x800009bc

  # watch a specific address and use AI as the source
  python3 tools/probe.py --irq-source ai --watch 0x80139f10

  # no interrupts at all: just report where the system settles
  python3 tools/probe.py --irq-source none
"""
import argparse, collections, os, sys

sys.path.insert(0, os.path.dirname(__file__))
import run_guest_sched as P
from mips_harness import Cpu, SENTINEL, Fault, RAM_BASE

SOURCES = {"sp": 0x01, "si": 0x02, "ai": 0x04, "vi": 0x08, "pi": 0x10, "dp": 0x20}
QUEUES = {"event 0x80139f10": 0x80139F10, "q9 0x8012bd30": 0x8012BD30, "q1 0x8012bcf8": 0x8012BCF8}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--entry", type=lambda s: int(s, 0), default=0x80000520,
                    help="default 0x80000520 = main (installs the vectors)")
    ap.add_argument("--steps", type=int, default=1_000_000)
    ap.add_argument("--irq-source", default="pi", choices=sorted(SOURCES) + ["none"])
    ap.add_argument("--irq-every", type=int, default=300_000,
                    help="re-assert the pending line every N instructions")
    ap.add_argument("--watch", action="append", default=None,
                    help="address to watch for writes (repeatable); default: the three queues")
    ap.add_argument("--reg", action="append", default=None,
                    help="log REG@PC, e.g. --reg 10@0x800009bc (r10 at that instruction)")
    a = ap.parse_args()

    rom = open("rom/Resident Evil 2 (USA) (Rev 1).z64", "rb").read()
    s2 = open("assets/unpacked/00000_0014420_1172240.bin", "rb").read()
    mem = P.build(rom, s2, with_ipl3=True)
    log = []
    hooks = P.hooks_for(mem, log)
    cpu = Cpu(mem, hooks)
    cpu.r[29] = 0x803FF000; cpu.r[31] = SENTINEL; cpu.pc = a.entry; cpu.delay = None

    watch = [int(x, 0) for x in (a.watch or [])] or list(QUEUES.values())
    watch_names = {}
    for name, q in QUEUES.items():
        for off in range(0, 0x18, 4):
            watch_names[q + off] = f"{name}+{off:#04x}"
    for w in watch:
        watch_names.setdefault(w, f"{w:#010x}")

    regs = []
    for spec in (a.reg or []):
        r, pc = spec.split("@")
        regs.append((int(r, 0), int(pc, 0)))

    bit = SOURCES.get(a.irq_source, 0)
    writes, excs, reglog, posts = [], [], [], []
    n, faults = 0, []
    while n < a.steps:
        if cpu.pc == SENTINEL:
            break
        if bit and n and n % a.irq_every == 0:
            mem.assert_device(bit)            # pending only; the mask stays guest-owned
        cpu.hw_pending = (cpu.hw_pending & ~0x400) | mem.rcp_asserted()
        if cpu.interrupt_pending():
            th = mem.read(0x80012950, 4)
            in_delay = cpu.delay is not None
            cpu.pc = cpu.interrupt_entry()
            excs.append((n, cpu.epc, in_delay, th, cpu.pc))
            n += 1
            continue
        for r, p in regs:
            if cpu.pc == p:
                reglog.append((n, p, r, cpu.r[r], mem.read(0x80012950, 4)))
        if cpu.pc in hooks:
            out = hooks[cpu.pc](cpu, *cpu.r[4:8])
            cpu.r[2] = (out or 0) & 0xFFFFFFFF
            cpu.pc = cpu.r[31]; n += 1
            continue
        cur, after = cpu.pc, cpu.delay
        cpu.delay = None
        try:
            cpu.step(cur)
        except Fault as e:
            faults.append((n, cur, str(e))); break
        cpu.pc = cpu.jump_now if cpu.jump_now is not None \
            else (after if after is not None else cur + 4)
        cpu.jump_now = None
        n += 1

    print(f"entry {a.entry:#x}: {n:,} instructions; faults={faults or 'none'}")
    print(f"interrupts taken: {len(excs)}  (source {a.irq_source}"
          + (f", pending 0x{bit:02x}, every {a.irq_every:,})" if bit else ")"))

    if excs:
        print(f"  {'instr':>9} {'EPC':>11} {'BD':>5} {'thread':>11}")
        for st, epc, bd, th, vec in excs[:8]:
            print(f"  {st:>9,} {format(epc, '#010x'):>11} {str(bd):>5} {format(th, '#010x')}")
    if reglog:
        print("\nregister log:")
        for st, pc, r, val, th in reglog[:12]:
            print(f"  instr {st:>9,}  pc {pc:#010x}  r{r} = {val:#018x}  thread {th:#x}")

    print("\nqueue state:")
    for name, q in QUEUES.items():
        print(f"  {name:16s} validCount={mem.read(q + 8, 4):<3} "
              f"mtqueue={mem.read(q, 4):#010x} msg={mem.read(q + 0x14, 4):#010x}")
    print(f"  current thread {mem.read(0x80012950, 4):#010x}   "
          f"run queue {mem.read(0x80012948, 4):#010x}   "
          f"MI pending {mem.mi_pending:#04x} mask {mem.mi_mask:#06x} (mask is guest-owned)")
    print(f"  host primitives used: {dict(collections.Counter(e[0] for e in log))}")


if __name__ == "__main__":
    main()
