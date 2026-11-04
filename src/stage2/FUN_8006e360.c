/* FUN_8006e360
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e360  body 0x8006e360..0x8006e387  size 40 B
 * body sha256 49262babf7947dafbb8891993ca6a40f75db4a0df87ebe18508597cfeb9d9fe7
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e360  80830002  lb $v1,2($a0)
 * 0x8006e364  00831821  addu $v1,$a0,$v1
 * 0x8006e368  90620008  lbu $v0,8($v1)
 * 0x8006e36c  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006e370  a0620008  sb $v0,8($v1)
 * 0x8006e374  8c82001c  lw $v0,28($a0)
 * 0x8006e378  24420002  addiu $v0,$v0,0x0002
 * 0x8006e37c  ac82001c  sw $v0,28($a0)
 * 0x8006e380  03e00008  jr $ra
 * 0x8006e384  24020001  addiu $v0,$zero,0x0001
 */
