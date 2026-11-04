/* FUN_80071df0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071df0  body 0x80071df0..0x80071e13  size 36 B
 * body sha256 de9567b2d0664402cbad55a0a9406162669d6e9cb06d80b29ded93c2f78e7c27
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80071df0  8c82001c  lw $v0,28($a0)
 * 0x80071df4  8c830154  lw $v1,340($a0)
 * 0x80071df8  90420001  lbu $v0,1($v0)
 * 0x80071dfc  a06201e9  sb $v0,489($v1)
 * 0x80071e00  8c82001c  lw $v0,28($a0)
 * 0x80071e04  24420002  addiu $v0,$v0,0x0002
 * 0x80071e08  ac82001c  sw $v0,28($a0)
 * 0x80071e0c  03e00008  jr $ra
 * 0x80071e10  24020001  addiu $v0,$zero,0x0001
 */
