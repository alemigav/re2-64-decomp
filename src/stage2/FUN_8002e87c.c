/* FUN_8002e87c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e87c  body 0x8002e87c..0x8002e88f  size 20 B
 * body sha256 9bace9317eea8d6d4e6ed6d0bd42766378a531e5f2612e19efd750a52e30a8c5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8002e86c..0x8002e88f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8002e87c  8c820000  lw $v0,0($a0)
 * 0x8002e880  ac40006c  sw $zero,108($v0)
 * 0x8002e884  8c820000  lw $v0,0($a0)
 * 0x8002e888  03e00008  jr $ra
 * 0x8002e88c  ac400014  sw $zero,20($v0)
 */
