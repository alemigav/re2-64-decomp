/* FUN_8007a510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a510  body 0x8007a510..0x8007a543  size 52 B
 * body sha256 fd146e8ccf6be65ee6e45ea1cddbdfdac47ecb7128b9fa49a2fa36e09fc94f9d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 13 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8007a510..0x8007a54b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8007a510  8c820234  lw $v0,564($a0)
 * 0x8007a514  ac400020  sw $zero,32($v0)
 * 0x8007a518  24020001  addiu $v0,$zero,0x0001
 * 0x8007a51c  a082025c  sb $v0,604($a0)
 * 0x8007a520  24020004  addiu $v0,$zero,0x0004
 * 0x8007a524  a0820004  sb $v0,4($a0)
 * 0x8007a528  8c820000  lw $v0,0($a0)
 * 0x8007a52c  24030014  addiu $v1,$zero,0x0014
 * 0x8007a530  a080025d  sb $zero,605($a0)
 * 0x8007a534  a0830005  sb $v1,5($a0)
 * 0x8007a538  3442000a  ori $v0,$v0,0x000a
 * 0x8007a53c  03e00008  jr $ra
 * 0x8007a540  ac820000  sw $v0,0($a0)
 */
