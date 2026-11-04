/* FUN_800a2108
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2108  body 0x800a2108..0x800a2193  size 140 B
 * body sha256 db79d90bbe1d441ce8dce309c585b8083c6ccb938dd8143126f403f3183e6e0a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 35 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a2108  3c028013  lui $v0,0x8013
 * 0x800a210c  90426310  lbu $v0,25360($v0)
 * 0x800a2110  10400023  beq $v0,$zero,+35
 * 0x800a2114  00001821  addu $v1,$zero,$zero
 * 0x800a2118  3c027fff  lui $v0,0x7fff
 * 0x800a211c  3442ffff  ori $v0,$v0,0xffff
 * 0x800a2120  00823824  and $a3,$a0,$v0
 * 0x800a2124  3c028014  lui $v0,0x8014
 * 0x800a2128  2446bc90  addiu $a2,$v0,0xbc90
 * 0x800a212c  90c20fc1  lbu $v0,4033($a2)
 * 0x800a2130  54400005  op&0x15 $zero,$v0,0x0005
 * 0x800a2134  24630001  addiu $v1,$v1,0x0001
 * 0x800a2138  8cc20000  lw $v0,0($a2)
 * 0x800a213c  10470015  beq $v0,$a3,+21
 * 0x800a2140  3c028000  lui $v0,0x8000
 * 0x800a2144  24630001  addiu $v1,$v1,0x0001
 * 0x800a2148  2c620008  op&0x0b $v0,$v1,0x0008
 * 0x800a214c  1440fff7  bne $v0,$zero,-9
 * 0x800a2150  24c60ff8  addiu $a2,$a2,0x0ff8
 * 0x800a2154  2404ffff  addiu $a0,$zero,0xffff
 * 0x800a2158  2402ffff  addiu $v0,$zero,0xffff
 * 0x800a215c  10820010  beq $a0,$v0,+16
 * 0x800a2160  00000000  sll $zero,$zero,0
 * 0x800a2164  0480000e  op&0x01 $zero,$a0,0x000e
 * 0x800a2168  3c028014  lui $v0,0x8014
 * 0x800a216c  2442bc90  addiu $v0,$v0,0xbc90
 * 0x800a2170  00041a40  sll $v1,$a0,9
 * 0x800a2174  00641823  subu $v1,$v1,$a0
 * 0x800a2178  000318c0  sll $v1,$v1,3
 * 0x800a217c  00621821  addu $v1,$v1,$v0
 * 0x800a2180  30a200ff  andi $v0,$a1,0x00ff
 * 0x800a2184  2c420001  op&0x0b $v0,$v0,0x0001
 * 0x800a2188  a0620fc5  sb $v0,4037($v1)
 * 0x800a218c  03e00008  jr $ra
 * 0x800a2190  24020001  addiu $v0,$zero,0x0001
 */
