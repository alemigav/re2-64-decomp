/* FUN_8006e388
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e388  body 0x8006e388..0x8006e3d3  size 76 B
 * body sha256 784595f785d9cca723573f891ac727c804e896c41932ee7c444ecdfcfd1c257d
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
 * 0x8006e388  80820002  lb $v0,2($a0)
 * 0x8006e38c  8c85001c  lw $a1,28($a0)
 * 0x8006e390  00823021  addu $a2,$a0,$v0
 * 0x8006e394  00021140  sll $v0,$v0,5
 * 0x8006e398  244200c0  addiu $v0,$v0,0x00c0
 * 0x8006e39c  90a30001  lbu $v1,1($a1)
 * 0x8006e3a0  90a70002  lbu $a3,2($a1)
 * 0x8006e3a4  84a80004  lh $t0,4($a1)
 * 0x8006e3a8  00821021  addu $v0,$a0,$v0
 * 0x8006e3ac  a0c30004  sb $v1,4($a2)
 * 0x8006e3b0  00031880  sll $v1,$v1,2
 * 0x8006e3b4  24630004  addiu $v1,$v1,0x0004
 * 0x8006e3b8  00431021  addu $v0,$v0,$v1
 * 0x8006e3bc  00a82821  addu $a1,$a1,$t0
 * 0x8006e3c0  ac820140  sw $v0,320($a0)
 * 0x8006e3c4  24020001  addiu $v0,$zero,0x0001
 * 0x8006e3c8  a0c70008  sb $a3,8($a2)
 * 0x8006e3cc  03e00008  jr $ra
 * 0x8006e3d0  ac85001c  sw $a1,28($a0)
 */
