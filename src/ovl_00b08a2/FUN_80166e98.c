/* FUN_80166e98
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166e98  body 0x80166e98..0x80166ecb  size 52 B
 * body sha256 f6c667bbd66310d8227dc7bb68804ff58c818cc1d1f31a15b760af94eb4dfbe7
 * EXTENT MEASURED, NOT RECONSTRUCTED: 13 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80166e98  00802821  addu $a1,$a0,$zero
 * 0x80166e9c  90a302bf  lbu $v1,703($a1)
 * 0x80166ea0  24020001  addiu $v0,$zero,0x0001
 * 0x80166ea4  10620009  beq $v1,$v0,+9
 * 0x80166ea8  28620002  op&0x0a $v0,$v1,0x0002
 * 0x80166eac  14400005  bne $v0,$zero,+5
 * 0x80166eb0  24020002  addiu $v0,$zero,0x0002
 * 0x80166eb4  1062000f  beq $v1,$v0,+15
 * 0x80166eb8  24020003  addiu $v0,$zero,0x0003
 * 0x80166ebc  10620016  beq $v1,$v0,+22
 * 0x80166ec0  2404ffbf  addiu $a0,$zero,0xffbf
 * 0x80166ec4  03e00008  jr $ra
 * 0x80166ec8  00000000  sll $zero,$zero,0
 */
