/* FUN_80005074
 * image   boot (boot), base 0x80000480
 * address 0x80005074  body 0x80005074..0x80005133  size 192 B
 * body sha256 aed7c7f4ad47a70dde7a3a76a1cebfd35a32ddfff7c36ff79e4808cac27825a9
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
 * 0x80005074  00804021  addu $t0,$a0,$zero
 * 0x80005078  240affff  addiu $t2,$zero,0xffff
 * 0x8000507c  24090001  addiu $t1,$zero,0x0001
 * 0x80005080  94a60000  lhu $a2,0($a1)
 * 0x80005084  00061400  sll $v0,$a2,16
 * 0x80005088  00021403  sra $v0,$v0,16
 * 0x8000508c  18400013  blez $v0,+19
 * 0x80005090  24a50002  addiu $a1,$a1,0x0002
 * 0x80005094  24c2ffff  addiu $v0,$a2,0xffff
 * 0x80005098  00403021  addu $a2,$v0,$zero
 * 0x8000509c  00021400  sll $v0,$v0,16
 * 0x800050a0  00021403  sra $v0,$v0,16
 * 0x800050a4  104a001f  beq $v0,$t2,+31
 * 0x800050a8  00061400  sll $v0,$a2,16
 * 0x800050ac  2407ffff  addiu $a3,$zero,0xffff
 * 0x800050b0  94a30000  lhu $v1,0($a1)
 * 0x800050b4  24a50002  addiu $a1,$a1,0x0002
 * 0x800050b8  24c2ffff  addiu $v0,$a2,0xffff
 * 0x800050bc  00403021  addu $a2,$v0,$zero
 * 0x800050c0  00021400  sll $v0,$v0,16
 * 0x800050c4  00021403  sra $v0,$v0,16
 * 0x800050c8  a4830000  sh $v1,0($a0)
 * 0x800050cc  1447fff8  bne $v0,$a3,-8
 * 0x800050d0  24840002  addiu $a0,$a0,0x0002
 * 0x800050d4  08001449  j 0x80005124
 * 0x800050d8  00061400  sll $v0,$a2,16
 * 0x800050dc  04410011  op&0x01 $at,$v0,0x0011
 * 0x800050e0  00061400  sll $v0,$a2,16
 * 0x800050e4  94a30000  lhu $v1,0($a1)
 * 0x800050e8  24c20001  addiu $v0,$a2,0x0001
 * 0x800050ec  00403021  addu $a2,$v0,$zero
 * 0x800050f0  00021400  sll $v0,$v0,16
 * 0x800050f4  00021403  sra $v0,$v0,16
 * 0x800050f8  10490009  beq $v0,$t1,+9
 * 0x800050fc  24a50002  addiu $a1,$a1,0x0002
 * 0x80005100  24070001  addiu $a3,$zero,0x0001
 * 0x80005104  a4830000  sh $v1,0($a0)
 * 0x80005108  24c20001  addiu $v0,$a2,0x0001
 * 0x8000510c  00403021  addu $a2,$v0,$zero
 * 0x80005110  00021400  sll $v0,$v0,16
 * 0x80005114  00021403  sra $v0,$v0,16
 * 0x80005118  1447fffa  bne $v0,$a3,-6
 * 0x8000511c  24840002  addiu $a0,$a0,0x0002
 * 0x80005120  00061400  sll $v0,$a2,16
 * 0x80005124  1440ffd6  bne $v0,$zero,-42
 * 0x80005128  00881023  subu $v0,$a0,$t0
 * 0x8000512c  03e00008  jr $ra
 * 0x80005130  00000000  sll $zero,$zero,0
 */
