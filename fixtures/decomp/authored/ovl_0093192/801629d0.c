typedef unsigned int uint;












void FUN_801629d0(uint *param_1, uint param_2, uint param_3)

{
  *param_1 = *param_1 | 2;
  param_1[0xb] = param_1[0xb] + 0x1e;
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x20;
  *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x40;
  func_0x80089d54(param_1,param_2,param_3,0x400);
  if (((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) ||
     ((int)param_1[0xb] < (int)*(short *)(param_1 + 0x6a))) {
    func_0x8003247c(param_1);
  }
  return;
}
