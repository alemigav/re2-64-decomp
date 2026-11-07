/* FUN_80037310
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80037310  body 0x80037310..0x8003736f  size 96 B
 * body sha256 d749badcb8f539acca964029fd6b36d4bbdfb9540505c8a359d1116fa9fbd9d6
 * EXTENT MEASURED, NOT RECONSTRUCTED: 24 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80037310..0x8003736f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80037310  94820064  lhu $v0,100($a0)
 * 0x80037314  a4c20000  sh $v0,0($a2)
 * 0x80037318  94820066  lhu $v0,102($a0)
 * 0x8003731c  a4c20002  sh $v0,2($a2)
 * 0x80037320  94820068  lhu $v0,104($a0)
 * 0x80037324  0800dccc  j 0x80037330
 * 0x80037328  a4c20004  sh $v0,4($a2)
 * 0x8003732c  8ca5012c  lw $a1,300($a1)
 * 0x80037330  94c20000  lhu $v0,0($a2)
 * 0x80037334  94a30058  lhu $v1,88($a1)
 * 0x80037338  00431021  addu $v0,$v0,$v1
 * 0x8003733c  a4c20000  sh $v0,0($a2)
 * 0x80037340  94c20002  lhu $v0,2($a2)
 * 0x80037344  94a3005a  lhu $v1,90($a1)
 * 0x80037348  00431021  addu $v0,$v0,$v1
 * 0x8003734c  a4c20002  sh $v0,2($a2)
 * 0x80037350  94c20004  lhu $v0,4($a2)
 * 0x80037354  94a3005c  lhu $v1,92($a1)
 * 0x80037358  00431021  addu $v0,$v0,$v1
 * 0x8003735c  a4c20004  sh $v0,4($a2)
 * 0x80037360  8c820234  lw $v0,564($a0)
 * 0x80037364  14a2fff1  bne $a1,$v0,-15
 * 0x80037368  00000000  sll $zero,$zero,0
 * 0x8003736c  03e00008  jr $ra
 */
