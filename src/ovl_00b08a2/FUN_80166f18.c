/* FUN_80166f18
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80166f18  body 0x80166f18..0x80166f37  size 32 B
 * body sha256 7e69402220218a5ad0f718855141f3f9576aec6c53f6bfa0ace53587a4f6be9d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 8 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80166f18  8ca20234  lw $v0,564($a1)
 * 0x80166f1c  8c4305e0  lw $v1,1504($v0)
 * 0x80166f20  34634000  ori $v1,$v1,0x4000
 * 0x80166f24  00641824  and $v1,$v1,$a0
 * 0x80166f28  ac4305e0  sw $v1,1504($v0)
 * 0x80166f2c  a0a002bf  sb $zero,703($a1)
 * 0x80166f30  03e00008  jr $ra
 * 0x80166f34  00000000  sll $zero,$zero,0
 */
