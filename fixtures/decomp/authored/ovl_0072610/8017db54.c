typedef unsigned int undefined4;
extern unsigned int DAT_8018578c;
extern unsigned int DAT_80185790;
extern unsigned int DAT_80185794;
extern unsigned int DAT_80185798;
extern unsigned int DAT_8018579c;
extern unsigned int DAT_801857a0;
extern unsigned int DAT_801857a4;
extern unsigned int DAT_801857a8;
extern unsigned int DAT_801857ac;
extern unsigned int DAT_801857b0;
extern unsigned int DAT_801857b4;
extern unsigned int DAT_801857b8;
extern unsigned int DAT_80186c94;












void FUN_8017db54(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_8017bec8(4);
  DAT_8018578c = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185790 = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185794 = iVar1 + -1;
  iVar1 = FUN_8017bec8(4);
  DAT_80185798 = iVar1 + -1;
  DAT_8018579c = FUN_8017bec8(2);
  DAT_801857a0 = FUN_8017bec8(2);
  DAT_801857a4 = FUN_8017bec8(1);
  DAT_801857a8 = FUN_8017bec8(1);
  DAT_801857ac = FUN_8017bec8(1);
  uVar2 = FUN_8017bec8(1);
  *(undefined4 *)(DAT_80186c94 + 0x424) = uVar2;
  DAT_801857b0 = FUN_8017bec8(1);
  uVar2 = FUN_8017bec8(1);
  *(undefined4 *)(DAT_80186c94 + 0x428) = uVar2;
  DAT_801857b4 = FUN_8017bec8(1);
  FUN_8017bec8(1);
  DAT_801857b8 = FUN_8017bec8(1);
  iVar1 = FUN_8017bec8(1);
  if (iVar1 != 0) {
    FUN_8017bec8(1);
    FUN_8017bec8(3);
    FUN_8017bec8(1);
    FUN_8017bec8(7);
    FUN_8017bec8(8);
  }
  return;
}
