/* FUN_8006b28c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b28c  body 0x8006b28c..0x8006b2cb  size 64 B
 * body sha256 ae82437f6863a54127b183aa31c476ff8d403bf3983b7dc2704691bffe49c3fd
 * EXTENT MEASURED, NOT RECONSTRUCTED: 16 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x8006b28c  3c030001  lui $v1,0x0001
 * 0x8006b290  346399b8  ori $v1,$v1,0x99b8
 * 0x8006b294  3c02800c  lui $v0,0x800c
 * 0x8006b298  244276b0  addiu $v0,$v0,0x76b0
 * 0x8006b29c  00433821  addu $a3,$v0,$v1
 * 0x8006b2a0  3c030001  lui $v1,0x0001
 * 0x8006b2a4  34638000  ori $v1,$v1,0x8000
 * 0x8006b2a8  00431021  addu $v0,$v0,$v1
 * 0x8006b2ac  ace00000  sw $zero,0($a3)
 * 0x8006b2b0  8c42027c  lw $v0,636($v0)
 * 0x8006b2b4  8c430020  lw $v1,32($v0)
 * 0x8006b2b8  8c620004  lw $v0,4($v1)
 * 0x8006b2bc  00004021  addu $t0,$zero,$zero
 * 0x8006b2c0  00021100  sll $v0,$v0,4
 * 0x8006b2c4  0801acc4  j 0x8006b310
 * 0x8006b2c8  00624821  addu $t1,$v1,$v0
 */
