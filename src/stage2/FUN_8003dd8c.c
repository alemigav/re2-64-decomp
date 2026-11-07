/* FUN_8003dd8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dd8c  body 0x8003dd8c..0x8003ddc3  size 56 B
 * body sha256 8063f510f4e3dd255cde8323efaf70db351784f9c4805e2c85ccb318ab0bc3fd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8003dd8c..0x8003ddc3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003dd8c  3c03800f  lui $v1,0x800f
 * 0x8003dd90  8c62bb94  lw $v0,-17516($v1)
 * 0x8003dd94  94440016  lhu $a0,22($v0)
 * 0x8003dd98  a0400009  sb $zero,9($v0)
 * 0x8003dd9c  a0400002  sb $zero,2($v0)
 * 0x8003dda0  8c65bb94  lw $a1,-17516($v1)
 * 0x8003dda4  a440000e  sh $zero,14($v0)
 * 0x8003dda8  a4440036  sh $a0,54($v0)
 * 0x8003ddac  a0a00001  sb $zero,1($a1)
 * 0x8003ddb0  8c63bb94  lw $v1,-17516($v1)
 * 0x8003ddb4  94620012  lhu $v0,18($v1)
 * 0x8003ddb8  3042fffe  andi $v0,$v0,0xfffe
 * 0x8003ddbc  03e00008  jr $ra
 * 0x8003ddc0  a4620012  sh $v0,18($v1)
 */
