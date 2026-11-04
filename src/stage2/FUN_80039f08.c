/* FUN_80039f08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039f08  body 0x80039f08..0x80039f27  size 32 B
 * body sha256 93b8113c27980f048cbe39a5e12efa37a05e455a905bc96d953bad09540a3f6e
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
 * 0x80039f08  3c02800f  lui $v0,0x800f
 * 0x80039f0c  8c43bb94  lw $v1,-17516($v0)
 * 0x80039f10  90620002  lbu $v0,2($v1)
 * 0x80039f14  50400004  op&0x14 $zero,$v0,0x0004
 * 0x80039f18  a0600001  sb $zero,1($v1)
 * 0x80039f1c  2442ffff  addiu $v0,$v0,0xffff
 * 0x80039f20  03e00008  jr $ra
 * 0x80039f24  a0620002  sb $v0,2($v1)
 */
