/* FUN_800765a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800765a4  body 0x800765a4..0x800765df  size 60 B
 * body sha256 d7665ff0ba121763b6b303bb18e10cb2e804cbab76db2321bfb4e6c6edad85b8
 * EXTENT MEASURED, NOT RECONSTRUCTED: 15 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x800765a4..0x800765df, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800765a4  2406008e  addiu $a2,$zero,0x008e
 * 0x800765a8  3c070002  lui $a3,0x0002
 * 0x800765ac  2484011c  addiu $a0,$a0,0x011c
 * 0x800765b0  3c02800c  lui $v0,0x800c
 * 0x800765b4  244276b0  addiu $v0,$v0,0x76b0
 * 0x800765b8  2445011c  addiu $a1,$v0,0x011c
 * 0x800765bc  2484fffe  addiu $a0,$a0,0xfffe
 * 0x800765c0  24a5fffe  addiu $a1,$a1,0xfffe
 * 0x800765c4  24c6ffff  addiu $a2,$a2,0xffff
 * 0x800765c8  94830000  lhu $v1,0($a0)
 * 0x800765cc  00a71021  addu $v0,$a1,$a3
 * 0x800765d0  14c0fffa  bne $a2,$zero,-6
 * 0x800765d4  a44314ac  sh $v1,5292($v0)
 * 0x800765d8  03e00008  jr $ra
 * 0x800765dc  00000000  sll $zero,$zero,0
 */
