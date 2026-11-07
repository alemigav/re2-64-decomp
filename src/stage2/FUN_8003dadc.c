/* FUN_8003dadc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dadc  body 0x8003dadc..0x8003daf3  size 24 B
 * body sha256 c8830e3cb9be5892cace18fbd07ec0b1e0dffc54f4e80ed72b49dac4668608bd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003dadc..0x8003daf3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003dadc  3c02800f  lui $v0,0x800f
 * 0x8003dae0  8c43bb94  lw $v1,-17516($v0)
 * 0x8003dae4  9462003a  lhu $v0,58($v1)
 * 0x8003dae8  24420087  addiu $v0,$v0,0x0087
 * 0x8003daec  03e00008  jr $ra
 * 0x8003daf0  a462003a  sh $v0,58($v1)
 */
