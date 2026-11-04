/* FUN_80072ddc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072ddc  body 0x80072ddc..0x80072e9b  size 192 B
 * body sha256 23a787e8b940239b7876aaab74f0e14ce21c6551c830b4a555582afddf84b16a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 48 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80072ddc  00803021  addu $a2,$a0,$zero
 * 0x80072de0  3c020001  lui $v0,0x0001
 * 0x80072de4  34428000  ori $v0,$v0,0x8000
 * 0x80072de8  3c03800c  lui $v1,0x800c
 * 0x80072dec  246376b0  addiu $v1,$v1,0x76b0
 * 0x80072df0  00621821  addu $v1,$v1,$v0
 * 0x80072df4  8cc5001c  lw $a1,28($a2)
 * 0x80072df8  8c63027c  lw $v1,636($v1)
 * 0x80072dfc  90a40001  lbu $a0,1($a1)
 * 0x80072e00  8c63002c  lw $v1,44($v1)
 * 0x80072e04  00041080  sll $v0,$a0,2
 * 0x80072e08  00441021  addu $v0,$v0,$a0
 * 0x80072e0c  000210c0  sll $v0,$v0,3
 * 0x80072e10  90a40002  lbu $a0,2($a1)
 * 0x80072e14  00621821  addu $v1,$v1,$v0
 * 0x80072e18  00041040  sll $v0,$a0,1
 * 0x80072e1c  00441021  addu $v0,$v0,$a0
 * 0x80072e20  00021040  sll $v0,$v0,1
 * 0x80072e24  24420010  addiu $v0,$v0,0x0010
 * 0x80072e28  00621821  addu $v1,$v1,$v0
 * 0x80072e2c  90a40003  lbu $a0,3($a1)
 * 0x80072e30  2402000c  addiu $v0,$zero,0x000c
 * 0x80072e34  10820010  beq $a0,$v0,+16
 * 0x80072e38  00000000  sll $zero,$zero,0
 * 0x80072e3c  2882000d  op&0x0a $v0,$a0,0x000d
 * 0x80072e40  10400005  beq $v0,$zero,+5
 * 0x80072e44  2402000b  addiu $v0,$zero,0x000b
 * 0x80072e48  10820008  beq $a0,$v0,+8
 * 0x80072e4c  00000000  sll $zero,$zero,0
 * 0x80072e50  0801cba4  j 0x80072e90
 * 0x80072e54  24a20006  addiu $v0,$a1,0x0006
 * 0x80072e58  2402000d  addiu $v0,$zero,0x000d
 * 0x80072e5c  10820009  beq $a0,$v0,+9
 * 0x80072e60  00000000  sll $zero,$zero,0
 * 0x80072e64  0801cba4  j 0x80072e90
 * 0x80072e68  24a20006  addiu $v0,$a1,0x0006
 * 0x80072e6c  94a20004  lhu $v0,4($a1)
 * 0x80072e70  0801cba3  j 0x80072e8c
 * 0x80072e74  a4620000  sh $v0,0($v1)
 * 0x80072e78  94a20004  lhu $v0,4($a1)
 * 0x80072e7c  0801cba3  j 0x80072e8c
 * 0x80072e80  a4620002  sh $v0,2($v1)
 * 0x80072e84  94a20004  lhu $v0,4($a1)
 * 0x80072e88  a4620004  sh $v0,4($v1)
 * 0x80072e8c  24a20006  addiu $v0,$a1,0x0006
 * 0x80072e90  acc2001c  sw $v0,28($a2)
 * 0x80072e94  03e00008  jr $ra
 * 0x80072e98  24020001  addiu $v0,$zero,0x0001
 */
