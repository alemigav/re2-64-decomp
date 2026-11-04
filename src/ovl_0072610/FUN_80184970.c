/* FUN_80184970
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x80184970  body 0x80184970..0x80184a7b  size 268 B
 * body sha256 5e403fd769e228871b5c501e182f968cb05eeeb9ab869702a327e290f58e870b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 67 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80184970  8c0c0000  lw $t4,0($zero)
 * 0x80184974  8c0d0004  lw $t5,4($zero)
 * 0x80184978  8c0e0008  lw $t6,8($zero)
 * 0x8018497c  8c0f000c  lw $t7,12($zero)
 * 0x80184980  8c100010  lw $s0,16($zero)
 * 0x80184984  8c110014  lw $s1,20($zero)
 * 0x80184988  8c120018  lw $s2,24($zero)
 * 0x8018498c  8c13001c  lw $s3,28($zero)
 * 0x80184990  c80a2002  op&0x32 $t2,$zero,0x2002
 * 0x80184994  4a000011  op&0x12 $zero,$s0,0x0011
 * 0x80184998  4a0318d1  op&0x12 $v1,$s0,0x18d1
 * 0x8018499c  21f7ffff  op&0x08 $s7,$t7,0xffff
 * 0x801849a0  10000003  beq $zero,$zero,+3
 * 0x801849a4  0017bb00  sll $s7,$s7,12
 * 0x801849a8  2237ffff  op&0x08 $s7,$s1,0xffff
 * 0x801849ac  0017bb00  sll $s7,$s7,12
 * 0x801849b0  02574025  or $t0,$s2,$s7
 * 0x801849b4  200a0000  op&0x08 $t2,$zero,0x0000
 * 0x801849b8  06f10021  op&0x01 $s1,$s7,0x0021
 * 0x801849bc  000c4820  add $t1,$zero,$t4
 * 0x801849c0  200a0800  op&0x08 $t2,$zero,0x0800
 * 0x801849c4  0511001e  op&0x01 $s1,$t0,0x001e
 * 0x801849c8  000d4820  add $t1,$zero,$t5
 * 0x801849cc  20150000  op&0x08 $s5,$zero,0x0000
 * 0x801849d0  20160800  op&0x08 $s6,$zero,0x0800
 * 0x801849d4  000ea020  add $s4,$zero,$t6
 * 0x801849d8  caa13800  op&0x32 $at,$s5,0x3800
 * 0x801849dc  cac23800  op&0x32 $v0,$s6,0x3800
 * 0x801849e0  4a020854  op&0x12 $v0,$s0,0x0854
 * 0x801849e4  4a0018d0  op&0x12 $zero,$s0,0x18d0
 * 0x801849e8  4b6a0854  op&0x12 $t2,$k1,0x0854
 * 0x801849ec  4a0018d0  op&0x12 $zero,$s0,0x18d0
 * 0x801849f0  4b8a0844  op&0x12 $t2,$gp,0x0844
 * 0x801849f4  4b8a18cd  op&0x12 $t2,$gp,0x18cd
 * 0x801849f8  4b00004e  op&0x12 $zero,$t8,0x004e
 * 0x801849fc  eac13800  op&0x3a $at,$s6,0x3800
 * 0x80184a00  22b50008  op&0x08 $s5,$s5,0x0008
 * 0x80184a04  2294fff8  op&0x08 $s4,$s4,0xfff8
 * 0x80184a08  1e80fff3  bgtz $s4,-13
 * 0x80184a0c  22d60008  op&0x08 $s6,$s6,0x0008
 * 0x80184a10  200a0800  op&0x08 $t2,$zero,0x0800
 * 0x80184a14  05110019  op&0x01 $s1,$t0,0x0019
 * 0x80184a18  000d4820  add $t1,$zero,$t5
 * 0x80184a1c  01936020  add $t4,$t4,$s3
 * 0x80184a20  2210ffff  op&0x08 $s0,$s0,0xffff
 * 0x80184a24  1e00ffe2  bgtz $s0,-30
 * 0x80184a28  01b36820  add $t5,$t5,$s3
 * 0x80184a2c  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184a30  340b5200  ori $t3,$zero,0x5200
 * 0x80184a34  408b2000  cop0 rs=4 rt=$t3 rd=4
 * 0x80184a38  0000000d  special&0x0d $zero,$zero,$zero
 * 0x80184a3c  00000000  sll $zero,$zero,0
 * 0x80184a40  400b3800  cop0 rs=0 rt=$t3 rd=7
 * 0x80184a44  1560fffe  bne $t3,$zero,-2
 * 0x80184a48  00000000  sll $zero,$zero,0
 * 0x80184a4c  400b2800  cop0 rs=0 rt=$t3 rd=5
 * 0x80184a50  1560fffe  bne $t3,$zero,-2
 * 0x80184a54  00000000  sll $zero,$zero,0
 * 0x80184a58  408a0000  cop0 rs=4 rt=$t2 rd=0
 * 0x80184a5c  40890800  cop0 rs=4 rt=$t1 rd=1
 * 0x80184a60  40881000  cop0 rs=4 rt=$t0 rd=2
 * 0x80184a64  40803800  cop0 rs=4 rt=$zero rd=7
 * 0x80184a68  400b3000  cop0 rs=0 rt=$t3 rd=6
 * 0x80184a6c  1560fffe  bne $t3,$zero,-2
 * 0x80184a70  00000000  sll $zero,$zero,0
 * 0x80184a74  03e00008  jr $ra
 * 0x80184a78  40803800  cop0 rs=4 rt=$zero rd=7
 */
