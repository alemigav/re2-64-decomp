typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_800724fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800275c0(*(undefined1 *)(iVar1 + 1),(int)*(short *)(iVar1 + 2),0,0);
  *(int *)(param_1 + 0x1c) = iVar1 + 4;
  return 1;
}
