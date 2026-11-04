/* FUN_80072e9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072e9c  body 0x80072e9c..0x80072ef3  size 88 B
 * body sha256 146a42e283c0071b9e20564c580ab855e6dc3d0472979315faad1c01035baecd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 22 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80072e9c  3c020001  lui $v0,0x0001
 * 0x80072ea0  34428000  ori $v0,$v0,0x8000
 * 0x80072ea4  3c03800c  lui $v1,0x800c
 * 0x80072ea8  246376b0  addiu $v1,$v1,0x76b0
 * 0x80072eac  8c86001c  lw $a2,28($a0)
 * 0x80072eb0  00621821  addu $v1,$v1,$v0
 * 0x80072eb4  90c50002  lbu $a1,2($a2)
 * 0x80072eb8  8c63027c  lw $v1,636($v1)
 * 0x80072ebc  00051080  sll $v0,$a1,2
 * 0x80072ec0  00451021  addu $v0,$v0,$a1
 * 0x80072ec4  000210c0  sll $v0,$v0,3
 * 0x80072ec8  8c65002c  lw $a1,44($v1)
 * 0x80072ecc  90c30003  lbu $v1,3($a2)
 * 0x80072ed0  00451021  addu $v0,$v0,$a1
 * 0x80072ed4  00031840  sll $v1,$v1,1
 * 0x80072ed8  00431021  addu $v0,$v0,$v1
 * 0x80072edc  94c50004  lhu $a1,4($a2)
 * 0x80072ee0  24c60006  addiu $a2,$a2,0x0006
 * 0x80072ee4  a4450022  sh $a1,34($v0)
 * 0x80072ee8  24020001  addiu $v0,$zero,0x0001
 * 0x80072eec  03e00008  jr $ra
 * 0x80072ef0  ac86001c  sw $a2,28($a0)
 */
