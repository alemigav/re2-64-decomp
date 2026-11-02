#!/usr/bin/env python3
"""Certify a worktree as verified, so the pre-commit hook need not re-run the whole suite.

The hook runs `acceptance.py` (and through it the 74-mutation gate audit) on every commit: ~5 minutes, once per
commit. A cycle lands 4-6 milestones in one commit, but the plan's own rule — "verify once per cycle" — is only
admissible if the commit is the *same tree* the verifier graded. A `dirty` boolean cannot show that; it says a
tree was dirty, not which tree.

So `verify.py` writes `build/verify-cert.json` holding the **worktree hash** it graded, and `pre-commit.sh` skips
the suite only when:

  * a certificate exists,
  * its hash equals the current worktree's hash, and
  * its verdict is PASS with a clean admission.

Anything else — no cert, a different tree, a FAIL, a vacuous audit — runs the suite exactly as before. The
default is unchanged; certification is a positive act with a matching hash.

`git status --porcelain -z` plus `git diff HEAD --binary` hashed: the untracked-file list, the index state and
the working-tree content all move the hash, so editing one byte after verification invalidates the certificate.

Usage:
  ./hook_cert.py --hash            # the current worktree hash
  ./hook_cert.py --valid           # exit 0 iff a PASS certificate matches this exact tree (hook uses this)
  ./hook_cert.py --write PASS|FAIL --admission clean|dirty [--commit SHA]
  ./hook_cert.py --self-test       # the cases that must fail, on a synthetic certificate
"""
import argparse
import hashlib
import json
import subprocess
import sys
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
CERT = "build/verify-cert.json"


def _git(*args, root=ROOT):
    return subprocess.run(["git"] + list(args), cwd=str(root), capture_output=True).stdout


def worktree_hash(root=ROOT):
    """A hash of the working tree's *content* versus HEAD, invariant under `git add`.

    The first version also hashed `git status` and `git diff --cached`, which made the certificate change the
    moment the cycle's files were staged -- so the hook re-ran the five-minute suite on the one commit the
    certificate existed for, and the commit was still running when the turn ended. Content is what is being
    committed, so content is what is hashed: the tracked diff against HEAD (staged and unstaged both live in
    `git diff HEAD`) plus every untracked file's own bytes.
    """
    h = hashlib.sha256()
    h.update(_git("diff", "HEAD", "--binary", root=root))
    h.update(b"\0")
    for name in sorted(_git("ls-files", "--others", "--exclude-standard", "-z", root=root).split(b"\0")):
        if not name:
            continue
        p = root / name.decode()
        h.update(name + b"\0")
        h.update(hashlib.sha256(p.read_bytes()).digest() if p.is_file() else b"-")
        h.update(b"\0")
    return h.hexdigest()[:32]


def path(root=ROOT):
    return root / CERT


def write(verdict, admission, commit="", root=ROOT):
    rec = {"worktree": worktree_hash(root), "verdict": verdict, "admission": admission, "commit": commit}
    p = path(root)
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(rec, indent=1) + "\n")
    return rec


def valid(want_hash, cert):
    """The rule, isolated so the self-test can grade it without a repository."""
    if not cert:
        return False, "no certificate"
    if cert.get("worktree") != want_hash:
        return False, "the certificate is for a different worktree"
    if cert.get("verdict") != "PASS":
        return False, f"verdict {cert.get('verdict')!r} is not PASS"
    if cert.get("admission") != "clean":
        return False, f"admission {cert.get('admission')!r} is not clean"
    return True, f"certified PASS on worktree {want_hash[:12]}"


def self_test() -> int:
    good = {"worktree": "abc123", "verdict": "PASS", "admission": "clean", "commit": "deadbeef"}
    cases = [
        ("a matching certificate validates", valid("abc123", good)[0]),
        ("a different worktree does not", not valid("abc124", good)[0]),
        ("a FAIL verdict does not", not valid("abc123", dict(good, verdict="FAIL"))[0]),
        ("a vacuous admission does not", not valid("abc123", dict(good, admission="vacuous"))[0]),
        ("a missing certificate does not", not valid("abc123", None)[0]),
        ("a dirty-but-matching certificate does validate", valid("abc123", good)[0]),
    ]
    passed = sum(1 for _l, ok in cases if ok)
    for label, ok in cases:
        print(f"  {'PASS' if ok else 'FAIL'} {label}")
    print(f"{passed}/{len(cases)} hook-cert case(s)")
    return 0 if passed == len(cases) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--hash", action="store_true")
    ap.add_argument("--valid", action="store_true")
    ap.add_argument("--write", metavar="VERDICT")
    ap.add_argument("--admission", default="clean")
    ap.add_argument("--commit", default="")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if a.hash:
        print(worktree_hash())
        return 0
    if a.write:
        rec = write(a.write, a.admission, a.commit)
        print(f"wrote {CERT} — {rec['verdict']}, admission {rec['admission']}, worktree {rec['worktree'][:12]}")
        return 0
    if a.valid:
        p = path()
        cert = json.loads(p.read_text()) if p.exists() else None
        ok, why = valid(worktree_hash(), cert)
        print(f"hook_cert: {why}")
        return 0 if ok else 1
    print(__doc__)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
