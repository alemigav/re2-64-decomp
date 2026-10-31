/* FUN_80040968
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040968  body 0x80040968..0x80040a13  size 175 B
 * body sha256 07779148d94056cd8758b84e4257f9586df2ebf317e23d56cc268477612cf56d
 * provider record sha256 5c33666d3d7138eaa8f747cd26770f6d144c0adce81627984a5dc5f0110e6104
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80040968(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xfff;
  if (uVar1 < 0x400) {
    return *(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
  }
  if (uVar1 < 0x800) {
    return *(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
  }
  if (uVar1 < 0xc00) {
    return -*(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
  }
  return -*(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
}
