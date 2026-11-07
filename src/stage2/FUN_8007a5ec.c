/* FUN_8007a5ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a5ec  body 0x8007a5ec..0x8007a6a7  size 188 B
 * body sha256 53f886de104c6550041d99506703c2f68c7e144839bb4a7ea8ad39ce153279d1
 * EXTENT MEASURED, NOT RECONSTRUCTED: 47 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8007a5ec..0x8007a6af, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8007a5ec  8c840234  lw $a0,564($a0)
 * 0x8007a5f0  2402ffd8  addiu $v0,$zero,0xffd8
 * 0x8007a5f4  24831608  addiu $v1,$a0,0x1608
 * 0x8007a5f8  ac62001c  sw $v0,28($v1)
 * 0x8007a5fc  2402fe90  addiu $v0,$zero,0xfe90
 * 0x8007a600  ac620020  sw $v0,32($v1)
 * 0x8007a604  ac600024  sw $zero,36($v1)
 * 0x8007a608  a4600130  sh $zero,304($v1)
 * 0x8007a60c  a4600132  sh $zero,306($v1)
 * 0x8007a610  a460005a  sh $zero,90($v1)
 * 0x8007a614  8c821608  lw $v0,5640($a0)
 * 0x8007a618  34420041  ori $v0,$v0,0x0041
 * 0x8007a61c  ac821608  sw $v0,5640($a0)
 * 0x8007a620  8c640178  lw $a0,376($v1)
 * 0x8007a624  2402ffd0  addiu $v0,$zero,0xffd0
 * 0x8007a628  ac620194  sw $v0,404($v1)
 * 0x8007a62c  2402ffe0  addiu $v0,$zero,0xffe0
 * 0x8007a630  ac620198  sw $v0,408($v1)
 * 0x8007a634  2402ffa5  addiu $v0,$zero,0xffa5
 * 0x8007a638  ac62030c  sw $v0,780($v1)
 * 0x8007a63c  24020061  addiu $v0,$zero,0x0061
 * 0x8007a640  ac620310  sw $v0,784($v1)
 * 0x8007a644  2402ffff  addiu $v0,$zero,0xffff
 * 0x8007a648  ac620484  sw $v0,1156($v1)
 * 0x8007a64c  2402007f  addiu $v0,$zero,0x007f
 * 0x8007a650  ac620488  sw $v0,1160($v1)
 * 0x8007a654  8c6202f0  lw $v0,752($v1)
 * 0x8007a658  ac60019c  sw $zero,412($v1)
 * 0x8007a65c  a46002a8  sh $zero,680($v1)
 * 0x8007a660  a46002aa  sh $zero,682($v1)
 * 0x8007a664  a46001d2  sh $zero,466($v1)
 * 0x8007a668  ac600314  sw $zero,788($v1)
 * 0x8007a66c  a4600420  sh $zero,1056($v1)
 * 0x8007a670  a4600422  sh $zero,1058($v1)
 * 0x8007a674  a460034a  sh $zero,842($v1)
 * 0x8007a678  ac60048c  sw $zero,1164($v1)
 * 0x8007a67c  a4600598  sh $zero,1432($v1)
 * 0x8007a680  a460059a  sh $zero,1434($v1)
 * 0x8007a684  a46004c2  sh $zero,1218($v1)
 * 0x8007a688  34840041  ori $a0,$a0,0x0041
 * 0x8007a68c  ac640178  sw $a0,376($v1)
 * 0x8007a690  8c640468  lw $a0,1128($v1)
 * 0x8007a694  34420041  ori $v0,$v0,0x0041
 * 0x8007a698  ac6202f0  sw $v0,752($v1)
 * 0x8007a69c  34840041  ori $a0,$a0,0x0041
 * 0x8007a6a0  03e00008  jr $ra
 * 0x8007a6a4  ac640468  sw $a0,1128($v1)
 */
