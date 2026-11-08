/* FUN_80039f08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039f08  body 0x80039f08..0x80039f33  size 44 B
 * body sha256 30e270154663c52c9b26a257cc88a861065c8567b43a1ec1ec924f54140007d9
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (M388 correction (extent too short): the `beql` at word 3 targets 0x80039f28, which is INSIDE the same body -- the take-the-zero arm `sb $zero,0($v1); jr $ra; sh $zero,24($v1)`. Cut at the extent's own `jr ra` the body looked like a fragment; the function has two returns and is 11 words. M388: and the 11-word extent ABSORBS the separate 3-word entry that used to sit at 0x80039f28 -- that fragment (`sb $zero,0($v1)` reading v1 before writing it) is this body's second return, not a function, so it is withdrawn rather than left as a duplicate claim on the same words)
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
 * 0x80039f28  a0600000  sb $zero,0($v1)
 * 0x80039f2c  03e00008  jr $ra
 * 0x80039f30  a4600018  sh $zero,24($v1)
 */
