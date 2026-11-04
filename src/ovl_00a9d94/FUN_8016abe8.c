/* FUN_8016abe8
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016abe8  body 0x8016abe8..0x8016ad0f  size 296 B
 * body sha256 ead03101bb1f81c9ae902e8f73060e09c2388ed829baf6a05acd48326520cd88
 * EXTENT MEASURED, NOT RECONSTRUCTED: 74 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8016abe8  908302c5  lbu $v1,709($a0)
 * 0x8016abec  24060001  addiu $a2,$zero,0x0001
 * 0x8016abf0  10660010  beq $v1,$a2,+16
 * 0x8016abf4  28620002  op&0x0a $v0,$v1,0x0002
 * 0x8016abf8  10400005  beq $v0,$zero,+5
 * 0x8016abfc  24020002  addiu $v0,$zero,0x0002
 * 0x8016ac00  10600009  beq $v1,$zero,+9
 * 0x8016ac04  24020078  addiu $v0,$zero,0x0078
 * 0x8016ac08  0805ab3f  j 0x8016acfc
 * 0x8016ac0c  00000000  sll $zero,$zero,0
 * 0x8016ac10  10620020  beq $v1,$v0,+32
 * 0x8016ac14  24020003  addiu $v0,$zero,0x0003
 * 0x8016ac18  1062002d  beq $v1,$v0,+45
 * 0x8016ac1c  2402003f  addiu $v0,$zero,0x003f
 * 0x8016ac20  0805ab3f  j 0x8016acfc
 * 0x8016ac24  00000000  sll $zero,$zero,0
 * 0x8016ac28  a08002c3  sb $zero,707($a0)
 * 0x8016ac2c  a08602c5  sb $a2,709($a0)
 * 0x8016ac30  a48202c6  sh $v0,710($a0)
 * 0x8016ac34  908302c3  lbu $v1,707($a0)
 * 0x8016ac38  2402003f  addiu $v0,$zero,0x003f
 * 0x8016ac3c  14620002  bne $v1,$v0,+2
 * 0x8016ac40  24020002  addiu $v0,$zero,0x0002
 * 0x8016ac44  a08202c5  sb $v0,709($a0)
 * 0x8016ac48  8ca30120  lw $v1,288($a1)
 * 0x8016ac4c  94620010  lhu $v0,16($v1)
 * 0x8016ac50  00021400  sll $v0,$v0,16
 * 0x8016ac54  00021443  sra $v0,$v0,17
 * 0x8016ac58  a4620010  sh $v0,16($v1)
 * 0x8016ac5c  8ca30120  lw $v1,288($a1)
 * 0x8016ac60  94620014  lhu $v0,20($v1)
 * 0x8016ac64  00021400  sll $v0,$v0,16
 * 0x8016ac68  00021443  sra $v0,$v0,17
 * 0x8016ac6c  a4620014  sh $v0,20($v1)
 * 0x8016ac70  3c028017  lui $v0,0x8017
 * 0x8016ac74  908302c3  lbu $v1,707($a0)
 * 0x8016ac78  2442c498  addiu $v0,$v0,0xc498
 * 0x8016ac7c  00621821  addu $v1,$v1,$v0
 * 0x8016ac80  80620000  lb $v0,0($v1)
 * 0x8016ac84  8ca30120  lw $v1,288($a1)
 * 0x8016ac88  00021100  sll $v0,$v0,4
 * 0x8016ac8c  0805ab3f  j 0x8016acfc
 * 0x8016ac90  a4620018  sh $v0,24($v1)
 * 0x8016ac94  908302c3  lbu $v1,707($a0)
 * 0x8016ac98  2402003f  addiu $v0,$zero,0x003f
 * 0x8016ac9c  14620005  bne $v1,$v0,+5
 * 0x8016aca0  3c028017  lui $v0,0x8017
 * 0x8016aca4  24020003  addiu $v0,$zero,0x0003
 * 0x8016aca8  a08202c5  sb $v0,709($a0)
 * 0x8016acac  3c028017  lui $v0,0x8017
 * 0x8016acb0  908302c3  lbu $v1,707($a0)
 * 0x8016acb4  2442c498  addiu $v0,$v0,0xc498
 * 0x8016acb8  00621821  addu $v1,$v1,$v0
 * 0x8016acbc  80620000  lb $v0,0($v1)
 * 0x8016acc0  8ca30120  lw $v1,288($a1)
 * 0x8016acc4  00021100  sll $v0,$v0,4
 * 0x8016acc8  0805ab3f  j 0x8016acfc
 * 0x8016accc  a4620010  sh $v0,16($v1)
 * 0x8016acd0  908302c3  lbu $v1,707($a0)
 * 0x8016acd4  50620001  op&0x14 $v0,$v1,0x0001
 * 0x8016acd8  a08602c5  sb $a2,709($a0)
 * 0x8016acdc  3c028017  lui $v0,0x8017
 * 0x8016ace0  908302c3  lbu $v1,707($a0)
 * 0x8016ace4  2442c498  addiu $v0,$v0,0xc498
 * 0x8016ace8  00621821  addu $v1,$v1,$v0
 * 0x8016acec  80620000  lb $v0,0($v1)
 * 0x8016acf0  8ca30120  lw $v1,288($a1)
 * 0x8016acf4  00021100  sll $v0,$v0,4
 * 0x8016acf8  a4620014  sh $v0,20($v1)
 * 0x8016acfc  908202c3  lbu $v0,707($a0)
 * 0x8016ad00  24420001  addiu $v0,$v0,0x0001
 * 0x8016ad04  3042003f  andi $v0,$v0,0x003f
 * 0x8016ad08  03e00008  jr $ra
 * 0x8016ad0c  a08202c3  sb $v0,707($a0)
 */
