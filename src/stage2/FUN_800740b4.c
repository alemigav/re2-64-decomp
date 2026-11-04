/* FUN_800740b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800740b4  body 0x800740b4..0x8007410f  size 92 B
 * body sha256 126c53a51f6378745a39806c387c0616a4653b9e5cc8a48bb4b79ade2e51f5f0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 23 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800740b4  3c030001  lui $v1,0x0001
 * 0x800740b8  34638000  ori $v1,$v1,0x8000
 * 0x800740bc  3c04800c  lui $a0,0x800c
 * 0x800740c0  248476b0  addiu $a0,$a0,0x76b0
 * 0x800740c4  3c050002  lui $a1,0x0002
 * 0x800740c8  00852821  addu $a1,$a0,$a1
 * 0x800740cc  3c028007  lui $v0,0x8007
 * 0x800740d0  24424110  addiu $v0,$v0,0x4110
 * 0x800740d4  aca21278  sw $v0,4728($a1)
 * 0x800740d8  3c028011  lui $v0,0x8011
 * 0x800740dc  a0a00f6e  sb $zero,3950($a1)
 * 0x800740e0  8c4252cc  lw $v0,21196($v0)
 * 0x800740e4  00832021  addu $a0,$a0,$v1
 * 0x800740e8  9046000d  lbu $a2,13($v0)
 * 0x800740ec  8c821a60  lw $v0,6752($a0)
 * 0x800740f0  3c038013  lui $v1,0x8013
 * 0x800740f4  ac6217c4  sw $v0,6084($v1)
 * 0x800740f8  3c03ff00  lui $v1,0xff00
 * 0x800740fc  00431025  or $v0,$v0,$v1
 * 0x80074100  ac821a60  sw $v0,6752($a0)
 * 0x80074104  00001021  addu $v0,$zero,$zero
 * 0x80074108  03e00008  jr $ra
 * 0x8007410c  a0a6148b  sb $a2,5259($a1)
 */
