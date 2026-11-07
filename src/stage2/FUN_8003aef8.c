/* FUN_8003aef8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003aef8  body 0x8003aef8..0x8003af0f  size 24 B
 * body sha256 36a18913e4e9cd70219df45cbdbf9222b1f606921aa6e2ff1b6a3a1846be610f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003aef8..0x8003af0f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003aef8  3c02800f  lui $v0,0x800f
 * 0x8003aefc  8c43bb94  lw $v1,-17516($v0)
 * 0x8003af00  94620004  lhu $v0,4($v1)
 * 0x8003af04  24420100  addiu $v0,$v0,0x0100
 * 0x8003af08  03e00008  jr $ra
 * 0x8003af0c  a4620004  sh $v0,4($v1)
 */
