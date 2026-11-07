/* FUN_8006e644
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e644  body 0x8006e644..0x8006e65b  size 24 B
 * body sha256 788308fc055c9d1d3b109749f94a938a51985338722ae88e7d6b140f3a23969c
 * EXTENT MEASURED, NOT RECONSTRUCTED: 6 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8006e644  00a41806  special&0x06 $v1,$a1,$a0
 * 0x8006e648  8cc40000  lw $a0,0($a2)
 * 0x8006e64c  00031827  special&0x27 $v1,$zero,$v1
 * 0x8006e650  00832024  and $a0,$a0,$v1
 * 0x8006e654  03e00008  jr $ra
 * 0x8006e658  acc40000  sw $a0,0($a2)
 */
