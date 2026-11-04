/* FUN_800a2070
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2070  body 0x800a2070..0x800a20f3  size 132 B
 * body sha256 d1259cbc767d7e66402fec6db4b3920bf1c60fea6a0c6541beb0b298c5b72c76
 * EXTENT MEASURED, NOT RECONSTRUCTED: 33 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a2070  3c028013  lui $v0,0x8013
 * 0x800a2074  90426310  lbu $v0,25360($v0)
 * 0x800a2078  10400021  beq $v0,$zero,+33
 * 0x800a207c  00002821  addu $a1,$zero,$zero
 * 0x800a2080  3c027fff  lui $v0,0x7fff
 * 0x800a2084  3442ffff  ori $v0,$v0,0xffff
 * 0x800a2088  00823024  and $a2,$a0,$v0
 * 0x800a208c  3c028014  lui $v0,0x8014
 * 0x800a2090  2443bc90  addiu $v1,$v0,0xbc90
 * 0x800a2094  90620fc1  lbu $v0,4033($v1)
 * 0x800a2098  54400005  op&0x15 $zero,$v0,0x0005
 * 0x800a209c  24a50001  addiu $a1,$a1,0x0001
 * 0x800a20a0  8c620000  lw $v0,0($v1)
 * 0x800a20a4  10460013  beq $v0,$a2,+19
 * 0x800a20a8  3c028000  lui $v0,0x8000
 * 0x800a20ac  24a50001  addiu $a1,$a1,0x0001
 * 0x800a20b0  2ca20008  op&0x0b $v0,$a1,0x0008
 * 0x800a20b4  1440fff7  bne $v0,$zero,-9
 * 0x800a20b8  24630ff8  addiu $v1,$v1,0x0ff8
 * 0x800a20bc  2404ffff  addiu $a0,$zero,0xffff
 * 0x800a20c0  2402ffff  addiu $v0,$zero,0xffff
 * 0x800a20c4  1082000e  beq $a0,$v0,+14
 * 0x800a20c8  00000000  sll $zero,$zero,0
 * 0x800a20cc  0480000c  op&0x01 $zero,$a0,0x000c
 * 0x800a20d0  3c038014  lui $v1,0x8014
 * 0x800a20d4  2463bc90  addiu $v1,$v1,0xbc90
 * 0x800a20d8  00041240  sll $v0,$a0,9
 * 0x800a20dc  00441023  subu $v0,$v0,$a0
 * 0x800a20e0  000210c0  sll $v0,$v0,3
 * 0x800a20e4  00431021  addu $v0,$v0,$v1
 * 0x800a20e8  94420fc6  lhu $v0,4038($v0)
 * 0x800a20ec  03e00008  jr $ra
 * 0x800a20f0  00000000  sll $zero,$zero,0
 */
