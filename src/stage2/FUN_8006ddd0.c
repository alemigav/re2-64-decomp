/* FUN_8006ddd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ddd0  body 0x8006ddd0..0x8006de17  size 72 B
 * body sha256 e175425161ad89b994db90d0a9b29f53243285d96e29055f3a6feea4b2f9c420
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006ddd0  3c028010  lui $v0,0x8010
 * 0x8006ddd4  2442e288  addiu $v0,$v0,0xe288
 * 0x8006ddd8  34038000  ori $v1,$zero,0x8000
 * 0x8006dddc  00431021  addu $v0,$v0,$v1
 * 0x8006dde0  9042500c  lbu $v0,20492($v0)
 * 0x8006dde4  30420080  andi $v0,$v0,0x0080
 * 0x8006dde8  1440000b  bne $v0,$zero,+11
 * 0x8006ddec  00000000  sll $zero,$zero,0
 * 0x8006ddf0  8ca2001c  lw $v0,28($a1)
 * 0x8006ddf4  80a40002  lb $a0,2($a1)
 * 0x8006ddf8  24420001  addiu $v0,$v0,0x0001
 * 0x8006ddfc  00a42021  addu $a0,$a1,$a0
 * 0x8006de00  aca2001c  sw $v0,28($a1)
 * 0x8006de04  90830008  lbu $v1,8($a0)
 * 0x8006de08  24020002  addiu $v0,$zero,0x0002
 * 0x8006de0c  2463ffff  addiu $v1,$v1,0xffff
 * 0x8006de10  03e00008  jr $ra
 * 0x8006de14  a0830008  sb $v1,8($a0)
 */
