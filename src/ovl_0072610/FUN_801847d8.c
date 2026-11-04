/* FUN_801847d8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801847d8  body 0x801847d8..0x80184933  size 348 B
 * body sha256 16df52a7f0f5c9c1d50d5131339b6e4c70b4521ad324de888b274d93106344b0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 87 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x801847d8  00000000  sll $zero,$zero,0
 * 0x801847dc  00000000  sll $zero,$zero,0
 * 0x801847e0  8c0c0000  lw $t4,0($zero)
 * 0x801847e4  8c0d0004  lw $t5,4($zero)
 * 0x801847e8  8c0e0008  lw $t6,8($zero)
 * 0x801847ec  8c0f000c  lw $t7,12($zero)
 * 0x801847f0  8c100010  lw $s0,16($zero)
 * 0x801847f4  8c110014  lw $s1,20($zero)
 * 0x801847f8  8c120018  lw $s2,24($zero)
 * 0x801847fc  8c13001c  lw $s3,28($zero)
 * 0x80184800  c80a2002  op&0x32 $t2,$zero,0x2002
 * 0x80184804  4a000011  op&0x12 $zero,$s0,0x0011
 * 0x80184808  4a094a51  op&0x12 $t1,$s0,0x4a51
 * 0x8018480c  21f7ffff  op&0x08 $s7,$t7,0xffff
 * 0x80184810  10000003  beq $zero,$zero,+3
 * 0x80184814  0017bb00  sll $s7,$s7,12
 * 0x80184818  2237ffff  op&0x08 $s7,$s1,0xffff
 * 0x8018481c  0017bb00  sll $s7,$s7,12
 * 0x80184820  02574025  or $t0,$s2,$s7
 * 0x80184824  200a0000  op&0x08 $t2,$zero,0x0000
 * 0x80184828  06f10033  op&0x01 $s1,$s7,0x0033
 * 0x8018482c  000c4820  add $t1,$zero,$t4
 * 0x80184830  200a0800  op&0x08 $t2,$zero,0x0800
 * 0x80184834  05110030  op&0x01 $s1,$t0,0x0030
 * 0x80184838  000d4820  add $t1,$zero,$t5
 * 0x8018483c  20150000  op&0x08 $s5,$zero,0x0000
 * 0x80184840  20160800  op&0x08 $s6,$zero,0x0800
 * 0x80184844  000ea020  add $s4,$zero,$t6
 * 0x80184848  caa12000  op&0x32 $at,$s5,0x2000
 * 0x8018484c  cac22000  op&0x32 $v0,$s6,0x2000
 * 0x80184850  4b0a08e8  op&0x12 $t2,$t8,0x08e8
 * 0x80184854  4b2a0928  op&0x12 $t2,$t9,0x0928
 * 0x80184858  4b4a0968  op&0x12 $t2,$k0,0x0968
 * 0x8018485c  4b0a11a8  op&0x12 $t2,$t8,0x11a8
 * 0x80184860  4b2a11e8  op&0x12 $t2,$t9,0x11e8
 * 0x80184864  4b4a1228  op&0x12 $t2,$k0,0x1228
 * 0x80184868  4a0618d4  op&0x12 $a2,$s0,0x18d4
 * 0x8018486c  4a004a50  op&0x12 $zero,$s0,0x4a50
 * 0x80184870  4a072110  op&0x12 $a3,$s0,0x2110
 * 0x80184874  4a082950  op&0x12 $t0,$s0,0x2950
 * 0x80184878  4baa18d4  op&0x12 $t2,$sp,0x18d4
 * 0x8018487c  4a004a50  op&0x12 $zero,$s0,0x4a50
 * 0x80184880  4bca2110  op&0x12 $t2,$fp,0x2110
 * 0x80184884  4bea2950  op&0x12 $t2,$ra,0x2950
 * 0x80184888  4b8a18c4  op&0x12 $t2,$gp,0x18c4
 * 0x8018488c  4b8a4a4d  op&0x12 $t2,$gp,0x4a4d
 * 0x80184890  4b0000ce  op&0x12 $zero,$t8,0x00ce
 * 0x80184894  4b8a2105  op&0x12 $t2,$gp,0x2105
 * 0x80184898  4b8a2945  op&0x12 $t2,$gp,0x2945
 * 0x8018489c  4b0a18e8  op&0x12 $t2,$t8,0x18e8
 * 0x801848a0  4b2a2128  op&0x12 $t2,$t9,0x2128
 * 0x801848a4  4b4a2968  op&0x12 $t2,$k0,0x2968
 * 0x801848a8  4a0418ea  op&0x12 $a0,$s0,0x18ea
 * 0x801848ac  4a0518ea  op&0x12 $a1,$s0,0x18ea
 * 0x801848b0  4b6a18ea  op&0x12 $t2,$k1,0x18ea
 * 0x801848b4  22b50010  op&0x08 $s5,$s5,0x0010
 * 0x801848b8  2294fff0  op&0x08 $s4,$s4,0xfff0
 * 0x801848bc  eac32000  op&0x3a $v1,$s6,0x2000
 * 0x801848c0  1e80ffe1  bgtz $s4,-31
 * 0x801848c4  22d60010  op&0x08 $s6,$s6,0x0010
 * 0x801848c8  200a0800  op&0x08 $t2,$zero,0x0800
 * 0x801848cc  05110019  op&0x01 $s1,$t0,0x0019
 * 0x801848d0  000d4820  add $t1,$zero,$t5
 * 0x801848d4  01936020  add $t4,$t4,$s3
 * 0x801848d8  2210ffff  op&0x08 $s0,$s0,0xffff
 * 0x801848dc  1e00ffd0  bgtz $s0,-48
 * 0x801848e0  01b36820  add $t5,$t5,$s3
 * 0x801848e4  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x801848e8  340b5200  ori $t3,$zero,0x5200
 * 0x801848ec  408b2000  cop0 rs=4 rt=$t3 rd=4
 * 0x801848f0  0000000d  special&0x0d $zero,$zero,$zero
 * 0x801848f4  00000000  sll $zero,$zero,0
 * 0x801848f8  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x801848fc  1560fffe  bne $t3,$zero,-2
 * 0x80184900  00000000  sll $zero,$zero,0
 * 0x80184904  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80184908  1560fffe  bne $t3,$zero,-2
 * 0x8018490c  00000000  sll $zero,$zero,0
 * 0x80184910  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x80184914  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x80184918  40881000  cop0 rs=4 rt=$t0 rd=2
 * 0x8018491c  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184920  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80184924  1560fffe  bne $t3,$zero,-2
 * 0x80184928  00000000  sll $zero,$zero,0
 * 0x8018492c  03e00008  jr $ra
 * 0x80184930  40803800  cop0 rs=4 rt=$zero rd=7
 */
