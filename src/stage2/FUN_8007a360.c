/* FUN_8007a360
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a360  body 0x8007a360..0x8007a3d7  size 120 B
 * body sha256 27d475317e9369c64c172cdd6d4ebecda26533086f114d0b8bf3c4cb16b81f52
 * EXTENT MEASURED, NOT RECONSTRUCTED: 30 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x8007a360  8c820234  lw $v0,564($a0)
 * 0x8007a364  ac401608  sw $zero,5640($v0)
 * 0x8007a368  948201aa  lhu $v0,426($a0)
 * 0x8007a36c  30420800  andi $v0,$v0,0x0800
 * 0x8007a370  10400017  beq $v0,$zero,+23
 * 0x8007a374  00000000  sll $zero,$zero,0
 * 0x8007a378  8c850234  lw $a1,564($a0)
 * 0x8007a37c  24a41608  addiu $a0,$a1,0x1608
 * 0x8007a380  8c8200a8  lw $v0,168($a0)
 * 0x8007a384  24a31028  addiu $v1,$a1,0x1028
 * 0x8007a388  ac6200a8  sw $v0,168($v1)
 * 0x8007a38c  8c8200ac  lw $v0,172($a0)
 * 0x8007a390  ac6200ac  sw $v0,172($v1)
 * 0x8007a394  8c8200b0  lw $v0,176($a0)
 * 0x8007a398  ac6200b0  sw $v0,176($v1)
 * 0x8007a39c  8c8200b4  lw $v0,180($a0)
 * 0x8007a3a0  ac6200b4  sw $v0,180($v1)
 * 0x8007a3a4  948200c4  lhu $v0,196($a0)
 * 0x8007a3a8  a46200c4  sh $v0,196($v1)
 * 0x8007a3ac  948200c6  lhu $v0,198($a0)
 * 0x8007a3b0  a46200c6  sh $v0,198($v1)
 * 0x8007a3b4  8c8200cc  lw $v0,204($a0)
 * 0x8007a3b8  ac6200cc  sw $v0,204($v1)
 * 0x8007a3bc  8c8200c8  lw $v0,200($a0)
 * 0x8007a3c0  ac6200c8  sw $v0,200($v1)
 * 0x8007a3c4  24020001  addiu $v0,$zero,0x0001
 * 0x8007a3c8  aca01608  sw $zero,5640($a1)
 * 0x8007a3cc  aca21028  sw $v0,4136($a1)
 * 0x8007a3d0  03e00008  jr $ra
 * 0x8007a3d4  00000000  sll $zero,$zero,0
 */
