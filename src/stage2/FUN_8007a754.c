/* FUN_8007a754
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a754  body 0x8007a754..0x8007a7e3  size 144 B
 * body sha256 11315efdc6abe8b14424af9b7bca2a50cd6a16cb068cbebfca9976907a3e26d7
 * EXTENT MEASURED, NOT RECONSTRUCTED: 36 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8007a74c..0x8007a7e3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8007a754  3c020001  lui $v0,0x0001
 * 0x8007a758  34428000  ori $v0,$v0,0x8000
 * 0x8007a75c  3c03800c  lui $v1,0x800c
 * 0x8007a760  246376b0  addiu $v1,$v1,0x76b0
 * 0x8007a764  00621821  addu $v1,$v1,$v0
 * 0x8007a768  3c028008  lui $v0,0x8008
 * 0x8007a76c  24429470  addiu $v0,$v0,0x9470
 * 0x8007a770  ac621e80  sw $v0,7808($v1)
 * 0x8007a774  ac621e84  sw $v0,7812($v1)
 * 0x8007a778  ac621e88  sw $v0,7816($v1)
 * 0x8007a77c  ac621e8c  sw $v0,7820($v1)
 * 0x8007a780  ac621e90  sw $v0,7824($v1)
 * 0x8007a784  ac621e94  sw $v0,7828($v1)
 * 0x8007a788  ac621e98  sw $v0,7832($v1)
 * 0x8007a78c  ac621e9c  sw $v0,7836($v1)
 * 0x8007a790  ac621ea0  sw $v0,7840($v1)
 * 0x8007a794  ac621ea4  sw $v0,7844($v1)
 * 0x8007a798  ac621ea8  sw $v0,7848($v1)
 * 0x8007a79c  ac621eac  sw $v0,7852($v1)
 * 0x8007a7a0  ac621eb0  sw $v0,7856($v1)
 * 0x8007a7a4  ac621eb4  sw $v0,7860($v1)
 * 0x8007a7a8  ac621eb8  sw $v0,7864($v1)
 * 0x8007a7ac  ac621ebc  sw $v0,7868($v1)
 * 0x8007a7b0  ac621ec0  sw $v0,7872($v1)
 * 0x8007a7b4  ac621ec4  sw $v0,7876($v1)
 * 0x8007a7b8  ac621ec8  sw $v0,7880($v1)
 * 0x8007a7bc  ac621ecc  sw $v0,7884($v1)
 * 0x8007a7c0  ac621ed0  sw $v0,7888($v1)
 * 0x8007a7c4  ac621ed4  sw $v0,7892($v1)
 * 0x8007a7c8  ac621ed8  sw $v0,7896($v1)
 * 0x8007a7cc  ac621edc  sw $v0,7900($v1)
 * 0x8007a7d0  ac621ee0  sw $v0,7904($v1)
 * 0x8007a7d4  ac621ee4  sw $v0,7908($v1)
 * 0x8007a7d8  ac621ee8  sw $v0,7912($v1)
 * 0x8007a7dc  03e00008  jr $ra
 * 0x8007a7e0  ac621eec  sw $v0,7916($v1)
 */
