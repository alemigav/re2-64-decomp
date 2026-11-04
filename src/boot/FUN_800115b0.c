/* FUN_800115b0
 * image   boot (boot), base 0x80000480
 * address 0x800115b0  body 0x800115b0..0x800115c3  size 20 B
 * EXTENT MEASURED 3 -> 5 words: no trailing `jr ra`; 5 words, measurable only after the boot extent was corrected to 0x13420 (M324). It reads AI_STATUS and returns its sign bit, and its one-word residue is a `slti`/`srl` idiom
 *   the body below is still the provider's truncated head -- this rung is the extent, not a reconstruction (fixtures/decomp/measured_extents.json)
 * body sha256 11b52ed8375ab330c46960b9d8651740c8927e96cb31508eb4340be70bdc7db6
 * provider record sha256 35a5b7963f3754bb7c1c79ed35f38024cd2b3d15a93f1af2e70ab023a3008d5c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800115b0(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
