/* FUN_80164cc4
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164cc4  body 0x80164cc4..0x80164d7f  size 188 B
 * body sha256 484a34ed751a6503d99aa346aae21b83a29704bca0964102d5e227b4c406aa35
 * EXTENT MEASURED, NOT RECONSTRUCTED: 47 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80164cc4  808202cb  lb $v0,715($a0)
 * 0x80164cc8  1440001c  bne $v0,$zero,+28
 * 0x80164ccc  24020010  addiu $v0,$zero,0x0010
 * 0x80164cd0  00003021  addu $a2,$zero,$zero
 * 0x80164cd4  8c820234  lw $v0,564($a0)
 * 0x80164cd8  2409fbff  addiu $t1,$zero,0xfbff
 * 0x80164cdc  24470468  addiu $a3,$v0,0x0468
 * 0x80164ce0  244504c8  addiu $a1,$v0,0x04c8
 * 0x80164ce4  24431378  addiu $v1,$v0,0x1378
 * 0x80164ce8  8ce20000  lw $v0,0($a3)
 * 0x80164cec  00491024  and $v0,$v0,$t1
 * 0x80164cf0  ace20000  sw $v0,0($a3)
 * 0x80164cf4  8c620054  lw $v0,84($v1)
 * 0x80164cf8  aca20054  sw $v0,84($a1)
 * 0x80164cfc  8c62005c  lw $v0,92($v1)
 * 0x80164d00  aca2005c  sw $v0,92($a1)
 * 0x80164d04  8c620058  lw $v0,88($v1)
 * 0x80164d08  24c60001  addiu $a2,$a2,0x0001
 * 0x80164d0c  aca20058  sw $v0,88($a1)
 * 0x80164d10  8c620060  lw $v0,96($v1)
 * 0x80164d14  24e70178  addiu $a3,$a3,0x0178
 * 0x80164d18  aca20060  sw $v0,96($a1)
 * 0x80164d1c  8c620000  lw $v0,0($v1)
 * 0x80164d20  24630178  addiu $v1,$v1,0x0178
 * 0x80164d24  aca20000  sw $v0,0($a1)
 * 0x80164d28  2cc20004  op&0x0b $v0,$a2,0x0004
 * 0x80164d2c  1440ffee  bne $v0,$zero,-18
 * 0x80164d30  24a50178  addiu $a1,$a1,0x0178
 * 0x80164d34  08059350  j 0x80164d40
 * 0x80164d38  a08002bd  sb $zero,701($a0)
 * 0x80164d3c  a08202cc  sb $v0,716($a0)
 * 0x80164d40  908202bd  lbu $v0,701($a0)
 * 0x80164d44  3c030101  lui $v1,0x0101
 * 0x80164d48  ac830004  sw $v1,4($a0)
 * 0x80164d4c  3042007f  andi $v0,$v0,0x007f
 * 0x80164d50  a08202bd  sb $v0,701($a0)
 * 0x80164d54  9082026f  lbu $v0,623($a0)
 * 0x80164d58  90830005  lbu $v1,5($a0)
 * 0x80164d5c  3042007f  andi $v0,$v0,0x007f
 * 0x80164d60  a082026f  sb $v0,623($a0)
 * 0x80164d64  a103000c  sb $v1,12($t0)
 * 0x80164d68  90820006  lbu $v0,6($a0)
 * 0x80164d6c  a102000d  sb $v0,13($t0)
 * 0x80164d70  90820007  lbu $v0,7($a0)
 * 0x80164d74  a102000e  sb $v0,14($t0)
 * 0x80164d78  03e00008  jr $ra
 * 0x80164d7c  00000000  sll $zero,$zero,0
 */
