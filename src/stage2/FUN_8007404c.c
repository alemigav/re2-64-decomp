/* FUN_8007404c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007404c  body 0x8007404c..0x800740b3  size 104 B
 * body sha256 79a8954523977c1660c59e29556d3e560819fc6dfe74451ee7d06542f84783b8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 26 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007404c  3c020001  lui $v0,0x0001
 * 0x80074050  34428000  ori $v0,$v0,0x8000
 * 0x80074054  3c06800c  lui $a2,0x800c
 * 0x80074058  24c676b0  addiu $a2,$a2,0x76b0
 * 0x8007405c  00c23021  addu $a2,$a2,$v0
 * 0x80074060  8cc30288  lw $v1,648($a2)
 * 0x80074064  84850000  lh $a1,0($a0)
 * 0x80074068  8c620028  lw $v0,40($v1)
 * 0x8007406c  00451021  addu $v0,$v0,$a1
 * 0x80074070  ac620028  sw $v0,40($v1)
 * 0x80074074  24630028  addiu $v1,$v1,0x0028
 * 0x80074078  84850002  lh $a1,2($a0)
 * 0x8007407c  8c620004  lw $v0,4($v1)
 * 0x80074080  00451021  addu $v0,$v0,$a1
 * 0x80074084  ac620004  sw $v0,4($v1)
 * 0x80074088  84840004  lh $a0,4($a0)
 * 0x8007408c  8c620008  lw $v0,8($v1)
 * 0x80074090  00441021  addu $v0,$v0,$a0
 * 0x80074094  ac620008  sw $v0,8($v1)
 * 0x80074098  8cc40288  lw $a0,648($a2)
 * 0x8007409c  8c820000  lw $v0,0($a0)
 * 0x800740a0  3c030002  lui $v1,0x0002
 * 0x800740a4  00431025  or $v0,$v0,$v1
 * 0x800740a8  ac820000  sw $v0,0($a0)
 * 0x800740ac  03e00008  jr $ra
 * 0x800740b0  00001021  addu $v0,$zero,$zero
 */
