/* FUN_8001f4c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f4c0  body 0x8001f4c0..0x8001f537  size 120 B
 * body sha256 0902c7a96efc85f95679fed793545cd20d7d09a8e580889121c6bc09cb6b3a9d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 30 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8001f4c0  943302f2  lhu $s3,754($at)
 * 0x8001f4c4  0c0007f2  jal 0x80001fc8
 * 0x8001f4c8  943502f2  lhu $s5,754($at)
 * 0x8001f4cc  201f118c  op&0x08 $ra,$zero,0x118c
 * 0x8001f4d0  228c0018  op&0x08 $t4,$s4,0x0018
 * 0x8001f4d4  4b00024e  op&0x12 $zero,$t8,0x024e
 * 0x8001f4d8  228b0008  op&0x08 $t3,$s4,0x0008
 * 0x8001f4dc  4b00020f  op&0x12 $zero,$t8,0x020f
 * 0x8001f4e0  22b5ffe0  op&0x08 $s5,$s5,0xffe0
 * 0x8001f4e4  4b000747  op&0x12 $zero,$t8,0x0747
 * 0x8001f4e8  caa51808  op&0x32 $a1,$s5,0x1808
 * 0x8001f4ec  caa51c08  op&0x32 $a1,$s5,0x1c08
 * 0x8001f4f0  ca832002  op&0x32 $v1,$s4,0x2002
 * 0x8001f4f4  caa41804  op&0x32 $a0,$s5,0x1804
 * 0x8001f4f8  caa41c04  op&0x32 $a0,$s5,0x1c04
 * 0x8001f4fc  ca822000  op&0x32 $v0,$s4,0x2000
 * 0x8001f500  4a832f4c  op&0x12 $v1,$s4,0x2f4c
 * 0x8001f504  22940002  op&0x08 $s4,$s4,0x0002
 * 0x8001f508  4a83274d  op&0x12 $v1,$s4,0x274d
 * 0x8001f50c  22b50008  op&0x08 $s5,$s5,0x0008
 * 0x8001f510  4a8229ce  op&0x12 $v0,$s4,0x29ce
 * 0x8001f514  168bfff4  bne $s4,$t3,-12
 * 0x8001f518  4a82218f  op&0x12 $v0,$s4,0x218f
 * 0x8001f51c  168cffed  bne $s4,$t4,-19
 * 0x8001f520  22940008  op&0x08 $s4,$s4,0x0008
 * 0x8001f524  ea692002  op&0x3a $t1,$s3,0x2002
 * 0x8001f528  ea682000  op&0x3a $t0,$s3,0x2000
 * 0x8001f52c  ea672003  op&0x3a $a3,$s3,0x2003
 * 0x8001f530  03e00008  jr $ra
 * 0x8001f534  ea662001  op&0x3a $a2,$s3,0x2001
 */
