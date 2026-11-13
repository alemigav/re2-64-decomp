typedef unsigned int undefined4;
extern unsigned int _DAT_80012820;
extern unsigned int _DAT_8010b6f8;














int FUN_800044f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_80012820;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (iVar1 == 0) {
    _DAT_80012820 = _DAT_8010b6f8;
  }
  FUN_800013b0(_DAT_80012820);
  uVar2 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return param_1;
}
