typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80071670(int param_1)

{
  FUN_80038f40(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}
