/* FUN_800b1bec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1bec  body 0x800b1bec..0x800b1c3f  size 84 B
 * body sha256 ec941a64f0d29ce214f34dd13d087eb3fd5c955388dd563de15822a9c9b31f8f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 21 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800b1bec  00802821  addu $a1,$a0,$zero
 * 0x800b1bf0  8ca30060  lw $v1,96($a1)
 * 0x800b1bf4  2402ffff  addiu $v0,$zero,0xffff
 * 0x800b1bf8  1062001a  beq $v1,$v0,+26
 * 0x800b1bfc  240300ff  addiu $v1,$zero,0x00ff
 * 0x800b1c00  90a2004a  lbu $v0,74($a1)
 * 0x800b1c04  10430018  beq $v0,$v1,+24
 * 0x800b1c08  00001021  addu $v0,$zero,$zero
 * 0x800b1c0c  90a2004b  lbu $v0,75($a1)
 * 0x800b1c10  90a60063  lbu $a2,99($a1)
 * 0x800b1c14  5443000a  op&0x15 $v1,$v0,0x000a
 * 0x800b1c18  3c048016  lui $a0,0x8016
 * 0x800b1c1c  3c028016  lui $v0,0x8016
 * 0x800b1c20  24428a80  addiu $v0,$v0,0x8a80
 * 0x800b1c24  30c300ff  andi $v1,$a2,0x00ff
 * 0x800b1c28  00621021  addu $v0,$v1,$v0
 * 0x800b1c2c  90420000  lbu $v0,0($v0)
 * 0x800b1c30  1443000d  bne $v0,$v1,+13
 * 0x800b1c34  00001021  addu $v0,$zero,$zero
 * 0x800b1c38  03e00008  jr $ra
 * 0x800b1c3c  24020001  addiu $v0,$zero,0x0001
 */
