/* FUN_80036c44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036c44  body 0x80036c44..0x80036c67  size 36 B
 * body sha256 3d887d689cf3f26ada3e6e260a949e041c9005a1eed5e3265f93b595dab4d8fe
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80036c44..0x80036c67, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80036c44  8c820004  lw $v0,4($a0)
 * 0x80036c48  2403ff00  addiu $v1,$zero,0xff00
 * 0x80036c4c  00a32824  and $a1,$a1,$v1
 * 0x80036c50  00431024  and $v0,$v0,$v1
 * 0x80036c54  10450002  beq $v0,$a1,+2
 * 0x80036c58  240200ff  addiu $v0,$zero,0x00ff
 * 0x80036c5c  a08201e8  sb $v0,488($a0)
 * 0x80036c60  03e00008  jr $ra
 * 0x80036c64  00000000  sll $zero,$zero,0
 */
