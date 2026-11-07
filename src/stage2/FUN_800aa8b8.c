/* FUN_800aa8b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800aa8b8  body 0x800aa8b8..0x800aa8cf  size 24 B
 * body sha256 254dc211ca6972c59da2f773827930ae996914faf62b2e52915551a9af91ea05
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800aa8b8..0x800aa8db, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800aa8b8  3c028013  lui $v0,0x8013
 * 0x800aa8bc  90426310  lbu $v0,25360($v0)
 * 0x800aa8c0  14400003  bne $v0,$zero,+3
 * 0x800aa8c4  00000000  sll $zero,$zero,0
 * 0x800aa8c8  03e00008  jr $ra
 * 0x800aa8cc  00001021  addu $v0,$zero,$zero
 */
