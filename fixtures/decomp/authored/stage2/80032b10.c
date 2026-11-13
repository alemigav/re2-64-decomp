typedef unsigned int undefined4;
typedef unsigned int uint;












undefined4 FUN_80032b10(int *param_1,short *param_2)

{
  if (((uint)(int)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(int)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}
