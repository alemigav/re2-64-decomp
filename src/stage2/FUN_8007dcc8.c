/* FUN_8007dcc8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dcc8  body 0x8007dcc8..0x8007dcd7  size 16 B
 * body sha256 75cf3592232e83d6229d8076349b3c7f829bd42c382d7a5d24265d77ff30ecae
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007dcc8  a4820006  sh $v0,6($a0)
 * 0x8007dccc  2402000d  addiu $v0,$zero,0x000d
 * 0x8007dcd0  03e00008  jr $ra
 * 0x8007dcd4  a0820207  sb $v0,519($a0)
 */
