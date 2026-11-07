/* FUN_8000cd40
 * image   boot (boot), base 0x80000480
 * address 0x8000cd40  body 0x8000cd40..0x8000cddf  size 160 B
 * body sha256 8472f668fedc18cb2e1674809bd6562d48496ddcbdeb8cacae5ef474beb5e860
 * EXTENT MEASURED, NOT RECONSTRUCTED: 40 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8000cd40..0x8000cddf, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8000cd40  400c6000  cop0 rs=0 rt=$t4 rd=12
 * 0x8000cd44  3182ff01  andi $v0,$t4,0xff01
 * 0x8000cd48  3c088001  lui $t0,0x8001
 * 0x8000cd4c  250828d0  addiu $t0,$t0,0x28d0
 * 0x8000cd50  8d0b0000  lw $t3,0($t0)
 * 0x8000cd54  2401ffff  addiu $at,$zero,0xffff
 * 0x8000cd58  01614026  xor $t0,$t3,$at
 * 0x8000cd5c  3108ff00  andi $t0,$t0,0xff00
 * 0x8000cd60  00481025  or $v0,$v0,$t0
 * 0x8000cd64  3c0aa430  lui $t2,0xa430
 * 0x8000cd68  8d4a000c  lw $t2,12($t2)
 * 0x8000cd6c  11400005  beq $t2,$zero,+5
 * 0x8000cd70  000b4c02  srl $t1,$t3,16
 * 0x8000cd74  2401ffff  addiu $at,$zero,0xffff
 * 0x8000cd78  01214826  xor $t1,$t1,$at
 * 0x8000cd7c  3129003f  andi $t1,$t1,0x003f
 * 0x8000cd80  01495025  or $t2,$t2,$t1
 * 0x8000cd84  000a5400  sll $t2,$t2,16
 * 0x8000cd88  004a1025  or $v0,$v0,$t2
 * 0x8000cd8c  3c01003f  lui $at,0x003f
 * 0x8000cd90  00814024  and $t0,$a0,$at
 * 0x8000cd94  010b4024  and $t0,$t0,$t3
 * 0x8000cd98  000843c2  srl $t0,$t0,15
 * 0x8000cd9c  3c0a8001  lui $t2,0x8001
 * 0x8000cda0  01485021  addu $t2,$t2,$t0
 * 0x8000cda4  954a1bc0  lhu $t2,7104($t2)
 * 0x8000cda8  3c01a430  lui $at,0xa430
 * 0x8000cdac  ac2a000c  sw $t2,12($at)
 * 0x8000cdb0  3088ff01  andi $t0,$a0,0xff01
 * 0x8000cdb4  3169ff00  andi $t1,$t3,0xff00
 * 0x8000cdb8  01094024  and $t0,$t0,$t1
 * 0x8000cdbc  3c01ffff  lui $at,0xffff
 * 0x8000cdc0  342100ff  ori $at,$at,0x00ff
 * 0x8000cdc4  01816024  and $t4,$t4,$at
 * 0x8000cdc8  01886025  or $t4,$t4,$t0
 * 0x8000cdcc  408c6000  cop0 rs=4 rt=$t4 rd=12
 * 0x8000cdd0  00000000  sll $zero,$zero,0
 * 0x8000cdd4  00000000  sll $zero,$zero,0
 * 0x8000cdd8  03e00008  jr $ra
 * 0x8000cddc  00000000  sll $zero,$zero,0
 */
