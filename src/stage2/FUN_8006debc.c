/* FUN_8006debc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006debc  body 0x8006debc..0x8006df77  size 188 B
 * body sha256 c34503982437d87c9c64129e5f4c9798325872822df804a96e1dbbfa8caa6782
 * EXTENT MEASURED, NOT RECONSTRUCTED: 47 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8006debc  00805021  addu $t2,$a0,$zero
 * 0x8006dec0  8d47001c  lw $a3,28($t2)
 * 0x8006dec4  3c02800f  lui $v0,0x800f
 * 0x8006dec8  90e30005  lbu $v1,5($a3)
 * 0x8006decc  244b8c78  addiu $t3,$v0,0x8c78
 * 0x8006ded0  00031840  sll $v1,$v1,1
 * 0x8006ded4  006b1821  addu $v1,$v1,$t3
 * 0x8006ded8  84620000  lh $v0,0($v1)
 * 0x8006dedc  81490002  lb $t1,2($t2)
 * 0x8006dee0  1040001f  beq $v0,$zero,+31
 * 0x8006dee4  01493021  addu $a2,$t2,$t1
 * 0x8006dee8  90c40008  lbu $a0,8($a2)
 * 0x8006deec  000910c0  sll $v0,$t1,3
 * 0x8006def0  24840001  addiu $a0,$a0,0x0001
 * 0x8006def4  a0c40008  sb $a0,8($a2)
 * 0x8006def8  84e80002  lh $t0,2($a3)
 * 0x8006defc  90e50005  lbu $a1,5($a3)
 * 0x8006df00  24e70006  addiu $a3,$a3,0x0006
 * 0x8006df04  00042600  sll $a0,$a0,24
 * 0x8006df08  00042603  sra $a0,$a0,24
 * 0x8006df0c  00041840  sll $v1,$a0,1
 * 0x8006df10  00621821  addu $v1,$v1,$v0
 * 0x8006df14  00052840  sll $a1,$a1,1
 * 0x8006df18  00ab2821  addu $a1,$a1,$t3
 * 0x8006df1c  94a20000  lhu $v0,0($a1)
 * 0x8006df20  01431821  addu $v1,$t2,$v1
 * 0x8006df24  a46200a0  sh $v0,160($v1)
 * 0x8006df28  00041080  sll $v0,$a0,2
 * 0x8006df2c  00091900  sll $v1,$t1,4
 * 0x8006df30  00431021  addu $v0,$v0,$v1
 * 0x8006df34  01421021  addu $v0,$t2,$v0
 * 0x8006df38  00e81821  addu $v1,$a3,$t0
 * 0x8006df3c  ad47001c  sw $a3,28($t2)
 * 0x8006df40  ac430060  sw $v1,96($v0)
 * 0x8006df44  ac470020  sw $a3,32($v0)
 * 0x8006df48  00091080  sll $v0,$t1,2
 * 0x8006df4c  00822021  addu $a0,$a0,$v0
 * 0x8006df50  90c20004  lbu $v0,4($a2)
 * 0x8006df54  01442021  addu $a0,$t2,$a0
 * 0x8006df58  0801b7dc  j 0x8006df70
 * 0x8006df5c  a082000c  sb $v0,12($a0)
 * 0x8006df60  84e80002  lh $t0,2($a3)
 * 0x8006df64  00e81021  addu $v0,$a3,$t0
 * 0x8006df68  24420006  addiu $v0,$v0,0x0006
 * 0x8006df6c  ad42001c  sw $v0,28($t2)
 * 0x8006df70  03e00008  jr $ra
 * 0x8006df74  24020001  addiu $v0,$zero,0x0001
 */
