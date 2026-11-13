typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;












undefined4 FUN_80083e14(int *param_1,short *param_2)

{
  if (((uint)(ushort)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(ushort)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}
