/* FUN_8006edb0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006edb0  body 0x8006edb0..0x8006ee23  size 116 B
 * body sha256 ba6f3e0e1388f229ce4680895a5952dae340143179fa2064cc11d75a0db47d0e
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
 * 0x8006edb0  3c030001  lui $v1,0x0001
 * 0x8006edb4  34638000  ori $v1,$v1,0x8000
 * 0x8006edb8  3c02800c  lui $v0,0x800c
 * 0x8006edbc  244276b0  addiu $v0,$v0,0x76b0
 * 0x8006edc0  00431021  addu $v0,$v0,$v1
 * 0x8006edc4  8c42027c  lw $v0,636($v0)
 * 0x8006edc8  8c83001c  lw $v1,28($a0)
 * 0x8006edcc  8c450028  lw $a1,40($v0)
 * 0x8006edd0  90660001  lbu $a2,1($v1)
 * 0x8006edd4  90a20002  lbu $v0,2($a1)
 * 0x8006edd8  10460006  beq $v0,$a2,+6
 * 0x8006eddc  00000000  sll $zero,$zero,0
 * 0x8006ede0  24a50014  addiu $a1,$a1,0x0014
 * 0x8006ede4  90a20002  lbu $v0,2($a1)
 * 0x8006ede8  5446fffe  op&0x15 $a2,$v0,0xfffe
 * 0x8006edec  24a50014  addiu $a1,$a1,0x0014
 * 0x8006edf0  8c83001c  lw $v1,28($a0)
 * 0x8006edf4  90660002  lbu $a2,2($v1)
 * 0x8006edf8  90630003  lbu $v1,3($v1)
 * 0x8006edfc  00061080  sll $v0,$a2,2
 * 0x8006ee00  00461021  addu $v0,$v0,$a2
 * 0x8006ee04  00021080  sll $v0,$v0,2
 * 0x8006ee08  00a22821  addu $a1,$a1,$v0
 * 0x8006ee0c  a0a30000  sb $v1,0($a1)
 * 0x8006ee10  8c82001c  lw $v0,28($a0)
 * 0x8006ee14  24420004  addiu $v0,$v0,0x0004
 * 0x8006ee18  ac82001c  sw $v0,28($a0)
 * 0x8006ee1c  03e00008  jr $ra
 * 0x8006ee20  24020001  addiu $v0,$zero,0x0001
 */
