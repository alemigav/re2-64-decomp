/* FUN_800218d0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800218d0  body 0x800218d0..0x80021a67  size 408 B
 * body sha256 fa9a3468c151fc565e97aba12d3e89b534d1340064bbc9f30d224c187f633055
 * EXTENT MEASURED, NOT RECONSTRUCTED: 102 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800218d0  04200021  op&0x01 $zero,$at,0x0021
 * 0x800218d4  00000000  sll $zero,$zero,0
 * 0x800218d8  14200012  bne $at,$zero,+18
 * 0x800218dc  035bd020  add $k0,$k0,$k1
 * 0x800218e0  8f7809f4  lw $t8,2548($k1)
 * 0x800218e4  ac1a0ff0  sw $k0,4080($zero)
 * 0x800218e8  ac180fd0  sw $t8,4048($zero)
 * 0x800218ec  24141080  addiu $s4,$zero,0x1080
 * 0x800218f0  0c0007f6  jal 0x80001fd8
 * 0x800218f4  20130f47  op&0x08 $s3,$zero,0x0f47
 * 0x800218f8  400b5800  cop0 rs=0 rt=$t3 rd=11
 * 0x800218fc  316b0100  andi $t3,$t3,0x0100
 * 0x80021900  1560fffd  bne $t3,$zero,-3
 * 0x80021904  8c1800d8  lw $t8,216($zero)
 * 0x80021908  24140180  addiu $s4,$zero,0x0180
 * 0x8002190c  33330fff  andi $s3,$t9,0x0fff
 * 0x80021910  0314c020  add $t8,$t8,$s4
 * 0x80021914  0c0007f6  jal 0x80001fd8
 * 0x80021918  02749822  sub $s3,$s3,$s4
 * 0x8002191c  080007f2  j 0x80001fc8
 * 0x80021920  201f1084  op&0x08 $ra,$zero,0x1084
 * 0x80021924  8c0b0fd0  lw $t3,4048($zero)
 * 0x80021928  ac1a0950  sw $k0,2384($zero)
 * 0x8002192c  ac0b0954  sw $t3,2388($zero)
 * 0x80021930  8c180ff8  lw $t8,4088($zero)
 * 0x80021934  20148000  op&0x08 $s4,$zero,0x8000
 * 0x80021938  0c0007f6  jal 0x80001fd8
 * 0x8002193c  2013090f  op&0x08 $s3,$zero,0x090f
 * 0x80021940  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x80021944  27180bf8  addiu $t8,$t8,0x0bf8
 * 0x80021948  20148950  op&0x08 $s4,$zero,0x8950
 * 0x8002194c  20130007  op&0x08 $s3,$zero,0x0007
 * 0x80021950  080007f6  j 0x80001fd8
 * 0x80021954  201f108c  op&0x08 $ra,$zero,0x108c
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
 * 0x800219a0  200b1140  op&0x08 $t3,$zero,0x1140
 * 0x800219a4  ad79f0a4  sw $t9,-3932($t3)
 * 0x800219a8  08000463  j 0x8000118c
 * 0x800219ac  ad78f0a8  sw $t8,-3928($t3)
 * 0x800219b0  00191402  srl $v0,$t9,16
 * 0x800219b4  944127fe  lhu $at,10238($v0)
 * 0x800219b8  00390820  add $at,$at,$t9
 * 0x800219bc  08000463  j 0x8000118c
 * 0x800219c0  ac380000  sw $t8,0($at)
 * 0x800219c4  8c0b00f4  lw $t3,244($zero)
 * 0x800219c8  8c020fe0  lw $v0,4064($zero)
 * 0x800219cc  0178c022  sub $t8,$t3,$t8
 * 0x800219d0  03020822  sub $at,$t8,$v0
 * 0x800219d4  04210002  op&0x01 $at,$at,0x0002
 * 0x800219d8  00000000  sll $zero,$zero,0
 * 0x800219dc  34580000  ori $t8,$v0,0x0000
 * 0x800219e0  130b0048  beq $t8,$t3,+72
 * 0x800219e4  ac1800f4  sw $t8,244($zero)
 * 0x800219e8  08000449  j 0x80001124
 * 0x800219ec  ac0001d9  sw $zero,473($zero)
 * 0x800219f0  943302f2  lhu $s3,754($at)
 * 0x800219f4  0c0007f2  jal 0x80001fc8
 * 0x800219f8  943502f2  lhu $s5,754($at)
 * 0x800219fc  201f118c  op&0x08 $ra,$zero,0x118c
 * 0x80021a00  228c0018  op&0x08 $t4,$s4,0x0018
 * 0x80021a04  4b00024e  op&0x12 $zero,$t8,0x024e
 * 0x80021a08  228b0008  op&0x08 $t3,$s4,0x0008
 * 0x80021a0c  4b00020f  op&0x12 $zero,$t8,0x020f
 * 0x80021a10  22b5ffe0  op&0x08 $s5,$s5,0xffe0
 * 0x80021a14  4b000747  op&0x12 $zero,$t8,0x0747
 * 0x80021a18  caa51808  op&0x32 $a1,$s5,0x1808
 * 0x80021a1c  caa51c08  op&0x32 $a1,$s5,0x1c08
 * 0x80021a20  ca832002  op&0x32 $v1,$s4,0x2002
 * 0x80021a24  caa41804  op&0x32 $a0,$s5,0x1804
 * 0x80021a28  caa41c04  op&0x32 $a0,$s5,0x1c04
 * 0x80021a2c  ca822000  op&0x32 $v0,$s4,0x2000
 * 0x80021a30  4a832f4c  op&0x12 $v1,$s4,0x2f4c
 * 0x80021a34  22940002  op&0x08 $s4,$s4,0x0002
 * 0x80021a38  4a83274d  op&0x12 $v1,$s4,0x274d
 * 0x80021a3c  22b50008  op&0x08 $s5,$s5,0x0008
 * 0x80021a40  4a8229ce  op&0x12 $v0,$s4,0x29ce
 * 0x80021a44  168bfff4  bne $s4,$t3,-12
 * 0x80021a48  4a82218f  op&0x12 $v0,$s4,0x218f
 * 0x80021a4c  168cffed  bne $s4,$t4,-19
 * 0x80021a50  22940008  op&0x08 $s4,$s4,0x0008
 * 0x80021a54  ea692002  op&0x3a $t1,$s3,0x2002
 * 0x80021a58  ea682000  op&0x3a $t0,$s3,0x2000
 * 0x80021a5c  ea672003  op&0x3a $a3,$s3,0x2003
 * 0x80021a60  03e00008  jr $ra
 * 0x80021a64  ea662001  op&0x3a $a2,$s3,0x2001
 */
