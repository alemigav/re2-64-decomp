/* FUN_800b4400
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4400  body 0x800b4400..0x800b442f  size 48 B
 * body sha256 113ca1344a5d00ca7edb4450f021a333aff2d14694887603f78e01bd819f37b1
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x800b43a0..0x800b4477, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800b4400  24428b20  addiu $v0,$v0,0x8b20
 * 0x800b4404  000618c0  sll $v1,$a2,3
 * 0x800b4408  00661821  addu $v1,$v1,$a2
 * 0x800b440c  00031900  sll $v1,$v1,4
 * 0x800b4410  00661821  addu $v1,$v1,$a2
 * 0x800b4414  00031880  sll $v1,$v1,2
 * 0x800b4418  00661821  addu $v1,$v1,$a2
 * 0x800b441c  000318c0  sll $v1,$v1,3
 * 0x800b4420  00621821  addu $v1,$v1,$v0
 * 0x800b4424  90621200  lbu $v0,4608($v1)
 * 0x800b4428  03e00008  jr $ra
 * 0x800b442c  0002102b  sltu $v0,$zero,$v0
 */
