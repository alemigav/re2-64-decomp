/* FUN_80071ce8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071ce8  body 0x80071ce8..0x80071d27  size 64 B
 * body sha256 56eb3ef3a1033ef5987a150bcbf271f48ad1f3b7e908c3f028c6655bd118ac29
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
 * 0x80071ce8  8c850154  lw $a1,340($a0)
 * 0x80071cec  8ca30004  lw $v1,4($a1)
 * 0x80071cf0  3c060414  lui $a2,0x0414
 * 0x80071cf4  14660004  bne $v1,$a2,+4
 * 0x80071cf8  00000000  sll $zero,$zero,0
 * 0x80071cfc  8c820170  lw $v0,368($a0)
 * 0x80071d00  0801c745  j 0x80071d14
 * 0x80071d04  aca20004  sw $v0,4($a1)
 * 0x80071d08  8c820154  lw $v0,340($a0)
 * 0x80071d0c  ac830170  sw $v1,368($a0)
 * 0x80071d10  ac460004  sw $a2,4($v0)
 * 0x80071d14  8c82001c  lw $v0,28($a0)
 * 0x80071d18  24420001  addiu $v0,$v0,0x0001
 * 0x80071d1c  ac82001c  sw $v0,28($a0)
 * 0x80071d20  03e00008  jr $ra
 * 0x80071d24  24020001  addiu $v0,$zero,0x0001
 */
