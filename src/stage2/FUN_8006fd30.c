/* FUN_8006fd30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fd30  body 0x8006fd30..0x8006fd57  size 40 B
 * body sha256 daccb57a9da7d5bfa177f7a9de97d241adf31d1b308dcde7fac7daba010a8cec
 * EXTENT MEASURED, NOT RECONSTRUCTED: 10 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006fd30  8c82001c  lw $v0,28($a0)
 * 0x8006fd34  90430001  lbu $v1,1($v0)
 * 0x8006fd38  94450002  lhu $a1,2($v0)
 * 0x8006fd3c  24420004  addiu $v0,$v0,0x0004
 * 0x8006fd40  ac82001c  sw $v0,28($a0)
 * 0x8006fd44  24020001  addiu $v0,$zero,0x0001
 * 0x8006fd48  00031840  sll $v1,$v1,1
 * 0x8006fd4c  00641821  addu $v1,$v1,$a0
 * 0x8006fd50  03e00008  jr $ra
 * 0x8006fd54  a4650158  sh $a1,344($v1)
 */
