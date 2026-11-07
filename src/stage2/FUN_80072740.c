/* FUN_80072740
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072740  body 0x80072740..0x80072753  size 20 B
 * body sha256 cf3d1a19452fac9eb4822910ecad77ffa996ceab29bfbce6587a71320a900acf
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8007272c..0x8007277b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80072740  8c82001c  lw $v0,28($a0)
 * 0x80072744  24420006  addiu $v0,$v0,0x0006
 * 0x80072748  ac82001c  sw $v0,28($a0)
 * 0x8007274c  03e00008  jr $ra
 * 0x80072750  24020001  addiu $v0,$zero,0x0001
 */
