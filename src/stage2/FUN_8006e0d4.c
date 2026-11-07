/* FUN_8006e0d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e0d4  body 0x8006e0d4..0x8006e137  size 100 B
 * body sha256 0127adbd4bf6a512760bc01ad9a864dc3aad3d5096dff762275dd61f7bef3c19
 * EXTENT MEASURED, NOT RECONSTRUCTED: 25 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006e09c..0x8006e137, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006e0d4  80870002  lb $a3,2($a0)
 * 0x8006e0d8  8c85001c  lw $a1,28($a0)
 * 0x8006e0dc  00874021  addu $t0,$a0,$a3
 * 0x8006e0e0  00071900  sll $v1,$a3,4
 * 0x8006e0e4  91060008  lbu $a2,8($t0)
 * 0x8006e0e8  00073880  sll $a3,$a3,2
 * 0x8006e0ec  24c60001  addiu $a2,$a2,0x0001
 * 0x8006e0f0  a1060008  sb $a2,8($t0)
 * 0x8006e0f4  84a90002  lh $t1,2($a1)
 * 0x8006e0f8  24a50004  addiu $a1,$a1,0x0004
 * 0x8006e0fc  00063600  sll $a2,$a2,24
 * 0x8006e100  00063603  sra $a2,$a2,24
 * 0x8006e104  00061080  sll $v0,$a2,2
 * 0x8006e108  00431021  addu $v0,$v0,$v1
 * 0x8006e10c  00821021  addu $v0,$a0,$v0
 * 0x8006e110  00c73021  addu $a2,$a2,$a3
 * 0x8006e114  ac85001c  sw $a1,28($a0)
 * 0x8006e118  ac450020  sw $a1,32($v0)
 * 0x8006e11c  00a92821  addu $a1,$a1,$t1
 * 0x8006e120  ac450060  sw $a1,96($v0)
 * 0x8006e124  91020004  lbu $v0,4($t0)
 * 0x8006e128  00862021  addu $a0,$a0,$a2
 * 0x8006e12c  a082000c  sb $v0,12($a0)
 * 0x8006e130  03e00008  jr $ra
 * 0x8006e134  24020001  addiu $v0,$zero,0x0001
 */
