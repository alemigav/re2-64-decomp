/* FUN_800712e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800712e8  body 0x800712e8..0x8007133f  size 88 B
 * body sha256 28143871119060bf469c55227e7af91a05c4baa94425aa969fd5b0d553b73a21
 * EXTENT MEASURED, NOT RECONSTRUCTED: 22 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x800712e8  3c030001  lui $v1,0x0001
 * 0x800712ec  34638000  ori $v1,$v1,0x8000
 * 0x800712f0  3c02800c  lui $v0,0x800c
 * 0x800712f4  244276b0  addiu $v0,$v0,0x76b0
 * 0x800712f8  00431021  addu $v0,$v0,$v1
 * 0x800712fc  8c86001c  lw $a2,28($a0)
 * 0x80071300  8c42027c  lw $v0,636($v0)
 * 0x80071304  90c30001  lbu $v1,1($a2)
 * 0x80071308  8c450020  lw $a1,32($v0)
 * 0x8007130c  94c20002  lhu $v0,2($a2)
 * 0x80071310  24c60004  addiu $a2,$a2,0x0004
 * 0x80071314  24630001  addiu $v1,$v1,0x0001
 * 0x80071318  00031900  sll $v1,$v1,4
 * 0x8007131c  00a32821  addu $a1,$a1,$v1
 * 0x80071320  94a30008  lhu $v1,8($a1)
 * 0x80071324  3042ff80  andi $v0,$v0,0xff80
 * 0x80071328  3063007f  andi $v1,$v1,0x007f
 * 0x8007132c  00621825  or $v1,$v1,$v0
 * 0x80071330  24020001  addiu $v0,$zero,0x0001
 * 0x80071334  a4a30008  sh $v1,8($a1)
 * 0x80071338  03e00008  jr $ra
 * 0x8007133c  ac86001c  sw $a2,28($a0)
 */
