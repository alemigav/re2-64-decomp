/* FUN_80073410
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073410  body 0x80073410..0x80073447  size 56 B
 * body sha256 64e9c6ae4379641c7ab14549f21c7762250ce8a13a56503ee5650a2204841b3a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073410  3c030001  lui $v1,0x0001
 * 0x80073414  8c82001c  lw $v0,28($a0)
 * 0x80073418  34638000  ori $v1,$v1,0x8000
 * 0x8007341c  24420001  addiu $v0,$v0,0x0001
 * 0x80073420  ac82001c  sw $v0,28($a0)
 * 0x80073424  3c02800c  lui $v0,0x800c
 * 0x80073428  244276b0  addiu $v0,$v0,0x76b0
 * 0x8007342c  00431021  addu $v0,$v0,$v1
 * 0x80073430  94431c7e  lhu $v1,7294($v0)
 * 0x80073434  a4401d34  sh $zero,7476($v0)
 * 0x80073438  a0401d36  sb $zero,7478($v0)
 * 0x8007343c  a4431c72  sh $v1,7282($v0)
 * 0x80073440  03e00008  jr $ra
 * 0x80073444  24020001  addiu $v0,$zero,0x0001
 */
