/* FUN_80050f38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80050f38  body 0x80050f38..0x80050fa7  size 112 B
 * body sha256 6c222072b402c8ab3509c7b27d36e3e59fd4bf68f2c70a94721647edc321e39e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 28 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80050f38  3c050040  lui $a1,0x0040
 * 0x80050f3c  8c8201e8  lw $v0,488($a0)
 * 0x80050f40  34a54040  ori $a1,$a1,0x4040
 * 0x80050f44  3442004a  ori $v0,$v0,0x004a
 * 0x80050f48  ac8201e8  sw $v0,488($a0)
 * 0x80050f4c  94820066  lhu $v0,102($a0)
 * 0x80050f50  248301e8  addiu $v1,$a0,0x01e8
 * 0x80050f54  a4600134  sh $zero,308($v1)
 * 0x80050f58  a4600136  sh $zero,310($v1)
 * 0x80050f5c  a460013c  sh $zero,316($v1)
 * 0x80050f60  ac650060  sw $a1,96($v1)
 * 0x80050f64  24420800  addiu $v0,$v0,0x0800
 * 0x80050f68  a4620130  sh $v0,304($v1)
 * 0x80050f6c  34028000  ori $v0,$zero,0x8000
 * 0x80050f70  a4620138  sh $v0,312($v1)
 * 0x80050f74  2402fff6  addiu $v0,$zero,0xfff6
 * 0x80050f78  a4620132  sh $v0,306($v1)
 * 0x80050f7c  8c6300c8  lw $v1,200($v1)
 * 0x80050f80  8c8200c0  lw $v0,192($a0)
 * 0x80050f84  8c680008  lw $t0,8($v1)
 * 0x80050f88  10400003  beq $v0,$zero,+3
 * 0x80050f8c  00000000  sll $zero,$zero,0
 * 0x80050f90  15000005  bne $t0,$zero,+5
 * 0x80050f94  240affff  addiu $t2,$zero,0xffff
 * 0x80050f98  11000048  beq $t0,$zero,+72
 * 0x80050f9c  00000000  sll $zero,$zero,0
 * 0x80050fa0  03e00008  jr $ra
 * 0x80050fa4  ac600008  sw $zero,8($v1)
 */
