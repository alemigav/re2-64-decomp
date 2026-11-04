/* FUN_80073170
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073170  body 0x80073170..0x800731bb  size 76 B
 * body sha256 ef483dd5dfbecdbddaa167c503859818722abe78c57d98f1159358ede5040c4f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073170  3c030001  lui $v1,0x0001
 * 0x80073174  34638000  ori $v1,$v1,0x8000
 * 0x80073178  3c02800c  lui $v0,0x800c
 * 0x8007317c  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073180  3c050002  lui $a1,0x0002
 * 0x80073184  00452821  addu $a1,$v0,$a1
 * 0x80073188  00431021  addu $v0,$v0,$v1
 * 0x8007318c  a0a0195f  sb $zero,6495($a1)
 * 0x80073190  8c461d3c  lw $a2,7484($v0)
 * 0x80073194  240300c8  addiu $v1,$zero,0x00c8
 * 0x80073198  a4a31960  sh $v1,6496($a1)
 * 0x8007319c  a4c301f2  sh $v1,498($a2)
 * 0x800731a0  8c421d3c  lw $v0,7484($v0)
 * 0x800731a4  a44301fe  sh $v1,510($v0)
 * 0x800731a8  8c82001c  lw $v0,28($a0)
 * 0x800731ac  24420001  addiu $v0,$v0,0x0001
 * 0x800731b0  ac82001c  sw $v0,28($a0)
 * 0x800731b4  03e00008  jr $ra
 * 0x800731b8  24020001  addiu $v0,$zero,0x0001
 */
