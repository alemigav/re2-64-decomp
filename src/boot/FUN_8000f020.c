/* FUN_8000f020
 * image   boot (boot), base 0x80000480
 * address 0x8000f020  body 0x8000f020..0x8000f047  size 40 B
 * body sha256 091721f03ca221b73ccd19733ab1fe8dc52c114accdf6273e5f7f18e0b770c14
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8000f020..0x8000f04f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8000f020  3c088000  lui $t0,0x8000
 * 0x8000f024  240a2000  addiu $t2,$zero,0x2000
 * 0x8000f028  010a4821  addu $t1,$t0,$t2
 * 0x8000f02c  2529fff0  addiu $t1,$t1,0xfff0
 * 0x8000f030  bd010000  op&0x2f $at,$t0,0x0000
 * 0x8000f034  0109082b  sltu $at,$t0,$t1
 * 0x8000f038  1420fffd  bne $at,$zero,-3
 * 0x8000f03c  25080010  addiu $t0,$t0,0x0010
 * 0x8000f040  03e00008  jr $ra
 * 0x8000f044  00000000  sll $zero,$zero,0
 */
