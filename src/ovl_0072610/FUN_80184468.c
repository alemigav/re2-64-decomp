/* FUN_80184468
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80184468  body 0x80184468..0x801847a7  size 832 B
 * body sha256 df30a3b7783524d9a2db886b244d93225a3e8cffd23d994e0165ff206cf1b10d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 208 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80184468  00000000  sll $zero,$zero,0
 * 0x8018446c  00000000  sll $zero,$zero,0
 * 0x80184470  8c150000  lw $s5,0($zero)
 * 0x80184474  8c160004  lw $s6,4($zero)
 * 0x80184478  8c170008  lw $s7,8($zero)
 * 0x8018447c  8c18000c  lw $t8,12($zero)
 * 0x80184480  8c190010  lw $t9,16($zero)
 * 0x80184484  8c1a0014  lw $k0,20($zero)
 * 0x80184488  8c1b0018  lw $k1,24($zero)
 * 0x8018448c  8c1c001c  lw $gp,28($zero)
 * 0x80184490  8c1d0020  lw $sp,32($zero)
 * 0x80184494  8c1e0024  lw $fp,36($zero)
 * 0x80184498  4a000011  op&0x12 $zero,$s0,0x0011
 * 0x8018449c  c8012004  op&0x32 $at,$zero,0x2004
 * 0x801844a0  c8022005  op&0x32 $v0,$zero,0x2005
 * 0x801844a4  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x801844a8  1560fffe  bne $t3,$zero,-2
 * 0x801844ac  0019a080  sll $s4,$t9,2
 * 0x801844b0  20080300  op&0x08 $t0,$zero,0x0300
 * 0x801844b4  20090ac0  op&0x08 $t1,$zero,0x0ac0
 * 0x801844b8  e9002000  op&0x3a $zero,$t0,0x2000
 * 0x801844bc  e9002001  op&0x3a $zero,$t0,0x2001
 * 0x801844c0  e9002002  op&0x3a $zero,$t0,0x2002
 * 0x801844c4  e9002003  op&0x3a $zero,$t0,0x2003
 * 0x801844c8  1509fffb  bne $t0,$t1,-5
 * 0x801844cc  21080040  op&0x08 $t0,$t0,0x0040
 * 0x801844d0  001b9820  add $s3,$zero,$k1
 * 0x801844d4  200c0000  op&0x08 $t4,$zero,0x0000
 * 0x801844d8  20100300  op&0x08 $s0,$zero,0x0300
 * 0x801844dc  200e0200  op&0x08 $t6,$zero,0x0200
 * 0x801844e0  200f0280  op&0x08 $t7,$zero,0x0280
 * 0x801844e4  01996820  add $t5,$t4,$t9
 * 0x801844e8  02148820  add $s1,$s0,$s4
 * 0x801844ec  200a0000  op&0x08 $t2,$zero,0x0000
 * 0x801844f0  00154820  add $t1,$zero,$s5
 * 0x801844f4  00194040  sll $t0,$t9,1
 * 0x801844f8  0551009f  op&0x01 $s1,$t2,0x009f
 * 0x801844fc  2108ffff  op&0x08 $t0,$t0,0xffff
 * 0x80184500  200a0200  op&0x08 $t2,$zero,0x0200
 * 0x80184504  00164820  add $t1,$zero,$s6
 * 0x80184508  0551009b  op&0x01 $s1,$t2,0x009b
 * 0x8018450c  2328ffff  op&0x08 $t0,$t9,0xffff
 * 0x80184510  200a0280  op&0x08 $t2,$zero,0x0280
 * 0x80184514  05510098  op&0x01 $s1,$t2,0x0098
 * 0x80184518  00174820  add $t1,$zero,$s7
 * 0x8018451c  00199020  add $s2,$zero,$t9
 * 0x80184520  c9e33800  op&0x32 $v1,$t7,0x3800
 * 0x80184524  21ef0008  op&0x08 $t7,$t7,0x0008
 * 0x80184528  c9c53800  op&0x32 $a1,$t6,0x3800
 * 0x8018452c  21ce0008  op&0x08 $t6,$t6,0x0008
 * 0x80184530  4b0218d1  op&0x12 $v0,$t8,0x18d1
 * 0x80184534  4b022951  op&0x12 $v0,$t8,0x2951
 * 0x80184538  4a030110  op&0x12 $v1,$s0,0x0110
 * 0x8018453c  4a050190  op&0x12 $a1,$s0,0x0190
 * 0x80184540  c9874000  op&0x32 $a3,$t4,0x4000
 * 0x80184544  c9a84000  op&0x32 $t0,$t5,0x4000
 * 0x80184548  4b0118c5  op&0x12 $at,$t8,0x18c5
 * 0x8018454c  4b212105  op&0x12 $at,$t9,0x2105
 * 0x80184550  4b412945  op&0x12 $at,$k0,0x2945
 * 0x80184554  4b613185  op&0x12 $at,$k1,0x3185
 * 0x80184558  4b8139c5  op&0x12 $at,$gp,0x39c5
 * 0x8018455c  4b814205  op&0x12 $at,$gp,0x4205
 * 0x80184560  218c0001  op&0x08 $t4,$t4,0x0001
 * 0x80184564  4a033a50  op&0x12 $v1,$s0,0x3a50
 * 0x80184568  21ad0001  op&0x08 $t5,$t5,0x0001
 * 0x8018456c  4a043ad1  op&0x12 $a0,$s0,0x3ad1
 * 0x80184570  2252fff0  op&0x08 $s2,$s2,0xfff0
 * 0x80184574  4a044311  op&0x12 $a0,$s0,0x4311
 * 0x80184578  4a063b50  op&0x12 $a2,$s0,0x3b50
 * 0x8018457c  4a034290  op&0x12 $v1,$s0,0x4290
 * 0x80184580  4a064390  op&0x12 $a2,$s0,0x4390
 * 0x80184584  4a055ad1  op&0x12 $a1,$s0,0x5ad1
 * 0x80184588  4a056311  op&0x12 $a1,$s0,0x6311
 * 0x8018458c  4a004a63  op&0x12 $zero,$s0,0x4a63
 * 0x80184590  4b624a60  op&0x12 $v0,$k1,0x4a60
 * 0x80184594  4a0052a3  op&0x12 $zero,$s0,0x52a3
 * 0x80184598  4b6252a0  op&0x12 $v0,$k1,0x52a0
 * 0x8018459c  4a005ae3  op&0x12 $zero,$s0,0x5ae3
 * 0x801845a0  4b625ae0  op&0x12 $v0,$k1,0x5ae0
 * 0x801845a4  4a006323  op&0x12 $zero,$s0,0x6323
 * 0x801845a8  4b626320  op&0x12 $v0,$k1,0x6320
 * 0x801845ac  4a006b63  op&0x12 $zero,$s0,0x6b63
 * 0x801845b0  4b626b60  op&0x12 $v0,$k1,0x6b60
 * 0x801845b4  4a0073a3  op&0x12 $zero,$s0,0x73a3
 * 0x801845b8  4b6273a0  op&0x12 $v0,$k1,0x73a0
 * 0x801845bc  c9874000  op&0x32 $a3,$t4,0x4000
 * 0x801845c0  c9a84000  op&0x32 $t0,$t5,0x4000
 * 0x801845c4  200b0f80  op&0x08 $t3,$zero,0x0f80
 * 0x801845c8  e9694000  op&0x3a $t1,$t3,0x4000
 * 0x801845cc  e96a4004  op&0x3a $t2,$t3,0x4004
 * 0x801845d0  e96b4001  op&0x3a $t3,$t3,0x4001
 * 0x801845d4  e96c4005  op&0x3a $t4,$t3,0x4005
 * 0x801845d8  e96d4002  op&0x3a $t5,$t3,0x4002
 * 0x801845dc  e96e4006  op&0x3a $t6,$t3,0x4006
 * 0x801845e0  4b8139c5  op&0x12 $at,$gp,0x39c5
 * 0x801845e4  4b814205  op&0x12 $at,$gp,0x4205
 * 0x801845e8  216b0001  op&0x08 $t3,$t3,0x0001
 * 0x801845ec  4a033a50  op&0x12 $v1,$s0,0x3a50
 * 0x801845f0  218c000f  op&0x08 $t4,$t4,0x000f
 * 0x801845f4  4a043ad1  op&0x12 $a0,$s0,0x3ad1
 * 0x801845f8  21ad000f  op&0x08 $t5,$t5,0x000f
 * 0x801845fc  4a044311  op&0x12 $a0,$s0,0x4311
 * 0x80184600  4a063b50  op&0x12 $a2,$s0,0x3b50
 * 0x80184604  4a034290  op&0x12 $v1,$s0,0x4290
 * 0x80184608  4a064390  op&0x12 $a2,$s0,0x4390
 * 0x8018460c  4a055ad1  op&0x12 $a1,$s0,0x5ad1
 * 0x80184610  4a056311  op&0x12 $a1,$s0,0x6311
 * 0x80184614  4a004a63  op&0x12 $zero,$s0,0x4a63
 * 0x80184618  4b624a60  op&0x12 $v0,$k1,0x4a60
 * 0x8018461c  4a0052a3  op&0x12 $zero,$s0,0x52a3
 * 0x80184620  4b6252a0  op&0x12 $v0,$k1,0x52a0
 * 0x80184624  4a005ae3  op&0x12 $zero,$s0,0x5ae3
 * 0x80184628  4b625ae0  op&0x12 $v0,$k1,0x5ae0
 * 0x8018462c  4a006323  op&0x12 $zero,$s0,0x6323
 * 0x80184630  4b626320  op&0x12 $v0,$k1,0x6320
 * 0x80184634  4a006b63  op&0x12 $zero,$s0,0x6b63
 * 0x80184638  4b626b60  op&0x12 $v0,$k1,0x6b60
 * 0x8018463c  4a0073a3  op&0x12 $zero,$s0,0x73a3
 * 0x80184640  4b6273a0  op&0x12 $v0,$k1,0x73a0
 * 0x80184644  e9694000  op&0x3a $t1,$t3,0x4000
 * 0x80184648  e96a4004  op&0x3a $t2,$t3,0x4004
 * 0x8018464c  e96b4001  op&0x3a $t3,$t3,0x4001
 * 0x80184650  e96c4005  op&0x3a $t4,$t3,0x4005
 * 0x80184654  e96d4002  op&0x3a $t5,$t3,0x4002
 * 0x80184658  e96e4006  op&0x3a $t6,$t3,0x4006
 * 0x8018465c  200b0f80  op&0x08 $t3,$zero,0x0f80
 * 0x80184660  c9693800  op&0x32 $t1,$t3,0x3800
 * 0x80184664  22090001  op&0x08 $t1,$s0,0x0001
 * 0x80184668  c96a3801  op&0x32 $t2,$t3,0x3801
 * 0x8018466c  220a0002  op&0x08 $t2,$s0,0x0002
 * 0x80184670  c96b3802  op&0x32 $t3,$t3,0x3802
 * 0x80184674  c96c3803  op&0x32 $t4,$t3,0x3803
 * 0x80184678  c96d3804  op&0x32 $t5,$t3,0x3804
 * 0x8018467c  c96e3805  op&0x32 $t6,$t3,0x3805
 * 0x80184680  ea094800  op&0x3a $t1,$s0,0x4800
 * 0x80184684  e92b4800  op&0x3a $t3,$t1,0x4800
 * 0x80184688  e94d4800  op&0x3a $t5,$t2,0x4800
 * 0x8018468c  ea0a4802  op&0x3a $t2,$s0,0x4802
 * 0x80184690  e92c4802  op&0x3a $t4,$t1,0x4802
 * 0x80184694  e94e4802  op&0x3a $t6,$t2,0x4802
 * 0x80184698  ea094c01  op&0x3a $t1,$s0,0x4c01
 * 0x8018469c  e92b4c01  op&0x3a $t3,$t1,0x4c01
 * 0x801846a0  e94d4c01  op&0x3a $t5,$t2,0x4c01
 * 0x801846a4  ea0a4c03  op&0x3a $t2,$s0,0x4c03
 * 0x801846a8  e92c4c03  op&0x3a $t4,$t1,0x4c03
 * 0x801846ac  e94e4c03  op&0x3a $t6,$t2,0x4c03
 * 0x801846b0  22290001  op&0x08 $t1,$s1,0x0001
 * 0x801846b4  c9693808  op&0x32 $t1,$t3,0x3808
 * 0x801846b8  222a0002  op&0x08 $t2,$s1,0x0002
 * 0x801846bc  c96a3809  op&0x32 $t2,$t3,0x3809
 * 0x801846c0  c96b380a  op&0x32 $t3,$t3,0x380a
 * 0x801846c4  c96c380b  op&0x32 $t4,$t3,0x380b
 * 0x801846c8  c96d380c  op&0x32 $t5,$t3,0x380c
 * 0x801846cc  c96e380d  op&0x32 $t6,$t3,0x380d
 * 0x801846d0  22100040  op&0x08 $s0,$s0,0x0040
 * 0x801846d4  ea202000  op&0x3a $zero,$s1,0x2000
 * 0x801846d8  ea202001  op&0x3a $zero,$s1,0x2001
 * 0x801846dc  ea202002  op&0x3a $zero,$s1,0x2002
 * 0x801846e0  ea202003  op&0x3a $zero,$s1,0x2003
 * 0x801846e4  ea294800  op&0x3a $t1,$s1,0x4800
 * 0x801846e8  e92b4800  op&0x3a $t3,$t1,0x4800
 * 0x801846ec  e94d4800  op&0x3a $t5,$t2,0x4800
 * 0x801846f0  ea2a4802  op&0x3a $t2,$s1,0x4802
 * 0x801846f4  e92c4802  op&0x3a $t4,$t1,0x4802
 * 0x801846f8  e94e4802  op&0x3a $t6,$t2,0x4802
 * 0x801846fc  ea294c01  op&0x3a $t1,$s1,0x4c01
 * 0x80184700  e92b4c01  op&0x3a $t3,$t1,0x4c01
 * 0x80184704  e94d4c01  op&0x3a $t5,$t2,0x4c01
 * 0x80184708  ea2a4c03  op&0x3a $t2,$s1,0x4c03
 * 0x8018470c  e92c4c03  op&0x3a $t4,$t1,0x4c03
 * 0x80184710  e94e4c03  op&0x3a $t6,$t2,0x4c03
 * 0x80184714  1e40ff82  bgtz $s2,-126
 * 0x80184718  22310040  op&0x08 $s1,$s1,0x0040
 * 0x8018471c  2273ffff  op&0x08 $s3,$s3,0xffff
 * 0x80184720  01996020  add $t4,$t4,$t9
 * 0x80184724  01b96820  add $t5,$t5,$t9
 * 0x80184728  02148020  add $s0,$s0,$s4
 * 0x8018472c  1e60ff7b  bgtz $s3,-133
 * 0x80184730  02348820  add $s1,$s1,$s4
 * 0x80184734  00184820  add $t1,$zero,$t8
 * 0x80184738  200a0300  op&0x08 $t2,$zero,0x0300
 * 0x8018473c  0551001a  op&0x01 $s1,$t2,0x001a
 * 0x80184740  001d4020  add $t0,$zero,$sp
 * 0x80184744  031ec020  add $t8,$t8,$fp
 * 0x80184748  00194040  sll $t0,$t9,1
 * 0x8018474c  02a8a820  add $s5,$s5,$t0
 * 0x80184750  00084082  srl $t0,$t0,2
 * 0x80184754  02e8b820  add $s7,$s7,$t0
 * 0x80184758  239cffff  op&0x08 $gp,$gp,0xffff
 * 0x8018475c  1f80ff5c  bgtz $gp,-164
 * 0x80184760  02c8b020  add $s6,$s6,$t0
 * 0x80184764  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184768  34014000  ori $at,$zero,0x4000
 * 0x8018476c  40812000  cop0 rs=4 rt=$at rd=4
 * 0x80184770  0000000d  special&0x0d $zero,$zero,$zero
 * 0x80184774  00000000  sll $zero,$zero,0
 * 0x80184778  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x8018477c  1560fffe  bne $t3,$zero,-2
 * 0x80184780  00000000  sll $zero,$zero,0
 * 0x80184784  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x80184788  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x8018478c  40881000  cop0 rs=4 rt=$t0 rd=2
 * 0x80184790  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184794  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80184798  1560fffe  bne $t3,$zero,-2
 * 0x8018479c  00000000  sll $zero,$zero,0
 * 0x801847a0  03e00008  jr $ra
 * 0x801847a4  00000000  sll $zero,$zero,0
 */
