/* FUN_8006efcc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006efcc  body 0x8006efcc..0x8006f03f  size 116 B
 * body sha256 29b92f45a7af75b739a80063f73ed0c49155455265f10654d8f96b6546f04341
 * EXTENT MEASURED, NOT RECONSTRUCTED: 29 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006efcc  00802821  addu $a1,$a0,$zero
 * 0x8006efd0  3c040001  lui $a0,0x0001
 * 0x8006efd4  34848000  ori $a0,$a0,0x8000
 * 0x8006efd8  8ca2001c  lw $v0,28($a1)
 * 0x8006efdc  3c03800c  lui $v1,0x800c
 * 0x8006efe0  90420001  lbu $v0,1($v0)
 * 0x8006efe4  246676b0  addiu $a2,$v1,0x76b0
 * 0x8006efe8  00021080  sll $v0,$v0,2
 * 0x8006efec  00461021  addu $v0,$v0,$a2
 * 0x8006eff0  00442021  addu $a0,$v0,$a0
 * 0x8006eff4  8c8204b0  lw $v0,1200($a0)
 * 0x8006eff8  14400005  bne $v0,$zero,+5
 * 0x8006effc  3c030002  lui $v1,0x0002
 * 0x8006f000  00c31821  addu $v1,$a2,$v1
 * 0x8006f004  90620f54  lbu $v0,3924($v1)
 * 0x8006f008  24420001  addiu $v0,$v0,0x0001
 * 0x8006f00c  a0620f54  sb $v0,3924($v1)
 * 0x8006f010  8ca2001c  lw $v0,28($a1)
 * 0x8006f014  24420002  addiu $v0,$v0,0x0002
 * 0x8006f018  ac8204b0  sw $v0,1200($a0)
 * 0x8006f01c  8ca3001c  lw $v1,28($a1)
 * 0x8006f020  90620003  lbu $v0,3($v1)
 * 0x8006f024  34420080  ori $v0,$v0,0x0080
 * 0x8006f028  a0620003  sb $v0,3($v1)
 * 0x8006f02c  8ca2001c  lw $v0,28($a1)
 * 0x8006f030  24420028  addiu $v0,$v0,0x0028
 * 0x8006f034  aca2001c  sw $v0,28($a1)
 * 0x8006f038  03e00008  jr $ra
 * 0x8006f03c  24020001  addiu $v0,$zero,0x0001
 */
