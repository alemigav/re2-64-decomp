/* FUN_8006fdd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fdd0  body 0x8006fdd0..0x8006fe43  size 116 B
 * body sha256 7850b574ab8434443c2c2d57ff58b017212a3213c92410b80e1f14d0ea73c537
 * EXTENT MEASURED, NOT RECONSTRUCTED: 29 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8006fdd0  94820158  lhu $v0,344($a0)
 * 0x8006fdd4  94830164  lhu $v1,356($a0)
 * 0x8006fdd8  94850166  lhu $a1,358($a0)
 * 0x8006fddc  94860168  lhu $a2,360($a0)
 * 0x8006fde0  00431021  addu $v0,$v0,$v1
 * 0x8006fde4  a4820158  sh $v0,344($a0)
 * 0x8006fde8  9482015a  lhu $v0,346($a0)
 * 0x8006fdec  9483015c  lhu $v1,348($a0)
 * 0x8006fdf0  00451021  addu $v0,$v0,$a1
 * 0x8006fdf4  a482015a  sh $v0,346($a0)
 * 0x8006fdf8  9482015e  lhu $v0,350($a0)
 * 0x8006fdfc  9485016a  lhu $a1,362($a0)
 * 0x8006fe00  00661821  addu $v1,$v1,$a2
 * 0x8006fe04  a483015c  sh $v1,348($a0)
 * 0x8006fe08  94830160  lhu $v1,352($a0)
 * 0x8006fe0c  9486016c  lhu $a2,364($a0)
 * 0x8006fe10  00451021  addu $v0,$v0,$a1
 * 0x8006fe14  a482015e  sh $v0,350($a0)
 * 0x8006fe18  94820162  lhu $v0,354($a0)
 * 0x8006fe1c  9485016e  lhu $a1,366($a0)
 * 0x8006fe20  00661821  addu $v1,$v1,$a2
 * 0x8006fe24  a4830160  sh $v1,352($a0)
 * 0x8006fe28  8c83001c  lw $v1,28($a0)
 * 0x8006fe2c  00451021  addu $v0,$v0,$a1
 * 0x8006fe30  24630001  addiu $v1,$v1,0x0001
 * 0x8006fe34  a4820162  sh $v0,354($a0)
 * 0x8006fe38  24020001  addiu $v0,$zero,0x0001
 * 0x8006fe3c  03e00008  jr $ra
 * 0x8006fe40  ac83001c  sw $v1,28($a0)
 */
