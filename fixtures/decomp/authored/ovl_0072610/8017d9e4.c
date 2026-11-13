extern unsigned int DAT_801857c4;
extern unsigned int DAT_801857c8;
extern unsigned int DAT_801857cc;
extern unsigned int DAT_801857d0;
extern unsigned int DAT_801857d4;
extern unsigned int DAT_801857d8;
extern unsigned int DAT_80186c94;












void FUN_8017d9e4(void)

{
  int iVar1;
  
  iVar1 = FUN_8017bec8(2);
  *(int *)(DAT_80186c94 + 0x420) = iVar1 + 1;
  FUN_8017bec8(4);
  if (*(int *)(DAT_80186c94 + 0x420) == 2) {
    DAT_801857c4 = FUN_8017bec8(0xe);
    FUN_8017bbe8(1);
    DAT_801857c8 = FUN_8017bec8(0xe);
    DAT_801857cc = FUN_8017bec8(5);
    DAT_801857d0 = FUN_8017bec8(5);
    DAT_801857d4 = FUN_8017bec8(5);
    DAT_801857d8 = FUN_8017bec8(5);
  }
  return;
}
