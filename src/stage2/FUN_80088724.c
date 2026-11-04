/* FUN_80088724
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80088724  body 0x80088724..0x80088763  size 64 B
 * body sha256 de129ee1797a5de49310e289dfceac1796a80a30f77fe0e6eb7a66cc2bee456c
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
 * 0x80088724  27bdffe8  addiu $sp,$sp,0xffe8
 * 0x80088728  10a0000a  beq $a1,$zero,+10
 * 0x8008872c  afbf0010  sw $ra,16($sp)
 * 0x80088730  3c028013  lui $v0,0x8013
 * 0x80088734  2443bcb0  addiu $v1,$v0,0xbcb0
 * 0x80088738  ac640008  sw $a0,8($v1)
 * 0x8008873c  a4650002  sh $a1,2($v1)
 * 0x80088740  ac66000c  sw $a2,12($v1)
 * 0x80088744  a4600004  sh $zero,4($v1)
 * 0x80088748  24030001  addiu $v1,$zero,0x0001
 * 0x8008874c  0c022170  jal 0x800885c0
 * 0x80088750  a043bcb0  sb $v1,-17232($v0)
 * 0x80088754  8fbf0010  lw $ra,16($sp)
 * 0x80088758  24020001  addiu $v0,$zero,0x0001
 * 0x8008875c  03e00008  jr $ra
 * 0x80088760  27bd0018  addiu $sp,$sp,0x0018
 */
