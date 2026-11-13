typedef unsigned char undefined1;
typedef unsigned short ushort;
extern unsigned int DAT_800ebb94;












void FUN_8003da98(void)

{
  ushort uVar1;
  
  FUN_80039c34();
  *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
  uVar1 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0x42) = (uVar1 & 3) + 10;
  return;
}
