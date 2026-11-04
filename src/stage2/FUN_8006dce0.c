/* FUN_8006dce0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dce0  body 0x8006dce0..0x8006dd27  size 72 B
 * body sha256 6ea9b3ca1068bd0f0c1123f6f136c6a2932b1f97f478b85907218d76dba1eaa4
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
 * 0x8006dce0  8c82001c  lw $v0,28($a0)
 * 0x8006dce4  80830002  lb $v1,2($a0)
 * 0x8006dce8  00403021  addu $a2,$v0,$zero
 * 0x8006dcec  24420001  addiu $v0,$v0,0x0001
 * 0x8006dcf0  00832821  addu $a1,$a0,$v1
 * 0x8006dcf4  ac82001c  sw $v0,28($a0)
 * 0x8006dcf8  90a20008  lbu $v0,8($a1)
 * 0x8006dcfc  000318c0  sll $v1,$v1,3
 * 0x8006dd00  24420001  addiu $v0,$v0,0x0001
 * 0x8006dd04  a0a20008  sb $v0,8($a1)
 * 0x8006dd08  00021600  sll $v0,$v0,24
 * 0x8006dd0c  000215c3  sra $v0,$v0,23
 * 0x8006dd10  00431021  addu $v0,$v0,$v1
 * 0x8006dd14  00822021  addu $a0,$a0,$v0
 * 0x8006dd18  94c30002  lhu $v1,2($a2)
 * 0x8006dd1c  24020001  addiu $v0,$zero,0x0001
 * 0x8006dd20  03e00008  jr $ra
 * 0x8006dd24  a48300a0  sh $v1,160($a0)
 */
