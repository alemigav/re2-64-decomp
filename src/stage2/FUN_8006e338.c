/* FUN_8006e338
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e338  body 0x8006e338..0x8006e34b  size 20 B
 * body sha256 33348add88f2ea5838fa5064680d9dfa216534ff20306e17c7c87d4f1b98963f
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
 * 0x8006e338  8c82001c  lw $v0,28($a0)
 * 0x8006e33c  24420006  addiu $v0,$v0,0x0006
 * 0x8006e340  ac82001c  sw $v0,28($a0)
 * 0x8006e344  03e00008  jr $ra
 * 0x8006e348  24020001  addiu $v0,$zero,0x0001
 */
