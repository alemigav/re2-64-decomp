# M353 — P19: the phase table catches up with twenty-one milestones

`progress_map.py` parses the front page's phase table and draws one bar per row, so the table's range *is* the picture's
range. It stopped at **P18 (M308–M331)**, which meant every bar after M331 was missing — the same debt M332 paid for P18,
one arc later, and now **21 milestones deep**.

## The row

```
| P19 | M332–M352 | the front page, the last functions, and the byte map closed: the README split into a short page and
      a dense companion; the duplicate cohorts banked +25 functions from five shapes, three of them closed by statement
      order rather than expression; then the twelve-milestone byte-map arc — unclassified 330 176 B (16.9 %) → 440 B
      (0.0 %), eleven measured classes each earned by a rule the audit mutates, and the last nine runs read by hand;
      and admission unparked to PASS (160/160, 0 vacuous, 0 broken), which immediately caught a class measuring a 64 KB
      page base instead of an address |
```

and the regenerated record panel:

```
P16  M251│███████│ 50
P17  M301│█│ 7
P18  M308│███│ 24
P19  M332│███│ 21          <- new, and the panel's header now reads M0–M352
```

## What the row had to say, and one stale number beside it

The phase table is a *summary that is allowed to be short*, so the row names the three things that actually changed the
project in this window: the front page became two documents; the cohort mechanic banked **+25 functions from five shapes**
(three of them closed by **statement order**, which is the reusable part); and the byte map went from *policy* to
*partition* — `unclassified` **330 176 B (16.9 %) → 440 B (0.0 %)**, with eleven measured classes and admission at `PASS`.

Regenerating the panel also exposed a stale figure **next to it**: the paragraph above the map still said *"the 59 cohort
copies and 55 singles"* while the corpus had reached **84 copies of twelve proven shapes** (16 hand + 55 singles + 84
copies = 155). Fixed in the same edit — a picture is not the only thing that rots when it is not regenerated, and the
sentence describing what the picture draws rots the same way.

## Verification

`progress_map.py --check` passes (the block matches the table), the panel's last bar is P19 with 21 milestones, its header
reads **M0–M352**, `counts.py --check` 26/26, `check_markers.py` 25/25, and `verify.py --full` is `PASS`.

## Numbers

- **P19 = M332–M352**, 21 milestones; the record panel now covers **M0–M352** (was M0–M331)
- one stale figure fixed beside it: **59 → 84** cohort copies
- no corpus change: **recovered 155 / 154 byte-exact**, `unclassified` **440 B (0.0 %)**, **15 classes**
