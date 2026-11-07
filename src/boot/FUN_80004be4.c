/* FUN_80004be4
 * image   boot (boot), base 0x80000480
 * address 0x80004be4  body 0x80004be4..0x80004c13  size 48 B
 * body sha256 67ee746d702f1fd485fc70e3ffb5cbb5bb50782853b38e9194e35cdee536a91a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 12 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x80004be4..0x80004c33, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x80004be4  3c040001  lui $a0,0x0001
 * 0x80004be8  34848000  ori $a0,$a0,0x8000
 * 0x80004bec  3c028001  lui $v0,0x8001
 * 0x80004bf0  3c03800c  lui $v1,0x800c
 * 0x80004bf4  246376b0  addiu $v1,$v1,0x76b0
 * 0x80004bf8  00641821  addu $v1,$v1,$a0
 * 0x80004bfc  ac402884  sw $zero,10372($v0)
 * 0x80004c00  8c621a5c  lw $v0,6748($v1)
 * 0x80004c04  2404ffdf  addiu $a0,$zero,0xffdf
 * 0x80004c08  00441024  and $v0,$v0,$a0
 * 0x80004c0c  03e00008  jr $ra
 * 0x80004c10  ac621a5c  sw $v0,6748($v1)
 */
