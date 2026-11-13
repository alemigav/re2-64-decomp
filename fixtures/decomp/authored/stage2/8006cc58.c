typedef unsigned int uint;












void FUN_8006cc58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) =
       ((int)((*(uint *)(param_1 + 0x1c) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x1c) & 0xffff) + param_2) % 0xffff;
  return;
}
