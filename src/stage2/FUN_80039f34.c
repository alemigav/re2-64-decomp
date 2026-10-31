/* FUN_80039f34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039f34  body 0x80039f34..0x80039fc3  size 147 B
 * sha256  f28cbb42aaf4c347342851ee7ae80329295d52e81ed2a8ec69849394d3e59500
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039f34(void)

{
  int local_18;
  int local_14;
  int local_10;
  
  *(char *)(DAT_800ebb94 + 0x1e) = *(char *)(DAT_800ebb94 + 0x1e) + *(char *)(DAT_800ebb94 + 3);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  if (*(char *)(DAT_800ebb94 + 0x1b) == '\0') {
    FUN_80077adc((uint)*(ushort *)(DAT_800ebb94 + 0x16) * 0x10000 + 1,&local_18);
    DAT_80131781 = 1;
  }
  else {
    FUN_80077adc(0x31f0001,&local_18);
  }
  FUN_80039ba8();
  return;
}
