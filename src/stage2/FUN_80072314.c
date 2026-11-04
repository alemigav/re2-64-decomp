/* FUN_80072314
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072314  body 0x80072314..0x80072353  size 64 B
 * body sha256 0328d45cf0c8eae589e00c7849091d86ac42a5cb8f92fd9f43aacf8aa2315f86
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
 * 0x80072314  3c050001  lui $a1,0x0001
 * 0x80072318  8c82001c  lw $v0,28($a0)
 * 0x8007231c  34a58000  ori $a1,$a1,0x8000
 * 0x80072320  90460001  lbu $a2,1($v0)
 * 0x80072324  94430002  lhu $v1,2($v0)
 * 0x80072328  24420004  addiu $v0,$v0,0x0004
 * 0x8007232c  ac82001c  sw $v0,28($a0)
 * 0x80072330  3c02800c  lui $v0,0x800c
 * 0x80072334  244276b0  addiu $v0,$v0,0x76b0
 * 0x80072338  00451021  addu $v0,$v0,$a1
 * 0x8007233c  8c420268  lw $v0,616($v0)
 * 0x80072340  00431024  and $v0,$v0,$v1
 * 0x80072344  10400003  beq $v0,$zero,+3
 * 0x80072348  38c20001  op&0x0e $v0,$a2,0x0001
 * 0x8007234c  03e00008  jr $ra
 * 0x80072350  00c01021  addu $v0,$a2,$zero
 */
