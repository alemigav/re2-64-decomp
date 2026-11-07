/* FUN_80004c14
 * image   boot (boot), base 0x80000480
 * address 0x80004c14  body 0x80004c14..0x80004c23  size 16 B
 * body sha256 ab5775bb239ff558b12d4cc6a976d3b70503002fbc5965d821981788d960944a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80004be4..0x80004c33, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80004c14  3c038001  lui $v1,0x8001
 * 0x80004c18  24020002  addiu $v0,$zero,0x0002
 * 0x80004c1c  03e00008  jr $ra
 * 0x80004c20  ac622884  sw $v0,10372($v1)
 */
