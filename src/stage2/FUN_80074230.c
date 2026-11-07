/* FUN_80074230
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074230  body 0x80074230..0x80074273  size 68 B
 * body sha256 31523a31ab9bdf2caec8d7c6fad285be52eeac4a2bf741680c67e45971e0d4f8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 17 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80074230..0x80074273, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80074230  3c03800c  lui $v1,0x800c
 * 0x80074234  246376b0  addiu $v1,$v1,0x76b0
 * 0x80074238  3c028011  lui $v0,0x8011
 * 0x8007423c  8c4552cc  lw $a1,21196($v0)
 * 0x80074240  3c020002  lui $v0,0x0002
 * 0x80074244  00621821  addu $v1,$v1,$v0
 * 0x80074248  90a4000d  lbu $a0,13($a1)
 * 0x8007424c  3c028007  lui $v0,0x8007
 * 0x80074250  a0640f5f  sb $a0,3935($v1)
 * 0x80074254  90a4000f  lbu $a0,15($a1)
 * 0x80074258  24424274  addiu $v0,$v0,0x4274
 * 0x8007425c  ac621278  sw $v0,4728($v1)
 * 0x80074260  3c028013  lui $v0,0x8013
 * 0x80074264  a0600f6e  sb $zero,3950($v1)
 * 0x80074268  a044bfac  sb $a0,-16468($v0)
 * 0x8007426c  03e00008  jr $ra
 * 0x80074270  00001021  addu $v0,$zero,$zero
 */
