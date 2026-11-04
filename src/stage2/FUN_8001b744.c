/* FUN_8001b744
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001b744  body 0x8001b744..0x8001b8c7  size 388 B
 * body sha256 12008d010b64482a2d50cf23b76a5122c3000f01103940e0eb65a7cd3c5b8d55
 * EXTENT MEASURED, NOT RECONSTRUCTED: 97 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8001b744  c81f2018  op&0x32 $ra,$zero,0x2018
 * 0x8001b748  c81e2019  op&0x32 $fp,$zero,0x2019
 * 0x8001b74c  c81d201a  op&0x32 $sp,$zero,0x201a
 * 0x8001b750  c81c201b  op&0x32 $gp,$zero,0x201b
 * 0x8001b754  201e01c0  op&0x08 $fp,$zero,0x01c0
 * 0x8001b758  201704c0  op&0x08 $s7,$zero,0x04c0
 * 0x8001b75c  201607e0  op&0x08 $s6,$zero,0x07e0
 * 0x8001b760  4b7f0051  op&0x12 $ra,$k1,0x0051
 * 0x8001b764  8c0b00f0  lw $t3,240($zero)
 * 0x8001b768  8c0c0fc4  lw $t4,4036($zero)
 * 0x8001b76c  20012800  op&0x08 $at,$zero,0x2800
 * 0x8001b770  11600006  beq $t3,$zero,+6
 * 0x8001b774  40812000  cop0 rs=4 rt=$at rd=4
 * 0x8001b778  318c0001  andi $t4,$t4,0x0001
 * 0x8001b77c  1180001e  beq $t4,$zero,+30
 * 0x8001b780  ac000fc4  sw $zero,4036($zero)
 * 0x8001b784  0800045f  j 0x8000117c
 * 0x8001b788  8c1a0bf8  lw $k0,3064($zero)
 * 0x8001b78c  400b5800  cop0 rs=0 rt=$t3 rd=11
 * 0x8001b790  316b0001  andi $t3,$t3,0x0001
 * 0x8001b794  1560000b  bne $t3,$zero,+11
 * 0x8001b798  40024800  cop0 rs=0 rt=$v0 rd=9
 * 0x8001b79c  8c030fe8  lw $v1,4072($zero)
 * 0x8001b7a0  00625822  sub $t3,$v1,$v0
 * 0x8001b7a4  1d600007  bgtz $t3,+7
 * 0x8001b7a8  40015000  cop0 rs=0 rt=$at rd=10
 * 0x8001b7ac  8c040fec  lw $a0,4076($zero)
 * 0x8001b7b0  10200004  beq $at,$zero,+4
 * 0x8001b7b4  00245822  sub $t3,$at,$a0
 * 0x8001b7b8  05610002  op&0x01 $at,$t3,0x0002
 * 0x8001b7bc  00000000  sll $zero,$zero,0
 * 0x8001b7c0  14220008  bne $at,$v0,+8
 * 0x8001b7c4  400b5800  cop0 rs=0 rt=$t3 rd=11
 * 0x8001b7c8  316b0400  andi $t3,$t3,0x0400
 * 0x8001b7cc  1560fffd  bne $t3,$zero,-3
 * 0x8001b7d0  200b0001  op&0x08 $t3,$zero,0x0001
 * 0x8001b7d4  408b5800  cop0 rs=4 rt=$t3 rd=11
 * 0x8001b7d8  8c020fec  lw $v0,4076($zero)
 * 0x8001b7dc  40824000  cop0 rs=4 rt=$v0 rd=8
 * 0x8001b7e0  40824800  cop0 rs=4 rt=$v0 rd=9
 * 0x8001b7e4  ac0200f0  sw $v0,240($zero)
 * 0x8001b7e8  8c0b00f4  lw $t3,244($zero)
 * 0x8001b7ec  15600002  bne $t3,$zero,+2
 * 0x8001b7f0  8c0b0fe0  lw $t3,4064($zero)
 * 0x8001b7f4  ac0b00f4  sw $t3,244($zero)
 * 0x8001b7f8  8c010fd0  lw $at,4048($zero)
 * 0x8001b7fc  8c020304  lw $v0,772($zero)
 * 0x8001b800  8c03030c  lw $v1,780($zero)
 * 0x8001b804  8c040314  lw $a0,788($zero)
 * 0x8001b808  8c05031c  lw $a1,796($zero)
 * 0x8001b80c  00411020  add $v0,$v0,$at
 * 0x8001b810  00611820  add $v1,$v1,$at
 * 0x8001b814  ac020304  sw $v0,772($zero)
 * 0x8001b818  ac03030c  sw $v1,780($zero)
 * 0x8001b81c  00812020  add $a0,$a0,$at
 * 0x8001b820  00a12820  add $a1,$a1,$at
 * 0x8001b824  ac040314  sw $a0,788($zero)
 * 0x8001b828  ac05031c  sw $a1,796($zero)
 * 0x8001b82c  8c1900c0  lw $t9,192($zero)
 * 0x8001b830  0c000477  jal 0x800011dc
 * 0x8001b834  8c1800c4  lw $t8,196($zero)
 * 0x8001b838  8c1a0ff0  lw $k0,4080($zero)
 * 0x8001b83c  200b030c  op&0x08 $t3,$zero,0x030c
 * 0x8001b840  0c0007ed  jal 0x80001fb4
 * 0x8001b844  37ec0000  ori $t4,$ra,0x0000
 * 0x8001b848  201300a7  op&0x08 $s3,$zero,0x00a7
 * 0x8001b84c  37580000  ori $t8,$k0,0x0000
 * 0x8001b850  0c0007f6  jal 0x80001fd8
 * 0x8001b854  24140418  addiu $s4,$zero,0x0418
 * 0x8001b858  275a00a8  addiu $k0,$k0,0x00a8
 * 0x8001b85c  201bff58  op&0x08 $k1,$zero,0xff58
 * 0x8001b860  0c0007f2  jal 0x80001fc8
 * 0x8001b864  40012000  cop0 rs=0 rt=$at rd=4
 * 0x8001b868  8f7904c0  lw $t9,1216($k1)
 * 0x8001b86c  1360fff6  beq $k1,$zero,-10
 * 0x8001b870  30210080  andi $at,$at,0x0080
 * 0x8001b874  00196603  sra $t4,$t9,24
 * 0x8001b878  000c5840  sll $t3,$t4,1
 * 0x8001b87c  956b0370  lhu $t3,880($t3)
 * 0x8001b880  1420037a  bne $at,$zero,+890
 * 0x8001b884  8f7804c4  lw $t8,1220($k1)
 * 0x8001b888  01600008  jr $t3
 * 0x8001b88c  277b0008  addiu $k1,$k1,0x0008
 * 0x8001b890  ac1900c0  sw $t9,192($zero)
 * 0x8001b894  ac1800c4  sw $t8,196($zero)
 * 0x8001b898  201f1140  op&0x08 $ra,$zero,0x1140
 * 0x8001b89c  332b0fff  andi $t3,$t9,0x0fff
 * 0x8001b8a0  a40b0208  sh $t3,520($zero)
 * 0x8001b8a4  00195b02  srl $t3,$t9,12
 * 0x8001b8a8  316b0fff  andi $t3,$t3,0x0fff
 * 0x8001b8ac  a40b0204  sh $t3,516($zero)
 * 0x8001b8b0  330b0fff  andi $t3,$t8,0x0fff
 * 0x8001b8b4  a40b020a  sh $t3,522($zero)
 * 0x8001b8b8  00185b02  srl $t3,$t8,12
 * 0x8001b8bc  316b0fff  andi $t3,$t3,0x0fff
 * 0x8001b8c0  03e00008  jr $ra
 * 0x8001b8c4  a40b0206  sh $t3,518($zero)
 */
