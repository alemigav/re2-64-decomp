/* FUN_80049dd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049dd0  body 0x80049dd0..0x80049f8b  size 444 B
 * body sha256 d886e10ca4a76d177992d0c48f9a0e05b11f9d0ffb85638be126a95efe38c81e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 111 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80049dd0  c4820000  op&0x31 $v0,$a0,0x0000
 * 0x80049dd4  3c01800c  lui $at,0x800c
 * 0x80049dd8  c4248a18  op&0x31 $a0,$at,0x8a18
 * 0x80049ddc  46041082  op&0x11 $a0,$s0,0x1082
 * 0x80049de0  c4800004  op&0x31 $zero,$a0,0x0004
 * 0x80049de4  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049de8  3c09ffff  lui $t1,0xffff
 * 0x80049dec  4600118d  op&0x11 $zero,$s0,0x118d
 * 0x80049df0  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049df4  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049df8  44083000  op&0x11 $t0,$zero,0x3000
 * 0x80049dfc  00e91024  and $v0,$a3,$t1
 * 0x80049e00  00081c02  srl $v1,$t0,16
 * 0x80049e04  00431025  or $v0,$v0,$v1
 * 0x80049e08  aca20000  sw $v0,0($a1)
 * 0x80049e0c  00071400  sll $v0,$a3,16
 * 0x80049e10  00491024  and $v0,$v0,$t1
 * 0x80049e14  3103ffff  andi $v1,$t0,0xffff
 * 0x80049e18  00431025  or $v0,$v0,$v1
 * 0x80049e1c  aca20020  sw $v0,32($a1)
 * 0x80049e20  c4800008  op&0x31 $zero,$a0,0x0008
 * 0x80049e24  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049e28  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049e2c  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049e30  00e91024  and $v0,$a3,$t1
 * 0x80049e34  aca20004  sw $v0,4($a1)
 * 0x80049e38  00071400  sll $v0,$a3,16
 * 0x80049e3c  00491024  and $v0,$v0,$t1
 * 0x80049e40  aca20024  sw $v0,36($a1)
 * 0x80049e44  c482000c  op&0x31 $v0,$a0,0x000c
 * 0x80049e48  46041082  op&0x11 $a0,$s0,0x1082
 * 0x80049e4c  c4800010  op&0x31 $zero,$a0,0x0010
 * 0x80049e50  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049e54  4600118d  op&0x11 $zero,$s0,0x118d
 * 0x80049e58  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049e5c  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049e60  44083000  op&0x11 $t0,$zero,0x3000
 * 0x80049e64  00e91024  and $v0,$a3,$t1
 * 0x80049e68  00081c02  srl $v1,$t0,16
 * 0x80049e6c  00431025  or $v0,$v0,$v1
 * 0x80049e70  aca20008  sw $v0,8($a1)
 * 0x80049e74  00071400  sll $v0,$a3,16
 * 0x80049e78  00491024  and $v0,$v0,$t1
 * 0x80049e7c  3103ffff  andi $v1,$t0,0xffff
 * 0x80049e80  00431025  or $v0,$v0,$v1
 * 0x80049e84  aca20028  sw $v0,40($a1)
 * 0x80049e88  c4800014  op&0x31 $zero,$a0,0x0014
 * 0x80049e8c  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049e90  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049e94  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049e98  00e91024  and $v0,$a3,$t1
 * 0x80049e9c  aca2000c  sw $v0,12($a1)
 * 0x80049ea0  00071400  sll $v0,$a3,16
 * 0x80049ea4  00491024  and $v0,$v0,$t1
 * 0x80049ea8  aca2002c  sw $v0,44($a1)
 * 0x80049eac  c4820018  op&0x31 $v0,$a0,0x0018
 * 0x80049eb0  46041082  op&0x11 $a0,$s0,0x1082
 * 0x80049eb4  c480001c  op&0x31 $zero,$a0,0x001c
 * 0x80049eb8  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049ebc  4600118d  op&0x11 $zero,$s0,0x118d
 * 0x80049ec0  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049ec4  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049ec8  44083000  op&0x11 $t0,$zero,0x3000
 * 0x80049ecc  00e91024  and $v0,$a3,$t1
 * 0x80049ed0  00081c02  srl $v1,$t0,16
 * 0x80049ed4  00431025  or $v0,$v0,$v1
 * 0x80049ed8  aca20010  sw $v0,16($a1)
 * 0x80049edc  00071400  sll $v0,$a3,16
 * 0x80049ee0  00491024  and $v0,$v0,$t1
 * 0x80049ee4  3103ffff  andi $v1,$t0,0xffff
 * 0x80049ee8  00431025  or $v0,$v0,$v1
 * 0x80049eec  aca20030  sw $v0,48($a1)
 * 0x80049ef0  c4800020  op&0x31 $zero,$a0,0x0020
 * 0x80049ef4  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049ef8  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049efc  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049f00  00e91024  and $v0,$a3,$t1
 * 0x80049f04  aca20014  sw $v0,20($a1)
 * 0x80049f08  00071400  sll $v0,$a3,16
 * 0x80049f0c  00491024  and $v0,$v0,$t1
 * 0x80049f10  10c0001c  beq $a2,$zero,+28
 * 0x80049f14  aca20034  sw $v0,52($a1)
 * 0x80049f18  c4820024  op&0x31 $v0,$a0,0x0024
 * 0x80049f1c  46041082  op&0x11 $a0,$s0,0x1082
 * 0x80049f20  c4800028  op&0x31 $zero,$a0,0x0028
 * 0x80049f24  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049f28  4600118d  op&0x11 $zero,$s0,0x118d
 * 0x80049f2c  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049f30  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049f34  44083000  op&0x11 $t0,$zero,0x3000
 * 0x80049f38  00e91024  and $v0,$a3,$t1
 * 0x80049f3c  00081c02  srl $v1,$t0,16
 * 0x80049f40  00431025  or $v0,$v0,$v1
 * 0x80049f44  aca20018  sw $v0,24($a1)
 * 0x80049f48  00071400  sll $v0,$a3,16
 * 0x80049f4c  00491024  and $v0,$v0,$t1
 * 0x80049f50  3103ffff  andi $v1,$t0,0xffff
 * 0x80049f54  00431025  or $v0,$v0,$v1
 * 0x80049f58  aca20038  sw $v0,56($a1)
 * 0x80049f5c  c480002c  op&0x31 $zero,$a0,0x002c
 * 0x80049f60  46040002  op&0x11 $a0,$s0,0x0002
 * 0x80049f64  4600018d  op&0x11 $zero,$s0,0x018d
 * 0x80049f68  44073000  op&0x11 $a3,$zero,0x3000
 * 0x80049f6c  00e91024  and $v0,$a3,$t1
 * 0x80049f70  34420001  ori $v0,$v0,0x0001
 * 0x80049f74  aca2001c  sw $v0,28($a1)
 * 0x80049f78  00071400  sll $v0,$a3,16
 * 0x80049f7c  00491024  and $v0,$v0,$t1
 * 0x80049f80  aca2003c  sw $v0,60($a1)
 * 0x80049f84  03e00008  jr $ra
 * 0x80049f88  00000000  sll $zero,$zero,0
 */
