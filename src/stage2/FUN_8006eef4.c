/* FUN_8006eef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eef4  body 0x8006eef4..0x8006ef67  size 116 B
 * body sha256 e2baae78863e192c81cd6a88739de2baf91a19cd7889c8f5643a28aff4e63a4d
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
 * 0x8006eef4  00802821  addu $a1,$a0,$zero
 * 0x8006eef8  3c040001  lui $a0,0x0001
 * 0x8006eefc  34848000  ori $a0,$a0,0x8000
 * 0x8006ef00  8ca2001c  lw $v0,28($a1)
 * 0x8006ef04  3c03800c  lui $v1,0x800c
 * 0x8006ef08  90420001  lbu $v0,1($v0)
 * 0x8006ef0c  246676b0  addiu $a2,$v1,0x76b0
 * 0x8006ef10  00021080  sll $v0,$v0,2
 * 0x8006ef14  00461021  addu $v0,$v0,$a2
 * 0x8006ef18  00442021  addu $a0,$v0,$a0
 * 0x8006ef1c  8c8204b0  lw $v0,1200($a0)
 * 0x8006ef20  14400005  bne $v0,$zero,+5
 * 0x8006ef24  3c030002  lui $v1,0x0002
 * 0x8006ef28  00c31821  addu $v1,$a2,$v1
 * 0x8006ef2c  90620f54  lbu $v0,3924($v1)
 * 0x8006ef30  24420001  addiu $v0,$v0,0x0001
 * 0x8006ef34  a0620f54  sb $v0,3924($v1)
 * 0x8006ef38  8ca2001c  lw $v0,28($a1)
 * 0x8006ef3c  24420002  addiu $v0,$v0,0x0002
 * 0x8006ef40  ac8204b0  sw $v0,1200($a0)
 * 0x8006ef44  8ca3001c  lw $v1,28($a1)
 * 0x8006ef48  90620003  lbu $v0,3($v1)
 * 0x8006ef4c  34420080  ori $v0,$v0,0x0080
 * 0x8006ef50  a0620003  sb $v0,3($v1)
 * 0x8006ef54  8ca2001c  lw $v0,28($a1)
 * 0x8006ef58  2442001c  addiu $v0,$v0,0x001c
 * 0x8006ef5c  aca2001c  sw $v0,28($a1)
 * 0x8006ef60  03e00008  jr $ra
 * 0x8006ef64  24020001  addiu $v0,$zero,0x0001
 */
