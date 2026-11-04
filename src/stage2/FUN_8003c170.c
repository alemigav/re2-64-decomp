/* FUN_8003c170
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c170  body 0x8003c170..0x8003c187  size 24 B
 * body sha256 84fa2a96025b4bc8060d5190a3d8e4e5a80b3df3ca705887c239e192bb166843
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8003c170  3c02800f  lui $v0,0x800f
 * 0x8003c174  8c42bb94  lw $v0,-17516($v0)
 * 0x8003c178  a0400008  sb $zero,8($v0)
 * 0x8003c17c  a440000c  sh $zero,12($v0)
 * 0x8003c180  03e00008  jr $ra
 * 0x8003c184  a0400003  sb $zero,3($v0)
 */
