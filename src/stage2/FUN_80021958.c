/* FUN_80021958
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80021958  body 0x80021958..0x8002199f  size 72 B
 * body sha256 a1a9ad797f72cc9f2403a0927839ee284d393044816d59b2e350102180a878cf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80021958  200c4000  op&0x08 $t4,$zero,0x4000
 * 0x8002195c  400b5800  cop0 rs=0 rt=$t3 rd=11
 * 0x80021960  316b0100  andi $t3,$t3,0x0100
 * 0x80021964  1560fffd  bne $t3,$zero,-3
 * 0x80021968  00000000  sll $zero,$zero,0
 * 0x8002196c  408c2000  cop0 rs=4 rt=$t4 rd=4
 * 0x80021970  0000000d  special&0x0d $zero,$zero,$zero
 * 0x80021974  00000000  sll $zero,$zero,0
 * 0x80021978  900100de  lbu $at,222($zero)
 * 0x8002197c  001913c0  sll $v0,$t9,15
 * 0x80021980  0c000487  jal 0x8000121c
 * 0x80021984  035b1820  add $v1,$k0,$k1
 * 0x80021988  04400057  op&0x01 $zero,$v0,0x0057
 * 0x8002198c  371a0000  ori $k0,$t8,0x0000
 * 0x80021990  ac230138  sw $v1,312($at)
 * 0x80021994  20210004  op&0x08 $at,$at,0x0004
 * 0x80021998  0800045c  j 0x80001170
 * 0x8002199c  a00100de  sb $at,222($zero)
 */
