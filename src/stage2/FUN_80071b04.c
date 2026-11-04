/* FUN_80071b04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071b04  body 0x80071b04..0x80071b3b  size 56 B
 * body sha256 13a1d7ca2f89230b17e594d11e095020252b36a7f8300bb75c4bd9e69dd4cb39
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80071b04  8c82001c  lw $v0,28($a0)
 * 0x80071b08  8c850154  lw $a1,340($a0)
 * 0x80071b0c  90420001  lbu $v0,1($v0)
 * 0x80071b10  3c030400  lui $v1,0x0400
 * 0x80071b14  a4a00270  sh $zero,624($a1)
 * 0x80071b18  a4a00272  sh $zero,626($a1)
 * 0x80071b1c  00021400  sll $v0,$v0,16
 * 0x80071b20  00431025  or $v0,$v0,$v1
 * 0x80071b24  aca20004  sw $v0,4($a1)
 * 0x80071b28  8c82001c  lw $v0,28($a0)
 * 0x80071b2c  24420002  addiu $v0,$v0,0x0002
 * 0x80071b30  ac82001c  sw $v0,28($a0)
 * 0x80071b34  03e00008  jr $ra
 * 0x80071b38  24020001  addiu $v0,$zero,0x0001
 */
