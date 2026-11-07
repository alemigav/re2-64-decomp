/* FUN_800a2100
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2100  body 0x800a2100..0x800a2107  size 8 B
 * body sha256 29c32c527f600f8a1732e85e347fe48328223f6ab00f857c085a73b8008d4c28
 * EXTENT MEASURED, NOT RECONSTRUCTED: 2 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x800a2100  03e00008  jr $ra
 * 0x800a2104  00001021  addu $v0,$zero,$zero
 */
