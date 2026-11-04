/* FUN_80163760
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163760  body 0x80163760..0x801637b3  size 84 B
 * body sha256 39998f1e481ba1e94ae1ce08c9c340294d06649f99b66ec3298778d8e67a627d
 * EXTENT MEASURED, NOT RECONSTRUCTED: 21 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80163760  3c02800c  lui $v0,0x800c
 * 0x80163764  244276b0  addiu $v0,$v0,0x76b0
 * 0x80163768  3c030002  lui $v1,0x0002
 * 0x8016376c  00431021  addu $v0,$v0,$v1
 * 0x80163770  90421962  lbu $v0,6498($v0)
 * 0x80163774  30420008  andi $v0,$v0,0x0008
 * 0x80163778  50400004  op&0x14 $zero,$v0,0x0004
 * 0x8016377c  aca00000  sw $zero,0($a1)
 * 0x80163780  8ca20000  lw $v0,0($a1)
 * 0x80163784  3442004a  ori $v0,$v0,0x004a
 * 0x80163788  aca20000  sw $v0,0($a1)
 * 0x8016378c  94830066  lhu $v1,102($a0)
 * 0x80163790  2402fff6  addiu $v0,$zero,0xfff6
 * 0x80163794  a4a00138  sh $zero,312($a1)
 * 0x80163798  a4a00134  sh $zero,308($a1)
 * 0x8016379c  a4a20132  sh $v0,306($a1)
 * 0x801637a0  a4a00136  sh $zero,310($a1)
 * 0x801637a4  a4a0013c  sh $zero,316($a1)
 * 0x801637a8  24630800  addiu $v1,$v1,0x0800
 * 0x801637ac  03e00008  jr $ra
 * 0x801637b0  a4a30130  sh $v1,304($a1)
 */
