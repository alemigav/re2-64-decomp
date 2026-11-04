/* FUN_8009b1bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b1bc  body 0x8009b1bc..0x8009b1f3  size 56 B
 * body sha256 b02064016dec1c5b70ca805f72c1c9a90cce2dbbd5d4960184e3dd0e665fd8b0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8009b1bc  3c048013  lui $a0,0x8013
 * 0x8009b1c0  2403ffff  addiu $v1,$zero,0xffff
 * 0x8009b1c4  808214c5  lb $v0,5317($a0)
 * 0x8009b1c8  908514c5  lbu $a1,5317($a0)
 * 0x8009b1cc  54430009  op&0x15 $v1,$v0,0x0009
 * 0x8009b1d0  3c04800c  lui $a0,0x800c
 * 0x8009b1d4  3c02800c  lui $v0,0x800c
 * 0x8009b1d8  244276b0  addiu $v0,$v0,0x76b0
 * 0x8009b1dc  3c030002  lui $v1,0x0002
 * 0x8009b1e0  00431021  addu $v0,$v0,$v1
 * 0x8009b1e4  90421962  lbu $v0,6498($v0)
 * 0x8009b1e8  00021102  srl $v0,$v0,4
 * 0x8009b1ec  03e00008  jr $ra
 * 0x8009b1f0  a08214c5  sb $v0,5317($a0)
 */
