typedef unsigned int undefined4;
typedef unsigned char byte;
typedef void code();
extern unsigned int DAT_800e1158;
extern unsigned int PTR_FUN_801666cc;












void FUN_80165128(int param_1,undefined4 param_2,undefined4 param_3)

{
  func_0x800653d0(param_1,&DAT_800e1158,0,0);
  (*(code *)(&PTR_FUN_801666cc)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}
