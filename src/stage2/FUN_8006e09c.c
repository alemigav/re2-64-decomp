/* FUN_8006e09c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e09c  body 0x8006e09c..0x8006e0d3  size 56 B
 * body sha256 29069e85c358b513410e11800e734d47bc00c9e0c0292a9910b2f63742d6aee5
 * EXTENT MEASURED, NOT RECONSTRUCTED: 14 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006e09c..0x8006e137, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006e09c  80830002  lb $v1,2($a0)
 * 0x8006e0a0  00832821  addu $a1,$a0,$v1
 * 0x8006e0a4  80a20008  lb $v0,8($a1)
 * 0x8006e0a8  00031900  sll $v1,$v1,4
 * 0x8006e0ac  00021080  sll $v0,$v0,2
 * 0x8006e0b0  00431021  addu $v0,$v0,$v1
 * 0x8006e0b4  00821021  addu $v0,$a0,$v0
 * 0x8006e0b8  8c420020  lw $v0,32($v0)
 * 0x8006e0bc  ac82001c  sw $v0,28($a0)
 * 0x8006e0c0  90a20008  lbu $v0,8($a1)
 * 0x8006e0c4  2442ffff  addiu $v0,$v0,0xffff
 * 0x8006e0c8  a0a20008  sb $v0,8($a1)
 * 0x8006e0cc  03e00008  jr $ra
 * 0x8006e0d0  24020001  addiu $v0,$zero,0x0001
 */
