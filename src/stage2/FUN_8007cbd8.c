/* FUN_8007cbd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007cbd8  body 0x8007cbd8..0x8007cc23  size 76 B
 * body sha256 65a3721009ca95fc66c0c38abbf067c39318526bf27b60aa2deb95c757d04885
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007cbd8  84a201f2  lh $v0,498($a1)
 * 0x8007cbdc  0440000f  op&0x01 $zero,$v0,0x000f
 * 0x8007cbe0  00000000  sll $zero,$zero,0
 * 0x8007cbe4  94a201aa  lhu $v0,426($a1)
 * 0x8007cbe8  30420001  andi $v0,$v0,0x0001
 * 0x8007cbec  1040000b  beq $v0,$zero,+11
 * 0x8007cbf0  3c030400  lui $v1,0x0400
 * 0x8007cbf4  8ca20000  lw $v0,0($a1)
 * 0x8007cbf8  00431024  and $v0,$v0,$v1
 * 0x8007cbfc  10400007  beq $v0,$zero,+7
 * 0x8007cc00  3c030105  lui $v1,0x0105
 * 0x8007cc04  948201f0  lhu $v0,496($a0)
 * 0x8007cc08  ac830004  sw $v1,4($a0)
 * 0x8007cc0c  ac850250  sw $a1,592($a0)
 * 0x8007cc10  30421fff  andi $v0,$v0,0x1fff
 * 0x8007cc14  34422000  ori $v0,$v0,0x2000
 * 0x8007cc18  a48201f0  sh $v0,496($a0)
 * 0x8007cc1c  03e00008  jr $ra
 * 0x8007cc20  00000000  sll $zero,$zero,0
 */
