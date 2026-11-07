/* FUN_8003b640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b640  body 0x8003b640..0x8003b66b  size 44 B
 * body sha256 beb03bb94c1775244d4657538e2b9215a6c9d7e13201485ace9a7de9db8daecf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003b640..0x8003b66b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003b640  3c02800f  lui $v0,0x800f
 * 0x8003b644  8c42bb94  lw $v0,-17516($v0)
 * 0x8003b648  94430004  lhu $v1,4($v0)
 * 0x8003b64c  94450012  lhu $a1,18($v0)
 * 0x8003b650  94440006  lhu $a0,6($v0)
 * 0x8003b654  94460014  lhu $a2,20($v0)
 * 0x8003b658  00651821  addu $v1,$v1,$a1
 * 0x8003b65c  00862021  addu $a0,$a0,$a2
 * 0x8003b660  a4430004  sh $v1,4($v0)
 * 0x8003b664  03e00008  jr $ra
 * 0x8003b668  a4440006  sh $a0,6($v0)
 */
