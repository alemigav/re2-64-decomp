/* FUN_80073e38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073e38  body 0x80073e38..0x80073efb  size 196 B
 * body sha256 57777d84aea39882283680d4631f5e079ce31668aa093cc779893c1c00575ac9
 * EXTENT MEASURED, NOT RECONSTRUCTED: 49 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073e38  00804021  addu $t0,$a0,$zero
 * 0x80073e3c  3c040001  lui $a0,0x0001
 * 0x80073e40  34848000  ori $a0,$a0,0x8000
 * 0x80073e44  3c028010  lui $v0,0x8010
 * 0x80073e48  2442e288  addiu $v0,$v0,0xe288
 * 0x80073e4c  34038000  ori $v1,$zero,0x8000
 * 0x80073e50  00431021  addu $v0,$v0,$v1
 * 0x80073e54  3c038011  lui $v1,0x8011
 * 0x80073e58  91070001  lbu $a3,1($t0)
 * 0x80073e5c  3c050002  lui $a1,0x0002
 * 0x80073e60  a047500f  sb $a3,20495($v0)
 * 0x80073e64  3c02800c  lui $v0,0x800c
 * 0x80073e68  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073e6c  00442021  addu $a0,$v0,$a0
 * 0x80073e70  8c6652cc  lw $a2,21196($v1)
 * 0x80073e74  8c831a3c  lw $v1,6716($a0)
 * 0x80073e78  00451021  addu $v0,$v0,$a1
 * 0x80073e7c  a0470f55  sb $a3,3925($v0)
 * 0x80073e80  30630040  andi $v1,$v1,0x0040
 * 0x80073e84  10600006  beq $v1,$zero,+6
 * 0x80073e88  ac860530  sw $a2,1328($a0)
 * 0x80073e8c  30e300ff  andi $v1,$a3,0x00ff
 * 0x80073e90  2402001e  addiu $v0,$zero,0x001e
 * 0x80073e94  14620002  bne $v1,$v0,+2
 * 0x80073e98  24020002  addiu $v0,$zero,0x0002
 * 0x80073e9c  a5020002  sh $v0,2($t0)
 * 0x80073ea0  91020007  lbu $v0,7($t0)
 * 0x80073ea4  30420001  andi $v0,$v0,0x0001
 * 0x80073ea8  14400014  bne $v0,$zero,+20
 * 0x80073eac  3c030001  lui $v1,0x0001
 * 0x80073eb0  3c060001  lui $a2,0x0001
 * 0x80073eb4  34c68000  ori $a2,$a2,0x8000
 * 0x80073eb8  00001021  addu $v0,$zero,$zero
 * 0x80073ebc  3c048013  lui $a0,0x8013
 * 0x80073ec0  24030002  addiu $v1,$zero,0x0002
 * 0x80073ec4  3c058013  lui $a1,0x8013
 * 0x80073ec8  a083bfa8  sb $v1,-16472($a0)
 * 0x80073ecc  24030001  addiu $v1,$zero,0x0001
 * 0x80073ed0  a0a31780  sb $v1,6016($a1)
 * 0x80073ed4  3c03800c  lui $v1,0x800c
 * 0x80073ed8  246376b0  addiu $v1,$v1,0x76b0
 * 0x80073edc  00661821  addu $v1,$v1,$a2
 * 0x80073ee0  24a51780  addiu $a1,$a1,0x1780
 * 0x80073ee4  8c641a5c  lw $a0,6748($v1)
 * 0x80073ee8  8c661a60  lw $a2,6752($v1)
 * 0x80073eec  34848000  ori $a0,$a0,0x8000
 * 0x80073ef0  aca60044  sw $a2,68($a1)
 * 0x80073ef4  03e00008  jr $ra
 * 0x80073ef8  ac641a5c  sw $a0,6748($v1)
 */
