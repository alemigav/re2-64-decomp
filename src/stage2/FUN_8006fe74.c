/* FUN_8006fe74
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fe74  body 0x8006fe74..0x8006fea3  size 48 B
 * body sha256 ca95321500c7404b382e7d1d5151a992b4932262f55c400455acc4597a3a15c3
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006fe74  8c82001c  lw $v0,28($a0)
 * 0x8006fe78  8c830154  lw $v1,340($a0)
 * 0x8006fe7c  84450002  lh $a1,2($v0)
 * 0x8006fe80  84460004  lh $a2,4($v0)
 * 0x8006fe84  84470006  lh $a3,6($v0)
 * 0x8006fe88  24420008  addiu $v0,$v0,0x0008
 * 0x8006fe8c  a4650064  sh $a1,100($v1)
 * 0x8006fe90  a4660066  sh $a2,102($v1)
 * 0x8006fe94  a4670068  sh $a3,104($v1)
 * 0x8006fe98  ac82001c  sw $v0,28($a0)
 * 0x8006fe9c  03e00008  jr $ra
 * 0x8006fea0  24020001  addiu $v0,$zero,0x0001
 */
