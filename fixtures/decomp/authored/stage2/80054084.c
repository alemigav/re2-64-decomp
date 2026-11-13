typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;












void FUN_80054084(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2] + (uint)*(ushort *)((int)param_2 + 10);
  param_1[3] = (uint)*(byte *)(param_2 + 3) * 0x1000000 +
               (uint)*(byte *)((int)param_2 + 0xd) * 0x10000 +
               (uint)*(byte *)((int)param_2 + 0xe) * 0x100 + (uint)*(byte *)((int)param_2 + 0xf);
  return;
}
