/* FUN_800722cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800722cc  body 0x800722cc..0x8007230b  size 64 B
 * body sha256 ddc651ccc1cb7c82982b8eeefacba7246d1a3801f3c8a82fc9d84bd1cd8bc0f4
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800722cc  3c050001  lui $a1,0x0001
 * 0x800722d0  8c82001c  lw $v0,28($a0)
 * 0x800722d4  34a58000  ori $a1,$a1,0x8000
 * 0x800722d8  90460001  lbu $a2,1($v0)
 * 0x800722dc  94430002  lhu $v1,2($v0)
 * 0x800722e0  24420004  addiu $v0,$v0,0x0004
 * 0x800722e4  ac82001c  sw $v0,28($a0)
 * 0x800722e8  3c02800c  lui $v0,0x800c
 * 0x800722ec  244276b0  addiu $v0,$v0,0x76b0
 * 0x800722f0  00451021  addu $v0,$v0,$a1
 * 0x800722f4  8c420264  lw $v0,612($v0)
 * 0x800722f8  00431024  and $v0,$v0,$v1
 * 0x800722fc  10400003  beq $v0,$zero,+3
 * 0x80072300  38c20001  op&0x0e $v0,$a2,0x0001
 * 0x80072304  03e00008  jr $ra
 * 0x80072308  00c01021  addu $v0,$a2,$zero
 */
