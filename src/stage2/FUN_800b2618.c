/* FUN_800b2618
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2618  body 0x800b2618..0x800b2637  size 32 B
 * body sha256 f8ef9344921012197adcdbd746afa4d58e56ddf3f30ec73311423cd76727536f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800b2618..0x800b2637, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800b2618  3c028014  lui $v0,0x8014
 * 0x800b261c  24427fb0  addiu $v0,$v0,0x7fb0
 * 0x800b2620  3084000f  andi $a0,$a0,0x000f
 * 0x800b2624  00042040  sll $a0,$a0,1
 * 0x800b2628  00822021  addu $a0,$a0,$v0
 * 0x800b262c  84820000  lh $v0,0($a0)
 * 0x800b2630  03e00008  jr $ra
 * 0x800b2634  00000000  sll $zero,$zero,0
 */
