/* FUN_80050fa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050fa8  body 0x80050fa8..0x800510c3  size 284 B
 * body sha256 a8be61201a04d0551d6088489da1184434f25c4c244882dd32e41731f0e0e5b3
 * EXTENT MEASURED, NOT RECONSTRUCTED: 71 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80050fa8  8c690000  lw $t1,0($v1)
 * 0x80050fac  3c058010  lui $a1,0x8010
 * 0x80050fb0  3c0741c6  lui $a3,0x41c6
 * 0x80050fb4  34e74e6d  ori $a3,$a3,0x4e6d
 * 0x80050fb8  2529ffff  addiu $t1,$t1,0xffff
 * 0x80050fbc  112a003f  beq $t1,$t2,+63
 * 0x80050fc0  00000000  sll $zero,$zero,0
 * 0x80050fc4  8d020000  lw $v0,0($t0)
 * 0x80050fc8  8506000e  lh $a2,14($t0)
 * 0x80050fcc  2444000e  addiu $a0,$v0,0x000e
 * 0x80050fd0  50c0fff9  op&0x14 $zero,$a2,0xfff9
 * 0x80050fd4  25080010  addiu $t0,$t0,0x0010
 * 0x80050fd8  8ca29e30  lw $v0,-25040($a1)
 * 0x80050fdc  00470018  mult $v0,$a3
 * 0x80050fe0  00005812  mflo $t3
 * 0x80050fe4  25623039  addiu $v0,$t3,0x3039
 * 0x80050fe8  aca29e30  sw $v0,-25040($a1)
 * 0x80050fec  00021403  sra $v0,$v0,16
 * 0x80050ff0  8083fffe  lb $v1,-2($a0)
 * 0x80050ff4  3042000f  andi $v0,$v0,0x000f
 * 0x80050ff8  00621821  addu $v1,$v1,$v0
 * 0x80050ffc  2463fff8  addiu $v1,$v1,0xfff8
 * 0x80051000  28620080  op&0x0a $v0,$v1,0x0080
 * 0x80051004  14400003  bne $v0,$zero,+3
 * 0x80051008  2862ff80  op&0x0a $v0,$v1,0xff80
 * 0x8005100c  08014407  j 0x8005101c
 * 0x80051010  24030080  addiu $v1,$zero,0x0080
 * 0x80051014  54400001  op&0x15 $zero,$v0,0x0001
 * 0x80051018  2403ff80  addiu $v1,$zero,0xff80
 * 0x8005101c  a083fffe  sb $v1,-2($a0)
 * 0x80051020  8ca29e30  lw $v0,-25040($a1)
 * 0x80051024  00470018  mult $v0,$a3
 * 0x80051028  00005812  mflo $t3
 * 0x8005102c  25623039  addiu $v0,$t3,0x3039
 * 0x80051030  aca29e30  sw $v0,-25040($a1)
 * 0x80051034  00021403  sra $v0,$v0,16
 * 0x80051038  8083ffff  lb $v1,-1($a0)
 * 0x8005103c  3042000f  andi $v0,$v0,0x000f
 * 0x80051040  00621821  addu $v1,$v1,$v0
 * 0x80051044  2463fff8  addiu $v1,$v1,0xfff8
 * 0x80051048  28620080  op&0x0a $v0,$v1,0x0080
 * 0x8005104c  14400003  bne $v0,$zero,+3
 * 0x80051050  2862ff80  op&0x0a $v0,$v1,0xff80
 * 0x80051054  08014419  j 0x80051064
 * 0x80051058  24030080  addiu $v1,$zero,0x0080
 * 0x8005105c  54400001  op&0x15 $zero,$v0,0x0001
 * 0x80051060  2403ff80  addiu $v1,$zero,0xff80
 * 0x80051064  a083ffff  sb $v1,-1($a0)
 * 0x80051068  8ca29e30  lw $v0,-25040($a1)
 * 0x8005106c  00470018  mult $v0,$a3
 * 0x80051070  00005812  mflo $t3
 * 0x80051074  25623039  addiu $v0,$t3,0x3039
 * 0x80051078  aca29e30  sw $v0,-25040($a1)
 * 0x8005107c  00021403  sra $v0,$v0,16
 * 0x80051080  80830000  lb $v1,0($a0)
 * 0x80051084  3042000f  andi $v0,$v0,0x000f
 * 0x80051088  00621821  addu $v1,$v1,$v0
 * 0x8005108c  2463fff8  addiu $v1,$v1,0xfff8
 * 0x80051090  28620080  op&0x0a $v0,$v1,0x0080
 * 0x80051094  14400003  bne $v0,$zero,+3
 * 0x80051098  2862ff80  op&0x0a $v0,$v1,0xff80
 * 0x8005109c  0801442b  j 0x800510ac
 * 0x800510a0  24030080  addiu $v1,$zero,0x0080
 * 0x800510a4  54400001  op&0x15 $zero,$v0,0x0001
 * 0x800510a8  2403ff80  addiu $v1,$zero,0xff80
 * 0x800510ac  a0830000  sb $v1,0($a0)
 * 0x800510b0  24840030  addiu $a0,$a0,0x0030
 * 0x800510b4  080143f4  j 0x80050fd0
 * 0x800510b8  24c6fffd  addiu $a2,$a2,0xfffd
 * 0x800510bc  03e00008  jr $ra
 * 0x800510c0  00000000  sll $zero,$zero,0
 */
