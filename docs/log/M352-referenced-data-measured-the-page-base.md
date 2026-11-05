# M352 — `referenced_data` measured the page base, not the address (a correction and a retraction)

The byte-map arc closed at 440 B with admission at `PASS`, so the next thing worth doing was to *use* the newest
instrument critically. The first place I looked was M348's headline — and it did not survive.

## 1. The defect, measured

```
run  stage2:0x8012ffac..0x801302cf (804 B), as published in M348: 403 site(s), displacements [95/84]
  401 of the 403 are `lui rt,0x8013` + a load/store off `rt`
       the page base 0x80130000 falls INSIDE the run, which straddles the 64 KB boundary
  all 401, evaluated at base+displacement, land OUTSIDE the run
  only 2 sites -- the `addiu/ori` path, which always tested the address -- are real
class-wide: 860 sites counted, 162 land inside at base+disp -- 19 % real
```

`referenced_runs()` had two paths: `lui` + `addiu/ori`, which computed the address, and `lui` + load/store, which tested
`run_of(hi)` where `hi = imm << 16` — **the 64 KB-aligned page base**. Any run that straddles a page boundary therefore
collected every access in that page: four hundred instructions "pointing at" data none of them touches.

## 2. The fix is one line; the retraction is the milestone

Both paths now compute `base + sign_extend(displacement)`, and both record the **real** displacement (the address minus
the run start) instead of the `-1` placeholder the load path used to store. Re-derived:

```
0x8012ffac..0x801302cf   2 site(s), displacements [85]        (was 403)
referenced_data         18 928 B                              (was 16 132 B)
enclosed_data           53 016 B                              (was 55 812 B)
unclassified               440 B (0.0 %)                      (unchanged)
partition closes at    1 956 560 B ✓
```

**The class grew**, which is the honest shape of this kind of correction: it lost 401 phantom sites for one run and gained
its other runs' *true* sites, which the old rule had missed because it charged the first matching run and broke out of the
lookahead. A correction that only shrinks would have been suspicious.

## 3. Retracted by addition

`docs/log/M348-...md` keeps every number it published and gains a **"Retracted by M352"** block; the log's
`## Retractions carried by later milestones` table gets a row. Both name the mechanism — *the 64 KB page base landed
inside a straddling run* — because the number without the mechanism is just a different number.

## 4. The gate that would have caught it, and one that would have let it back in

Two pin-cases, on synthetic bodies:

```
PASS a `lui` whose page base lands in one run but whose ADDRESS lands in another counts the address, not the base
PASS the recorded displacement is the ADDRESS minus the run start, not a placeholder
```

The first is precisely M348's failure: two runs, `0x80130000..0x8013003F` and `0x80134000..0x8013403F`, and one
instruction `lui $v0,0x8013 ; lw $v0,0x4000($v0)` whose page base is in the first and whose address is the second. The old
rule charged the first, and the case fails under it.

And one mutation, so the correction cannot be undone silently: **`addr = base + sign_extend(d)` → `addr = hi`** — the
base-only test, restored. Audit **159 → 160 mutations**.

## 5. One operator error, recorded

While adding the mutation I overwrote `tools/classify_image.py` with `audit_gates.py`'s source — a `p.write_text` where
`q` was meant, inside the same script. `git checkout -- tools/classify_image.py` restored it, both edits were re-applied
to the correct file, and the byte-map suite went 20 → **22 cases** with the two straddle cases in place. Worth the line
here: the recovery was trivial because the file was committed, and the mistake would have been invisible if I had been
editing a file that was not.

## Numbers

- `referenced_data` **16 132 → 18 928 B**; `enclosed_data` 55 812 → **53 016 B**; `unclassified` **440 B (0.0 %)** unchanged
- the run M348 named: **403 → 2 sites**, displacement 85, class-wide evidence **860 → 162 real**
- byte map **20 → 22 cases**; audit **159 → 160 mutations** (0 vacuous, 0 broken); probe 136 cases
- **recovered 155 / 154 byte-exact — unchanged**; retraction recorded in two places
