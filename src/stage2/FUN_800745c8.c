/* FUN_800745c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800745c8  body 0x800745c8..0x8007460f  size 72 B
 * body sha256 8ed539b563fd0fe0b6a212a628ddf56a919aa820466aaaa3b7e38ff6fcc38225
 * EXTENT MEASURED, NOT RECONSTRUCTED: 18 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x800745c8..0x8007460f, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800745c8  3c030001  lui $v1,0x0001
 * 0x800745cc  34638000  ori $v1,$v1,0x8000
 * 0x800745d0  3c028013  lui $v0,0x8013
 * 0x800745d4  3c048013  lui $a0,0x8013
 * 0x800745d8  a040bfa8  sb $zero,-16472($v0)
 * 0x800745dc  24020001  addiu $v0,$zero,0x0001
 * 0x800745e0  a0821780  sb $v0,6016($a0)
 * 0x800745e4  3c02800c  lui $v0,0x800c
 * 0x800745e8  244276b0  addiu $v0,$v0,0x76b0
 * 0x800745ec  00431021  addu $v0,$v0,$v1
 * 0x800745f0  24841780  addiu $a0,$a0,0x1780
 * 0x800745f4  8c431a5c  lw $v1,6748($v0)
 * 0x800745f8  8c451a60  lw $a1,6752($v0)
 * 0x800745fc  34638000  ori $v1,$v1,0x8000
 * 0x80074600  ac850044  sw $a1,68($a0)
 * 0x80074604  ac431a5c  sw $v1,6748($v0)
 * 0x80074608  03e00008  jr $ra
 * 0x8007460c  00001021  addu $v0,$zero,$zero
 */
