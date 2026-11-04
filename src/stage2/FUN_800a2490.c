/* FUN_800a2490
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2490  body 0x800a2490..0x800a250f  size 128 B
 * body sha256 b5a2877a85fbb13cf1d4876bab592c8b6a155953698a99b5188c5a92c56485db
 * EXTENT MEASURED, NOT RECONSTRUCTED: 32 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a2490  00803021  addu $a2,$a0,$zero
 * 0x800a2494  00002021  addu $a0,$zero,$zero
 * 0x800a2498  3c027fff  lui $v0,0x7fff
 * 0x800a249c  3442ffff  ori $v0,$v0,0xffff
 * 0x800a24a0  00c23824  and $a3,$a2,$v0
 * 0x800a24a4  3c028014  lui $v0,0x8014
 * 0x800a24a8  2443bc90  addiu $v1,$v0,0xbc90
 * 0x800a24ac  90620fc1  lbu $v0,4033($v1)
 * 0x800a24b0  54400005  op&0x15 $zero,$v0,0x0005
 * 0x800a24b4  24840001  addiu $a0,$a0,0x0001
 * 0x800a24b8  8c620000  lw $v0,0($v1)
 * 0x800a24bc  10470014  beq $v0,$a3,+20
 * 0x800a24c0  3c028000  lui $v0,0x8000
 * 0x800a24c4  24840001  addiu $a0,$a0,0x0001
 * 0x800a24c8  2c820008  op&0x0b $v0,$a0,0x0008
 * 0x800a24cc  1440fff7  bne $v0,$zero,-9
 * 0x800a24d0  24630ff8  addiu $v1,$v1,0x0ff8
 * 0x800a24d4  2404ffff  addiu $a0,$zero,0xffff
 * 0x800a24d8  00803021  addu $a2,$a0,$zero
 * 0x800a24dc  2402ffff  addiu $v0,$zero,0xffff
 * 0x800a24e0  10c2001a  beq $a2,$v0,+26
 * 0x800a24e4  00000000  sll $zero,$zero,0
 * 0x800a24e8  04c0000c  op&0x01 $zero,$a2,0x000c
 * 0x800a24ec  3c027fff  lui $v0,0x7fff
 * 0x800a24f0  3c038014  lui $v1,0x8014
 * 0x800a24f4  2463bc90  addiu $v1,$v1,0xbc90
 * 0x800a24f8  00061240  sll $v0,$a2,9
 * 0x800a24fc  00461023  subu $v0,$v0,$a2
 * 0x800a2500  000210c0  sll $v0,$v0,3
 * 0x800a2504  00431021  addu $v0,$v0,$v1
 * 0x800a2508  03e00008  jr $ra
 * 0x800a250c  a4450fc2  sh $a1,4034($v0)
 */
