typedef unsigned int undefined4;
extern unsigned int DAT_80167340;
extern unsigned int DAT_801673c8;
extern unsigned int DAT_80167440;












void FUN_801665e8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167340,param_2);
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_801673c8,uVar1);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80167440,uVar1);
  return;
}
