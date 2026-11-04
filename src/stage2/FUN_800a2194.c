/* FUN_800a2194
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2194  body 0x800a2194..0x800a21a7  size 20 B
 * body sha256 247401856a4d1a409a01068a6a4a1c04f47697103b3bc04fba096829d66426bf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a2194  00821024  and $v0,$a0,$v0
 * 0x800a2198  08028856  j 0x800a2158
 * 0x800a219c  00622025  or $a0,$v1,$v0
 * 0x800a21a0  03e00008  jr $ra
 * 0x800a21a4  00001021  addu $v0,$zero,$zero
 */
