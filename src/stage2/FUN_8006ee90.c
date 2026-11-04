/* FUN_8006ee90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ee90  body 0x8006ee90..0x8006eef3  size 100 B
 * body sha256 83ce69f1779d205956da1565fea2024c01f22642beb79a087c7a0fb4371f9bc1
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
 * 0x8006ee90  00802821  addu $a1,$a0,$zero
 * 0x8006ee94  3c040001  lui $a0,0x0001
 * 0x8006ee98  34848000  ori $a0,$a0,0x8000
 * 0x8006ee9c  8ca2001c  lw $v0,28($a1)
 * 0x8006eea0  3c03800c  lui $v1,0x800c
 * 0x8006eea4  90420001  lbu $v0,1($v0)
 * 0x8006eea8  246676b0  addiu $a2,$v1,0x76b0
 * 0x8006eeac  00021080  sll $v0,$v0,2
 * 0x8006eeb0  00461021  addu $v0,$v0,$a2
 * 0x8006eeb4  00442021  addu $a0,$v0,$a0
 * 0x8006eeb8  8c8204b0  lw $v0,1200($a0)
 * 0x8006eebc  14400005  bne $v0,$zero,+5
 * 0x8006eec0  3c030002  lui $v1,0x0002
 * 0x8006eec4  00c31821  addu $v1,$a2,$v1
 * 0x8006eec8  90620f54  lbu $v0,3924($v1)
 * 0x8006eecc  24420001  addiu $v0,$v0,0x0001
 * 0x8006eed0  a0620f54  sb $v0,3924($v1)
 * 0x8006eed4  8ca2001c  lw $v0,28($a1)
 * 0x8006eed8  24420002  addiu $v0,$v0,0x0002
 * 0x8006eedc  ac8204b0  sw $v0,1200($a0)
 * 0x8006eee0  8ca2001c  lw $v0,28($a1)
 * 0x8006eee4  24420014  addiu $v0,$v0,0x0014
 * 0x8006eee8  aca2001c  sw $v0,28($a1)
 * 0x8006eeec  03e00008  jr $ra
 * 0x8006eef0  24020001  addiu $v0,$zero,0x0001
 */
