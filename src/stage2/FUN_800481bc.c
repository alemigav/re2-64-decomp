/* FUN_800481bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800481bc  body 0x800481bc..0x8004827f  size 196 B
 * body sha256 fb658832518157150d1bf5ae0126ae0f759a32ec5890c24a75dfa0e03125e0a1
 * EXTENT MEASURED, NOT RECONSTRUCTED: 49 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x800481bc  46006121  op&0x11 $zero,$s0,0x6121
 * 0x800481c0  44800000  op&0x11 $zero,$a0,0x0000
 * 0x800481c4  44800800  op&0x11 $zero,$a0,0x0800
 * 0x800481c8  3c01800c  lui $at,0x800c
 * 0x800481cc  c4268980  op&0x31 $a2,$at,0x8980
 * 0x800481d0  3c01800c  lui $at,0x800c
 * 0x800481d4  c4228984  op&0x31 $v0,$at,0x8984
 * 0x800481d8  4620203c  op&0x11 $zero,$s1,0x203c
 * 0x800481dc  00000000  sll $zero,$zero,0
 * 0x800481e0  45030001  op&0x11 $v1,$t0,0x0001
 * 0x800481e4  46202107  op&0x11 $zero,$s1,0x2107
 * 0x800481e8  3c01800c  lui $at,0x800c
 * 0x800481ec  c4208988  op&0x31 $zero,$at,0x8988
 * 0x800481f0  46202120  op&0x11 $zero,$s1,0x2120
 * 0x800481f4  4604003c  op&0x11 $a0,$s0,0x003c
 * 0x800481f8  00000000  sll $zero,$zero,0
 * 0x800481fc  45000007  op&0x11 $zero,$t0,0x0007
 * 0x80048200  00000000  sll $zero,$zero,0
 * 0x80048204  46023182  op&0x11 $v0,$s0,0x3182
 * 0x80048208  46002101  op&0x11 $zero,$s0,0x2101
 * 0x8004820c  4604003c  op&0x11 $a0,$s0,0x003c
 * 0x80048210  00000000  sll $zero,$zero,0
 * 0x80048214  4501fffb  op&0x11 $at,$t0,0xfffb
 * 0x80048218  00000000  sll $zero,$zero,0
 * 0x8004821c  3c01800c  lui $at,0x800c
 * 0x80048220  c422898c  op&0x31 $v0,$at,0x898c
 * 0x80048224  46022002  op&0x11 $v0,$s0,0x2002
 * 0x80048228  3c02800f  lui $v0,0x800f
 * 0x8004822c  24421328  addiu $v0,$v0,0x1328
 * 0x80048230  4600020d  op&0x11 $zero,$s0,0x020d
 * 0x80048234  44034000  op&0x11 $v1,$zero,0x4000
 * 0x80048238  44830000  op&0x11 $v1,$a0,0x0000
 * 0x8004823c  46800020  op&0x11 $zero,$s4,0x0020
 * 0x80048240  46020003  op&0x11 $v0,$s0,0x0003
 * 0x80048244  00031880  sll $v1,$v1,2
 * 0x80048248  46002001  op&0x11 $zero,$s0,0x2001
 * 0x8004824c  3c01800c  lui $at,0x800c
 * 0x80048250  c4228990  op&0x31 $v0,$at,0x8990
 * 0x80048254  00621821  addu $v1,$v1,$v0
 * 0x80048258  46020000  op&0x11 $v0,$s0,0x0000
 * 0x8004825c  c4620000  op&0x31 $v0,$v1,0x0000
 * 0x80048260  46001082  op&0x11 $zero,$s0,0x1082
 * 0x80048264  44800000  op&0x11 $zero,$a0,0x0000
 * 0x80048268  4600603c  op&0x11 $zero,$s0,0x603c
 * 0x8004826c  46023182  op&0x11 $v0,$s0,0x3182
 * 0x80048270  45030003  op&0x11 $v1,$t0,0x0003
 * 0x80048274  460030a1  op&0x11 $zero,$s0,0x30a1
 * 0x80048278  03e00008  jr $ra
 * 0x8004827c  46003006  op&0x11 $zero,$s0,0x3006
 */
