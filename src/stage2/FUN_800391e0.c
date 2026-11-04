/* FUN_800391e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800391e0  body 0x800391e0..0x80039227  size 72 B
 * body sha256 0aac7ef2f924243da3209c292cf0c02f7d6f5b2970370d74facc88ff2616344d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800391e0  308400ff  andi $a0,$a0,0x00ff
 * 0x800391e4  30a500ff  andi $a1,$a1,0x00ff
 * 0x800391e8  3c02800f  lui $v0,0x800f
 * 0x800391ec  2443bda8  addiu $v1,$v0,0xbda8
 * 0x800391f0  9062001c  lbu $v0,28($v1)
 * 0x800391f4  14440006  bne $v0,$a0,+6
 * 0x800391f8  25080001  addiu $t0,$t0,0x0001
 * 0x800391fc  9062001e  lbu $v0,30($v1)
 * 0x80039200  14450003  bne $v0,$a1,+3
 * 0x80039204  00000000  sll $zero,$zero,0
 * 0x80039208  a4660006  sh $a2,6($v1)
 * 0x8003920c  a4670012  sh $a3,18($v1)
 * 0x80039210  2d020060  op&0x0b $v0,$t0,0x0060
 * 0x80039214  1440fff6  bne $v0,$zero,-10
 * 0x80039218  2463007c  addiu $v1,$v1,0x007c
 * 0x8003921c  00001021  addu $v0,$zero,$zero
 * 0x80039220  03e00008  jr $ra
 * 0x80039224  00000000  sll $zero,$zero,0
 */
