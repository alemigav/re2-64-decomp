/* FUN_800408c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800408c0  body 0x800408c0..0x80040967  size 171 B
 * sha256  450edf571d11ceb278ddd2281345f2097c9eea38ce73025f460c3ef2d7e95047
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800408c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xfff;
  if (uVar1 < 0x400) {
    return *(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
  }
  if (uVar1 < 0x800) {
    return -*(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
  }
  if (uVar1 < 0xc00) {
    return -*(int *)(&DAT_800eec30 + (param_1 & 0x3ff) * 4);
  }
  return *(int *)(&DAT_800eec30 + (0x400 - (param_1 & 0x3ff)) * 4);
}
