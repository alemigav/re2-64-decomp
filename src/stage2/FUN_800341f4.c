/* FUN_800341f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341f4  body 0x800341f4..0x8003427f  size 140 B
 * body sha256 e0dc45d2d5b088c1586b9b2b3a02ab16d9ee29300314c30c13f9252dcda7be57
 * EXTENT MEASURED, NOT RECONSTRUCTED: 35 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800341f4  04e00020  op&0x01 $zero,$a3,0x0020
 * 0x800341f8  240dffff  addiu $t5,$zero,0xffff
 * 0x800341fc  00052a00  sll $a1,$a1,8
 * 0x80034200  8c8200c8  lw $v0,200($a0)
 * 0x80034204  00063200  sll $a2,$a2,8
 * 0x80034208  8c4a0004  lw $t2,4($v0)
 * 0x8003420c  8c4b0000  lw $t3,0($v0)
 * 0x80034210  2549000e  addiu $t1,$t2,0x000e
 * 0x80034214  256bffff  addiu $t3,$t3,0xffff
 * 0x80034218  116d0017  beq $t3,$t5,+23
 * 0x8003421c  00000000  sll $zero,$zero,0
 * 0x80034220  8d22fffa  lw $v0,-6($t1)
 * 0x80034224  8c420008  lw $v0,8($v0)
 * 0x80034228  54470011  op&0x15 $a3,$v0,0x0011
 * 0x8003422c  25290010  addiu $t1,$t1,0x0010
 * 0x80034230  85280000  lh $t0,0($t1)
 * 0x80034234  8d430000  lw $v1,0($t2)
 * 0x80034238  2508ffff  addiu $t0,$t0,0xffff
 * 0x8003423c  110d000b  beq $t0,$t5,+11
 * 0x80034240  240cffff  addiu $t4,$zero,0xffff
 * 0x80034244  2464000a  addiu $a0,$v1,0x000a
 * 0x80034248  2508ffff  addiu $t0,$t0,0xffff
 * 0x8003424c  9482fffe  lhu $v0,-2($a0)
 * 0x80034250  94830000  lhu $v1,0($a0)
 * 0x80034254  00451021  addu $v0,$v0,$a1
 * 0x80034258  00661821  addu $v1,$v1,$a2
 * 0x8003425c  a482fffe  sh $v0,-2($a0)
 * 0x80034260  a4830000  sh $v1,0($a0)
 * 0x80034264  150cfff8  bne $t0,$t4,-8
 * 0x80034268  24840010  addiu $a0,$a0,0x0010
 * 0x8003426c  25290010  addiu $t1,$t1,0x0010
 * 0x80034270  0800d085  j 0x80034214
 * 0x80034274  254a0010  addiu $t2,$t2,0x0010
 * 0x80034278  03e00008  jr $ra
 * 0x8003427c  00000000  sll $zero,$zero,0
 */
