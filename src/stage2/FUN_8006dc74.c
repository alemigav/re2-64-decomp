/* FUN_8006dc74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dc74  body 0x8006dc74..0x8006dcab  size 56 B
 * body sha256 f811da11663098d0d8a9aa9bac0f1361724bc4e1738c9d8af4ab82ba2a16463c
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006dc74  8c820140  lw $v0,320($a0)
 * 0x8006dc78  8c83001c  lw $v1,28($a0)
 * 0x8006dc7c  2442fffc  addiu $v0,$v0,0xfffc
 * 0x8006dc80  ac820140  sw $v0,320($a0)
 * 0x8006dc84  94620002  lhu $v0,2($v1)
 * 0x8006dc88  80850002  lb $a1,2($a0)
 * 0x8006dc8c  00621821  addu $v1,$v1,$v0
 * 0x8006dc90  ac83001c  sw $v1,28($a0)
 * 0x8006dc94  00852021  addu $a0,$a0,$a1
 * 0x8006dc98  90820004  lbu $v0,4($a0)
 * 0x8006dc9c  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006dca0  a0820004  sb $v0,4($a0)
 * 0x8006dca4  03e00008  jr $ra
 * 0x8006dca8  24020001  addiu $v0,$zero,0x0001
 */
