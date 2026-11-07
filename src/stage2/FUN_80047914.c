/* FUN_80047914
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047914  body 0x80047914..0x8004794b  size 56 B
 * body sha256 feee874af9f7a487008768d40d09a9f67a446edde2b8363431e6400c74994121
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80047914..0x8004794b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80047914  97a20012  lhu $v0,18($sp)
 * 0x80047918  97a30016  lhu $v1,22($sp)
 * 0x8004791c  97a8001a  lhu $t0,26($sp)
 * 0x80047920  97a9001e  lhu $t1,30($sp)
 * 0x80047924  97aa0022  lhu $t2,34($sp)
 * 0x80047928  a0850008  sb $a1,8($a0)
 * 0x8004792c  a0860009  sb $a2,9($a0)
 * 0x80047930  a0870014  sb $a3,20($a0)
 * 0x80047934  a0820015  sb $v0,21($a0)
 * 0x80047938  a0830020  sb $v1,32($a0)
 * 0x8004793c  a0880021  sb $t0,33($a0)
 * 0x80047940  a089002c  sb $t1,44($a0)
 * 0x80047944  03e00008  jr $ra
 * 0x80047948  a08a002d  sb $t2,45($a0)
 */
