typedef unsigned short undefined2;












void FUN_801665a0(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(short *)(param_1 + 0x134) = 0xfce0;
    *(short *)(param_1 + 0x13a) = 1000;
    *(short *)(param_1 + 300) = 800;
    *(short *)(param_1 + 0x12e) = 0x578;
    return;
  }
  *(short *)(param_1 + 0x13a) = 2000;
  *(short *)(param_1 + 0x134) = 0;
  *(short *)(param_1 + 300) = 4;
  *(short *)(param_1 + 0x12e) = 4;
  return;
}
