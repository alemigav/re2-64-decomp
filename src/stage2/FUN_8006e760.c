/* FUN_8006e760
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e760  body 0x8006e760..0x8006e79b  size 60 B
 * body sha256 4c2360b6fb24daadd10817ee5f0767f8547f0750c317f575ef1abc0772028d7d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 15 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e760  8c82001c  lw $v0,28($a0)
 * 0x8006e764  90450001  lbu $a1,1($v0)
 * 0x8006e768  90430002  lbu $v1,2($v0)
 * 0x8006e76c  24420003  addiu $v0,$v0,0x0003
 * 0x8006e770  ac82001c  sw $v0,28($a0)
 * 0x8006e774  3c02800f  lui $v0,0x800f
 * 0x8006e778  24428c78  addiu $v0,$v0,0x8c78
 * 0x8006e77c  00052840  sll $a1,$a1,1
 * 0x8006e780  00031840  sll $v1,$v1,1
 * 0x8006e784  00621821  addu $v1,$v1,$v0
 * 0x8006e788  00a22821  addu $a1,$a1,$v0
 * 0x8006e78c  94630000  lhu $v1,0($v1)
 * 0x8006e790  24020001  addiu $v0,$zero,0x0001
 * 0x8006e794  03e00008  jr $ra
 * 0x8006e798  a4a30000  sh $v1,0($a1)
 */
