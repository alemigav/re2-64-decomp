/* FUN_8006e48c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e48c  body 0x8006e48c..0x8006e4d3  size 72 B
 * body sha256 88d55086eaacfc16773ff32c2651b0040b1ce294f0364b9728473deb13f45b52
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e48c  80830002  lb $v1,2($a0)
 * 0x8006e490  00833821  addu $a3,$a0,$v1
 * 0x8006e494  00032900  sll $a1,$v1,4
 * 0x8006e498  80e60008  lb $a2,8($a3)
 * 0x8006e49c  00031880  sll $v1,$v1,2
 * 0x8006e4a0  00061080  sll $v0,$a2,2
 * 0x8006e4a4  00451021  addu $v0,$v0,$a1
 * 0x8006e4a8  00821021  addu $v0,$a0,$v0
 * 0x8006e4ac  8c420060  lw $v0,96($v0)
 * 0x8006e4b0  00c31821  addu $v1,$a2,$v1
 * 0x8006e4b4  ac82001c  sw $v0,28($a0)
 * 0x8006e4b8  00832021  addu $a0,$a0,$v1
 * 0x8006e4bc  9082000c  lbu $v0,12($a0)
 * 0x8006e4c0  24c6ffff  addiu $a2,$a2,0xffff
 * 0x8006e4c4  a0e60008  sb $a2,8($a3)
 * 0x8006e4c8  a0e20004  sb $v0,4($a3)
 * 0x8006e4cc  03e00008  jr $ra
 * 0x8006e4d0  24020001  addiu $v0,$zero,0x0001
 */
