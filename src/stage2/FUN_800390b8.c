/* FUN_800390b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800390b8  body 0x800390b8..0x800390df  size 40 B
 * body sha256 19528fc62b77514b4a21d350eddfac6236d991f6d786ab1c0bdab00a7e699435
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
 * 0x800390b8  3c03800f  lui $v1,0x800f
 * 0x800390bc  2463bda8  addiu $v1,$v1,0xbda8
 * 0x800390c0  3084ffff  andi $a0,$a0,0xffff
 * 0x800390c4  00041140  sll $v0,$a0,5
 * 0x800390c8  00441023  subu $v0,$v0,$a0
 * 0x800390cc  00021080  sll $v0,$v0,2
 * 0x800390d0  00431021  addu $v0,$v0,$v1
 * 0x800390d4  a0450000  sb $a1,0($v0)
 * 0x800390d8  03e00008  jr $ra
 * 0x800390dc  00001021  addu $v0,$zero,$zero
 */
