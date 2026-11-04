/* FUN_8003ecb8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ecb8  body 0x8003ecb8..0x8003ed0b  size 84 B
 * body sha256 eca68702d6227ecc621a60b655160d5113af24b7e8d46d9113b910813a453821
 * EXTENT MEASURED, NOT RECONSTRUCTED: 21 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8003ecb8  3c05800f  lui $a1,0x800f
 * 0x8003ecbc  8ca4bb94  lw $a0,-17516($a1)
 * 0x8003ecc0  90830021  lbu $v1,33($a0)
 * 0x8003ecc4  90820002  lbu $v0,2($a0)
 * 0x8003ecc8  1462000e  bne $v1,$v0,+14
 * 0x8003eccc  2402ffff  addiu $v0,$zero,0xffff
 * 0x8003ecd0  a0820009  sb $v0,9($a0)
 * 0x8003ecd4  8ca3bb94  lw $v1,-17516($a1)
 * 0x8003ecd8  2402fffd  addiu $v0,$zero,0xfffd
 * 0x8003ecdc  a0620008  sb $v0,8($v1)
 * 0x8003ece0  8ca4bb94  lw $a0,-17516($a1)
 * 0x8003ece4  9483000c  lhu $v1,12($a0)
 * 0x8003ece8  a0800000  sb $zero,0($a0)
 * 0x8003ecec  00031c00  sll $v1,$v1,16
 * 0x8003ecf0  00031403  sra $v0,$v1,16
 * 0x8003ecf4  00031fc2  srl $v1,$v1,31
 * 0x8003ecf8  00431021  addu $v0,$v0,$v1
 * 0x8003ecfc  00021043  sra $v0,$v0,1
 * 0x8003ed00  a482000c  sh $v0,12($a0)
 * 0x8003ed04  03e00008  jr $ra
 * 0x8003ed08  00000000  sll $zero,$zero,0
 */
