/* FUN_8017b558
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017b558  body 0x8017b558..0x8017b573  size 28 B
 * body sha256 11b62a7c6478cc7230dfab7ecc71901395dcc94d43f43320a3734ae747834c97
 * EXTENT MEASURED, NOT RECONSTRUCTED: 7 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x8017b558..0x8017b573, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8017b558  27bdffe8  addiu $sp,$sp,0xffe8
 * 0x8017b55c  afbf0010  sw $ra,16($sp)
 * 0x8017b560  0c05eee6  jal 0x8017bb98
 * 0x8017b564  00000000  sll $zero,$zero,0
 * 0x8017b568  8fbf0010  lw $ra,16($sp)
 * 0x8017b56c  03e00008  jr $ra
 * 0x8017b570  27bd0018  addiu $sp,$sp,0x0018
 */
