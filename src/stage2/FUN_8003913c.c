/* FUN_8003913c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003913c  body 0x8003913c..0x80039183  size 72 B
 * body sha256 a4b5d1dafa1dd27001cb9e0257ea8754c81e7c09c23bb9580edbff195ff86c1c
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8003913c  308400ff  andi $a0,$a0,0x00ff
 * 0x80039140  30a500ff  andi $a1,$a1,0x00ff
 * 0x80039144  3c02800f  lui $v0,0x800f
 * 0x80039148  2443bda8  addiu $v1,$v0,0xbda8
 * 0x8003914c  9062001c  lbu $v0,28($v1)
 * 0x80039150  14440006  bne $v0,$a0,+6
 * 0x80039154  25080001  addiu $t0,$t0,0x0001
 * 0x80039158  9062001e  lbu $v0,30($v1)
 * 0x8003915c  14450003  bne $v0,$a1,+3
 * 0x80039160  00000000  sll $zero,$zero,0
 * 0x80039164  a4660004  sh $a2,4($v1)
 * 0x80039168  a067000b  sb $a3,11($v1)
 * 0x8003916c  2d020060  op&0x0b $v0,$t0,0x0060
 * 0x80039170  1440fff6  bne $v0,$zero,-10
 * 0x80039174  2463007c  addiu $v1,$v1,0x007c
 * 0x80039178  00001021  addu $v0,$zero,$zero
 * 0x8003917c  03e00008  jr $ra
 * 0x80039180  00000000  sll $zero,$zero,0
 */
