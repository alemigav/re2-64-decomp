/* FUN_8006a880
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a880  body 0x8006a880..0x8006a8a3  size 36 B
 * body sha256 f63e8d08af8b44f5cd243bb5bddb13a1cabfdd2cf94ea3cdde80e4e7fbf11f03
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006a880..0x8006a8f3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006a880  24020001  addiu $v0,$zero,0x0001
 * 0x8006a884  10820011  beq $a0,$v0,+17
 * 0x8006a888  28820002  op&0x0a $v0,$a0,0x0002
 * 0x8006a88c  50400005  op&0x14 $zero,$v0,0x0005
 * 0x8006a890  24020002  addiu $v0,$zero,0x0002
 * 0x8006a894  10800009  beq $a0,$zero,+9
 * 0x8006a898  00000000  sll $zero,$zero,0
 * 0x8006a89c  03e00008  jr $ra
 * 0x8006a8a0  00000000  sll $zero,$zero,0
 */
