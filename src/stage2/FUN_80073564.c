/* FUN_80073564
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073564  body 0x80073564..0x8007358f  size 44 B
 * body sha256 529274d3225029332db0bfee006609b05d9944013fb145e5577dcb0e8789879b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80073564..0x8007358f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80073564  3c030001  lui $v1,0x0001
 * 0x80073568  8c82001c  lw $v0,28($a0)
 * 0x8007356c  34638000  ori $v1,$v1,0x8000
 * 0x80073570  24420001  addiu $v0,$v0,0x0001
 * 0x80073574  ac82001c  sw $v0,28($a0)
 * 0x80073578  3c02800c  lui $v0,0x800c
 * 0x8007357c  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073580  00431021  addu $v0,$v0,$v1
 * 0x80073584  94421d34  lhu $v0,7476($v0)
 * 0x80073588  03e00008  jr $ra
 * 0x8007358c  0002102b  sltu $v0,$zero,$v0
 */
