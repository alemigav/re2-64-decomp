#!/usr/bin/env python3
"""Resolve a function's source file from its ADDRESS, so a name change is not a code change.

Why this exists. Six tools cited reconstructed sources by *filename* — `"src/stage2/FUN_800b63b4.c"` in 29 places,
`"…​.c:<line>: <statement>"` in 214, and 9 joins built the path at run time. A function's name is the one thing about it
that moves: the twelve audio bodies were named from their behaviour and every one of those citations broke, which turned
the mutation audit INCONCLUSIVE (34 gates whose own tool could no longer read a file) before a single number moved.

The index is the authority, and it is committed: `manifests/code_index.json` carries `functions_list[].file` for every
address, written by `export_src.py`. So resolution needs no cartridge and cannot disagree with the tree.

Two forms, and only two:

    srcmap.path("stage2", 0x800b63b4)      -> Path("src/stage2/snd_synth_lattice.c")   # or today's provider name
    srcmap.render("@800b63b4:20: iVar6 = (int)(short)param_1[0xb3];")
                                           -> "src/stage2/snd_synth_lattice.c:20: iVar6 = …"

`@<hex>:<line>:` is the citation syntax: address first, file name never. `render()` expands it at use time and **verifies
the cited statement is still on that line**, because a citation whose line moved is a claim that has rotted.

    ./srcmap.py --self-test   # 3 cases: resolve, render, and a missing address that must name the address
    ./srcmap.py --check       # no tool may name a source file by function name (the gate this exists to earn)
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# a citation may name a statement (`@addr:12: <text>`) or just a line (`@addr:12`), which the registry does
CITE = re.compile(r"^@([0-9a-fA-F]{8}):(\d+)(?::\s*(.*))?$")
_INDEX = None


def _index(root: Path = ROOT) -> dict:
    """(image, address) -> committed path, plus address -> image for a bare citation."""
    global _INDEX
    if _INDEX is None:
        doc = json.loads((root / "manifests" / "code_index.json").read_text())
        by_addr = {}
        for img in doc["images"]:
            for f in img.get("functions_list", []):
                by_addr[(img["name"], int(f["address"], 16))] = f["file"]
        _INDEX = by_addr
    return _INDEX


class MissingFunction(Exception):
    """An address that the committed index does not carry — reported by address, never by a guessed name."""

    def __init__(self, image, addr):
        self.image, self.addr = image, addr
        super().__init__("no function at %s:%s in manifests/code_index.json "
                         "(the index is written by tools/export_src.py -- run it first?)"
                         % (image, "0x%08x" % addr))


def path(image: str, addr: int, root: Path = ROOT) -> Path:
    """The committed source path for a function, by address."""
    rel = _index(root).get((image, int(addr)))
    if rel is None:
        raise MissingFunction(image, addr)
    return Path(rel)


def find(addr: int, root: Path = ROOT) -> Path:
    """The path for an address whose image the caller does not know (a citation names only the address)."""
    hits = [rel for (img, a), rel in _index(root).items() if a == int(addr)]
    if not hits:
        raise MissingFunction("<any image>", int(addr))
    if len(hits) > 1:
        raise MissingFunction("<ambiguous: %d images>" % len(hits), int(addr))
    return Path(hits[0])


def render(text: str, root: Path = ROOT, verify: bool = True) -> str:
    """Expand a `@addr:line:` citation to `<path>:line:`, checking the statement is still on that line."""
    m = CITE.match(text)
    if not m:
        return text
    addr, line, statement = int(m.group(1), 16), int(m.group(2)), m.group(3)
    target = find(addr, root)
    if verify and statement:
        p = root / target
        if not p.exists():
            raise MissingFunction(str(target.parent.name), addr)
        lines = p.read_text(encoding="utf-8", errors="replace").splitlines()
        if not 1 <= line <= len(lines):
            raise ValueError("%s has %d lines, so %d is out of range" % (target, len(lines), line))
        norm = lambda s: re.sub(r"\s+", "", s)
        if norm(statement) not in norm(lines[line - 1]):
            raise ValueError("%s:%d no longer contains %r" % (target, line, statement))
    return "%s:%d: %s" % (target, line, statement) if statement else "%s:%d" % (target, line)


# --- the gate --------------------------------------------------------------------------------------------
FORBIDDEN = [
    ("a source path literal", re.compile(r'"src/[^"]*\.c"')),
    ("a file-name citation", re.compile(r'"[^"]*\.c:\d+')),
    ("a runtime path join", re.compile(r'"src"\s*/\s*"[a-z_0-9]+"\s*/\s*f"')),
    # M395: a bare `"FUN_xxxxxxxx.c"` joined to a src directory is still a filename, and the first version of this gate
    # missed it -- `snd_proj` and `file_table` both built one that way. A name *with a `.c` extension* is never a C
    # identifier, so this pattern has no false positives.
    ("a bare file-name literal", re.compile(r'"(?:FUN|func)_[0-9a-fA-F]{8}\.c"')),
]


def check(root: Path = ROOT) -> list[tuple[str, bool, str]]:
    """No tool may name a source file by function name. Counted, with the offending file named."""
    cases = []
    for label, rx in FORBIDDEN:
        hits = []
        for p in sorted((root / "tools").glob("*.py")):
            if p.name == Path(__file__).name:
                continue          # this file names the patterns; it does not cite a source
            for i, line in enumerate(p.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
                if rx.search(line):
                    hits.append("%s:%d" % (p.name, i))
        cases.append(("no tool names a source file by function name — %s" % label, not hits,
                      "none" if not hits else "%d: %s" % (len(hits), ", ".join(hits[:6]))))
    return cases


def self_test(root: Path = ROOT) -> int:
    cases = []
    idx = _index(root)
    if not idx:
        print("SKIP (no committed index)")
        return 3
    (image, addr), rel = next(iter(sorted(idx.items())))
    cases.append(("an address resolves to the committed path", str(path(image, addr, root)) == rel))
    cases.append(("a citation renders with the CURRENT name and keeps its line",
                  render("@%08x:1: x" % addr, root, verify=False) == "%s:1: x" % rel))
    try:
        path("stage2", 0x00000000, root)
        cases.append(("an unknown address raises and names the address", False, "no exception"))
    except MissingFunction as exc:
        cases.append(("an unknown address raises and names the address", "0x00000000" in str(exc), "ok"))
    bad = 0
    for label, ok, *_ in cases:
        print("  %s %s" % ("PASS" if ok else "FAIL", label))
        bad += 0 if ok else 1
    print("%d/%d srcmap self-test case(s)" % (len(cases) - bad, len(cases)))
    return 1 if bad else 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--path", nargs=2, metavar=("IMAGE", "ADDR"))
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.path:
        print(path(a.path[0], int(a.path[1], 16)))
        return 0
    cases = check()
    passed = 0
    for label, ok, detail in cases:
        passed += ok
        print("  %s %s — %s" % ("PASS" if ok else "FAIL", label, detail))
    print("%d/%d resolve case(s)" % (passed, len(cases)))
    return 0 if passed == len(cases) else 1


if __name__ == "__main__":
    raise SystemExit(main())
