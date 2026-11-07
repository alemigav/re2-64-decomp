/* FUN_800a2308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2308  body 0x800a2308..0x800a2313  size 12 B
 * body sha256 875a0e8a61234c4c447aa48f5400018ee215214a2e09d1caa386bc447fbb52bf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 3 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
 * provider none: this address is not in the decompile index, so there is no pseudocode and no provider hash
 * extents: fixtures/decomp/measured_extents.json
 */
/*
 * DISASSEMBLY LISTING — the extent is measured, the body is not reconstructed.
 *
 * These are the bytes of a function the provider never claimed, decoded word by word.
 * This file is a listing: not ours, not C, and no claim that the body is understood. It
 * exists so the census, the byte map and the coverage union can all name these bytes
 * (fixtures/decomp/measured_extents.json, M341).
 * 0x800a2308  00821024  and $v0,$a0,$v0
 * 0x800a230c  080288b7  j 0x800a22dc
 * 0x800a2310  00a22025  or $a0,$a1,$v0
 */
