/* FUN_8006db14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db14  body 0x8006db14..0x8006db27  size 20 B
 * body sha256 2d3f68754adf9ee0928ff6fa9a6c1ec6867b4357825e2afefefc46cfac26c702
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006db00..0x8006db97, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006db14  8c82001c  lw $v0,28($a0)
 * 0x8006db18  24420001  addiu $v0,$v0,0x0001
 * 0x8006db1c  ac82001c  sw $v0,28($a0)
 * 0x8006db20  03e00008  jr $ra
 * 0x8006db24  24020001  addiu $v0,$zero,0x0001
 */
