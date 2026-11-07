/* FUN_8003247c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003247c  body 0x8003247c..0x800324a7  size 44 B
 * body sha256 841c142528819d4a1d6477d4dfe14f0d48bc006d3c5d6a6f13f9a58b5c796eab
 * EXTENT MEASURED, NOT RECONSTRUCTED: 11 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8003247c..0x800327eb, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8003247c  3c020001  lui $v0,0x0001
 * 0x80032480  34428000  ori $v0,$v0,0x8000
 * 0x80032484  3c03800c  lui $v1,0x800c
 * 0x80032488  246376b0  addiu $v1,$v1,0x76b0
 * 0x8003248c  00621821  addu $v1,$v1,$v0
 * 0x80032490  ac800000  sw $zero,0($a0)
 * 0x80032494  ac800004  sw $zero,4($a0)
 * 0x80032498  90621a76  lbu $v0,6774($v1)
 * 0x8003249c  2442ffff  addiu $v0,$v0,0xffff
 * 0x800324a0  03e00008  jr $ra
 * 0x800324a4  a0621a76  sb $v0,6774($v1)
 */
