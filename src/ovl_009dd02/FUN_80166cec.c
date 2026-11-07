/* FUN_80166cec
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166cec  body 0x80166cec..0x80166d13  size 40 B
 * body sha256 f74c03fe3447bc274ab77322904490695f3f1966c3eeb3da747763319b4bb820
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80166ccc..0x80166d13, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80166cec  240300c2  addiu $v1,$zero,0x00c2
 * 0x80166cf0  a0c3000d  sb $v1,13($a2)
 * 0x80166cf4  24030001  addiu $v1,$zero,0x0001
 * 0x80166cf8  00a31804  special&0x04 $v1,$a1,$v1
 * 0x80166cfc  90c4000e  lbu $a0,14($a2)
 * 0x80166d00  00031827  special&0x27 $v1,$zero,$v1
 * 0x80166d04  a0c5000f  sb $a1,15($a2)
 * 0x80166d08  00832024  and $a0,$a0,$v1
 * 0x80166d0c  03e00008  jr $ra
 * 0x80166d10  a0c4000e  sb $a0,14($a2)
 */
