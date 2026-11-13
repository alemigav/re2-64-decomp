typedef unsigned int undefined4;
typedef unsigned short ushort;
extern unsigned int DAT_800e8eb8;












void FUN_8007977c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8eb8,5);
  if (((iVar1 == 0) && (iVar1 = FUN_800837ac(&DAT_800e8eb8,0xf), iVar1 == 0)) &&
     ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0)) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}
