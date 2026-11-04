/* FUN_8006dd7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dd7c  body 0x8006dd7c..0x8006dda3  size 40 B
 * body sha256 84d30864f2e619abb46a471bb559548b67dcd2f10406d29ae893fc1c72c6dfe4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006dd7c  80830002  lb $v1,2($a0)
 * 0x8006dd80  00831821  addu $v1,$a0,$v1
 * 0x8006dd84  90620008  lbu $v0,8($v1)
 * 0x8006dd88  24420001  addiu $v0,$v0,0x0001
 * 0x8006dd8c  a0620008  sb $v0,8($v1)
 * 0x8006dd90  8c82001c  lw $v0,28($a0)
 * 0x8006dd94  24420001  addiu $v0,$v0,0x0001
 * 0x8006dd98  ac82001c  sw $v0,28($a0)
 * 0x8006dd9c  03e00008  jr $ra
 * 0x8006dda0  24020001  addiu $v0,$zero,0x0001
 */
