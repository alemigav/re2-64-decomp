/* FUN_80071d28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071d28  body 0x80071d28..0x80071d9b  size 116 B
 * body sha256 96d9692463c90c5b6fd193df770f1d1b518c8fd39b1341ede41d695f1fe48333
 * EXTENT MEASURED, NOT RECONSTRUCTED: 29 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80071d28  8c82001c  lw $v0,28($a0)
 * 0x80071d2c  24030001  addiu $v1,$zero,0x0001
 * 0x80071d30  90450001  lbu $a1,1($v0)
 * 0x80071d34  94460002  lhu $a2,2($v0)
 * 0x80071d38  10a3000c  beq $a1,$v1,+12
 * 0x80071d3c  00000000  sll $zero,$zero,0
 * 0x80071d40  10a00006  beq $a1,$zero,+6
 * 0x80071d44  00000000  sll $zero,$zero,0
 * 0x80071d48  24020002  addiu $v0,$zero,0x0002
 * 0x80071d4c  10a2000a  beq $a1,$v0,+10
 * 0x80071d50  00000000  sll $zero,$zero,0
 * 0x80071d54  0801c762  j 0x80071d88
 * 0x80071d58  00000000  sll $zero,$zero,0
 * 0x80071d5c  8c830154  lw $v1,340($a0)
 * 0x80071d60  94620268  lhu $v0,616($v1)
 * 0x80071d64  0801c761  j 0x80071d84
 * 0x80071d68  00461025  or $v0,$v0,$a2
 * 0x80071d6c  8c820154  lw $v0,340($a0)
 * 0x80071d70  0801c762  j 0x80071d88
 * 0x80071d74  a4460268  sh $a2,616($v0)
 * 0x80071d78  8c830154  lw $v1,340($a0)
 * 0x80071d7c  94620268  lhu $v0,616($v1)
 * 0x80071d80  00461026  xor $v0,$v0,$a2
 * 0x80071d84  a4620268  sh $v0,616($v1)
 * 0x80071d88  8c82001c  lw $v0,28($a0)
 * 0x80071d8c  24420004  addiu $v0,$v0,0x0004
 * 0x80071d90  ac82001c  sw $v0,28($a0)
 * 0x80071d94  03e00008  jr $ra
 * 0x80071d98  24020001  addiu $v0,$zero,0x0001
 */
