/* FUN_80083758
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083758  body 0x80083758..0x8008377f  size 43 B
 * body sha256 5a235af125ea5816247be08fd0e78d7cba831f166dd3b22f4e8e39bed190fa9f
 * provider record sha256 4896e4202eda4f61e49dc626c1909f1429f49e3781b6c8ee6e95116904e2e1cc
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
