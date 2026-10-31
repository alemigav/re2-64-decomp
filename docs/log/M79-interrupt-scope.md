# M79 — Scoping the interrupt context path

**Question:** what does the harness need in order to take an interrupt, run the guest's handler, and return to
the interrupted code — without executing the boot chain off the end of its stack (the M78 crash)?

The answer turns out to be narrower than "implement context switching", because **the guest already does it**.

---

## 1. What the guest handler does (disassembled, not assumed)

`E_VEC` → preamble `lui k0,0x8000 ; addiu k0,k0,0x6d0 ; jr k0` → handler at `0x800006d0`:

```
0x800006d0  lui k0, 0x8001
0x800006d4  addiu k0, k0, 0x5000      k0 = 0x80015000, a fixed exception work area
0x800006d8  sd at, 0x20(k0)          SAVES 64-BIT REGISTERS with sd
0x800006dc  mfc0 k1, $12             read Status
0x800006e0  sw k1, 0x118(k0)         Status at +0x118 (the same slot __osCurrentThread uses in a thread)
0x800006e4  addiu at, zero, -0x4
0x800006e8  and                      mask the low two bits (IE, EXL)
0x800006ec  mtc0 k1, $12             write Status back
0x800006f0  sd t0, 0x58(k0)
0x800006f4  sd t1, 0x60(k0)
0x800006f8  sd t2, 0x68(k0)
0x80000700  mfc0 t0, $13             read Cause
…
0x80000730  mfc0 t2, $9              read Count
```

Later, at `0x80000764`–`0x80000768` it does `lw k0, 0x2950(k0)` — **`__osCurrentThread`** — and copies the frame
into the thread's own context. The restore side is the mirror image already mapped in M46
(`ld at…ra`, `mtc0 $12`, `lw pc` → `mtc0 $14`, `eret`).

**Consequence:** the harness must not implement context switching. It must implement **CP0 fidelity well enough
that the guest's own save/restore round-trips**. That is a much smaller and much better-defined job.

---

## 2. The gaps, each with the evidence that it matters

| # | gap | why it matters here | effort | risk |
|---|---|---|---|---|
| G1 | **Exception *entry* semantics for a taken interrupt during a delay slot** — `Cause.BD` and `EPC = branch address` | the idle spin `0x80000518`/`0x8000051c` is a branch + delay slot, so **the very first interrupt in this system lands in the delay-slot case**. My `take_exception(pc)` sets `EPC = pc` unconditionally | small | **high** — this is the most likely single cause of the M78 unwind |
| G2 | **`sd`/`ld` are 32-bit approximations.** The handler saves with `sd` (64-bit) and restores with `ld` | every register the handler preserves goes through 64-bit store/load. If high halves are wrong, `ra` may restore wrong | medium | high |
| G3 | **`Count`/`Compare` don't advance meaningfully** — `Count` increments per instruction, `Compare` never fires in practice | the handler reads `mfc0 $9` at `0x80000730` and the profiling path compares against `0x80012140` | small | medium |
| G4 | **Interrupt taken while a host hook is executing** | `pi_dma`/`inflate` are host functions; if the tick lands "inside" one, the guest never called it and the resume point is meaningless | small | medium |
| G5 | **Multiple simultaneous pending sources** — `Cause.IP` must show all of them, not just the last | the game registers AI, SP, PI and RDB and may have several pending at once | small | low |
| G6 | **`mtc0 $12` masking in the handler expects `EXL`/`IE` semantics to be honoured** | the handler clears bits 0–1 itself and relies on the hardware not re-taking the interrupt | small | low |
| G7 | **FPU context not saved/restored** if the handler saves `fcr31`/FPRs | only matters if a thread is interrupted mid-FP work | medium | low (defer) |

Already correct and **not** in scope: `EPC`/`EXL`/`ERL` acceptance rule, `eret`, `mtc0 $14`, MI
pending-until-guest-writes-`MI_INTR`, per-thread `MI_INTR_MASK` restore, `TLBR/TLBWI/TLBWR/TLBP` as no-ops.

---

## 3. Ordered plan, with an acceptance test each

**S1 — delay-slot-correct exception entry (G1).** Track whether the instruction about to retire is a delay
slot; on take, set `EPC` to the branch address and `Cause.BD = 1`. *Acceptance:* inject PI during the idle spin
and the handler returns to `0x80000518`, not `0x0`. **Do this first — it is both the smallest and the most
likely fix.**

**S2 — real 64-bit register file (G2).** Represent GPRs as 64-bit ints; `sd`/`ld` move the full value; 32-bit
ops sign-extend per MIPS III. *Acceptance:* `sd`/`ld` round-trip of `0xDEADBEEFCAFEBABE` is exact, and the
M78 unwind no longer loses `ra`.

**S3 — Count/Compare (G3).** Tick `Count` from a cycle proxy, fire `Compare` as a timer interrupt. *Acceptance:*
`mfc0 $9` inside the handler returns a value that advances between two interrupts.

**S4 — atomic host hooks (G4).** Defer the interrupt check until after a hook returns; never take an interrupt
"inside" one. *Acceptance:* injecting during a burst of `pi_dma`/`inflate` leaves `EPC` pointing at guest code.

**S5 — multi-source `Cause.IP` (G5).** *Acceptance:* assert PI and SP together; the handler sees both bits and
clears them independently.

**Deferred:** FPU context (G7) unless the interrupt test fails with FP state.

---

## 4. Non-goals

- No host-side context switching, thread table or register file. The guest owns all of it.
- No VI model: **VI is not a registered event** in this game (only AI/SP/PI/RDB on `0x80139f10`), so a VI
  interrupt dispatches to a null handler *even on hardware*.
- No RSP/RDP/AI emulation. Injecting a *completion* for a task the game never started will not be faithful; the
  honest event source here is **PI** (a DMA the guest itself programmed) — which the harness does model.

---

## 5. Acceptance criterion for the whole piece

> Inject one PI completion at the idle spin, and the guest's own handler runs, the event table is consulted, a
> message is delivered to its registered queue, a waiting thread wakes, and execution continues **without** the
> boot chain unwinding to `0x0`.

That is testable in one run, it is falsifiable, and it is the same sequence the console performs.

---

## 6. What this is worth, honestly

If S1 alone fixes it, the payoff is large: the harness could then progress past boot on its own, and the page
diff against ares becomes meaningful for later states. If it takes S1–S5, the work is bounded (all five are
local to `mips_harness.py` plus MI) but it is **emulator work**, not RE2 work — and the oracle already answers
RE2 questions more cheaply. Worth doing if the goal is a runnable reconstruction; not worth doing if the goal is
understanding the game.
