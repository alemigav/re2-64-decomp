/* FUN_8006e4d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e4d4  body 0x8006e4d4..0x8006e533  size 96 B
 * body sha256 eee3b468e7e389fa4618771592ca94bdbe916e0e12fd03f5f7a6ed4ef6a5218b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 24 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8006e4d4  8c85001c  lw $a1,28($a0)
 * 0x8006e4d8  90a60001  lbu $a2,1($a1)
 * 0x8006e4dc  90a70002  lbu $a3,2($a1)
 * 0x8006e4e0  90a20003  lbu $v0,3($a1)
 * 0x8006e4e4  24a50004  addiu $a1,$a1,0x0004
 * 0x8006e4e8  10400009  beq $v0,$zero,+9
 * 0x8006e4ec  ac85001c  sw $a1,28($a0)
 * 0x8006e4f0  3c03800f  lui $v1,0x800f
 * 0x8006e4f4  24638c78  addiu $v1,$v1,0x8c78
 * 0x8006e4f8  00061040  sll $v0,$a2,1
 * 0x8006e4fc  00431021  addu $v0,$v0,$v1
 * 0x8006e500  94430000  lhu $v1,0($v0)
 * 0x8006e504  00a71021  addu $v0,$a1,$a3
 * 0x8006e508  0801b94b  j 0x8006e52c
 * 0x8006e50c  a4430000  sh $v1,0($v0)
 * 0x8006e510  3c03800f  lui $v1,0x800f
 * 0x8006e514  24638c78  addiu $v1,$v1,0x8c78
 * 0x8006e518  00061040  sll $v0,$a2,1
 * 0x8006e51c  00431021  addu $v0,$v0,$v1
 * 0x8006e520  90430001  lbu $v1,1($v0)
 * 0x8006e524  00a71021  addu $v0,$a1,$a3
 * 0x8006e528  a0430000  sb $v1,0($v0)
 * 0x8006e52c  03e00008  jr $ra
 * 0x8006e530  24020001  addiu $v0,$zero,0x0001
 */
