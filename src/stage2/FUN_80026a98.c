/* FUN_80026a98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026a98  body 0x80026a98..0x80026aa7  size 16 B
 * body sha256 435c7962af8c2c8ed57b01fdae0da7353c4f9d6a8ce28d5802e22fb77fa00f14
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80026a98..0x80026aa7, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80026a98  3c03800f  lui $v1,0x800f
 * 0x80026a9c  24020001  addiu $v0,$zero,0x0001
 * 0x80026aa0  03e00008  jr $ra
 * 0x80026aa4  ac629130  sw $v0,-28368($v1)
 */
