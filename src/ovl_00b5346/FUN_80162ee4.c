/* FUN_80162ee4
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162ee4  body 0x80162ee4..0x80162f33  size 80 B
 * body sha256 f4bf9a877d2bb54dc0f6a82e1670cc161a33efbc86817cae48f7b45212d269d8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 20 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80162ee4  10800008  beq $a0,$zero,+8
 * 0x80162ee8  3c030001  lui $v1,0x0001
 * 0x80162eec  34638000  ori $v1,$v1,0x8000
 * 0x80162ef0  3c02800c  lui $v0,0x800c
 * 0x80162ef4  244276b0  addiu $v0,$v0,0x76b0
 * 0x80162ef8  00431021  addu $v0,$v0,$v1
 * 0x80162efc  8c441d3c  lw $a0,7484($v0)
 * 0x80162f00  08058bc4  j 0x80162f10
 * 0x80162f04  00000000  sll $zero,$zero,0
 * 0x80162f08  3c02800e  lui $v0,0x800e
 * 0x80162f0c  24441130  addiu $a0,$v0,0x1130
 * 0x80162f10  9083026f  lbu $v1,623($a0)
 * 0x80162f14  24020002  addiu $v0,$zero,0x0002
 * 0x80162f18  a0820004  sb $v0,4($a0)
 * 0x80162f1c  a0850005  sb $a1,5($a0)
 * 0x80162f20  a0800006  sb $zero,6($a0)
 * 0x80162f24  a0800007  sb $zero,7($a0)
 * 0x80162f28  34630080  ori $v1,$v1,0x0080
 * 0x80162f2c  03e00008  jr $ra
 * 0x80162f30  a083026f  sb $v1,623($a0)
 */
