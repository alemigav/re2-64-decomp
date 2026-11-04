/* FUN_80088498
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088498  body 0x80088498..0x80088527  size 144 B
 * body sha256 c148ecc1b992379e5f8c23ad84b4c63976bf163ee16a8fcea40cd14e3b364b05
 * EXTENT MEASURED, NOT RECONSTRUCTED: 36 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80088498  3c028013  lui $v0,0x8013
 * 0x8008849c  8c45bae0  lw $a1,-17696($v0)
 * 0x800884a0  94a30000  lhu $v1,0($a1)
 * 0x800884a4  30620008  andi $v0,$v1,0x0008
 * 0x800884a8  14400025  bne $v0,$zero,+37
 * 0x800884ac  00003821  addu $a3,$zero,$zero
 * 0x800884b0  24090001  addiu $t1,$zero,0x0001
 * 0x800884b4  8ca20004  lw $v0,4($a1)
 * 0x800884b8  00a23021  addu $a2,$a1,$v0
 * 0x800884bc  30620002  andi $v0,$v1,0x0002
 * 0x800884c0  10400019  beq $v0,$zero,+25
 * 0x800884c4  24c80010  addiu $t0,$a2,0x0010
 * 0x800884c8  54850018  op&0x15 $a1,$a0,0x0018
 * 0x800884cc  00a03821  addu $a3,$a1,$zero
 * 0x800884d0  a4a90000  sh $t1,0($a1)
 * 0x800884d4  94c20010  lhu $v0,16($a2)
 * 0x800884d8  30420001  andi $v0,$v0,0x0001
 * 0x800884dc  10400006  beq $v0,$zero,+6
 * 0x800884e0  00000000  sll $zero,$zero,0
 * 0x800884e4  8ca20004  lw $v0,4($a1)
 * 0x800884e8  8d030004  lw $v1,4($t0)
 * 0x800884ec  24420010  addiu $v0,$v0,0x0010
 * 0x800884f0  00431021  addu $v0,$v0,$v1
 * 0x800884f4  aca20004  sw $v0,4($a1)
 * 0x800884f8  10e00011  beq $a3,$zero,+17
 * 0x800884fc  00000000  sll $zero,$zero,0
 * 0x80088500  94e20000  lhu $v0,0($a3)
 * 0x80088504  30420001  andi $v0,$v0,0x0001
 * 0x80088508  1040000d  beq $v0,$zero,+13
 * 0x8008850c  00000000  sll $zero,$zero,0
 * 0x80088510  8ce20004  lw $v0,4($a3)
 * 0x80088514  8ca30004  lw $v1,4($a1)
 * 0x80088518  24420010  addiu $v0,$v0,0x0010
 * 0x8008851c  00431021  addu $v0,$v0,$v1
 * 0x80088520  03e00008  jr $ra
 * 0x80088524  ace20004  sw $v0,4($a3)
 */
