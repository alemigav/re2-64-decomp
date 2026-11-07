/* FUN_8006a42c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a42c  body 0x8006a42c..0x8006a4cf  size 164 B
 * body sha256 714996d9798818d661bddd18f26d45eec5c81bc5a20f30bcf39479bdbe004dbf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 41 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006a42c..0x8006a4cf, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006a42c  84a30000  lh $v1,0($a1)
 * 0x8006a430  8c820000  lw $v0,0($a0)
 * 0x8006a434  94a70006  lhu $a3,6($a1)
 * 0x8006a438  00431023  subu $v0,$v0,$v1
 * 0x8006a43c  00e20018  mult $a3,$v0
 * 0x8006a440  00001812  mflo $v1
 * 0x8006a444  94a20004  lhu $v0,4($a1)
 * 0x8006a448  00000000  sll $zero,$zero,0
 * 0x8006a44c  0062001a  div $v1,$v0
 * 0x8006a450  14400002  bne $v0,$zero,+2
 * 0x8006a454  00000000  sll $zero,$zero,0
 * 0x8006a458  0007000d  special&0x0d $zero,$zero,$a3
 * 0x8006a45c  2401ffff  addiu $at,$zero,0xffff
 * 0x8006a460  14410004  bne $v0,$at,+4
 * 0x8006a464  3c018000  lui $at,0x8000
 * 0x8006a468  14610002  bne $v1,$at,+2
 * 0x8006a46c  00000000  sll $zero,$zero,0
 * 0x8006a470  0006000d  special&0x0d $zero,$zero,$a2
 * 0x8006a474  00001812  mflo $v1
 * 0x8006a478  8c840008  lw $a0,8($a0)
 * 0x8006a47c  84a50002  lh $a1,2($a1)
 * 0x8006a480  00851023  subu $v0,$a0,$a1
 * 0x8006a484  0062102a  slt $v0,$v1,$v0
 * 0x8006a488  10400009  beq $v0,$zero,+9
 * 0x8006a48c  00003021  addu $a2,$zero,$zero
 * 0x8006a490  00031823  subu $v1,$zero,$v1
 * 0x8006a494  00a71021  addu $v0,$a1,$a3
 * 0x8006a498  00821023  subu $v0,$a0,$v0
 * 0x8006a49c  0062182a  slt $v1,$v1,$v0
 * 0x8006a4a0  10600009  beq $v1,$zero,+9
 * 0x8006a4a4  24060002  addiu $a2,$zero,0x0002
 * 0x8006a4a8  0801a932  j 0x8006a4c8
 * 0x8006a4ac  24060003  addiu $a2,$zero,0x0003
 * 0x8006a4b0  00031823  subu $v1,$zero,$v1
 * 0x8006a4b4  00a71021  addu $v0,$a1,$a3
 * 0x8006a4b8  00821023  subu $v0,$a0,$v0
 * 0x8006a4bc  0043102a  slt $v0,$v0,$v1
 * 0x8006a4c0  54400001  op&0x15 $zero,$v0,0x0001
 * 0x8006a4c4  24060001  addiu $a2,$zero,0x0001
 * 0x8006a4c8  03e00008  jr $ra
 * 0x8006a4cc  00c01021  addu $v0,$a2,$zero
 */
