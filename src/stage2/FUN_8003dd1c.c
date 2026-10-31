/* FUN_8003dd1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dd1c  body 0x8003dd1c..0x8003dd8b  size 115 B
 * body sha256 325b58bb51b0afaba10342c1e9324fff410806576a1ad3b7615825c6a7d5ace2
 * provider record sha256 75c64d0634ddb6f0574a50b413231d072ffe637e62434feaaf58bdda5e8af6c2
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003dd1c(void)

{
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  FUN_80069f1c(&local_18,2,0x80,1);
  if (DAT_8011270c != 0) {
    *(ushort *)(DAT_800ebb94 + 0x18) = *(ushort *)(DAT_800ebb94 + 0x18) & 0xdfff;
  }
  return;
}
