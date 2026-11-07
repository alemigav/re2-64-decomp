/* FUN_8001f434
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f434  body 0x8001f434..0x8001f46f  size 60 B
 * body sha256 10e0b0046220027eac48c23e59c98c2e1507891740cc95dd1047af515841e3af
 * EXTENT MEASURED, NOT RECONSTRUCTED: 15 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8001f434  200c4000  op&0x08 $t4,$zero,0x4000
 * 0x8001f438  408c2000  cop0 rs=4 rt=$t4 rd=4
 * 0x8001f43c  0000000d  special&0x0d $zero,$zero,$zero
 * 0x8001f440  00000000  sll $zero,$zero,0
 * 0x8001f444  00000000  sll $zero,$zero,0
 * 0x8001f448  900100de  lbu $at,222($zero)
 * 0x8001f44c  001913c0  sll $v0,$t9,15
 * 0x8001f450  0c000487  jal 0x8000121c
 * 0x8001f454  035b1820  add $v1,$k0,$k1
 * 0x8001f458  04400057  op&0x01 $zero,$v0,0x0057
 * 0x8001f45c  371a0000  ori $k0,$t8,0x0000
 * 0x8001f460  ac230138  sw $v1,312($at)
 * 0x8001f464  20210004  op&0x08 $at,$at,0x0004
 * 0x8001f468  0800045c  j 0x80001170
 * 0x8001f46c  a00100de  sb $at,222($zero)
 */
