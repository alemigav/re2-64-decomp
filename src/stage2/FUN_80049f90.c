/* FUN_80049f90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049f90  body 0x80049f90..0x80049f97  size 8 B
 * body sha256 c87953fcc35273cef4ce585123299a6b7086844fb01d0471cd3c3f4109b14387
 * EXTENT MEASURED, NOT RECONSTRUCTED: 2 words, found by the extent scan inside a byte-map region no artifact names (M388 correction (shape: a leading alignment `nop`): the extent opened one word early on a `sll $zero,$zero,0` that belongs to no body -- the preceding function ends `jr ra`+`nop` at 0x80049f84/88. From 0x80049f90 the body is `jr ra; addu $v0,$a1,$zero`, i.e. the two-word `return b;` shape, and it is self-contained by the M385 screen)
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
 * 0x80049f90  03e00008  jr $ra
 * 0x80049f94  00a01021  addu $v0,$a1,$zero
 */
