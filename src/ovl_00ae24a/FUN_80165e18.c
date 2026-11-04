/* FUN_80165e18
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165e18  body 0x80165e18..0x80165e37  size 32 B
 * body sha256 5cf3b87856ef4756131eaeeea3bc7dad30012d67aaaa99a4356d98e3f851898f
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
 * 0x80165e18  00803021  addu $a2,$a0,$zero
 * 0x80165e1c  90c302b5  lbu $v1,693($a2)
 * 0x80165e20  10600005  beq $v1,$zero,+5
 * 0x80165e24  24020001  addiu $v0,$zero,0x0001
 * 0x80165e28  1062000c  beq $v1,$v0,+12
 * 0x80165e2c  00000000  sll $zero,$zero,0
 * 0x80165e30  03e00008  jr $ra
 * 0x80165e34  00000000  sll $zero,$zero,0
 */
