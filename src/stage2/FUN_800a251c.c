/* FUN_800a251c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a251c  body 0x800a251c..0x800a254f  size 52 B
 * body sha256 ae9385272264d8b58db0f6ab8d5cc82bb15ee34f87a56dd8f8e3797438fc3da0
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
 * 0x800a251c  3442ffff  ori $v0,$v0,0xffff
 * 0x800a2520  00c23024  and $a2,$a2,$v0
 * 0x800a2524  3c038014  lui $v1,0x8014
 * 0x800a2528  2463bc90  addiu $v1,$v1,0xbc90
 * 0x800a252c  00061240  sll $v0,$a2,9
 * 0x800a2530  00461023  subu $v0,$v0,$a2
 * 0x800a2534  000210c0  sll $v0,$v0,3
 * 0x800a2538  00431021  addu $v0,$v0,$v1
 * 0x800a253c  90430fee  lbu $v1,4078($v0)
 * 0x800a2540  a4450fec  sh $a1,4076($v0)
 * 0x800a2544  34630020  ori $v1,$v1,0x0020
 * 0x800a2548  a0430fee  sb $v1,4078($v0)
 * 0x800a254c  03e00008  jr $ra
 */
