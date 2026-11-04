/* FUN_8004276c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004276c  body 0x8004276c..0x80042823  size 184 B
 * EXTENT MEASURED 3 -> 46 words: no trailing `jr ra` and 96 callers: a truncated extent, not a stub (M320; leaf_screen.py --called, compile_probe.truncated_extents). Hand-written 64-bit DSP assembly, so there is no C to reconstruct
 *   the body below is still the provider's truncated head -- this rung is the extent, not a reconstruction (fixtures/decomp/measured_extents.json)
 * body sha256 314075ef19b0ac1061cf773a92879f5fb7a82627bc6c8b26469524e686234985
 * provider record sha256 2f4387f7fad4577beddda0c883502df1d74e6bb5e2177c43c4bcfd2db0966656
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */

void FUN_8004276c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
