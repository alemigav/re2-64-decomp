/* FUN_800823b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800823b0  body 0x800823b0..0x800823d7  size 40 B
 * body sha256 4c532fe24688cc4cb2df5c33f4080413a990e884cdef1c5d326f08fefc924bd4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800823b0..0x800823df, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800823b0  90a30000  lbu $v1,0($a1)
 * 0x800823b4  10600006  beq $v1,$zero,+6
 * 0x800823b8  00801021  addu $v0,$a0,$zero
 * 0x800823bc  24a50001  addiu $a1,$a1,0x0001
 * 0x800823c0  a0830000  sb $v1,0($a0)
 * 0x800823c4  90a30000  lbu $v1,0($a1)
 * 0x800823c8  1460fffc  bne $v1,$zero,-4
 * 0x800823cc  24840001  addiu $a0,$a0,0x0001
 * 0x800823d0  03e00008  jr $ra
 * 0x800823d4  a0800000  sb $zero,0($a0)
 */
