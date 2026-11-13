typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned short ushort;
extern unsigned int DAT_800ebb94;












void FUN_8003d144(void)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(DAT_800ebb94 + 2) = 0x40;
  iVar1 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 8) = 0;
  *(undefined1 *)(iVar1 + 3) = 0;
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(iVar1 + 0xc) = 0;
  *(ushort *)(iVar2 + 0x12) = *(ushort *)(iVar2 + 0x12) & 0xfffd;
  return;
}
