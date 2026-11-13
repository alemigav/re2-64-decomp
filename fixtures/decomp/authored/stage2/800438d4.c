typedef unsigned int undefined4;
extern unsigned int DAT_800efd94;
extern unsigned int DAT_800efd9c;












undefined4 FUN_800438d4(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x10) {
    param_1 = FUN_80043930(param_1,param_2);
  }
  return param_1;
}
