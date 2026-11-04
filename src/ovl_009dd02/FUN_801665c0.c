/* FUN_801665c0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801665c0  body 0x801665c0..0x80166603  size 68 B
 * body sha256 3a472a9498d23c4368d4da9977e49b92b53620deb0441ffb9644ebf8479ba39e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 17 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x801665c0  90a20013  lbu $v0,19($a1)
 * 0x801665c4  1440000d  bne $v0,$zero,+13
 * 0x801665c8  24040001  addiu $a0,$zero,0x0001
 * 0x801665cc  90a30014  lbu $v1,20($a1)
 * 0x801665d0  94a20006  lhu $v0,6($a1)
 * 0x801665d4  a0a40004  sb $a0,4($a1)
 * 0x801665d8  00431021  addu $v0,$v0,$v1
 * 0x801665dc  a4a20006  sh $v0,6($a1)
 * 0x801665e0  00021400  sll $v0,$v0,16
 * 0x801665e4  00021403  sra $v0,$v0,16
 * 0x801665e8  28420100  op&0x0a $v0,$v0,0x0100
 * 0x801665ec  14400003  bne $v0,$zero,+3
 * 0x801665f0  24020100  addiu $v0,$zero,0x0100
 * 0x801665f4  a0a40013  sb $a0,19($a1)
 * 0x801665f8  a4a20006  sh $v0,6($a1)
 * 0x801665fc  03e00008  jr $ra
 * 0x80166600  00000000  sll $zero,$zero,0
 */
