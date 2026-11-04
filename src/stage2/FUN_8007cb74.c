/* FUN_8007cb74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007cb74  body 0x8007cb74..0x8007cbd7  size 100 B
 * body sha256 664611a56c4f0cfb5af7d79fd4029cc45c2e3aa8fc7d364d81cd904518b6c8e5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 25 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007cb74  3c028012  lui $v0,0x8012
 * 0x8007cb78  3c038012  lui $v1,0x8012
 * 0x8007cb7c  8c45b54c  lw $a1,-19124($v0)
 * 0x8007cb80  908202c6  lbu $v0,710($a0)
 * 0x8007cb84  9463b560  lhu $v1,-19104($v1)
 * 0x8007cb88  14400024  bne $v0,$zero,+36
 * 0x8007cb8c  00000000  sll $zero,$zero,0
 * 0x8007cb90  10a00022  beq $a1,$zero,+34
 * 0x8007cb94  00000000  sll $zero,$zero,0
 * 0x8007cb98  84a201f2  lh $v0,498($a1)
 * 0x8007cb9c  0440001f  op&0x01 $zero,$v0,0x001f
 * 0x8007cba0  00000000  sll $zero,$zero,0
 * 0x8007cba4  94a201aa  lhu $v0,426($a1)
 * 0x8007cba8  30422000  andi $v0,$v0,0x2000
 * 0x8007cbac  1440000a  bne $v0,$zero,+10
 * 0x8007cbb0  2c6209c4  op&0x0b $v0,$v1,0x09c4
 * 0x8007cbb4  10400008  beq $v0,$zero,+8
 * 0x8007cbb8  3c030105  lui $v1,0x0105
 * 0x8007cbbc  948201f0  lhu $v0,496($a0)
 * 0x8007cbc0  ac830004  sw $v1,4($a0)
 * 0x8007cbc4  ac850250  sw $a1,592($a0)
 * 0x8007cbc8  30421fff  andi $v0,$v0,0x1fff
 * 0x8007cbcc  34424000  ori $v0,$v0,0x4000
 * 0x8007cbd0  03e00008  jr $ra
 * 0x8007cbd4  a48201f0  sh $v0,496($a0)
 */
