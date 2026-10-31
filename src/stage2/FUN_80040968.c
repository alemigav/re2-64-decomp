/* FUN_80040968
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040968  body 0x80040968..0x80040a13  size 175 B
 * sha256  7a38ebe76868ebf3f185af81311104aff48f2e39ac47432771379146c8a0a7f6
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
