/* FUN_80074024
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074024  body 0x80074024..0x8007404b  size 40 B
 * body sha256 5ad6103be85e854362916e1bcb3435c8e313b7460107c1564137d18ee19293e0
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
 * 0x80074024  3c030001  lui $v1,0x0001
 * 0x80074028  34638000  ori $v1,$v1,0x8000
 * 0x8007402c  3c02800c  lui $v0,0x800c
 * 0x80074030  244276b0  addiu $v0,$v0,0x76b0
 * 0x80074034  00431021  addu $v0,$v0,$v1
 * 0x80074038  8c430288  lw $v1,648($v0)
 * 0x8007403c  94820000  lhu $v0,0($a0)
 * 0x80074040  a46201a8  sh $v0,424($v1)
 * 0x80074044  03e00008  jr $ra
 * 0x80074048  00001021  addu $v0,$zero,$zero
 */
