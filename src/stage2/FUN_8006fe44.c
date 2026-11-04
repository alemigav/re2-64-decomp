/* FUN_8006fe44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fe44  body 0x8006fe44..0x8006fe73  size 48 B
 * body sha256 7ecbd477a78b39fbb84b70827258f84e192dd9737cba5114c5940f17c5d219f1
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
 * 0x8006fe44  8c82001c  lw $v0,28($a0)
 * 0x8006fe48  8c830154  lw $v1,340($a0)
 * 0x8006fe4c  84450002  lh $a1,2($v0)
 * 0x8006fe50  84460004  lh $a2,4($v0)
 * 0x8006fe54  84470006  lh $a3,6($v0)
 * 0x8006fe58  24420008  addiu $v0,$v0,0x0008
 * 0x8006fe5c  ac650028  sw $a1,40($v1)
 * 0x8006fe60  ac66002c  sw $a2,44($v1)
 * 0x8006fe64  ac670030  sw $a3,48($v1)
 * 0x8006fe68  ac82001c  sw $v0,28($a0)
 * 0x8006fe6c  03e00008  jr $ra
 * 0x8006fe70  24020001  addiu $v0,$zero,0x0001
 */
