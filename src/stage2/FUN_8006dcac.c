/* FUN_8006dcac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dcac  body 0x8006dcac..0x8006dcdf  size 52 B
 * body sha256 3874be5e73ca16f4d9e4c0013bbb523af752dd58c2f5b7268d397a2fda8e5e89
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
 * 0x8006dcac  8c820140  lw $v0,320($a0)
 * 0x8006dcb0  2442fffc  addiu $v0,$v0,0xfffc
 * 0x8006dcb4  ac820140  sw $v0,320($a0)
 * 0x8006dcb8  8c82001c  lw $v0,28($a0)
 * 0x8006dcbc  80830002  lb $v1,2($a0)
 * 0x8006dcc0  24420002  addiu $v0,$v0,0x0002
 * 0x8006dcc4  ac82001c  sw $v0,28($a0)
 * 0x8006dcc8  00832021  addu $a0,$a0,$v1
 * 0x8006dccc  90820004  lbu $v0,4($a0)
 * 0x8006dcd0  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006dcd4  a0820004  sb $v0,4($a0)
 * 0x8006dcd8  03e00008  jr $ra
 * 0x8006dcdc  24020001  addiu $v0,$zero,0x0001
 */
