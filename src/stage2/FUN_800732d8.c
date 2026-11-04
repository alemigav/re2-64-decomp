/* FUN_800732d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800732d8  body 0x800732d8..0x8007337b  size 164 B
 * body sha256 1cd341d7a6559b7f22c43dc00c3ace79cdc7a8373e6508d137c9e4a9964e082f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 41 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800732d8  00803021  addu $a2,$a0,$zero
 * 0x800732dc  8cc5001c  lw $a1,28($a2)
 * 0x800732e0  90a30001  lbu $v1,1($a1)
 * 0x800732e4  8cc40154  lw $a0,340($a2)
 * 0x800732e8  00031040  sll $v0,$v1,1
 * 0x800732ec  00431021  addu $v0,$v0,$v1
 * 0x800732f0  00021100  sll $v0,$v0,4
 * 0x800732f4  00431023  subu $v0,$v0,$v1
 * 0x800732f8  8c830234  lw $v1,564($a0)
 * 0x800732fc  000210c0  sll $v0,$v0,3
 * 0x80073300  00622021  addu $a0,$v1,$v0
 * 0x80073304  3c02800c  lui $v0,0x800c
 * 0x80073308  244276b0  addiu $v0,$v0,0x76b0
 * 0x8007330c  3c030002  lui $v1,0x0002
 * 0x80073310  00431021  addu $v0,$v0,$v1
 * 0x80073314  90421962  lbu $v0,6498($v0)
 * 0x80073318  8c830000  lw $v1,0($a0)
 * 0x8007331c  30420008  andi $v0,$v0,0x0008
 * 0x80073320  54400001  op&0x15 $zero,$v0,0x0001
 * 0x80073324  34631062  ori $v1,$v1,0x1062
 * 0x80073328  ac830000  sw $v1,0($a0)
 * 0x8007332c  a480011e  sh $zero,286($a0)
 * 0x80073330  94a20002  lhu $v0,2($a1)
 * 0x80073334  a4820028  sh $v0,40($a0)
 * 0x80073338  94a20004  lhu $v0,4($a1)
 * 0x8007333c  a482002c  sh $v0,44($a0)
 * 0x80073340  94a20006  lhu $v0,6($a1)
 * 0x80073344  a482002a  sh $v0,42($a0)
 * 0x80073348  90a20009  lbu $v0,9($a1)
 * 0x8007334c  a0820111  sb $v0,273($a0)
 * 0x80073350  94a2000a  lhu $v0,10($a1)
 * 0x80073354  a482002e  sh $v0,46($a0)
 * 0x80073358  94a2000c  lhu $v0,12($a1)
 * 0x8007335c  a4820030  sh $v0,48($a0)
 * 0x80073360  94a2000e  lhu $v0,14($a1)
 * 0x80073364  a4820032  sh $v0,50($a0)
 * 0x80073368  8cc2001c  lw $v0,28($a2)
 * 0x8007336c  24420010  addiu $v0,$v0,0x0010
 * 0x80073370  acc2001c  sw $v0,28($a2)
 * 0x80073374  03e00008  jr $ra
 * 0x80073378  24020001  addiu $v0,$zero,0x0001
 */
