/* FUN_80164bf8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164bf8  body 0x80164bf8..0x80164cc3  size 204 B
 * body sha256 1918a4565ca73b283abe7c16551ae2a1453b21b4a177f0b5b5f560568f15b04d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 51 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80164bf8  8482025e  lh $v0,606($a0)
 * 0x80164bfc  a0850007  sb $a1,7($a0)
 * 0x80164c00  ac8001e8  sw $zero,488($a0)
 * 0x80164c04  ac82002c  sw $v0,44($a0)
 * 0x80164c08  91020009  lbu $v0,9($t0)
 * 0x80164c0c  81030017  lb $v1,23($t0)
 * 0x80164c10  a1050006  sb $a1,6($t0)
 * 0x80164c14  a1000007  sb $zero,7($t0)
 * 0x80164c18  34420080  ori $v0,$v0,0x0080
 * 0x80164c1c  14600012  bne $v1,$zero,+18
 * 0x80164c20  a1020009  sb $v0,9($t0)
 * 0x80164c24  24060003  addiu $a2,$zero,0x0003
 * 0x80164c28  24070fff  addiu $a3,$zero,0x0fff
 * 0x80164c2c  24030468  addiu $v1,$zero,0x0468
 * 0x80164c30  8c820234  lw $v0,564($a0)
 * 0x80164c34  24c60001  addiu $a2,$a2,0x0001
 * 0x80164c38  00432821  addu $a1,$v0,$v1
 * 0x80164c3c  8ca20000  lw $v0,0($a1)
 * 0x80164c40  a4a70128  sh $a3,296($a1)
 * 0x80164c44  a4a70126  sh $a3,294($a1)
 * 0x80164c48  a4a70124  sh $a3,292($a1)
 * 0x80164c4c  34420400  ori $v0,$v0,0x0400
 * 0x80164c50  aca20000  sw $v0,0($a1)
 * 0x80164c54  2cc20007  op&0x0b $v0,$a2,0x0007
 * 0x80164c58  1440fff5  bne $v0,$zero,-11
 * 0x80164c5c  24630178  addiu $v1,$v1,0x0178
 * 0x80164c60  24020020  addiu $v0,$zero,0x0020
 * 0x80164c64  a1020018  sb $v0,24($t0)
 * 0x80164c68  24060003  addiu $a2,$zero,0x0003
 * 0x80164c6c  24070468  addiu $a3,$zero,0x0468
 * 0x80164c70  8c820234  lw $v0,564($a0)
 * 0x80164c74  24c60001  addiu $a2,$a2,0x0001
 * 0x80164c78  00472821  addu $a1,$v0,$a3
 * 0x80164c7c  94a20124  lhu $v0,292($a1)
 * 0x80164c80  94a30128  lhu $v1,296($a1)
 * 0x80164c84  2442ff80  addiu $v0,$v0,0xff80
 * 0x80164c88  a4a20124  sh $v0,292($a1)
 * 0x80164c8c  94a20126  lhu $v0,294($a1)
 * 0x80164c90  2463ff80  addiu $v1,$v1,0xff80
 * 0x80164c94  a4a30128  sh $v1,296($a1)
 * 0x80164c98  2442ff80  addiu $v0,$v0,0xff80
 * 0x80164c9c  a4a20126  sh $v0,294($a1)
 * 0x80164ca0  2cc20007  op&0x0b $v0,$a2,0x0007
 * 0x80164ca4  1440fff2  bne $v0,$zero,-14
 * 0x80164ca8  24e70178  addiu $a3,$a3,0x0178
 * 0x80164cac  84a20124  lh $v0,292($a1)
 * 0x80164cb0  28420401  op&0x0a $v0,$v0,0x0401
 * 0x80164cb4  1040ffca  beq $v0,$zero,-54
 * 0x80164cb8  24020002  addiu $v0,$zero,0x0002
 * 0x80164cbc  03e00008  jr $ra
 * 0x80164cc0  a0820007  sb $v0,7($a0)
 */
