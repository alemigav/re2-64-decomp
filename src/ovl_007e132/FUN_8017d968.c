/* FUN_8017d968
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017d968  body 0x8017d968..0x8017d99f  size 56 B
 * body sha256 f144be7e686bd5cdc28bf1cbda1218f4ff5de1c2764ad4aa9af3f3b3904d8b7b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8017d968  3c028018  lui $v0,0x8018
 * 0x8017d96c  8c43e8e0  lw $v1,-5920($v0)
 * 0x8017d970  94620002  lhu $v0,2($v1)
 * 0x8017d974  24420001  addiu $v0,$v0,0x0001
 * 0x8017d978  a4620002  sh $v0,2($v1)
 * 0x8017d97c  00021400  sll $v0,$v0,16
 * 0x8017d980  00021403  sra $v0,$v0,16
 * 0x8017d984  284200b5  op&0x0a $v0,$v0,0x00b5
 * 0x8017d988  14400003  bne $v0,$zero,+3
 * 0x8017d98c  00000000  sll $zero,$zero,0
 * 0x8017d990  a4600002  sh $zero,2($v1)
 * 0x8017d994  a4600000  sh $zero,0($v1)
 * 0x8017d998  03e00008  jr $ra
 * 0x8017d99c  00000000  sll $zero,$zero,0
 */
