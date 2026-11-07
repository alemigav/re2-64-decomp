/* FUN_80072f94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072f94  body 0x80072f94..0x80073017  size 132 B
 * body sha256 2e52e8b38b3b418e6d2f5834f346c9cc4b7dd9bd221f1b4215ac08ded62c773c
 * EXTENT MEASURED, NOT RECONSTRUCTED: 33 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80072f94  3c030001  lui $v1,0x0001
 * 0x80072f98  34638000  ori $v1,$v1,0x8000
 * 0x80072f9c  3c02800c  lui $v0,0x800c
 * 0x80072fa0  244276b0  addiu $v0,$v0,0x76b0
 * 0x80072fa4  00431021  addu $v0,$v0,$v1
 * 0x80072fa8  8c42027c  lw $v0,636($v0)
 * 0x80072fac  8c86001c  lw $a2,28($a0)
 * 0x80072fb0  8c450034  lw $a1,52($v0)
 * 0x80072fb4  90c30001  lbu $v1,1($a2)
 * 0x80072fb8  94a20000  lhu $v0,0($a1)
 * 0x80072fbc  0062102b  sltu $v0,$v1,$v0
 * 0x80072fc0  10400010  beq $v0,$zero,+16
 * 0x80072fc4  00000000  sll $zero,$zero,0
 * 0x80072fc8  00031040  sll $v0,$v1,1
 * 0x80072fcc  00431021  addu $v0,$v0,$v1
 * 0x80072fd0  00021080  sll $v0,$v0,2
 * 0x80072fd4  00a21021  addu $v0,$a1,$v0
 * 0x80072fd8  2445000c  addiu $a1,$v0,0x000c
 * 0x80072fdc  90c30002  lbu $v1,2($a2)
 * 0x80072fe0  24020001  addiu $v0,$zero,0x0001
 * 0x80072fe4  14620004  bne $v1,$v0,+4
 * 0x80072fe8  00000000  sll $zero,$zero,0
 * 0x80072fec  94a20000  lhu $v0,0($a1)
 * 0x80072ff0  0801cc00  j 0x80073000
 * 0x80072ff4  3042ff7f  andi $v0,$v0,0xff7f
 * 0x80072ff8  94a20000  lhu $v0,0($a1)
 * 0x80072ffc  34420080  ori $v0,$v0,0x0080
 * 0x80073000  a4a20000  sh $v0,0($a1)
 * 0x80073004  8c82001c  lw $v0,28($a0)
 * 0x80073008  24420003  addiu $v0,$v0,0x0003
 * 0x8007300c  ac82001c  sw $v0,28($a0)
 * 0x80073010  03e00008  jr $ra
 * 0x80073014  24020001  addiu $v0,$zero,0x0001
 */
