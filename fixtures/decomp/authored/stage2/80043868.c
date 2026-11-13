typedef unsigned int undefined4;
extern unsigned int DAT_800efd94;
extern unsigned int DAT_800efd9c;
extern unsigned int DAT_800efda0;












undefined4 FUN_80043868(undefined4 param_1,int param_2,int param_3)

{
  DAT_800efd94 = 0xffffffff;
  DAT_800efda0 = 0;
  DAT_800efd9c = 0;
  for (; param_2 != param_3; param_2 = param_2 + 0x14) {
    param_1 = FUN_80043988(param_1,param_2,0,0);
  }
  return param_1;
}
