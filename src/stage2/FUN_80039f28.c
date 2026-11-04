/* FUN_80039f28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039f28  body 0x80039f28..0x80039f33  size 12 B
 * body sha256 9aadbeb4a176cfe1c332a7c21099eef9e8c967321719356097e36adfbf038560
 * EXTENT MEASURED, NOT RECONSTRUCTED: 3 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80039f28  a0600000  sb $zero,0($v1)
 * 0x80039f2c  03e00008  jr $ra
 * 0x80039f30  a4600018  sh $zero,24($v1)
 */
