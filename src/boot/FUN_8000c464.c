/* FUN_8000c464
 * image   boot (boot), base 0x80000480
 * address 0x8000c464  body 0x8000c464..0x8000c487  size 36 B
 * body sha256 dea51e33f5530cfb230a30120e966027a4f7b2aaaa3443b1244fab08c93cef1f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8000c464..0x8000c48f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8000c464  8fbf0040  lw $ra,64($sp)
 * 0x8000c468  8fb5003c  lw $s5,60($sp)
 * 0x8000c46c  8fb40038  lw $s4,56($sp)
 * 0x8000c470  8fb30034  lw $s3,52($sp)
 * 0x8000c474  8fb20030  lw $s2,48($sp)
 * 0x8000c478  8fb1002c  lw $s1,44($sp)
 * 0x8000c47c  8fb00028  lw $s0,40($sp)
 * 0x8000c480  03e00008  jr $ra
 * 0x8000c484  27bd0048  addiu $sp,$sp,0x0048
 */
