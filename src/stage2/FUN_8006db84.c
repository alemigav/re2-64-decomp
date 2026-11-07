/* FUN_8006db84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db84  body 0x8006db84..0x8006db97  size 20 B
 * body sha256 29f1f702fc7263419c6652f9f86b730a6cd6b4591f64457b0a7b7f5395f09fd1
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006db00..0x8006db97, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006db84  8c82001c  lw $v0,28($a0)
 * 0x8006db88  24420001  addiu $v0,$v0,0x0001
 * 0x8006db8c  ac82001c  sw $v0,28($a0)
 * 0x8006db90  03e00008  jr $ra
 * 0x8006db94  24020002  addiu $v0,$zero,0x0002
 */
