/* FUN_80163714
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163714  body 0x80163714..0x80163723  size 16 B
 * body sha256 6b767e3d5e5682be6b67fe8b2b088818c00147e260f78c0b35518378db924f43
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8016370c..0x80163723, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80163714  948201aa  lhu $v0,426($a0)
 * 0x80163718  34424400  ori $v0,$v0,0x4400
 * 0x8016371c  03e00008  jr $ra
 * 0x80163720  a48201aa  sh $v0,426($a0)
 */
