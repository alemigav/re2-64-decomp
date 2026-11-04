/* FUN_80073224
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073224  body 0x80073224..0x800732d7  size 180 B
 * body sha256 be4a68b8e9b68aa76a30611e288e7a595721fb2fbb4d0cf5219c4af84d9603d3
 * EXTENT MEASURED, NOT RECONSTRUCTED: 45 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073224  00803821  addu $a3,$a0,$zero
 * 0x80073228  8ce6001c  lw $a2,28($a3)
 * 0x8007322c  90c30002  lbu $v1,2($a2)
 * 0x80073230  8ce40154  lw $a0,340($a3)
 * 0x80073234  00031040  sll $v0,$v1,1
 * 0x80073238  00431021  addu $v0,$v0,$v1
 * 0x8007323c  00021100  sll $v0,$v0,4
 * 0x80073240  00431023  subu $v0,$v0,$v1
 * 0x80073244  8c830234  lw $v1,564($a0)
 * 0x80073248  000210c0  sll $v0,$v0,3
 * 0x8007324c  00622821  addu $a1,$v1,$v0
 * 0x80073250  3c02800c  lui $v0,0x800c
 * 0x80073254  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073258  3c030002  lui $v1,0x0002
 * 0x8007325c  00431021  addu $v0,$v0,$v1
 * 0x80073260  90421962  lbu $v0,6498($v0)
 * 0x80073264  8ca30000  lw $v1,0($a1)
 * 0x80073268  30420008  andi $v0,$v0,0x0008
 * 0x8007326c  54400001  op&0x15 $zero,$v0,0x0001
 * 0x80073270  3463004a  ori $v1,$v1,0x004a
 * 0x80073274  aca30000  sw $v1,0($a1)
 * 0x80073278  90c40003  lbu $a0,3($a2)
 * 0x8007327c  90c20004  lbu $v0,4($a2)
 * 0x80073280  90c30005  lbu $v1,5($a2)
 * 0x80073284  a4a00138  sh $zero,312($a1)
 * 0x80073288  00021200  sll $v0,$v0,8
 * 0x8007328c  00822025  or $a0,$a0,$v0
 * 0x80073290  00031c00  sll $v1,$v1,16
 * 0x80073294  00832025  or $a0,$a0,$v1
 * 0x80073298  aca40060  sw $a0,96($a1)
 * 0x8007329c  94c20006  lhu $v0,6($a2)
 * 0x800732a0  a4a20130  sh $v0,304($a1)
 * 0x800732a4  94c20008  lhu $v0,8($a2)
 * 0x800732a8  a4a20134  sh $v0,308($a1)
 * 0x800732ac  94c2000a  lhu $v0,10($a2)
 * 0x800732b0  a4a2013c  sh $v0,316($a1)
 * 0x800732b4  94c2000c  lhu $v0,12($a2)
 * 0x800732b8  a4a20132  sh $v0,306($a1)
 * 0x800732bc  94c2000e  lhu $v0,14($a2)
 * 0x800732c0  a4a20136  sh $v0,310($a1)
 * 0x800732c4  8ce2001c  lw $v0,28($a3)
 * 0x800732c8  24420010  addiu $v0,$v0,0x0010
 * 0x800732cc  ace2001c  sw $v0,28($a3)
 * 0x800732d0  03e00008  jr $ra
 * 0x800732d4  24020001  addiu $v0,$zero,0x0001
 */
