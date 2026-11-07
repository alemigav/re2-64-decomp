/* FUN_80071d9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071d9c  body 0x80071d9c..0x80071def  size 84 B
 * body sha256 30312d94406136bd1c0366129db60151e976c90dd21d778f7c7a5c2d8a437da5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 21 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80071d9c  8c85001c  lw $a1,28($a0)
 * 0x80071da0  90a30001  lbu $v1,1($a1)
 * 0x80071da4  10600006  beq $v1,$zero,+6
 * 0x80071da8  00000000  sll $zero,$zero,0
 * 0x80071dac  24020001  addiu $v0,$zero,0x0001
 * 0x80071db0  10620007  beq $v1,$v0,+7
 * 0x80071db4  00000000  sll $zero,$zero,0
 * 0x80071db8  0801c777  j 0x80071ddc
 * 0x80071dbc  00000000  sll $zero,$zero,0
 * 0x80071dc0  8c830154  lw $v1,340($a0)
 * 0x80071dc4  94a20002  lhu $v0,2($a1)
 * 0x80071dc8  0801c777  j 0x80071ddc
 * 0x80071dcc  a4620270  sh $v0,624($v1)
 * 0x80071dd0  8c830154  lw $v1,340($a0)
 * 0x80071dd4  94a20002  lhu $v0,2($a1)
 * 0x80071dd8  a4620272  sh $v0,626($v1)
 * 0x80071ddc  8c82001c  lw $v0,28($a0)
 * 0x80071de0  24420004  addiu $v0,$v0,0x0004
 * 0x80071de4  ac82001c  sw $v0,28($a0)
 * 0x80071de8  03e00008  jr $ra
 * 0x80071dec  24020001  addiu $v0,$zero,0x0001
 */
