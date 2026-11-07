/* FUN_80011458
 * image   boot (boot), base 0x80000480
 * address 0x80011458  body 0x80011458..0x80011507  size 176 B
 * body sha256 6f8db2f0c1329853822f09967367cda63f7962d076c7f3d38182831bcd5156fe
 * EXTENT MEASURED, NOT RECONSTRUCTED: 44 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80011458  4600008d  op&0x11 $zero,$s0,0x008d
 * 0x8001145c  44061000  op&0x11 $a2,$zero,0x1000
 * 0x80011460  3c028000  lui $v0,0x8000
 * 0x80011464  00c23025  or $a2,$a2,$v0
 * 0x80011468  2cc20084  op&0x0b $v0,$a2,0x0084
 * 0x8001146c  14400024  bne $v0,$zero,+36
 * 0x80011470  2402ffff  addiu $v0,$zero,0xffff
 * 0x80011474  3c023e0f  lui $v0,0x3e0f
 * 0x80011478  344283e1  ori $v0,$v0,0x83e1
 * 0x8001147c  00c20019  multu $a2,$v0
 * 0x80011480  00004010  mfhi $t0
 * 0x80011484  00083902  srl $a3,$t0,4
 * 0x80011488  30e200ff  andi $v0,$a3,0x00ff
 * 0x8001148c  2c420011  op&0x0b $v0,$v0,0x0011
 * 0x80011490  50400001  op&0x14 $zero,$v0,0x0001
 * 0x80011494  24070010  addiu $a3,$zero,0x0010
 * 0x80011498  3c03a450  lui $v1,0xa450
 * 0x8001149c  34630010  ori $v1,$v1,0x0010
 * 0x800114a0  3c04a450  lui $a0,0xa450
 * 0x800114a4  34840014  ori $a0,$a0,0x0014
 * 0x800114a8  3c05a450  lui $a1,0xa450
 * 0x800114ac  34a50008  ori $a1,$a1,0x0008
 * 0x800114b0  24c2ffff  addiu $v0,$a2,0xffff
 * 0x800114b4  ac620000  sw $v0,0($v1)
 * 0x800114b8  3c028001  lui $v0,0x8001
 * 0x800114bc  8c4228c8  lw $v0,10440($v0)
 * 0x800114c0  30e300ff  andi $v1,$a3,0x00ff
 * 0x800114c4  2463ffff  addiu $v1,$v1,0xffff
 * 0x800114c8  ac830000  sw $v1,0($a0)
 * 0x800114cc  24030001  addiu $v1,$zero,0x0001
 * 0x800114d0  aca30000  sw $v1,0($a1)
 * 0x800114d4  0046001a  div $v0,$a2
 * 0x800114d8  14c00002  bne $a2,$zero,+2
 * 0x800114dc  00000000  sll $zero,$zero,0
 * 0x800114e0  0007000d  special&0x0d $zero,$zero,$a3
 * 0x800114e4  2401ffff  addiu $at,$zero,0xffff
 * 0x800114e8  14c10004  bne $a2,$at,+4
 * 0x800114ec  3c018000  lui $at,0x8000
 * 0x800114f0  14410002  bne $v0,$at,+2
 * 0x800114f4  00000000  sll $zero,$zero,0
 * 0x800114f8  0006000d  special&0x0d $zero,$zero,$a2
 * 0x800114fc  00001012  mflo $v0
 * 0x80011500  03e00008  jr $ra
 * 0x80011504  00000000  sll $zero,$zero,0
 */
