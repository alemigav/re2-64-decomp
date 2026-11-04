/* FUN_8003c3c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c3c0  body 0x8003c3c0..0x8003c417  size 88 B
 * body sha256 74b67416881934d347cd40b55fa3dae668bdbcc125be6071eddf870f4c2be4b1
 * EXTENT MEASURED, NOT RECONSTRUCTED: 22 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8003c3c0  3c05800f  lui $a1,0x800f
 * 0x8003c3c4  8ca2bb94  lw $v0,-17516($a1)
 * 0x8003c3c8  a0400000  sb $zero,0($v0)
 * 0x8003c3cc  8ca2bb94  lw $v0,-17516($a1)
 * 0x8003c3d0  a0400001  sb $zero,1($v0)
 * 0x8003c3d4  8ca3bb94  lw $v1,-17516($a1)
 * 0x8003c3d8  2402001e  addiu $v0,$zero,0x001e
 * 0x8003c3dc  a0620021  sb $v0,33($v1)
 * 0x8003c3e0  94620016  lhu $v0,22($v1)
 * 0x8003c3e4  8ca4bb94  lw $a0,-17516($a1)
 * 0x8003c3e8  a4620036  sh $v0,54($v1)
 * 0x8003c3ec  90820021  lbu $v0,33($a0)
 * 0x8003c3f0  8c830070  lw $v1,112($a0)
 * 0x8003c3f4  000210c0  sll $v0,$v0,3
 * 0x8003c3f8  00621821  addu $v1,$v1,$v0
 * 0x8003c3fc  90620002  lbu $v0,2($v1)
 * 0x8003c400  a0820020  sb $v0,32($a0)
 * 0x8003c404  8ca3bb94  lw $v1,-17516($a1)
 * 0x8003c408  94620018  lhu $v0,24($v1)
 * 0x8003c40c  3042fffd  andi $v0,$v0,0xfffd
 * 0x8003c410  03e00008  jr $ra
 * 0x8003c414  a4620018  sh $v0,24($v1)
 */
