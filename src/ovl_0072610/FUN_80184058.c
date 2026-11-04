/* FUN_80184058
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80184058  body 0x80184058..0x8018442b  size 980 B
 * body sha256 ef7bea54ac970f30dda635ab8c75263542050be583821b07a8634ea3a6fd1375
 * EXTENT MEASURED, NOT RECONSTRUCTED: 245 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80184058  00000000  sll $zero,$zero,0
 * 0x8018405c  00000000  sll $zero,$zero,0
 * 0x80184060  8c150000  lw $s5,0($zero)
 * 0x80184064  8c160004  lw $s6,4($zero)
 * 0x80184068  8c170008  lw $s7,8($zero)
 * 0x8018406c  8c18000c  lw $t8,12($zero)
 * 0x80184070  8c190010  lw $t9,16($zero)
 * 0x80184074  8c1a0014  lw $k0,20($zero)
 * 0x80184078  8c1b0018  lw $k1,24($zero)
 * 0x8018407c  8c1c001c  lw $gp,28($zero)
 * 0x80184080  8c1d0020  lw $sp,32($zero)
 * 0x80184084  8c1e0024  lw $fp,36($zero)
 * 0x80184088  4a000011  op&0x12 $zero,$s0,0x0011
 * 0x8018408c  c8012004  op&0x32 $at,$zero,0x2004
 * 0x80184090  c8012804  op&0x32 $at,$zero,0x2804
 * 0x80184094  c8022005  op&0x32 $v0,$zero,0x2005
 * 0x80184098  c8022805  op&0x32 $v0,$zero,0x2805
 * 0x8018409c  001b9820  add $s3,$zero,$k1
 * 0x801840a0  200c0000  op&0x08 $t4,$zero,0x0000
 * 0x801840a4  200d0000  op&0x08 $t5,$zero,0x0000
 * 0x801840a8  01b96820  add $t5,$t5,$t9
 * 0x801840ac  200e0400  op&0x08 $t6,$zero,0x0400
 * 0x801840b0  200f0500  op&0x08 $t7,$zero,0x0500
 * 0x801840b4  20100800  op&0x08 $s0,$zero,0x0800
 * 0x801840b8  20110800  op&0x08 $s1,$zero,0x0800
 * 0x801840bc  02398820  add $s1,$s1,$t9
 * 0x801840c0  02398820  add $s1,$s1,$t9
 * 0x801840c4  200a0000  op&0x08 $t2,$zero,0x0000
 * 0x801840c8  00154820  add $t1,$zero,$s5
 * 0x801840cc  055100c8  op&0x01 $s1,$t2,0x00c8
 * 0x801840d0  00194080  sll $t0,$t9,2
 * 0x801840d4  2108ffff  op&0x08 $t0,$t0,0xffff
 * 0x801840d8  200a0400  op&0x08 $t2,$zero,0x0400
 * 0x801840dc  00164820  add $t1,$zero,$s6
 * 0x801840e0  055100c3  op&0x01 $s1,$t2,0x00c3
 * 0x801840e4  00194020  add $t0,$zero,$t9
 * 0x801840e8  2108ffff  op&0x08 $t0,$t0,0xffff
 * 0x801840ec  200a0500  op&0x08 $t2,$zero,0x0500
 * 0x801840f0  00174820  add $t1,$zero,$s7
 * 0x801840f4  055100be  op&0x01 $s1,$t2,0x00be
 * 0x801840f8  00194020  add $t0,$zero,$t9
 * 0x801840fc  2108ffff  op&0x08 $t0,$t0,0xffff
 * 0x80184100  00199020  add $s2,$zero,$t9
 * 0x80184104  00000000  sll $zero,$zero,0
 * 0x80184108  4a0318d1  op&0x12 $v1,$s0,0x18d1
 * 0x8018410c  c9e33800  op&0x32 $v1,$t7,0x3800
 * 0x80184110  4bc118c5  op&0x12 $at,$fp,0x18c5
 * 0x80184114  21ef0008  op&0x08 $t7,$t7,0x0008
 * 0x80184118  4a052951  op&0x12 $a1,$s0,0x2951
 * 0x8018411c  c9c53800  op&0x32 $a1,$t6,0x3800
 * 0x80184120  4bc12945  op&0x12 $at,$fp,0x2945
 * 0x80184124  21ce0008  op&0x08 $t6,$t6,0x0008
 * 0x80184128  4b0218d1  op&0x12 $v0,$t8,0x18d1
 * 0x8018412c  4b022951  op&0x12 $v0,$t8,0x2951
 * 0x80184130  4a030110  op&0x12 $v1,$s0,0x0110
 * 0x80184134  4a050190  op&0x12 $a1,$s0,0x0190
 * 0x80184138  4b0118c7  op&0x12 $at,$t8,0x18c7
 * 0x8018413c  4b212107  op&0x12 $at,$t9,0x2107
 * 0x80184140  4b412947  op&0x12 $at,$k0,0x2947
 * 0x80184144  4b613187  op&0x12 $at,$k1,0x3187
 * 0x80184148  4a0739d1  op&0x12 $a3,$s0,0x39d1
 * 0x8018414c  c9874000  op&0x32 $a3,$t4,0x4000
 * 0x80184150  4bc139c5  op&0x12 $at,$fp,0x39c5
 * 0x80184154  4a084211  op&0x12 $t0,$s0,0x4211
 * 0x80184158  c9a84000  op&0x32 $t0,$t5,0x4000
 * 0x8018415c  4bc14205  op&0x12 $at,$fp,0x4205
 * 0x80184160  4b8139c7  op&0x12 $at,$gp,0x39c7
 * 0x80184164  4b814207  op&0x12 $at,$gp,0x4207
 * 0x80184168  4a070250  op&0x12 $a3,$s0,0x0250
 * 0x8018416c  4a034a50  op&0x12 $v1,$s0,0x4a50
 * 0x80184170  4a080290  op&0x12 $t0,$s0,0x0290
 * 0x80184174  4a035290  op&0x12 $v1,$s0,0x5290
 * 0x80184178  4a0702d0  op&0x12 $a3,$s0,0x02d0
 * 0x8018417c  4a045ad0  op&0x12 $a0,$s0,0x5ad0
 * 0x80184180  4a055ad0  op&0x12 $a1,$s0,0x5ad0
 * 0x80184184  4a080310  op&0x12 $t0,$s0,0x0310
 * 0x80184188  4a046310  op&0x12 $a0,$s0,0x6310
 * 0x8018418c  4a056310  op&0x12 $a1,$s0,0x6310
 * 0x80184190  4a070350  op&0x12 $a3,$s0,0x0350
 * 0x80184194  4a066b50  op&0x12 $a2,$s0,0x6b50
 * 0x80184198  4a080390  op&0x12 $t0,$s0,0x0390
 * 0x8018419c  4a067390  op&0x12 $a2,$s0,0x7390
 * 0x801841a0  4a004a63  op&0x12 $zero,$s0,0x4a63
 * 0x801841a4  4b624a60  op&0x12 $v0,$k1,0x4a60
 * 0x801841a8  4a0052a3  op&0x12 $zero,$s0,0x52a3
 * 0x801841ac  4b6252a0  op&0x12 $v0,$k1,0x52a0
 * 0x801841b0  4a005ae3  op&0x12 $zero,$s0,0x5ae3
 * 0x801841b4  4b625ae0  op&0x12 $v0,$k1,0x5ae0
 * 0x801841b8  4a006323  op&0x12 $zero,$s0,0x6323
 * 0x801841bc  4b626320  op&0x12 $v0,$k1,0x6320
 * 0x801841c0  4a006b63  op&0x12 $zero,$s0,0x6b63
 * 0x801841c4  4b626b60  op&0x12 $v0,$k1,0x6b60
 * 0x801841c8  4a0073a3  op&0x12 $zero,$s0,0x73a3
 * 0x801841cc  4b6273a0  op&0x12 $v0,$k1,0x73a0
 * 0x801841d0  4b224a68  op&0x12 $v0,$t9,0x4a68
 * 0x801841d4  4b2252a8  op&0x12 $v0,$t9,0x52a8
 * 0x801841d8  4b225ae8  op&0x12 $v0,$t9,0x5ae8
 * 0x801841dc  4b226328  op&0x12 $v0,$t9,0x6328
 * 0x801841e0  4b226b68  op&0x12 $v0,$t9,0x6b68
 * 0x801841e4  4b2273a8  op&0x12 $v0,$t9,0x73a8
 * 0x801841e8  4a094a54  op&0x12 $t1,$s0,0x4a54
 * 0x801841ec  4a0a5294  op&0x12 $t2,$s0,0x5294
 * 0x801841f0  4ba15ac5  op&0x12 $at,$sp,0x5ac5
 * 0x801841f4  4ba16305  op&0x12 $at,$sp,0x6305
 * 0x801841f8  4be16b45  op&0x12 $at,$ra,0x6b45
 * 0x801841fc  4be17385  op&0x12 $at,$ra,0x7385
 * 0x80184200  4a0b4a6a  op&0x12 $t3,$s0,0x4a6a
 * 0x80184204  4a0c52aa  op&0x12 $t4,$s0,0x52aa
 * 0x80184208  4a0d4a6a  op&0x12 $t5,$s0,0x4a6a
 * 0x8018420c  4a0e52aa  op&0x12 $t6,$s0,0x52aa
 * 0x80184210  4b424a6a  op&0x12 $v0,$k0,0x4a6a
 * 0x80184214  4b4252aa  op&0x12 $v0,$k0,0x52aa
 * 0x80184218  ea090800  op&0x3a $t1,$s0,0x0800
 * 0x8018421c  ea090902  op&0x3a $t1,$s0,0x0902
 * 0x80184220  ea090a04  op&0x3a $t1,$s0,0x0a04
 * 0x80184224  ea090b06  op&0x3a $t1,$s0,0x0b06
 * 0x80184228  ea090c08  op&0x3a $t1,$s0,0x0c08
 * 0x8018422c  ea090d0a  op&0x3a $t1,$s0,0x0d0a
 * 0x80184230  ea090e0c  op&0x3a $t1,$s0,0x0e0c
 * 0x80184234  ea090f0e  op&0x3a $t1,$s0,0x0f0e
 * 0x80184238  ea2a0800  op&0x3a $t2,$s1,0x0800
 * 0x8018423c  ea2a0902  op&0x3a $t2,$s1,0x0902
 * 0x80184240  ea2a0a04  op&0x3a $t2,$s1,0x0a04
 * 0x80184244  ea2a0b06  op&0x3a $t2,$s1,0x0b06
 * 0x80184248  ea2a0c08  op&0x3a $t2,$s1,0x0c08
 * 0x8018424c  ea2a0d0a  op&0x3a $t2,$s1,0x0d0a
 * 0x80184250  ea2a0e0c  op&0x3a $t2,$s1,0x0e0c
 * 0x80184254  ea2a0f0e  op&0x3a $t2,$s1,0x0f0e
 * 0x80184258  218c0001  op&0x08 $t4,$t4,0x0001
 * 0x8018425c  21ad0001  op&0x08 $t5,$t5,0x0001
 * 0x80184260  4a0739d1  op&0x12 $a3,$s0,0x39d1
 * 0x80184264  c9874000  op&0x32 $a3,$t4,0x4000
 * 0x80184268  4bc139c5  op&0x12 $at,$fp,0x39c5
 * 0x8018426c  4a084211  op&0x12 $t0,$s0,0x4211
 * 0x80184270  c9a84000  op&0x32 $t0,$t5,0x4000
 * 0x80184274  4bc14205  op&0x12 $at,$fp,0x4205
 * 0x80184278  4b8139c7  op&0x12 $at,$gp,0x39c7
 * 0x8018427c  4b814207  op&0x12 $at,$gp,0x4207
 * 0x80184280  4a070250  op&0x12 $a3,$s0,0x0250
 * 0x80184284  4a034a50  op&0x12 $v1,$s0,0x4a50
 * 0x80184288  4a080290  op&0x12 $t0,$s0,0x0290
 * 0x8018428c  4a035290  op&0x12 $v1,$s0,0x5290
 * 0x80184290  4a0702d0  op&0x12 $a3,$s0,0x02d0
 * 0x80184294  4a045ad0  op&0x12 $a0,$s0,0x5ad0
 * 0x80184298  4a055ad0  op&0x12 $a1,$s0,0x5ad0
 * 0x8018429c  4a080310  op&0x12 $t0,$s0,0x0310
 * 0x801842a0  4a046310  op&0x12 $a0,$s0,0x6310
 * 0x801842a4  4a056310  op&0x12 $a1,$s0,0x6310
 * 0x801842a8  4a070350  op&0x12 $a3,$s0,0x0350
 * 0x801842ac  4a066b50  op&0x12 $a2,$s0,0x6b50
 * 0x801842b0  4a080390  op&0x12 $t0,$s0,0x0390
 * 0x801842b4  4a067390  op&0x12 $a2,$s0,0x7390
 * 0x801842b8  4a004a63  op&0x12 $zero,$s0,0x4a63
 * 0x801842bc  4b624a60  op&0x12 $v0,$k1,0x4a60
 * 0x801842c0  4a0052a3  op&0x12 $zero,$s0,0x52a3
 * 0x801842c4  4b6252a0  op&0x12 $v0,$k1,0x52a0
 * 0x801842c8  4a005ae3  op&0x12 $zero,$s0,0x5ae3
 * 0x801842cc  4b625ae0  op&0x12 $v0,$k1,0x5ae0
 * 0x801842d0  4a006323  op&0x12 $zero,$s0,0x6323
 * 0x801842d4  4b626320  op&0x12 $v0,$k1,0x6320
 * 0x801842d8  4a006b63  op&0x12 $zero,$s0,0x6b63
 * 0x801842dc  4b626b60  op&0x12 $v0,$k1,0x6b60
 * 0x801842e0  4a0073a3  op&0x12 $zero,$s0,0x73a3
 * 0x801842e4  4b6273a0  op&0x12 $v0,$k1,0x73a0
 * 0x801842e8  4b224a68  op&0x12 $v0,$t9,0x4a68
 * 0x801842ec  4b2252a8  op&0x12 $v0,$t9,0x52a8
 * 0x801842f0  4b225ae8  op&0x12 $v0,$t9,0x5ae8
 * 0x801842f4  4b226328  op&0x12 $v0,$t9,0x6328
 * 0x801842f8  4b226b68  op&0x12 $v0,$t9,0x6b68
 * 0x801842fc  4b2273a8  op&0x12 $v0,$t9,0x73a8
 * 0x80184300  4a094a54  op&0x12 $t1,$s0,0x4a54
 * 0x80184304  4a0a5294  op&0x12 $t2,$s0,0x5294
 * 0x80184308  4ba15ac5  op&0x12 $at,$sp,0x5ac5
 * 0x8018430c  4ba16305  op&0x12 $at,$sp,0x6305
 * 0x80184310  4be16b45  op&0x12 $at,$ra,0x6b45
 * 0x80184314  4be17385  op&0x12 $at,$ra,0x7385
 * 0x80184318  4a0b4a6a  op&0x12 $t3,$s0,0x4a6a
 * 0x8018431c  4a0c52aa  op&0x12 $t4,$s0,0x52aa
 * 0x80184320  4a0d4a6a  op&0x12 $t5,$s0,0x4a6a
 * 0x80184324  4a0e52aa  op&0x12 $t6,$s0,0x52aa
 * 0x80184328  4b424a6a  op&0x12 $v0,$k0,0x4a6a
 * 0x8018432c  4b4252aa  op&0x12 $v0,$k0,0x52aa
 * 0x80184330  ea090801  op&0x3a $t1,$s0,0x0801
 * 0x80184334  ea090903  op&0x3a $t1,$s0,0x0903
 * 0x80184338  ea090a05  op&0x3a $t1,$s0,0x0a05
 * 0x8018433c  ea090b07  op&0x3a $t1,$s0,0x0b07
 * 0x80184340  ea090c09  op&0x3a $t1,$s0,0x0c09
 * 0x80184344  ea090d0b  op&0x3a $t1,$s0,0x0d0b
 * 0x80184348  ea090e0d  op&0x3a $t1,$s0,0x0e0d
 * 0x8018434c  ea090f0f  op&0x3a $t1,$s0,0x0f0f
 * 0x80184350  ea2a0801  op&0x3a $t2,$s1,0x0801
 * 0x80184354  ea2a0903  op&0x3a $t2,$s1,0x0903
 * 0x80184358  ea2a0a05  op&0x3a $t2,$s1,0x0a05
 * 0x8018435c  ea2a0b07  op&0x3a $t2,$s1,0x0b07
 * 0x80184360  ea2a0c09  op&0x3a $t2,$s1,0x0c09
 * 0x80184364  ea2a0d0b  op&0x3a $t2,$s1,0x0d0b
 * 0x80184368  ea2a0e0d  op&0x3a $t2,$s1,0x0e0d
 * 0x8018436c  ea2a0f0f  op&0x3a $t2,$s1,0x0f0f
 * 0x80184370  22100020  op&0x08 $s0,$s0,0x0020
 * 0x80184374  22310020  op&0x08 $s1,$s1,0x0020
 * 0x80184378  218c000f  op&0x08 $t4,$t4,0x000f
 * 0x8018437c  21ad000f  op&0x08 $t5,$t5,0x000f
 * 0x80184380  2252fff0  op&0x08 $s2,$s2,0xfff0
 * 0x80184384  1640ff60  bne $s2,$zero,-160
 * 0x80184388  00000000  sll $zero,$zero,0
 * 0x8018438c  01996020  add $t4,$t4,$t9
 * 0x80184390  01b96820  add $t5,$t5,$t9
 * 0x80184394  03395820  add $t3,$t9,$t9
 * 0x80184398  020b8020  add $s0,$s0,$t3
 * 0x8018439c  022b8820  add $s1,$s1,$t3
 * 0x801843a0  2273ffff  op&0x08 $s3,$s3,0xffff
 * 0x801843a4  1660ff56  bne $s3,$zero,-170
 * 0x801843a8  00000000  sll $zero,$zero,0
 * 0x801843ac  00184820  add $t1,$zero,$t8
 * 0x801843b0  200a0800  op&0x08 $t2,$zero,0x0800
 * 0x801843b4  0551001d  op&0x01 $s1,$t2,0x001d
 * 0x801843b8  001d4020  add $t0,$zero,$sp
 * 0x801843bc  031ec020  add $t8,$t8,$fp
 * 0x801843c0  00194080  sll $t0,$t9,2
 * 0x801843c4  02a8a820  add $s5,$s5,$t0
 * 0x801843c8  02f9b820  add $s7,$s7,$t9
 * 0x801843cc  02d9b020  add $s6,$s6,$t9
 * 0x801843d0  239cffff  op&0x08 $gp,$gp,0xffff
 * 0x801843d4  1f80ff31  bgtz $gp,-207
 * 0x801843d8  00000000  sll $zero,$zero,0
 * 0x801843dc  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x801843e0  340b5200  ori $t3,$zero,0x5200
 * 0x801843e4  408b2000  cop0 rs=4 rt=$t3 rd=4
 * 0x801843e8  0000000d  special&0x0d $zero,$zero,$zero
 * 0x801843ec  00000000  sll $zero,$zero,0
 * 0x801843f0  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x801843f4  1560fffe  bne $t3,$zero,-2
 * 0x801843f8  00000000  sll $zero,$zero,0
 * 0x801843fc  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80184400  1560fffe  bne $t3,$zero,-2
 * 0x80184404  00000000  sll $zero,$zero,0
 * 0x80184408  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x8018440c  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x80184410  40881000  cop0 rs=4 rt=$t0 rd=2
 * 0x80184414  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184418  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x8018441c  1560fffe  bne $t3,$zero,-2
 * 0x80184420  00000000  sll $zero,$zero,0
 * 0x80184424  03e00008  jr $ra
 * 0x80184428  40803800  cop0 rs=4 rt=$zero rd=7
 */
