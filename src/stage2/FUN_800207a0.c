/* FUN_800207a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800207a0  body 0x800207a0..0x800207c3  size 36 B
 * body sha256 199c549a8f6466c0a9774b6b8ee14785133532c8c254df543c45f2a689a25905
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
 * 0x800207a0  8c0b0fd0  lw $t3,4048($zero)
 * 0x800207a4  ac1a0bf8  sw $k0,3064($zero)
 * 0x800207a8  ac0b0bfc  sw $t3,3068($zero)
 * 0x800207ac  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x800207b0  8c180ff8  lw $t8,4088($zero)
 * 0x800207b4  20148000  op&0x08 $s4,$zero,0x8000
 * 0x800207b8  20130bff  op&0x08 $s3,$zero,0x0bff
 * 0x800207bc  080007f6  j 0x80001fd8
 * 0x800207c0  201f1088  op&0x08 $ra,$zero,0x1088
 */
