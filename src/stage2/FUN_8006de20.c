/* FUN_8006de20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006de20  body 0x8006de20..0x8006debb  size 156 B
 * body sha256 d74e0f7bff4d5c6fc61ff26d071a7ba0d5d313fb737298ef32addebcaa3de26e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 39 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8006de20  00805021  addu $t2,$a0,$zero
 * 0x8006de24  8d47001c  lw $a3,28($t2)
 * 0x8006de28  84e20004  lh $v0,4($a3)
 * 0x8006de2c  81490002  lb $t1,2($t2)
 * 0x8006de30  1040001c  beq $v0,$zero,+28
 * 0x8006de34  01492821  addu $a1,$t2,$t1
 * 0x8006de38  90a40008  lbu $a0,8($a1)
 * 0x8006de3c  000918c0  sll $v1,$t1,3
 * 0x8006de40  24840001  addiu $a0,$a0,0x0001
 * 0x8006de44  a0a40008  sb $a0,8($a1)
 * 0x8006de48  84e80002  lh $t0,2($a3)
 * 0x8006de4c  94e60004  lhu $a2,4($a3)
 * 0x8006de50  24e70006  addiu $a3,$a3,0x0006
 * 0x8006de54  00042600  sll $a0,$a0,24
 * 0x8006de58  00042603  sra $a0,$a0,24
 * 0x8006de5c  00041040  sll $v0,$a0,1
 * 0x8006de60  00431021  addu $v0,$v0,$v1
 * 0x8006de64  01421021  addu $v0,$t2,$v0
 * 0x8006de68  00091900  sll $v1,$t1,4
 * 0x8006de6c  a44600a0  sh $a2,160($v0)
 * 0x8006de70  00041080  sll $v0,$a0,2
 * 0x8006de74  00431021  addu $v0,$v0,$v1
 * 0x8006de78  01421021  addu $v0,$t2,$v0
 * 0x8006de7c  00e81821  addu $v1,$a3,$t0
 * 0x8006de80  ad47001c  sw $a3,28($t2)
 * 0x8006de84  ac430060  sw $v1,96($v0)
 * 0x8006de88  ac470020  sw $a3,32($v0)
 * 0x8006de8c  00091080  sll $v0,$t1,2
 * 0x8006de90  00822021  addu $a0,$a0,$v0
 * 0x8006de94  90a20004  lbu $v0,4($a1)
 * 0x8006de98  01442021  addu $a0,$t2,$a0
 * 0x8006de9c  0801b7ad  j 0x8006deb4
 * 0x8006dea0  a082000c  sb $v0,12($a0)
 * 0x8006dea4  84e80002  lh $t0,2($a3)
 * 0x8006dea8  00e81021  addu $v0,$a3,$t0
 * 0x8006deac  24420006  addiu $v0,$v0,0x0006
 * 0x8006deb0  ad42001c  sw $v0,28($t2)
 * 0x8006deb4  03e00008  jr $ra
 * 0x8006deb8  24020001  addiu $v0,$zero,0x0001
 */
