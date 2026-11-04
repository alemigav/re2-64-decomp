/* FUN_80164e50
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x80164e50  body 0x80164e50..0x80164e93  size 68 B
 * body sha256 936f1c4e38d9aca9b25d50ad92bb57738ba1e0cc716bfc732b2089f353ccccb0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 17 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80164e50  94820270  lhu $v0,624($a0)
 * 0x80164e54  30420010  andi $v0,$v0,0x0010
 * 0x80164e58  1040000c  beq $v0,$zero,+12
 * 0x80164e5c  3c020101  lui $v0,0x0101
 * 0x80164e60  3c038017  lui $v1,0x8017
 * 0x80164e64  ac820004  sw $v0,4($a0)
 * 0x80164e68  94820270  lhu $v0,624($a0)
 * 0x80164e6c  24639894  addiu $v1,$v1,0x9894
 * 0x80164e70  3042000f  andi $v0,$v0,0x000f
 * 0x80164e74  00021080  sll $v0,$v0,2
 * 0x80164e78  00431021  addu $v0,$v0,$v1
 * 0x80164e7c  84430000  lh $v1,0($v0)
 * 0x80164e80  ac830028  sw $v1,40($a0)
 * 0x80164e84  84420002  lh $v0,2($v0)
 * 0x80164e88  ac820030  sw $v0,48($a0)
 * 0x80164e8c  03e00008  jr $ra
 * 0x80164e90  00000000  sll $zero,$zero,0
 */
