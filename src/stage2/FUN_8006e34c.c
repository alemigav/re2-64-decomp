/* FUN_8006e34c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e34c  body 0x8006e34c..0x8006e35f  size 20 B
 * body sha256 6a75dbb877282530e5282dcb5791f6a3f74de1eb7f8bbba9817295bee3d88ab4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e34c  8c82001c  lw $v0,28($a0)
 * 0x8006e350  24420002  addiu $v0,$v0,0x0002
 * 0x8006e354  ac82001c  sw $v0,28($a0)
 * 0x8006e358  03e00008  jr $ra
 * 0x8006e35c  24020001  addiu $v0,$zero,0x0001
 */
