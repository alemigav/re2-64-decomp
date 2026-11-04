/* FUN_80072f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072f64  body 0x80072f64..0x80072f93  size 48 B
 * body sha256 8d8c4d43cd8a1bcec25630b0b845823d3901e249741caff32923aec7827de265
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80072f64  3c02800c  lui $v0,0x800c
 * 0x80072f68  244276b0  addiu $v0,$v0,0x76b0
 * 0x80072f6c  8c83001c  lw $v1,28($a0)
 * 0x80072f70  3c050002  lui $a1,0x0002
 * 0x80072f74  94630002  lhu $v1,2($v1)
 * 0x80072f78  00451021  addu $v0,$v0,$a1
 * 0x80072f7c  a4431270  sh $v1,4720($v0)
 * 0x80072f80  8c82001c  lw $v0,28($a0)
 * 0x80072f84  24420004  addiu $v0,$v0,0x0004
 * 0x80072f88  ac82001c  sw $v0,28($a0)
 * 0x80072f8c  03e00008  jr $ra
 * 0x80072f90  24020001  addiu $v0,$zero,0x0001
 */
