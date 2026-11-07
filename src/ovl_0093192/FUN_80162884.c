/* FUN_80162884
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162884  body 0x80162884..0x801628ab  size 40 B
 * body sha256 82c931712db5c56e9db4079984e5b6a2f443babf09ca25c5a6b0053012a55378
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8016287c..0x801628bb, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80162884  90830006  lbu $v1,6($a0)
 * 0x80162888  24050001  addiu $a1,$zero,0x0001
 * 0x8016288c  10650005  beq $v1,$a1,+5
 * 0x80162890  28620002  op&0x0a $v0,$v1,0x0002
 * 0x80162894  10400003  beq $v0,$zero,+3
 * 0x80162898  00000000  sll $zero,$zero,0
 * 0x8016289c  50600001  op&0x14 $zero,$v1,0x0001
 * 0x801628a0  a0850006  sb $a1,6($a0)
 * 0x801628a4  03e00008  jr $ra
 * 0x801628a8  00000000  sll $zero,$zero,0
 */
