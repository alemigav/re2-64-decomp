/* FUN_8007272c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007272c  body 0x8007272c..0x8007273f  size 20 B
 * body sha256 fd79779486355a1b6b5be21e88e593026042410a64d6e70f8e7a2a0a0d26c9be
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8007272c..0x8007277b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8007272c  8c82001c  lw $v0,28($a0)
 * 0x80072730  24420004  addiu $v0,$v0,0x0004
 * 0x80072734  ac82001c  sw $v0,28($a0)
 * 0x80072738  03e00008  jr $ra
 * 0x8007273c  24020001  addiu $v0,$zero,0x0001
 */
