/* FUN_80088528
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088528  body 0x80088528..0x80088547  size 32 B
 * body sha256 3994cd594ee8bb45b4afd5f699c0e1a29867358cc7313b2a708ccb4dc095be27
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80088528  00a03821  addu $a3,$a1,$zero
 * 0x8008852c  01002821  addu $a1,$t0,$zero
 * 0x80088530  94a30000  lhu $v1,0($a1)
 * 0x80088534  30620008  andi $v0,$v1,0x0008
 * 0x80088538  1040ffde  beq $v0,$zero,-34
 * 0x8008853c  00000000  sll $zero,$zero,0
 * 0x80088540  03e00008  jr $ra
 * 0x80088544  00000000  sll $zero,$zero,0
 */
