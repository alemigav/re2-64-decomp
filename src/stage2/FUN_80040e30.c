/* FUN_80040e30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040e30  body 0x80040e30..0x80040e57  size 40 B
 * body sha256 5f21bf87913e8b03788411fa0a6fc71ee859c576c546dd40d14617f80e4a17cc
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80040e08..0x80040e57, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80040e30  3c02800f  lui $v0,0x800f
 * 0x80040e34  24425e30  addiu $v0,$v0,0x5e30
 * 0x80040e38  3084ffff  andi $a0,$a0,0xffff
 * 0x80040e3c  24840400  addiu $a0,$a0,0x0400
 * 0x80040e40  30840fff  andi $a0,$a0,0x0fff
 * 0x80040e44  00042080  sll $a0,$a0,2
 * 0x80040e48  00822021  addu $a0,$a0,$v0
 * 0x80040e4c  c4800000  op&0x31 $zero,$a0,0x0000
 * 0x80040e50  03e00008  jr $ra
 * 0x80040e54  00000000  sll $zero,$zero,0
 */
