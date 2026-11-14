typedef unsigned char undefined1;
typedef unsigned short ushort;
typedef unsigned int uint;
extern unsigned int DAT_800ebb94;












void FUN_8003ba1c(void)

{
  ushort uVar2;
  unsigned char uVar1;
  
  FUN_80039c34();
  if (*(unsigned char *)(DAT_800ebb94 + 0x1e) == '\x04') {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
    uVar2 = FUN_80033604();
    *(ushort *)(DAT_800ebb94 + 0x42) = (uVar2 & 7) + 2;
  }
  else {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
    uVar1 = FUN_80033604();
    *(short *)(DAT_800ebb94 + 0x42) = (short)((uVar1 & 0xff) % 6) * 0x32 + 700;
  }
  return;
}
