/* FUN_80047984
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047984  body 0x80047984..0x800479bb  size 56 B
 * body sha256 0ed2956f4bb9a91428711263235e4f58eef6c9f6cd0e26842487b35bee3c9dfd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80047984..0x800479bb, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80047984  97a20012  lhu $v0,18($sp)
 * 0x80047988  97a30016  lhu $v1,22($sp)
 * 0x8004798c  97a8001a  lhu $t0,26($sp)
 * 0x80047990  97a9001e  lhu $t1,30($sp)
 * 0x80047994  97aa0022  lhu $t2,34($sp)
 * 0x80047998  a0850048  sb $a1,72($a0)
 * 0x8004799c  a0860049  sb $a2,73($a0)
 * 0x800479a0  a087004a  sb $a3,74($a0)
 * 0x800479a4  a082004b  sb $v0,75($a0)
 * 0x800479a8  a083004c  sb $v1,76($a0)
 * 0x800479ac  a088004d  sb $t0,77($a0)
 * 0x800479b0  a089004e  sb $t1,78($a0)
 * 0x800479b4  03e00008  jr $ra
 * 0x800479b8  a08a004f  sb $t2,79($a0)
 */
