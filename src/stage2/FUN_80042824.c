/* FUN_80042824
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042824  body 0x80042824..0x800428db  size 184 B
 * EXTENT MEASURED 3 -> 46 words: no trailing `jr ra` and 20 callers; the `sw` member of the same 46-word DSP family (M320)
 *   the body below is still the provider's truncated head -- this rung is the extent, not a reconstruction (fixtures/decomp/measured_extents.json)
 * body sha256 477c67a9a1b09914d436f8186412c5106794f22cac04535a15868db2f22e8436
 * provider record sha256 dfea4d88ed6105b2659f02e0c39a11c25a7d68931dc14acd76e5376c5f1146d7
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void FUN_80042824(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
