/* FUN_80049b18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049b18  body 0x80049b18..0x80049b93  size 124 B
 * body sha256 54cad7124031339709919a1397c2d3b443a40863615aa85a6e12f1a2a0ddbfe3
 * EXTENT MEASURED, NOT RECONSTRUCTED: 31 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80049a84..0x80049b93, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80049b18  c4a20000  op&0x31 $v0,$a1,0x0000
 * 0x80049b1c  c48a0000  op&0x31 $t2,$a0,0x0000
 * 0x80049b20  460a1282  op&0x11 $t2,$s0,0x1282
 * 0x80049b24  c4880004  op&0x31 $t0,$a0,0x0004
 * 0x80049b28  46081202  op&0x11 $t0,$s0,0x1202
 * 0x80049b2c  c4800008  op&0x31 $zero,$a0,0x0008
 * 0x80049b30  46001082  op&0x11 $zero,$s0,0x1082
 * 0x80049b34  c4ae0004  op&0x31 $t6,$a1,0x0004
 * 0x80049b38  c492000c  op&0x31 $s2,$a0,0x000c
 * 0x80049b3c  46127482  op&0x11 $s2,$s0,0x7482
 * 0x80049b40  c4900010  op&0x31 $s0,$a0,0x0010
 * 0x80049b44  46107402  op&0x11 $s0,$s0,0x7402
 * 0x80049b48  c4a40008  op&0x31 $a0,$a1,0x0008
 * 0x80049b4c  c48c0018  op&0x31 $t4,$a0,0x0018
 * 0x80049b50  460c2302  op&0x11 $t4,$s0,0x2302
 * 0x80049b54  c486001c  op&0x31 $a2,$a0,0x001c
 * 0x80049b58  46062182  op&0x11 $a2,$s0,0x2182
 * 0x80049b5c  c4800014  op&0x31 $zero,$a0,0x0014
 * 0x80049b60  46007382  op&0x11 $zero,$s0,0x7382
 * 0x80049b64  c4800020  op&0x31 $zero,$a0,0x0020
 * 0x80049b68  46002102  op&0x11 $zero,$s0,0x2102
 * 0x80049b6c  46125280  op&0x11 $s2,$s0,0x5280
 * 0x80049b70  46104200  op&0x11 $s0,$s0,0x4200
 * 0x80049b74  460e1080  op&0x11 $t6,$s0,0x1080
 * 0x80049b78  460c5280  op&0x11 $t4,$s0,0x5280
 * 0x80049b7c  46064200  op&0x11 $a2,$s0,0x4200
 * 0x80049b80  46041080  op&0x11 $a0,$s0,0x1080
 * 0x80049b84  e4aa0000  op&0x39 $t2,$a1,0x0000
 * 0x80049b88  e4a80004  op&0x39 $t0,$a1,0x0004
 * 0x80049b8c  03e00008  jr $ra
 * 0x80049b90  e4a20008  op&0x39 $v0,$a1,0x0008
 */
