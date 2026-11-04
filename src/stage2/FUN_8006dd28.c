/* FUN_8006dd28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dd28  body 0x8006dd28..0x8006dd7b  size 84 B
 * body sha256 5ba84375bde75be29a99b91eb498c9246b159af71d2df6b6302e8d21def5c0c9
 * EXTENT MEASURED, NOT RECONSTRUCTED: 21 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006dd28  80820002  lb $v0,2($a0)
 * 0x8006dd2c  00822821  addu $a1,$a0,$v0
 * 0x8006dd30  80a30008  lb $v1,8($a1)
 * 0x8006dd34  000210c0  sll $v0,$v0,3
 * 0x8006dd38  00031840  sll $v1,$v1,1
 * 0x8006dd3c  00621821  addu $v1,$v1,$v0
 * 0x8006dd40  00831821  addu $v1,$a0,$v1
 * 0x8006dd44  946200a0  lhu $v0,160($v1)
 * 0x8006dd48  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006dd4c  a46200a0  sh $v0,160($v1)
 * 0x8006dd50  00021400  sll $v0,$v0,16
 * 0x8006dd54  14400007  bne $v0,$zero,+7
 * 0x8006dd58  00000000  sll $zero,$zero,0
 * 0x8006dd5c  8c82001c  lw $v0,28($a0)
 * 0x8006dd60  24420003  addiu $v0,$v0,0x0003
 * 0x8006dd64  ac82001c  sw $v0,28($a0)
 * 0x8006dd68  90a20008  lbu $v0,8($a1)
 * 0x8006dd6c  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006dd70  a0a20008  sb $v0,8($a1)
 * 0x8006dd74  03e00008  jr $ra
 * 0x8006dd78  24020002  addiu $v0,$zero,0x0002
 */
