/* FUN_80166ecc
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166ecc  body 0x80166ecc..0x80166f17  size 76 B
 * body sha256 b9011c6e1f4ea0a474fe3c6f63399287f5aa8710d3fdcedfcf21b0f1a1834ae8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80166ecc  8ca40234  lw $a0,564($a1)
 * 0x80166ed0  8c8205e0  lw $v0,1504($a0)
 * 0x80166ed4  2403bfff  addiu $v1,$zero,0xbfff
 * 0x80166ed8  00431024  and $v0,$v0,$v1
 * 0x80166edc  34420040  ori $v0,$v0,0x0040
 * 0x80166ee0  ac8205e0  sw $v0,1504($a0)
 * 0x80166ee4  24020002  addiu $v0,$zero,0x0002
 * 0x80166ee8  a0a202bf  sb $v0,703($a1)
 * 0x80166eec  24020096  addiu $v0,$zero,0x0096
 * 0x80166ef0  a4a202c0  sh $v0,704($a1)
 * 0x80166ef4  94a202c0  lhu $v0,704($a1)
 * 0x80166ef8  3403ffff  ori $v1,$zero,0xffff
 * 0x80166efc  2442ffff  addiu $v0,$v0,0xffff
 * 0x80166f00  a4a202c0  sh $v0,704($a1)
 * 0x80166f04  3042ffff  andi $v0,$v0,0xffff
 * 0x80166f08  1443ffee  bne $v0,$v1,-18
 * 0x80166f0c  24020003  addiu $v0,$zero,0x0003
 * 0x80166f10  03e00008  jr $ra
 * 0x80166f14  a0a202bf  sb $v0,703($a1)
 */
