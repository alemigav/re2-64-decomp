/* FUN_80073ac4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073ac4  body 0x80073ac4..0x80073af3  size 48 B
 * body sha256 874844f26bbae54be23b4cf283e49a1eb1789c4289e5069ba7319f73e8912b18
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80073ac4..0x80073af3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80073ac4  3c02800c  lui $v0,0x800c
 * 0x80073ac8  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073acc  3c050002  lui $a1,0x0002
 * 0x80073ad0  3c038011  lui $v1,0x8011
 * 0x80073ad4  3c048011  lui $a0,0x8011
 * 0x80073ad8  946352d2  lhu $v1,21202($v1)
 * 0x80073adc  948452d6  lhu $a0,21206($a0)
 * 0x80073ae0  00451021  addu $v0,$v0,$a1
 * 0x80073ae4  a44315c8  sh $v1,5576($v0)
 * 0x80073ae8  a44415ca  sh $a0,5578($v0)
 * 0x80073aec  03e00008  jr $ra
 * 0x80073af0  00001021  addu $v0,$zero,$zero
 */
