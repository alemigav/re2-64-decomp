typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int uint;












void FUN_80162f54(uint *param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x7d) = 8;
  *(undefined2 *)(param_1 + 0x78) = param_2;
  *(undefined2 *)((int)param_1 + 0x1e2) = param_3;
  param_1[0x7a] = 0x14000700;
  *(undefined1 *)((int)param_1 + 0x2ba) = 0;
  *(undefined1 *)((int)param_1 + 699) = 0;
  *param_1 = *param_1 & 0xefffffff | 0x4000000;
  return;
}
