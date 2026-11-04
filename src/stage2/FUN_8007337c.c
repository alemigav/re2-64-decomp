/* FUN_8007337c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007337c  body 0x8007337c..0x8007340f  size 148 B
 * body sha256 cce8d6a8552daaedc3699e55e19515d8bfdb85c64b490921666b7e1dfaacf3ae
 * EXTENT MEASURED, NOT RECONSTRUCTED: 37 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007337c  00804021  addu $t0,$a0,$zero
 * 0x80073380  3c028011  lui $v0,0x8011
 * 0x80073384  2442bc34  addiu $v0,$v0,0xbc34
 * 0x80073388  9046034a  lbu $a2,842($v0)
 * 0x8007338c  10c00018  beq $a2,$zero,+24
 * 0x80073390  00002021  addu $a0,$zero,$zero
 * 0x80073394  8d070154  lw $a3,340($t0)
 * 0x80073398  00402821  addu $a1,$v0,$zero
 * 0x8007339c  00a01821  addu $v1,$a1,$zero
 * 0x800733a0  8c620018  lw $v0,24($v1)
 * 0x800733a4  10470006  beq $v0,$a3,+6
 * 0x800733a8  24840001  addiu $a0,$a0,0x0001
 * 0x800733ac  0086102b  sltu $v0,$a0,$a2
 * 0x800733b0  1440fffa  bne $v0,$zero,-6
 * 0x800733b4  2465001c  addiu $a1,$v1,0x001c
 * 0x800733b8  0801ccfd  j 0x800733f4
 * 0x800733bc  3c028011  lui $v0,0x8011
 * 0x800733c0  8d04001c  lw $a0,28($t0)
 * 0x800733c4  90a20000  lbu $v0,0($a1)
 * 0x800733c8  90830001  lbu $v1,1($a0)
 * 0x800733cc  304200c0  andi $v0,$v0,0x00c0
 * 0x800733d0  00621825  or $v1,$v1,$v0
 * 0x800733d4  a0a30000  sb $v1,0($a1)
 * 0x800733d8  90820002  lbu $v0,2($a0)
 * 0x800733dc  a0a20001  sb $v0,1($a1)
 * 0x800733e0  90820003  lbu $v0,3($a0)
 * 0x800733e4  a0a20002  sb $v0,2($a1)
 * 0x800733e8  90820004  lbu $v0,4($a0)
 * 0x800733ec  a0a20003  sb $v0,3($a1)
 * 0x800733f0  3c028011  lui $v0,0x8011
 * 0x800733f4  8d03001c  lw $v1,28($t0)
 * 0x800733f8  24040001  addiu $a0,$zero,0x0001
 * 0x800733fc  ac445280  sw $a0,21120($v0)
 * 0x80073400  00801021  addu $v0,$a0,$zero
 * 0x80073404  24630005  addiu $v1,$v1,0x0005
 * 0x80073408  03e00008  jr $ra
 * 0x8007340c  ad03001c  sw $v1,28($t0)
 */
