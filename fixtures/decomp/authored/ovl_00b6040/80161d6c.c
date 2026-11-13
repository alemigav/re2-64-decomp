typedef unsigned char undefined1;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_80161d6c(uint *param_1)

{
  param_1[1] = 0x2000000;
  param_1[0x7a] = 0;
  func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0);
  *(undefined1 *)((int)param_1 + 0x25d) = 0;
  param_1[0xa1] = 0;
  func_0x800339dc(param_1 + 0x82,0,0,0,param_1 + 10);
  *(undefined1 *)(param_1[0x82] + 0xe) = 0;
  *param_1 = *param_1 | 10;
  *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  return;
}
