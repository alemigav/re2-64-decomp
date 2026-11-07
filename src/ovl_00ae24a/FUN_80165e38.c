/* FUN_80165e38
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165e38  body 0x80165e38..0x80165edb  size 164 B
 * body sha256 90deb7a56c68089aeb52f760aeaaa4708830538f043e3ff1d27c6a63e3eb5fa9
 * EXTENT MEASURED, NOT RECONSTRUCTED: 41 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra`, then corrected (M365): split at every tail `j` and extended while a branch left the body, so the entry is self-contained -- no branch or jump leaves it, it opens no frame it does not save, and it overlaps no provider range)
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
 * 0x80165e38  24020001  addiu $v0,$zero,0x0001
 * 0x80165e3c  a0c202b5  sb $v0,693($a2)
 * 0x80165e40  24020024  addiu $v0,$zero,0x0024
 * 0x80165e44  a4c202b8  sh $v0,696($a2)
 * 0x80165e48  2402000a  addiu $v0,$zero,0x000a
 * 0x80165e4c  a0c202b7  sb $v0,695($a2)
 * 0x80165e50  a0c202bc  sb $v0,700($a2)
 * 0x80165e54  24020001  addiu $v0,$zero,0x0001
 * 0x80165e58  a4c202ba  sh $v0,698($a2)
 * 0x80165e5c  8ca40120  lw $a0,288($a1)
 * 0x80165e60  94c302b8  lhu $v1,696($a2)
 * 0x80165e64  94820010  lhu $v0,16($a0)
 * 0x80165e68  00431021  addu $v0,$v0,$v1
 * 0x80165e6c  a4820010  sh $v0,16($a0)
 * 0x80165e70  84c402ba  lh $a0,698($a2)
 * 0x80165e74  94c302b8  lhu $v1,696($a2)
 * 0x80165e78  90c202b7  lbu $v0,695($a2)
 * 0x80165e7c  00042080  sll $a0,$a0,2
 * 0x80165e80  00641823  subu $v1,$v1,$a0
 * 0x80165e84  2442ffff  addiu $v0,$v0,0xffff
 * 0x80165e88  a0c202b7  sb $v0,695($a2)
 * 0x80165e8c  00021600  sll $v0,$v0,24
 * 0x80165e90  00021603  sra $v0,$v0,24
 * 0x80165e94  a4c302b8  sh $v1,696($a2)
 * 0x80165e98  2403ffff  addiu $v1,$zero,0xffff
 * 0x80165e9c  1443000d  bne $v0,$v1,+13
 * 0x80165ea0  00000000  sll $zero,$zero,0
 * 0x80165ea4  90c302bc  lbu $v1,700($a2)
 * 0x80165ea8  00601021  addu $v0,$v1,$zero
 * 0x80165eac  2442ffff  addiu $v0,$v0,0xffff
 * 0x80165eb0  a0c202bc  sb $v0,700($a2)
 * 0x80165eb4  84c202ba  lh $v0,698($a2)
 * 0x80165eb8  a0c302b7  sb $v1,695($a2)
 * 0x80165ebc  80c302b7  lb $v1,695($a2)
 * 0x80165ec0  00021023  subu $v0,$zero,$v0
 * 0x80165ec4  1460ffda  bne $v1,$zero,-38
 * 0x80165ec8  a4c202ba  sh $v0,698($a2)
 * 0x80165ecc  a0c002b4  sb $zero,692($a2)
 * 0x80165ed0  a0c002b5  sb $zero,693($a2)
 * 0x80165ed4  03e00008  jr $ra
 * 0x80165ed8  00000000  sll $zero,$zero,0
 */
