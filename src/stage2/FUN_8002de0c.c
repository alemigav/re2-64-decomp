/* FUN_8002de0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002de0c  body 0x8002de0c..0x8002df13  size 264 B
 * body sha256 4cade8bae0c700b3c29a76428356d821a3d8a2abd294cdb26d500ef40c05200a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 66 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8002de0c  00000000  sll $zero,$zero,0
 * 0x8002de10  3c03800f  lui $v1,0x800f
 * 0x8002de14  8c890180  lw $t1,384($a0)
 * 0x8002de18  8c639260  lw $v1,-28064($v1)
 * 0x8002de1c  3c02800f  lui $v0,0x800f
 * 0x8002de20  ad200024  sw $zero,36($t1)
 * 0x8002de24  8c840060  lw $a0,96($a0)
 * 0x8002de28  24429264  addiu $v0,$v0,0x9264
 * 0x8002de2c  ad220010  sw $v0,16($t1)
 * 0x8002de30  3c02800f  lui $v0,0x800f
 * 0x8002de34  24429664  addiu $v0,$v0,0x9664
 * 0x8002de38  ad220014  sw $v0,20($t1)
 * 0x8002de3c  3c02800f  lui $v0,0x800f
 * 0x8002de40  24429a64  addiu $v0,$v0,0x9a64
 * 0x8002de44  ad220018  sw $v0,24($t1)
 * 0x8002de48  3c02800f  lui $v0,0x800f
 * 0x8002de4c  24429e64  addiu $v0,$v0,0x9e64
 * 0x8002de50  ad22001c  sw $v0,28($t1)
 * 0x8002de54  1460002d  bne $v1,$zero,+45
 * 0x8002de58  ad24002c  sw $a0,44($t1)
 * 0x8002de5c  00005021  addu $t2,$zero,$zero
 * 0x8002de60  340f8000  ori $t7,$zero,0x8000
 * 0x8002de64  3c0e002b  lui $t6,0x002b
 * 0x8002de68  35cee0f3  ori $t6,$t6,0xe0f3
 * 0x8002de6c  3c0d005b  lui $t5,0x005b
 * 0x8002de70  35ad0d97  ori $t5,$t5,0x0d97
 * 0x8002de74  3c0cff1e  lui $t4,0xff1e
 * 0x8002de78  358c11d1  ori $t4,$t4,0x11d1
 * 0x8002de7c  3c0bff4d  lui $t3,0xff4d
 * 0x8002de80  356b3e75  ori $t3,$t3,0x3e75
 * 0x8002de84  01cf4021  addu $t0,$t6,$t7
 * 0x8002de88  25cea7e6  addiu $t6,$t6,0xa7e6
 * 0x8002de8c  3c07ffff  lui $a3,0xffff
 * 0x8002de90  34e7492e  ori $a3,$a3,0x492e
 * 0x8002de94  3c020001  lui $v0,0x0001
 * 0x8002de98  3442c5a2  ori $v0,$v0,0xc5a2
 * 0x8002de9c  018f2821  addu $a1,$t4,$t7
 * 0x8002dea0  01826021  addu $t4,$t4,$v0
 * 0x8002dea4  3c060001  lui $a2,0x0001
 * 0x8002dea8  34c666ea  ori $a2,$a2,0x66ea
 * 0x8002deac  000a2080  sll $a0,$t2,2
 * 0x8002deb0  016f1021  addu $v0,$t3,$t7
 * 0x8002deb4  00021403  sra $v0,$v0,16
 * 0x8002deb8  8d230010  lw $v1,16($t1)
 * 0x8002debc  01665821  addu $t3,$t3,$a2
 * 0x8002dec0  00831821  addu $v1,$a0,$v1
 * 0x8002dec4  ac620000  sw $v0,0($v1)
 * 0x8002dec8  8d220014  lw $v0,20($t1)
 * 0x8002decc  00052c03  sra $a1,$a1,16
 * 0x8002ded0  00821021  addu $v0,$a0,$v0
 * 0x8002ded4  ac450000  sw $a1,0($v0)
 * 0x8002ded8  8d220018  lw $v0,24($t1)
 * 0x8002dedc  254a0001  addiu $t2,$t2,0x0001
 * 0x8002dee0  00821021  addu $v0,$a0,$v0
 * 0x8002dee4  ac4d0000  sw $t5,0($v0)
 * 0x8002dee8  8d22001c  lw $v0,28($t1)
 * 0x8002deec  01a76821  addu $t5,$t5,$a3
 * 0x8002def0  00822021  addu $a0,$a0,$v0
 * 0x8002def4  29420100  op&0x0a $v0,$t2,0x0100
 * 0x8002def8  1440ffe2  bne $v0,$zero,-30
 * 0x8002defc  ac880000  sw $t0,0($a0)
 * 0x8002df00  3c03800f  lui $v1,0x800f
 * 0x8002df04  24020001  addiu $v0,$zero,0x0001
 * 0x8002df08  ac629260  sw $v0,-28064($v1)
 * 0x8002df0c  03e00008  jr $ra
 * 0x8002df10  00000000  sll $zero,$zero,0
 */
