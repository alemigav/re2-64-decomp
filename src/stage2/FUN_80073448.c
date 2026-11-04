/* FUN_80073448
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073448  body 0x80073448..0x800734af  size 104 B
 * body sha256 a1241892554e1af76d04a1cfbacce65d19f72f46a16bac3d2ee672a5afafdf58
 * EXTENT MEASURED, NOT RECONSTRUCTED: 26 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073448  3c030001  lui $v1,0x0001
 * 0x8007344c  34638000  ori $v1,$v1,0x8000
 * 0x80073450  3c078013  lui $a3,0x8013
 * 0x80073454  24e7bf98  addiu $a3,$a3,0xbf98
 * 0x80073458  24020004  addiu $v0,$zero,0x0004
 * 0x8007345c  3c058013  lui $a1,0x8013
 * 0x80073460  a0e20010  sb $v0,16($a3)
 * 0x80073464  24020001  addiu $v0,$zero,0x0001
 * 0x80073468  a0a21780  sb $v0,6016($a1)
 * 0x8007346c  3c02800c  lui $v0,0x800c
 * 0x80073470  244276b0  addiu $v0,$v0,0x76b0
 * 0x80073474  00431021  addu $v0,$v0,$v1
 * 0x80073478  24a51780  addiu $a1,$a1,0x1780
 * 0x8007347c  8c431a5c  lw $v1,6748($v0)
 * 0x80073480  8c461a60  lw $a2,6752($v0)
 * 0x80073484  34638000  ori $v1,$v1,0x8000
 * 0x80073488  aca60044  sw $a2,68($a1)
 * 0x8007348c  ac431a5c  sw $v1,6748($v0)
 * 0x80073490  8c82001c  lw $v0,28($a0)
 * 0x80073494  90420001  lbu $v0,1($v0)
 * 0x80073498  a0e2358a  sb $v0,13706($a3)
 * 0x8007349c  8c82001c  lw $v0,28($a0)
 * 0x800734a0  24420002  addiu $v0,$v0,0x0002
 * 0x800734a4  ac82001c  sw $v0,28($a0)
 * 0x800734a8  03e00008  jr $ra
 * 0x800734ac  24020001  addiu $v0,$zero,0x0001
 */
