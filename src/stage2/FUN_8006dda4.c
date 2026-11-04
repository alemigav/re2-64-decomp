/* FUN_8006dda4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dda4  body 0x8006dda4..0x8006ddcf  size 44 B
 * body sha256 a4a960d3066b2fab1241edadcadc6f0a65944c072093d4321cef164e80c2ecd8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006dda4  3c020001  lui $v0,0x0001
 * 0x8006dda8  34428000  ori $v0,$v0,0x8000
 * 0x8006ddac  3c03800c  lui $v1,0x800c
 * 0x8006ddb0  246376b0  addiu $v1,$v1,0x76b0
 * 0x8006ddb4  00621821  addu $v1,$v1,$v0
 * 0x8006ddb8  8c621a5c  lw $v0,6748($v1)
 * 0x8006ddbc  30420020  andi $v0,$v0,0x0020
 * 0x8006ddc0  10400003  beq $v0,$zero,+3
 * 0x8006ddc4  00802821  addu $a1,$a0,$zero
 * 0x8006ddc8  03e00008  jr $ra
 * 0x8006ddcc  24020002  addiu $v0,$zero,0x0002
 */
