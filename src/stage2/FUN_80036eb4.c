/* FUN_80036eb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036eb4  body 0x80036eb4..0x80036ecf  size 28 B
 * body sha256 e87a40b3f425b9cc906511b4f4345e1b9b3ea36bce7e543aa067dc9dc0c9e4f2
 * EXTENT MEASURED, NOT RECONSTRUCTED: 7 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80036eb4  14400006  bne $v0,$zero,+6
 * 0x80036eb8  24020001  addiu $v0,$zero,0x0001
 * 0x80036ebc  0087182b  sltu $v1,$a0,$a3
 * 0x80036ec0  14600003  bne $v1,$zero,+3
 * 0x80036ec4  24020002  addiu $v0,$zero,0x0002
 * 0x80036ec8  03e00008  jr $ra
 * 0x80036ecc  24020003  addiu $v0,$zero,0x0003
 */
