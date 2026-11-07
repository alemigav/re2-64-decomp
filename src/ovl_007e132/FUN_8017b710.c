/* FUN_8017b710
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017b710  body 0x8017b710..0x8017b743  size 52 B
 * body sha256 521a0dc533a6d0a5702d5eaa91750fcabbbee3296fd5507a0c83c663c1c07416
 * EXTENT MEASURED, NOT RECONSTRUCTED: 13 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8017b710..0x8017b743, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8017b710  3c028018  lui $v0,0x8018
 * 0x8017b714  2443e700  addiu $v1,$v0,0xe700
 * 0x8017b718  94620038  lhu $v0,56($v1)
 * 0x8017b71c  2442ffff  addiu $v0,$v0,0xffff
 * 0x8017b720  a4620038  sh $v0,56($v1)
 * 0x8017b724  00021400  sll $v0,$v0,16
 * 0x8017b728  04410004  op&0x01 $at,$v0,0x0004
 * 0x8017b72c  00000000  sll $zero,$zero,0
 * 0x8017b730  94620002  lhu $v0,2($v1)
 * 0x8017b734  24420001  addiu $v0,$v0,0x0001
 * 0x8017b738  a4620002  sh $v0,2($v1)
 * 0x8017b73c  03e00008  jr $ra
 * 0x8017b740  00000000  sll $zero,$zero,0
 */
