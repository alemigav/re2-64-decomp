/* FUN_800218ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800218ac  body 0x800218ac..0x800218c7  size 28 B
 * body sha256 16fbbc7244aee7878edb08323fe71d0d4fb7ebcf51c508059a3ba1a95bcaec1d
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
 * 0x800218ac  1560ffff  bne $t3,$zero,-1
 * 0x800218b0  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x800218b4  40940000  cop0 rs=4 rt=$s4 rd=0
 * 0x800218b8  06800003  op&0x01 $zero,$s4,0x0003
 * 0x800218bc  40980800  cop0 rs=4 rt=$t8 rd=1
 * 0x800218c0  03e00008  jr $ra
 * 0x800218c4  40931000  cop0 rs=4 rt=$s3 rd=2
 */
