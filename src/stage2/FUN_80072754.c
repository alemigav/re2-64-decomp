/* FUN_80072754
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072754  body 0x80072754..0x80072767  size 20 B
 * body sha256 7be3ce1aea121e7dc8843f6e1669f09ff9baef824c735736be7ec3cd1a63eec2
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
 * 0x80072754  8c82001c  lw $v0,28($a0)
 * 0x80072758  24420001  addiu $v0,$v0,0x0001
 * 0x8007275c  ac82001c  sw $v0,28($a0)
 * 0x80072760  03e00008  jr $ra
 * 0x80072764  24020001  addiu $v0,$zero,0x0001
 */
