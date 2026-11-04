/* FUN_8006f740
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006f740  body 0x8006f740..0x8006f8af  size 368 B
 * body sha256 e94c1e2dd3c3312aa65ba8a99aa17f311fc826b0126374b08c4e70805b4b1476
 * EXTENT MEASURED, NOT RECONSTRUCTED: 92 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006f740  3c02800c  lui $v0,0x800c
 * 0x8006f744  244976b0  addiu $t1,$v0,0x76b0
 * 0x8006f748  24020040  addiu $v0,$zero,0x0040
 * 0x8006f74c  8c88001c  lw $t0,28($a0)
 * 0x8006f750  8c870154  lw $a3,340($a0)
 * 0x8006f754  91050002  lbu $a1,2($t0)
 * 0x8006f758  91060003  lbu $a2,3($t0)
 * 0x8006f75c  30a300c0  andi $v1,$a1,0x00c0
 * 0x8006f760  1062000f  beq $v1,$v0,+15
 * 0x8006f764  2c620041  op&0x0b $v0,$v1,0x0041
 * 0x8006f768  50400005  op&0x14 $zero,$v0,0x0005
 * 0x8006f76c  24020080  addiu $v0,$zero,0x0080
 * 0x8006f770  50600009  op&0x14 $zero,$v1,0x0009
 * 0x8006f774  3c02800f  lui $v0,0x800f
 * 0x8006f778  0801be1c  j 0x8006f870
 * 0x8006f77c  00000000  sll $zero,$zero,0
 * 0x8006f780  10620012  beq $v1,$v0,+18
 * 0x8006f784  240200c0  addiu $v0,$zero,0x00c0
 * 0x8006f788  1062002d  beq $v1,$v0,+45
 * 0x8006f78c  3c03ffff  lui $v1,0xffff
 * 0x8006f790  0801be1c  j 0x8006f870
 * 0x8006f794  00000000  sll $zero,$zero,0
 * 0x8006f798  0801be1b  j 0x8006f86c
 * 0x8006f79c  24429028  addiu $v0,$v0,0x9028
 * 0x8006f7a0  30c20080  andi $v0,$a2,0x0080
 * 0x8006f7a4  10400005  beq $v0,$zero,+5
 * 0x8006f7a8  30c3007f  andi $v1,$a2,0x007f
 * 0x8006f7ac  3c020001  lui $v0,0x0001
 * 0x8006f7b0  34429a80  ori $v0,$v0,0x9a80
 * 0x8006f7b4  0801bdfd  j 0x8006f7f4
 * 0x8006f7b8  01222821  addu $a1,$t1,$v0
 * 0x8006f7bc  3c020001  lui $v0,0x0001
 * 0x8006f7c0  34429a94  ori $v0,$v0,0x9a94
 * 0x8006f7c4  0801be1b  j 0x8006f86c
 * 0x8006f7c8  01221021  addu $v0,$t1,$v0
 * 0x8006f7cc  30c20080  andi $v0,$a2,0x0080
 * 0x8006f7d0  10400012  beq $v0,$zero,+18
 * 0x8006f7d4  3c030001  lui $v1,0x0001
 * 0x8006f7d8  34638000  ori $v1,$v1,0x8000
 * 0x8006f7dc  24a2ff80  addiu $v0,$a1,0xff80
 * 0x8006f7e0  00021080  sll $v0,$v0,2
 * 0x8006f7e4  00491021  addu $v0,$v0,$t1
 * 0x8006f7e8  00431021  addu $v0,$v0,$v1
 * 0x8006f7ec  30c3007f  andi $v1,$a2,0x007f
 * 0x8006f7f0  8c451d38  lw $a1,7480($v0)
 * 0x8006f7f4  00031040  sll $v0,$v1,1
 * 0x8006f7f8  00431021  addu $v0,$v0,$v1
 * 0x8006f7fc  00021100  sll $v0,$v0,4
 * 0x8006f800  00431023  subu $v0,$v0,$v1
 * 0x8006f804  8ca30234  lw $v1,564($a1)
 * 0x8006f808  000210c0  sll $v0,$v0,3
 * 0x8006f80c  00621821  addu $v1,$v1,$v0
 * 0x8006f810  24630038  addiu $v1,$v1,0x0038
 * 0x8006f814  0801be1c  j 0x8006f870
 * 0x8006f818  ace30070  sw $v1,112($a3)
 * 0x8006f81c  3c020001  lui $v0,0x0001
 * 0x8006f820  34428000  ori $v0,$v0,0x8000
 * 0x8006f824  24a3ff80  addiu $v1,$a1,0xff80
 * 0x8006f828  00031880  sll $v1,$v1,2
 * 0x8006f82c  00691821  addu $v1,$v1,$t1
 * 0x8006f830  00621821  addu $v1,$v1,$v0
 * 0x8006f834  8c621d38  lw $v0,7480($v1)
 * 0x8006f838  0801be1b  j 0x8006f86c
 * 0x8006f83c  24420014  addiu $v0,$v0,0x0014
 * 0x8006f840  34631448  ori $v1,$v1,0x1448
 * 0x8006f844  000510c0  sll $v0,$a1,3
 * 0x8006f848  00451023  subu $v0,$v0,$a1
 * 0x8006f84c  00021080  sll $v0,$v0,2
 * 0x8006f850  00451023  subu $v0,$v0,$a1
 * 0x8006f854  00021080  sll $v0,$v0,2
 * 0x8006f858  00451021  addu $v0,$v0,$a1
 * 0x8006f85c  000210c0  sll $v0,$v0,3
 * 0x8006f860  00431021  addu $v0,$v0,$v1
 * 0x8006f864  00491021  addu $v0,$v0,$t1
 * 0x8006f868  24420044  addiu $v0,$v0,0x0044
 * 0x8006f86c  ace20070  sw $v0,112($a3)
 * 0x8006f870  85020004  lh $v0,4($t0)
 * 0x8006f874  85030006  lh $v1,6($t0)
 * 0x8006f878  85050008  lh $a1,8($t0)
 * 0x8006f87c  ace20028  sw $v0,40($a3)
 * 0x8006f880  ace3002c  sw $v1,44($a3)
 * 0x8006f884  ace50030  sw $a1,48($a3)
 * 0x8006f888  8502000a  lh $v0,10($t0)
 * 0x8006f88c  8503000c  lh $v1,12($t0)
 * 0x8006f890  8505000e  lh $a1,14($t0)
 * 0x8006f894  a4e20064  sh $v0,100($a3)
 * 0x8006f898  25020010  addiu $v0,$t0,0x0010
 * 0x8006f89c  a4e30066  sh $v1,102($a3)
 * 0x8006f8a0  a4e50068  sh $a1,104($a3)
 * 0x8006f8a4  ac82001c  sw $v0,28($a0)
 * 0x8006f8a8  03e00008  jr $ra
 * 0x8006f8ac  24020001  addiu $v0,$zero,0x0001
 */
