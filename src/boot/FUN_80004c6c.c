/* FUN_80004c6c
 * image   boot (boot), base 0x80000480
 * address 0x80004c6c  body 0x80004c6c..0x80004c9b  size 48 B
 * body sha256 76d8fb46520a77bfd5b2c79292577ef1d3f402a88e345f23f5b84029ab30a495
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `gap` run that no provider range covers; the run is 0x80004c6c..0x80004c9b, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80004c6c  3c040001  lui $a0,0x0001
 * 0x80004c70  34848000  ori $a0,$a0,0x8000
 * 0x80004c74  3c028001  lui $v0,0x8001
 * 0x80004c78  3c03800c  lui $v1,0x800c
 * 0x80004c7c  246376b0  addiu $v1,$v1,0x76b0
 * 0x80004c80  00641821  addu $v1,$v1,$a0
 * 0x80004c84  ac402884  sw $zero,10372($v0)
 * 0x80004c88  8c621a5c  lw $v0,6748($v1)
 * 0x80004c8c  2404ffdf  addiu $a0,$zero,0xffdf
 * 0x80004c90  00441024  and $v0,$v0,$a0
 * 0x80004c94  03e00008  jr $ra
 * 0x80004c98  ac621a5c  sw $v0,6748($v1)
 */
