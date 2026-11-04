/* FUN_8007c3e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c3e0  body 0x8007c3e0..0x8007c4a7  size 200 B
 * body sha256 3d20a2af311176e8b8fab9b3b7cb6f56ba518883c583857fd216845c4f1ef2ee
 * EXTENT MEASURED, NOT RECONSTRUCTED: 50 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007c3e0  3c028012  lui $v0,0x8012
 * 0x8007c3e4  908302c6  lbu $v1,710($a0)
 * 0x8007c3e8  8c45b54c  lw $a1,-19124($v0)
 * 0x8007c3ec  1460002c  bne $v1,$zero,+44
 * 0x8007c3f0  00000000  sll $zero,$zero,0
 * 0x8007c3f4  10a00015  beq $a1,$zero,+21
 * 0x8007c3f8  3c028012  lui $v0,0x8012
 * 0x8007c3fc  84a201f2  lh $v0,498($a1)
 * 0x8007c400  04400012  op&0x01 $zero,$v0,0x0012
 * 0x8007c404  3c028012  lui $v0,0x8012
 * 0x8007c408  94a301aa  lhu $v1,426($a1)
 * 0x8007c40c  30622000  andi $v0,$v1,0x2000
 * 0x8007c410  1040001c  beq $v0,$zero,+28
 * 0x8007c414  30620001  andi $v0,$v1,0x0001
 * 0x8007c418  1040000b  beq $v0,$zero,+11
 * 0x8007c41c  3c030400  lui $v1,0x0400
 * 0x8007c420  8ca20000  lw $v0,0($a1)
 * 0x8007c424  00431024  and $v0,$v0,$v1
 * 0x8007c428  10400007  beq $v0,$zero,+7
 * 0x8007c42c  3c030105  lui $v1,0x0105
 * 0x8007c430  948201f0  lhu $v0,496($a0)
 * 0x8007c434  ac830004  sw $v1,4($a0)
 * 0x8007c438  ac850250  sw $a1,592($a0)
 * 0x8007c43c  30421fff  andi $v0,$v0,0x1fff
 * 0x8007c440  34422000  ori $v0,$v0,0x2000
 * 0x8007c444  a48201f0  sh $v0,496($a0)
 * 0x8007c448  3c028012  lui $v0,0x8012
 * 0x8007c44c  8c45b550  lw $a1,-19120($v0)
 * 0x8007c450  3c028012  lui $v0,0x8012
 * 0x8007c454  9443b562  lhu $v1,-19102($v0)
 * 0x8007c458  10a00011  beq $a1,$zero,+17
 * 0x8007c45c  00000000  sll $zero,$zero,0
 * 0x8007c460  84a201f2  lh $v0,498($a1)
 * 0x8007c464  0440000e  op&0x01 $zero,$v0,0x000e
 * 0x8007c468  00000000  sll $zero,$zero,0
 * 0x8007c46c  94a201aa  lhu $v0,426($a1)
 * 0x8007c470  30422000  andi $v0,$v0,0x2000
 * 0x8007c474  1440000a  bne $v0,$zero,+10
 * 0x8007c478  2c620bb8  op&0x0b $v0,$v1,0x0bb8
 * 0x8007c47c  10400008  beq $v0,$zero,+8
 * 0x8007c480  00000000  sll $zero,$zero,0
 * 0x8007c484  948201f0  lhu $v0,496($a0)
 * 0x8007c488  3c030105  lui $v1,0x0105
 * 0x8007c48c  ac830004  sw $v1,4($a0)
 * 0x8007c490  ac850250  sw $a1,592($a0)
 * 0x8007c494  30421fff  andi $v0,$v0,0x1fff
 * 0x8007c498  34424000  ori $v0,$v0,0x4000
 * 0x8007c49c  a48201f0  sh $v0,496($a0)
 * 0x8007c4a0  03e00008  jr $ra
 * 0x8007c4a4  00000000  sll $zero,$zero,0
 */
