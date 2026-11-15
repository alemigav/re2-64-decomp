typedef unsigned int uint;












void FUN_80165e40(uint *param_1, uint param_2, uint param_3)

{
  uint uVar1;
  
  param_1[0x7a] = 0xd000700;
  func_0x80089d54(param_1,param_2,param_3,0x200);
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2002,(uVar1 & 3) + 1);
  FUN_8016703c(param_1,0,0);
  param_1[1] = 0x7000000;
  *param_1 = *param_1 | 0x42;
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 0x46;
  }
  return;
}
