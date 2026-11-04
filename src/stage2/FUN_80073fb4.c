/* FUN_80073fb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073fb4  body 0x80073fb4..0x80074023  size 112 B
 * body sha256 70c196dddf80ea5a8b06cf6b839e4639a32c46a7ae603d9e8702d98db458bb55
 * EXTENT MEASURED, NOT RECONSTRUCTED: 28 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073fb4  3c028011  lui $v0,0x8011
 * 0x80073fb8  24425090  addiu $v0,$v0,0x5090
 * 0x80073fbc  94830000  lhu $v1,0($a0)
 * 0x80073fc0  94850002  lhu $a1,2($a0)
 * 0x80073fc4  94840004  lhu $a0,4($a0)
 * 0x80073fc8  00031880  sll $v1,$v1,2
 * 0x80073fcc  00621821  addu $v1,$v1,$v0
 * 0x80073fd0  000510c2  srl $v0,$a1,3
 * 0x80073fd4  8c630000  lw $v1,0($v1)
 * 0x80073fd8  3042001c  andi $v0,$v0,0x001c
 * 0x80073fdc  10800008  beq $a0,$zero,+8
 * 0x80073fe0  00623021  addu $a2,$v1,$v0
 * 0x80073fe4  30a2001f  andi $v0,$a1,0x001f
 * 0x80073fe8  3c038000  lui $v1,0x8000
 * 0x80073fec  8cc40000  lw $a0,0($a2)
 * 0x80073ff0  00431806  special&0x06 $v1,$v0,$v1
 * 0x80073ff4  00832025  or $a0,$a0,$v1
 * 0x80073ff8  0801d007  j 0x8007401c
 * 0x80073ffc  acc40000  sw $a0,0($a2)
 * 0x80074000  30a2001f  andi $v0,$a1,0x001f
 * 0x80074004  3c038000  lui $v1,0x8000
 * 0x80074008  00431806  special&0x06 $v1,$v0,$v1
 * 0x8007400c  8cc20000  lw $v0,0($a2)
 * 0x80074010  00031827  special&0x27 $v1,$zero,$v1
 * 0x80074014  00431024  and $v0,$v0,$v1
 * 0x80074018  acc20000  sw $v0,0($a2)
 * 0x8007401c  03e00008  jr $ra
 * 0x80074020  00001021  addu $v0,$zero,$zero
 */
