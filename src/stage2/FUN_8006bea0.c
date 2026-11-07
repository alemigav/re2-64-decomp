/* FUN_8006bea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bea0  body 0x8006bea0..0x8006beb3  size 20 B
 * body sha256 aea75c3053cd4e0f9365d69c0a63663fda9d21815381f137b8f538c672785dd6
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8006bea0..0x8006beb3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006bea0  3c028014  lui $v0,0x8014
 * 0x8006bea4  8c429e60  lw $v0,-24992($v0)
 * 0x8006bea8  30420060  andi $v0,$v0,0x0060
 * 0x8006beac  03e00008  jr $ra
 * 0x8006beb0  0002102b  sltu $v0,$zero,$v0
 */
