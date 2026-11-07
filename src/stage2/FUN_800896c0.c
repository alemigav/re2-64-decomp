/* FUN_800896c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800896c0  body 0x800896c0..0x8008972f  size 112 B
 * body sha256 55ab6b81abff9d48df3921dc0f33fde3ac73baa98cb6238ed0829c81582e4d91
 * EXTENT MEASURED, NOT RECONSTRUCTED: 28 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x800896c0..0x8008972f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800896c0  2402ffff  addiu $v0,$zero,0xffff
 * 0x800896c4  908701a3  lbu $a3,419($a0)
 * 0x800896c8  8c840234  lw $a0,564($a0)
 * 0x800896cc  24e7ffff  addiu $a3,$a3,0xffff
 * 0x800896d0  10e20015  beq $a3,$v0,+21
 * 0x800896d4  00002821  addu $a1,$zero,$zero
 * 0x800896d8  00404021  addu $t0,$v0,$zero
 * 0x800896dc  248600bc  addiu $a2,$a0,0x00bc
 * 0x800896e0  24a5000c  addiu $a1,$a1,0x000c
 * 0x800896e4  8cc2fff8  lw $v0,-8($a2)
 * 0x800896e8  8cc40000  lw $a0,0($a2)
 * 0x800896ec  24c60178  addiu $a2,$a2,0x0178
 * 0x800896f0  8c430014  lw $v1,20($v0)
 * 0x800896f4  24e7ffff  addiu $a3,$a3,0xffff
 * 0x800896f8  00031080  sll $v0,$v1,2
 * 0x800896fc  00431021  addu $v0,$v0,$v1
 * 0x80089700  00021080  sll $v0,$v0,2
 * 0x80089704  8c830014  lw $v1,20($a0)
 * 0x80089708  00a22821  addu $a1,$a1,$v0
 * 0x8008970c  00031040  sll $v0,$v1,1
 * 0x80089710  00431021  addu $v0,$v0,$v1
 * 0x80089714  00021080  sll $v0,$v0,2
 * 0x80089718  00431021  addu $v0,$v0,$v1
 * 0x8008971c  00021040  sll $v0,$v0,1
 * 0x80089720  14e8ffef  bne $a3,$t0,-17
 * 0x80089724  00a22821  addu $a1,$a1,$v0
 * 0x80089728  03e00008  jr $ra
 * 0x8008972c  00a01021  addu $v0,$a1,$zero
 */
