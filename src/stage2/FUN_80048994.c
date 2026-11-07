/* FUN_80048994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80048994  body 0x80048994..0x80048a3f  size 172 B
 * body sha256 12c1afb6a0037da23c59559028c29fcb7bd609e8d4c00bfff838a06e5b51d60b
 * EXTENT MEASURED, NOT RECONSTRUCTED: 43 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80048994  c4aa0000  op&0x31 $t2,$a1,0x0000
 * 0x80048998  c4a80024  op&0x31 $t0,$a1,0x0024
 * 0x8004899c  c4a40028  op&0x31 $a0,$a1,0x0028
 * 0x800489a0  c4a6002c  op&0x31 $a2,$a1,0x002c
 * 0x800489a4  46085302  op&0x11 $t0,$s0,0x5302
 * 0x800489a8  e48a0000  op&0x39 $t2,$a0,0x0000
 * 0x800489ac  c4aa0004  op&0x31 $t2,$a1,0x0004
 * 0x800489b0  46045082  op&0x11 $a0,$s0,0x5082
 * 0x800489b4  e48a000c  op&0x39 $t2,$a0,0x000c
 * 0x800489b8  c4aa0008  op&0x31 $t2,$a1,0x0008
 * 0x800489bc  46065002  op&0x11 $a2,$s0,0x5002
 * 0x800489c0  46026300  op&0x11 $v0,$s0,0x6300
 * 0x800489c4  46006300  op&0x11 $zero,$s0,0x6300
 * 0x800489c8  e48a0018  op&0x39 $t2,$a0,0x0018
 * 0x800489cc  46006007  op&0x11 $zero,$s0,0x6007
 * 0x800489d0  e4800024  op&0x39 $zero,$a0,0x0024
 * 0x800489d4  c4aa000c  op&0x31 $t2,$a1,0x000c
 * 0x800489d8  46085302  op&0x11 $t0,$s0,0x5302
 * 0x800489dc  e48a0004  op&0x39 $t2,$a0,0x0004
 * 0x800489e0  c4aa0010  op&0x31 $t2,$a1,0x0010
 * 0x800489e4  46045082  op&0x11 $a0,$s0,0x5082
 * 0x800489e8  e48a0010  op&0x39 $t2,$a0,0x0010
 * 0x800489ec  c4aa0014  op&0x31 $t2,$a1,0x0014
 * 0x800489f0  46065002  op&0x11 $a2,$s0,0x5002
 * 0x800489f4  46026300  op&0x11 $v0,$s0,0x6300
 * 0x800489f8  46006300  op&0x11 $zero,$s0,0x6300
 * 0x800489fc  e48a001c  op&0x39 $t2,$a0,0x001c
 * 0x80048a00  46006007  op&0x11 $zero,$s0,0x6007
 * 0x80048a04  e4800028  op&0x39 $zero,$a0,0x0028
 * 0x80048a08  c4aa0018  op&0x31 $t2,$a1,0x0018
 * 0x80048a0c  46085302  op&0x11 $t0,$s0,0x5302
 * 0x80048a10  e48a0008  op&0x39 $t2,$a0,0x0008
 * 0x80048a14  c4aa001c  op&0x31 $t2,$a1,0x001c
 * 0x80048a18  46045102  op&0x11 $a0,$s0,0x5102
 * 0x80048a1c  e48a0014  op&0x39 $t2,$a0,0x0014
 * 0x80048a20  c4aa0020  op&0x31 $t2,$a1,0x0020
 * 0x80048a24  46065182  op&0x11 $a2,$s0,0x5182
 * 0x80048a28  46046300  op&0x11 $a0,$s0,0x6300
 * 0x80048a2c  46066300  op&0x11 $a2,$s0,0x6300
 * 0x80048a30  e48a0020  op&0x39 $t2,$a0,0x0020
 * 0x80048a34  46006007  op&0x11 $zero,$s0,0x6007
 * 0x80048a38  03e00008  jr $ra
 * 0x80048a3c  e480002c  op&0x39 $zero,$a0,0x002c
 */
