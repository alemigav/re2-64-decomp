/* FUN_8006e730
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e730  body 0x8006e730..0x8006e75f  size 48 B
 * body sha256 9568c9e526b8a2080bb912323aa366b6981ef5a40b76e5cb57c4eed3d50a2628
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e730  8c82001c  lw $v0,28($a0)
 * 0x8006e734  90430001  lbu $v1,1($v0)
 * 0x8006e738  84450002  lh $a1,2($v0)
 * 0x8006e73c  24420004  addiu $v0,$v0,0x0004
 * 0x8006e740  ac82001c  sw $v0,28($a0)
 * 0x8006e744  3c02800f  lui $v0,0x800f
 * 0x8006e748  24428c78  addiu $v0,$v0,0x8c78
 * 0x8006e74c  00031840  sll $v1,$v1,1
 * 0x8006e750  00621821  addu $v1,$v1,$v0
 * 0x8006e754  24020001  addiu $v0,$zero,0x0001
 * 0x8006e758  03e00008  jr $ra
 * 0x8006e75c  a4650000  sh $a1,0($v1)
 */
