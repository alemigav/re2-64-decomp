/* FUN_80043374
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043374  body 0x80043374..0x80043397  size 36 B
 * body sha256 6554f225c8f1a04702bb8c05bf405eca275496808058d04b0ebd660a4da0f4e2
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80043374..0x80043397, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80043374  3c028014  lui $v0,0x8014
 * 0x80043378  94439a80  lhu $v1,-25984($v0)
 * 0x8004337c  24429a80  addiu $v0,$v0,0x9a80
 * 0x80043380  a4830000  sh $v1,0($a0)
 * 0x80043384  94430002  lhu $v1,2($v0)
 * 0x80043388  a4830002  sh $v1,2($a0)
 * 0x8004338c  94420004  lhu $v0,4($v0)
 * 0x80043390  03e00008  jr $ra
 * 0x80043394  a4820004  sh $v0,4($a0)
 */
