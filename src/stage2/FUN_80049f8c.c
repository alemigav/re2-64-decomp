/* FUN_80049f8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049f8c  body 0x80049f8c..0x80049f97  size 12 B
 * body sha256 fa6341713cfa5161245ed15df103ee48bb668c1596f06ac4e511e0e728f99ab8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 3 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80049f8c  00000000  sll $zero,$zero,0
 * 0x80049f90  03e00008  jr $ra
 * 0x80049f94  00a01021  addu $v0,$a1,$zero
 */
