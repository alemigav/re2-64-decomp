/* FUN_80184934
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80184934  body 0x80184934..0x8018496f  size 60 B
 * body sha256 b722e2ae0b6423ffc0797acb11212b20e2a55a90e5d8d72f0b2d2863ace2daa9
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
 * 0x80184934  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x80184938  1560fffe  bne $t3,$zero,-2
 * 0x8018493c  00000000  sll $zero,$zero,0
 * 0x80184940  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80184944  1560fffe  bne $t3,$zero,-2
 * 0x80184948  00000000  sll $zero,$zero,0
 * 0x8018494c  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x80184950  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x80184954  40881800  cop0 rs=4 rt=$t0 rd=3
 * 0x80184958  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x8018495c  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80184960  1560fffe  bne $t3,$zero,-2
 * 0x80184964  00000000  sll $zero,$zero,0
 * 0x80184968  03e00008  jr $ra
 * 0x8018496c  40803800  cop0 rs=4 rt=$zero rd=7
 */
