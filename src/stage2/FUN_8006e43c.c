/* FUN_8006e43c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e43c  body 0x8006e43c..0x8006e48b  size 80 B
 * body sha256 c83fa7121f0b9f3f8f5515e78e321c274199154a6c69f4815012420009b33acd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 20 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006e43c  90830002  lbu $v1,2($a0)
 * 0x8006e440  2463ffff  addiu $v1,$v1,0xffff
 * 0x8006e444  a0830002  sb $v1,2($a0)
 * 0x8006e448  00031e00  sll $v1,$v1,24
 * 0x8006e44c  00031e03  sra $v1,$v1,24
 * 0x8006e450  00031080  sll $v0,$v1,2
 * 0x8006e454  00821021  addu $v0,$a0,$v0
 * 0x8006e458  8c420144  lw $v0,324($v0)
 * 0x8006e45c  ac82001c  sw $v0,28($a0)
 * 0x8006e460  00031140  sll $v0,$v1,5
 * 0x8006e464  244200c0  addiu $v0,$v0,0x00c0
 * 0x8006e468  00831821  addu $v1,$a0,$v1
 * 0x8006e46c  80630004  lb $v1,4($v1)
 * 0x8006e470  00821021  addu $v0,$a0,$v0
 * 0x8006e474  00031880  sll $v1,$v1,2
 * 0x8006e478  24630004  addiu $v1,$v1,0x0004
 * 0x8006e47c  00431021  addu $v0,$v0,$v1
 * 0x8006e480  ac820140  sw $v0,320($a0)
 * 0x8006e484  03e00008  jr $ra
 * 0x8006e488  24020001  addiu $v0,$zero,0x0001
 */
