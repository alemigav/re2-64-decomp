/* FUN_800390e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800390e0  body 0x800390e0..0x8003913b  size 92 B
 * body sha256 55c935177cd369541e16c5acd1d6a059e96d80c227d02a43ec9808c3a686ba28
 * EXTENT MEASURED, NOT RECONSTRUCTED: 23 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800390e0  8fa90010  lw $t1,16($sp)
 * 0x800390e4  11200015  beq $t1,$zero,+21
 * 0x800390e8  00004021  addu $t0,$zero,$zero
 * 0x800390ec  308400ff  andi $a0,$a0,0x00ff
 * 0x800390f0  30a500ff  andi $a1,$a1,0x00ff
 * 0x800390f4  3c02800f  lui $v0,0x800f
 * 0x800390f8  2443bda8  addiu $v1,$v0,0xbda8
 * 0x800390fc  9062001c  lbu $v0,28($v1)
 * 0x80039100  54440009  op&0x15 $a0,$v0,0x0009
 * 0x80039104  25080001  addiu $t0,$t0,0x0001
 * 0x80039108  9062001e  lbu $v0,30($v1)
 * 0x8003910c  14450006  bne $v0,$a1,+6
 * 0x80039110  25080001  addiu $t0,$t0,0x0001
 * 0x80039114  8c62006c  lw $v0,108($v1)
 * 0x80039118  14490003  bne $v0,$t1,+3
 * 0x8003911c  00000000  sll $zero,$zero,0
 * 0x80039120  a4660004  sh $a2,4($v1)
 * 0x80039124  a067000b  sb $a3,11($v1)
 * 0x80039128  2d020060  op&0x0b $v0,$t0,0x0060
 * 0x8003912c  1440fff3  bne $v0,$zero,-13
 * 0x80039130  2463007c  addiu $v1,$v1,0x007c
 * 0x80039134  03e00008  jr $ra
 * 0x80039138  00001021  addu $v0,$zero,$zero
 */
