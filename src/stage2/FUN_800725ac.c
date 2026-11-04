/* FUN_800725ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800725ac  body 0x800725ac..0x800725db  size 48 B
 * body sha256 eb458101bb58301e4df557f4372dfd2db98bd533562a8a05dfa43be9bb897be0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800725ac  8c82001c  lw $v0,28($a0)
 * 0x800725b0  90430001  lbu $v1,1($v0)
 * 0x800725b4  2c620080  op&0x0b $v0,$v1,0x0080
 * 0x800725b8  10400003  beq $v0,$zero,+3
 * 0x800725bc  00000000  sll $zero,$zero,0
 * 0x800725c0  3c028001  lui $v0,0x8001
 * 0x800725c4  a0432888  sb $v1,10376($v0)
 * 0x800725c8  8c82001c  lw $v0,28($a0)
 * 0x800725cc  24420002  addiu $v0,$v0,0x0002
 * 0x800725d0  ac82001c  sw $v0,28($a0)
 * 0x800725d4  03e00008  jr $ra
 * 0x800725d8  24020001  addiu $v0,$zero,0x0001
 */
