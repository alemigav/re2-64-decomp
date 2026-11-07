/* FUN_8001f480
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8001f480  body 0x8001f480..0x8001f493  size 20 B
 * body sha256 33787db1ddcd3c34f59f1a9d785f50a3fd144424a15c38f73a0144d5e656b449
 * EXTENT MEASURED, NOT RECONSTRUCTED: 5 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8001f480  00191402  srl $v0,$t9,16
 * 0x8001f484  944127fe  lhu $at,10238($v0)
 * 0x8001f488  00390820  add $at,$at,$t9
 * 0x8001f48c  08000463  j 0x8000118c
 * 0x8001f490  ac380000  sw $t8,0($at)
 */
