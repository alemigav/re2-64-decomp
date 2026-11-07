/* FUN_800ab7b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab7b8  body 0x800ab7b8..0x800ab7cf  size 24 B
 * body sha256 9c23ebaf2792df784fff5f45152e76b842961ac413e8315b0bd136e04dacb607
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800ab7a8..0x800ab7df, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800ab7b8  3c028013  lui $v0,0x8013
 * 0x800ab7bc  90426310  lbu $v0,25360($v0)
 * 0x800ab7c0  14400003  bne $v0,$zero,+3
 * 0x800ab7c4  3c028014  lui $v0,0x8014
 * 0x800ab7c8  03e00008  jr $ra
 * 0x800ab7cc  00001021  addu $v0,$zero,$zero
 */
