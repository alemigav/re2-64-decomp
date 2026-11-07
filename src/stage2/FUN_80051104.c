/* FUN_80051104
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80051104  body 0x80051104..0x8005112f  size 44 B
 * body sha256 ac1d11a6747fe1b46364a757fd0ffeed26daa137683552baa07b59c7c6f43e1b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80051104..0x8005113f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80051104  3c028011  lui $v0,0x8011
 * 0x80051108  8c42bc30  lw $v0,-17360($v0)
 * 0x8005110c  18400006  blez $v0,+6
 * 0x80051110  00001821  addu $v1,$zero,$zero
 * 0x80051114  00402021  addu $a0,$v0,$zero
 * 0x80051118  24630001  addiu $v1,$v1,0x0001
 * 0x8005111c  0064102a  slt $v0,$v1,$a0
 * 0x80051120  1440fffe  bne $v0,$zero,-2
 * 0x80051124  24630001  addiu $v1,$v1,0x0001
 * 0x80051128  03e00008  jr $ra
 * 0x8005112c  00000000  sll $zero,$zero,0
 */
