











void FUN_8008794c(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0xd6)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0xb8) + param_3 * *(short *)(param_1 + 0xd4) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0xbc) + param_3 * *(short *)(param_1 + 0xd4) * 4;
  }
  return;
}
