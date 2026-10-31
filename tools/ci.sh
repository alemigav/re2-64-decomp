#!/bin/sh
# Continuous integration, runnable locally: `sh tools/ci.sh`.
#
# Three checks, in the order that fails fastest and most informatively:
#   1. every fixture, via tools/acceptance.py (same suite the pre-commit hook runs)
#   2. nothing that must stay out of git is tracked (ROM, extracted assets, builds, binaries)
#   3. the cartridge, when present, still hashes to the value the manifests were built from
#
# The cartridge is gitignored by design, so a fresh clone cannot supply it: check 3 reports SKIP and the
# corpus-dependent suites in check 1 report SKIP too. CI is therefore meaningful without the ROM (45 of 48
# cases) and strictly stronger with it. Exit status is non-zero on any real failure.
set -u

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
	printf 'ci: not inside a git work tree\n' >&2
	exit 1
}
cd "$root" || exit 1
status=0

printf '== fixtures\n'
python3 tools/acceptance.py || status=1

printf '\n== tracked artefacts\n'
bad=$(git ls-files | grep -E '^(rom|assets|build)/|\.(z64|n64|bin|elf)$' || true)
if [ -n "$bad" ]; then
	printf 'FAIL these must not be tracked:\n%s\n' "$bad"
	status=1
else
	printf 'none (ok)\n'
fi

printf '\n== cartridge integrity\n'
python3 - <<'PY' || status=1
import hashlib, json, sys
from pathlib import Path

rom = Path("rom/Resident Evil 2 (USA) (Rev 1).z64")
manifest = Path("build/elfs/images.json")
if not manifest.exists():
    print("SKIP no build/elfs/images.json in this checkout (build/ is gitignored)")
    sys.exit(0)
if not rom.exists():
    print("SKIP no cartridge in this checkout (gitignored by design)")
    sys.exit(0)
want = json.loads(manifest.read_text())["cart_sha256"]
got = hashlib.sha256(rom.read_bytes()).hexdigest()
print(("PASS " if got == want else "FAIL ") + "sha256 %s" % got)
print("     expected %s (build/elfs/images.json)" % want)
sys.exit(0 if got == want else 1)
PY

printf '\n'
if [ "$status" -eq 0 ]; then
	printf 'ci: ok\n'
else
	printf 'ci: FAILED\n'
fi
exit "$status"
