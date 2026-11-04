/* FUN_800b1c40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1c40  body 0x800b1c40..0x800b1c6f  size 48 B
 * body sha256 2ca0f80a3e0089d1f42b944eddf01b7748367081bf27a6499487c413db417f02
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800b1c40  24848aa0  addiu $a0,$a0,0x8aa0
 * 0x800b1c44  90a3004b  lbu $v1,75($a1)
 * 0x800b1c48  90a2004a  lbu $v0,74($a1)
 * 0x800b1c4c  00031900  sll $v1,$v1,4
 * 0x800b1c50  00431021  addu $v0,$v0,$v1
 * 0x800b1c54  00441021  addu $v0,$v0,$a0
 * 0x800b1c58  90430000  lbu $v1,0($v0)
 * 0x800b1c5c  10660002  beq $v1,$a2,+2
 * 0x800b1c60  24020001  addiu $v0,$zero,0x0001
 * 0x800b1c64  00001021  addu $v0,$zero,$zero
 * 0x800b1c68  03e00008  jr $ra
 * 0x800b1c6c  00000000  sll $zero,$zero,0
 */
