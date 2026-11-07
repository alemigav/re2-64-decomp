/* FUN_80021924
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80021924  body 0x80021924..0x80021957  size 52 B
 * body sha256 1b568554f44f93720c1adb94439f3f54da36b2bb6de9dc0cb284a9072bcba129
 * EXTENT MEASURED, NOT RECONSTRUCTED: 13 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80021924  8c0b0fd0  lw $t3,4048($zero)
 * 0x80021928  ac1a0950  sw $k0,2384($zero)
 * 0x8002192c  ac0b0954  sw $t3,2388($zero)
 * 0x80021930  8c180ff8  lw $t8,4088($zero)
 * 0x80021934  20148000  op&0x08 $s4,$zero,0x8000
 * 0x80021938  0c0007f6  jal 0x80001fd8
 * 0x8002193c  2013090f  op&0x08 $s3,$zero,0x090f
 * 0x80021940  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x80021944  27180bf8  addiu $t8,$t8,0x0bf8
 * 0x80021948  20148950  op&0x08 $s4,$zero,0x8950
 * 0x8002194c  20130007  op&0x08 $s3,$zero,0x0007
 * 0x80021950  080007f6  j 0x80001fd8
 * 0x80021954  201f108c  op&0x08 $ra,$zero,0x108c
 */
