/* FUN_80071b94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071b94  body 0x80071b94..0x80071c9f  size 268 B
 * body sha256 fc828bc50184bf9c3b7ad1c49338a8d091a432a4a797854fe197df6e99734d32
 * EXTENT MEASURED, NOT RECONSTRUCTED: 67 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80071b94  8c82001c  lw $v0,28($a0)
 * 0x80071b98  8c850154  lw $a1,340($a0)
 * 0x80071b9c  90460001  lbu $a2,1($v0)
 * 0x80071ba0  8ca30234  lw $v1,564($a1)
 * 0x80071ba4  24020080  addiu $v0,$zero,0x0080
 * 0x80071ba8  a0a2025c  sb $v0,604($a1)
 * 0x80071bac  8c82001c  lw $v0,28($a0)
 * 0x80071bb0  246b0bc0  addiu $t3,$v1,0x0bc0
 * 0x80071bb4  2cc30007  op&0x0b $v1,$a2,0x0007
 * 0x80071bb8  84480002  lh $t0,2($v0)
 * 0x80071bbc  84490004  lh $t1,4($v0)
 * 0x80071bc0  844a0006  lh $t2,6($v0)
 * 0x80071bc4  84470008  lh $a3,8($v0)
 * 0x80071bc8  1060001c  beq $v1,$zero,+28
 * 0x80071bcc  3c02800c  lui $v0,0x800c
 * 0x80071bd0  24429990  addiu $v0,$v0,0x9990
 * 0x80071bd4  00061880  sll $v1,$a2,2
 * 0x80071bd8  00621821  addu $v1,$v1,$v0
 * 0x80071bdc  8c620000  lw $v0,0($v1)
 * 0x80071be0  00400008  jr $v0
 * 0x80071be4  00000000  sll $zero,$zero,0
 * 0x80071be8  90a2025c  lbu $v0,604($a1)
 * 0x80071bec  34420012  ori $v0,$v0,0x0012
 * 0x80071bf0  0801c70f  j 0x80071c3c
 * 0x80071bf4  a0a2025c  sb $v0,604($a1)
 * 0x80071bf8  90a2025c  lbu $v0,604($a1)
 * 0x80071bfc  34420008  ori $v0,$v0,0x0008
 * 0x80071c00  0801c70f  j 0x80071c3c
 * 0x80071c04  a0a2025c  sb $v0,604($a1)
 * 0x80071c08  90a2025c  lbu $v0,604($a1)
 * 0x80071c0c  3442002a  ori $v0,$v0,0x002a
 * 0x80071c10  0801c70f  j 0x80071c3c
 * 0x80071c14  a0a2025c  sb $v0,604($a1)
 * 0x80071c18  90a2025c  lbu $v0,604($a1)
 * 0x80071c1c  34420058  ori $v0,$v0,0x0058
 * 0x80071c20  0801c70f  j 0x80071c3c
 * 0x80071c24  a0a2025c  sb $v0,604($a1)
 * 0x80071c28  90a2025c  lbu $v0,604($a1)
 * 0x80071c2c  34420004  ori $v0,$v0,0x0004
 * 0x80071c30  0801c70f  j 0x80071c3c
 * 0x80071c34  a0a2025c  sb $v0,604($a1)
 * 0x80071c38  a0a0025c  sb $zero,604($a1)
 * 0x80071c3c  24020005  addiu $v0,$zero,0x0005
 * 0x80071c40  a4a8020c  sh $t0,524($a1)
 * 0x80071c44  a4a9020e  sh $t1,526($a1)
 * 0x80071c48  14c2000d  bne $a2,$v0,+13
 * 0x80071c4c  a4aa0210  sh $t2,528($a1)
 * 0x80071c50  84a3020c  lh $v1,524($a1)
 * 0x80071c54  24060001  addiu $a2,$zero,0x0001
 * 0x80071c58  50660007  op&0x14 $a2,$v1,0x0007
 * 0x80071c5c  a4a0020c  sh $zero,524($a1)
 * 0x80071c60  24020002  addiu $v0,$zero,0x0002
 * 0x80071c64  50620004  op&0x14 $v0,$v1,0x0004
 * 0x80071c68  a4a6020c  sh $a2,524($a1)
 * 0x80071c6c  94a2020e  lhu $v0,526($a1)
 * 0x80071c70  24420002  addiu $v0,$v0,0x0002
 * 0x80071c74  a4a2020c  sh $v0,524($a1)
 * 0x80071c78  24028000  addiu $v0,$zero,0x8000
 * 0x80071c7c  a4a2020e  sh $v0,526($a1)
 * 0x80071c80  00071202  srl $v0,$a3,8
 * 0x80071c84  a162013c  sb $v0,316($t3)
 * 0x80071c88  a167013d  sb $a3,317($t3)
 * 0x80071c8c  8c82001c  lw $v0,28($a0)
 * 0x80071c90  2442000a  addiu $v0,$v0,0x000a
 * 0x80071c94  ac82001c  sw $v0,28($a0)
 * 0x80071c98  03e00008  jr $ra
 * 0x80071c9c  24020001  addiu $v0,$zero,0x0001
 */
