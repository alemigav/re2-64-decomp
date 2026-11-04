/* FUN_8006faf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006faf4  body 0x8006faf4..0x8006fb47  size 84 B
 * body sha256 9eb2103f797f78bf4caed5d14399fe7b4c9ffbe5c51647cb587f23bad5cc3265
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
 * 0x8006faf4  3c03800f  lui $v1,0x800f
 * 0x8006faf8  8c820154  lw $v0,340($a0)
 * 0x8006fafc  8c85001c  lw $a1,28($a0)
 * 0x8006fb00  8c460058  lw $a2,88($v0)
 * 0x8006fb04  8c47005c  lw $a3,92($v0)
 * 0x8006fb08  8c480060  lw $t0,96($v0)
 * 0x8006fb0c  24639028  addiu $v1,$v1,0x9028
 * 0x8006fb10  ac430070  sw $v1,112($v0)
 * 0x8006fb14  ac460028  sw $a2,40($v0)
 * 0x8006fb18  ac47002c  sw $a3,44($v0)
 * 0x8006fb1c  ac480030  sw $t0,48($v0)
 * 0x8006fb20  84a30002  lh $v1,2($a1)
 * 0x8006fb24  84a60004  lh $a2,4($a1)
 * 0x8006fb28  84a70006  lh $a3,6($a1)
 * 0x8006fb2c  24a50008  addiu $a1,$a1,0x0008
 * 0x8006fb30  a4430064  sh $v1,100($v0)
 * 0x8006fb34  a4460066  sh $a2,102($v0)
 * 0x8006fb38  a4470068  sh $a3,104($v0)
 * 0x8006fb3c  24020001  addiu $v0,$zero,0x0001
 * 0x8006fb40  03e00008  jr $ra
 * 0x8006fb44  ac85001c  sw $a1,28($a0)
 */
