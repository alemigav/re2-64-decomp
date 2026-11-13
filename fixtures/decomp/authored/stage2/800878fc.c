











void FUN_800878fc(int param_1,int param_2,int param_3)

{
  if (param_3 < *(short *)(param_1 + 0x5e)) {
    *(int *)(param_2 + 0xa8) = *(int *)(param_1 + 0x40) + param_3 * *(short *)(param_1 + 0x5c) * 4;
    *(int *)(param_2 + 0xac) = *(int *)(param_1 + 0x44) + param_3 * *(short *)(param_1 + 0x5c) * 4;
  }
  return;
}
