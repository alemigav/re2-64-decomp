/* FUN_800ab330
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab330  body 0x800ab330..0x800ab3cb  size 159 B
 * body sha256 8f73637e0d7c187f321ed0d8b4b10d956d17b813ea355d874d02efeb0f6efd06
 * provider record sha256 3586c9d15bc5be3967dc17a4fc2a82b23d3218e33f0816036d044cea5e85e7d0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800ab330(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xfff;
  if (0x3ff < uVar1) {
    if (0x7ff < uVar1) {
      if (uVar1 < 0xc00) {
        return (int)((uint)*(ushort *)(&DAT_80136324 + (param_1 & 0x3ff) * 2) * -0x10000) >> 0x10;
      }
      return (int)((uint)*(ushort *)(&DAT_80136324 + (~param_1 & 0x3ff) * 2) * -0x10000) >> 0x10;
    }
    uVar1 = ~param_1 & 0x3ff;
  }
  return (int)*(short *)(&DAT_80136324 + uVar1 * 2);
}
