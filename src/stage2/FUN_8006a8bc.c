/* FUN_8006a8bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a8bc  body 0x8006a8bc..0x8006a8cb  size 16 B
 * body sha256 7b3323544c39799d43e5ff23697d0ff9757503f671c05621da1834d90432049a
 * EXTENT MEASURED, NOT RECONSTRUCTED: 4 words, found by the extent scan inside a byte-map region no artifact names (extent measured by walking to the first `jr ra` inside a `enclosed_data` run that no provider range covers; the run is 0x8006a880..0x8006a8f3, the segment starts with a non-branch word and is at least four words, and no C exists for it (M362))
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
 * 0x8006a8bc  84a30000  lh $v1,0($a1)
 * 0x8006a8c0  94a20004  lhu $v0,4($a1)
 * 0x8006a8c4  03e00008  jr $ra
 * 0x8006a8c8  00621021  addu $v0,$v1,$v0
 */
