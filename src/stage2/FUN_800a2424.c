/* FUN_800a2424
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2424  body 0x800a2424..0x800a243b  size 24 B
 * body sha256 3253fe7fe9ac2848d38bd01231b8568b463ac8c9ac1a94d349408f52b3cfc0f5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800a2424..0x800a2443, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800a2424  8c840000  lw $a0,0($a0)
 * 0x800a2428  2402ffff  addiu $v0,$zero,0xffff
 * 0x800a242c  14820003  bne $a0,$v0,+3
 * 0x800a2430  000417c2  srl $v0,$a0,31
 * 0x800a2434  03e00008  jr $ra
 * 0x800a2438  24020001  addiu $v0,$zero,0x0001
 */
