/* FUN_80025e90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025e90  body 0x80025e90..0x80025eef  size 96 B
 * body sha256 b29a6b667b9f6d2b13d1da648f30d18c417a0988789457044273844f3c4267a8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 24 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80025e90..0x80025eef, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80025e90  3c09800c  lui $t1,0x800c
 * 0x80025e94  3c02800c  lui $v0,0x800c
 * 0x80025e98  3c04800c  lui $a0,0x800c
 * 0x80025e9c  3c05800c  lui $a1,0x800c
 * 0x80025ea0  3c06800c  lui $a2,0x800c
 * 0x80025ea4  3c07800c  lui $a3,0x800c
 * 0x80025ea8  3c08800c  lui $t0,0x800c
 * 0x80025eac  8c434ea0  lw $v1,20128($v0)
 * 0x80025eb0  8c824ea4  lw $v0,20132($a0)
 * 0x80025eb4  8ca456ec  lw $a0,22252($a1)
 * 0x80025eb8  8cc556f0  lw $a1,22256($a2)
 * 0x80025ebc  8ce67648  lw $a2,30280($a3)
 * 0x80025ec0  8d07763c  lw $a3,30268($t0)
 * 0x80025ec4  00621021  addu $v0,$v1,$v0
 * 0x80025ec8  ad2256e4  sw $v0,22244($t1)
 * 0x80025ecc  ac830028  sw $v1,40($a0)
 * 0x80025ed0  ac82002c  sw $v0,44($a0)
 * 0x80025ed4  aca30028  sw $v1,40($a1)
 * 0x80025ed8  aca2002c  sw $v0,44($a1)
 * 0x80025edc  acc30028  sw $v1,40($a2)
 * 0x80025ee0  acc2002c  sw $v0,44($a2)
 * 0x80025ee4  ace30028  sw $v1,40($a3)
 * 0x80025ee8  03e00008  jr $ra
 * 0x80025eec  ace2002c  sw $v0,44($a3)
 */
