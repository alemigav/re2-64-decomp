/* FUN_80184a7c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80184a7c  body 0x80184a7c..0x80184ab7  size 60 B
 * body sha256 355c0636d8b0df17c9f8d1e6d7ea602046c85d4ff640a5e12de7d16bbd15a6b4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 15 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80184a7c  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x80184a80  1560fffe  bne $t3,$zero,-2
 * 0x80184a84  00000000  sll $zero,$zero,0
 * 0x80184a88  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80184a8c  1560fffe  bne $t3,$zero,-2
 * 0x80184a90  00000000  sll $zero,$zero,0
 * 0x80184a94  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x80184a98  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x80184a9c  40881800  cop0 rs=4 rt=$t0 rd=3
 * 0x80184aa0  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184aa4  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80184aa8  1560fffe  bne $t3,$zero,-2
 * 0x80184aac  00000000  sll $zero,$zero,0
 * 0x80184ab0  03e00008  jr $ra
 * 0x80184ab4  40803800  cop0 rs=4 rt=$zero rd=7
 */
