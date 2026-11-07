/* FUN_8016b214
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016b214  body 0x8016b214..0x8016b3a7  size 404 B
 * body sha256 8db1106078c57ab1a1c8d4676ac9e46c06467cfa2fa96adf45c18cbd72629639
 * EXTENT MEASURED, NOT RECONSTRUCTED: 101 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8016b214  00803021  addu $a2,$a0,$zero
 * 0x8016b218  90c302c5  lbu $v1,709($a2)
 * 0x8016b21c  24040001  addiu $a0,$zero,0x0001
 * 0x8016b220  10640010  beq $v1,$a0,+16
 * 0x8016b224  27bdfff8  addiu $sp,$sp,0xfff8
 * 0x8016b228  28620002  op&0x0a $v0,$v1,0x0002
 * 0x8016b22c  50400005  op&0x14 $zero,$v0,0x0005
 * 0x8016b230  24020002  addiu $v0,$zero,0x0002
 * 0x8016b234  10600009  beq $v1,$zero,+9
 * 0x8016b238  24020008  addiu $v0,$zero,0x0008
 * 0x8016b23c  0805ace8  j 0x8016b3a0
 * 0x8016b240  00000000  sll $zero,$zero,0
 * 0x8016b244  10620040  beq $v1,$v0,+64
 * 0x8016b248  24020003  addiu $v0,$zero,0x0003
 * 0x8016b24c  50620053  op&0x14 $v0,$v1,0x0053
 * 0x8016b250  a0c002c4  sb $zero,708($a2)
 * 0x8016b254  0805ace8  j 0x8016b3a0
 * 0x8016b258  00000000  sll $zero,$zero,0
 * 0x8016b25c  a0c402c5  sb $a0,709($a2)
 * 0x8016b260  a4c202c6  sh $v0,710($a2)
 * 0x8016b264  90c302d0  lbu $v1,720($a2)
 * 0x8016b268  8ca20120  lw $v0,288($a1)
 * 0x8016b26c  94c402c6  lhu $a0,710($a2)
 * 0x8016b270  00031880  sll $v1,$v1,2
 * 0x8016b274  00621821  addu $v1,$v1,$v0
 * 0x8016b278  94620000  lhu $v0,0($v1)
 * 0x8016b27c  00441023  subu $v0,$v0,$a0
 * 0x8016b280  a4620000  sh $v0,0($v1)
 * 0x8016b284  90c302d1  lbu $v1,721($a2)
 * 0x8016b288  8ca20120  lw $v0,288($a1)
 * 0x8016b28c  94c402c6  lhu $a0,710($a2)
 * 0x8016b290  00031880  sll $v1,$v1,2
 * 0x8016b294  00621821  addu $v1,$v1,$v0
 * 0x8016b298  94620000  lhu $v0,0($v1)
 * 0x8016b29c  00441023  subu $v0,$v0,$a0
 * 0x8016b2a0  a4620000  sh $v0,0($v1)
 * 0x8016b2a4  90c202d1  lbu $v0,721($a2)
 * 0x8016b2a8  8ca30120  lw $v1,288($a1)
 * 0x8016b2ac  00021080  sll $v0,$v0,2
 * 0x8016b2b0  00431821  addu $v1,$v0,$v1
 * 0x8016b2b4  84620000  lh $v0,0($v1)
 * 0x8016b2b8  04420001  op&0x01 $v0,$v0,0x0001
 * 0x8016b2bc  a4600000  sh $zero,0($v1)
 * 0x8016b2c0  84c202c6  lh $v0,710($a2)
 * 0x8016b2c4  00021040  sll $v0,$v0,1
 * 0x8016b2c8  a4c202c6  sh $v0,710($a2)
 * 0x8016b2cc  8ca30120  lw $v1,288($a1)
 * 0x8016b2d0  94620010  lhu $v0,16($v1)
 * 0x8016b2d4  00021400  sll $v0,$v0,16
 * 0x8016b2d8  00021443  sra $v0,$v0,17
 * 0x8016b2dc  a4620010  sh $v0,16($v1)
 * 0x8016b2e0  90c202d0  lbu $v0,720($a2)
 * 0x8016b2e4  8ca30120  lw $v1,288($a1)
 * 0x8016b2e8  00021080  sll $v0,$v0,2
 * 0x8016b2ec  00431821  addu $v1,$v0,$v1
 * 0x8016b2f0  84620000  lh $v0,0($v1)
 * 0x8016b2f4  2842fcc8  op&0x0a $v0,$v0,0xfcc8
 * 0x8016b2f8  10400002  beq $v0,$zero,+2
 * 0x8016b2fc  2402fcc8  addiu $v0,$zero,0xfcc8
 * 0x8016b300  a4620000  sh $v0,0($v1)
 * 0x8016b304  90c202d0  lbu $v0,720($a2)
 * 0x8016b308  8ca50120  lw $a1,288($a1)
 * 0x8016b30c  00021080  sll $v0,$v0,2
 * 0x8016b310  00451021  addu $v0,$v0,$a1
 * 0x8016b314  84430000  lh $v1,0($v0)
 * 0x8016b318  2402fcc8  addiu $v0,$zero,0xfcc8
 * 0x8016b31c  14620020  bne $v1,$v0,+32
 * 0x8016b320  00000000  sll $zero,$zero,0
 * 0x8016b324  90c202d1  lbu $v0,721($a2)
 * 0x8016b328  00021080  sll $v0,$v0,2
 * 0x8016b32c  00451021  addu $v0,$v0,$a1
 * 0x8016b330  84420000  lh $v0,0($v0)
 * 0x8016b334  1440001a  bne $v0,$zero,+26
 * 0x8016b338  24020002  addiu $v0,$zero,0x0002
 * 0x8016b33c  a0c202c5  sb $v0,709($a2)
 * 0x8016b340  0805ace8  j 0x8016b3a0
 * 0x8016b344  a4c002c6  sh $zero,710($a2)
 * 0x8016b348  90c302d0  lbu $v1,720($a2)
 * 0x8016b34c  8ca20120  lw $v0,288($a1)
 * 0x8016b350  94c402c6  lhu $a0,710($a2)
 * 0x8016b354  00031880  sll $v1,$v1,2
 * 0x8016b358  00621821  addu $v1,$v1,$v0
 * 0x8016b35c  94620000  lhu $v0,0($v1)
 * 0x8016b360  00441021  addu $v0,$v0,$a0
 * 0x8016b364  a4620000  sh $v0,0($v1)
 * 0x8016b368  94c202c6  lhu $v0,710($a2)
 * 0x8016b36c  24420001  addiu $v0,$v0,0x0001
 * 0x8016b370  a4c202c6  sh $v0,710($a2)
 * 0x8016b374  90c202d0  lbu $v0,720($a2)
 * 0x8016b378  8ca30120  lw $v1,288($a1)
 * 0x8016b37c  00021080  sll $v0,$v0,2
 * 0x8016b380  00431821  addu $v1,$v0,$v1
 * 0x8016b384  84620000  lh $v0,0($v1)
 * 0x8016b388  18400005  blez $v0,+5
 * 0x8016b38c  24020003  addiu $v0,$zero,0x0003
 * 0x8016b390  a4600000  sh $zero,0($v1)
 * 0x8016b394  0805ace8  j 0x8016b3a0
 * 0x8016b398  a0c202c5  sb $v0,709($a2)
 * 0x8016b39c  a0c002c5  sb $zero,709($a2)
 * 0x8016b3a0  03e00008  jr $ra
 * 0x8016b3a4  27bd0008  addiu $sp,$sp,0x0008
 */
