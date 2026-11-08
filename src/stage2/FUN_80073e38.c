/* FUN_80073e38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073e38  body 0x80073e38..0x80073f1f  size 232 B
 * body sha256 abe5a8d8fbad7d302f7bf034e484dd8be7e7e0239250fad2865f5480a112275d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 58 words, found by the extent scan inside a byte-map region no artifact names (M388 correction (split at an EARLY RETURN, not at a function end): the extent opened on `ori $v1,$v1,0x8000`, reading a register the previous 9 words had just materialised -- `bne` at 0x80073ea8 targets 0x80073efc, so this is the second half of one body whose real start is 0x80073e38 (the word after the previous `jr ra`+`addiu sp,sp,0x18` at 0x80073e30/34). 58 words, and it carries the M372 shape internally (`lui 1; ori 0x8000` = the 0x18000 constant))
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
 * 0x80073efc  34638000  ori $v1,$v1,0x8000
 * 0x80073f00  24020001  addiu $v0,$zero,0x0001
 * 0x80073f04  3c04800c  lui $a0,0x800c
 * 0x80073f08  248476b0  addiu $a0,$a0,0x76b0
 * 0x80073f0c  00832021  addu $a0,$a0,$v1
 * 0x80073f10  24030006  addiu $v1,$zero,0x0006
 * 0x80073f14  a0831a85  sb $v1,6789($a0)
 * 0x80073f18  03e00008  jr $ra
 * 0x80073f1c  a0801a86  sb $zero,6790($a0)
 */
