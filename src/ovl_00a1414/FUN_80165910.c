/* FUN_80165910
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165910  body 0x80165910..0x8016591f  size 16 B
 * body sha256 9e2d19cad8082eab6f8a3c6059e47c658291a1b938b95df25669bc7cb457be1e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80165910..0x8016591f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80165910  8ca20000  lw $v0,0($a1)
 * 0x80165914  34424000  ori $v0,$v0,0x4000
 * 0x80165918  03e00008  jr $ra
 * 0x8016591c  aca20000  sw $v0,0($a1)
 */
