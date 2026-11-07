/* FUN_800113d8
 * image   boot (boot), base 0x80000480
 * address 0x800113d8  body 0x800113d8..0x80011457  size 128 B
 * body sha256 bb7c970b966a446367ecfbd63b31298347c257d50c332490ba34ca001ac95941
 * EXTENT MEASURED, NOT RECONSTRUCTED: 32 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x800113d8  00000000  sll $zero,$zero,0
 * 0x800113dc  00000000  sll $zero,$zero,0
 * 0x800113e0  44841000  op&0x11 $a0,$a0,0x1000
 * 0x800113e4  00000000  sll $zero,$zero,0
 * 0x800113e8  468010a1  op&0x11 $zero,$s4,0x10a1
 * 0x800113ec  3c018001  lui $at,0x8001
 * 0x800113f0  c42428c8  op&0x31 $a0,$at,0x28c8
 * 0x800113f4  46802120  op&0x11 $zero,$s4,0x2120
 * 0x800113f8  04830005  op&0x01 $v1,$a0,0x0005
 * 0x800113fc  46201020  op&0x11 $zero,$s1,0x1020
 * 0x80011400  3c018001  lui $at,0x8001
 * 0x80011404  d4202100  op&0x35 $zero,$at,0x2100
 * 0x80011408  46201080  op&0x11 $zero,$s1,0x1080
 * 0x8001140c  46201020  op&0x11 $zero,$s1,0x1020
 * 0x80011410  46002003  op&0x11 $zero,$s0,0x2003
 * 0x80011414  3c013f00  lui $at,0x3f00
 * 0x80011418  44811000  op&0x11 $at,$a0,0x1000
 * 0x8001141c  00000000  sll $zero,$zero,0
 * 0x80011420  46020080  op&0x11 $v0,$s0,0x0080
 * 0x80011424  3c014f00  lui $at,0x4f00
 * 0x80011428  44810000  op&0x11 $at,$a0,0x0000
 * 0x8001142c  00000000  sll $zero,$zero,0
 * 0x80011430  4602003e  op&0x11 $v0,$s0,0x003e
 * 0x80011434  00000000  sll $zero,$zero,0
 * 0x80011438  00000000  sll $zero,$zero,0
 * 0x8001143c  45030006  op&0x11 $v1,$t0,0x0006
 * 0x80011440  46001001  op&0x11 $zero,$s0,0x1001
 * 0x80011444  4600100d  op&0x11 $zero,$s0,0x100d
 * 0x80011448  44060000  op&0x11 $a2,$zero,0x0000
 * 0x8001144c  00000000  sll $zero,$zero,0
 * 0x80011450  0800451b  j 0x8001146c
 * 0x80011454  2cc20084  op&0x0b $v0,$a2,0x0084
 */
