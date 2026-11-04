/* FUN_80036ea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036ea0  body 0x80036ea0..0x80036eb3  size 20 B
 * body sha256 a1482d9de00634562f90b84162eb3e7f2dae4a3c7e83a775945462b4830e264a
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
 * 0x80036ea0  0085282b  sltu $a1,$a0,$a1
 * 0x80036ea4  10a00003  beq $a1,$zero,+3
 * 0x80036ea8  0086102b  sltu $v0,$a0,$a2
 * 0x80036eac  03e00008  jr $ra
 * 0x80036eb0  00001021  addu $v0,$zero,$zero
 */
