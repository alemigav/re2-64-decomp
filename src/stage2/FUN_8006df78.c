/* FUN_8006df78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006df78  body 0x8006df78..0x8006dfe3  size 108 B
 * body sha256 ab993d7e06e0ad0c43dd340561efef34e55c7fd80dabd45e4dc7475044eb040f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 27 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006df78  80850002  lb $a1,2($a0)
 * 0x8006df7c  00853021  addu $a2,$a0,$a1
 * 0x8006df80  80c70008  lb $a3,8($a2)
 * 0x8006df84  000518c0  sll $v1,$a1,3
 * 0x8006df88  00071040  sll $v0,$a3,1
 * 0x8006df8c  00431021  addu $v0,$v0,$v1
 * 0x8006df90  00821021  addu $v0,$a0,$v0
 * 0x8006df94  944300a0  lhu $v1,160($v0)
 * 0x8006df98  2463ffff  addiu $v1,$v1,0xffff
 * 0x8006df9c  a44300a0  sh $v1,160($v0)
 * 0x8006dfa0  00031c00  sll $v1,$v1,16
 * 0x8006dfa4  10600007  beq $v1,$zero,+7
 * 0x8006dfa8  00051900  sll $v1,$a1,4
 * 0x8006dfac  00071080  sll $v0,$a3,2
 * 0x8006dfb0  00431021  addu $v0,$v0,$v1
 * 0x8006dfb4  00821021  addu $v0,$a0,$v0
 * 0x8006dfb8  8c420020  lw $v0,32($v0)
 * 0x8006dfbc  0801b7f7  j 0x8006dfdc
 * 0x8006dfc0  ac82001c  sw $v0,28($a0)
 * 0x8006dfc4  8c82001c  lw $v0,28($a0)
 * 0x8006dfc8  24420002  addiu $v0,$v0,0x0002
 * 0x8006dfcc  ac82001c  sw $v0,28($a0)
 * 0x8006dfd0  90c20008  lbu $v0,8($a2)
 * 0x8006dfd4  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006dfd8  a0c20008  sb $v0,8($a2)
 * 0x8006dfdc  03e00008  jr $ra
 * 0x8006dfe0  24020001  addiu $v0,$zero,0x0001
 */
