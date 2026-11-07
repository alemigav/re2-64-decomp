# The corpus, as a build.
#
# Everything else in this repository measures. This is the part that *builds*: it compiles every reconstructed
# function with the canonical profile, links each one at the address the cartridge puts it, and stitches the results
# into an image-shaped binary — so `src/` is code that compiles and links, not only code that is described.
#
#   make            # build every image into build/corpus/
#   make check      # build, then compare every function against the cartridge
#   make test       # the fast gate the acceptance suite runs (one small image)
#   make clean      # remove the build products
#
# What this is not: a ROM. Data and unrecovered code are holes, and every image reports the share it covers rather
# than pretending to be complete. The ELF per image is the shape a static recompiler wants — an address-bearing
# image with symbols — and it is the first thing in this repository that a downstream tool could actually open.

PYTHON ?= python3
TOOLS  := tools

.PHONY: all corpus check test clean

all: corpus

corpus:
	$(PYTHON) $(TOOLS)/build_corpus.py

check: corpus
	$(PYTHON) $(TOOLS)/build_corpus.py --check

test:
	$(PYTHON) $(TOOLS)/build_corpus.py --self-test

clean:
	rm -rf build/corpus
