/* FUN_8004249c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004249c  body 0x8004249c..0x800424bb  size 32 B
 * body sha256 08538e12761f9cfc6352fe79077971aeb1d33fb62d6724707f56095cdc926eba
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8004249c..0x800424bb, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8004249c  8c890014  lw $t1,20($a0)
 * 0x800424a0  aca90014  sw $t1,20($a1)
 * 0x800424a4  8c890018  lw $t1,24($a0)
 * 0x800424a8  aca90018  sw $t1,24($a1)
 * 0x800424ac  8c89001c  lw $t1,28($a0)
 * 0x800424b0  aca9001c  sw $t1,28($a1)
 * 0x800424b4  03e00008  jr $ra
 * 0x800424b8  00a0102d  special&0x2d $v0,$a1,$zero
 */
