/* FUN_8006dc34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dc34  body 0x8006dc34..0x8006dc73  size 64 B
 * body sha256 1336d05de411023223fa2bf271f610d25eaed28af76f9cbbe815524ae89b9484
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
 * 0x8006dc34  8c83001c  lw $v1,28($a0)
 * 0x8006dc38  80850002  lb $a1,2($a0)
 * 0x8006dc3c  24630004  addiu $v1,$v1,0x0004
 * 0x8006dc40  00852821  addu $a1,$a0,$a1
 * 0x8006dc44  ac83001c  sw $v1,28($a0)
 * 0x8006dc48  90a20004  lbu $v0,4($a1)
 * 0x8006dc4c  9466fffe  lhu $a2,-2($v1)
 * 0x8006dc50  24420001  addiu $v0,$v0,0x0001
 * 0x8006dc54  a0a20004  sb $v0,4($a1)
 * 0x8006dc58  8c820140  lw $v0,320($a0)
 * 0x8006dc5c  00661821  addu $v1,$v1,$a2
 * 0x8006dc60  ac430000  sw $v1,0($v0)
 * 0x8006dc64  24420004  addiu $v0,$v0,0x0004
 * 0x8006dc68  ac820140  sw $v0,320($a0)
 * 0x8006dc6c  03e00008  jr $ra
 * 0x8006dc70  24020001  addiu $v0,$zero,0x0001
 */
