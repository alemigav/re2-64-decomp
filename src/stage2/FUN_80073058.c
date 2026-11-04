/* FUN_80073058
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073058  body 0x80073058..0x800730ff  size 168 B
 * body sha256 9f455d032b05c995db1b87baa42aeaa08e261f772039fc139403fa4c7214bd1e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 42 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80073058  00803821  addu $a3,$a0,$zero
 * 0x8007305c  3c040001  lui $a0,0x0001
 * 0x80073060  34848000  ori $a0,$a0,0x8000
 * 0x80073064  3c020100  lui $v0,0x0100
 * 0x80073068  8ce60154  lw $a2,340($a3)
 * 0x8007306c  3c051000  lui $a1,0x1000
 * 0x80073070  acc20004  sw $v0,4($a2)
 * 0x80073074  3c02800e  lui $v0,0x800e
 * 0x80073078  94c301aa  lhu $v1,426($a2)
 * 0x8007307c  24421130  addiu $v0,$v0,0x1130
 * 0x80073080  acc20254  sw $v0,596($a2)
 * 0x80073084  3c020002  lui $v0,0x0002
 * 0x80073088  a0c0025c  sb $zero,604($a2)
 * 0x8007308c  3063afff  andi $v1,$v1,0xafff
 * 0x80073090  34630400  ori $v1,$v1,0x0400
 * 0x80073094  a4c301aa  sh $v1,426($a2)
 * 0x80073098  3c03800c  lui $v1,0x800c
 * 0x8007309c  246376b0  addiu $v1,$v1,0x76b0
 * 0x800730a0  00642021  addu $a0,$v1,$a0
 * 0x800730a4  00621821  addu $v1,$v1,$v0
 * 0x800730a8  8c821a5c  lw $v0,6748($a0)
 * 0x800730ac  94631960  lhu $v1,6496($v1)
 * 0x800730b0  00451025  or $v0,$v0,$a1
 * 0x800730b4  ac821a5c  sw $v0,6748($a0)
 * 0x800730b8  a4c301f2  sh $v1,498($a2)
 * 0x800730bc  90c30008  lbu $v1,8($a2)
 * 0x800730c0  240200c8  addiu $v0,$zero,0x00c8
 * 0x800730c4  a4c201fe  sh $v0,510($a2)
 * 0x800730c8  24020045  addiu $v0,$zero,0x0045
 * 0x800730cc  10620004  beq $v1,$v0,+4
 * 0x800730d0  00000000  sll $zero,$zero,0
 * 0x800730d4  2402004f  addiu $v0,$zero,0x004f
 * 0x800730d8  14620004  bne $v1,$v0,+4
 * 0x800730dc  00000000  sll $zero,$zero,0
 * 0x800730e0  94c202b8  lhu $v0,696($a2)
 * 0x800730e4  3042dfff  andi $v0,$v0,0xdfff
 * 0x800730e8  a4c202b8  sh $v0,696($a2)
 * 0x800730ec  8ce2001c  lw $v0,28($a3)
 * 0x800730f0  24420001  addiu $v0,$v0,0x0001
 * 0x800730f4  ace2001c  sw $v0,28($a3)
 * 0x800730f8  03e00008  jr $ra
 * 0x800730fc  24020001  addiu $v0,$zero,0x0001
 */
