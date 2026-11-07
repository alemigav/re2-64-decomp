/* FUN_80048108
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048108  body 0x80048108..0x800481b3  size 172 B
 * body sha256 eb7363143766c36a53c1983ba7bfc80d3208081b3a30a0da97df6483ccc4c3c2
 * EXTENT MEASURED, NOT RECONSTRUCTED: 43 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80048108..0x80048293, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80048108  44801000  op&0x11 $zero,$a0,0x1000
 * 0x8004810c  3c01800c  lui $at,0x800c
 * 0x80048110  c426896c  op&0x31 $a2,$at,0x896c
 * 0x80048114  4602603c  op&0x11 $v0,$s0,0x603c
 * 0x80048118  00000000  sll $zero,$zero,0
 * 0x8004811c  45010025  op&0x11 $at,$t0,0x0025
 * 0x80048120  46001006  op&0x11 $zero,$s0,0x1006
 * 0x80048124  3c01800c  lui $at,0x800c
 * 0x80048128  c4208970  op&0x31 $zero,$at,0x8970
 * 0x8004812c  460c003c  op&0x11 $t4,$s0,0x003c
 * 0x80048130  00000000  sll $zero,$zero,0
 * 0x80048134  45000006  op&0x11 $zero,$t0,0x0006
 * 0x80048138  00000000  sll $zero,$zero,0
 * 0x8004813c  46006303  op&0x11 $zero,$s0,0x6303
 * 0x80048140  460c003c  op&0x11 $t4,$s0,0x003c
 * 0x80048144  00000000  sll $zero,$zero,0
 * 0x80048148  4501fffc  op&0x11 $at,$t0,0xfffc
 * 0x8004814c  46061080  op&0x11 $a2,$s0,0x1080
 * 0x80048150  3c01800c  lui $at,0x800c
 * 0x80048154  c4208974  op&0x31 $zero,$at,0x8974
 * 0x80048158  4600603c  op&0x11 $zero,$s0,0x603c
 * 0x8004815c  00000000  sll $zero,$zero,0
 * 0x80048160  45000008  op&0x11 $zero,$t0,0x0008
 * 0x80048164  00000000  sll $zero,$zero,0
 * 0x80048168  3c01800c  lui $at,0x800c
 * 0x8004816c  c4248978  op&0x31 $a0,$at,0x8978
 * 0x80048170  46046302  op&0x11 $a0,$s0,0x6302
 * 0x80048174  4600603c  op&0x11 $zero,$s0,0x603c
 * 0x80048178  00000000  sll $zero,$zero,0
 * 0x8004817c  4501fffc  op&0x11 $at,$t0,0xfffc
 * 0x80048180  46061081  op&0x11 $a2,$s0,0x1081
 * 0x80048184  3c01800c  lui $at,0x800c
 * 0x80048188  c420897c  op&0x31 $zero,$at,0x897c
 * 0x8004818c  46006002  op&0x11 $zero,$s0,0x6002
 * 0x80048190  3c02800f  lui $v0,0x800f
 * 0x80048194  24420300  addiu $v0,$v0,0x0300
 * 0x80048198  4600020d  op&0x11 $zero,$s0,0x020d
 * 0x8004819c  44034000  op&0x11 $v1,$zero,0x4000
 * 0x800481a0  00031880  sll $v1,$v1,2
 * 0x800481a4  00621821  addu $v1,$v1,$v0
 * 0x800481a8  c4600000  op&0x31 $zero,$v1,0x0000
 * 0x800481ac  03e00008  jr $ra
 * 0x800481b0  46001000  op&0x11 $zero,$s0,0x1000
 */
