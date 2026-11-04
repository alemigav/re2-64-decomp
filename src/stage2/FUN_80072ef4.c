/* FUN_80072ef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072ef4  body 0x80072ef4..0x80072f63  size 112 B
 * body sha256 6c13e46f54df61d8a66f10ad0be6b1881892da5c3a405b61edc7e14a93269e9f
 * EXTENT MEASURED, NOT RECONSTRUCTED: 28 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a byte-map region no artifact names (M339); no C and no provider record exists)
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
 * 0x80072ef4  3c020001  lui $v0,0x0001
 * 0x80072ef8  34428000  ori $v0,$v0,0x8000
 * 0x80072efc  3c03800c  lui $v1,0x800c
 * 0x80072f00  246376b0  addiu $v1,$v1,0x76b0
 * 0x80072f04  00621821  addu $v1,$v1,$v0
 * 0x80072f08  8c85001c  lw $a1,28($a0)
 * 0x80072f0c  8c63027c  lw $v1,636($v1)
 * 0x80072f10  90a60001  lbu $a2,1($a1)
 * 0x80072f14  8c63002c  lw $v1,44($v1)
 * 0x80072f18  00061080  sll $v0,$a2,2
 * 0x80072f1c  00461021  addu $v0,$v0,$a2
 * 0x80072f20  000210c0  sll $v0,$v0,3
 * 0x80072f24  90a60002  lbu $a2,2($a1)
 * 0x80072f28  00621821  addu $v1,$v1,$v0
 * 0x80072f2c  00061040  sll $v0,$a2,1
 * 0x80072f30  00461021  addu $v0,$v0,$a2
 * 0x80072f34  24420004  addiu $v0,$v0,0x0004
 * 0x80072f38  90a60003  lbu $a2,3($a1)
 * 0x80072f3c  00621821  addu $v1,$v1,$v0
 * 0x80072f40  a0660000  sb $a2,0($v1)
 * 0x80072f44  90a20004  lbu $v0,4($a1)
 * 0x80072f48  a0620001  sb $v0,1($v1)
 * 0x80072f4c  90a20005  lbu $v0,5($a1)
 * 0x80072f50  24a50006  addiu $a1,$a1,0x0006
 * 0x80072f54  a0620002  sb $v0,2($v1)
 * 0x80072f58  24020001  addiu $v0,$zero,0x0001
 * 0x80072f5c  03e00008  jr $ra
 * 0x80072f60  ac85001c  sw $a1,28($a0)
 */
