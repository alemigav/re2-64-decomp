/* FUN_80021b98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80021b98  body 0x80021b98..0x80021c77  size 224 B
 * body sha256 ec6245589b01bf890df391bf78837c7df2878b12df9e7896cf333c488cb046d7
 * EXTENT MEASURED, NOT RECONSTRUCTED: 56 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80021b98  8c0b00f4  lw $t3,244($zero)
 * 0x80021b9c  15600002  bne $t3,$zero,+2
 * 0x80021ba0  8c0b0fe0  lw $t3,4064($zero)
 * 0x80021ba4  ac0b00f4  sw $t3,244($zero)
 * 0x80021ba8  8c010fd0  lw $at,4048($zero)
 * 0x80021bac  8c020304  lw $v0,772($zero)
 * 0x80021bb0  8c03030c  lw $v1,780($zero)
 * 0x80021bb4  8c040314  lw $a0,788($zero)
 * 0x80021bb8  8c05031c  lw $a1,796($zero)
 * 0x80021bbc  00411020  add $v0,$v0,$at
 * 0x80021bc0  00611820  add $v1,$v1,$at
 * 0x80021bc4  ac020304  sw $v0,772($zero)
 * 0x80021bc8  ac03030c  sw $v1,780($zero)
 * 0x80021bcc  00812020  add $a0,$a0,$at
 * 0x80021bd0  00a12820  add $a1,$a1,$at
 * 0x80021bd4  ac040314  sw $a0,788($zero)
 * 0x80021bd8  ac05031c  sw $a1,796($zero)
 * 0x80021bdc  8c1900c0  lw $t9,192($zero)
 * 0x80021be0  0c000477  jal 0x800011dc
 * 0x80021be4  8c1800c4  lw $t8,196($zero)
 * 0x80021be8  8c1a0ff0  lw $k0,4080($zero)
 * 0x80021bec  200b030c  op&0x08 $t3,$zero,0x030c
 * 0x80021bf0  0c0007ed  jal 0x80001fb4
 * 0x80021bf4  37ec0000  ori $t4,$ra,0x0000
 * 0x80021bf8  201300a7  op&0x08 $s3,$zero,0x00a7
 * 0x80021bfc  37580000  ori $t8,$k0,0x0000
 * 0x80021c00  0c0007f6  jal 0x80001fd8
 * 0x80021c04  24140418  addiu $s4,$zero,0x0418
 * 0x80021c08  275a00a8  addiu $k0,$k0,0x00a8
 * 0x80021c0c  201bff58  op&0x08 $k1,$zero,0xff58
 * 0x80021c10  0c0007f2  jal 0x80001fc8
 * 0x80021c14  40012000  cop0 rs=0 rt=$at rd=4
 * 0x80021c18  8f7904c0  lw $t9,1216($k1)
 * 0x80021c1c  1360fff6  beq $k1,$zero,-10
 * 0x80021c20  30210080  andi $at,$at,0x0080
 * 0x80021c24  00196603  sra $t4,$t9,24
 * 0x80021c28  000c5840  sll $t3,$t4,1
 * 0x80021c2c  956b0370  lhu $t3,880($t3)
 * 0x80021c30  1420037a  bne $at,$zero,+890
 * 0x80021c34  8f7804c4  lw $t8,1220($k1)
 * 0x80021c38  01600008  jr $t3
 * 0x80021c3c  277b0008  addiu $k1,$k1,0x0008
 * 0x80021c40  ac1900c0  sw $t9,192($zero)
 * 0x80021c44  ac1800c4  sw $t8,196($zero)
 * 0x80021c48  201f1140  op&0x08 $ra,$zero,0x1140
 * 0x80021c4c  332b0fff  andi $t3,$t9,0x0fff
 * 0x80021c50  a40b0208  sh $t3,520($zero)
 * 0x80021c54  00195b02  srl $t3,$t9,12
 * 0x80021c58  316b0fff  andi $t3,$t3,0x0fff
 * 0x80021c5c  a40b0204  sh $t3,516($zero)
 * 0x80021c60  330b0fff  andi $t3,$t8,0x0fff
 * 0x80021c64  a40b020a  sh $t3,522($zero)
 * 0x80021c68  00185b02  srl $t3,$t8,12
 * 0x80021c6c  316b0fff  andi $t3,$t3,0x0fff
 * 0x80021c70  03e00008  jr $ra
 * 0x80021c74  a40b0206  sh $t3,518($zero)
 */
