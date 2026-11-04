/* FUN_800a228c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a228c  body 0x800a228c..0x800a2307  size 124 B
 * body sha256 087afe5b9f695ca58d463808321bb65cb159688b5ab1db8a8aee7c8f8f89ff6c
 * EXTENT MEASURED, NOT RECONSTRUCTED: 31 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a228c  3c028013  lui $v0,0x8013
 * 0x800a2290  90426310  lbu $v0,25360($v0)
 * 0x800a2294  1040001f  beq $v0,$zero,+31
 * 0x800a2298  00002821  addu $a1,$zero,$zero
 * 0x800a229c  3c027fff  lui $v0,0x7fff
 * 0x800a22a0  3442ffff  ori $v0,$v0,0xffff
 * 0x800a22a4  00823024  and $a2,$a0,$v0
 * 0x800a22a8  3c028014  lui $v0,0x8014
 * 0x800a22ac  2443bc90  addiu $v1,$v0,0xbc90
 * 0x800a22b0  90620fc1  lbu $v0,4033($v1)
 * 0x800a22b4  54400005  op&0x15 $zero,$v0,0x0005
 * 0x800a22b8  24a50001  addiu $a1,$a1,0x0001
 * 0x800a22bc  8c620000  lw $v0,0($v1)
 * 0x800a22c0  10460011  beq $v0,$a2,+17
 * 0x800a22c4  3c028000  lui $v0,0x8000
 * 0x800a22c8  24a50001  addiu $a1,$a1,0x0001
 * 0x800a22cc  2ca20008  op&0x0b $v0,$a1,0x0008
 * 0x800a22d0  1440fff7  bne $v0,$zero,-9
 * 0x800a22d4  24630ff8  addiu $v1,$v1,0x0ff8
 * 0x800a22d8  2404ffff  addiu $a0,$zero,0xffff
 * 0x800a22dc  2402ffff  addiu $v0,$zero,0xffff
 * 0x800a22e0  1082000c  beq $a0,$v0,+12
 * 0x800a22e4  3c038014  lui $v1,0x8014
 * 0x800a22e8  2463bc90  addiu $v1,$v1,0xbc90
 * 0x800a22ec  00041240  sll $v0,$a0,9
 * 0x800a22f0  00441023  subu $v0,$v0,$a0
 * 0x800a22f4  000210c0  sll $v0,$v0,3
 * 0x800a22f8  00431021  addu $v0,$v0,$v1
 * 0x800a22fc  90420fc4  lbu $v0,4036($v0)
 * 0x800a2300  03e00008  jr $ra
 * 0x800a2304  00000000  sll $zero,$zero,0
 */
