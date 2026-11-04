/* FUN_8006dbf4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dbf4  body 0x8006dbf4..0x8006dc33  size 64 B
 * body sha256 5f364926ada0ce8b0315eb5bff2f844b31c3fa11493562bc318fda5a9530c4fd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006dbf4  8c82001c  lw $v0,28($a0)
 * 0x8006dbf8  3c058011  lui $a1,0x8011
 * 0x8006dbfc  90420001  lbu $v0,1($v0)
 * 0x8006dc00  24a53ad0  addiu $a1,$a1,0x3ad0
 * 0x8006dc04  00021840  sll $v1,$v0,1
 * 0x8006dc08  00621821  addu $v1,$v1,$v0
 * 0x8006dc0c  00031140  sll $v0,$v1,5
 * 0x8006dc10  00431023  subu $v0,$v0,$v1
 * 0x8006dc14  00021080  sll $v0,$v0,2
 * 0x8006dc18  00451021  addu $v0,$v0,$a1
 * 0x8006dc1c  a0400001  sb $zero,1($v0)
 * 0x8006dc20  8c82001c  lw $v0,28($a0)
 * 0x8006dc24  24420002  addiu $v0,$v0,0x0002
 * 0x8006dc28  ac82001c  sw $v0,28($a0)
 * 0x8006dc2c  03e00008  jr $ra
 * 0x8006dc30  24020001  addiu $v0,$zero,0x0001
 */
