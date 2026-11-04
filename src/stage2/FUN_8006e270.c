/* FUN_8006e270
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e270  body 0x8006e270..0x8006e337  size 200 B
 * body sha256 89221c379fd2a2b0fde7152cfa2b2bd56b73ac6b7b80a9ab6e5fe539e72482c4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 50 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e270  00805021  addu $t2,$a0,$zero
 * 0x8006e274  240c0015  addiu $t4,$zero,0x0015
 * 0x8006e278  240b0016  addiu $t3,$zero,0x0016
 * 0x8006e27c  81490002  lb $t1,2($t2)
 * 0x8006e280  8d47001c  lw $a3,28($t2)
 * 0x8006e284  01493021  addu $a2,$t2,$t1
 * 0x8006e288  94e80002  lhu $t0,2($a3)
 * 0x8006e28c  90e50001  lbu $a1,1($a3)
 * 0x8006e290  24e70004  addiu $a3,$a3,0x0004
 * 0x8006e294  90c20008  lbu $v0,8($a2)
 * 0x8006e298  00092100  sll $a0,$t1,4
 * 0x8006e29c  24420001  addiu $v0,$v0,0x0001
 * 0x8006e2a0  a0c20008  sb $v0,8($a2)
 * 0x8006e2a4  00021600  sll $v0,$v0,24
 * 0x8006e2a8  00021603  sra $v0,$v0,24
 * 0x8006e2ac  00021880  sll $v1,$v0,2
 * 0x8006e2b0  00641821  addu $v1,$v1,$a0
 * 0x8006e2b4  01431821  addu $v1,$t2,$v1
 * 0x8006e2b8  00e82021  addu $a0,$a3,$t0
 * 0x8006e2bc  ac640060  sw $a0,96($v1)
 * 0x8006e2c0  00091880  sll $v1,$t1,2
 * 0x8006e2c4  00431021  addu $v0,$v0,$v1
 * 0x8006e2c8  01421021  addu $v0,$t2,$v0
 * 0x8006e2cc  90c30004  lbu $v1,4($a2)
 * 0x8006e2d0  00052840  sll $a1,$a1,1
 * 0x8006e2d4  a043000c  sb $v1,12($v0)
 * 0x8006e2d8  3c02800f  lui $v0,0x800f
 * 0x8006e2dc  24428c78  addiu $v0,$v0,0x8c78
 * 0x8006e2e0  00a22821  addu $a1,$a1,$v0
 * 0x8006e2e4  84a30000  lh $v1,0($a1)
 * 0x8006e2e8  90e20000  lbu $v0,0($a3)
 * 0x8006e2ec  144c0003  bne $v0,$t4,+3
 * 0x8006e2f0  00000000  sll $zero,$zero,0
 * 0x8006e2f4  0801b8cb  j 0x8006e32c
 * 0x8006e2f8  24e70002  addiu $a3,$a3,0x0002
 * 0x8006e2fc  504b0007  op&0x14 $t3,$v0,0x0007
 * 0x8006e300  01491821  addu $v1,$t2,$t1
 * 0x8006e304  94e80002  lhu $t0,2($a3)
 * 0x8006e308  84e20004  lh $v0,4($a3)
 * 0x8006e30c  10620007  beq $v1,$v0,+7
 * 0x8006e310  24e70006  addiu $a3,$a3,0x0006
 * 0x8006e314  0801b8ba  j 0x8006e2e8
 * 0x8006e318  00e83821  addu $a3,$a3,$t0
 * 0x8006e31c  90620008  lbu $v0,8($v1)
 * 0x8006e320  24e70002  addiu $a3,$a3,0x0002
 * 0x8006e324  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006e328  a0620008  sb $v0,8($v1)
 * 0x8006e32c  ad47001c  sw $a3,28($t2)
 * 0x8006e330  03e00008  jr $ra
 * 0x8006e334  24020001  addiu $v0,$zero,0x0001
 */
