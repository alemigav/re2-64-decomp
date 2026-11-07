/* FUN_800a5b7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5b7c  body 0x800a5b7c..0x800a5ba3  size 40 B
 * body sha256 1a25a6104274b97b20b91bb1210444284c907cdb527bb3efea9a0c669176bd9f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800a5b7c..0x800a5ba3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800a5b7c  3c038014  lui $v1,0x8014
 * 0x800a5b80  00041040  sll $v0,$a0,1
 * 0x800a5b84  00441021  addu $v0,$v0,$a0
 * 0x800a5b88  00021080  sll $v0,$v0,2
 * 0x800a5b8c  00441021  addu $v0,$v0,$a0
 * 0x800a5b90  8c633f0c  lw $v1,16140($v1)
 * 0x800a5b94  000210c0  sll $v0,$v0,3
 * 0x800a5b98  00431021  addu $v0,$v0,$v1
 * 0x800a5b9c  03e00008  jr $ra
 * 0x800a5ba0  a0400000  sb $zero,0($v0)
 */
