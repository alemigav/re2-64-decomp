typedef unsigned short ushort;
extern unsigned int DAT_800e9028;
extern unsigned int DAT_800ebb94;












void FUN_80040524(void)

{
  if ((*(ushort *)(DAT_800ebb94 + 0x12) & 3) == 0) {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1c020000,(int)*(short *)(DAT_800ebb94 + 0x22),
                 &DAT_800e9028,DAT_800ebb94 + 0x2c);
  }
  *(short *)(DAT_800ebb94 + 0x12) = *(short *)(DAT_800ebb94 + 0x12) + 1;
  return;
}
