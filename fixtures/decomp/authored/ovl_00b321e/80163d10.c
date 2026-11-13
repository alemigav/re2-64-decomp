typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80163d10(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  *(short *)((int)param_1 + 6) = 0x100;
  *(short *)(param_1 + 0x19) = 0;
  *param_1 = *param_1 | 4;
  FUN_801665a0(param_1,1);
  *(short *)(param_1 + 0x78) = 0x30f;
  *(short *)(param_1 + 0x79) = 0;
  func_0x80032b5c(param_1,0);
  *(short *)(param_1 + 0x1a) = 0xfc00;
  param_1[0x7a] = 0x8000000;
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
