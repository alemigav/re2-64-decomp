/* FUN_800ab330
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab330  body 0x800ab330..0x800ab3cb  size 159 B
 * sha256  150121589380dd29eb58163d1d8319c4a6bb3db78eb03375cc6e4ad408e9bf63
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
