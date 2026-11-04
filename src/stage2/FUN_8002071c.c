/* FUN_8002071c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002071c  body 0x8002071c..0x80020737  size 28 B
 * body sha256 20e7b3915812bc0947bdbab93eb61ee6727586d1626e935f6add7e0bf8eadd6e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 7 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8002071c  1560ffff  bne $t3,$zero,-1
 * 0x80020720  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80020724  40940000  cop0 rs=4 rt=$s4 rd=0
 * 0x80020728  06800003  op&0x01 $zero,$s4,0x0003
 * 0x8002072c  40980800  cop0 rs=4 rt=$t8 rd=1
 * 0x80020730  03e00008  jr $ra
 * 0x80020734  40931000  cop0 rs=4 rt=$s3 rd=2
 */
