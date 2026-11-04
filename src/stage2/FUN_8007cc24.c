/* FUN_8007cc24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007cc24  body 0x8007cc24..0x8007cce3  size 192 B
 * body sha256 8cc8c0fd74107fcb09bba14fa3ed6e6d318b344a362fe293b71b1b0c5f1a3f34
 * EXTENT MEASURED, NOT RECONSTRUCTED: 48 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007cc24  3c028012  lui $v0,0x8012
 * 0x8007cc28  3c038012  lui $v1,0x8012
 * 0x8007cc2c  8c46b54c  lw $a2,-19124($v0)
 * 0x8007cc30  9465b560  lhu $a1,-19104($v1)
 * 0x8007cc34  10c00029  beq $a2,$zero,+41
 * 0x8007cc38  00000000  sll $zero,$zero,0
 * 0x8007cc3c  94c2002e  lhu $v0,46($a2)
 * 0x8007cc40  9483002e  lhu $v1,46($a0)
 * 0x8007cc44  00431823  subu $v1,$v0,$v1
 * 0x8007cc48  84c201f2  lh $v0,498($a2)
 * 0x8007cc4c  04400023  op&0x01 $zero,$v0,0x0023
 * 0x8007cc50  00604021  addu $t0,$v1,$zero
 * 0x8007cc54  94c201aa  lhu $v0,426($a2)
 * 0x8007cc58  30422000  andi $v0,$v0,0x2000
 * 0x8007cc5c  1440001f  bne $v0,$zero,+31
 * 0x8007cc60  2ca209c4  op&0x0b $v0,$a1,0x09c4
 * 0x8007cc64  1040001d  beq $v0,$zero,+29
 * 0x8007cc68  00031400  sll $v0,$v1,16
 * 0x8007cc6c  00022c03  sra $a1,$v0,16
 * 0x8007cc70  28a7ec79  op&0x0a $a3,$a1,0xec79
 * 0x8007cc74  14e00019  bne $a3,$zero,+25
 * 0x8007cc78  28a207d0  op&0x0a $v0,$a1,0x07d0
 * 0x8007cc7c  10400017  beq $v0,$zero,+23
 * 0x8007cc80  3c030105  lui $v1,0x0105
 * 0x8007cc84  948201f0  lhu $v0,496($a0)
 * 0x8007cc88  ac830004  sw $v1,4($a0)
 * 0x8007cc8c  ac860250  sw $a2,592($a0)
 * 0x8007cc90  30421fff  andi $v0,$v0,0x1fff
 * 0x8007cc94  34434000  ori $v1,$v0,0x4000
 * 0x8007cc98  28a2f830  op&0x0a $v0,$a1,0xf830
 * 0x8007cc9c  10400006  beq $v0,$zero,+6
 * 0x8007cca0  a48301f0  sh $v1,496($a0)
 * 0x8007cca4  14e00005  bne $a3,$zero,+5
 * 0x8007cca8  250201f3  addiu $v0,$t0,0x01f3
 * 0x8007ccac  30621fff  andi $v0,$v1,0x1fff
 * 0x8007ccb0  34428000  ori $v0,$v0,0x8000
 * 0x8007ccb4  a48201f0  sh $v0,496($a0)
 * 0x8007ccb8  250201f3  addiu $v0,$t0,0x01f3
 * 0x8007ccbc  3042ffff  andi $v0,$v0,0xffff
 * 0x8007ccc0  2c4209c3  op&0x0b $v0,$v0,0x09c3
 * 0x8007ccc4  10400005  beq $v0,$zero,+5
 * 0x8007ccc8  00000000  sll $zero,$zero,0
 * 0x8007cccc  948201f0  lhu $v0,496($a0)
 * 0x8007ccd0  30421fff  andi $v0,$v0,0x1fff
 * 0x8007ccd4  34422000  ori $v0,$v0,0x2000
 * 0x8007ccd8  a48201f0  sh $v0,496($a0)
 * 0x8007ccdc  03e00008  jr $ra
 * 0x8007cce0  00000000  sll $zero,$zero,0
 */
