/* FUN_8007c5b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c5b4  body 0x8007c5b4..0x8007c713  size 352 B
 * body sha256 bfb9a8e9cdb7a7a64beeeda07e3840439ca88efaf376fab67a61c91a772442cf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 88 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8007c5b4  3c028012  lui $v0,0x8012
 * 0x8007c5b8  8c45b54c  lw $a1,-19124($v0)
 * 0x8007c5bc  10a00025  beq $a1,$zero,+37
 * 0x8007c5c0  00803021  addu $a2,$a0,$zero
 * 0x8007c5c4  94a2002e  lhu $v0,46($a1)
 * 0x8007c5c8  94c3002e  lhu $v1,46($a2)
 * 0x8007c5cc  84a401f2  lh $a0,498($a1)
 * 0x8007c5d0  04800020  op&0x01 $zero,$a0,0x0020
 * 0x8007c5d4  00431823  subu $v1,$v0,$v1
 * 0x8007c5d8  94a201aa  lhu $v0,426($a1)
 * 0x8007c5dc  30422000  andi $v0,$v0,0x2000
 * 0x8007c5e0  1440001d  bne $v0,$zero,+29
 * 0x8007c5e4  3c028012  lui $v0,0x8012
 * 0x8007c5e8  00031400  sll $v0,$v1,16
 * 0x8007c5ec  00021c03  sra $v1,$v0,16
 * 0x8007c5f0  2862ec79  op&0x0a $v0,$v1,0xec79
 * 0x8007c5f4  14400018  bne $v0,$zero,+24
 * 0x8007c5f8  3c028012  lui $v0,0x8012
 * 0x8007c5fc  286207d0  op&0x0a $v0,$v1,0x07d0
 * 0x8007c600  10400014  beq $v0,$zero,+20
 * 0x8007c604  3c020105  lui $v0,0x0105
 * 0x8007c608  94c301f0  lhu $v1,496($a2)
 * 0x8007c60c  acc20004  sw $v0,4($a2)
 * 0x8007c610  acc50250  sw $a1,592($a2)
 * 0x8007c614  30631fff  andi $v1,$v1,0x1fff
 * 0x8007c618  34644000  ori $a0,$v1,0x4000
 * 0x8007c61c  a4c401f0  sh $a0,496($a2)
 * 0x8007c620  94a2002e  lhu $v0,46($a1)
 * 0x8007c624  94c3002e  lhu $v1,46($a2)
 * 0x8007c628  00431023  subu $v0,$v0,$v1
 * 0x8007c62c  00404021  addu $t0,$v0,$zero
 * 0x8007c630  00021400  sll $v0,$v0,16
 * 0x8007c634  00021c03  sra $v1,$v0,16
 * 0x8007c638  2862f830  op&0x0a $v0,$v1,0xf830
 * 0x8007c63c  1040002a  beq $v0,$zero,+42
 * 0x8007c640  2862ec79  op&0x0a $v0,$v1,0xec79
 * 0x8007c644  14400029  bne $v0,$zero,+41
 * 0x8007c648  250201f3  addiu $v0,$t0,0x01f3
 * 0x8007c64c  0801f1b8  j 0x8007c6e0
 * 0x8007c650  30821fff  andi $v0,$a0,0x1fff
 * 0x8007c654  3c028012  lui $v0,0x8012
 * 0x8007c658  8c45b550  lw $a1,-19120($v0)
 * 0x8007c65c  3c028012  lui $v0,0x8012
 * 0x8007c660  9444b562  lhu $a0,-19102($v0)
 * 0x8007c664  10a00029  beq $a1,$zero,+41
 * 0x8007c668  00000000  sll $zero,$zero,0
 * 0x8007c66c  94a2002e  lhu $v0,46($a1)
 * 0x8007c670  94c3002e  lhu $v1,46($a2)
 * 0x8007c674  00431823  subu $v1,$v0,$v1
 * 0x8007c678  84a201f2  lh $v0,498($a1)
 * 0x8007c67c  04400023  op&0x01 $zero,$v0,0x0023
 * 0x8007c680  00604021  addu $t0,$v1,$zero
 * 0x8007c684  94a201aa  lhu $v0,426($a1)
 * 0x8007c688  30422000  andi $v0,$v0,0x2000
 * 0x8007c68c  1440001f  bne $v0,$zero,+31
 * 0x8007c690  2c8207d0  op&0x0b $v0,$a0,0x07d0
 * 0x8007c694  1040001d  beq $v0,$zero,+29
 * 0x8007c698  00031400  sll $v0,$v1,16
 * 0x8007c69c  00022403  sra $a0,$v0,16
 * 0x8007c6a0  2887ec79  op&0x0a $a3,$a0,0xec79
 * 0x8007c6a4  14e00019  bne $a3,$zero,+25
 * 0x8007c6a8  288207d0  op&0x0a $v0,$a0,0x07d0
 * 0x8007c6ac  10400017  beq $v0,$zero,+23
 * 0x8007c6b0  3c030105  lui $v1,0x0105
 * 0x8007c6b4  94c201f0  lhu $v0,496($a2)
 * 0x8007c6b8  acc30004  sw $v1,4($a2)
 * 0x8007c6bc  acc50250  sw $a1,592($a2)
 * 0x8007c6c0  30421fff  andi $v0,$v0,0x1fff
 * 0x8007c6c4  34434000  ori $v1,$v0,0x4000
 * 0x8007c6c8  2882f830  op&0x0a $v0,$a0,0xf830
 * 0x8007c6cc  10400006  beq $v0,$zero,+6
 * 0x8007c6d0  a4c301f0  sh $v1,496($a2)
 * 0x8007c6d4  14e00005  bne $a3,$zero,+5
 * 0x8007c6d8  250201f3  addiu $v0,$t0,0x01f3
 * 0x8007c6dc  30621fff  andi $v0,$v1,0x1fff
 * 0x8007c6e0  34428000  ori $v0,$v0,0x8000
 * 0x8007c6e4  a4c201f0  sh $v0,496($a2)
 * 0x8007c6e8  250201f3  addiu $v0,$t0,0x01f3
 * 0x8007c6ec  3042ffff  andi $v0,$v0,0xffff
 * 0x8007c6f0  2c4209c3  op&0x0b $v0,$v0,0x09c3
 * 0x8007c6f4  10400005  beq $v0,$zero,+5
 * 0x8007c6f8  00000000  sll $zero,$zero,0
 * 0x8007c6fc  94c201f0  lhu $v0,496($a2)
 * 0x8007c700  30421fff  andi $v0,$v0,0x1fff
 * 0x8007c704  34422000  ori $v0,$v0,0x2000
 * 0x8007c708  a4c201f0  sh $v0,496($a2)
 * 0x8007c70c  03e00008  jr $ra
 * 0x8007c710  00000000  sll $zero,$zero,0
 */
