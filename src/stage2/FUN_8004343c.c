/* FUN_8004343c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004343c  body 0x8004343c..0x8004345f  size 36 B
 * body sha256 2db66242a341a25daaaeb066acc751609056b70ae5b247491463500901ce815a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8004343c..0x8004345f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8004343c  3c028014  lui $v0,0x8014
 * 0x80043440  84439a80  lh $v1,-25984($v0)
 * 0x80043444  24429a80  addiu $v0,$v0,0x9a80
 * 0x80043448  ac830000  sw $v1,0($a0)
 * 0x8004344c  84430002  lh $v1,2($v0)
 * 0x80043450  ac830004  sw $v1,4($a0)
 * 0x80043454  84420004  lh $v0,4($v0)
 * 0x80043458  03e00008  jr $ra
 * 0x8004345c  ac820008  sw $v0,8($a0)
 */
