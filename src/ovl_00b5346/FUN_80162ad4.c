/* FUN_80162ad4
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162ad4  body 0x80162ad4..0x80162b0b  size 56 B
 * body sha256 5113a292e1f422b2083c960bbb217bf4853b2d24d261ced91eb563d8a8c339ec
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80162ad4..0x80162b1b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80162ad4  84820270  lh $v0,624($a0)
 * 0x80162ad8  1040000a  beq $v0,$zero,+10
 * 0x80162adc  248302b4  addiu $v1,$a0,0x02b4
 * 0x80162ae0  24020005  addiu $v0,$zero,0x0005
 * 0x80162ae4  a4800270  sh $zero,624($a0)
 * 0x80162ae8  a0620005  sb $v0,5($v1)
 * 0x80162aec  9482002a  lhu $v0,42($a0)
 * 0x80162af0  a4620006  sh $v0,6($v1)
 * 0x80162af4  94820032  lhu $v0,50($a0)
 * 0x80162af8  a4620008  sh $v0,8($v1)
 * 0x80162afc  24020100  addiu $v0,$zero,0x0100
 * 0x80162b00  a4820006  sh $v0,6($a0)
 * 0x80162b04  03e00008  jr $ra
 * 0x80162b08  00000000  sll $zero,$zero,0
 */
