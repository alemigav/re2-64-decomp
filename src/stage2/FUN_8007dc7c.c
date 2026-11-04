/* FUN_8007dc7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dc7c  body 0x8007dc7c..0x8007dcc7  size 76 B
 * body sha256 03b269f80970746a2ee1bfe7b08e7f10271438ae82cd52a05533930cacc4377d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007dc7c  8c830250  lw $v1,592($a0)
 * 0x8007dc80  9062026f  lbu $v0,623($v1)
 * 0x8007dc84  1440002b  bne $v0,$zero,+43
 * 0x8007dc88  24020300  addiu $v0,$zero,0x0300
 * 0x8007dc8c  846201f2  lh $v0,498($v1)
 * 0x8007dc90  04400028  op&0x01 $zero,$v0,0x0028
 * 0x8007dc94  24020300  addiu $v0,$zero,0x0300
 * 0x8007dc98  946201aa  lhu $v0,426($v1)
 * 0x8007dc9c  30422000  andi $v0,$v0,0x2000
 * 0x8007dca0  1440000d  bne $v0,$zero,+13
 * 0x8007dca4  00000000  sll $zero,$zero,0
 * 0x8007dca8  90820207  lbu $v0,519($a0)
 * 0x8007dcac  2442ffff  addiu $v0,$v0,0xffff
 * 0x8007dcb0  a0820207  sb $v0,519($a0)
 * 0x8007dcb4  00021600  sll $v0,$v0,24
 * 0x8007dcb8  04400003  op&0x01 $zero,$v0,0x0003
 * 0x8007dcbc  24020200  addiu $v0,$zero,0x0200
 * 0x8007dcc0  03e00008  jr $ra
 * 0x8007dcc4  a4820006  sh $v0,6($a0)
 */
