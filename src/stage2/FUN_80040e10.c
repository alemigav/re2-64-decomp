/* FUN_80040e10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040e10  body 0x80040e10..0x80040e2f  size 32 B
 * body sha256 d03ee2fab409e570a57f47fcdb5cc21b4d9104725ac4246e01296e97cc2a35da
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80040e08..0x80040e57, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80040e10  3c02800f  lui $v0,0x800f
 * 0x80040e14  24425e30  addiu $v0,$v0,0x5e30
 * 0x80040e18  30840fff  andi $a0,$a0,0x0fff
 * 0x80040e1c  00042080  sll $a0,$a0,2
 * 0x80040e20  00822021  addu $a0,$a0,$v0
 * 0x80040e24  c4800000  op&0x31 $zero,$a0,0x0000
 * 0x80040e28  03e00008  jr $ra
 * 0x80040e2c  00000000  sll $zero,$zero,0
 */
