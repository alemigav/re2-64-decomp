/* FUN_800ab7a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab7a8  body 0x800ab7a8..0x800ab7b7  size 16 B
 * body sha256 887bdd92d1e604c19147959de8d2acfc954b4fff3370322ac2face6441776edb
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800ab7a8..0x800ab7df, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800ab7a8  3c028013  lui $v0,0x8013
 * 0x800ab7ac  90426310  lbu $v0,25360($v0)
 * 0x800ab7b0  03e00008  jr $ra
 * 0x800ab7b4  00000000  sll $zero,$zero,0
 */
