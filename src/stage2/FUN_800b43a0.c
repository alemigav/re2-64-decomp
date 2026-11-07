/* FUN_800b43a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b43a0  body 0x800b43a0..0x800b43ff  size 96 B
 * body sha256 bafd107c3c55aee2b035e2c088bb62fcbde582ceb35d8c8cb2608c9083eb1a2e
 * EXTENT MEASURED, NOT RECONSTRUCTED: 24 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x800b43a0..0x800b4477, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x800b43a0  3c028013  lui $v0,0x8013
 * 0x800b43a4  90426d80  lbu $v0,28032($v0)
 * 0x800b43a8  10400021  beq $v0,$zero,+33
 * 0x800b43ac  00803021  addu $a2,$a0,$zero
 * 0x800b43b0  00002021  addu $a0,$zero,$zero
 * 0x800b43b4  3c028016  lui $v0,0x8016
 * 0x800b43b8  24458b20  addiu $a1,$v0,0x8b20
 * 0x800b43bc  90a21200  lbu $v0,4608($a1)
 * 0x800b43c0  50400005  op&0x14 $zero,$v0,0x0005
 * 0x800b43c4  24840001  addiu $a0,$a0,0x0001
 * 0x800b43c8  8ca21224  lw $v0,4644($a1)
 * 0x800b43cc  50460007  op&0x14 $a2,$v0,0x0007
 * 0x800b43d0  00803021  addu $a2,$a0,$zero
 * 0x800b43d4  24840001  addiu $a0,$a0,0x0001
 * 0x800b43d8  2c820002  op&0x0b $v0,$a0,0x0002
 * 0x800b43dc  1440fff7  bne $v0,$zero,-9
 * 0x800b43e0  24a51228  addiu $a1,$a1,0x1228
 * 0x800b43e4  2404ffff  addiu $a0,$zero,0xffff
 * 0x800b43e8  00803021  addu $a2,$a0,$zero
 * 0x800b43ec  2402ffff  addiu $v0,$zero,0xffff
 * 0x800b43f0  14c20003  bne $a2,$v0,+3
 * 0x800b43f4  3c028016  lui $v0,0x8016
 * 0x800b43f8  03e00008  jr $ra
 * 0x800b43fc  00001021  addu $v0,$zero,$zero
 */
