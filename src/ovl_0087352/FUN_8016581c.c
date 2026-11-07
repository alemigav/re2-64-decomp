/* FUN_8016581c
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x8016581c  body 0x8016581c..0x8016584f  size 52 B
 * body sha256 e993d75463711c8bc2ad5435132acdff6665e6040c1ded34fa708d7399bf0df5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 13 words, found by the extent scan inside a byte-map region no artifact names (extent measured, text withdrawn (M369): this function was reconstructed from an unlicensed third-party corpus and the reconstruction has been removed; the address, extent and word count stand, the C does not)
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
 * 0x8016581c  90820006  lbu $v0,6($a0)
 * 0x80165820  14400009  bne $v0,$zero,+9
 * 0x80165824  24020080  addiu $v0,$zero,0x0080
 * 0x80165828  a082026f  sb $v0,623($a0)
 * 0x8016582c  8c820000  lw $v0,0($a0)
 * 0x80165830  8c830208  lw $v1,520($a0)
 * 0x80165834  34420002  ori $v0,$v0,0x0002
 * 0x80165838  ac820000  sw $v0,0($a0)
 * 0x8016583c  24020001  addiu $v0,$zero,0x0001
 * 0x80165840  a060000e  sb $zero,14($v1)
 * 0x80165844  a0820006  sb $v0,6($a0)
 * 0x80165848  03e00008  jr $ra
 * 0x8016584c  00000000  sll $zero,$zero,0
 */
