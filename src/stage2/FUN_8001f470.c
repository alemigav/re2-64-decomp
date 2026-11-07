/* FUN_8001f470
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f470  body 0x8001f470..0x8001f47f  size 16 B
 * body sha256 f5cb4c5e97cd100dcf5fc7af76b17ecb47e84fadf7ccba9a082dd9f8c7c0d189
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8001f470  200b1140  op&0x08 $t3,$zero,0x1140
 * 0x8001f474  ad79f0a4  sw $t9,-3932($t3)
 * 0x8001f478  08000463  j 0x8000118c
 * 0x8001f47c  ad78f0a8  sw $t8,-3928($t3)
 */
