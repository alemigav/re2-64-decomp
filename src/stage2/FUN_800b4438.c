/* FUN_800b4438
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4438  body 0x800b4438..0x800b4477  size 64 B
 * body sha256 6b73941976935647853e80258e9b551ddc3d2a2d4e001439fda1569f39c97fed
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x800b43a0..0x800b4477, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800b4438  3c028016  lui $v0,0x8016
 * 0x800b443c  24458b20  addiu $a1,$v0,0x8b20
 * 0x800b4440  00002021  addu $a0,$zero,$zero
 * 0x800b4444  00a01821  addu $v1,$a1,$zero
 * 0x800b4448  90621200  lbu $v0,4608($v1)
 * 0x800b444c  14400006  bne $v0,$zero,+6
 * 0x800b4450  24020002  addiu $v0,$zero,0x0002
 * 0x800b4454  24840001  addiu $a0,$a0,0x0001
 * 0x800b4458  28820002  op&0x0a $v0,$a0,0x0002
 * 0x800b445c  1440fffa  bne $v0,$zero,-6
 * 0x800b4460  24631228  addiu $v1,$v1,0x1228
 * 0x800b4464  24020002  addiu $v0,$zero,0x0002
 * 0x800b4468  1482fff6  bne $a0,$v0,-10
 * 0x800b446c  00002021  addu $a0,$zero,$zero
 * 0x800b4470  03e00008  jr $ra
 * 0x800b4474  00000000  sll $zero,$zero,0
 */
