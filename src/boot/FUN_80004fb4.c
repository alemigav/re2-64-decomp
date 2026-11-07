/* FUN_80004fb4
 * image   boot (boot), base 0x80000480
 * address 0x80004fb4  body 0x80004fb4..0x80005073  size 192 B
 * body sha256 fdc5afaa1eb8bcded395856aaea527c32da30d9d33040592d7a3e9f4451d4460
 * EXTENT MEASURED, NOT RECONSTRUCTED: 48 words, found by the extent scan inside a byte-map region no artifact names (extent measured, text withdrawn (M369): this function was reconstructed from an unlicensed third-party corpus and the reconstruction has been removed; the address, extent and word count stand, the C does not)
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
 * 0x80004fb4  00804021  addu $t0,$a0,$zero
 * 0x80004fb8  240affff  addiu $t2,$zero,0xffff
 * 0x80004fbc  24090001  addiu $t1,$zero,0x0001
 * 0x80004fc0  90a60000  lbu $a2,0($a1)
 * 0x80004fc4  00061600  sll $v0,$a2,24
 * 0x80004fc8  00021603  sra $v0,$v0,24
 * 0x80004fcc  18400013  blez $v0,+19
 * 0x80004fd0  24a50001  addiu $a1,$a1,0x0001
 * 0x80004fd4  24c2ffff  addiu $v0,$a2,0xffff
 * 0x80004fd8  00403021  addu $a2,$v0,$zero
 * 0x80004fdc  00021600  sll $v0,$v0,24
 * 0x80004fe0  00021603  sra $v0,$v0,24
 * 0x80004fe4  104a001f  beq $v0,$t2,+31
 * 0x80004fe8  00061600  sll $v0,$a2,24
 * 0x80004fec  2407ffff  addiu $a3,$zero,0xffff
 * 0x80004ff0  90a30000  lbu $v1,0($a1)
 * 0x80004ff4  24a50001  addiu $a1,$a1,0x0001
 * 0x80004ff8  24c2ffff  addiu $v0,$a2,0xffff
 * 0x80004ffc  00403021  addu $a2,$v0,$zero
 * 0x80005000  00021600  sll $v0,$v0,24
 * 0x80005004  00021603  sra $v0,$v0,24
 * 0x80005008  a0830000  sb $v1,0($a0)
 * 0x8000500c  1447fff8  bne $v0,$a3,-8
 * 0x80005010  24840001  addiu $a0,$a0,0x0001
 * 0x80005014  08001419  j 0x80005064
 * 0x80005018  00061600  sll $v0,$a2,24
 * 0x8000501c  04410011  op&0x01 $at,$v0,0x0011
 * 0x80005020  00061600  sll $v0,$a2,24
 * 0x80005024  90a30000  lbu $v1,0($a1)
 * 0x80005028  24c20001  addiu $v0,$a2,0x0001
 * 0x8000502c  00403021  addu $a2,$v0,$zero
 * 0x80005030  00021600  sll $v0,$v0,24
 * 0x80005034  00021603  sra $v0,$v0,24
 * 0x80005038  10490009  beq $v0,$t1,+9
 * 0x8000503c  24a50001  addiu $a1,$a1,0x0001
 * 0x80005040  24070001  addiu $a3,$zero,0x0001
 * 0x80005044  a0830000  sb $v1,0($a0)
 * 0x80005048  24c20001  addiu $v0,$a2,0x0001
 * 0x8000504c  00403021  addu $a2,$v0,$zero
 * 0x80005050  00021600  sll $v0,$v0,24
 * 0x80005054  00021603  sra $v0,$v0,24
 * 0x80005058  1447fffa  bne $v0,$a3,-6
 * 0x8000505c  24840001  addiu $a0,$a0,0x0001
 * 0x80005060  00061600  sll $v0,$a2,24
 * 0x80005064  1440ffd6  bne $v0,$zero,-42
 * 0x80005068  00881023  subu $v0,$a0,$t0
 * 0x8000506c  03e00008  jr $ra
 * 0x80005070  00000000  sll $zero,$zero,0
 */
