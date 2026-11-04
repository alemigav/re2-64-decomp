/* FUN_800421b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800421b4  body 0x800421b4..0x8004226b  size 184 B
 * EXTENT MEASURED 3 -> 46 words: no trailing `jr ra` and 3 callers; the third 46-word member of the DSP family (M320)
 *   the body below is still the provider's truncated head -- this rung is the extent, not a reconstruction (fixtures/decomp/measured_extents.json)
 * body sha256 cc065b94488e7ffcf532faef498af5976ee133ea8431445022e756e2a937b01d
 * provider record sha256 64f2160afaeb830b959b26d2806e88a9e86552f1de02623e74630e0dfb9a718a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void FUN_800421b4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
