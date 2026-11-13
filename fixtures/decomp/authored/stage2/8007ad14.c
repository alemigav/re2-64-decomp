typedef unsigned int undefined4;
typedef unsigned short ushort;












void FUN_8007ad14(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x200) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfdff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
  }
  return;
}
