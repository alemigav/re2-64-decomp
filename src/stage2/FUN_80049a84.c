/* FUN_80049a84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049a84  body 0x80049a84..0x80049b17  size 148 B
 * body sha256 4cb34deaf0ef36aad3025d16c80f0e087411c61057a45265ca8d8e711bb85031
 * EXTENT MEASURED, NOT RECONSTRUCTED: 37 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80049a84  c4a20000  op&0x31 $v0,$a1,0x0000
 * 0x80049a88  c48a0000  op&0x31 $t2,$a0,0x0000
 * 0x80049a8c  460a1282  op&0x11 $t2,$s0,0x1282
 * 0x80049a90  c4880004  op&0x31 $t0,$a0,0x0004
 * 0x80049a94  46081202  op&0x11 $t0,$s0,0x1202
 * 0x80049a98  c4800008  op&0x31 $zero,$a0,0x0008
 * 0x80049a9c  46001082  op&0x11 $zero,$s0,0x1082
 * 0x80049aa0  c4ae0004  op&0x31 $t6,$a1,0x0004
 * 0x80049aa4  c492000c  op&0x31 $s2,$a0,0x000c
 * 0x80049aa8  46127482  op&0x11 $s2,$s0,0x7482
 * 0x80049aac  c4900010  op&0x31 $s0,$a0,0x0010
 * 0x80049ab0  46107402  op&0x11 $s0,$s0,0x7402
 * 0x80049ab4  c4a40008  op&0x31 $a0,$a1,0x0008
 * 0x80049ab8  c48c0018  op&0x31 $t4,$a0,0x0018
 * 0x80049abc  460c2302  op&0x11 $t4,$s0,0x2302
 * 0x80049ac0  c486001c  op&0x31 $a2,$a0,0x001c
 * 0x80049ac4  46062182  op&0x11 $a2,$s0,0x2182
 * 0x80049ac8  c4800014  op&0x31 $zero,$a0,0x0014
 * 0x80049acc  46007382  op&0x11 $zero,$s0,0x7382
 * 0x80049ad0  c4800020  op&0x31 $zero,$a0,0x0020
 * 0x80049ad4  46002102  op&0x11 $zero,$s0,0x2102
 * 0x80049ad8  46125280  op&0x11 $s2,$s0,0x5280
 * 0x80049adc  46104200  op&0x11 $s0,$s0,0x4200
 * 0x80049ae0  460e1080  op&0x11 $t6,$s0,0x1080
 * 0x80049ae4  460c5280  op&0x11 $t4,$s0,0x5280
 * 0x80049ae8  46064200  op&0x11 $a2,$s0,0x4200
 * 0x80049aec  46041080  op&0x11 $a0,$s0,0x1080
 * 0x80049af0  c4800024  op&0x31 $zero,$a0,0x0024
 * 0x80049af4  46005280  op&0x11 $zero,$s0,0x5280
 * 0x80049af8  c4800028  op&0x31 $zero,$a0,0x0028
 * 0x80049afc  46004200  op&0x11 $zero,$s0,0x4200
 * 0x80049b00  c480002c  op&0x31 $zero,$a0,0x002c
 * 0x80049b04  46001080  op&0x11 $zero,$s0,0x1080
 * 0x80049b08  e4aa0000  op&0x39 $t2,$a1,0x0000
 * 0x80049b0c  e4a80004  op&0x39 $t0,$a1,0x0004
 * 0x80049b10  03e00008  jr $ra
 * 0x80049b14  e4a20008  op&0x39 $v0,$a1,0x0008
 */
