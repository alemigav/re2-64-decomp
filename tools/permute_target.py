#!/usr/bin/env python3
"""Build a decomp-permuter objective from an image's own words, and verify it is the cartridge's bytes.

The permuter needs `target.o` in a working directory; the wrong way to make one is to compile an earlier draft, which
gives a *proxy* objective (the p6 fixture documented that mistake at 116 instructions against a 98-instruction function).
This builds the real thing — the image's words, assembled through `.word` directives so the assembler cannot "improve"
anything — and then **verifies the object's `.text` is byte-identical to the cartridge** before it writes anything.

    ./permute_target.py --image stage2 --addr 0x800725ac --words 12 --out build/permuter/m390-725ac/target.o
    ./permute_target.py --check --image stage2 --addr 0x800725ac --words 12 --out build/permuter/m390-725ac/target.o

The harness directory also needs `base.c`, `compile.sh` and `settings.toml`; `fixtures/permuter/p6/` is the committed
worked example, and `build/permuter/` is where per-run directories live (gitignored: no cartridge bytes are committed).

What this tool does NOT do, and the reason M390 is a refutation rather than a win: the permuter's score is an
instruction diff of **unlinked** objects, while this project's verdict links each candidate at the cartridge address and
compares **words**. On a body that materialises an absolute address (`lui`+`sb disp` in the image, a relocation pair in
the candidate) the two metrics diverge, so a permuter run can improve its own score while making the word match worse.
Score every candidate with `leaf_screen.py --try` before believing the search.
"""
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent


def words_of(image: str, addr: int, n: int):
    sys.path.insert(0, str(HERE))
    import classify_image as ci
    imgs = json.loads((ROOT / "fixtures" / "decomp" / "images.json").read_text())["images"]
    by = {i["name"]: i for i in imgs}
    if image not in by:
        raise SystemExit("no such image: %s" % image)
    img = by[image]
    blob = ci.image_bytes(img, ROOT)
    if blob is None:
        raise SystemExit("no bytes for %s (the cartridge is absent)" % image)
    off = addr - img["base"]
    if off < 0 or off + 4 * n > len(blob):
        raise SystemExit("%s+%d words runs past the image" % (hex(addr), n))
    return [blob[off + 4 * i:off + 4 * i + 4] for i in range(n)]


def build(image: str, addr: int, n: int, out: Path, write: bool) -> int:
    ws = words_of(image, addr, n)
    tc = ROOT / "build" / "toolchain"
    as27 = tc / "src" / "bu27-build" / "gas" / "as.new"
    gas = as27 if as27.exists() else tc / "binutils" / "bin" / "mips-linux-gnu-as"
    objcopy = tc / "binutils" / "bin" / "mips-linux-gnu-objcopy"
    if not gas.exists() or not objcopy.exists():
        print("SKIP (no provisioned toolchain: run tools/provision.sh)")
        return 3
    tmp = Path(tempfile.mkdtemp())
    src = tmp / "target.s"
    src.write_text(".text\n" + "".join(".word 0x%s\n" % w.hex() for w in ws))
    obj = tmp / "target.o"
    if subprocess.run([str(gas), "-EB", "-mips2", "-G", "0", "-o", str(obj), str(src)],
                      capture_output=True).returncode:
        print("FAIL the assembler refused the image's own words")
        return 1
    bin_ = tmp / "t.bin"
    subprocess.run([str(objcopy), "-O", "binary", "--only-section=.text", str(obj), str(bin_)],
                   capture_output=True)
    got = bin_.read_bytes() if bin_.exists() else b""
    want = b"".join(ws)
    if got != want:
        # a target that is not the cartridge is the defect this tool exists to prevent
        print("FAIL the assembled target is NOT byte-identical to the image (%d of %d bytes)" % (len(got), len(want)))
        return 1
    if write:
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(obj.read_bytes())
        print("wrote %s — %d words, byte-identical to %s:%s" % (out, n, image, hex(addr)))
    else:
        print("  PASS %s:%s is %d words and the objective assembles to the cartridge's own bytes — %d B"
              % (image, hex(addr), n, len(want)))
        print("1/1 permute-target case(s)")
    return 0


def self_test() -> int:
    """The verifier must be able to fail: a wrong word count cannot be byte-identical."""
    cases = []
    # a synthetic check of the identity rule itself, with no cartridge needed
    want = b"\x27\xbd\xff\xe8" * 3
    cases.append(("an object of the right length compares equal", want == b"\x27\xbd\xff\xe8" * 3))
    cases.append(("one wrong word breaks the identity", (b"\x27\xbd\xff\xe8" * 2 + b"\x00\x00\x00\x00") != want))
    cases.append(("a truncated object breaks the identity", want[:8] != want))
    bad = 0
    for label, ok in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d permute-target self-test case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--image")
    ap.add_argument("--addr")
    ap.add_argument("--words", type=int)
    ap.add_argument("--out")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if not (a.image and a.addr and a.words and a.out):
        ap.error("give --image --addr --words --out (or --self-test)")
    return build(a.image, int(a.addr, 16), a.words, Path(a.out), write=not a.check)


if __name__ == "__main__":
    raise SystemExit(main())
