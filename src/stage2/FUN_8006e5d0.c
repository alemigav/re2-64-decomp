/* FUN_8006e5d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e5d0  body 0x8006e5d0..0x8006e65b  size 140 B
 * body sha256 9991a2cf35133da0b484605bed301a39fd05b8d8ed7ee4bc6fd19a12f320d497
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
 * 0x8006e5d0  8c82001c  lw $v0,28($a0)
 * 0x8006e5d4  90430001  lbu $v1,1($v0)
 * 0x8006e5d8  90450002  lbu $a1,2($v0)
 * 0x8006e5dc  90470003  lbu $a3,3($v0)
 * 0x8006e5e0  24420004  addiu $v0,$v0,0x0004
 * 0x8006e5e4  ac82001c  sw $v0,28($a0)
 * 0x8006e5e8  3c048000  lui $a0,0x8000
 * 0x8006e5ec  3c028011  lui $v0,0x8011
 * 0x8006e5f0  24425090  addiu $v0,$v0,0x5090
 * 0x8006e5f4  00031880  sll $v1,$v1,2
 * 0x8006e5f8  00621821  addu $v1,$v1,$v0
 * 0x8006e5fc  00051143  sra $v0,$a1,5
 * 0x8006e600  00021080  sll $v0,$v0,2
 * 0x8006e604  8c630000  lw $v1,0($v1)
 * 0x8006e608  00623021  addu $a2,$v1,$v0
 * 0x8006e60c  24020001  addiu $v0,$zero,0x0001
 * 0x8006e610  10e20012  beq $a3,$v0,+18
 * 0x8006e614  30a5001f  andi $a1,$a1,0x001f
 * 0x8006e618  28e20002  op&0x0a $v0,$a3,0x0002
 * 0x8006e61c  10400005  beq $v0,$zero,+5
 * 0x8006e620  24020007  addiu $v0,$zero,0x0007
 * 0x8006e624  10e00007  beq $a3,$zero,+7
 * 0x8006e628  24020001  addiu $v0,$zero,0x0001
 * 0x8006e62c  0801b9a1  j 0x8006e684
 * 0x8006e630  00000000  sll $zero,$zero,0
 * 0x8006e634  10e2000e  beq $a3,$v0,+14
 * 0x8006e638  24020001  addiu $v0,$zero,0x0001
 * 0x8006e63c  0801b9a1  j 0x8006e684
 * 0x8006e640  00000000  sll $zero,$zero,0
 * 0x8006e644  00a41806  special&0x06 $v1,$a1,$a0
 * 0x8006e648  8cc40000  lw $a0,0($a2)
 * 0x8006e64c  00031827  special&0x27 $v1,$zero,$v1
 * 0x8006e650  00832024  and $a0,$a0,$v1
 * 0x8006e654  03e00008  jr $ra
 * 0x8006e658  acc40000  sw $a0,0($a2)
 */
