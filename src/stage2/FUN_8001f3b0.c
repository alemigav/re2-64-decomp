/* FUN_8001f3b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f3b0  body 0x8001f3b0..0x8001f537  size 392 B
 * body sha256 6c1f41bc08cf12e73b838aad6081ddba77524b69dd575331b5e0857d517a169a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 98 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8001f3b0  02f65822  sub $t3,$s7,$s6
 * 0x8001f3b4  256c0157  addiu $t4,$t3,0x0157
 * 0x8001f3b8  05910094  op&0x01 $s1,$t4,0x0094
 * 0x8001f3bc  00000000  sll $zero,$zero,0
 * 0x8001f3c0  0c0007f2  jal 0x80001fc8
 * 0x8001f3c4  8c1800f0  lw $t8,240($zero)
 * 0x8001f3c8  0420001a  op&0x01 $zero,$at,0x001a
 * 0x8001f3cc  40984800  cop0 rs=4 rt=$t8 rd=9
 * 0x8001f3d0  1420000f  bne $at,$zero,+15
 * 0x8001f3d4  035bd020  add $k0,$k0,$k1
 * 0x8001f3d8  8f7809c4  lw $t8,2500($k1)
 * 0x8001f3dc  ac1a0ff0  sw $k0,4080($zero)
 * 0x8001f3e0  ac180fd0  sw $t8,4048($zero)
 * 0x8001f3e4  24141080  addiu $s4,$zero,0x1080
 * 0x8001f3e8  0c0007f6  jal 0x80001fd8
 * 0x8001f3ec  20130f47  op&0x08 $s3,$zero,0x0f47
 * 0x8001f3f0  8c1800d8  lw $t8,216($zero)
 * 0x8001f3f4  24140180  addiu $s4,$zero,0x0180
 * 0x8001f3f8  33330fff  andi $s3,$t9,0x0fff
 * 0x8001f3fc  0314c020  add $t8,$t8,$s4
 * 0x8001f400  0c0007f6  jal 0x80001fd8
 * 0x8001f404  02749822  sub $s3,$s3,$s4
 * 0x8001f408  080007f2  j 0x80001fc8
 * 0x8001f40c  201f1084  op&0x08 $ra,$zero,0x1084
 * 0x8001f410  8c0b0fd0  lw $t3,4048($zero)
 * 0x8001f414  ac1a0bf8  sw $k0,3064($zero)
 * 0x8001f418  ac0b0bfc  sw $t3,3068($zero)
 * 0x8001f41c  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x8001f420  8c180ff8  lw $t8,4088($zero)
 * 0x8001f424  20148000  op&0x08 $s4,$zero,0x8000
 * 0x8001f428  20130bff  op&0x08 $s3,$zero,0x0bff
 * 0x8001f42c  080007f6  j 0x80001fd8
 * 0x8001f430  201f1088  op&0x08 $ra,$zero,0x1088
 * 0x8001f434  200c4000  op&0x08 $t4,$zero,0x4000
 * 0x8001f438  408c2000  cop0 rs=4 rt=$t4 rd=4
 * 0x8001f43c  0000000d  special&0x0d $zero,$zero,$zero
 * 0x8001f440  00000000  sll $zero,$zero,0
 * 0x8001f444  00000000  sll $zero,$zero,0
 * 0x8001f448  900100de  lbu $at,222($zero)
 * 0x8001f44c  001913c0  sll $v0,$t9,15
 * 0x8001f450  0c000487  jal 0x8000121c
 * 0x8001f454  035b1820  add $v1,$k0,$k1
 * 0x8001f458  04400057  op&0x01 $zero,$v0,0x0057
 * 0x8001f45c  371a0000  ori $k0,$t8,0x0000
 * 0x8001f460  ac230138  sw $v1,312($at)
 * 0x8001f464  20210004  op&0x08 $at,$at,0x0004
 * 0x8001f468  0800045c  j 0x80001170
 * 0x8001f46c  a00100de  sb $at,222($zero)
 * 0x8001f470  200b1140  op&0x08 $t3,$zero,0x1140
 * 0x8001f474  ad79f0a4  sw $t9,-3932($t3)
 * 0x8001f478  08000463  j 0x8000118c
 * 0x8001f47c  ad78f0a8  sw $t8,-3928($t3)
 * 0x8001f480  00191402  srl $v0,$t9,16
 * 0x8001f484  944127fe  lhu $at,10238($v0)
 * 0x8001f488  00390820  add $at,$at,$t9
 * 0x8001f48c  08000463  j 0x8000118c
 * 0x8001f490  ac380000  sw $t8,0($at)
 * 0x8001f494  8c0b00f4  lw $t3,244($zero)
 * 0x8001f498  8c020fe0  lw $v0,4064($zero)
 * 0x8001f49c  0178c022  sub $t8,$t3,$t8
 * 0x8001f4a0  03020822  sub $at,$t8,$v0
 * 0x8001f4a4  04210002  op&0x01 $at,$at,0x0002
 * 0x8001f4a8  00000000  sll $zero,$zero,0
 * 0x8001f4ac  34580000  ori $t8,$v0,0x0000
 * 0x8001f4b0  130b0048  beq $t8,$t3,+72
 * 0x8001f4b4  ac1800f4  sw $t8,244($zero)
 * 0x8001f4b8  08000449  j 0x80001124
 * 0x8001f4bc  ac0001d9  sw $zero,473($zero)
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
