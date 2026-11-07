/* FUN_8000de78
 * image   boot (boot), base 0x80000480
 * address 0x8000de78  body 0x8000de78..0x8000de9b  size 36 B
 * body sha256 756e16bf555c86248d435ff4dce26863933b47c4319926842dfba30c7dc40437
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8000de78..0x8000de9b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8000de78  90820000  lbu $v0,0($a0)
 * 0x8000de7c  10400005  beq $v0,$zero,+5
 * 0x8000de80  00801821  addu $v1,$a0,$zero
 * 0x8000de84  24630001  addiu $v1,$v1,0x0001
 * 0x8000de88  90620000  lbu $v0,0($v1)
 * 0x8000de8c  5440fffe  op&0x15 $zero,$v0,0xfffe
 * 0x8000de90  24630001  addiu $v1,$v1,0x0001
 * 0x8000de94  03e00008  jr $ra
 * 0x8000de98  00641023  subu $v0,$v1,$a0
 */
