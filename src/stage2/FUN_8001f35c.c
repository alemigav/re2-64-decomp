/* FUN_8001f35c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f35c  body 0x8001f35c..0x8001f38b  size 48 B
 * body sha256 d0bb9ee5947f976ddcb0b6294accbc73052389189b663b4efde72a63fbf2a1df
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
 * 0x8001f35c  200c1000  op&0x08 $t4,$zero,0x1000
 * 0x8001f360  200b02e0  op&0x08 $t3,$zero,0x02e0
 * 0x8001f364  8d780000  lw $t8,0($t3)
 * 0x8001f368  95730004  lhu $s3,4($t3)
 * 0x8001f36c  0c0007f6  jal 0x80001fd8
 * 0x8001f370  95740006  lhu $s4,6($t3)
 * 0x8001f374  359f0000  ori $ra,$t4,0x0000
 * 0x8001f378  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x8001f37c  1560ffff  bne $t3,$zero,-1
 * 0x8001f380  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x8001f384  03e00008  jr $ra
 * 0x8001f388  400b2800  cop0 rs=0 rt=$t3 rd=5
 */
