/* FUN_80039184
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039184  body 0x80039184..0x800391df  size 92 B
 * body sha256 eb1593a18e0410ec74e479dea3cf20b2b22608923c1d0569067b0dd516669d86
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
 * 0x80039184  8fa90010  lw $t1,16($sp)
 * 0x80039188  11200015  beq $t1,$zero,+21
 * 0x8003918c  00004021  addu $t0,$zero,$zero
 * 0x80039190  308400ff  andi $a0,$a0,0x00ff
 * 0x80039194  30a500ff  andi $a1,$a1,0x00ff
 * 0x80039198  3c02800f  lui $v0,0x800f
 * 0x8003919c  2443bda8  addiu $v1,$v0,0xbda8
 * 0x800391a0  9062001c  lbu $v0,28($v1)
 * 0x800391a4  54440009  op&0x15 $a0,$v0,0x0009
 * 0x800391a8  25080001  addiu $t0,$t0,0x0001
 * 0x800391ac  9062001e  lbu $v0,30($v1)
 * 0x800391b0  14450006  bne $v0,$a1,+6
 * 0x800391b4  25080001  addiu $t0,$t0,0x0001
 * 0x800391b8  8c62006c  lw $v0,108($v1)
 * 0x800391bc  14490003  bne $v0,$t1,+3
 * 0x800391c0  00000000  sll $zero,$zero,0
 * 0x800391c4  a4660006  sh $a2,6($v1)
 * 0x800391c8  a4670012  sh $a3,18($v1)
 * 0x800391cc  2d020060  op&0x0b $v0,$t0,0x0060
 * 0x800391d0  1440fff3  bne $v0,$zero,-13
 * 0x800391d4  2463007c  addiu $v1,$v1,0x007c
 * 0x800391d8  03e00008  jr $ra
 * 0x800391dc  00001021  addu $v0,$zero,$zero
 */
