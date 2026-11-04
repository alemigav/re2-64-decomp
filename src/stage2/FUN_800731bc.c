/* FUN_800731bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800731bc  body 0x800731bc..0x80073223  size 104 B
 * body sha256 93538ad450deddff466567ad99498b6b59753d11f1dd3e75455a001a4f827469
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
 * 0x800731bc  3c020001  lui $v0,0x0001
 * 0x800731c0  34428000  ori $v0,$v0,0x8000
 * 0x800731c4  3c05800c  lui $a1,0x800c
 * 0x800731c8  24a576b0  addiu $a1,$a1,0x76b0
 * 0x800731cc  00a22821  addu $a1,$a1,$v0
 * 0x800731d0  8ca21a5c  lw $v0,6748($a1)
 * 0x800731d4  3c030001  lui $v1,0x0001
 * 0x800731d8  00431025  or $v0,$v0,$v1
 * 0x800731dc  aca21a5c  sw $v0,6748($a1)
 * 0x800731e0  8c82001c  lw $v0,28($a0)
 * 0x800731e4  90420001  lbu $v0,1($v0)
 * 0x800731e8  a0a21a41  sb $v0,6721($a1)
 * 0x800731ec  8c82001c  lw $v0,28($a0)
 * 0x800731f0  94420002  lhu $v0,2($v0)
 * 0x800731f4  a4a21a42  sh $v0,6722($a1)
 * 0x800731f8  8c82001c  lw $v0,28($a0)
 * 0x800731fc  94420004  lhu $v0,4($v0)
 * 0x80073200  a4a21a46  sh $v0,6726($a1)
 * 0x80073204  8c82001c  lw $v0,28($a0)
 * 0x80073208  94420006  lhu $v0,6($v0)
 * 0x8007320c  a4a21a44  sh $v0,6724($a1)
 * 0x80073210  8c82001c  lw $v0,28($a0)
 * 0x80073214  24420008  addiu $v0,$v0,0x0008
 * 0x80073218  ac82001c  sw $v0,28($a0)
 * 0x8007321c  03e00008  jr $ra
 * 0x80073220  24020001  addiu $v0,$zero,0x0001
 */
