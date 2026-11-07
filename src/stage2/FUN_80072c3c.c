/* FUN_80072c3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072c3c  body 0x80072c3c..0x80072d03  size 200 B
 * body sha256 c9d83ff77aed5f671b4b52e867f1818b9a7795b973ec004188f8f42ab984c442
 * EXTENT MEASURED, NOT RECONSTRUCTED: 50 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80072c3c  00803021  addu $a2,$a0,$zero
 * 0x80072c40  3c050001  lui $a1,0x0001
 * 0x80072c44  34a58000  ori $a1,$a1,0x8000
 * 0x80072c48  3c03800c  lui $v1,0x800c
 * 0x80072c4c  246376b0  addiu $v1,$v1,0x76b0
 * 0x80072c50  3c020002  lui $v0,0x0002
 * 0x80072c54  00621021  addu $v0,$v1,$v0
 * 0x80072c58  00651821  addu $v1,$v1,$a1
 * 0x80072c5c  844415fc  lh $a0,5628($v0)
 * 0x80072c60  8c63027c  lw $v1,636($v1)
 * 0x80072c64  8cc5001c  lw $a1,28($a2)
 * 0x80072c68  00041080  sll $v0,$a0,2
 * 0x80072c6c  00441021  addu $v0,$v0,$a0
 * 0x80072c70  000210c0  sll $v0,$v0,3
 * 0x80072c74  8c63002c  lw $v1,44($v1)
 * 0x80072c78  90a40002  lbu $a0,2($a1)
 * 0x80072c7c  00621821  addu $v1,$v1,$v0
 * 0x80072c80  00041040  sll $v0,$a0,1
 * 0x80072c84  00441021  addu $v0,$v0,$a0
 * 0x80072c88  00021040  sll $v0,$v0,1
 * 0x80072c8c  24420010  addiu $v0,$v0,0x0010
 * 0x80072c90  00621821  addu $v1,$v1,$v0
 * 0x80072c94  90a40003  lbu $a0,3($a1)
 * 0x80072c98  2402000c  addiu $v0,$zero,0x000c
 * 0x80072c9c  10820010  beq $a0,$v0,+16
 * 0x80072ca0  00000000  sll $zero,$zero,0
 * 0x80072ca4  2882000d  op&0x0a $v0,$a0,0x000d
 * 0x80072ca8  10400005  beq $v0,$zero,+5
 * 0x80072cac  2402000b  addiu $v0,$zero,0x000b
 * 0x80072cb0  10820008  beq $a0,$v0,+8
 * 0x80072cb4  00000000  sll $zero,$zero,0
 * 0x80072cb8  0801cb3e  j 0x80072cf8
 * 0x80072cbc  24a20006  addiu $v0,$a1,0x0006
 * 0x80072cc0  2402000d  addiu $v0,$zero,0x000d
 * 0x80072cc4  10820009  beq $a0,$v0,+9
 * 0x80072cc8  00000000  sll $zero,$zero,0
 * 0x80072ccc  0801cb3e  j 0x80072cf8
 * 0x80072cd0  24a20006  addiu $v0,$a1,0x0006
 * 0x80072cd4  94a20004  lhu $v0,4($a1)
 * 0x80072cd8  0801cb3d  j 0x80072cf4
 * 0x80072cdc  a4620000  sh $v0,0($v1)
 * 0x80072ce0  94a20004  lhu $v0,4($a1)
 * 0x80072ce4  0801cb3d  j 0x80072cf4
 * 0x80072ce8  a4620002  sh $v0,2($v1)
 * 0x80072cec  94a20004  lhu $v0,4($a1)
 * 0x80072cf0  a4620004  sh $v0,4($v1)
 * 0x80072cf4  24a20006  addiu $v0,$a1,0x0006
 * 0x80072cf8  acc2001c  sw $v0,28($a2)
 * 0x80072cfc  03e00008  jr $ra
 * 0x80072d00  24020001  addiu $v0,$zero,0x0001
 */
