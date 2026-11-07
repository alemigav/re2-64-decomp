/* FUN_8004d320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d320  body 0x8004d320..0x8004d343  size 36 B
 * body sha256 4ab698d03209e45f868508731b9766903220590c6e64ca6a459ee6220c3f503b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8004d320..0x8004d343, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8004d320  3c038011  lui $v1,0x8011
 * 0x8004d324  2463b700  addiu $v1,$v1,0xb700
 * 0x8004d328  8c62003c  lw $v0,60($v1)
 * 0x8004d32c  00002021  addu $a0,$zero,$zero
 * 0x8004d330  00002821  addu $a1,$zero,$zero
 * 0x8004d334  ac640038  sw $a0,56($v1)
 * 0x8004d338  ac65003c  sw $a1,60($v1)
 * 0x8004d33c  03e00008  jr $ra
 * 0x8004d340  00000000  sll $zero,$zero,0
 */
