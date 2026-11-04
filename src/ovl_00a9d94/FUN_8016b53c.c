/* FUN_8016b53c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b53c  body 0x8016b53c..0x8016b647  size 268 B
 * body sha256 03df2931ec758720dce85fe9c2c47c9403de953f326db9c1f4cca048678ffc11
 * EXTENT MEASURED, NOT RECONSTRUCTED: 67 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8016b53c  00803021  addu $a2,$a0,$zero
 * 0x8016b540  90c302c5  lbu $v1,709($a2)
 * 0x8016b544  10600006  beq $v1,$zero,+6
 * 0x8016b548  27bdfff8  addiu $sp,$sp,0xfff8
 * 0x8016b54c  24020001  addiu $v0,$zero,0x0001
 * 0x8016b550  10620006  beq $v1,$v0,+6
 * 0x8016b554  00000000  sll $zero,$zero,0
 * 0x8016b558  0805ad90  j 0x8016b640
 * 0x8016b55c  00000000  sll $zero,$zero,0
 * 0x8016b560  24020001  addiu $v0,$zero,0x0001
 * 0x8016b564  a0c202c5  sb $v0,709($a2)
 * 0x8016b568  a4c002c6  sh $zero,710($a2)
 * 0x8016b56c  90c302d0  lbu $v1,720($a2)
 * 0x8016b570  8ca20120  lw $v0,288($a1)
 * 0x8016b574  94c402c6  lhu $a0,710($a2)
 * 0x8016b578  00031880  sll $v1,$v1,2
 * 0x8016b57c  00621821  addu $v1,$v1,$v0
 * 0x8016b580  94620000  lhu $v0,0($v1)
 * 0x8016b584  00441023  subu $v0,$v0,$a0
 * 0x8016b588  a4620000  sh $v0,0($v1)
 * 0x8016b58c  90c302d1  lbu $v1,721($a2)
 * 0x8016b590  8ca20120  lw $v0,288($a1)
 * 0x8016b594  94c402c6  lhu $a0,710($a2)
 * 0x8016b598  00031880  sll $v1,$v1,2
 * 0x8016b59c  00621821  addu $v1,$v1,$v0
 * 0x8016b5a0  94620000  lhu $v0,0($v1)
 * 0x8016b5a4  00441023  subu $v0,$v0,$a0
 * 0x8016b5a8  a4620000  sh $v0,0($v1)
 * 0x8016b5ac  90c202d1  lbu $v0,721($a2)
 * 0x8016b5b0  8ca30120  lw $v1,288($a1)
 * 0x8016b5b4  00021080  sll $v0,$v0,2
 * 0x8016b5b8  00431821  addu $v1,$v0,$v1
 * 0x8016b5bc  84620000  lh $v0,0($v1)
 * 0x8016b5c0  04420001  op&0x01 $v0,$v0,0x0001
 * 0x8016b5c4  a4600000  sh $zero,0($v1)
 * 0x8016b5c8  90c202d0  lbu $v0,720($a2)
 * 0x8016b5cc  8ca30120  lw $v1,288($a1)
 * 0x8016b5d0  00021080  sll $v0,$v0,2
 * 0x8016b5d4  00431821  addu $v1,$v0,$v1
 * 0x8016b5d8  84620000  lh $v0,0($v1)
 * 0x8016b5dc  04420001  op&0x01 $v0,$v0,0x0001
 * 0x8016b5e0  a4600000  sh $zero,0($v1)
 * 0x8016b5e4  94c202c6  lhu $v0,710($a2)
 * 0x8016b5e8  24420002  addiu $v0,$v0,0x0002
 * 0x8016b5ec  a4c202c6  sh $v0,710($a2)
 * 0x8016b5f0  8ca30120  lw $v1,288($a1)
 * 0x8016b5f4  94620010  lhu $v0,16($v1)
 * 0x8016b5f8  00021400  sll $v0,$v0,16
 * 0x8016b5fc  00021443  sra $v0,$v0,17
 * 0x8016b600  a4620010  sh $v0,16($v1)
 * 0x8016b604  90c202d0  lbu $v0,720($a2)
 * 0x8016b608  8ca50120  lw $a1,288($a1)
 * 0x8016b60c  00021080  sll $v0,$v0,2
 * 0x8016b610  00451021  addu $v0,$v0,$a1
 * 0x8016b614  84420000  lh $v0,0($v0)
 * 0x8016b618  14400009  bne $v0,$zero,+9
 * 0x8016b61c  00000000  sll $zero,$zero,0
 * 0x8016b620  90c202d1  lbu $v0,721($a2)
 * 0x8016b624  00021080  sll $v0,$v0,2
 * 0x8016b628  00451021  addu $v0,$v0,$a1
 * 0x8016b62c  84420000  lh $v0,0($v0)
 * 0x8016b630  14400003  bne $v0,$zero,+3
 * 0x8016b634  00000000  sll $zero,$zero,0
 * 0x8016b638  a0c002c4  sb $zero,708($a2)
 * 0x8016b63c  a0c002c5  sb $zero,709($a2)
 * 0x8016b640  03e00008  jr $ra
 * 0x8016b644  27bd0008  addiu $sp,$sp,0x0008
 */
