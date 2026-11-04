/* FUN_80049fa0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049fa0  body 0x80049fa0..0x80049ff7  size 88 B
 * body sha256 f6e8d515d5143a45ac1efc4f9fd9fc01432eb98725f3d39fc14a7eb91686c19f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 22 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80049fa0  8c870004  lw $a3,4($a0)
 * 0x80049fa4  24850008  addiu $a1,$a0,0x0008
 * 0x80049fa8  00a03021  addu $a2,$a1,$zero
 * 0x80049fac  24840020  addiu $a0,$a0,0x0020
 * 0x80049fb0  8ca20000  lw $v0,0($a1)
 * 0x80049fb4  24e7ffff  addiu $a3,$a3,0xffff
 * 0x80049fb8  00461021  addu $v0,$v0,$a2
 * 0x80049fbc  aca20000  sw $v0,0($a1)
 * 0x80049fc0  24a5001c  addiu $a1,$a1,0x001c
 * 0x80049fc4  8c82fff0  lw $v0,-16($a0)
 * 0x80049fc8  8c830000  lw $v1,0($a0)
 * 0x80049fcc  00461021  addu $v0,$v0,$a2
 * 0x80049fd0  ac82fff0  sw $v0,-16($a0)
 * 0x80049fd4  8c82fff8  lw $v0,-8($a0)
 * 0x80049fd8  00661821  addu $v1,$v1,$a2
 * 0x80049fdc  ac830000  sw $v1,0($a0)
 * 0x80049fe0  00461021  addu $v0,$v0,$a2
 * 0x80049fe4  ac82fff8  sw $v0,-8($a0)
 * 0x80049fe8  14e0fff1  bne $a3,$zero,-15
 * 0x80049fec  2484001c  addiu $a0,$a0,0x001c
 * 0x80049ff0  03e00008  jr $ra
 * 0x80049ff4  00000000  sll $zero,$zero,0
 */
