/* FUN_8003d144
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d144  body 0x8003d144..0x8003d177  size 52 B
 * body sha256 59cc724e20b1fb009b73c9f0de111b6049f7f99ff7a2f6301be3cd0b0b0def10
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003d144.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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
