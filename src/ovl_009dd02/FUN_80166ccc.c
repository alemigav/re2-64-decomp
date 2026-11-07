/* FUN_80166ccc
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166ccc  body 0x80166ccc..0x80166ceb  size 32 B
 * body sha256 ef871bdf270d81bbb2faa33581a66fba96c47bcd50b6c78163c42b435986aa81
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80166ccc..0x80166d13, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80166ccc  248602b4  addiu $a2,$a0,0x02b4
 * 0x80166cd0  90c2000e  lbu $v0,14($a2)
 * 0x80166cd4  00a21007  special&0x07 $v0,$a1,$v0
 * 0x80166cd8  30420001  andi $v0,$v0,0x0001
 * 0x80166cdc  14400003  bne $v0,$zero,+3
 * 0x80166ce0  00001021  addu $v0,$zero,$zero
 * 0x80166ce4  03e00008  jr $ra
 * 0x80166ce8  24020001  addiu $v0,$zero,0x0001
 */
