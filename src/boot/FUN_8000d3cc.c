/* FUN_8000d3cc
 * image   boot (boot), base 0x80000480
 * address 0x8000d3cc  body 0x8000d3cc..0x8000d427  size 92 B
 * body sha256 4a236803677a6a8c0ce41ef06c275deaa92602d28e4193e33bbb7aee57b9fb68
 * EXTENT MEASURED, NOT RECONSTRUCTED: 23 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8000d3cc  00000000  sll $zero,$zero,0
 * 0x8000d3d0  afa50004  sw $a1,4($sp)
 * 0x8000d3d4  afa60008  sw $a2,8($sp)
 * 0x8000d3d8  afa7000c  sw $a3,12($sp)
 * 0x8000d3dc  27bdffe8  addiu $sp,$sp,0xffe8
 * 0x8000d3e0  afb00010  sw $s0,16($sp)
 * 0x8000d3e4  00808021  addu $s0,$a0,$zero
 * 0x8000d3e8  00a03021  addu $a2,$a1,$zero
 * 0x8000d3ec  3c048001  lui $a0,0x8001
 * 0x8000d3f0  2484d428  addiu $a0,$a0,0xd428
 * 0x8000d3f4  02002821  addu $a1,$s0,$zero
 * 0x8000d3f8  afbf0014  sw $ra,20($sp)
 * 0x8000d3fc  0c003c14  jal 0x8000f050
 * 0x8000d400  27a70020  addiu $a3,$sp,0x0020
 * 0x8000d404  00401821  addu $v1,$v0,$zero
 * 0x8000d408  04600002  op&0x01 $zero,$v1,0x0002
 * 0x8000d40c  02031021  addu $v0,$s0,$v1
 * 0x8000d410  a0400000  sb $zero,0($v0)
 * 0x8000d414  00601021  addu $v0,$v1,$zero
 * 0x8000d418  8fbf0014  lw $ra,20($sp)
 * 0x8000d41c  8fb00010  lw $s0,16($sp)
 * 0x8000d420  03e00008  jr $ra
 * 0x8000d424  27bd0018  addiu $sp,$sp,0x0018
 */
