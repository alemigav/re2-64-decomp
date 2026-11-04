/* FUN_800510c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800510c4  body 0x800510c4..0x800510cf  size 12 B
 * body sha256 c79898b1e3c98cca9c5040e9186fd92437d7fd9de2517113bfc970ce932d111f
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
 * 0x800510c4  3c028011  lui $v0,0x8011
 * 0x800510c8  03e00008  jr $ra
 * 0x800510cc  ac40bc30  sw $zero,-17360($v0)
 */
