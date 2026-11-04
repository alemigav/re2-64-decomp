/* FUN_80000dd4
 * image   boot (boot), base 0x80000480
 * address 0x80000dd4  body 0x80000dd4..0x80000f4f  size 380 B
 * EXTENT MEASURED 5 -> 95 words: no trailing `jr ra` and 7 callers: 95 words, the largest truncated body in the corpus (M320) -- and its 95-word body CONTAINS the separately published function at 0x80000f08 (18 words, three direct `jal` callers): the last 18 words are a shared tail reachable from both entry points, so the two extents overlap and are reported rather than absorbed. Absorbing would delete a function that is called directly
 *   the body below is still the provider's truncated head -- this rung is the extent, not a reconstruction (fixtures/decomp/measured_extents.json)
 * body sha256 8c62e6d827e597bfa7fa68519f9f4a486b3708ecd422c84365244ee8c52d525a
 * provider record sha256 202999f89f2f166073123e3198a7f099ea76273b74f6be310913ed8ca5da3066
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80000dd4(void)

{
  *(uint *)(_DAT_80012950 + 0x118) = Status | 2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
