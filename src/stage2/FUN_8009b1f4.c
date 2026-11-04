/* FUN_8009b1f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b1f4  body 0x8009b1f4..0x8009b21b  size 40 B
 * body sha256 91736a884d01d76e4297bfed9bca1a7b4267e10f7d4e123de824d1f59f743de6
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8009b1f4  248476b0  addiu $a0,$a0,0x76b0
 * 0x8009b1f8  3c020002  lui $v0,0x0002
 * 0x8009b1fc  00822021  addu $a0,$a0,$v0
 * 0x8009b200  30a2000f  andi $v0,$a1,0x000f
 * 0x8009b204  90831962  lbu $v1,6498($a0)
 * 0x8009b208  00021100  sll $v0,$v0,4
 * 0x8009b20c  3063000f  andi $v1,$v1,0x000f
 * 0x8009b210  00621825  or $v1,$v1,$v0
 * 0x8009b214  03e00008  jr $ra
 * 0x8009b218  a0831962  sb $v1,6498($a0)
 */
