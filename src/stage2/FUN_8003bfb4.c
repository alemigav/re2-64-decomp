/* FUN_8003bfb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bfb4  body 0x8003bfb4..0x8003bfc7  size 20 B
 * body sha256 983c29b0cecfc57b78d7e095d9a963252074416a09d23d03fcaaac1f8f4608bf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003bfb4..0x8003bfc7, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003bfb4  3c02800f  lui $v0,0x800f
 * 0x8003bfb8  8c42bb94  lw $v0,-17516($v0)
 * 0x8003bfbc  a0400000  sb $zero,0($v0)
 * 0x8003bfc0  03e00008  jr $ra
 * 0x8003bfc4  a4400018  sh $zero,24($v0)
 */
