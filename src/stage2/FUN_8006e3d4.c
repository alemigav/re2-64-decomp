/* FUN_8006e3d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e3d4  body 0x8006e3d4..0x8006e43b  size 104 B
 * body sha256 aeb5fe066a926e962851eeb2623835e6d2deeca2d36b8f7fcfb31cb2f167d415
 * EXTENT MEASURED, NOT RECONSTRUCTED: 26 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e3d4  8c83001c  lw $v1,28($a0)
 * 0x8006e3d8  80850002  lb $a1,2($a0)
 * 0x8006e3dc  90660001  lbu $a2,1($v1)
 * 0x8006e3e0  24630002  addiu $v1,$v1,0x0002
 * 0x8006e3e4  00051080  sll $v0,$a1,2
 * 0x8006e3e8  24a50001  addiu $a1,$a1,0x0001
 * 0x8006e3ec  00821021  addu $v0,$a0,$v0
 * 0x8006e3f0  ac430144  sw $v1,324($v0)
 * 0x8006e3f4  00851821  addu $v1,$a0,$a1
 * 0x8006e3f8  2402ffff  addiu $v0,$zero,0xffff
 * 0x8006e3fc  a0620004  sb $v0,4($v1)
 * 0x8006e400  a0620008  sb $v0,8($v1)
 * 0x8006e404  00051140  sll $v0,$a1,5
 * 0x8006e408  244200c0  addiu $v0,$v0,0x00c0
 * 0x8006e40c  00821021  addu $v0,$a0,$v0
 * 0x8006e410  ac820140  sw $v0,320($a0)
 * 0x8006e414  3c028011  lui $v0,0x8011
 * 0x8006e418  8c434f2c  lw $v1,20268($v0)
 * 0x8006e41c  00063040  sll $a2,$a2,1
 * 0x8006e420  00c33021  addu $a2,$a2,$v1
 * 0x8006e424  94c20000  lhu $v0,0($a2)
 * 0x8006e428  a0850002  sb $a1,2($a0)
 * 0x8006e42c  00621021  addu $v0,$v1,$v0
 * 0x8006e430  ac82001c  sw $v0,28($a0)
 * 0x8006e434  03e00008  jr $ra
 * 0x8006e438  24020001  addiu $v0,$zero,0x0001
 */
