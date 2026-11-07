/* FUN_8001f410
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f410  body 0x8001f410..0x8001f433  size 36 B
 * body sha256 323b55da1e35a769ac8d8f817bfcb4ba0a9a006ab90f2821b6fcfe9004241e6d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8001f410  8c0b0fd0  lw $t3,4048($zero)
 * 0x8001f414  ac1a0bf8  sw $k0,3064($zero)
 * 0x8001f418  ac0b0bfc  sw $t3,3068($zero)
 * 0x8001f41c  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x8001f420  8c180ff8  lw $t8,4088($zero)
 * 0x8001f424  20148000  op&0x08 $s4,$zero,0x8000
 * 0x8001f428  20130bff  op&0x08 $s3,$zero,0x0bff
 * 0x8001f42c  080007f6  j 0x80001fd8
 * 0x8001f430  201f1088  op&0x08 $ra,$zero,0x1088
 */
