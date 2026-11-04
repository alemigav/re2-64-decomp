# M317 — the 4-word set: 9 of 17, and four of the misses were one known residue

The second singles batch, one draft each. **Nine of seventeen landed**, taking the corpus to **103 recovered / 102
exact**.

## What landed

| shape | site |
|---|---|
| `return *(u32 *)0x800C7640;` | `stage2:0x80025b0c` |
| `return *(u32 *)(*(u32 *)(p + 4) + 44) - d;` | `stage2:0x8002fcc0` |
| `v = p[27] \| b; *(u32 *)(p + 24) = v; return v;` | `stage2:0x800341dc` |
| `return *(s16 *)0x80139A78;` | `stage2:0x800434b8` |
| `p[4]=a; p[5]=b; p[6]=c;` | `stage2:0x8004789c` |
| `*(u8 *)0x80143F08 = 1;` | `stage2:0x800a5cfc` |
| `*(u8 *)0x80136311 = 42;` | `stage2:0x800a860c` |
| `v = *p << 8; *p = v; return v;` | `stage2:0x800ab504` |
| `p[4]=a; p[5]=b; *(u16 *)(p+6)=0;` | `ovl_0087352:0x80165c58` |

## The misses, and one that was mine

- **Four of the seven are the delay-slot sinking residue**: the three hardware-register accesses
  (`0xA4600010`, `0xA4040010` twice) and `boot:0x8000e7f0` from the last batch. The image emits
  `lui; ori; jr ra; <access>` — the access **sunk into the delay slot** — and we emit `lui; ori; <access>; jr ra`.
  The three here were written with `volatile`, which *forbids* the scheduler to move the access, so it is possible
  the original simply did not qualify them; that is a second hypothesis and was not spent under the one-draft rule.
- **One is a real source unknown**: `stage2:0x8006b364` is `sltu v0,a0,a1; subu v0,a1,a0; jr ra; nop` — the `sltu`
  result is dead in the extent, so either the extent is truncated or the construct is something the four words do
  not reveal.
- **Two were my reading errors, both caught by decoding rather than by eye**:
  - `ovl_0087352:0x80165c58`'s delay slot is `sh **zero**` (`a4800006`), not the pointer (`a4840006`) — the same
    "store 0" shape as its 3-word neighbour already banked;
  - one draft had a duplicated `typedef u8` from my generator, which cc1 rejected outright.

## Rate and what it says

| batch | drafts | landed |
|---|---|---|
| 3-word set (M316) | 16 | **16** |
| 4-word set (M317) | 17 | **9** |
| all singles so far | 33 | **25** |

The screen's yield drops as soon as bodies are four words rather than three: 3-word functions are single
statements, while 4-word functions start needing **a second value live across the return** — which is where the
delay-slot/scheduling residues and the dead-`sltu` case both live. So the singles route is worth running at
**3 words exhaustively** and sampling at 4; the remaining screened pool is 55 candidates at 4–8 words.

## Numbers

- **recovered 94 → 103**, byte-exact **93 → 102**
- compile probe **80 → 89 cases** (89/89 pass); tree **73 suites / 1 064 cases** (778 need the cartridge)
- `SINGLES` in `tools/compile_probe.py` now carries 25 entries; registration was data only
