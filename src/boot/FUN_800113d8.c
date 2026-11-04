/* FUN_800113d8
 * image   boot (boot), base 0x80000480
 * address 0x800113d8  body 0x800113d8..0x80011507  size 304 B
 * body sha256 8a7f688329f7c5b318a7eb17635dd46b9afbdfa1dcc9ed9a90e83e910391c603
 * EXTENT MEASURED, NOT RECONSTRUCTED: 76 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800113d8  00000000  sll $zero,$zero,0
 * 0x800113dc  00000000  sll $zero,$zero,0
 * 0x800113e0  44841000  op&0x11 $a0,$a0,0x1000
 * 0x800113e4  00000000  sll $zero,$zero,0
 * 0x800113e8  468010a1  op&0x11 $zero,$s4,0x10a1
 * 0x800113ec  3c018001  lui $at,0x8001
 * 0x800113f0  c42428c8  op&0x31 $a0,$at,0x28c8
 * 0x800113f4  46802120  op&0x11 $zero,$s4,0x2120
 * 0x800113f8  04830005  op&0x01 $v1,$a0,0x0005
 * 0x800113fc  46201020  op&0x11 $zero,$s1,0x1020
 * 0x80011400  3c018001  lui $at,0x8001
 * 0x80011404  d4202100  op&0x35 $zero,$at,0x2100
 * 0x80011408  46201080  op&0x11 $zero,$s1,0x1080
 * 0x8001140c  46201020  op&0x11 $zero,$s1,0x1020
 * 0x80011410  46002003  op&0x11 $zero,$s0,0x2003
 * 0x80011414  3c013f00  lui $at,0x3f00
 * 0x80011418  44811000  op&0x11 $at,$a0,0x1000
 * 0x8001141c  00000000  sll $zero,$zero,0
 * 0x80011420  46020080  op&0x11 $v0,$s0,0x0080
 * 0x80011424  3c014f00  lui $at,0x4f00
 * 0x80011428  44810000  op&0x11 $at,$a0,0x0000
 * 0x8001142c  00000000  sll $zero,$zero,0
 * 0x80011430  4602003e  op&0x11 $v0,$s0,0x003e
 * 0x80011434  00000000  sll $zero,$zero,0
 * 0x80011438  00000000  sll $zero,$zero,0
 * 0x8001143c  45030006  op&0x11 $v1,$t0,0x0006
 * 0x80011440  46001001  op&0x11 $zero,$s0,0x1001
 * 0x80011444  4600100d  op&0x11 $zero,$s0,0x100d
 * 0x80011448  44060000  op&0x11 $a2,$zero,0x0000
 * 0x8001144c  00000000  sll $zero,$zero,0
 * 0x80011450  0800451b  j 0x8001146c
 * 0x80011454  2cc20084  op&0x0b $v0,$a2,0x0084
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
