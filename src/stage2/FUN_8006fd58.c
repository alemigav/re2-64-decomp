/* FUN_8006fd58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fd58  body 0x8006fd58..0x8006fdcf  size 120 B
 * body sha256 d03171073999447148a60ee785a2ac426d98ec8960d2cb83f2910af92c98b5bf
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
 * 0x8006fd58  84830158  lh $v1,344($a0)
 * 0x8006fd5c  8c850154  lw $a1,340($a0)
 * 0x8006fd60  8486015a  lh $a2,346($a0)
 * 0x8006fd64  8ca20028  lw $v0,40($a1)
 * 0x8006fd68  8487015c  lh $a3,348($a0)
 * 0x8006fd6c  00431021  addu $v0,$v0,$v1
 * 0x8006fd70  aca20028  sw $v0,40($a1)
 * 0x8006fd74  8ca2002c  lw $v0,44($a1)
 * 0x8006fd78  8ca30030  lw $v1,48($a1)
 * 0x8006fd7c  00461021  addu $v0,$v0,$a2
 * 0x8006fd80  00671821  addu $v1,$v1,$a3
 * 0x8006fd84  aca2002c  sw $v0,44($a1)
 * 0x8006fd88  aca30030  sw $v1,48($a1)
 * 0x8006fd8c  8483015e  lh $v1,350($a0)
 * 0x8006fd90  84860160  lh $a2,352($a0)
 * 0x8006fd94  94a20064  lhu $v0,100($a1)
 * 0x8006fd98  84870162  lh $a3,354($a0)
 * 0x8006fd9c  00431021  addu $v0,$v0,$v1
 * 0x8006fda0  a4a20064  sh $v0,100($a1)
 * 0x8006fda4  94a20066  lhu $v0,102($a1)
 * 0x8006fda8  94a30068  lhu $v1,104($a1)
 * 0x8006fdac  00461021  addu $v0,$v0,$a2
 * 0x8006fdb0  00671821  addu $v1,$v1,$a3
 * 0x8006fdb4  a4a20066  sh $v0,102($a1)
 * 0x8006fdb8  a4a30068  sh $v1,104($a1)
 * 0x8006fdbc  8c82001c  lw $v0,28($a0)
 * 0x8006fdc0  24420001  addiu $v0,$v0,0x0001
 * 0x8006fdc4  ac82001c  sw $v0,28($a0)
 * 0x8006fdc8  03e00008  jr $ra
 * 0x8006fdcc  24020001  addiu $v0,$zero,0x0001
 */
