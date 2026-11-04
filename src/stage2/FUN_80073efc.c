/* FUN_80073efc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073efc  body 0x80073efc..0x80073f1f  size 36 B
 * body sha256 7a047e5eb127be610cb8f9d1ccf11a5df9de4a18807f6a185b7ebaf6432229ab
 * EXTENT MEASURED, NOT RECONSTRUCTED: 9 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073efc  34638000  ori $v1,$v1,0x8000
 * 0x80073f00  24020001  addiu $v0,$zero,0x0001
 * 0x80073f04  3c04800c  lui $a0,0x800c
 * 0x80073f08  248476b0  addiu $a0,$a0,0x76b0
 * 0x80073f0c  00832021  addu $a0,$a0,$v1
 * 0x80073f10  24030006  addiu $v1,$zero,0x0006
 * 0x80073f14  a0831a85  sb $v1,6789($a0)
 * 0x80073f18  03e00008  jr $ra
 * 0x80073f1c  a0801a86  sb $zero,6790($a0)
 */
