/* FUN_80020740
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80020740  body 0x80020740..0x800208c7  size 392 B
 * body sha256 5fa2309f30a1fc8833c8c99be552e1e33ecfa74e81471db3c4f7be9513a60af4
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
 * 0x80020740  02f65822  sub $t3,$s7,$s6
 * 0x80020744  256c024f  addiu $t4,$t3,0x024f
 * 0x80020748  05910094  op&0x01 $s1,$t4,0x0094
 * 0x8002074c  00000000  sll $zero,$zero,0
 * 0x80020750  0c0007f2  jal 0x80001fc8
 * 0x80020754  8c1800f0  lw $t8,240($zero)
 * 0x80020758  0420001a  op&0x01 $zero,$at,0x001a
 * 0x8002075c  40984800  cop0 rs=4 rt=$t8 rd=9
 * 0x80020760  1420000f  bne $at,$zero,+15
 * 0x80020764  035bd020  add $k0,$k0,$k1
 * 0x80020768  8f7809b4  lw $t8,2484($k1)
 * 0x8002076c  ac1a0ff0  sw $k0,4080($zero)
 * 0x80020770  ac180fd0  sw $t8,4048($zero)
 * 0x80020774  24141080  addiu $s4,$zero,0x1080
 * 0x80020778  0c0007f6  jal 0x80001fd8
 * 0x8002077c  20130f47  op&0x08 $s3,$zero,0x0f47
 * 0x80020780  8c1800d8  lw $t8,216($zero)
 * 0x80020784  24140180  addiu $s4,$zero,0x0180
 * 0x80020788  33330fff  andi $s3,$t9,0x0fff
 * 0x8002078c  0314c020  add $t8,$t8,$s4
 * 0x80020790  0c0007f6  jal 0x80001fd8
 * 0x80020794  02749822  sub $s3,$s3,$s4
 * 0x80020798  080007f2  j 0x80001fc8
 * 0x8002079c  201f1084  op&0x08 $ra,$zero,0x1084
 * 0x800207a0  8c0b0fd0  lw $t3,4048($zero)
 * 0x800207a4  ac1a0bf8  sw $k0,3064($zero)
 * 0x800207a8  ac0b0bfc  sw $t3,3068($zero)
 * 0x800207ac  200c5000  op&0x08 $t4,$zero,0x5000
 * 0x800207b0  8c180ff8  lw $t8,4088($zero)
 * 0x800207b4  20148000  op&0x08 $s4,$zero,0x8000
 * 0x800207b8  20130bff  op&0x08 $s3,$zero,0x0bff
 * 0x800207bc  080007f6  j 0x80001fd8
 * 0x800207c0  201f1088  op&0x08 $ra,$zero,0x1088
 * 0x800207c4  200c4000  op&0x08 $t4,$zero,0x4000
 * 0x800207c8  408c2000  cop0 rs=4 rt=$t4 rd=4
 * 0x800207cc  0000000d  special&0x0d $zero,$zero,$zero
 * 0x800207d0  00000000  sll $zero,$zero,0
 * 0x800207d4  00000000  sll $zero,$zero,0
 * 0x800207d8  900100de  lbu $at,222($zero)
 * 0x800207dc  001913c0  sll $v0,$t9,15
 * 0x800207e0  0c000487  jal 0x8000121c
 * 0x800207e4  035b1820  add $v1,$k0,$k1
 * 0x800207e8  04400057  op&0x01 $zero,$v0,0x0057
 * 0x800207ec  371a0000  ori $k0,$t8,0x0000
 * 0x800207f0  ac230138  sw $v1,312($at)
 * 0x800207f4  20210004  op&0x08 $at,$at,0x0004
 * 0x800207f8  0800045c  j 0x80001170
 * 0x800207fc  a00100de  sb $at,222($zero)
 * 0x80020800  200b1140  op&0x08 $t3,$zero,0x1140
 * 0x80020804  ad79f0a4  sw $t9,-3932($t3)
 * 0x80020808  08000463  j 0x8000118c
 * 0x8002080c  ad78f0a8  sw $t8,-3928($t3)
 * 0x80020810  00191402  srl $v0,$t9,16
 * 0x80020814  944127fe  lhu $at,10238($v0)
 * 0x80020818  00390820  add $at,$at,$t9
 * 0x8002081c  08000463  j 0x8000118c
 * 0x80020820  ac380000  sw $t8,0($at)
 * 0x80020824  8c0b00f4  lw $t3,244($zero)
 * 0x80020828  8c020fe0  lw $v0,4064($zero)
 * 0x8002082c  0178c022  sub $t8,$t3,$t8
 * 0x80020830  03020822  sub $at,$t8,$v0
 * 0x80020834  04210002  op&0x01 $at,$at,0x0002
 * 0x80020838  00000000  sll $zero,$zero,0
 * 0x8002083c  34580000  ori $t8,$v0,0x0000
 * 0x80020840  130b0048  beq $t8,$t3,+72
 * 0x80020844  ac1800f4  sw $t8,244($zero)
 * 0x80020848  08000449  j 0x80001124
 * 0x8002084c  ac0001d9  sw $zero,473($zero)
 * 0x80020850  943302f2  lhu $s3,754($at)
 * 0x80020854  0c0007f2  jal 0x80001fc8
 * 0x80020858  943502f2  lhu $s5,754($at)
 * 0x8002085c  201f118c  op&0x08 $ra,$zero,0x118c
 * 0x80020860  228c0018  op&0x08 $t4,$s4,0x0018
 * 0x80020864  4b00024e  op&0x12 $zero,$t8,0x024e
 * 0x80020868  228b0008  op&0x08 $t3,$s4,0x0008
 * 0x8002086c  4b00020f  op&0x12 $zero,$t8,0x020f
 * 0x80020870  22b5ffe0  op&0x08 $s5,$s5,0xffe0
 * 0x80020874  4b000747  op&0x12 $zero,$t8,0x0747
 * 0x80020878  caa51808  op&0x32 $a1,$s5,0x1808
 * 0x8002087c  caa51c08  op&0x32 $a1,$s5,0x1c08
 * 0x80020880  ca832002  op&0x32 $v1,$s4,0x2002
 * 0x80020884  caa41804  op&0x32 $a0,$s5,0x1804
 * 0x80020888  caa41c04  op&0x32 $a0,$s5,0x1c04
 * 0x8002088c  ca822000  op&0x32 $v0,$s4,0x2000
 * 0x80020890  4a832f4c  op&0x12 $v1,$s4,0x2f4c
 * 0x80020894  22940002  op&0x08 $s4,$s4,0x0002
 * 0x80020898  4a83274d  op&0x12 $v1,$s4,0x274d
 * 0x8002089c  22b50008  op&0x08 $s5,$s5,0x0008
 * 0x800208a0  4a8229ce  op&0x12 $v0,$s4,0x29ce
 * 0x800208a4  168bfff4  bne $s4,$t3,-12
 * 0x800208a8  4a82218f  op&0x12 $v0,$s4,0x218f
 * 0x800208ac  168cffed  bne $s4,$t4,-19
 * 0x800208b0  22940008  op&0x08 $s4,$s4,0x0008
 * 0x800208b4  ea692002  op&0x3a $t1,$s3,0x2002
 * 0x800208b8  ea682000  op&0x3a $t0,$s3,0x2000
 * 0x800208bc  ea672003  op&0x3a $a3,$s3,0x2003
 * 0x800208c0  03e00008  jr $ra
 * 0x800208c4  ea662001  op&0x3a $a2,$s3,0x2001
 */
