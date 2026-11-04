/* FUN_8006f32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f32c  body 0x8006f32c..0x8006f3b3  size 136 B
 * body sha256 6d908f8c5a49fd5c17c75f765c16fa7ff578ca84b5c5305d76e9aa3cdea8a8cb
 * EXTENT MEASURED, NOT RECONSTRUCTED: 34 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006f32c  00803821  addu $a3,$a0,$zero
 * 0x8006f330  3c040001  lui $a0,0x0001
 * 0x8006f334  34848000  ori $a0,$a0,0x8000
 * 0x8006f338  8ce6001c  lw $a2,28($a3)
 * 0x8006f33c  3c03800c  lui $v1,0x800c
 * 0x8006f340  80c50001  lb $a1,1($a2)
 * 0x8006f344  246376b0  addiu $v1,$v1,0x76b0
 * 0x8006f348  00051080  sll $v0,$a1,2
 * 0x8006f34c  00431021  addu $v0,$v0,$v1
 * 0x8006f350  00441021  addu $v0,$v0,$a0
 * 0x8006f354  8c4404b0  lw $a0,1200($v0)
 * 0x8006f358  10800013  beq $a0,$zero,+19
 * 0x8006f35c  24c2000a  addiu $v0,$a2,0x000a
 * 0x8006f360  90c20002  lbu $v0,2($a2)
 * 0x8006f364  90850001  lbu $a1,1($a0)
 * 0x8006f368  a0820000  sb $v0,0($a0)
 * 0x8006f36c  90c20003  lbu $v0,3($a2)
 * 0x8006f370  30a30080  andi $v1,$a1,0x0080
 * 0x8006f374  00431025  or $v0,$v0,$v1
 * 0x8006f378  10600003  beq $v1,$zero,+3
 * 0x8006f37c  a0820001  sb $v0,1($a0)
 * 0x8006f380  0801bce3  j 0x8006f38c
 * 0x8006f384  24840014  addiu $a0,$a0,0x0014
 * 0x8006f388  2484000c  addiu $a0,$a0,0x000c
 * 0x8006f38c  84c50004  lh $a1,4($a2)
 * 0x8006f390  84c20006  lh $v0,6($a2)
 * 0x8006f394  84c30008  lh $v1,8($a2)
 * 0x8006f398  a4850000  sh $a1,0($a0)
 * 0x8006f39c  a4820002  sh $v0,2($a0)
 * 0x8006f3a0  a4830004  sh $v1,4($a0)
 * 0x8006f3a4  24c2000a  addiu $v0,$a2,0x000a
 * 0x8006f3a8  ace2001c  sw $v0,28($a3)
 * 0x8006f3ac  03e00008  jr $ra
 * 0x8006f3b0  24020001  addiu $v0,$zero,0x0001
 */
