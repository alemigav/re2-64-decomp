/* FUN_8006ef68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ef68  body 0x8006ef68..0x8006efcb  size 100 B
 * body sha256 56d0430fd1073417f7e1e61a0838f48a6d340f137dce2f2bd416829752aefc65
 * EXTENT MEASURED, NOT RECONSTRUCTED: 25 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006ef68  00802821  addu $a1,$a0,$zero
 * 0x8006ef6c  3c040001  lui $a0,0x0001
 * 0x8006ef70  34848000  ori $a0,$a0,0x8000
 * 0x8006ef74  8ca2001c  lw $v0,28($a1)
 * 0x8006ef78  3c03800c  lui $v1,0x800c
 * 0x8006ef7c  90420001  lbu $v0,1($v0)
 * 0x8006ef80  246676b0  addiu $a2,$v1,0x76b0
 * 0x8006ef84  00021080  sll $v0,$v0,2
 * 0x8006ef88  00461021  addu $v0,$v0,$a2
 * 0x8006ef8c  00442021  addu $a0,$v0,$a0
 * 0x8006ef90  8c8204b0  lw $v0,1200($a0)
 * 0x8006ef94  14400005  bne $v0,$zero,+5
 * 0x8006ef98  3c030002  lui $v1,0x0002
 * 0x8006ef9c  00c31821  addu $v1,$a2,$v1
 * 0x8006efa0  90620f54  lbu $v0,3924($v1)
 * 0x8006efa4  24420001  addiu $v0,$v0,0x0001
 * 0x8006efa8  a0620f54  sb $v0,3924($v1)
 * 0x8006efac  8ca2001c  lw $v0,28($a1)
 * 0x8006efb0  24420002  addiu $v0,$v0,0x0002
 * 0x8006efb4  ac8204b0  sw $v0,1200($a0)
 * 0x8006efb8  8ca2001c  lw $v0,28($a1)
 * 0x8006efbc  24420020  addiu $v0,$v0,0x0020
 * 0x8006efc0  aca2001c  sw $v0,28($a1)
 * 0x8006efc4  03e00008  jr $ra
 * 0x8006efc8  24020001  addiu $v0,$zero,0x0001
 */
