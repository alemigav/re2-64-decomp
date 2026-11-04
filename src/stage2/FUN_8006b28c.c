/* FUN_8006b28c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b28c  body 0x8006b28c..0x8006b31f  size 148 B
 * body sha256 21074e57291e14138f9df79e2240505f0a73bd0018f31be17fa6fa2cd95968e2
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
 * 0x8006b28c  3c030001  lui $v1,0x0001
 * 0x8006b290  346399b8  ori $v1,$v1,0x99b8
 * 0x8006b294  3c02800c  lui $v0,0x800c
 * 0x8006b298  244276b0  addiu $v0,$v0,0x76b0
 * 0x8006b29c  00433821  addu $a3,$v0,$v1
 * 0x8006b2a0  3c030001  lui $v1,0x0001
 * 0x8006b2a4  34638000  ori $v1,$v1,0x8000
 * 0x8006b2a8  00431021  addu $v0,$v0,$v1
 * 0x8006b2ac  ace00000  sw $zero,0($a3)
 * 0x8006b2b0  8c42027c  lw $v0,636($v0)
 * 0x8006b2b4  8c430020  lw $v1,32($v0)
 * 0x8006b2b8  8c620004  lw $v0,4($v1)
 * 0x8006b2bc  00004021  addu $t0,$zero,$zero
 * 0x8006b2c0  00021100  sll $v0,$v0,4
 * 0x8006b2c4  0801acc4  j 0x8006b310
 * 0x8006b2c8  00624821  addu $t1,$v1,$v0
 * 0x8006b2cc  9462000a  lhu $v0,10($v1)
 * 0x8006b2d0  00441024  and $v0,$v0,$a0
 * 0x8006b2d4  5040000f  op&0x14 $zero,$v0,0x000f
 * 0x8006b2d8  24630010  addiu $v1,$v1,0x0010
 * 0x8006b2dc  94620008  lhu $v0,8($v1)
 * 0x8006b2e0  00451024  and $v0,$v0,$a1
 * 0x8006b2e4  5040000b  op&0x14 $zero,$v0,0x000b
 * 0x8006b2e8  24630010  addiu $v1,$v1,0x0010
 * 0x8006b2ec  8c62000c  lw $v0,12($v1)
 * 0x8006b2f0  00461024  and $v0,$v0,$a2
 * 0x8006b2f4  10400006  beq $v0,$zero,+6
 * 0x8006b2f8  24020020  addiu $v0,$zero,0x0020
 * 0x8006b2fc  ace30000  sw $v1,0($a3)
 * 0x8006b300  24e70004  addiu $a3,$a3,0x0004
 * 0x8006b304  25080001  addiu $t0,$t0,0x0001
 * 0x8006b308  11020004  beq $t0,$v0,+4
 * 0x8006b30c  ace00000  sw $zero,0($a3)
 * 0x8006b310  24630010  addiu $v1,$v1,0x0010
 * 0x8006b314  1469ffed  bne $v1,$t1,-19
 * 0x8006b318  00000000  sll $zero,$zero,0
 * 0x8006b31c  03e00008  jr $ra
 */
