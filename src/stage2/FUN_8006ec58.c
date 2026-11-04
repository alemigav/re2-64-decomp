/* FUN_8006ec58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006ec58  body 0x8006ec58..0x8006ecbf  size 104 B
 * body sha256 7460adbbc4215a011def5ab09398f92f3bc7a546bfc058f2f4a2aa21b0d41b57
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
 * 0x8006ec58  00802821  addu $a1,$a0,$zero
 * 0x8006ec5c  8ca2001c  lw $v0,28($a1)
 * 0x8006ec60  90430001  lbu $v1,1($v0)
 * 0x8006ec64  24020001  addiu $v0,$zero,0x0001
 * 0x8006ec68  14620009  bne $v1,$v0,+9
 * 0x8006ec6c  3c020001  lui $v0,0x0001
 * 0x8006ec70  34428000  ori $v0,$v0,0x8000
 * 0x8006ec74  3c03800c  lui $v1,0x800c
 * 0x8006ec78  246376b0  addiu $v1,$v1,0x76b0
 * 0x8006ec7c  00621821  addu $v1,$v1,$v0
 * 0x8006ec80  8c621a5c  lw $v0,6748($v1)
 * 0x8006ec84  2404feff  addiu $a0,$zero,0xfeff
 * 0x8006ec88  0801bb2a  j 0x8006eca8
 * 0x8006ec8c  00441024  and $v0,$v0,$a0
 * 0x8006ec90  34428000  ori $v0,$v0,0x8000
 * 0x8006ec94  3c03800c  lui $v1,0x800c
 * 0x8006ec98  246376b0  addiu $v1,$v1,0x76b0
 * 0x8006ec9c  00621821  addu $v1,$v1,$v0
 * 0x8006eca0  8c621a5c  lw $v0,6748($v1)
 * 0x8006eca4  34420100  ori $v0,$v0,0x0100
 * 0x8006eca8  ac621a5c  sw $v0,6748($v1)
 * 0x8006ecac  8ca2001c  lw $v0,28($a1)
 * 0x8006ecb0  24420002  addiu $v0,$v0,0x0002
 * 0x8006ecb4  aca2001c  sw $v0,28($a1)
 * 0x8006ecb8  03e00008  jr $ra
 * 0x8006ecbc  24020001  addiu $v0,$zero,0x0001
 */
