/* FUN_80036b2c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036b2c  body 0x80036b2c..0x80036b7b  size 80 B
 * body sha256 e574d53a3276838df0b89fdd36e12d6500e8f4a36b1343bcd1f29add3f22ed31
 * EXTENT MEASURED, NOT RECONSTRUCTED: 20 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80036b2c..0x80036b83, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80036b2c  8c870000  lw $a3,0($a0)
 * 0x80036b30  3c028000  lui $v0,0x8000
 * 0x80036b34  00e51823  subu $v1,$a3,$a1
 * 0x80036b38  00624024  and $t0,$v1,$v0
 * 0x80036b3c  11000004  beq $t0,$zero,+4
 * 0x80036b40  00061400  sll $v0,$a2,16
 * 0x80036b44  00021403  sra $v0,$v0,16
 * 0x80036b48  0800dad6  j 0x80036b58
 * 0x80036b4c  00e21021  addu $v0,$a3,$v0
 * 0x80036b50  00021403  sra $v0,$v0,16
 * 0x80036b54  00e21023  subu $v0,$a3,$v0
 * 0x80036b58  ac820000  sw $v0,0($a0)
 * 0x80036b5c  8c820000  lw $v0,0($a0)
 * 0x80036b60  3c038000  lui $v1,0x8000
 * 0x80036b64  00451023  subu $v0,$v0,$a1
 * 0x80036b68  00431024  and $v0,$v0,$v1
 * 0x80036b6c  55020003  op&0x15 $v0,$t0,0x0003
 * 0x80036b70  ac850000  sw $a1,0($a0)
 * 0x80036b74  03e00008  jr $ra
 * 0x80036b78  00001021  addu $v0,$zero,$zero
 */
