/* FUN_8016371c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016371c  body 0x8016371c..0x801637a7  size 140 B
 * body sha256 4c397b21df05b435d5b13a1e69fc376c30055365ff63a643b544712a614c57ca
 * EXTENT MEASURED, NOT RECONSTRUCTED: 35 words, found by the extent scan inside a byte-map region no artifact names (extent measured, text withdrawn (M369): this function was reconstructed from an unlicensed third-party corpus and the reconstruction has been removed; the address, extent and word count stand, the C does not)
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
 * 0x8016371c  248602b4  addiu $a2,$a0,0x02b4
 * 0x80163720  2402002e  addiu $v0,$zero,0x002e
 * 0x80163724  90830008  lbu $v1,8($a0)
 * 0x80163728  90c50026  lbu $a1,38($a2)
 * 0x8016372c  54620001  op&0x15 $v0,$v1,0x0001
 * 0x80163730  24a50008  addiu $a1,$a1,0x0008
 * 0x80163734  2402005a  addiu $v0,$zero,0x005a
 * 0x80163738  a0c5000c  sb $a1,12($a2)
 * 0x8016373c  a0c2000b  sb $v0,11($a2)
 * 0x80163740  8c820000  lw $v0,0($a0)
 * 0x80163744  2403fffb  addiu $v1,$zero,0xfffb
 * 0x80163748  00431024  and $v0,$v0,$v1
 * 0x8016374c  ac820000  sw $v0,0($a0)
 * 0x80163750  a0c00002  sb $zero,2($a2)
 * 0x80163754  908302cd  lbu $v1,717($a0)
 * 0x80163758  24020100  addiu $v0,$zero,0x0100
 * 0x8016375c  a4820006  sh $v0,6($a0)
 * 0x80163760  00031040  sll $v0,$v1,1
 * 0x80163764  00431021  addu $v0,$v0,$v1
 * 0x80163768  00021080  sll $v0,$v0,2
 * 0x8016376c  00431021  addu $v0,$v0,$v1
 * 0x80163770  00021600  sll $v0,$v0,24
 * 0x80163774  24423f00  addiu $v0,$v0,0x3f00
 * 0x80163778  ac8201e8  sw $v0,488($a0)
 * 0x8016377c  90c20004  lbu $v0,4($a2)
 * 0x80163780  14400007  bne $v0,$zero,+7
 * 0x80163784  24020200  addiu $v0,$zero,0x0200
 * 0x80163788  a4820006  sh $v0,6($a0)
 * 0x8016378c  24020001  addiu $v0,$zero,0x0001
 * 0x80163790  a0c20012  sb $v0,18($a2)
 * 0x80163794  24020020  addiu $v0,$zero,0x0020
 * 0x80163798  a0c00013  sb $zero,19($a2)
 * 0x8016379c  a0c20014  sb $v0,20($a2)
 * 0x801637a0  03e00008  jr $ra
 * 0x801637a4  00000000  sll $zero,$zero,0
 */
