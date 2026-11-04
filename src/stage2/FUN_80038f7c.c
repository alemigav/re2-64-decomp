/* FUN_80038f7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038f7c  body 0x80038f7c..0x80038fef  size 116 B
 * body sha256 ef6af8fbc70f26e7f3b6193d3c148eedacf6ac39aa5b7a0b6ffcad0966361032
 * EXTENT MEASURED, NOT RECONSTRUCTED: 29 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80038f7c  3c02800f  lui $v0,0x800f
 * 0x80038f80  2442ebac  addiu $v0,$v0,0xebac
 * 0x80038f84  2446d180  addiu $a2,$v0,0xd180
 * 0x80038f88  24090005  addiu $t1,$zero,0x0005
 * 0x80038f8c  24080002  addiu $t0,$zero,0x0002
 * 0x80038f90  24070003  addiu $a3,$zero,0x0003
 * 0x80038f94  2445d198  addiu $a1,$v0,0xd198
 * 0x80038f98  24a5007c  addiu $a1,$a1,0x007c
 * 0x80038f9c  24c6007c  addiu $a2,$a2,0x007c
 * 0x80038fa0  90a30004  lbu $v1,4($a1)
 * 0x80038fa4  10600008  beq $v1,$zero,+8
 * 0x80038fa8  24040001  addiu $a0,$zero,0x0001
 * 0x80038fac  14690007  bne $v1,$t1,+7
 * 0x80038fb0  00000000  sll $zero,$zero,0
 * 0x80038fb4  90a30006  lbu $v1,6($a1)
 * 0x80038fb8  50680001  op&0x14 $t0,$v1,0x0001
 * 0x80038fbc  00002021  addu $a0,$zero,$zero
 * 0x80038fc0  14670002  bne $v1,$a3,+2
 * 0x80038fc4  00000000  sll $zero,$zero,0
 * 0x80038fc8  00002021  addu $a0,$zero,$zero
 * 0x80038fcc  10800004  beq $a0,$zero,+4
 * 0x80038fd0  00000000  sll $zero,$zero,0
 * 0x80038fd4  a0a0ffe9  sb $zero,-23($a1)
 * 0x80038fd8  a0c00000  sb $zero,0($a2)
 * 0x80038fdc  a4a00000  sh $zero,0($a1)
 * 0x80038fe0  14c2ffee  bne $a2,$v0,-18
 * 0x80038fe4  24a5007c  addiu $a1,$a1,0x007c
 * 0x80038fe8  03e00008  jr $ra
 * 0x80038fec  00000000  sll $zero,$zero,0
 */
