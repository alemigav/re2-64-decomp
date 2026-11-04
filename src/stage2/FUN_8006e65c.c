/* FUN_8006e65c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e65c  body 0x8006e65c..0x8006e66f  size 20 B
 * body sha256 038f60d88bbee7e1b5f24706e12140b260b616268d4f8ee3276171726cda06bc
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e65c  8cc30000  lw $v1,0($a2)
 * 0x8006e660  00a42006  special&0x06 $a0,$a1,$a0
 * 0x8006e664  00641825  or $v1,$v1,$a0
 * 0x8006e668  03e00008  jr $ra
 * 0x8006e66c  acc30000  sw $v1,0($a2)
 */
