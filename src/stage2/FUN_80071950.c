/* FUN_80071950
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071950  body 0x80071950..0x8007199b  size 76 B
 * body sha256 6573fb6a2117b2cfd533ed5a6086cf1612a5bef37e6161d4cb7f7758d1fd5230
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80071950  8c82001c  lw $v0,28($a0)
 * 0x80071954  8c850154  lw $a1,340($a0)
 * 0x80071958  90460002  lbu $a2,2($v0)
 * 0x8007195c  90470003  lbu $a3,3($v0)
 * 0x80071960  90430001  lbu $v1,1($v0)
 * 0x80071964  3c020400  lui $v0,0x0400
 * 0x80071968  a0a001e9  sb $zero,489($a1)
 * 0x8007196c  a4a00270  sh $zero,624($a1)
 * 0x80071970  a4a00272  sh $zero,626($a1)
 * 0x80071974  00031c00  sll $v1,$v1,16
 * 0x80071978  00621825  or $v1,$v1,$v0
 * 0x8007197c  aca30004  sw $v1,4($a1)
 * 0x80071980  a0a601e8  sb $a2,488($a1)
 * 0x80071984  a4a70268  sh $a3,616($a1)
 * 0x80071988  8c82001c  lw $v0,28($a0)
 * 0x8007198c  24420004  addiu $v0,$v0,0x0004
 * 0x80071990  ac82001c  sw $v0,28($a0)
 * 0x80071994  03e00008  jr $ra
 * 0x80071998  24020001  addiu $v0,$zero,0x0001
 */
