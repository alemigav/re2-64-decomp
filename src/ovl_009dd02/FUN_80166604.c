/* FUN_80166604
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166604  body 0x80166604..0x80166643  size 64 B
 * body sha256 b765482e8d7a2ab26fbdda2024de4188b03890c00d00c064808afe72babb926a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80166604  90a20013  lbu $v0,19($a1)
 * 0x80166608  1440000c  bne $v0,$zero,+12
 * 0x8016660c  24040001  addiu $a0,$zero,0x0001
 * 0x80166610  90a30014  lbu $v1,20($a1)
 * 0x80166614  94a20006  lhu $v0,6($a1)
 * 0x80166618  a0a40004  sb $a0,4($a1)
 * 0x8016661c  00431023  subu $v0,$v0,$v1
 * 0x80166620  a4a20006  sh $v0,6($a1)
 * 0x80166624  00021400  sll $v0,$v0,16
 * 0x80166628  1c400004  bgtz $v0,+4
 * 0x8016662c  00000000  sll $zero,$zero,0
 * 0x80166630  a0a40013  sb $a0,19($a1)
 * 0x80166634  a4a00006  sh $zero,6($a1)
 * 0x80166638  a0a00004  sb $zero,4($a1)
 * 0x8016663c  03e00008  jr $ra
 * 0x80166640  00000000  sll $zero,$zero,0
 */
