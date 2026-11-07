/* FUN_80047fe4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047fe4  body 0x80047fe4..0x8004805f  size 124 B
 * body sha256 26761e60fd0d5242cdcdbfcb9610675397d8a2102a4dcb962d057b618dae6e70
 * EXTENT MEASURED, NOT RECONSTRUCTED: 31 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80047fe4  44800000  op&0x11 $zero,$a0,0x0000
 * 0x80047fe8  27bdfff8  addiu $sp,$sp,0xfff8
 * 0x80047fec  4600603e  op&0x11 $zero,$s0,0x603e
 * 0x80047ff0  00000000  sll $zero,$zero,0
 * 0x80047ff4  45010018  op&0x11 $at,$t0,0x0018
 * 0x80047ff8  e7ac0008  op&0x39 $t4,$sp,0x0008
 * 0x80047ffc  3c023f80  lui $v0,0x3f80
 * 0x80048000  8fa40008  lw $a0,8($sp)
 * 0x80048004  3c037f80  lui $v1,0x7f80
 * 0x80048008  00821021  addu $v0,$a0,$v0
 * 0x8004800c  00021043  sra $v0,$v0,1
 * 0x80048010  00432824  and $a1,$v0,$v1
 * 0x80048014  3c020080  lui $v0,0x0080
 * 0x80048018  00821024  and $v0,$a0,$v0
 * 0x8004801c  10400004  beq $v0,$zero,+4
 * 0x80048020  afa40000  sw $a0,0($sp)
 * 0x80048024  3c02800f  lui $v0,0x800f
 * 0x80048028  0801200e  j 0x80048038
 * 0x8004802c  24420000  addiu $v0,$v0,0x0000
 * 0x80048030  3c02800f  lui $v0,0x800f
 * 0x80048034  24420100  addiu $v0,$v0,0x0100
 * 0x80048038  00041bc3  sra $v1,$a0,15
 * 0x8004803c  306300ff  andi $v1,$v1,0x00ff
 * 0x80048040  00621821  addu $v1,$v1,$v0
 * 0x80048044  90620000  lbu $v0,0($v1)
 * 0x80048048  000213c0  sll $v0,$v0,15
 * 0x8004804c  00a21025  or $v0,$a1,$v0
 * 0x80048050  afa20000  sw $v0,0($sp)
 * 0x80048054  c7a00000  op&0x31 $zero,$sp,0x0000
 * 0x80048058  03e00008  jr $ra
 * 0x8004805c  27bd0008  addiu $sp,$sp,0x0008
 */
