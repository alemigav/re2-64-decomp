#!/usr/bin/env python3
"""Header analysis for the RE2 cartridge container: compare, derive, chain.

Discovery tool, not an extractor. It answers three questions with numbers instead
of impressions:

  window   hexdump a bounded window around anchors (offsets printed, no guessing)
  compare  which bytes are constant across a set of block headers
  derive   which (offset, width, endian) field predicts block boundaries, scored
           against anchors whose boundaries are already known
  chain    walk a candidate format across a whole region and report where it breaks

The ROM is opened read-only and its sha256 is printed before and after every run,
so "the original cartridge image is immutable input" is demonstrated, not assumed.

Why anchors: the MJPEG region yielded 1 227 JPEG frames with exact boundaries by
carving ffd8ff..ffd9. Those are ground truth. A length field that predicts 1 226
consecutive transitions is a finding; one that predicts a few is a coincidence.
"""
import argparse, hashlib, json, struct, sys

def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()

def load(path):
    with open(path, "rb") as f:      # read-only, whole file, never written back
        return f.read()

def jpeg_anchors(d, lo, hi):
    """Payload starts of JPEG members inside [lo,hi), by carving SOI..EOI."""
    out, i = [], lo
    while True:
        i = d.find(b"\xff\xd8\xff", i, hi)
        if i < 0: break
        j = d.find(b"\xff\xd9", i + 2, hi)
        if j < 0: break
        out.append((i, j + 2 - i))
        i = j + 2
    return out

def rd(d, pos, width, endian):
    if pos < 0 or pos + width > len(d): return None
    return int.from_bytes(d[pos:pos + width], "big" if endian == "be" else "little")

def cmd_window(d, at, before, after):
    for addr in at:
        lo, hi = max(0, addr - before), min(len(d), addr + after)
        print(f"\n@ {addr:#09x}  (window {lo:#x}..{hi:#x})")
        for row in range(lo, hi, 16):
            b = d[row:row + 16]
            mark = ""
            if row <= addr < row + 16: mark = "  <== anchor"
            print(f"  {row:#09x}  {b.hex(' '):<47}  {mark}")

def cmd_compare(d, at, before):
    """Byte-by-byte constancy across the `before` bytes preceding each anchor."""
    rows = [d[a - before:a] for a in at]
    if not rows or min(len(r) for r in rows) < before:
        sys.exit("anchor too close to the start of the file")
    print(f"\ncomparing {before} bytes before each of {len(at)} anchors")
    print(f"{'rel':>4} {'const?':>7}  values")
    for k in range(before):
        vals = {r[k] for r in rows}
        const = "CONST" if len(vals) == 1 else f"{len(vals):>4}var"
        show = f"{list(vals)[0]:#04x}" if len(vals) == 1 else \
               " ".join(f"{v:02x}" for v in sorted(vals)[:6]) + (" …" if len(vals) > 6 else "")
        print(f"  -{before-k:>2} {const:>7}  {show}")

def cmd_derive(d, anchors, max_before=40):
    """Find which field explains anchor-to-anchor spacing, using residual distributions.

    Anchors are payload starts. For a candidate field read in either the current
    anchor's window or the *next* anchor's window, compute the residual

        r_k = (A[k+1] - A[k]) - value_k

    A real length field makes the residual nearly constant: 0 for an unpadded
    length, 8 or 9 for a big-endian trailer plus parity padding, and so on. Scoring
    by residual constancy finds a field whose block framing differs from the
    anchor spacing by a fixed overhead — which exact-match scoring cannot see, and
    which is exactly the shape this container turned out to have.

    Reading the field in the NEXT anchor's window is what discovers a trailer:
    a size stored after its payload sits before the following payload.
    """
    from collections import Counter
    A = [a for a, _ in anchors]
    if len(A) < 8: sys.exit("need at least 8 anchors")
    trans = len(A) - 1
    cands = []
    for frame in ("cur", "next"):
        for endian in ("be", "le"):
            for width in (1, 2, 3, 4):
                for rel in range(-max_before, 0):
                    vals = []
                    for k in range(trans):
                        base = A[k] if frame == "cur" else A[k + 1]
                        vals.append(rd(d, base + rel, width, endian))
                    if any(v is None for v in vals): continue
                    res = Counter(A[k + 1] - A[k] - vals[k] for k in range(trans))
                    mode, cnt = res.most_common(1)[0]
                    cands.append((cnt / trans, frame, endian, width, rel, mode,
                                  res.most_common(3)))
    cands.sort(reverse=True)
    print(f"\nderive: {trans} transitions from {len(A)} anchors")
    print(f"  {'match':>6}  {'window':>4} {'width':>5} {'endian':>6} {'rel':>5} {'residual':>9}  next-best residuals")
    for share, frame, endian, width, rel, mode, top in cands[:8]:
        print(f"  {share*100:5.1f}%  {frame:>4} {width:>5} {endian:>6} {rel:>5} {mode:>9}  "
              f"{[(r, c) for r, c in top[1:3]]}")
    best = cands[0]
    if best[0] < 0.9:
        print("  NO candidate reaches 90 % — do not extract from this spec")
        return None
    spec = {"window": best[1], "endian": best[2], "width": best[3], "rel": best[4],
            "residual": best[5], "score": best[0]}
    print("\nbest spec:", json.dumps(spec))
    return spec

def a_ok(a, b, c, extra):
    return a + b + extra == c

def cmd_chain(d, lo, hi, hlen, rel, width, endian, meaning, expect_type=None, verbose=False):
    """Walk a forward hypothesis and report where it stops.

    meaning="payload"  block = [hlen bytes][value bytes]        -> next = pos + hlen + value
    meaning="total"    block = [hlen bytes, value includes it]  -> next = pos + value
    A run that lands exactly on `hi` is evidence; one that stops early is not.
    """
    p, n, stuck = lo, 0, 0
    stops = []
    while p + hlen <= hi:
        v = rd(d, p + rel, width, endian)
        if v is None: break
        if expect_type is not None:
            got = rd(d, p, len(expect_type) // 2, "be")
            if got != int(expect_type, 16):
                stops.append(f"type {got:#010x} != {expect_type} at {p:#09x}")
                break
        nxt = p + (v if meaning == "total" else hlen + v)
        if nxt <= p or nxt > hi:
            stops.append(f"length {v:#x} at {p:#09x} overruns")
            break
        n += 1; p = nxt
    tail = (f"EXACT at region end" if p == hi else f"{hi - p:#x} bytes short")
    print(f"    chain hlen={hlen} rel={rel} w={width} {endian} {meaning}: "
          f"{n} blocks, stopped {p:#09x} ({tail})")
    for st in stops[:2]:
        print(f"      {st}")
    return n, p

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    sub = ap.add_subparsers(dest="cmd", required=True)

    w = sub.add_parser("window"); w.add_argument("--at", required=True)
    w.add_argument("--before", type=int, default=24); w.add_argument("--after", type=int, default=8)

    c = sub.add_parser("compare"); c.add_argument("--at", required=True)
    c.add_argument("--before", type=int, default=16)

    dv = sub.add_parser("derive"); dv.add_argument("--jpeg-region", required=True)
    dv.add_argument("--max-before", type=int, default=40)

    ch = sub.add_parser("chain"); ch.add_argument("--region", required=True)
    ch.add_argument("--header-len", type=int, required=True)
    ch.add_argument("--rel", type=int, required=True)
    ch.add_argument("--width", type=int, required=True)
    ch.add_argument("--endian", default="be")
    ch.add_argument("--meaning", default="length_covers_header")
    ch.add_argument("--expect-type")

    a = ap.parse_args()
    before = sha256(a.rom)
    d = load(a.rom)

    if a.cmd == "window":
        cmd_window(d, [int(x, 0) for x in a.at.split(",")], a.before, a.after)
    elif a.cmd == "compare":
        cmd_compare(d, [int(x, 0) for x in a.at.split(",")], a.before)
    elif a.cmd == "derive":
        lo, hi = (int(x, 0) for x in a.jpeg_region.split(":"))
        anchors = jpeg_anchors(d, lo, hi)
        print(f"anchors: {len(anchors)} JPEG members in {lo:#x}..{hi:#x}")
        spec = cmd_derive(d, anchors, a.max_before)
        if spec: print("\nbest spec:", json.dumps(spec))
    elif a.cmd == "chain":
        lo, hi = (int(x, 0) for x in a.region.split(":"))
        cmd_chain(d, lo, hi, a.header_len, a.rel, a.width, a.endian, a.meaning, a.expect_type, True)

    after = sha256(a.rom)
    print(f"\nROM sha256 before {before[:16]}…  after {after[:16]}…  "
          f"{'UNCHANGED' if before == after else 'MODIFIED — INVESTIGATE'}")

if __name__ == "__main__":
    main()
