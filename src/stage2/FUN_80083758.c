/* FUN_80083758
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083758  body 0x80083758..0x8008377f  size 43 B
 * sha256  2f646d57037a13d18f509b4ca84eb4de34ebcc53d41cede0f821b2e051752c8a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083758(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 | 0x80000000U >> (param_2 & 0x1f);
  return;
}
