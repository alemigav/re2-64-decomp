/* FUN_800a2510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a2510  body 0x800a2510..0x800a254f  size 64 B
 * body sha256 64a389481572b024e342428e8bb1967b700eab4727d06976c78f8e1198fc6930
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800a2510  00c21024  and $v0,$a2,$v0
 * 0x800a2514  08028936  j 0x800a24d8
 * 0x800a2518  00822025  or $a0,$a0,$v0
 * 0x800a251c  3442ffff  ori $v0,$v0,0xffff
 * 0x800a2520  00c23024  and $a2,$a2,$v0
 * 0x800a2524  3c038014  lui $v1,0x8014
 * 0x800a2528  2463bc90  addiu $v1,$v1,0xbc90
 * 0x800a252c  00061240  sll $v0,$a2,9
 * 0x800a2530  00461023  subu $v0,$v0,$a2
 * 0x800a2534  000210c0  sll $v0,$v0,3
 * 0x800a2538  00431021  addu $v0,$v0,$v1
 * 0x800a253c  90430fee  lbu $v1,4078($v0)
 * 0x800a2540  a4450fec  sh $a1,4076($v0)
 * 0x800a2544  34630020  ori $v1,$v1,0x0020
 * 0x800a2548  a0430fee  sb $v1,4078($v0)
 * 0x800a254c  03e00008  jr $ra
 */
