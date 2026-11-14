/* FUN_8003ba1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ba1c  body 0x8003ba1c..0x8003bac7  size 172 B
 * body sha256 88744b2a99c67e11ab2991258b47192e76193844f8f8b1bdec9316c1395c8853
 * recovered byte-exact (imported: closed by the cast pass after localtype (43 of 43) (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003ba1c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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
