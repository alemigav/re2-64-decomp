typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern unsigned int DAT_8012bae0;












void FUN_80088548(undefined2 *param_1,int param_2)

{
  DAT_8012bae0 = param_1;
  *param_1 = 1;
  param_1[1] = 0;
  *(int *)(param_1 + 2) = param_2 + -0x20;
  *(undefined2 *)((int)param_1 + param_2 + -0x10) = 8;
  *(undefined2 *)((int)param_1 + param_2 + -0xe) = 0;
  *(undefined4 *)((int)param_1 + param_2 + -0xc) = 0;
  return;
}
