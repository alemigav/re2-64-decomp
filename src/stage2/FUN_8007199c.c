/* FUN_8007199c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007199c  body 0x8007199c..0x80071b03  size 360 B
 * body sha256 066dd7ea001649589bd643aaf472aa66b1de910269b017fe7c7f01ea2e8c3cec
 * EXTENT MEASURED, NOT RECONSTRUCTED: 90 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007199c  8c860154  lw $a2,340($a0)
 * 0x800719a0  8c88001c  lw $t0,28($a0)
 * 0x800719a4  94c20268  lhu $v0,616($a2)
 * 0x800719a8  90c70008  lbu $a3,8($a2)
 * 0x800719ac  91050002  lbu $a1,2($t0)
 * 0x800719b0  30420004  andi $v0,$v0,0x0004
 * 0x800719b4  10400004  beq $v0,$zero,+4
 * 0x800719b8  00051400  sll $v0,$a1,16
 * 0x800719bc  90c20005  lbu $v0,5($a2)
 * 0x800719c0  10450004  beq $v0,$a1,+4
 * 0x800719c4  00051400  sll $v0,$a1,16
 * 0x800719c8  3c030400  lui $v1,0x0400
 * 0x800719cc  00431025  or $v0,$v0,$v1
 * 0x800719d0  acc20004  sw $v0,4($a2)
 * 0x800719d4  2ce20010  op&0x0b $v0,$a3,0x0010
 * 0x800719d8  1040001e  beq $v0,$zero,+30
 * 0x800719dc  24a3fffc  addiu $v1,$a1,0xfffc
 * 0x800719e0  2c62000f  op&0x0b $v0,$v1,0x000f
 * 0x800719e4  10400037  beq $v0,$zero,+55
 * 0x800719e8  00031880  sll $v1,$v1,2
 * 0x800719ec  3c02800c  lui $v0,0x800c
 * 0x800719f0  24429910  addiu $v0,$v0,0x9910
 * 0x800719f4  00621821  addu $v1,$v1,$v0
 * 0x800719f8  8c620000  lw $v0,0($v1)
 * 0x800719fc  00400008  jr $v0
 * 0x80071a00  00000000  sll $zero,$zero,0
 * 0x80071a04  3c028011  lui $v0,0x8011
 * 0x80071a08  24425130  addiu $v0,$v0,0x5130
 * 0x80071a0c  0801c6ad  j 0x80071ab4
 * 0x80071a10  24e30010  addiu $v1,$a3,0x0010
 * 0x80071a14  3c028011  lui $v0,0x8011
 * 0x80071a18  24425230  addiu $v0,$v0,0x5230
 * 0x80071a1c  0801c6ad  j 0x80071ab4
 * 0x80071a20  24e30010  addiu $v1,$a3,0x0010
 * 0x80071a24  3c028011  lui $v0,0x8011
 * 0x80071a28  24425170  addiu $v0,$v0,0x5170
 * 0x80071a2c  0801c6ad  j 0x80071ab4
 * 0x80071a30  24e30010  addiu $v1,$a3,0x0010
 * 0x80071a34  3c028011  lui $v0,0x8011
 * 0x80071a38  244251f0  addiu $v0,$v0,0x51f0
 * 0x80071a3c  0801c6ad  j 0x80071ab4
 * 0x80071a40  24e30010  addiu $v1,$a3,0x0010
 * 0x80071a44  3c028011  lui $v0,0x8011
 * 0x80071a48  244251b0  addiu $v0,$v0,0x51b0
 * 0x80071a4c  0801c6ad  j 0x80071ab4
 * 0x80071a50  24e30010  addiu $v1,$a3,0x0010
 * 0x80071a54  2c62000f  op&0x0b $v0,$v1,0x000f
 * 0x80071a58  1040001a  beq $v0,$zero,+26
 * 0x80071a5c  00031880  sll $v1,$v1,2
 * 0x80071a60  3c02800c  lui $v0,0x800c
 * 0x80071a64  24429950  addiu $v0,$v0,0x9950
 * 0x80071a68  00621821  addu $v1,$v1,$v0
 * 0x80071a6c  8c620000  lw $v0,0($v1)
 * 0x80071a70  00400008  jr $v0
 * 0x80071a74  00000000  sll $zero,$zero,0
 * 0x80071a78  3c028011  lui $v0,0x8011
 * 0x80071a7c  0801c6ac  j 0x80071ab0
 * 0x80071a80  24425130  addiu $v0,$v0,0x5130
 * 0x80071a84  3c028011  lui $v0,0x8011
 * 0x80071a88  0801c6ac  j 0x80071ab0
 * 0x80071a8c  24425230  addiu $v0,$v0,0x5230
 * 0x80071a90  3c028011  lui $v0,0x8011
 * 0x80071a94  0801c6ac  j 0x80071ab0
 * 0x80071a98  24425170  addiu $v0,$v0,0x5170
 * 0x80071a9c  3c028011  lui $v0,0x8011
 * 0x80071aa0  0801c6ac  j 0x80071ab0
 * 0x80071aa4  244251f0  addiu $v0,$v0,0x51f0
 * 0x80071aa8  3c028011  lui $v0,0x8011
 * 0x80071aac  244251b0  addiu $v0,$v0,0x51b0
 * 0x80071ab0  24e3ffc0  addiu $v1,$a3,0xffc0
 * 0x80071ab4  00031840  sll $v1,$v1,1
 * 0x80071ab8  00621821  addu $v1,$v1,$v0
 * 0x80071abc  90620001  lbu $v0,1($v1)
 * 0x80071ac0  a4c20270  sh $v0,624($a2)
 * 0x80071ac4  91020003  lbu $v0,3($t0)
 * 0x80071ac8  a4c00268  sh $zero,616($a2)
 * 0x80071acc  a4c00272  sh $zero,626($a2)
 * 0x80071ad0  a0c20267  sb $v0,615($a2)
 * 0x80071ad4  95020004  lhu $v0,4($t0)
 * 0x80071ad8  a4c20260  sh $v0,608($a2)
 * 0x80071adc  95020006  lhu $v0,6($t0)
 * 0x80071ae0  a4c20262  sh $v0,610($a2)
 * 0x80071ae4  94c20260  lhu $v0,608($a2)
 * 0x80071ae8  94c30262  lhu $v1,610($a2)
 * 0x80071aec  a4c20274  sh $v0,628($a2)
 * 0x80071af0  25020008  addiu $v0,$t0,0x0008
 * 0x80071af4  a4c30276  sh $v1,630($a2)
 * 0x80071af8  ac82001c  sw $v0,28($a0)
 * 0x80071afc  03e00008  jr $ra
 * 0x80071b00  24020001  addiu $v0,$zero,0x0001
 */
