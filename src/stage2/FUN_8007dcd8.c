/* FUN_8007dcd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007dcd8  body 0x8007dcd8..0x8007dd3f  size 104 B
 * body sha256 0162a0c8f16fd3fbb72dff9c869e2b2c56a0c6a4fe564ff3448ee14ab8436f8f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 26 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8007dcd8  948201aa  lhu $v0,426($a0)
 * 0x8007dcdc  30420001  andi $v0,$v0,0x0001
 * 0x8007dce0  1040000d  beq $v0,$zero,+13
 * 0x8007dce4  00000000  sll $zero,$zero,0
 * 0x8007dce8  948201f0  lhu $v0,496($a0)
 * 0x8007dcec  30422000  andi $v0,$v0,0x2000
 * 0x8007dcf0  10400009  beq $v0,$zero,+9
 * 0x8007dcf4  00000000  sll $zero,$zero,0
 * 0x8007dcf8  90820207  lbu $v0,519($a0)
 * 0x8007dcfc  2442ffff  addiu $v0,$v0,0xffff
 * 0x8007dd00  a0820207  sb $v0,519($a0)
 * 0x8007dd04  00021600  sll $v0,$v0,24
 * 0x8007dd08  0441ffed  op&0x01 $at,$v0,0xffed
 * 0x8007dd0c  24020200  addiu $v0,$zero,0x0200
 * 0x8007dd10  0801f733  j 0x8007dccc
 * 0x8007dd14  a4820006  sh $v0,6($a0)
 * 0x8007dd18  846201f2  lh $v0,498($v1)
 * 0x8007dd1c  04400005  op&0x01 $zero,$v0,0x0005
 * 0x8007dd20  24020300  addiu $v0,$zero,0x0300
 * 0x8007dd24  946201aa  lhu $v0,426($v1)
 * 0x8007dd28  30422000  andi $v0,$v0,0x2000
 * 0x8007dd2c  10400002  beq $v0,$zero,+2
 * 0x8007dd30  24020300  addiu $v0,$zero,0x0300
 * 0x8007dd34  a4820006  sh $v0,6($a0)
 * 0x8007dd38  03e00008  jr $ra
 * 0x8007dd3c  00000000  sll $zero,$zero,0
 */
