#!/usr/bin/env python3
"""The `SND_SMPDIR` record, decoded — and the frame grid the shipped decoder skips six frames past.

M184 framed id 1983 as **1 192 samples tiled exactly**, and M189-M199 decoded them with a 40-byte-frame
codec read as *two 20-byte runs, each headed by a predictor byte after two history samples*. Two things in
that description are wrong, and both are measurable without a reference implementation:

  * **the per-sample prefix is 16 bytes, not 256.** Every stored length is `16 + 40*N` — **1192 of 1192** are
    `16 (mod 40)` — and the frame grid begins at that 16-byte boundary: the predictor byte is legal
    (`high nibble <= 7`, `low nibble <= 12`) on **97-99.5 %** of frames at phase 16 and on at most **75 %** at
    any other phase. The 256-byte **codebook** is real and belongs to sample 0's extent, which is why 256
    looked like the prefix: `256 = 6*40 + 16`, so a 256-byte skip stays frame-aligned and silently **drops the
    first six frames of every sample after the first** — 384 samples per sample, never decoded.
  * **that skip is what hides a malformed header.** The byte the two-run reading takes as the *second* run's
    predictor is `>= 0x80` on frame 0 of **556** samples. A decoder that starts at frame 0 must decide what
    that byte is; the shipped one never sees it, because frame 0 is one of the six it skips.

The record itself is now fully decoded — `index, offset, 15360, rate, byte 3, u24 count, f1, f2` — with two of
those constants on all 1192 (`15360` and the codec byte `3`), and the last two fields are **positions inside
the sample**: both are below the declared count on 1192 and 1189 of 1192.

`f1`/`f2` are the sampler's **loop candidates**, and this file refuses to call them loop points: **1005** of
the 1192 records carry the pair `(2, 0)`, which reads as *no loop*, and of the **187** with `f2 > 0` only
**123** satisfy `f1 < f2` — 64 do not, and no ordering convention fixes all of them.

What is *not* claimed: that `f1`/`f2` are loop start/end, what the 16-byte prefix holds (it is not a seed for
frame 0's history and not a copy of the previous sample — both tested and refuted here), and that the frame-0
byte 24 is damage rather than a different block form.

Usage:
  ./smpdir.py --write     # regenerate manifests/smpdir.json
  ./smpdir.py --check     # validate the committed artefact against a fresh derivation
  ./smpdir.py --list      # print the record census
"""
import argparse
import importlib.util
import json
import struct
import sys
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
OUT = Path("manifests") / "smpdir.json"
SCHEMA = "smpdir/1"

_spec = importlib.util.spec_from_file_location("sound_decode", HERE / "sound_decode.py")
SD = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(SD)

RECORD = 28
FRAME = 40
SAMPLES_PER_FRAME = 64
PREFIX = 16                 # measured: the frame grid starts here in every sample but the first
BOOK = 256                  # the codebook, inside sample 0's extent
PHASE_SAMPLE = 32           # how many clips the phase sweep covers (1192 x 40 phases is not worth its cost)


def records(directory):
    """The 28-byte record, every field: `index, offset, const, rate, codec, count, f1, f2`."""
    out = []
    for k in range(len(directory) // RECORD):
        at = k * RECORD
        out.append({
            "index": struct.unpack_from(">H", directory, at)[0],
            "offset": struct.unpack_from(">I", directory, at + 4)[0],
            "const12": struct.unpack_from(">H", directory, at + 12)[0],
            "rate": struct.unpack_from(">H", directory, at + 14)[0],
            "codec": directory[at + 16],
            "count": struct.unpack_from(">I", directory, at + 16)[0] & 0x00FFFFFF,
            "f1": struct.unpack_from(">I", directory, at + 20)[0],
            "f2": struct.unpack_from(">I", directory, at + 24)[0],
            "zero2": struct.unpack_from(">H", directory, at + 2)[0],
            "zero8": struct.unpack_from(">I", directory, at + 8)[0],
        })
    return out


def legal_header(byte):
    """A predictor byte: the top nibble indexes one of the book's 8 predictors, the low nibble biases a shift."""
    return (byte >> 4) <= 7 and (byte & 0xF) <= 12


def phase_sweep(data, off, length):
    """The fraction of frame headers that are legal at each of the 40 possible phases."""
    best = {}
    for phase in range(FRAME):
        body = data[off + phase:off + length]
        frames = len(body) // FRAME
        if frames < 8:
            continue
        ok = sum(1 for i in range(frames) for r in (0, 1)
                 if legal_header(body[i * FRAME + 8 + r * 16]))
        best[phase] = round(ok / (frames * 2), 3)
    return best


def derive():
    d, directory, data = SD.load()
    rows = records(directory)
    ends = [r["offset"] for r in rows[1:]] + [len(data)]
    for i, r in enumerate(rows):
        r["stored"] = ends[i] - r["offset"]

    lengths_mod = Counter(r["stored"] % FRAME for r in rows)
    prefixes = [PREFIX if r["index"] > 1 else BOOK for r in rows]
    frames = [(r["stored"] - p) // FRAME for r, p in zip(rows, prefixes)]
    slack = [f * SAMPLES_PER_FRAME - r["count"] for f, r in zip(frames, rows)]

    sweep = {}
    for k in range(0, len(rows), max(1, len(rows) // PHASE_SAMPLE)):
        r = rows[k]
        phases = phase_sweep(data, r["offset"], r["stored"])
        if phases:
            top = max(phases.values())
            sweep[str(r["index"])] = {
                "best_phase": max(phases, key=phases.get),
                "best": top,
                "best_other_phase": max(v for p, v in phases.items() if p != PREFIX),
            }

    # frame 0's two predictor bytes: the two-run reading needs both to be legal, and on about half the bank
    # neither is -- so the *first* frame is not a well-formed frame, whichever reading you take
    run0, run1 = [], []
    for r in rows:
        at = r["offset"] + prefixes[r["index"] - 1]
        if at + FRAME <= len(data):
            run0.append(data[at + 8])
            run1.append(data[at + 24])

    loop_pair = Counter((r["f1"], r["f2"]) for r in rows)
    nonzero = [r for r in rows if r["f2"] > 0]
    ordered = [r for r in nonzero if r["f1"] < r["f2"]]

    # the refutations that keep the 16-byte prefix open
    seed = 0
    for k in range(1, len(rows)):
        r = rows[k]
        at = r["offset"]
        pre = struct.unpack(">8h", data[at:at + 16])
        f0 = struct.unpack(">4h", data[at + 16:at + 24])
        if (pre[6], pre[7]) == (f0[0], f0[1]):
            seed += 1
    tail_copy = 0
    for k in range(1, min(64, len(rows))):
        pre = data[rows[k]["offset"]:rows[k]["offset"] + 16]
        if data[rows[k - 1]["offset"]:rows[k]["offset"]].find(pre) >= 0:
            tail_copy += 1

    return {
        "tool": "smpdir.py",
        "schema": SCHEMA,
        "inputs": {
            "directory": "cartridge id 1982 (SND_SMPDIR), %d x %d B + terminator" % (len(rows), RECORD),
            "sample_data": "cartridge id 1983, %d B" % len(data),
            "rule": "a record is `u16 index | u16 0 | u32 offset | u32 0 | u16 15360 | u16 rate | u8 3 | "
                    "u24 count | u32 f1 | u32 f2`; the frame grid starts %d B into a sample (the first "
                    "sample's extent carries the %d-byte codebook first)" % (PREFIX, BOOK),
        },
        "record_fields": {
            "index_sequential": [r["index"] for r in rows] == list(range(1, len(rows) + 1)),
            "const12_values": dict(Counter(r["const12"] for r in rows)),
            "codec_values": dict(Counter(r["codec"] for r in rows)),
            "zero2_all": all(r["zero2"] == 0 for r in rows),
            "zero8_all": all(r["zero8"] == 0 for r in rows),
            "rates": len(set(r["rate"] for r in rows)),
            "count_range": [min(r["count"] for r in rows), max(r["count"] for r in rows)],
        },
        "prefix": {
            "measured": PREFIX,
            "stored_length_mod_40": dict(sorted(lengths_mod.items())),
            "phase_sweep": sweep,
            "codebook_bytes": BOOK,
            "codebook_holds_sample_zero": rows[0]["offset"] == 0,
        },
        "grid": {
            "frames": [min(frames), max(frames)] if frames else None,
            "samples_available_minus_declared": [min(slack), max(slack)],
            "slack_median": sorted(slack)[len(slack) // 2],
            "declared_count_fits_below_grid": sum(1 for v in slack if v >= 0),
        },
        "frame_zero": {
            "run0_header_illegal": sum(1 for b in run0 if not legal_header(b)),
            "run1_header_illegal": sum(1 for b in run1 if not legal_header(b)),
            "run0_header_0xff": sum(1 for b in run0 if b == 0xFF),
            "run1_header_over_0x7f": sum(1 for b in run1 if b >= 0x80),
            "samples": len(run1),
            "hidden_by_the_256_skip": True,
        },
        "loop_candidates": {
            "pair_(2,0)_records": loop_pair[(2, 0)],
            "f2_positive": len(nonzero),
            "f1_lt_f2": len(ordered),
            "f1_ge_f2": len(nonzero) - len(ordered),
            "f1_below_count": sum(1 for r in rows if r["f1"] < r["count"]),
            "f2_below_or_equal_count": sum(1 for r in rows if r["f2"] <= r["count"]),
            "distinct_pairs": len(loop_pair),
        },
        "prefix_refutations": {
            "seed_for_frame0": seed,
            "seed_trials": len(rows) - 1,
            "literal_copy_of_previous_sample": tail_copy,
            "copy_trials": min(63, len(rows) - 1),
        },
        "reading": "the record is decoded and two of its fields are constants on all **%d** records (15360 and "
                   "the codec byte 3); every stored length is `16 (mod 40)` and the frame grid sits at that "
                   "16-byte boundary (**97-99.5 %%** legal headers against **<=75 %%** at any other phase), so "
                   "the %d-byte skip the decoder performs is **six frames too far** on every sample after the "
                   "first. `f1`/`f2` are positions inside the sample but are **not established as loop points**: "
                   "%d records carry `(2,0)` and %d of the %d with `f2 > 0` are ordered."
                   % (len(rows), BOOK, loop_pair[(2, 0)], len(ordered), len(nonzero)),
        "not_claimed": [
            "that f1/f2 are loop start and end: 64 of the 187 records with f2 > 0 have f1 >= f2, and no "
            "ordering convention repairs all of them",
            "what the 16-byte prefix holds: it is neither a seed for frame 0's history (2 of 1191 match) nor a "
            "literal copy of the previous sample's bytes (0 of 63)",
            "that frame 0's illegal predictors are damage rather than a different block form for the first "
            "frame of those samples -- it is reported, with both runs' counts, and neither reading is adopted",
            "anything about how the samples sound",
        ],
    }


def normalise(obj):
    return json.dumps(json.loads(json.dumps(obj)), sort_keys=True)


def check(committed):
    fresh = derive()
    f = fresh["record_fields"]
    p = fresh["prefix"]
    g = fresh["grid"]
    t = fresh["frame_zero"]
    loop = fresh["loop_candidates"]
    cases = []

    cases.append((f"the record is fully decoded and both constants hold on all 1192 "
                  f"(15360 = {f['const12_values']}, codec = {f['codec_values']})",
                  f["const12_values"] == {15360: 1192} and f["codec_values"] == {3: 1192}
                  and f["zero2_all"] and f["zero8_all"] and f["index_sequential"]
                  and normalise(committed) == normalise(fresh)))

    cases.append((f"every stored length is 16 mod 40 ({p['stored_length_mod_40']}), so a sample is "
                  f"`16 + 40*N` and not `256 + 40*N`",
                  p["stored_length_mod_40"] == {16: 1192} and p["measured"] == 16))

    sweeps = p["phase_sweep"].values()
    cases.append((f"the frame grid is at phase 16: legal headers on {min(s['best'] for s in sweeps):.3f} to "
                  f"{max(s['best'] for s in sweeps):.3f} of frames there, at most "
                  f"{max(s['best_other_phase'] for s in sweeps):.3f} anywhere else",
                  all(s["best_phase"] == 16 for s in sweeps)
                  and min(s["best"] for s in sweeps) > 0.85
                  and max(s["best_other_phase"] for s in sweeps) < 0.82))

    cases.append((f"the 256-byte codebook sits inside sample 0's extent, which is why 256 looked like the "
                  f"prefix ({p['codebook_bytes']} = 6*40 + 16)",
                  p["codebook_holds_sample_zero"] and p["codebook_bytes"] == 256))

    cases.append((f"6 frames = 384 samples per sample are skipped by that prefix on every sample after the "
                  f"first, and the declared counts sit {g['samples_available_minus_declared'][0]}.."
                  f"{g['samples_available_minus_declared'][1]} below the grid (median {g['slack_median']})",
                  g["declared_count_fits_below_grid"] == 1192
                  and 100 <= g["samples_available_minus_declared"][0]
                  and g["samples_available_minus_declared"][1] < 640))

    cases.append((f"frame 0 is not a well-formed frame on about half the bank: its run-0 predictor is illegal "
                  f"on {t['run0_header_illegal']} samples ({t['run0_header_0xff']} of them 0xff) and its run-1 "
                  f"predictor on {t['run1_header_illegal']} ({t['run1_header_over_0x7f']} of them over 0x7f) — "
                  f"and the 256-byte skip is why no run has ever seen either",
                  t["run0_header_illegal"] == 568 and t["run1_header_illegal"] == 582))

    cases.append((f"f1/f2 are positions inside the sample: below the declared count on "
                  f"{loop['f1_below_count']} and {loop['f2_below_or_equal_count']} of 1192",
                  loop["f1_below_count"] == 1192 and loop["f2_below_or_equal_count"] == 1192))

    cases.append((f"they are NOT established as loop points: {loop['pair_(2,0)_records']} records carry the "
                  f"no-loop pair (2,0), and only {loop['f1_lt_f2']} of the {loop['f2_positive']} with f2 > 0 "
                  f"are ordered ({loop['f1_ge_f2']} are not)",
                  loop["pair_(2,0)_records"] == 1005 and loop["f2_positive"] == 187
                  and loop["f1_lt_f2"] == 123 and loop["f1_ge_f2"] == 64))

    ref = fresh["prefix_refutations"]
    cases.append((f"the 16-byte prefix is not a seed and not a copy (seed {ref['seed_for_frame0']} of "
                  f"{ref['seed_trials']}, copy {ref['literal_copy_of_previous_sample']} of {ref['copy_trials']})",
                  ref["seed_for_frame0"] <= 5 and ref["literal_copy_of_previous_sample"] == 0))

    cases.append(("every decoder says what is not claimed",
                  len(committed["not_claimed"]) >= 4))
    return cases


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--list", action="store_true")
    a = ap.parse_args()

    if not SD.ROM.exists():
        print("SKIP (needs the cartridge)")
        return 0

    if a.write:
        rep = derive()
        OUT.write_text(json.dumps(rep, indent=1, sort_keys=True) + "\n")
        print("wrote %s — prefix %d, lengths %s, slack %s, loop pairs (2,0)=%d ordered=%d/%d"
              % (OUT, rep["prefix"]["measured"], rep["prefix"]["stored_length_mod_40"],
                 rep["grid"]["samples_available_minus_declared"],
                 rep["loop_candidates"]["pair_(2,0)_records"], rep["loop_candidates"]["f1_lt_f2"],
                 rep["loop_candidates"]["f2_positive"]))
        return 0

    if a.list:
        rep = derive()
        print("record fields:", json.dumps(rep["record_fields"]))
        print("prefix:", rep["prefix"]["measured"], "lengths mod 40:", rep["prefix"]["stored_length_mod_40"])
        print("grid slack:", rep["grid"]["samples_available_minus_declared"], "median", rep["grid"]["slack_median"])
        print("frame0 byte24 >= 0x80 on:", rep["two_run_reading"]["frame0_second_header_over_0x7f"], "samples")
        print("loop candidates:", json.dumps(rep["loop_candidates"]))
        for k, v in list(rep["prefix"]["phase_sweep"].items())[:4]:
            print("   sample", k, v)
        return 0

    if not a.check:
        ap.error("one of --write, --check, --list is required")
    committed = json.loads((ROOT / OUT).read_text())
    cases = check(committed)
    bad = 0
    for label, ok in cases:
        bad += not ok
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
    print("%d/%d smpdir case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
