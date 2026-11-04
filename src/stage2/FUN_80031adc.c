/* FUN_80031adc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031adc  body 0x80031adc..0x80031b77  size 156 B
 * body sha256 2cdb0c2309122c1d2cf47dfe296a4fd82dca1c3dffe9a707323347132169555b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 39 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80031adc  00000000  sll $zero,$zero,0
 * 0x80031ae0  3c030001  lui $v1,0x0001
 * 0x80031ae4  34638000  ori $v1,$v1,0x8000
 * 0x80031ae8  2407ffff  addiu $a3,$zero,0xffff
 * 0x80031aec  240bfff8  addiu $t3,$zero,0xfff8
 * 0x80031af0  3c02800c  lui $v0,0x800c
 * 0x80031af4  244976b0  addiu $t1,$v0,0x76b0
 * 0x80031af8  01231821  addu $v1,$t1,$v1
 * 0x80031afc  90651a76  lbu $a1,6774($v1)
 * 0x80031b00  24080300  addiu $t0,$zero,0x0300
 * 0x80031b04  00a80018  mult $a1,$t0
 * 0x80031b08  3c0a0001  lui $t2,0x0001
 * 0x80031b0c  354a8000  ori $t2,$t2,0x8000
 * 0x80031b10  24060004  addiu $a2,$zero,0x0004
 * 0x80031b14  8c640284  lw $a0,644($v1)
 * 0x80031b18  00006012  mflo $t4
 * 0x80031b1c  008c1021  addu $v0,$a0,$t4
 * 0x80031b20  ac620284  sw $v0,644($v1)
 * 0x80031b24  24820008  addiu $v0,$a0,0x0008
 * 0x80031b28  004b2024  and $a0,$v0,$t3
 * 0x80031b2c  01261021  addu $v0,$t1,$a2
 * 0x80031b30  004a1021  addu $v0,$v0,$t2
 * 0x80031b34  ac441d38  sw $a0,7480($v0)
 * 0x80031b38  ac800000  sw $zero,0($a0)
 * 0x80031b3c  00882021  addu $a0,$a0,$t0
 * 0x80031b40  24c60004  addiu $a2,$a2,0x0004
 * 0x80031b44  24a5ffff  addiu $a1,$a1,0xffff
 * 0x80031b48  14a0fff6  bne $a1,$zero,-10
 * 0x80031b4c  24e70001  addiu $a3,$a3,0x0001
 * 0x80031b50  3c020001  lui $v0,0x0001
 * 0x80031b54  34428000  ori $v0,$v0,0x8000
 * 0x80031b58  3c040001  lui $a0,0x0001
 * 0x80031b5c  34849d40  ori $a0,$a0,0x9d40
 * 0x80031b60  01221021  addu $v0,$t1,$v0
 * 0x80031b64  00071880  sll $v1,$a3,2
 * 0x80031b68  00641821  addu $v1,$v1,$a0
 * 0x80031b6c  01231821  addu $v1,$t1,$v1
 * 0x80031b70  03e00008  jr $ra
 * 0x80031b74  ac43028c  sw $v1,652($v0)
 */
