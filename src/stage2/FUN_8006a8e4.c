/* FUN_8006a8e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a8e4  body 0x8006a8e4..0x8006a8f3  size 16 B
 * body sha256 96c0d3f9184441f16b9f6359f3b551abdb7549bf55118705e9c8d9bb95bada6a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006a880..0x8006a8f3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006a8e4  84a30002  lh $v1,2($a1)
 * 0x8006a8e8  94a20006  lhu $v0,6($a1)
 * 0x8006a8ec  03e00008  jr $ra
 * 0x8006a8f0  00621021  addu $v0,$v1,$v0
 */
