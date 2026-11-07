/* FUN_80165424
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165424  body 0x80165424..0x80165443  size 32 B
 * body sha256 a02b8cb63cb4f3d0f4ffc66645a4b28c67fda763e27c359a3fbd49dadab66e04
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80165424..0x8016544b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80165424  90820006  lbu $v0,6($a0)
 * 0x80165428  14400004  bne $v0,$zero,+4
 * 0x8016542c  24020001  addiu $v0,$zero,0x0001
 * 0x80165430  a0820006  sb $v0,6($a0)
 * 0x80165434  3c021700  lui $v0,0x1700
 * 0x80165438  ac8201e8  sw $v0,488($a0)
 * 0x8016543c  03e00008  jr $ra
 * 0x80165440  00000000  sll $zero,$zero,0
 */
