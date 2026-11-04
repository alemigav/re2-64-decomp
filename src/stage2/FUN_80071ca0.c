/* FUN_80071ca0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071ca0  body 0x80071ca0..0x80071ce7  size 72 B
 * body sha256 8f80cc5ad667b17cb054605e7a1f7d29c69b80a379e90b1cb00e4cda6acd53e2
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80071ca0  8c850154  lw $a1,340($a0)
 * 0x80071ca4  90a20008  lbu $v0,8($a1)
 * 0x80071ca8  3c030100  lui $v1,0x0100
 * 0x80071cac  2c420010  op&0x0b $v0,$v0,0x0010
 * 0x80071cb0  10400004  beq $v0,$zero,+4
 * 0x80071cb4  aca30004  sw $v1,4($a1)
 * 0x80071cb8  94a201aa  lhu $v0,426($a1)
 * 0x80071cbc  30420fff  andi $v0,$v0,0x0fff
 * 0x80071cc0  a4a201aa  sh $v0,426($a1)
 * 0x80071cc4  94a201aa  lhu $v0,426($a1)
 * 0x80071cc8  a0a0025c  sb $zero,604($a1)
 * 0x80071ccc  3042afff  andi $v0,$v0,0xafff
 * 0x80071cd0  a4a201aa  sh $v0,426($a1)
 * 0x80071cd4  8c82001c  lw $v0,28($a0)
 * 0x80071cd8  24420001  addiu $v0,$v0,0x0001
 * 0x80071cdc  ac82001c  sw $v0,28($a0)
 * 0x80071ce0  03e00008  jr $ra
 * 0x80071ce4  24020001  addiu $v0,$zero,0x0001
 */
