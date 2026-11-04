/* FUN_8003c114
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c114  body 0x8003c114..0x8003c16f  size 92 B
 * body sha256 8193bdb3c7e81b16d62629fdca5e8a565085481b34cf850afe33b0859b9b5d87
 * EXTENT MEASURED, NOT RECONSTRUCTED: 23 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8003c114  3c05800f  lui $a1,0x800f
 * 0x8003c118  8ca2bb94  lw $v0,-17516($a1)
 * 0x8003c11c  ac400000  sw $zero,0($v0)
 * 0x8003c120  8ca2bb94  lw $v0,-17516($a1)
 * 0x8003c124  a0400009  sb $zero,9($v0)
 * 0x8003c128  a0400008  sb $zero,8($v0)
 * 0x8003c12c  8ca3bb94  lw $v1,-17516($a1)
 * 0x8003c130  24020006  addiu $v0,$zero,0x0006
 * 0x8003c134  a0620021  sb $v0,33($v1)
 * 0x8003c138  8ca4bb94  lw $a0,-17516($a1)
 * 0x8003c13c  a460000e  sh $zero,14($v1)
 * 0x8003c140  a460000c  sh $zero,12($v1)
 * 0x8003c144  90820021  lbu $v0,33($a0)
 * 0x8003c148  8c830070  lw $v1,112($a0)
 * 0x8003c14c  000210c0  sll $v0,$v0,3
 * 0x8003c150  00621821  addu $v1,$v1,$v0
 * 0x8003c154  90620002  lbu $v0,2($v1)
 * 0x8003c158  a0820020  sb $v0,32($a0)
 * 0x8003c15c  8ca3bb94  lw $v1,-17516($a1)
 * 0x8003c160  94620018  lhu $v0,24($v1)
 * 0x8003c164  3042a001  andi $v0,$v0,0xa001
 * 0x8003c168  03e00008  jr $ra
 * 0x8003c16c  a4620018  sh $v0,24($v1)
 */
