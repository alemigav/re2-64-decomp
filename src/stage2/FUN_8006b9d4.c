/* FUN_8006b9d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b9d4  body 0x8006b9d4..0x8006b9ef  size 28 B
 * body sha256 8361ac17cec2acb31b43b199b513eb932a8a836c5cfa463b711552f7cbc5a219
 * EXTENT MEASURED, NOT RECONSTRUCTED: 7 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8006b9bc..0x8006b9ef, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006b9d4  3c028011  lui $v0,0x8011
 * 0x8006b9d8  3c038011  lui $v1,0x8011
 * 0x8006b9dc  ac442a20  sw $a0,10784($v0)
 * 0x8006b9e0  24020001  addiu $v0,$zero,0x0001
 * 0x8006b9e4  ac6237d4  sw $v0,14292($v1)
 * 0x8006b9e8  03e00008  jr $ra
 * 0x8006b9ec  00000000  sll $zero,$zero,0
 */
