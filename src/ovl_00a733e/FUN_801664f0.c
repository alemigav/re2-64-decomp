/* FUN_801664f0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801664f0  body 0x801664f0..0x8016654f  size 96 B
 * body sha256 05e3599ac9b4230ef3096aab33739dbc02d9f7201c4e33ec14279406735d94f0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 24 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x801664f0  90820006  lbu $v0,6($a0)
 * 0x801664f4  1440000e  bne $v0,$zero,+14
 * 0x801664f8  3c031013  lui $v1,0x1013
 * 0x801664fc  24020001  addiu $v0,$zero,0x0001
 * 0x80166500  a0820006  sb $v0,6($a0)
 * 0x80166504  a08202c4  sb $v0,708($a0)
 * 0x80166508  a08202c5  sb $v0,709($a0)
 * 0x8016650c  8c820000  lw $v0,0($a0)
 * 0x80166510  34630f00  ori $v1,$v1,0x0f00
 * 0x80166514  ac8301e8  sw $v1,488($a0)
 * 0x80166518  9083025c  lbu $v1,604($a0)
 * 0x8016651c  a4800272  sh $zero,626($a0)
 * 0x80166520  34420400  ori $v0,$v0,0x0400
 * 0x80166524  34630001  ori $v1,$v1,0x0001
 * 0x80166528  ac820000  sw $v0,0($a0)
 * 0x8016652c  a083025c  sb $v1,604($a0)
 * 0x80166530  84830270  lh $v1,624($a0)
 * 0x80166534  24020001  addiu $v0,$zero,0x0001
 * 0x80166538  14620003  bne $v1,$v0,+3
 * 0x8016653c  00000000  sll $zero,$zero,0
 * 0x80166540  a0830005  sb $v1,5($a0)
 * 0x80166544  a4800006  sh $zero,6($a0)
 * 0x80166548  03e00008  jr $ra
 * 0x8016654c  00000000  sll $zero,$zero,0
 */
