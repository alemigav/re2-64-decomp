/* FUN_80072768
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072768  body 0x80072768..0x8007277b  size 20 B
 * body sha256 eaffe28800ef5c06f9665e0b24d12dff9b70ff3545f701d7009bc4fc496d4ae5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8007272c..0x8007277b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80072768  8c82001c  lw $v0,28($a0)
 * 0x8007276c  24420002  addiu $v0,$v0,0x0002
 * 0x80072770  ac82001c  sw $v0,28($a0)
 * 0x80072774  03e00008  jr $ra
 * 0x80072778  24020001  addiu $v0,$zero,0x0001
 */
