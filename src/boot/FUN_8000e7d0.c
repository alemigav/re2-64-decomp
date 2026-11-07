/* FUN_8000e7d0
 * image   boot (boot), base 0x80000480
 * address 0x8000e7d0  body 0x8000e7d0..0x8000e7ef  size 32 B
 * body sha256 7ed0cef5dd3fb1b63fc6e01aa96c32fb89828421b8ba692632b4db9da3a215d8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8000e7d0..0x8000e7ef, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8000e7d0  8fbf002c  lw $ra,44($sp)
 * 0x8000e7d4  8fb40028  lw $s4,40($sp)
 * 0x8000e7d8  8fb30024  lw $s3,36($sp)
 * 0x8000e7dc  8fb20020  lw $s2,32($sp)
 * 0x8000e7e0  8fb1001c  lw $s1,28($sp)
 * 0x8000e7e4  8fb00018  lw $s0,24($sp)
 * 0x8000e7e8  03e00008  jr $ra
 * 0x8000e7ec  27bd0030  addiu $sp,$sp,0x0030
 */
