/* FUN_8003a578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a578  body 0x8003a578..0x8003a58f  size 24 B
 * body sha256 73cd415acd73d3b5dd7299f0c08526ba5247f93637a8f992129781b9cd55b0f2
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003a578..0x8003a58f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003a578  3c02800f  lui $v0,0x800f
 * 0x8003a57c  8c43bb94  lw $v1,-17516($v0)
 * 0x8003a580  3402a003  ori $v0,$zero,0xa003
 * 0x8003a584  a4620018  sh $v0,24($v1)
 * 0x8003a588  03e00008  jr $ra
 * 0x8003a58c  a0600000  sb $zero,0($v1)
 */
