/* FUN_800b21f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b21f0  body 0x800b21f0..0x800b2297  size 168 B
 * body sha256 cbe2602ead2e1ff62d3677ae211f6ea0956ec11a1c0d9c36b22a77b2ac1fa3d7
 * EXTENT MEASURED, NOT RECONSTRUCTED: 42 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x800b21f0  3c028013  lui $v0,0x8013
 * 0x800b21f4  90426310  lbu $v0,25360($v0)
 * 0x800b21f8  27bdffe0  addiu $sp,$sp,0xffe0
 * 0x800b21fc  afb10014  sw $s1,20($sp)
 * 0x800b2200  00008821  addu $s1,$zero,$zero
 * 0x800b2204  afbf001c  sw $ra,28($sp)
 * 0x800b2208  afb20018  sw $s2,24($sp)
 * 0x800b220c  1040001a  beq $v0,$zero,+26
 * 0x800b2210  afb00010  sw $s0,16($sp)
 * 0x800b2214  3c028014  lui $v0,0x8014
 * 0x800b2218  24030001  addiu $v1,$zero,0x0001
 * 0x800b221c  a0437fa8  sb $v1,32680($v0)
 * 0x800b2220  0c02962f  jal 0x800a58bc
 * 0x800b2224  00000000  sll $zero,$zero,0
 * 0x800b2228  304200ff  andi $v0,$v0,0x00ff
 * 0x800b222c  54400010  op&0x15 $zero,$v0,0x0010
 * 0x800b2230  24110001  addiu $s1,$zero,0x0001
 * 0x800b2234  3c038014  lui $v1,0x8014
 * 0x800b2238  90627a58  lbu $v0,31320($v1)
 * 0x800b223c  1040000c  beq $v0,$zero,+12
 * 0x800b2240  00008021  addu $s0,$zero,$zero
 * 0x800b2244  00609021  addu $s2,$v1,$zero
 * 0x800b2248  0c029624  jal 0x800a5890
 * 0x800b224c  02002021  addu $a0,$s0,$zero
 * 0x800b2250  02228825  or $s1,$s1,$v0
 * 0x800b2254  92427a58  lbu $v0,31320($s2)
 * 0x800b2258  26100001  addiu $s0,$s0,0x0001
 * 0x800b225c  0202102a  slt $v0,$s0,$v0
 * 0x800b2260  1440fff9  bne $v0,$zero,-7
 * 0x800b2264  3c028014  lui $v0,0x8014
 * 0x800b2268  0802c89d  j 0x800b2274
 * 0x800b226c  00000000  sll $zero,$zero,0
 * 0x800b2270  3c028014  lui $v0,0x8014
 * 0x800b2274  a0407fa8  sb $zero,32680($v0)
 * 0x800b2278  322200ff  andi $v0,$s1,0x00ff
 * 0x800b227c  8fbf001c  lw $ra,28($sp)
 * 0x800b2280  8fb20018  lw $s2,24($sp)
 * 0x800b2284  8fb10014  lw $s1,20($sp)
 * 0x800b2288  8fb00010  lw $s0,16($sp)
 * 0x800b228c  2c420001  op&0x0b $v0,$v0,0x0001
 * 0x800b2290  03e00008  jr $ra
 * 0x800b2294  27bd0020  addiu $sp,$sp,0x0020
 */
