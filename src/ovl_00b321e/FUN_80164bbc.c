/* FUN_80164bbc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164bbc  body 0x80164bbc..0x80164be7  size 44 B
 * body sha256 ea80f56023915ea3014f5d56a099bfb6fe62a84469d6b476a00061200bce2e5d
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
 * 0x80164bbc  90830007  lbu $v1,7($a0)
 * 0x80164bc0  24050001  addiu $a1,$zero,0x0001
 * 0x80164bc4  10650028  beq $v1,$a1,+40
 * 0x80164bc8  248802b4  addiu $t0,$a0,0x02b4
 * 0x80164bcc  28620002  op&0x0a $v0,$v1,0x0002
 * 0x80164bd0  50400005  op&0x14 $zero,$v0,0x0005
 * 0x80164bd4  24020002  addiu $v0,$zero,0x0002
 * 0x80164bd8  10600007  beq $v1,$zero,+7
 * 0x80164bdc  00000000  sll $zero,$zero,0
 * 0x80164be0  03e00008  jr $ra
 * 0x80164be4  00000000  sll $zero,$zero,0
 */
