/* FUN_80079560
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079560  body 0x80079560..0x800795ab  size 76 B
 * body sha256 eb9061bb3ec9f86b291771216b45d6916af5b0a079c65a274f1325f3bc569af0
 * EXTENT MEASURED, NOT RECONSTRUCTED: 19 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80079560..0x800795ab, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80079560  8c820234  lw $v0,564($a0)
 * 0x80079564  8c430008  lw $v1,8($v0)
 * 0x80079568  8c45000c  lw $a1,12($v0)
 * 0x8007956c  8c460010  lw $a2,16($v0)
 * 0x80079570  8c470014  lw $a3,20($v0)
 * 0x80079574  ac431788  sw $v1,6024($v0)
 * 0x80079578  ac45178c  sw $a1,6028($v0)
 * 0x8007957c  ac461790  sw $a2,6032($v0)
 * 0x80079580  ac471794  sw $a3,6036($v0)
 * 0x80079584  8c430018  lw $v1,24($v0)
 * 0x80079588  8c45001c  lw $a1,28($v0)
 * 0x8007958c  8c460020  lw $a2,32($v0)
 * 0x80079590  8c470024  lw $a3,36($v0)
 * 0x80079594  ac431798  sw $v1,6040($v0)
 * 0x80079598  ac45179c  sw $a1,6044($v0)
 * 0x8007959c  ac4617a0  sw $a2,6048($v0)
 * 0x800795a0  ac4717a4  sw $a3,6052($v0)
 * 0x800795a4  03e00008  jr $ra
 * 0x800795a8  00000000  sll $zero,$zero,0
 */
