typedef unsigned char byte;
typedef unsigned short ushort;
extern unsigned int DAT_800e9028;
extern unsigned int DAT_800ebb94;












void FUN_8003b1b8(void)

{
  if (*(byte *)(DAT_800ebb94 + 2) != 0) {
    if (((*(byte *)(DAT_800ebb94 + 2) & 1) == 0) &&
       ((int)*(short *)(DAT_800ebb94 + 0x34) + (int)*(short *)(DAT_800ebb94 + 0x36) +
        (int)*(short *)(DAT_800ebb94 + 0x38) != 0)) {
      FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) + 0xb00 | 0x3090000,0,&DAT_800e9028,
                   DAT_800ebb94 + 0x34);
    }
    *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + -1;
  }
  return;
}
