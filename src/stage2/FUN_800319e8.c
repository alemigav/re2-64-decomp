/* FUN_800319e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800319e8  body 0x800319e8..0x80031a17  size 48 B
 * body sha256 6d24a0484b5770968fe77ef9f3c10c0c21c07411f84320969af9e20788e8f055
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800319e8  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x800319ec  1560fffe  bne $t3,$zero,-2
 * 0x800319f0  00000000  sll $zero,$zero,0
 * 0x800319f4  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x800319f8  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x800319fc  40881800  cop0 rs=4 rt=$t0 rd=3
 * 0x80031a00  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80031a04  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80031a08  1560fffe  bne $t3,$zero,-2
 * 0x80031a0c  00000000  sll $zero,$zero,0
 * 0x80031a10  03e00008  jr $ra
 * 0x80031a14  00000000  sll $zero,$zero,0
 */
