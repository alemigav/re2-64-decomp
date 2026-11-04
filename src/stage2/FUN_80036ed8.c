/* FUN_80036ed8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036ed8  body 0x80036ed8..0x80036f63  size 140 B
 * body sha256 4917279058b40bd0feac69f6d128861bb1ae5646c44fa94f8045386281a77fc6
 * EXTENT MEASURED, NOT RECONSTRUCTED: 35 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80036ed8  00805021  addu $t2,$a0,$zero
 * 0x80036edc  3c030001  lui $v1,0x0001
 * 0x80036ee0  34638000  ori $v1,$v1,0x8000
 * 0x80036ee4  3c04800e  lui $a0,0x800e
 * 0x80036ee8  3c02800c  lui $v0,0x800c
 * 0x80036eec  244276b0  addiu $v0,$v0,0x76b0
 * 0x80036ef0  00431821  addu $v1,$v0,$v1
 * 0x80036ef4  8c62028c  lw $v0,652($v1)
 * 0x80036ef8  248413e8  addiu $a0,$a0,0x13e8
 * 0x80036efc  10440017  beq $v0,$a0,+23
 * 0x80036f00  00004021  addu $t0,$zero,$zero
 * 0x80036f04  00604821  addu $t1,$v1,$zero
 * 0x80036f08  8c830000  lw $v1,0($a0)
 * 0x80036f0c  8c620000  lw $v0,0($v1)
 * 0x80036f10  30420001  andi $v0,$v0,0x0001
 * 0x80036f14  1040000d  beq $v0,$zero,+13
 * 0x80036f18  00000000  sll $zero,$zero,0
 * 0x80036f1c  90620008  lbu $v0,8($v1)
 * 0x80036f20  1446000a  bne $v0,$a2,+10
 * 0x80036f24  00000000  sll $zero,$zero,0
 * 0x80036f28  106a0008  beq $v1,$t2,+8
 * 0x80036f2c  00000000  sll $zero,$zero,0
 * 0x80036f30  10a00006  beq $a1,$zero,+6
 * 0x80036f34  25080001  addiu $t0,$t0,0x0001
 * 0x80036f38  10e00004  beq $a3,$zero,+4
 * 0x80036f3c  00000000  sll $zero,$zero,0
 * 0x80036f40  aca30000  sw $v1,0($a1)
 * 0x80036f44  24a50004  addiu $a1,$a1,0x0004
 * 0x80036f48  24e7ffff  addiu $a3,$a3,0xffff
 * 0x80036f4c  8d22028c  lw $v0,652($t1)
 * 0x80036f50  24840004  addiu $a0,$a0,0x0004
 * 0x80036f54  1482ffec  bne $a0,$v0,-20
 * 0x80036f58  00000000  sll $zero,$zero,0
 * 0x80036f5c  03e00008  jr $ra
 * 0x80036f60  01001021  addu $v0,$t0,$zero
 */
