typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












undefined4 FUN_8007235c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_800777d8((uint)*(byte *)(iVar1 + 1) << 0x1c | (uint)*(byte *)(iVar1 + 2) << 0x18 |
               (uint)*(byte *)(iVar1 + 3) << 0x10 | (uint)*(byte *)(iVar1 + 4) << 8 |
               (uint)*(byte *)(iVar1 + 5));
  *(int *)(param_1 + 0x1c) = iVar1 + 6;
  return 1;
}
