/* FUN_800a5d10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5d10  body 0x800a5d10..0x800a5d8f  size 131 B
 * body sha256 a3ccb30ca46e1ac1353870b1637a9783fe12a9247bcabf88cdfbe6f02dcb858a
 * provider record sha256 7060c1266011af3fa63e246a721fd77458c3cb46739fdf3502eb70c3bbf9ec47
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800a5d10(int param_1)

{
  float fVar1;
  
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar1 = (fVar1 * 4096.0) / (float)_DAT_80147fa4;
  if (2.1474836e+09 <= fVar1) {
    return (int)(fVar1 - 2.1474836e+09) | 0x80000000;
  }
  return (int)fVar1;
}
