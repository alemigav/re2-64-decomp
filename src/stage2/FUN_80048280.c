/* FUN_80048280
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048280  body 0x80048280..0x80048293  size 20 B
 * body sha256 832cdd086176cc2dd0591a2d7652130bb57dfd9f091b3e98d487c47983a87d03
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80048108..0x80048293, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80048280  3c01800c  lui $at,0x800c
 * 0x80048284  d4208998  op&0x35 $zero,$at,0x8998
 * 0x80048288  46220003  op&0x11 $v0,$s1,0x0003
 * 0x8004828c  03e00008  jr $ra
 * 0x80048290  46200020  op&0x11 $zero,$s1,0x0020
 */
